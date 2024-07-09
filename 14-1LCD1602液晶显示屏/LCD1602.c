#include <REGX52.H>

sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;
sbit LCD_E=P2^7;
#define LCD_DataPort P0

void LCD_Delay()		//@12.000MHz,延时1us
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}


void LCD_WriteCommand(unsigned char Command)
{
	LCD_RS=0;
	LCD_RW=0;
	LCD_DataPort=Command;
	LCD_E=1;
	LCD_Delay();
	LCD_E=0;
	LCD_Delay();
}

void LCD_WriteData(unsigned char Data)
{
	LCD_RS=1;
	LCD_RW=0;
	LCD_DataPort=Data;
	LCD_E=1;
	LCD_Delay();
	LCD_E=0;
	LCD_Delay();
}

void LCD_Init(void)
{
	LCD_WriteCommand(0x38);
	LCD_WriteCommand(0x0c);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x01);
	
}

void LCD_SetCursor(unsigned char Line,unsigned char Column)
{
		if(Line==1)
	{
		LCD_WriteCommand(0x80|(Column-1));
	}
	else
	{
		LCD_WriteCommand(0x80|(Column-1)+0x40);
	}
	
	
}

void LCD_ShowChar(unsigned char Line,unsigned char Column,unsigned char Char )
{
	/*if(Line==1)
	{
		LCD_WriteCommand(0x80|(Column-1));
	}
	else
	{
		LCD_WriteCommand(0x80|(Column-1)+0x40);
	}*/
	LCD_SetCursor(Line,Column);
	LCD_WriteData(Char);
}

void LCD_ShowString(unsigned char Line,unsigned char Column,unsigned char String[] )
{
	unsigned char i;
	if(Line==1)
	{
		LCD_WriteCommand(0x80|(Column-1));
	}
	else
	{
		LCD_WriteCommand(0x80|(Column-1)+0x40);
	}
	for(i=0;String[i]!='\0';i++)
	{
		LCD_WriteData(String[i]);
	}
		
}
int LCD_Pow(int X,int Y)//乘方函数
{
	unsigned char i;
	int Result=1;
	for(i=0;i<Y;i++)
	{
		Result*=X;
	}
	return Result;
}

void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Num,unsigned char Length)
{
	unsigned char i;
	LCD_SetCursor(Line,Column);
	for(i=Length;i>0;i--)
	{
		LCD_WriteData(0x30+Num/LCD_Pow(10,i-1)%10);//数字转字符
	}
	
	
}
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Num,unsigned char Length)
{
	unsigned char i;
	unsigned int Num1;
	LCD_SetCursor(Line,Column);
	if(Num>=0)
	{
		LCD_WriteData('+');
		Num1=Num;
	}
	else{
		LCD_WriteData('-');
		Num1=-Num;
	}
	for(i=Length;i>0;i--)
	{
		LCD_WriteData(0x30+Num1/LCD_Pow(10,i-1)%10);//数字转字符
	}
}

void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned int Num,unsigned char Length)
{
	unsigned char i;
	unsigned char SingleNum;
	LCD_SetCursor(Line,Column);
	for(i=Length;i>0;i--)
	{
		SingleNum=Num/LCD_Pow(16,i-1)%16;
		if(SingleNum<10)
		{
			LCD_WriteData('0'+SingleNum);
		}
		else
		{
			LCD_WriteData('A'+SingleNum-10);
		}
		
	}
	
}

void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Num,unsigned char Length)
{
	unsigned char i;
	LCD_SetCursor(Line,Column);
	for(i=Length;i>0;i--)
	{
		LCD_WriteData(0x30+Num/LCD_Pow(2,i-1)%2);//数字转字符
	}
	
}