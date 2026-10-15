#include <at89c51RC2.h>
#include "Timer0.h"
#include "Key.h"
#include "INTRINS.H"

unsigned char KeyNum,LEDMode;

void main()
{
	P2=0xFE;
	Timer0_Init();
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
//			测试程序
//			if(KeyNum==1)P2_1=~P2_1;
//			if(KeyNum==2)P2_2=~P2_2;
//			if(KeyNum==3)P2_3=~P2_3;
//			if(KeyNum==4)P2_4=~P2_4;
			if(KeyNum==1)
			{
				LEDMode++;
				if(LEDMode>=2)LEDMode=0;
			}
		}
	}
}


void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;	//静态局部变量
	TL0 = 0x66;		
	TH0 = 0xFC;	
	T0Count++;
	if(T0Count>=500)
	{
		T0Count=0;
		if(LEDMode==0)
			P2=_crol_(P2,1);//左移函数
		if(LEDMode==1)
			P2=_cror_(P2,1);//右移函数
	}
	
}