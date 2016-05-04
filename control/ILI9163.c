/*
 * ILI9163.c
 *
 *  Created on: 2014-7-21
 *      Author: comy
 */

#include "ILI9163.h"
#include "intrins.h"
#include "TFT_ascii.h"
//��ɫ����
uint TFT_color[]={
		0x07e0,//��
		0xf800,//��
		0xffe0,//��
		
		0x07ff,//��
		0x001f,//��
		0xf81f,//��
		0x0000,//��
		0xffff,//��
		0x7bef //��
};

/*��ʱ*/
void delay_ms(int x)		//@12.000MHz
{
	unsigned char i, j;

	i = 108;
	j = 145;
	do
	{
		while (--j);
	} while (--i);
}

uchar Flip(uchar Data)
{
	int i;
	uchar temp = 0x00;

	for (i = 7;i >= 0;i--)
	{
		temp |= ((Data&0x01) << i);
		Data >>= 1; 
	}

	return temp;
}

void Delay10us()		//@12.000MHz
{													  

	unsigned char i;

	i = 2;
	while (--i);
}

void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 5;
	j = 52;
	k = 195;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void TFT_char(uint x,uint y,uint font_color,uint back_color,char ch){
	uchar temp , Bytes;
	uchar pos,t;
	uint  CHAR_W,CHAR_H;  //һ���ַ��Ĵ�С

	//CHAR_W = 8;         //8*16
	//CHAR_H = 16;

	CHAR_W = 6;         //16*24  �ַ��Ĵ�СΪ16*24
	CHAR_H = 8;

	if(x>(TFT_size_x-CHAR_W)||y>(TFT_size_y-CHAR_H))   //���ָ�����ַ���ʾ��λ�ó����˲����ķֱ��ʣ��򷵻�
		return;
	LCD_SetPos( Flip(y), Flip(y+CHAR_H-1),Flip(x), Flip(x+CHAR_W-1)); //�����ַ���ʾ�ĵ�ַ��Χ
	ch = ch-32;                       //����ASCII����˳��õ���Ӧ��ĸ�ı���
	Bytes = (CHAR_W*CHAR_H)/8; //ÿ����ĸȡģ�ֽ���  һ���ֽ�Ϊ8λ��Ҳ����8�����ص���һ���ֽ�
	for(pos=0;pos<Bytes;pos++)  //һ���ֽ�һ���ֽڵ�д�룬֪������ַ���ȫ���ֽ���д��
	{
		// temp= Font8x16[ch][pos];  //8*16������
		temp= Font6x8[ch][pos];  //����Ĵ�СΪ16*24
		for(t=0;t<8;t++)   //һ���ֽ�Ϊ8λ������Ҫѭ��8��д�룬һ��ֻ��д��һ�����ص�
		{
			//�ж���������ʾ�ַ��ĵط��������Ǳ�����Ȼ��ֱ�д�벻ͬ����ɫ�Ϳ�����
			if(temp&0x80)   //�������ʾ�ַ��ĵط�
				Write_Data_U16(Flip(font_color));  //textcolor
			else   //������Ǳ����ĵط�
				Write_Data_U16(Flip(back_color));  //backcolor
			temp<<=1;   //����һλ
		}

	}
}

void TFT_string(uint x,uint y,uint font_color,uint back_color,char *p){
	while(*p!='\0'){	//�ж��Ƿ����ַ�����β
		TFT_char(y,x,font_color,back_color,*p);
		x+=6;
		p++;
	}
}

//д�Ĵ���ID���ӳ���
/******************************************************/
void WriteCOM(unsigned char ID)
{
//Flip (ID);
	rs_clr;
//	Delay10us();
	cs_clr;
	

//	Delay10us();
	TFT_DATA=0x00;
//	Delay10us();

	rw_clr;
	Delay10us();
	rw_set;

//	Delay10us();
	TFT_DATA=(ID);
//	Delay10us();

	rw_clr;
	Delay10us();
	rw_set;
//	Delay10us();
	rs_set;
//	Delay10us();
	cs_set;
}
/******************************************************
д���ݵ��ӳ���
******************************************************/
void WriteDAT(unsigned char HD,unsigned char LD) //д16λ����
{
 //Flip (HD);
//Flip (LD);	

	rs_set;
//	Delay10us();
	cs_clr;
//	Delay10us();

	TFT_DATA=(HD);
	rw_clr;
	Delay10us();
	rw_set;	
//	Delay10us();

	TFT_DATA=(LD);
	rw_clr;
	Delay10us();
	rw_set;
//	Delay10us();
	rs_clr;
//	Delay10us();
	cs_set;
}
void WriteDAT_8(unsigned char ddate)     //д8λ����
{
//Flip (ddate);		

	rs_set;
//	Delay10us();
	cs_clr;
//	Delay10us();
	
	TFT_DATA=(ddate);
	rw_clr;
	Delay10us();
	rw_set;
	Delay10us();
	
	rs_clr;
//	Delay10us();
	cs_set;
	
}
/******************************************************
����д�ַ���ͼ�ߵ�
*****************************************************/
void Write_Data_U16(unsigned int y)
{
	unsigned char m,n;
	m=y>>8; //��8λ
	n=y; //��8λ
	WriteDAT(m,n);
}

