# include "delay_xs.h"
# include <intrins.h>	  //包含_crol_的头文件  向右移动

void Delay_n100_us(int us)		//@12.000MHz
{
	unsigned char i, j;

	i = 2;
	j = 39 * us;
	do
	{
		while (--j);
	} while (--i);
}

void Delay_Nms(int ms)		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 10 * ms;
	j = 31;
	k = 147;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}