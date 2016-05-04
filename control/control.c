# include  <STC15F2K60S2.H>
# include "ILI9163.h"

void init_iap()
{
//	AUXR=0X40;
	CLK_DIV = 0x20;				 //…Ë÷√∑÷∆µ
	P3M1 = 0x00;
	P3M0 = 0x00;

	P2M1 = 0x00;
	P2M0 = 0x00;

	P4M1 = 0x00;
	P4M0 = 0x00;
}  

int main(void)
{
	/* code */
	init_iap();
//	ILI9163_init();


	while(1)
	{
		TFT_Test();
	//	Delay_Nms(1000);
	}  

//	P3 = 0xff;
	
	return 0;
}				 