/******************************************************
IC ILI9163��ʼ��
******************************************************/
void ILI9163_init(void)
{
	rst_set;
	delay_ms(10);
	rst_clr;
	delay_ms(10);
	rst_set;
	delay_ms(10);
	WriteCOM(0x88);//�˳�˯��ģʽ
	delay_ms(10);
	WriteCOM(0x64);// Gammut format ٤����������
	WriteDAT_8(0x20);
	/* 04h GC3 Gammut 2.2��01h GC1 Gammut 1.0 , 02h GC2 gammut 1.8, 08h GC3 Gammut 2.5 */

	delay_ms(10);
	WriteCOM(0x8d);   //֡Ƶ����
	WriteDAT_8(0x60);
	WriteDAT_8(0x10);
	WriteDAT_8(0x90);

	WriteCOM(0x03);   //��Դ����
	WriteDAT_8(0x20);
	WriteDAT_8(0x00);

	WriteCOM(0x83);   //��Դ����
	WriteDAT_8(0xe0);

	WriteCOM(0xa3);   //ƫѹ����
	WriteDAT_8(0x32);  //vcom control 0x48,0x24 34 //2b
	WriteDAT_8(0x1c);  //vcom control 0x48,0x24 50 //47

	WriteCOM(0xe3);   //ƫѹ����
	WriteDAT_8(0x02);  //C4

	delay_ms(10);

	WriteCOM(0x5c);   // Interface Pixel mode
	WriteDAT_8(0xa0);
	/*0x05 16 bit/Pixel RGB 53-35 Twice per pixel for 80-8bits parallel
	0x06 18 bit/Pixel RGB 6-6-6 Three times per pixel for 80-8bits parallel */

	WriteCOM(0x6c);  //ɨ�跽�����
	//WriteDAT_8(0x15); //
	//WriteDAT_8(0x16);
	WriteDAT_8(0x14);
	//WriteDAT_8(0x17);

	WriteCOM(0xed);
	WriteDAT_8(0x00); //

	WriteCOM(0x4f);
	WriteDAT_8(0x80);
	delay_ms(10);

	// t Gamma,٤����������
	WriteCOM(0x07);// Positive 05
	WriteDAT_8(0x90);//1
	WriteDAT_8(0x68);//2
	WriteDAT_8(0x90);//3
	WriteDAT_8(0xe4);//4
	WriteDAT_8(0x74);//5
	WriteDAT_8(0xa4);//6
	WriteDAT_8(0x38);//7
	WriteDAT_8(0x04);//8
	WriteDAT_8(0x78);//9
	WriteDAT_8(0x58);//10
	WriteDAT_8(0x24);//11
	WriteDAT_8(0xb4);//12
	WriteDAT_8(0x20);//13
	WriteDAT_8(0xa0);//14
	WriteDAT_8(0x40);//15
	WriteDAT_8(0x70);//16
	WriteCOM(0x87); // Negative
	WriteDAT_8(0xd0);//1
	WriteDAT_8(0x28);//2
	WriteDAT_8(0x90);//3
	WriteDAT_8(0x64);//4
	WriteDAT_8(0xe4);//5
	WriteDAT_8(0x44);//6
	WriteDAT_8(0x38);//7
	WriteDAT_8(0x04);//8
	WriteDAT_8(0xb8);//9
	WriteDAT_8(0x58);//10
	WriteDAT_8(0xa4);//11
	WriteDAT_8(0xb4);//12
	WriteDAT_8(0x60);//13
	WriteDAT_8(0x60);//14
	WriteDAT_8(0x40);//15
	WriteDAT_8(0xf0);//16

	WriteCOM(0x94); //Display on
	delay_ms(10);
	WriteCOM(0x34); //write to RAM
}

