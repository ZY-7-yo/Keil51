#ifndef __DS1302_H__
#define __DS1302_H__

extern char DS1302_Time[];//声明变量加extern,表明引用外部已定义好的变量

void DS1302_Init(void);
void DS1302_WriteByte(unsigned char Command,Data);
unsigned char DS1302_ReadByte(unsigned char Command);
void DS1302_SetTime(void);
void DS1302_ReadTime(void);

#endif