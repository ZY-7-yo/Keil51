#include <at89c51RC2.h>

/**
   * @brief  串口初始化，4800bps@11.0592MHz
   * @param  无
   * @retval 无
   */
void UART_Init()		
{
	SCON=0x50;			//寄存器工作方式0101 0000
	PCON |= 0x80;		//波特率设置
	//串口依据的是定时器1
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xF4;		//设定定时初值
	TH1 = 0xF4;		//设定定时器重装值
	TR1 = 1;		//启动定时器1
	ET1 = 0;		//禁止定时器1中断
	EA=1;
	ES=1;

	
}

/**
   * @brief  串口发送一个字节数据
   * @param  Byte 要发送的一个字节数据
   * @retval 无
   */
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}

/*串口中断函数模板
void UART_Routine() interrupt 4
{
	if(RI==1)
	{
		
		RI=0;
	}
}
*/