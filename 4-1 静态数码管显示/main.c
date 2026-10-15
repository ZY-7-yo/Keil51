#include <at89c51RC2.h>
//工程损坏打不开，只有main.c文件

void Nixie(unsigned char Location,Number)
{
	switch(Location)
	{
		//从左到右
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8 :P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0=0x7D;
}

void main()
{
//	P2_4=1;
//	P2_3=0;
//	P2_2=0;//LED的位置
//	P0=0x7D;//数字的显示
	Nixie(7,2)
	while(1)
	{
	
	}
}