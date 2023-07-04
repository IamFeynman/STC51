#include <REGX52.H>

void Delay1ms(unsigned int n)		//@12.000MHz
{
	unsigned char i, j;

	
	while(n)//定义一个n，写一个n毫秒的函数1
	{
		i = 2;
		j = 239;//必须在while循环之内，不然只能循环一次
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
		P2=0xFE;//1111 1110
		Delay1ms(1000);//这样就可以随随便便定义延迟时间了
		P2=0xFD;//1111 1101
		Delay1ms(1000);
		P2=0xFB;//1111 1011
		Delay1ms(100);
		P2=0xF7;//1111 0111
		Delay1ms(100);
		P2=0xEF;//1110 1111
		Delay1ms(100);
		P2=0xDF;//1101 1111
		Delay1ms(100);
		P2=0xBF;//1011 1111
		Delay1ms(100);
		P2=0x7F;//0111 1111
		Delay1ms(100);
	}
	
	
}