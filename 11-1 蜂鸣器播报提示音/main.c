#include <at89c51RC2.h>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Buzzer.h"

unsigned char KeyNum;

void main()
{
	Nixie(1,0);//会跳3是因为红外模块和P3_2共用接口
	Delay(1000);
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
			Buzzer_Time(100);
			Nixie(1,KeyNum);
		}
	}

}