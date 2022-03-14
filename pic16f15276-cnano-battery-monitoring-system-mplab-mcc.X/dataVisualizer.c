/*
 * dataVisualizer.c
 *
 * Created: 6/22/2021 12:14:08 PM
 *  Author: I20946
 */ 
#include <stdio.h>
#include "dataVisualizer.h"
#include "application.h"
#include "mcc_generated_files/uart/eusart1.h"

extern powerParameter PowerParameters;

DataStremerFrame_u dataStremerFrame_u;

void FindBatteryIndexToDataVisu (void);
static void SendString(uint8_t *data,uint16_t len);

/*******************************************************************************
 * void CreateDataStreamProtocolAndSend(void)
 *
 * API to create data streamer protocol buffer and send same buffer in to 
 * data visualizer.   
 *
 * @param None 
 * @return None 
 ******************************************************************************/
void CreateDataStreamProtocolAndSend(void)
{
		dataStremerFrame_u.dataStreamer_st.start_of_frame = (char)START_OF_FRAME;      //start of frame 03 
		dataStremerFrame_u.dataStreamer_st.end_of_frame = (char)END_OF_FRAME;          //end of frame ~03 
		
        dataStremerFrame_u.dataStreamer_st.StateOfCharge = PowerParameters.batStateOfCharge;      //State of Battery data      
        
        FindBatteryIndexToDataVisu();              //API to set the index for showing the battery level in data visualizer custom board                 
		if(PowerParameters.batStateOfCharge > 0)       //System on/off index set by checking the SOC level
        {
            dataStremerFrame_u.dataStreamer_st.OnOffFlag = 1;
        }
        else
        {
            dataStremerFrame_u.dataStreamer_st.OnOffFlag = 0;
        }
        dataStremerFrame_u.dataStreamer_st.Vbat = PowerParameters.voltage[0];            //Battery voltage           
		dataStremerFrame_u.dataStreamer_st.Vload = PowerParameters.voltage[1];           //Load Voltage 
		dataStremerFrame_u.dataStreamer_st.Ibat = PowerParameters.current[0];            //Battery charging current
		dataStremerFrame_u.dataStreamer_st.Iload = PowerParameters.current[1];           //Load charging current
		
	    SendString(dataStremerFrame_u.DataStreamer_buffer,26);                //sending data frame to data visualizer
}

/*******************************************************************************
 * void FindBatteryIndexToDataVisu (void)
 *
 * API to set the index for showing the battery level in data visualizer custom board. 
 *
 * @param None 
 * @return None 
 ******************************************************************************/
void FindBatteryIndexToDataVisu (void)
{
    if(PowerParameters.batStateOfCharge == 0.00)
    {
       dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[0] = 0;
       dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[1] = 0;
       dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[2] = 0;
       dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[3] = 0;
    }
    if(1.00 <= PowerParameters.batStateOfCharge && PowerParameters.batStateOfCharge <= 25.00) 
    {
	   dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[0] = 1;
       dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[1] = 0;
       dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[2] = 0;
       dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[3] = 0;
	}else if(25.00 <= PowerParameters.batStateOfCharge && PowerParameters.batStateOfCharge <= 50.00) 
    {
	   dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[0] = 1;
       dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[1] = 1;
       dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[2] = 0;
       dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[3] = 0;
    }else if(50.00 <= PowerParameters.batStateOfCharge && PowerParameters.batStateOfCharge <= 75.00) 
    {
	   dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[0] = 1;
       dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[1] = 1;
       dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[2] = 1;
       dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[3] = 0;
    }else if(75.00 <= PowerParameters.batStateOfCharge && PowerParameters.batStateOfCharge <= 100.00) 
    {
	   dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[0] = 1;
       dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[1] = 1;
       dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[2] = 1;
       dataStremerFrame_u.dataStreamer_st.StateOfChargeInd[3] = 1;
    }
}
/*******************************************************************************
 * static void SendString(uint8_t *data,uint16_t len)
 *
 * API to send string via USART  
 *
 * @param string which we like to transmit and size of the string 
 * @return None 
 ******************************************************************************/
static void SendString(uint8_t *data,uint16_t len)
{
	uint16_t  i = 0;
	for (i=0;i<=len;i++)
	{
      while(!EUSART1_IsTxReady());  
      EUSART1_Write(*data++);
	}
    
}