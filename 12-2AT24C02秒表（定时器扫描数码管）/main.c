#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"
#include "AT24C02.h"

unsigned char KeyNum;
unsigned char Min,Sec,Minisec;
unsigned char RunFlag;

void main()
{
	Timer0_Init();
	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{
			RunFlag=!RunFlag;//运行标志，按1停止or开始
		}
			if(KeyNum==2)
		{
			Min=0;
			Sec=0;
			Minisec=0;
		}
			if(KeyNum==3)//写入
		{
			AT24C02_WriteByte(0,Min);
			Delay(5);
			AT24C02_WriteByte(1,Sec);
			Delay(5);
			AT24C02_WriteByte(2,Minisec);
			Delay(5);
		}
			if(KeyNum==4)//读取
		{
			Min=AT24C02_ReadByte(0);
			Sec=AT24C02_ReadByte(1);
			Minisec=AT24C02_ReadByte(2);
		}
			Nixie_SetBuf(1,Min/10);
			Nixie_SetBuf(2,Min%10);
			Nixie_SetBuf(3,11);
			Nixie_SetBuf(4,Sec/10);
			Nixie_SetBuf(5,Sec%10);
			Nixie_SetBuf(6,11);
			Nixie_SetBuf(7,Minisec/10);
			Nixie_SetBuf(8,Minisec%10);
		
		
	}
	
	
}
void Sec_Loop()
{
	if(RunFlag)
	{
		Minisec++;
		if(Minisec>=100)
		{
			Minisec=0;
			Sec++;
			if(Sec>=60)
			{
				Sec=0;
				Min++;
				if(Min>=60)
					Min=0;
			}
		}
	}
	
}

void Timer0_Routine() interrupt 1//中断函数
{
	static unsigned int T0Count1,T0Count2,T0Count3;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count1++;
	if(T0Count1>=20)
	{
		T0Count1=0;
		Key_Loop();
	}
	T0Count2++;
	if(T0Count2>=2)
	{
		T0Count2=0;
		Nixie_Loop();
	}
	T0Count3++;
	if(T0Count3>=10)
	{
		T0Count3=0;
		Sec_Loop();
	}
}