/*
 * ILI9163.c
 *
 *  Created on: 2014-7-21
 *      Author: comy
 */

#include "ILI9163.h"
#include "intrins.h"
#include "TFT_ascii.h"
//颜色定义
uint TFT_color[]={
		0x07e0,//绿
		0xf800,//红
		0xffe0,//黄
		
		0x07ff,//青
		0x001f,//蓝
		0xf81f,//紫
		0x0000,//黑
		0xffff,//白
		0x7bef //灰
};

/*延时*/
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
	uint  CHAR_W,CHAR_H;  //一个字符的大小

	//CHAR_W = 8;         //8*16
	//CHAR_H = 16;

	CHAR_W = 6;         //16*24  字符的大小为16*24
	CHAR_H = 8;

	if(x>(TFT_size_x-CHAR_W)||y>(TFT_size_y-CHAR_H))   //如果指定的字符显示的位置超过了彩屏的分辨率，则返回
		return;
	LCD_SetPos( Flip(y), Flip(y+CHAR_H-1),Flip(x), Flip(x+CHAR_W-1)); //设置字符显示的地址范围
	ch = ch-32;                       //按照ASCII编码顺序得到相应字母的编码
	Bytes = (CHAR_W*CHAR_H)/8; //每个字母取模字节数  一个字节为8位，也即是8个像素点是一个字节
	for(pos=0;pos<Bytes;pos++)  //一个字节一个字节的写入，知道这个字符的全部字节数写完
	{
		// temp= Font8x16[ch][pos];  //8*16的字体
		temp= Font6x8[ch][pos];  //字体的大小为16*24
		for(t=0;t<8;t++)   //一个字节为8位，所以要循环8次写入，一次只能写入一个像素点
		{
			//判断哪里是显示字符的地方，哪里是背景，然后分别写入不同的颜色就可以了
			if(temp&0x80)   //如果是显示字符的地方
				Write_Data_U16(Flip(font_color));  //textcolor
			else   //否则就是背景的地方
				Write_Data_U16(Flip(back_color));  //backcolor
			temp<<=1;   //右移一位
		}

	}
}

void TFT_string(uint x,uint y,uint font_color,uint back_color,char *p){
	while(*p!='\0'){	//判断是否到了字符串结尾
		TFT_char(y,x,font_color,back_color,*p);
		x+=6;
		p++;
	}
}

//写寄存器ID的子程序
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
写数据的子程序
******************************************************/
void WriteDAT(unsigned char HD,unsigned char LD) //写16位数据
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
void WriteDAT_8(unsigned char ddate)     //写8位数据
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
用于写字符，图线等
*****************************************************/
void Write_Data_U16(unsigned int y)
{
	unsigned char m,n;
	m=y>>8; //高8位
	n=y; //低8位
	WriteDAT(m,n);
}

/******************************************************
IC ILI9163初始化
******************************************************/
void ILI9163_init(void)
{
	rst_set;
	delay_ms(10);
	rst_clr;
	delay_ms(10);
	rst_set;
	delay_ms(10);
	WriteCOM(0x88);//退出睡眠模式
	delay_ms(10);
	WriteCOM(0x64);// Gammut format 伽马曲线设置
	WriteDAT_8(0x20);
	/* 04h GC3 Gammut 2.2，01h GC1 Gammut 1.0 , 02h GC2 gammut 1.8, 08h GC3 Gammut 2.5 */

	delay_ms(10);
	WriteCOM(0x8d);   //帧频控制
	WriteDAT_8(0x60);
	WriteDAT_8(0x10);
	WriteDAT_8(0x90);

	WriteCOM(0x03);   //电源控制
	WriteDAT_8(0x20);
	WriteDAT_8(0x00);

	WriteCOM(0x83);   //电源控制
	WriteDAT_8(0xe0);

	WriteCOM(0xa3);   //偏压控制
	WriteDAT_8(0x32);  //vcom control 0x48,0x24 34 //2b
	WriteDAT_8(0x1c);  //vcom control 0x48,0x24 50 //47

	WriteCOM(0xe3);   //偏压控制
	WriteDAT_8(0x02);  //C4

	delay_ms(10);

	WriteCOM(0x5c);   // Interface Pixel mode
	WriteDAT_8(0xa0);
	/*0x05 16 bit/Pixel RGB 53-35 Twice per pixel for 80-8bits parallel
	0x06 18 bit/Pixel RGB 6-6-6 Three times per pixel for 80-8bits parallel */

	WriteCOM(0x6c);  //扫描方向控制
	//WriteDAT_8(0x15); //
	//WriteDAT_8(0x16);
	WriteDAT_8(0x14);
	//WriteDAT_8(0x17);

	WriteCOM(0xed);
	WriteDAT_8(0x00); //

	WriteCOM(0x4f);
	WriteDAT_8(0x80);
	delay_ms(10);

	// t Gamma,伽马曲线设置
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
地址设置
******************************************************/
void add_rst(void)   //地址重置
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
	WriteDAT_8(x0>>8);  //取x0的高8位
	WriteDAT_8(x0);     //取x0的低8位

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
函数名：display()
功能：显示整屏颜色，颜色由d1,d2决定
******************************************************/
void display(unsigned int colour)
{

	unsigned int c,s;
	add_rst(); 
	for(c=0;c<160;c++)    //横向扫描
	{
	   for(s=0;s<128;s++)
	   {
	   	 WriteDAT(colour>>8,colour);
	   }
	}
	delay_ms(200);
}
/******************************************************
函数名：LCD_ico
功能：在起始位置为xs、ys，宽x、高y的区域内写入大小
为x*y的图像ico
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
函数名：LCD_clear
功能：在起始位置为xs、ys，宽x、高y的区域内写白色
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
函数名：LCD_write_kong
功能：写空白显示在编号x位置
******************************************************/
void LCD_write_kong(unsigned char y)
{
	unsigned char m,n;
	   LCD_SetPos((y%3)*42+y%3,(y%3)*42+42-1+y%3,(y/3)*42+y/3,(y/3)*42+42-1+y/3); //ram ready
	for(n=0;n<42;n++) //
	for(m=0;m<42;m++)
	{
	   WriteDAT(0xFF,0x77); //暂定为 色
	}
}
/******************************************************
函数名：LCD_write_part
功能：从图片数组中取出对应于x的部分显示在编号y位置上
   每一小部分大小暂定为42x42。
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
第x列，第y行，颜色fColor
*****************************************************/
void LCD_bot(uchar x,uchar y,unsigned int fColor)
{
	LCD_SetPos(Flip(x),Flip(x+1),Flip(y),Flip(y+1));
	Write_Data_U16(fColor);
}

/******************************************************
自测试程序，正屏刷8种颜色
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
	//判断是否到了字符串结尾	
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