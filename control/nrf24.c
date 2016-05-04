/*
时间：2014年12月
作者：竹林
组织：开源硬件协会
说明：遥控器电路手绘，没有画原理图
	  需要按键功能的同学，请查看GetKey（）函数，自己琢磨原理图
	  本程序包括：按键扫描，LCD彩屏显示，NRF24L01无线模块。
	  其中按键扫描和无线模块是必要代码，如果没有彩屏，可以在程序中把彩屏相关的代码
	  注释掉。
	  使用的是STC15F2K60S2型号单片机，使用的是内部时钟12M。
权利说明：转载请注意说明出处
*/

# include <STC15F2K60S2.h> 
# include <stdio.h>
# include "nrf.h"
# include "ILI9163.h"

uchar Textpackage[5] = {0};
uchar keyboard[11] = {0};
uchar flag = 1,a,i;
uint addressdisk = 64;
struct KeyInfo{
	uchar up;
	uchar down;
	uchar left;
	uchar right;
	uchar mode;
	uchar pause;
	uchar A;
	uchar B;
	uchar C;
	uchar D;
}keyinfo;

void getkey();

/*引脚、定时器等初始化*/
void init ()
{
	TMOD = 0x20;
	TH1 = 0xfd;
	TL1 = 0xfd;
	TR1 = 1;
	REN = 1;		   //   允许串行接受位
	SM0 = 0;		   //	10位异步数据收发（8位数据）/
	SM1 = 1;		   //	波特率可变（由定时器1的溢出率控制）
	EA = 1;
	ES = 1;

	CLK_DIV = 0x20;				 //设置分频
	P3M1 = 0x00;
	P3M0 = 0x00;

	P2M1 = 0x00;
	P2M0 = 0x00;

	P4M1 = 0x00;
	P4M0 = 0x00;

	P1M1 = 0x00;
	P1M0 = 0x00;

	P0M1 = 0x00;
	P0M0 = 0x00; 

	ILI9163_init();
	//TX_MODE();
}

/*串口中断*/
void ser () interrupt 4
{
	RI = 0;
	a = SBUF;
}
/*串口打印函数*/
void println(uchar *p)
{
		int i;
		
		ES = 0;
		TI = 1;while (!TI);
		for (i = 0;i < 5 ;i ++)
			printf (" %d \n",p[i]);
		
		TI = 0;
		ES = 1;
	
}

/*在液晶上面显示按下按键的位置*/
void DisplayKey()
{
	write_ascii(addressdisk+20,30,keyinfo.up + 0x30);
	write_ascii(addressdisk-20,30,keyinfo.down + 0x30);
	write_ascii(addressdisk,10,keyinfo.left + 0x30);
	write_ascii(addressdisk,50,keyinfo.right + 0x30);
	
	write_ascii(addressdisk,75,keyinfo.mode + 0x30);
	write_ascii(addressdisk,95,keyinfo.pause + 0x30);
	
	write_ascii(addressdisk+15,120,keyinfo.A + 0x30);
	write_ascii(addressdisk+15,150,keyinfo.B + 0x30);
	write_ascii(addressdisk-15,120,keyinfo.C + 0x30);
	write_ascii(addressdisk-15,150,keyinfo.D + 0x30);
}

void main ()
{
	int i; 
	init ();
	Textpackage[0] = 0xf5;
	Textpackage[1] = 0x5f;
	
	display(TFT_color[7]);		//屏幕显示为白色

	write_ascii_string(30, 80, "Checking 24l01");  //在屏幕上显示 无法找到芯片
	while (NRF24L01_Check())	 //判断24l01能否工作
	{
		init_nrf ();
		Delay_Nms(200);
	}
	TX_MODE();	//设置无线模块为发送模式
	write_ascii_string(50, 60, "Success!");	   //24l01读取成功
	Delay_Nms(5000);
	ILI9163_init();
	display(TFT_color[7]);	  	//清屏			 

	while (1)
	{ 
		getkey(); 	
		while (!nRF24l01_TxPacket(Textpackage))
		{
			for (i = 0;i < 500;i ++);
		}
		DisplayKey();
	} 
}

/*
时间：2014年12月
作者：竹林
组织：开源硬件协会
*/
void getkey()
{
	int i;
	char temp;
	
	P0 = 0xFF;
	P1 = 0xff;

	//防止按键冲突 
	//上下不能同时按
	//左右不能同时按
	//B C不能同时按
	//如果不需要检测，则注释掉以下 9行代码
	if ( !((P0 >> 1) & 0x01) )
		if (!((P0 >> 2) & 0x01))
			return ;
	if ( !((P0 >> 7) & 0x01) )
		if ( !((P1 >> 1) & 0x01))
			return ;
	if ( !((P0 >> 0) & 0x01))
		if ( !((P0 >> 3) & 0x01))
			return ;
	
	//将按键信息写入发射缓冲数组
	Textpackage[0] = ~P0;
	Textpackage[1] = ~(P1&0x03);

	//将按键信息记录在结构体之中，方便后续的使用
	keyinfo.left = (Textpackage[0] >> 0) & 0x01;
	keyinfo.up   = (Textpackage[0] >> 1) & 0x01;
	keyinfo.down = (Textpackage[0] >> 2) & 0x01;
	keyinfo.right= (Textpackage[0] >> 3) & 0x01;
	keyinfo.mode = (Textpackage[0] >> 4) & 0x01;
	keyinfo.pause= (Textpackage[0] >> 5) & 0x01;
	keyinfo.C    = (Textpackage[0] >> 6) & 0x01;
	keyinfo.D    = (Textpackage[0] >> 7) & 0x01;	
	keyinfo.A    = (Textpackage[1] >> 0) & 0x01;
	keyinfo.B    = (Textpackage[1] >> 1) & 0x01;
}
