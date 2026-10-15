#include <at89c51RC2.h>

/**	
   * @brief 	定时器0初始化，1ms@11.0592MHz
   * @param		无
   * @retval	无
   */
void Timer0_Init()		//1毫秒@11.0592MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0=1;//定时器使能
	EA=1;//允许总中断
}


//	TMOD=0x01;//0000 0001
//	TMOD&=0xF0;//1111 0000把TMOD的低四位清零，高四位保持不变
//	TMOD|=0x01;//0000 0001把TMOD的最低位置1，高四位保持不变
//	TF0=0;//计数器溢出标准，初始化为0
//	TR0=1;//计数器运行控制位，置1允许计数器工作
//	TH0=64614/256;
//	TL0=64614%256;
//	ET0=1;//定时器使能
//	EA=1;//允许总中断
	//PT0=0;//定时器优先级为低，STC89C52RC不用设置，头文件没有定义

/*定时器中断函数模板
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;	//静态局部变量
	TL0 = 0x66;		
	TH0 = 0xFC;	
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
		
	}	
}
*/