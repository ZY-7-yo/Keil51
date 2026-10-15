#include <at89c51RC2.h>

sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;

/**
   * @brief  I2C开始
   * @param	 无
   * @retval 无
   */
void I2C_Start(void)
{
	/*无论发送还是接收或者应答结束时SCL=0,所以拼接时已经是低电平*/
	I2C_SDA=1;	//SCL低电平时，SDA发生变化
	I2C_SCL=1;
	I2C_SDA=0;
	I2C_SCL=0;
}

/**
   * @brief  I2C停止
   * @param	 无
   * @retval 无
   */
void I2C_Stop(void)
{
	I2C_SDA=0;
	I2C_SCL=1;
	I2C_SDA=1;
}

/**
   * @brief  I2C发送一个字节
   * @param	 Byte 要发送的字节
   * @retval 无
   */
void I2C_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		I2C_SDA=Byte&(0x80>>i);	//依次从高位到低位发
		I2C_SCL=1;
		I2C_SCL=0; 
	}
}

/**
   * @brief  I2C接受一个字节
   * @param  无
   * @retval 接收到的一个字节数据
   */
unsigned char I2C_ReceiveByte(void)
{
	unsigned char i,Byte=0x00;
	
	I2C_SDA=1;	//释放SDA
	
	for(i=0;i<8;i++)
	{
		I2C_SCL=1;
		if(I2C_SDA){Byte|=(0x80>>i);}	//看I2C_SDA的数据，传到Byte上
		I2C_SCL=0;
	}	
	return Byte;
}

/**
   * @brief  I2C发送应答位
   * @param  AckBit 应答位，0为应答，1为非应答
   * @retval 无
   */
void I2C_SendACK(unsigned char AckBit)	/*C51特有的数据类型：bit位宽只有一位*/
{
	I2C_SDA=AckBit;
	I2C_SCL=1;
	I2C_SCL=0;
}	

/**
   * @brief  I2C接收应答位
   * @param  无
   * @retval 接收到的应答位，0为应答，1为非应答
   */
unsigned char I2C_ReceiveAck(void)
{
	unsigned char AckBit;
	I2C_SDA=1;
	I2C_SCL=1;
	AckBit=I2C_SDA;	
	I2C_SCL=0;
	return AckBit;
}

