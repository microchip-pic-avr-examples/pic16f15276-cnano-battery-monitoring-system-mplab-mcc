#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "application.h"
#include "mcc_generated_files/uart/eusart1.h"
#include "mcc_generated_files/adc/adc.h"
#include "mcc_generated_files/system/pins.h"
#include "dataVisualizer.h"

uint8_t ReadSwToEnableRegulator(void);
void BatteryMonitoringFSM(void);

powerParameter PowerParameters;     //Power parameters structure: Voltage and Current variables 

uint16_t adc_ch[5] = {Vbat,Vload,Vinput,Ibat,Iload};   //ADC channels array 
uint16_t voltage[5];                                   //Store accumulated ADC o/p data
uint16_t adc_Results = 0;                              

volatile uint8_t timer_flag = false;
volatile uint16_t sample_counter = false;
volatile uint8_t index = false;
volatile uint8_t SWPinChangeFlag = false;

bsmAppStatus_e state = idle;   //BMS FSM default state 

/*******************************************************************************
 * void Application(void)
 *
 * API to run the application, this API calls main application functions.
 * Function calls measure the system power parameters.
 *
 * @param None
 * @return None
 ******************************************************************************/
void Application(void) 
{
    SystemPowerMeasurement();         //This function calculates the power parameters of battery, charger and load.
                                      //Determine battery state of charge and display on the data visualizer.
}

/*******************************************************************************
 * void PreviusSOCFind(void)
 *
 * API to calculate and assign the approximate previous SOC value for
 * calculating the SOC. This function calculates previous soc value 
 * using  terminal voltage method.
 *  
 * @param None
 * @return None
 ******************************************************************************/
void PreviusSOCFind(void)
{
    GetVoltageOrCurrent(adc_ch[0], &adc_Results);
    PowerParameters.voltage[0] = (float) (VOLTAGE_GAIN * adc_Results);
    if((PowerParameters.voltage[0] > BAT_MIN_VOL) && (PowerParameters.voltage[0] < BAT_MAX_VOL))               //If battery voltage is in between minimum and maximum voltage, assign approx battery capacity (previous SOC).  
    {
        PowerParameters.socPrev = (SOC_MAX - (((BAT_MAX_VOL - PowerParameters.voltage[0])/BAT_POWER_HOLD_DIFF)*PERCENTAGE_CONV));  //calculating and assigning approx battery capacity
    }               //calculating the aprox soc by measuring the current Bat voltage and dividing by battery vol diff between the min and max voltage.
    else if(PowerParameters.voltage[0] < BAT_MIN_VOL)
    {
        PowerParameters.socPrev = 0;
    }
    else 
    {
        PowerParameters.socPrev = TOTAL_BAT_CAP;   //Assuming battery capacity is 100%
    }
}

/*******************************************************************************
 * void SOCCalibration(void)
 *
 * API to reset the SOC variables as per the battery behavior when battery reaches
 * to possible min and max. 
 *  
 * @param None
 * @return None
 ******************************************************************************/
void SOCCalibration(void)
{
    if((STAT1_GetValue()) && (PowerParameters.voltage[0] >= BAT_MAX_VOL))  //If battery is full and not charging, calibrate SOC. 
    {
        PowerParameters.socPrev = TOTAL_BAT_CAP;                     //Reseting previous SOC to full battery capacity 
    }
    if(PowerParameters.voltage[0] < BAT_MIN_VOL)   //If battery voltage is less than or equal to bat min vol and regulator vol is less than expected vol, assume SOC as 0%
    { 
        PowerParameters.socPrev = SOC_MIN;                                 //assigning the previous soc as a zero  
        PowerParameters.batStateOfCharge = SOC_MIN;                        
    }
}

/*******************************************************************************
 * void BatteryMonitoringFSM(void)
 *
 * API to find-out the system status by running the FSM.
 *  
 * @param None
 * @return None
 ******************************************************************************/
