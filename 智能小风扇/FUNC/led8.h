#include<reg52.h>

#define DataPort P0 //�������ݶ˿� ����������DataPort ����P0 �滻
sbit LATCH1=P2^2;//��������ʹ�ܶ˿� ������
sbit LATCH2=P2^3;//                 λ����

void Display(unsigned char FirstBit,unsigned char Num);
