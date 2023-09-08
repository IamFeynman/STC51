#include <REGX52.H>

/**
  * @brief  ��ʱ��0��ʼ����100΢��@12.000MHZ
  * @param   ��
  * @retval   ��
  */
void Timer0_Init(void)		//100΢��@12.000MHz
{
	TMOD&= 0xF0;		//���ö�ʱ��ģʽ
	TMOD|= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x9C;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0=1;
	EA=1;
	PT0=0;
}

/*void Timer0_Routine() interrupt 1//�жϺ���
{
	static unsigned int T0Count;
	TL0 = 0x9C;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
		P2_0=~P2_0;
	}
}*/