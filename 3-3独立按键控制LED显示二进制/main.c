#include <REGX52.H>

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
	unsigned char LEDNum=0;
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			LEDNum++;
			P2=~LEDNum;//È«²¿µÄLED
		}
	}
		
	
	
}