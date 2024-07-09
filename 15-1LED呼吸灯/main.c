#include <REGX52.H>

sbit LED=P2^0;

void Delay(unsigned int t)
{
	while(t--);
}


void mian()
{
	unsigned char Time,i;
	while(1)
	{
		for(Time=0;Time<100;Time++)
		{//类似PWM波的工作原理，控制亮灭的时间，实现呼吸灯
			for(i=0;i<20;i++)
			{
				LED=0;
				Delay(Time);
				LED=1;
				Delay(100-Time);
			}
			
		}
		for(Time=100;Time>0;Time--)
		{
			for(i=0;i<20;i++)
			{
				LED=0;
				Delay(Time);
				LED=1;
				Delay(100-Time);
			}
			
		}
	
	}
	
	
}