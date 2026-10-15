#include <at89c51RC2.h>
#include "Delay.h"
#include "Timer0.h"

sbit Buzzer=P2^5;

#define SPEED	500		//以四分音符为基准

//音高部分
unsigned int FreqTable[]={
	0, //休止符
	62013,62211,62398,62574,62740,62897,63045,63185,63317,63441,63559,63670, 
	63775,63874,63967,64055,64138,64217,64291,64360,64426,64489,64547,64603,
	64655,64705,64751,64795,64837,64876,64913,64948,64981,65012,65042,65069	
};

//音乐+时长,小星星
unsigned char Music[]={
	13,4,
	13,4,
	20,4,
	22,4,
	22,4,
	20,4+4,
	18,4,
	18,4,
	17,4,
	17,4,
	15,4,
	15,4,
	13,4+4,
	
	0xFF
};

unsigned char FreqSelect,MusicSelect;

void main()
{
	Timer0_Init();
	while(1)
	{
//		测试从低到高的音		
//		FreqSelect++;
//		Delay(500);
		if(Music[MusicSelect]!=0xFF)
		{
			FreqSelect=Music[MusicSelect];
			MusicSelect++;
			Delay(SPEED/4*Music[MusicSelect]);
			MusicSelect++;
			TR0=0;
			Delay(5);
			TR0=1;
		}
		else
		{
			TR0=0;
		}
		
	}
} 

void Timer0_Routine() interrupt 1
{
	if(FreqTable[FreqSelect])
	{
		TL0 = FreqTable[FreqSelect]%256;	//低八位	
		TH0 = FreqTable[FreqSelect]/256;	//高八位
		Buzzer=!Buzzer; 	
	}
	
	
}