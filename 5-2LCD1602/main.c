#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

void main()
{
		unsigned int result=0;
	LCD_Init();
	/*LCD_Init();
		LCD_ShowChar(1,1,'A');//�ַ�
		LCD_ShowString(1,3,"Hello ");//�ַ���
		LCD_ShowNum(1,9,123,4);
		LCD_ShowSignedNum(1,13,-66,2);//�����ŵ�����
		LCD_ShowHexNum(2,1,0xA8,2);//ʮ������
		LCD_ShowBinNum(2,4,0xAA,8);//��λ������
		*/
	
	result=1+1;
	while(1)
	{
		result++;
		Delay(500);
		LCD_ShowNum(1,1,result,3);
	}
	
	
}