#include <REGX52.H>

unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x79,0x76,0x38};//,E,H,L
void Nixie(unsigned char Location,Number)
{
	switch(Location)//想要控制的位置，第几个数码管
	{
		case 1:
			P2_4=1;P2_3=1;P2_2=1;break;
		case 2:
			P2_4=1;P2_3=1;P2_2=0;break;
		case 3:
			P2_4=1;P2_3=0;P2_2=1;break;
		case 4:
			P2_4=1;P2_3=0;P2_2=0;break;
		case 5:
			P2_4=0;P2_3=1;P2_2=1;break;
		case 6:
			P2_4=0;P2_3=1;P2_2=0;break;
		case 7:
			P2_4=0;P2_3=0;P2_2=1;break;
		case 8:
			P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0=NixieTable[Number];//数码管的状态，你想让他输出那个数字？
}

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
		/*int i=0;
		for(i=0;i<=8;i++)//写一个for循环，一直延迟100ms输出6
		{
			Nixie(i,6);
			Delay1ms(100);
		}*/
		Nixie(1,11);//H
		Delay1ms(1);
		Nixie(2,10);//E
		Delay1ms(1);
		Nixie(3,12);//0x38是L
		Delay1ms(1);
		Nixie(4,12);//L
		Delay1ms(1);
		Nixie(5,0);//0
		Delay1ms(1);//HELLLO
		
	}
	
}