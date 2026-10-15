#include <at89c51RC2.h>

void main()
{
//	P2=0xFE;
	
	
	while(1)
	{
		if(P3_1==0 || P3_0==0)//原理图上写的P3_1是第一个按键，P3_0是第二个按键
		{
			P2_0=0;//按下就亮
		}
		else
		{
			P2_0=1;//松开就灭
		}
	}
}