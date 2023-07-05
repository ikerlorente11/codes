/*
 * 1602Һ����ʾģ��
 *
 * AUTHOR			WHAT		DATE
 * Huafeng Lin		created 	2011/10/08
 * Huafeng Lin		modified 	2011/10/08
 *
 */

#include"Lcd.h"

sbit RS=P0^2;  
sbit RW=P0^1;  
sbit E=P0^0;
  
#define busy  0x80

void delay_LCM(uchar k)	//��ʱ����   
{   
	uint i,j;
    for(i=0;i<k;i++)
    {
        for(j=0;j<60;j++)
        	{;}
    }
}   

void test_1602busy()//��æ����  
{  
    P2=0xff;   
    E=1;
	RS=0;
	RW=1;   
    _nop_();
	_nop_();   
  	while(P2&busy)	//���LCD DB7 �Ƿ�Ϊ1
	{
		E=0;
	   	_nop_();
	   	E=1;
	   	_nop_();
	}
   	E=0;  
}   

void write_1602Command(uchar co)  //д����� 
{ 
	test_1602busy();   	//���LCD�Ƿ�æ
    RS=0;
	RW=0;
	E=0;   
    _nop_(); 
    P2=co;          
    _nop_();  
    E=1;  				//LCD��ʹ�ܶ˸ߵ�ƽ��Ч
    _nop_();  
    E=0;   
}   

void write_1602Data(uchar Data)//д���ݺ���   
{
	test_1602busy(); 
	P2=Data; 
	RS=1;
	RW=0;
	E=1;   
	_nop_();
	E=0; 
}   

void init_1602(void)//��ʼ������  
{   
	write_1602Command(0x38);  //LCD�����趨,DL=1(8λ),N=1(2����ʾ)
	delay_LCM(5); 
	write_1602Command(0x01);  //���LCD����Ļ
	delay_LCM(5);  
	write_1602Command(0x06);  //LCDģʽ�趨,I/D=1(������ַ��1)
	delay_LCM(5);  
	write_1602Command(0x0F);  //��ʾ��Ļ
	delay_LCM(5);
}

void reset_1602(void)
{
	write_1602Command(0x01);
	delay_LCM(5);  
	write_1602Command(0x06);
	delay_LCM(5);  
	write_1602Command(0x0c);
	delay_LCM(5);
} 

void DisplayOneChar(uchar X,uchar Y,uchar DData)
{
    Y&=1;
    X&=15;
    if(Y)X|=0x40;               //��yΪ1����ʾ�ڶ��У�����ַ��+0X40
    X|=0x80;                    //ָ����Ϊ��ַ��+0X80
    write_1602Command(X);
    write_1602Data(DData);
}

void display_1602(uchar *DData,X,Y)//��ʾ����  
{   
    uchar ListLength=0;
    Y&=0x01;
    X&=0x0f;
    while(X<16)
    {
        DisplayOneChar(X,Y,DData[ListLength]);
        ListLength++;
        X++;
    } 
}

