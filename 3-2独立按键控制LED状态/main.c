#include <REGX52.H>
void Delay1ms(unsigned int n)		//@12.000MHz
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
	while(1)
	{
		if(P3_1==0)
		{
			Delay1ms(20);
			while(P3_1==0);
			Delay1ms(20);
			P2_0=~P2_0;
		}
	}
	
	
}