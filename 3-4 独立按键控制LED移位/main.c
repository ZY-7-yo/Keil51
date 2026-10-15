#include <at89c51RC2.h>
void Delay(unsigned int xms);

unsigned char LEDNum;//全局变量不给初始值 默认是0

void main()
{
	P2=~0x01;
	while(1)
	{
		if(P3_1==0)
		{
			
			Delay(20);
			while(P3_1==0);
			Delay(20);
			
			LEDNum++;			
			if(LEDNum>=8)
				LEDNum=0;
			P2=~(0x01<<LEDNum);
						
		}
		if(P3_0==0)
		{
			Delay(20);
			while(P3_0==0);
			Delay(20);
			
			if(LEDNum==0)
			{
				LEDNum=7;
			}
			else
				LEDNum--;
			P2=~(0x01<<LEDNum);
		}
	}
}

//如果把函数体放在后面定义，要在头文件下面声明
void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 199;  
		do
		{
			while (--j);
		} while (--i);		
	}
	
}

