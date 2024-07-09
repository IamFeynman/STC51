#include <REGX52.H>

unsigned char LEDNum=0;

void Delay(unsigned int n)		//@12.000MHz
{
	unsigned char i, j;
	while(n)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		n--;
	}
}


void main()
{
	P2=~0x01;//初始化一下
	while(1)
	{
		if(P3_1==0)
			{
				Delay(20);
				while(P3_1==0);
				Delay(20);
				LEDNum++;
				if(LEDNum>=8)
						LEDNum=0;
				P2=~(0x01<<LEDNum);
			}
		if(P3_0==0)
				{
				Delay(20);
				while(P3_0==0);
				Delay(20);
				if(LEDNum==0)
					LEDNum=7;
				else
					LEDNum--;
				
				
				P2=~(0x01<<LEDNum);
			}
	}
	
	
}