/******************************************************
��ַ����
******************************************************/
void add_rst(void)   //��ַ����
{
	WriteCOM(0x54);      //Colulm addRSTs set
	WriteDAT_8(0x00);
	WriteDAT_8(0x00);
	WriteDAT_8(0x00);
	WriteDAT_8(0xf9);

	WriteCOM(0xd4);      //Colulm addRSTs set
	WriteDAT_8(0x00);
	WriteDAT_8(0x00);
	WriteDAT_8(0x00);
	WriteDAT_8(0x01);

	WriteCOM(0x34);      //Write Data to GRAM	   
}
void LCD_SetPos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1)
{
	WriteCOM(0x54);    //Colulm addRSTs set
	WriteDAT_8(x0>>8);  //ȡx0�ĸ�8λ
	WriteDAT_8(x0);     //ȡx0�ĵ�8λ

	WriteDAT_8(x1>>8);
	WriteDAT_8(x1);

	WriteCOM(0xd4);      //Colulm addRSTs set
	WriteDAT_8(y0>>8);
	WriteDAT_8(y0);

	WriteDAT_8(y1>>8);
	WriteDAT_8(y1);

	WriteCOM(0x34);      //Write Data to GRAM
}
/*****************************************************
��������display()
���ܣ���ʾ������ɫ����ɫ��d1,d2����
******************************************************/
void display(unsigned int colour)
{

	unsigned int c,s;
	add_rst(); 
	for(c=0;c<160;c++)    //����ɨ��
	{
	   for(s=0;s<128;s++)
	   {
	   	 WriteDAT(colour>>8,colour);
	   }
	}
	delay_ms(200);
}
/******************************************************
��������LCD_ico
���ܣ�����ʼλ��Ϊxs��ys����x����y��������д���С
Ϊx*y��ͼ��ico
******************************************************/
void LCD_ico(unsigned char xs,unsigned char ys,unsigned char x,unsigned char y,unsigned char ico[])
{
	unsigned int i;
	LCD_SetPos(xs,xs+x-1,ys,ys+y-1);
	for(i=0;i<x*y*2-1;i=i+2)    //
	{
	   WriteDAT(ico[i],ico[i+1]);    //
	}
}
/******************************************************
��������LCD_clear
���ܣ�����ʼλ��Ϊxs��ys����x����y��������д��ɫ
*****************************************************/
void LCD_clear(unsigned char xs,unsigned char ys,unsigned char x,unsigned char y)
{
	unsigned int i;
	LCD_SetPos(xs,xs+x-1,ys,ys+y-1);
	for(i=0;i<x*y*2-2;i=i+2)    //
	{
	   WriteDAT(0xff,0xff);    //
	}
}

/******************************************************
��������LCD_write_kong
���ܣ�д�հ���ʾ�ڱ��xλ��
******************************************************/
void LCD_write_kong(unsigned char y)
{
	unsigned char m,n;
	   LCD_SetPos((y%3)*42+y%3,(y%3)*42+42-1+y%3,(y/3)*42+y/3,(y/3)*42+42-1+y/3); //ram ready
	for(n=0;n<42;n++) //
	for(m=0;m<42;m++)
	{
	   WriteDAT(0xFF,0x77); //�ݶ�Ϊ ɫ
	}
}
/******************************************************
��������LCD_write_part
���ܣ���ͼƬ������ȡ����Ӧ��x�Ĳ�����ʾ�ڱ��yλ����
   ÿһС���ִ�С�ݶ�Ϊ42x42��
******************************************************/
void LCD_write_part(unsigned char y,unsigned char x,unsigned char img[])
{
	unsigned char m,n;
	   LCD_SetPos((y%3)*42+y%3,(y%3)*42+42-1+y%3,(y/3)*42+y/3,(y/3)*42+42-1+y/3); //ram ready
	if(x==8)
	   LCD_write_kong(y);
	else
	{
	   for(n=0;n<42;n++)
	   {
	   	 for(m=0;m<42;m++)
		    {
		     WriteDAT(img[2*(m+126*n+42*(x%3)+126*42*(x/3))],img[2*(m+126*n+42*(x%3)+126*42*(x/3))+1]);    //
		    }
		}
	}
}

/******************************************************
��x�У���y�У���ɫfColor
*****************************************************/
void LCD_bot(uchar x,uchar y,unsigned int fColor)
{
	LCD_SetPos(Flip(x),Flip(x+1),Flip(y),Flip(y+1));
	Write_Data_U16(fColor);
}

/******************************************************
�Բ��Գ�������ˢ8����ɫ
*******************************************************/
void TFT_Test()
{
	unsigned char i;  
	
	ILI9163_init();
	for(i=0;i<8;i++)
	{		
		display(TFT_color[i]);   //white FULL
	 	Delay100ms();
	}
}

void write_ascii(uchar x,uchar y,char p)
{
	int i,n,temp,x0 = x;
	for (i = 0;i < 6; i++)
	{
		temp = 0x80;
		for (n = 0;n < 8;n++)				   
		{
			if ( (Font6x8[p - 32][i] & temp))
			{	
				LCD_bot(y,x,TFT_color[0]);
			}
			else 
			{
				LCD_bot(y,x,TFT_color[7]);	
			}	
			
			x --;								  

			temp >>= 1;
		}
		y ++;
		x = x0;
	}	
}

void write_ascii_string(uint y,uint x,char *p)
{
	while(*p!='\0')
	{	
	//�ж��Ƿ����ַ�����β	
		write_ascii(x,y,*p);
		y+=6;
		p++;
	}	
}

void dispaly_byte(int y,uchar P)
{
	int i;
	uchar temp;	

	temp = 	0x80;
	for (i = 0;i < 8;i ++)
	{	
		if ( !(P&temp))
		{	
			write_ascii_string(3+i*7,y,"0");	
		}
		else 
		{
			write_ascii_string(3+i*7,y,"1");	
		}
		
		temp >>= 1;	
	}
		
}