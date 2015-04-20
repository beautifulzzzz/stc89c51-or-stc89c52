/*-----------------------------------------------
���ƣ�������������ֱ���������
���ݣ���Ӧ�ĵ���ӿ����öŰ������ӵ�uln2003������ƶ�
ʹ��5V-12V С���ʵ���Կ� 2�������ֱ���ٺͼ���
------------------------------------------------*/
#include "../FUNC/led8.h"
#include "../FUNC/uart.h"
#include "../FUNC/key8.h"
#include "../INTE/inte.h"

sbit DCOUT = P1^1;//�������ź�����˿�
/*------------------------------------------------
ȫ�ֱ���
------------------------------------------------*/
unsigned char PWM_ON;   //�����ٶȵȼ�
#define CYCLE 10        //����

extern unsigned char code DuanMa[];// ��ʾ����ֵ
extern unsigned char TempData[8]; //�洢��ʾֵ��ȫ�ֱ���
/*------------------------------------------------
��������
------------------------------------------------*/
extern void Display(unsigned char FirstBit,unsigned char Num);//�������ʾ����
extern unsigned char KeyScan(void);//����ɨ��
extern void Init_Timer0(void);//��ʱ����ʼ��
/*------------------------------------------------
������
------------------------------------------------*/
void main (void)
{
	unsigned char num;                  
	PWM_ON=0;
	Init_Timer0();    //��ʼ����ʱ��0����Ҫ��������ܶ�̬ɨ��
	
	while (1)         //��ѭ��
	{
		num=KeyScan();    //ѭ�����ð���ɨ��
		if(num==1)//��һ������,�ٶȵȼ�����
		{
			if(PWM_ON<CYCLE)
				PWM_ON++;
		}	
		else if(num==2)//�ڶ����������ٶȵȼ���С
		{
			if(PWM_ON>0)
				PWM_ON--;
		}	
		TempData[0]=DuanMa[PWM_ON/10]; //��ʾ�ٶȵȼ�
		TempData[1]=DuanMa[PWM_ON%10]; 	 
	}
}
/*------------------------------------------------
��ʱ���ж��ӳ���
------------------------------------------------*/
void Timer0_isr(void) interrupt 1 
{
	static unsigned char count;
	TH0=(65536-2000)/256;		  //���¸�ֵ 2ms
	TL0=(65536-2000)%256;
	
	Display(6,2);                // ���������ɨ��
	
	if (count==PWM_ON) 
    {
		DCOUT = 0;               //�����ʱ����on��ʱ�䣬
		//˵������ʱ�����������͵�ƽ
    }
	count++;
	if(count == CYCLE)       //��֮�͵�ƽʱ������󷵻ظߵ�ƽ
    {
		count=0;
		if(PWM_ON!=0)    //�������ʱ����0 ����ԭ��״̬
			DCOUT = 1;      	
    }
}

