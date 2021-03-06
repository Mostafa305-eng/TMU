/*
 * SLEEP.c
 *
 * Created: 1/13/2020
 *  Author: Mostafa Metwaly
 */ 


/************************************************************************/
/*				 				INCLUDES						        */
/************************************************************************/
#include "registers.h"
#include "SLEEP.h"




/************************************************************************/
/*						FUNCTIONS IMPLEMENTATION				        */
/************************************************************************/


/*************************************************************************
* @brief: CPU_Sleep provides six modes
* 	  IDLE, ADC_NOISE_REDUC, POWER_DOWN, POWER_SAVE, STANDBY, EXT_STANDBY
* 	  Note: STANDBY and EXT_STANDBY sleep modes are only available with
* 	  	external crystal/resonator fuse selection
* @param: E_SleepMode_t defines sleep modes
* Input : E_SleepMode_t
* Output: None
* @return: void
*****************************************************************************/
void CPU_Sleep(uint8 u8_mode)
{
  switch (u8_mode) {
    case (IDLE):
      /* Set IDLE sleep mode */
      MCUCR &= ~(SM2 | SM1 | SM0);
      /* Enter sleep mode */
      MCUCR |= SE;
      break;
    case (ADC_NOISE_REDUC):
      /* Set ADC noise reduction sleep mode */
      MCUCR &= ~(SM2 | SM1);
      MCUCR |= SM0;
      /* Enter sleep mode */
      MCUCR |= SE;
      break;
    case (POWER_DOWN):
      /* Set Power-down sleep mode */
      MCUCR &= ~(SM2 | SM0);
      MCUCR |= SM1;
      /* Enter sleep mode */
      MCUCR |= SE;
      break;
    case (POWER_SAVE):
      /* Set Power-save sleep mode */
      MCUCR |= (SM1 | SM0);
      MCUCR &= ~SM2;
      /* Enter sleep mode */
      MCUCR |= SE;
      break;
    case (STANDBY):
      /* Set Standby sleep mode */
      MCUCR |= (SM2 | SM1);
      MCUCR &= ~SM0;
      /* Enter sleep mode */
      MCUCR |= SE;
      break;
    case (EXT_STANDBY):
      /* Set Extended standby sleep mode */
      MCUCR |= (SM2 | SM1 | SM0);
      /* Enter sleep mode */
      MCUCR |= SE;
      break;
    default:
      break;
  }
  /* Execute SLEEP instruction to put device in selected sleep mode */
  asm("SLEEP");
}
