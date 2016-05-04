# include "LED_guanglifang.h"

uchar display[8][8];

void delay5us(void)   //误差 -0.026765046296us STC 1T 22.1184Mhz
{
    unsigned char b;
    for(b=7;b>0;b--);
        //for(a=2;a>0;a--);
}

void delay(uint i)
{                                                                                                     

     while (i--){
	 delay5us();}//12t的mcu 注释这个延时即可
}

void clear(char le)

{
         uchar i,j;
         for (j=0;j<8;j++)
         {
                   for (i=0;i<8;i++)
                   display[j][i]=le;
         }
}

void set(uchar x,uchar y,uchar z)
{
	display[x][y] |= 0x01<<z;
}

void clr(uchar x,uchar y,uchar z)
{
	display[x][y] &=~(0x01<<z);
}