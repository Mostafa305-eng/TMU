/*
 * TMU.c
 *
 * Created: 1/11/2020 6:14:20 PM
 * Author : Mostafa Metwaly
 */ 

#include "TMU.h"
#include "led.h"
#include "SLEEP.h"
#include "interrupt.h"
#include "DIO.h"


void testzero()
{
	Led_Toggle(LED_0);
}

void testone()
{
	Led_Toggle(LED_1);
}

void testtwo()
{
	Led_Toggle(LED_2);
}

void testthree()
{
	Led_Toggle(LED_3);
}

void testfour()
{
	DIO_Toggle(GPIOA,BIT0);
}

void testfive()
{
	DIO_Toggle(GPIOA,BIT1);
}

void testsex()
{
	DIO_Toggle(GPIOA,BIT2);
}

void testseven()
{
	DIO_Toggle(GPIOA,BIT3);
}

void testeight()
{
	DIO_Toggle(GPIOA,BIT4);
}
void testnine()
{
	DIO_Toggle(GPIOA,BIT5);
}
void testten()
{
	DIO_Toggle(GPIOA,BIT6);
}




int main(void)
{
	LED_cfg_s_t LED_cfg_s={LED_0};
	Led_Init(&LED_cfg_s);	
	 LED_cfg_s.LedId=LED_1;
	Led_Init(&LED_cfg_s);
	LED_cfg_s.LedId=LED_2;
	Led_Init(&LED_cfg_s);
	LED_cfg_s.LedId=LED_3;
	Led_Init(&LED_cfg_s);
	DIO_Cfg_st myDio_Cfg_s={GPIOA,FULL_PORT,HIGH};
	DIO_init(&myDio_Cfg_s);
	
	
	
	
	sei();
	

		
	TMU_Init();
    /* Replace with your application code */
    
	
	TMU_Start_Timer(testzero,1,PERIODIC);
	TMU_Start_Timer(testone,2,PERIODIC);
	TMU_Start_Timer(testtwo,3,PERIODIC);
	TMU_Start_Timer(testthree,4,PERIODIC);
	TMU_Start_Timer(testfour,5,PERIODIC);
	TMU_Start_Timer(testfive,6,PERIODIC);
	TMU_Start_Timer(testsex,7,PERIODIC);
	TMU_Start_Timer(testseven,8,PERIODIC);
	TMU_Start_Timer(testeight,9,PERIODIC);
	TMU_Start_Timer(testnine,10,PERIODIC);
	TMU_Start_Timer(testten,11,PERIODIC);


	while (1) 
    {
		TMU_Dispatcher();
		 CPU_Sleep(IDLE);
    }
}

