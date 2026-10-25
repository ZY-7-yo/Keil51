#include <at89c51RC2.h>

/**	
   * @brief 	定时器1初始化，100us@11.0592MHz
   * @param		无
   * @retval	无
   */
void Timer1_Init()		//1毫秒@11.0592MHz
{
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x10;		//设置定时器模式
	TL1 = 0xA4;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
	ET1=1;//定时器使能
	EA=1;//允许总中断
}

/*定时器中断函数模板
void Timer1_Routine() interrupt 3
{
	static unsigned int T1Count;	//静态局部变量
	TL1 = 0xA4;		
	TH1 = 0xFF;	
	T1Count++;
	if(T1Count>=1000)
	{
		T1Count=0;
		
	}	
}
*/