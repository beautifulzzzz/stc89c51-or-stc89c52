#include"display_4X8.h"

unsigned char code DuanMa[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};// ��ʾ����ֵ0~F
unsigned char code WeiMa[]={0xbf,0xdf,0xef,0xf7};//�ֱ��Ӧ��Ӧ������ܵ���,��λ��
unsigned char TempData[4]; //�洢��ʾֵ��ȫ�ֱ���

//------------------------------------------------
//4λ8�ι����������ʾ����
//��һ������Ϊ0��ʾ�ӵ�һ������ܿ�ʼ��ʾnum����
//��ǰҪ��ʾ����Ҫ����TempData�У�TempData[0]��ʾҪ��ʾ�ĵ�һ������
//------------------------------------------------
void Display(unsigned char FirstBit,unsigned char Num)
{
	static unsigned char i=0;

	DataPort=0x00;   //������ݣ���ֹ�н�����Ӱ
	DataControl=0x00;

	DataPort=TempData[i]; //ȡ��ʾ���ݣ�����
	DataControl=WeiMa[i+FirstBit];

	i++;
	if(i==Num)
		i=0;
}