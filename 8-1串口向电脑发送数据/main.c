#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned char sec=0;


void main()
{
	UART_Init();

	while(1)
	{
		UART_SendByte(sec);
		sec++;
		Delay(500);
	}
	
}
