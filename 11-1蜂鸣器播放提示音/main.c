#include <REGX52.H>
#include "Key.h"
#include "Nixie.h"
#include "Buzzer.h"

sbit Buzzer=P2^5;

unsigned char KeyNum;
unsigned int i;
void main()
{
	Nixie(1,0);
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
			Buzzer_Time(100);
			Nixie(1,KeyNum);
		}
	}
	
	
}
