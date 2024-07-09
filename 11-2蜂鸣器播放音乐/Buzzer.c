#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "INTRINS.h"
//�������˿ڣ����еİ�����P25��
sbit Buzzer=P2^5;

/**
  * @brief  ������˽����ʱ��������ʱ500US
  * @param ��
  * @retval ��
  */
void Buzzer_Delay500us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
}

/**
  * @brief  ����������
  * @param  ms������ʱ��
  * @retval ��
  */
void Buzzer_Time(unsigned int ms)
{
	unsigned int i;
	for(i=0;i<ms*2;i++)
	{
			Buzzer=!Buzzer;
			Buzzer_Delay500us();
	}
}


