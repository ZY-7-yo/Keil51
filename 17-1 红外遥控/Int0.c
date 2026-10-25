#include <at89c51RC2.h>

void Int0_Init(void)
{
	IT0=1;
	IE0=0;
	EX0=1;
	EA=1;
}

/*
void Int0_Routine(void)	interrupt 0
{
	
}
*/