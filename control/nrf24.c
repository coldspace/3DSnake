/*
ʱ�䣺2014��12��
���ߣ�����
��֯����ԴӲ��Э��
˵����ң������·�ֻ棬û�л�ԭ��ͼ
	  ��Ҫ�������ܵ�ͬѧ����鿴GetKey�����������Լ���ĥԭ��ͼ
	  ���������������ɨ�裬LCD������ʾ��NRF24L01����ģ�顣
	  ���а���ɨ�������ģ���Ǳ�Ҫ���룬���û�в����������ڳ����аѲ�����صĴ���
	  ע�͵���
	  ʹ�õ���STC15F2K60S2�ͺŵ�Ƭ����ʹ�õ����ڲ�ʱ��12M��
Ȩ��˵����ת����ע��˵������
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

/*���š���ʱ���ȳ�ʼ��*/
void init ()
{
	TMOD = 0x20;
	TH1 = 0xfd;
	TL1 = 0xfd;
	TR1 = 1;
	REN = 1;		   //   �����н���λ
	SM0 = 0;		   //	10λ�첽�����շ���8λ���ݣ�/
	SM1 = 1;		   //	�����ʿɱ䣨�ɶ�ʱ��1������ʿ��ƣ�
	EA = 1;
	ES = 1;

	CLK_DIV = 0x20;				 //���÷�Ƶ
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

/*�����ж�*/
void ser () interrupt 4
{
	RI = 0;
	a = SBUF;
}
/*���ڴ�ӡ����*/
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

/*��Һ��������ʾ���°�����λ��*/
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
	
	display(TFT_color[7]);		//��Ļ��ʾΪ��ɫ

	write_ascii_string(30, 80, "Checking 24l01");  //����Ļ����ʾ �޷��ҵ�оƬ
	while (NRF24L01_Check())	 //�ж�24l01�ܷ���
	{
		init_nrf ();
		Delay_Nms(200);
	}
	TX_MODE();	//��������ģ��Ϊ����ģʽ
	write_ascii_string(50, 60, "Success!");	   //24l01��ȡ�ɹ�
	Delay_Nms(5000);
	ILI9163_init();
	display(TFT_color[7]);	  	//����			 

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
ʱ�䣺2014��12��
���ߣ�����
��֯����ԴӲ��Э��
*/
void getkey()
{
	int i;
	char temp;
	
	P0 = 0xFF;
	P1 = 0xff;

	//��ֹ������ͻ 
	//���²���ͬʱ��
	//���Ҳ���ͬʱ��
	//B C����ͬʱ��
	//�������Ҫ��⣬��ע�͵����� 9�д���
	if ( !((P0 >> 1) & 0x01) )
		if (!((P0 >> 2) & 0x01))
			return ;
	if ( !((P0 >> 7) & 0x01) )
		if ( !((P1 >> 1) & 0x01))
			return ;
	if ( !((P0 >> 0) & 0x01))
		if ( !((P0 >> 3) & 0x01))
			return ;
	
	//��������Ϣд�뷢�仺������
	Textpackage[0] = ~P0;
	Textpackage[1] = ~(P1&0x03);

	//��������Ϣ��¼�ڽṹ��֮�У����������ʹ��
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
