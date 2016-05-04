/*
 * ILI9163.h
 *
 *  Created on: 2014-12-31
 *      Author: hanying
 */

#ifndef ILI9163_H_
#define ILI9163_H_

#include <STC15F2K60S2.H>
#include "delay_xs.h"
//#include "TFT_ascii.h"

sbit rs_tft = P2^0;
sbit wr_tft = P4^4;
sbit rst_tft = P4^2;
sbit cs_tft = P4^1;

#define cs_set cs_tft = 1
#define cs_clr cs_tft = 0

#define rst_set rst_tft = 1
#define rst_clr rst_tft = 0

#define rw_set wr_tft = 1
#define rw_clr wr_tft = 0

#define rs_set rs_tft = 1
#define rs_clr rs_tft = 0

#define TFT_DATA P3

#define TFT_size_x 128
#define TFT_size_y 160

extern uint TFT_color[];

extern void TFT_char(uint x,uint y,uint font_color,uint back_color,char ch);
extern void TFT_string(uint x,uint y,uint font_color,uint back_color,char *p);

extern void WriteCOM(unsigned char ID);
extern void WriteDAT(unsigned char HD,unsigned char LD); //写16位数据
extern void WriteDAT_8(unsigned char ddate);     //写8位数据
extern void Write_Data_U16(unsigned int y);
extern void ILI9163_init(void);
extern void add_rst(void);   //地址重置
extern void LCD_SetPos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1);
extern void display(unsigned int colour);
extern void LCD_ico(unsigned char xs,unsigned char ys,unsigned char x,unsigned char y,unsigned char ico[]);
extern void LCD_clear(unsigned char xs,unsigned char ys,unsigned char x,unsigned char y);
extern void LCD_write_kong(unsigned char y);
extern void LCD_write_part(unsigned char y,unsigned char x,unsigned char img[]);
extern void LCD_bot(unsigned char x,unsigned char y,unsigned int fColor);	 //在x，y处写一个颜色为fColor点
extern void TFT_Test();							   //测试函数
extern void write_ascii(uchar x,uchar y,char p);   //写单个字符
void write_ascii_string(uint x,uint y,char *p);	   //写多个字符
void dispaly_byte(int y,uchar P);   //显示位

#endif /* ILI9163_H_ */
