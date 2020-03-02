/*
 * CPU_SLEEP.h
 *
 * Created: 1/12/2020 1:10:12 PM
 *  Author: Mostafa Metwaly
 */ 


#ifndef CPU_SLEEP_H_
#define CPU_SLEEP_H_

/************************************************************************/
/*				 I				INCLUDES						        */
/************************************************************************/
#include "std_types.h"
#include "common_macros.h"


/************************************************************************/
/*				 DEFINES			        */
/************************************************************************/
#define IDLE_MODE	0
#define ADC_NOISE_REDUCTION	0x10
#define POWER_DOWN_MODE		0x20
#define POWER_SAVE_MODE		0x30
#define STANDBY_MODE		0x60
#define EXTENDED_STANDBY_MODE	0x70



/************************************************************************/
/*						 FUNCTIONS' PROTOTYPES					        */
/************************************************************************/


/******************************************************************************
 * fun
 * Input:  
 * Output:
 * In/Out:			
 * Return: The error status of the function.			
 * Description: Initiates the module.
 *
 **************************************************************************/

ERROR_STATUS CPUSLEEP_Init(void);



/******************************************************************************
 * fun
 * Input:the required sleep mode 
 * Output:
 * In/Out:			
 * Return: The error status of the function.			
 * Description: enters cpu in the required sleep mode
 *
 **************************************************************************/

ERROR_STATUS CPUSLEEP_SetMode(uint8 SleepMode);


#endif /* CPU_SLEEP_H_ */