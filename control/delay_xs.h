#ifndef DEALY_XS_H_
#define DEALY_XS_H_

# include  <STC15F2K60S2.H>

#define uchar unsigned char 
#define uint unsigned int 
#define ulong unsigned long
#define ushort unsigned short

void Delay_n100_us(int us);
void Delay_Nms(int ms);

# endif 