#ifndef __DS1302_H__
#define __DS1302_H__

extern char DS1302_Time[];//声明EXTER
//数组和函数可以不用加，但是变量必须加extern
void DS1302_Init(void);
void DS1302_WriteByte(unsigned char Command,Data);
unsigned char DS1302_ReadByte(unsigned char Command);
void DS1302_SetTime();
void DS1302_ReadTime();
#endif