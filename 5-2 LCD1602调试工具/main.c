#include <at89c51RC2.h>
#include "LCD1602.h"
#include "Delay.h"

int Result=0;

void main()
{
	LCD_Init();//LCD初始化
//	LCD_ShowChar(1,1,'A');
//	LCD_ShowString(1,3,"Hello");
//	LCD_ShowNum(1,9,123,3);
//	LCD_ShowSignedNum(1,13,-66,2);//长度不包括符号在内
//	LCD_ShowHexNum(2,1,0xA8,2);//显示十六进制数
//	LCD_ShowBinNum(2,4,0xAA,8);//显示二进制数,但是使用十六进制表示二进制数
	
	while(1)
	{
		Result++;
		Delay(1000);
		LCD_ShowNum(1,1,Result,3);
	}
}