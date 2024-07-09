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
	
	LCD_ShowString(1,16,"Welcome to China!");//已经超过LCD范围，但是没超过40
	while(1)
	{
		LCD_WriteCommand(0x18);//发送指令，进行流动字幕
		Delay(500);

		
		
	}
	
}