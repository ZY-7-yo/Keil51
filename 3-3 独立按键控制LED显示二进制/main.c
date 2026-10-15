#include <at89c51RC2.h>

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


void main()
{
	unsigned char LEDNum=0;
	while(1)
	{
//		P2_0=0;
//		Delay(500);
//		P2_0=1; 
//		Delay(500);
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			
			LEDNum++;
			P2=~LEDNum;
			
		}
	}
}
