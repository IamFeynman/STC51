#include <REGX52.H>
#include "Int0.h"
#include "Timer0.h"


unsigned char IR_State;
unsigned int IR_Time;

unsigned char IR_Data[4];
unsigned char IR_PData;

unsigned char IR_DataFlag;
unsigned char IR_RepeatFlag;
unsigned char IR_Address;
unsigned char IR_Command;

void IR_Init()
{
	Timer0_Init();
	Int0_Init();
}


unsigned char IR_GetDataFlag()
{
	if(IR_DataFlag)
	{
		IR_DataFlag=0;
		return 1;
	}
	return 0;
}


unsigned char IR_GetRepeatFlag()
{
		if(IR_RepeatFlag)
	{
		IR_RepeatFlag=0;
		return 1;
	}
	return 0;	
}


unsigned char IR_GetAddress()
{
	return IR_Address;
	
}


unsigned char IR_GetCommand()
{
	return IR_Command;
}


void Int0_Routine(void) interrupt 0
{
	if(IR_State==0)
	{
		Timer0_SetCounter(0);
		Timer0_Run(1);
		IR_State=1;
	}
	else if(IR_State==1)
	{
		IR_Time=Timer0_GetCounter();
		Timer0_SetCounter(0);
		if(IR_Time>12442-500 && IR_Time<12442+500)
		{
			IR_State=2;
		}
		else if(IR_Time>10368-500 && IR_Time<10368+500)
		{
			IR_RepeatFlag=1;
			Timer0_Run(0);
			IR_State=0;
		}
		else
		{
			IR_State=1;
		}
	}
	else if(IR_State==2)
	{
		IR_Time=Timer0_GetCounter();
		Timer0_SetCounter(0);
		if(IR_Time>1032-500 && IR_Time<1032+500)
		{
			IR_Data[IR_PData/8]&=~(0x01<<(IR_PData%8));
			IR_PData++;
		}
		else if(IR_Time>2074-500 && IR_Time<2074+500)
		{
			IR_Data[IR_PData/8]|=(0x01<<(IR_PData%8));
			IR_PData++;
		}
		else
		{
			IR_PData=0;
			IR_State=1;	
		}
		if(IR_PData>=32)
		{
			IR_PData=0;
			if((IR_Data[0]==~IR_Data[1])&&(IR_Data[2]==~IR_Data[3]))
			{
				IR_Address=IR_Data[0];
				IR_Command=IR_Data[2];
				IR_DataFlag=1;
			}
			Timer0_Run(0);
			IR_State=0;
		}
		
	}	
}
