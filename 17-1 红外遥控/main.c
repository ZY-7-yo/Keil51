#include <at89c51RC2.h>
#include "Delay.h"
#include "LCD1602.h"
#include "IR.h"

unsigned char Num;
unsigned int Address;
unsigned int Command;


void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"ADDR  CMD  NUM");
	LCD_ShowString(2,1,"00    00   000");

	IR_Init();
	
//	测试定时器计时	
//	Timer0_Init();
//	Timer0_SetCounter(0);
//	Timer0_Run(1);
//	Delay(10);
//	Time=Timer0_GetCounter();
//	LCD_ShowNum(2,1,Time,5);
	
	while(1)
	{
		if(IR_GetDataFlag() || IR_GetRepeatFlag())
		{
			Address=IR_GetAddress();
			Command=IR_GetCommand();
			
			LCD_ShowHexNum(2,1,Address,2);
			LCD_ShowHexNum(2,7,Command,2);
			
			if(Command==IR_VOL_MINUS)
			{
				Num--;
			}
			if(Command==IR_VOL_ADD)
			{
				Num++;
			}
			LCD_ShowNum(2,12,Num,3);
		}
	}
}
