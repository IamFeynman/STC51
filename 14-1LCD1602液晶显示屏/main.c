#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"


void main()
{
	LCD_Init();
	LCD_ShowChar(1,1,0xF0);
	LCD_ShowString(2,2,"HELLO WORLD");
	LCD_ShowSignedNum(1,5,-88,2);
	LCD_ShowHexNum(1,8,0xA5,2);
	
	LCD_ShowString(1,16,"Welcome to China!");//�Ѿ�����LCD��Χ������û����40
	while(1)
	{
		LCD_WriteCommand(0x18);//����ָ�����������Ļ
		Delay(500);

		
		
	}
	
}