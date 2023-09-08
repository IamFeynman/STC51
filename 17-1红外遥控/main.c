#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "Int0.h"
#include "Timer0.h"
#include "IR.h"

unsigned char Num,Address,Command;
unsigned int Time;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"ADDR  CMD  NUM");
	
	IR_Init();
	
	while(1)
	{
		if(IR_GetDataFlag()||IR_GetRepeatFlag())
		{
			Address=IR_GetAddress();
			Command=IR_GetCommand();
			
			LCD_ShowHexNum(2,2,Address,2);
			LCD_ShowHexNum(2,8,Command,2);
			if(Command==0x15)
			{
				Num--;
			}
			if(Command==0x09)
			{
				Num++;
			}
			LCD_ShowNum(2,12,Num,3);
		}
	}
	
	
}

