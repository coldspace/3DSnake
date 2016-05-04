# ifndef _LED_GUANGLIFANG_H_
# define _LED_GUANGLIFANG_H_

# include <STC12C5A60S2.H>
#include <intrins.h>

#define uchar unsigned char
#define uint unsigned int

extern void clr(uchar x,uchar y,uchar z);
extern void set(uchar x,uchar y,uchar z);
extern void delay5us(void);   //Îó²î -0.026765046296us STC 1T 22.1184Mhz
extern void delay(uint i); 

# endif 