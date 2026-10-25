#include <at89c51RC2.h>
#include "LCD1602.h"
#include "Delay.h"
#include "XPT2046.h"

unsigned int ADValue1,ADValue2,ADValue3;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"ADJ  NTC  RG");
	while(1)
	{
		ADValue1=XPT2046_ReadAD(XPT2046_XP_8);
		LCD_ShowNum(2,1,ADValue1,3);
		ADValue2=XPT2046_ReadAD(XPT2046_YP_8);
		LCD_ShowNum(2,6,ADValue2,3);
		ADValue3=XPT2046_ReadAD(XPT2046_VBAT_8);
		LCD_ShowNum(2,11,ADValue3,3);
		Delay(10);
	}
}