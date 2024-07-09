#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.H"
#include "Timer0.h"

unsigned char sec,min,hour;
void main()
{
	LCD_Init();
	Timer0Init();
	LCD_ShowString(1,1,"Clock:");
	//LCD_ShowString(2,3,":  :");
	
	while(1)
	{
		LCD_ShowNum(2,1,hour,2);
		LCD_ShowChar(2,3,':');//����ð�ţ�Ҳ���԰���Line12�Ĵ���
		LCD_ShowNum(2,4,min,2);
		LCD_ShowChar(2,6,':');
		LCD_ShowNum(2,7,sec,2);
	}
	
	
}

void Timer0_Routine() interrupt 1//�жϺ���
{
	static unsigned int T0Count;
	TL0 &= 0x18;		//���ö�ʱ��ģʽ
	TH0 |= 0xFC;		//���ö�ʱ��ģʽ
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
		sec++;
		if(sec>=60)
		{
			sec=0;
			min++;
			if(min>=60)
			{
				min=0;
				hour++;
				if(hour>=24)
				{
					hour=0;
				}
			}
		}
				
	}
}