void BatteryMonitoringFSM(void)
{
    switch(state)
    {
        case charging:
             //Check the STAT pin of the charger, if battery is charging update the SOC.
           if((!STAT1_GetValue()) && (PowerParameters.voltage[2] >= BAT_MAX_VOL))
           {
               state = charging;
                                                                       
               PowerParameters.batStateOfCharge = (PowerParameters.current[0]/BAT_NOMICAL_CAP_AH);
               PowerParameters.batStateOfCharge = (PowerParameters.socPrev + (PowerParameters.batStateOfCharge * SAMPLE_TIME * PERCENTAGE_CONV)); 
               PowerParameters.socPrev = PowerParameters.batStateOfCharge;
           }
           if((PowerParameters.voltage[1] < LDO_VOL) && (PowerParameters.voltage[2] < BAT_MAX_VOL) && (STAT1_GetValue()))         //If charging is happening and regulator is off, set state to Idle.
           {
               state = idle;
           }
           if((PowerParameters.voltage[0] >= BAT_MIN_VOL))     //If user pressed switch and load vol is as expected, set the state to systemOn. 
           {
               Reg_En_SetHigh(); 
               state = systemOn;
           }
           break;
        case systemOn:
           if((PowerParameters.voltage[0] <= BAT_MIN_VOL))
           {
              Reg_En_SetLow();
              state = charging;
           }
           //If the regulator voltage is greater than or equal to desired regulator vol, update the SOC.
           if((PowerParameters.voltage[0] >= BAT_MIN_VOL) && (PowerParameters.voltage[1] >= LDO_VOL))  
           {
              state = systemOn;
    
              PowerParameters.batStateOfCharge = (PowerParameters.current[1]/BAT_NOMICAL_CAP_AH);
              PowerParameters.batStateOfCharge = (PowerParameters.socPrev - (PowerParameters.batStateOfCharge * SAMPLE_TIME * PERCENTAGE_CONV)); 
              PowerParameters.socPrev = PowerParameters.batStateOfCharge; 
           }
           if((PowerParameters.voltage[2] >= BAT_MAX_VOL) && (!STAT1_GetValue())) //If charger i/p vol is greater than or equal to 4.2V, set the state to charging.
           {
              state = charging;
           }
           if((PowerParameters.voltage[0] >= BAT_MIN_VOL) && (PowerParameters.voltage[2] < BAT_MAX_VOL) && (PowerParameters.voltage[1] < LDO_VOL))
           {
              state = idle;
           }
            break;
        case idle:
           if ((PowerParameters.voltage[0] >= BAT_MIN_VOL) && (PowerParameters.voltage[1] <= LDO_VOL) && (PowerParameters.voltage[2] <= BAT_MIN_VOL))   //If the battery vol is higher than minimum vol and regulator output is less than or desired vol, set the state to Idle. 
           {
               state = idle;
           }
           if(((PowerParameters.voltage[0] < BAT_MAX_VOL) || (!STAT1_GetValue())) && ((PowerParameters.voltage[2] >= BAT_MAX_VOL)))          //If charger i/p vol is greater than or equal to 4.2V, set the state to charging.
           {
              state = charging;
           }
           if ((PowerParameters.voltage[0] >= BAT_MIN_VOL))   //If user pressed the switch or load vol is greater or equal to desired vol, set the state to systemOn. 
           {
               Reg_En_SetHigh(); 
               state = systemOn;
           }
           break;
        case error:                                                     //setting all the vol and current parameters to 999 to indicate error
            PowerParameters.voltage[0] = ERROR_CODE;
            PowerParameters.voltage[1] = ERROR_CODE;
            PowerParameters.current[0] = ERROR_CODE;
            PowerParameters.current[1] = ERROR_CODE;
            break;
        default:
            state = error;                                               //set status to error
            break;
    }
}

/*******************************************************************************
 * void SystemPowerMeasurement(void)
 *
 * API to measure Battery Voltage, Load Voltage, Battery Current and Load Current
 * using ADC.
 *  
 * @param None
 * @return None
 ******************************************************************************/
void SystemPowerMeasurement(void) 
{
    if (timer_flag == true)                        //timer overflow happens for every 200ms and flag become true
    {
        timer_flag = false;
        for (index = 0; index <= 4; index++)       //0 - Battery Vol,1 - Load Vol, 2-Bat current, 3-Charger i/p, 4-Load current, 5-Charger input.
        {
            GetVoltageOrCurrent(adc_ch[index], &adc_Results);
            voltage[index] += adc_Results;
        }
        sample_counter++;
    }

    if (sample_counter >= SAMPLE_COUNT)        //average the accumulated value and calculate the voltage and current. 
    {
        for (index = 0; index <= 2; index++) 
        {
            voltage[index] = (voltage[index] / (sample_counter));               //divide the accumulated value with number of samples. 
            PowerParameters.voltage[index] = voltage[index] * (STEP_SIZE);    //Convert ADC raw digital in to voltage using ADC step size and voltage divider circuit. 
            PowerParameters.voltage[index] /= (float)VOLTAGE_GAIN;
            voltage[index] = 0;
        }

        for (index = 3; index <= 4; index++) 
        {
            voltage[index] = (voltage[index] / (sample_counter));               //divide the accumulated value with number of samples 
            PowerParameters.current[index-3] = (float)(CURRENT_GAIN * voltage[index]);   //Convert ADC raw digital in to current using ADC step size and voltage divider circuit. 
            voltage[index] = 0;
        }

        sample_counter = 0;                         //Reset the sample counter for next cycle
        PowerParameters.batStateOfCharge = PowerParameters.socPrev;
        BatteryMonitoringFSM();                //calling FSM every second
        SOCCalibration();                      //SOC calibration when battery is full or empty.  
        CreateDataStreamProtocolAndSend();     //Arrange data in data stream protocol and send through EUSART
    }
}

/*******************************************************************************
 * void GetVoltageOrCurrent(uint16_t sel, uint16_t *Vol) 
 *
 * API to get the digital value of adc to measure voltage or current.
 *  
 * @param sel: ADC channel, *Vol: digital value of corresponding channel 
 * @return None
 ******************************************************************************/
void GetVoltageOrCurrent(uint16_t sel, uint16_t *vol) 
{
    *vol = ADC_GetConversion(sel);
}

/*******************************************************************************
 * void ReadSwToEnableRegulator(void)
 *
 * API to read the GPIO for finding the user switch press
 *  
 * @param None
 * @return None
 ******************************************************************************/
uint8_t ReadSwToEnableRegulator(void)   //Tracking switch press for enabling the regulator to be connected to the system/load
{
    if (SWPinChangeFlag == true) 
    {
        SWPinChangeFlag = false;
        return 1;                        //return 1 if user pressed switch 
    } 
    return 0;                            //return 0 if user not pressed switch 
}

/*******************************************************************************
 * void UserTMR_InterruptHandler(void)
 *
 * Timer user interrupt handler to track the 100ms scheduler.
 * timer overflow interrupt.
 *  
 * @param None
 * @return None
 ******************************************************************************/
void UserTMR_InterruptHandler() 
{
    timer_flag = true;
}

/*******************************************************************************
 * void UserSW_InterruptHandler(void)
 *
 * IO user interrupt handler to track the change in IO pin.
 * IO interrupt handler.
 *  
 * @param None
 * @return None
 ******************************************************************************/
void UserSW_InterruptHandler() 
{
    SWPinChangeFlag = true;
}