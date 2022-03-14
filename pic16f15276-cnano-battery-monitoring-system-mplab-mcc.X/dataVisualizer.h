/*
 * dataVisualizer.h
 *
 * Created: 3/12/2020 12:14:31 PM
 *  Author: I20946
 */ 
#include <stdint.h>

#ifndef DATAVISUALIZER_H_
#define DATAVISUALIZER_H_

#define START_OF_FRAME 0x03
#define END_OF_FRAME 0xFC

typedef struct{                                  //Data streamer field 
	uint8_t start_of_frame; //1
    uint8_t OnOffFlag;
	uint8_t StateOfChargeInd[4];	//4
	float Vbat;	  //4
	float Vload;  //4
	float Ibat;	  //4
    float Iload;  //4			//1
    float StateOfCharge;   //4
	uint8_t end_of_frame;   //1
}DataStreamer_st;

typedef union {                                    //data streamer frame creation 
	uint8_t  DataStreamer_buffer[28]; 
    DataStreamer_st dataStreamer_st;
}DataStremerFrame_u;

void CreateDataStreamProtocolAndSend(void);


#endif /* DATAVISUALIZER_H_ */