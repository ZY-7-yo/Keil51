#include <at89c51RC2.h>
#include "Timer1.h"

sbit Motor=P1^0;

unsigned char Counter,Compare;

void Motor_Init(void)
{
	Timer1_Init();
}

void Motor_SetSpeed(unsigned char Speed)
{
	Compare=Speed;
}

void Timer1_Routine() interrupt 3
{
	TL1 = 0xA4;		
	TH1 = 0xFF;	
	Counter++;
	Counter%=100;	//Counter>=100,Counter=0
	if(Counter<Compare)
	{
		Motor=1;
	}
	else
	{
		Motor=0;
	}
}