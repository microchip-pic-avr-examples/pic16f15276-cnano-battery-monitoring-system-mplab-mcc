/* 
 * File:   application.h
 * Author: I20946
 *
 * Created on June 3, 2021, 11:38 PM
 */
#include <stdint.h>
#include "mcc_generated_files/system/clock.h"

#define STEP_SIZE (float)(0.00322)
#define VOLTAGE_GAIN (float)(0.66225 - 0.013245)         //    //(3.3/1023)/Rgain)-5% tollerence
#define CURRENT_GAIN (float)(0.003225 * 0.3333) //0.5)    //0.33333
#define SAMPLE_TIME (float)(0.00028)    //1 secound (1/3600)
#define TOTAL_BAT_CAP (float)(100.00)  //Battery capacity in Ah
#define BAT_MAX_VOL (float)(4.10)       //Battery maximum voltage 
#define BAT_MIN_VOL (float)(2.5)        //Battery minimum voltage
#define BAT_NOMICAL_CAP_AH (float)(2.5)  //battery nominla capacity in Ah 
#define LDO_VOL (float)(0.060)           //LDO output voltage - approx 
#define PERCENTAGE_CONV (float)(100.0)    //constant 100 to convert values in to %
#define SOC_MAX (100)                    //max SOC SOC = 100 = Battery full
#define SOC_MIN (0)                      //min SOC SOC = 0 = Battery Empty
#define BAT_POWER_HOLD_DIFF (float)(1.7)
#define ERROR_CODE (float)(999.99)    //Error code if error occurs
#define MIN_LOAD_CURR (float)(0.010)
#define SAMPLE_COUNT 5

#ifndef APPLICATION_H
#define	APPLICATION_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum 
{
    charging = 1,
    systemOn,
    idle,
    error
}bsmAppStatus_e;

typedef struct powerPara 
{
  float batStateOfCharge;
  float socPrev;
  float voltage[3];
  float current[2];
}powerParameter;

void GetVoltageOrCurrent(uint16_t sel,uint16_t *Vol);
void UserTMR_InterruptHandler();
void UserSW_InterruptHandler();
void SystemPowerMeasurement(void);
void Application(void);
void PreviusSOCFind(void);
void SOCCalibration(void);


#ifdef	__cplusplus
}
#endif

#endif	/* APPLICATION_H */

