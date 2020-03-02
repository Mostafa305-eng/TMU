/*
 * CPU_SLEEP.c
 *
 * Created: 1/12/2020 1:08:38 PM
 *  Author: Mostafa Metwaly
 */ 

/************************************************************************/
/*				 INCLUDES			        */
/************************************************************************/

#include "CPU_SLEEP.h"
#include "registers.h"


/************************************************************************/
/*				 DEFINES			        */
/************************************************************************/

#define SLEEP_MODE_BIT	0x80
#define Init			1
#define NotInit			0



/************************************************************************/
/*				  Static Global variables				        */
/************************************************************************/

static uint8 gu8_initState;

/************************************************************************/
/*						FUNCTIONS IMPLEMENTATION				        */
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

ERROR_STATUS CPUSLEEP_Init(void)
{
	gu8_initState=Init;
	return E_OK;
}


/******************************************************************************
 * fun
 * Input:the required sleep mode 
 * Output:
 * In/Out:			
 * Return: The error status of the function.			
 * Description: enters cpu in the required sleep mode
 *
 **************************************************************************/

ERROR_STATUS CPUSLEEP_SetMode(uint8 SleepMode)
{
	uint8 u8_MCUCSRBuffer=0;
	
	if (gu8_initState==NotInit)
	{
		return E_NOK;
	}
	
	SET_BIT(u8_MCUCSRBuffer,SLEEP_MODE_BIT);
	switch (SleepMode)
	{
	case IDLE_MODE :
		SET_BIT(u8_MCUCSRBuffer,IDLE_MODE);
		break;
	default:
		return E_NOK;
		break;
	}
	
	MCUCSR=u8_MCUCSRBuffer;
	return E_OK;
}
