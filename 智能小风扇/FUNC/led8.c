#include"led8.h"


unsigned char code DuanMa[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};// ��ʾ����ֵ0~F
unsigned char code WeiMa[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};//�ֱ��Ӧ��Ӧ������ܵ���,��λ��
unsigned char TempData[8]; //�洢��ʾֵ��ȫ�ֱ���


/*------------------------------------------------
����:��ʾ���������ڶ�̬ɨ�������
����:1) FirstBit��ʾ8x8���������Ҫ��ʾ�ĵ�һλ���縳ֵ2��ʾ�ӵ���������ܿ�ʼ��ʾ
	 2) Num��ʾ��Ҫ��ʾ��λ��������Ҫ��ʾ99��λ��ֵ���ֵ����2
------------------------------------------------*/
void Display(unsigned char FirstBit,unsigned char Num)
{
	static unsigned char i=0;

	DataPort=0;   //������ݣ���ֹ�н�����Ӱ
	LATCH1=1;     //������
	LATCH1=0;

	DataPort=WeiMa[i+FirstBit]; //ȡλ�� 
	LATCH2=1;     //λ����
	LATCH2=0;

	DataPort=TempData[i]; //ȡ��ʾ���ݣ�����
	LATCH1=1;     //������
	LATCH1=0;

	i++;
	if(i==Num)
		i=0;
}