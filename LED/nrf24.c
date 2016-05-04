//#include <REG52.H>
#include <STC12C5A60S2.H>
#include <intrins.h>
# include <stdlib.h>
#include "nrf.h"
//# include "corrupt_snack.h"
//# include "LED_guanglifang.h"

#define uchar unsigned char
#define uint unsigned int

uchar display[8][8];
uchar Textpackage[5] = {0};
uchar LED_key[2] = {0}; 
int snack_long;	   	//��������ĳ���
int number = 1,food_ture = 1;
int snack_die = 0;
unsigned xdata nAsciiDot[] =              // ASCII
{
	0x38,0x44,0x44,0x44,0x44,0x44,0x44,0x38,  // -0-

	0x30,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,  // -1-

	0x38,0x44,0x04,0x08,0x10,0x20,0x44,0x7C,  // -2-

	0x38,0x44,0x04,0x18,0x04,0x04,0x44,0x38,  // -3-

	0x0C,0x14,0x14,0x24,0x44,0x7C,0x04,0x0C,  // -4-

	0x3C,0x20,0x20,0x38,0x04,0x04,0x44,0x38,  // -5-

	0x1C,0x20,0x40,0x78,0x44,0x44,0x44,0x38,  // -6-

	0x7C,0x44,0x04,0x08,0x08,0x08,0x10,0x10,  // -7-

	0x38,0x44,0x44,0x38,0x44,0x44,0x44,0x38,  // -8-

	0x38,0x44,0x44,0x44,0x3C,0x04,0x08,0x70  // -9-
};

struct Sack			 //�����߽ڵĿռ�����
{
	char x;
	char y;
	char z;
};

struct Food		  //����ʳ��λ�� 
{
	uchar x;
	uchar y;
	uchar z;
}snack_food;

static xdata struct Sack snack[512];	 //��������߽�Ϊ512

void setfood ();

void delay5us(void)   //��� -0.026765046296us STC 1T 22.1184Mhz
{
    unsigned char b;
    for(b=7;b>0;b--);
        //for(a=2;a>0;a--);
}

void delay(uint i)
{                                                                                                     

     while (i--){
	 delay5us();}//12t��mcu ע�������ʱ����
}

void delay_ms(int ms)	   //��ʱ ms
{
	uint i,n;

	for (i = 0;i < 24 * ms;i ++)
		for (n = 0;n < 110;n ++);
}

/* ��������������*/
void clear(char le)		 	//�����еĵ� ����Ϊ��������
{
         uchar i,j;
         for (j=0;j<8;j++)
         {
                   for (i=0;i<8;i++)
                   display[j][i]=le;
         }
}

void set(uchar x,uchar y,uchar z)	   //����x��y��z���ĵ�Ϊ��
{
	display[x][y] |= 0x01<<z;
}

void clr(uchar x,uchar y,uchar z)	   //����x��y��z���ĵ�Ϊ��
{
	display[x][y] &=~(0x01<<z);
}
/*end  ��������������*/

/*̰������������*/

void set_led(struct Sack Buf)	 		//��ʾ�߽ڵ�λ��
{
	set(Buf.x,Buf.y,Buf.z);
}

void clr_led(struct Sack Buf)		   //Ϩ�� �߽�
{
	clr(Buf.x,Buf.y,Buf.z);	
}

void setfood ()
{
	int i;
	srand(number);	
	snack_food.x = (uchar)rand()%8;
	snack_food.y = (uchar)rand()%8;
	snack_food.z = (uchar)rand()%8;

	for (i = 0;i <= snack_long;i ++)
	{
		if ( (snack_food.x == snack[i].x) && (snack_food.y == snack[i].y) && (snack_food.z == snack[i].z) )
		{
			setfood();
		}
	}
	
	set(snack_food.x,snack_food.y,snack_food.z);		
}

void move()	   //�ƶ�
{
	int i;
	static int x = 1,y = 1,z = 1;
	struct Sack linshi_snack,last_snack;

	linshi_snack = snack[0];		 //��linshi_snack��¼����ͷ��ֵ
	last_snack = snack[snack_long];
	
	//�ж��Ƿ��а�����Ϣ
	if ( ( (LED_key[0] & 0x8f) != 0x00) || ( (LED_key[1] & 0x02) == 0x02) )
	{		
		for (i = 0;i < 8;i ++)
		{
			switch(LED_key[0] & (0x01 << i))
			{
				case 0x01: 
					if ( ((linshi_snack.y - 1) != snack[1].y) && (linshi_snack.y != (snack[1].y - 7)))
					{
						linshi_snack.y --;
					}
					else 
					{
						linshi_snack.y ++;	
					}
					
					if (linshi_snack.y < 0)
					{
						linshi_snack.y = 7;
						y = 0;
					}

					if (linshi_snack.y > 7)
					{
						linshi_snack.y = 0;
						y = 0;
					}
					break;
				case 0x02: 
					if ( ((linshi_snack.z - 1) != snack[1].z) && (linshi_snack.z != (snack[1].z - 7)))
					{
						linshi_snack.z --;
					}
					else 
					{
						linshi_snack.z ++;	
					}

					if (linshi_snack.z < 0)
					{
						linshi_snack.z = 7;
						z = 0;
					}

					if (linshi_snack.z > 7)
					{
						linshi_snack.z = 0;
						z = 0;
					}
					break;
				case 0x04: 
					if ( ((linshi_snack.z + 1) != snack[1].z) && (linshi_snack.z != (snack[1].z + 7)))
					{
						linshi_snack.z ++;
					}
					else 
					{
						linshi_snack.z --;	
					}
					
					if (linshi_snack.z > 7)
					{
						linshi_snack.z = 0;
						z = 0;
					}

					if (linshi_snack.z < 0)
					{
						linshi_snack.z = 7;
						z = 0;
					}
					break;
				case 0x08:
					if ( ((linshi_snack.y + 1) != snack[1].y) && (linshi_snack.y != (snack[1].y + 7)))
					{
						linshi_snack.y ++;
					}
					else 
					{
						linshi_snack.y --;	
					}
					
					if (linshi_snack.y > 7)
					{
						linshi_snack.y = 0;
						y = 0;
					}

					if (linshi_snack.y < 0)
					{
						linshi_snack.y = 7;
						y = 0;
					}
					break;
				case 0x10: break;
				case 0x20: break;
				case 0x40: break;
				case 0x80: 
					if ( ((linshi_snack.x + 1) != snack[1].x) && (linshi_snack.x != (snack[1].x + 7)))
					{
						linshi_snack.x ++;
					}
					else 
					{
						linshi_snack.x --;	
					}
					if (linshi_snack.x > 7)
					{
						linshi_snack.x = 0;
						x = 0;
					}

					if (linshi_snack.x < 0)
					{
						linshi_snack.x = 7;
						x = 0;
					}
					break;
				default : break;
			}
		}
	
		if ((LED_key[1]&0x02) == 0x02)
		{
			if ( ((linshi_snack.x - 1) != snack[1].x) && (linshi_snack.x != (snack[1].x - 7)))
			{
				linshi_snack.x --;
			}
			else 
			{
				linshi_snack.x ++;	
			}
			if (linshi_snack.x < 0)
			{
				linshi_snack.x = 7;
				x = 0;
			}

			if (linshi_snack.x > 7)
			{
				linshi_snack.x = 0;
				x = 0;
			}
		}

		if (food_ture)
		{
			setfood();
			food_ture = 0;
		}
			
	} 
	/*�ж��������еķ���*/
	else 
	{	 
		if(snack[0].x != snack[1].x)	//�ж��ƶ������Ƿ���x�᷽��
		{
			if (x)
			{
				if(snack[0].x > snack[1].x)	//�ж���x���������͸�����
				{
					linshi_snack.x ++;		//̰���ߵ�ͷ��ǰ�ƶ�
					if (linshi_snack.x > 7)
					{
						linshi_snack.x = 0;
						x = 0;
					}
				}
				else 
				{
					linshi_snack.x --;	
					if (linshi_snack.x < 0)
					{
						linshi_snack.x = 7;
						x = 0;
					}
				}
			}

			else 
			{
				if(snack[0].x < snack[1].x)	//�ж���x���������͸�����
				{
					linshi_snack.x ++;		//̰���ߵ�ͷ��ǰ�ƶ�
				}
				else 
				{
					linshi_snack.x --;	
				}
				x = 1;	
			}
		}					
	
	
		if(snack[0].y != snack[1].y)
		{
			if (y)
			{			
				if(snack[0].y > snack[1].y)	//�ж���y���������͸�����
				{
					linshi_snack.y ++;		//̰���ߵ�ͷ��ǰ�ƶ�
					if (linshi_snack.y > 7)
					{
						linshi_snack.y = 0;
						y = 0;
					}
				}
				else 
				{
					linshi_snack.y --;
					if (linshi_snack.y < 0)
					{
						linshi_snack.y = 7;
						y = 0;
					}	
				}
			}
			else 
			{
				if(snack[0].y < snack[1].y)	//�ж���y���������͸�����
				{
					linshi_snack.y ++;		//̰���ߵ�ͷ��ǰ�ƶ�
				}
				else 
				{
					linshi_snack.y --;	
				}
				y = 1;	
			}		
		}
	
		if(snack[0].z != snack[1].z)
		{
			if (z)
			{			
				if(snack[0].z > snack[1].z)	//�ж���z���������͸�����
				{
					linshi_snack.z ++;		//̰���ߵ�ͷ��ǰ�ƶ�
					if (linshi_snack.z > 7)
					{
						linshi_snack.z = 0;
						z = 0;
					}
				}
				else 
				{
					linshi_snack.z --;
					if (linshi_snack.z < 0)
					{
						linshi_snack.z = 7;
						z = 0;
					}	
				}
			}
			else 
			{
				if(snack[0].z < snack[1].z)	//�ж���z���������͸�����
				{
					linshi_snack.z ++;		//̰���ߵ�ͷ��ǰ�ƶ�
				}
				else 
				{
					linshi_snack.z --;	
				}
				z = 1;	
			}	
		}
	} 
	clr_led (last_snack);  //������ǰ�ƶ�һ�� ����������һ������
	if ( (snack_food.x == snack[0].x) && (snack_food.y == snack[0].y) && (snack_food.z == snack[0].z) )
	{
		snack_long ++;
		setfood();	
	}
		   
	/*���������Ҳ������ǰ�ƶ�һ��*/
	for (i = snack_long;i > 0;i --)
	{
		snack[i] = snack[i - 1];
	}
	snack[0] = linshi_snack;	
	/*�ж��Ƿ�����*/
	for (i = 1;i < snack_long;i ++)
	{
		if ( (snack[i].x == snack[0].x) && (snack[i].y == snack[0].y) && (snack[i].z == snack[0].z) )
		{
			snack_die = 1;
		}
	}

	for (i = 0;i <= snack_long;i ++)   //��ʾ���е�����
	{
		set_led(snack[i]);
	} 

	//set_led (snack[0]);
}

void init_snack()
{
	uchar i;
	snack[0].x = 3;
	snack[0].y = 5;
	snack[0].z = 3;	

	snack[1].x = 3;
	snack[1].y = 4;
	snack[1].z = 3;
	
	snack[2].x = 3;
	snack[2].y = 3;
	snack[2].z = 3;	
	snack_long = 2;

	clear(0);

	for (i = 0;i <= snack_long ;i ++)
	{	
		set_led (snack[i]);	
	}	 
}

uchar getkey ()
{
	int i;
	i = 0;
	while (NRF24L01_RXPacket(Textpackage)) 
	{
		if ( ( Textpackage[0] != 0x00) || ( (Textpackage[1] & 0x03) != 0x00 ) )
		{
			LED_key[0] = Textpackage[0];
			LED_key[1] = Textpackage[1];
		}
		
		i ++;
		
		if (i == 2)
			break;		
	}
	
	return 1;	
}

void playgame()
{
	int i,n,b;
	i = 0;

/*	for (b = 0;b < 500;b++)
		{	
			for (i = 0;i < 12;i++)
				for (n = 0;n < 110;n ++);				
										
			getkey();	  //�õ�������Ϣ
		}*/
	
	while (1)
	{
		for (b = 0;b < 200;b++)
		{	
			for (i = 0;i < 12;i++)
				for (n = 0;n < 110;n ++);				
										
			getkey();	  //�õ�������Ϣ
		}
				
		move();	
		if (snack_die)  // ��Ϸ����
			break;
	}
}

void display_number(int number,int y)
{
	int i,n;
	uint temp;
	for (i = 0;i < 8;i ++)
	{
		temp = nAsciiDot[number * 8 + i];
		for (n = 0;n < 8;n ++)
		{
			if ( ((temp & 0x80) >> 7) & 0x01)
				set (i,n,y);
			else 
				clr (i,n,y);
			
			temp <<= 1;
		}
	}
}

void display_grade()
{
	int i;
	uint grade_unit,grade_ten,grade_hundred;
	
	grade_hundred = snack_long / 100;
	grade_ten = (snack_long - grade_hundred*100) / 10;
	grade_unit = snack_long % 10;
	
	if (grade_hundred > 0)
	{
		for (i = 7;i >= 0;i --)
		{
			display_number(grade_hundred,i);
			delay_ms(50);
			clear(0);
		}
	}
	
	if ((grade_hundred > 0) || (grade_ten > 0))
	{
		for (i = 7;i >= 0;i --)
		{
			display_number(grade_ten,i);
			delay_ms(50);
			clear(0);
		}
	}
	
	for (i = 7;i >= 0;i --)
	{
		display_number(grade_unit,i);
		delay_ms(50);
		clear(0);
	}
}
void Snack()
{
	while (1)
	{
		if (snack_die)
		{
			clear(0);
			display_grade();
		}
		init_snack ();
		
		if (snack_die)
		{
			setfood();
			snack_die = 0;
		}
		
		playgame();
	}
}

/*end ̰������������*/

/*nrf���Ժ���*/
void Text()
{
	int i;
	int temp;
	while (NRF24L01_RXPacket(Textpackage)) 
	{
		for(i = 0;i < 500;i++);
		set(1,1,2);
	}
	clr (1,1,2); 
	set (1,1,3); 	
	
	clr(snack[0].x,snack[0].y,snack[0].z);
	
	temp = Textpackage[0];
		
	for (i = 0;i < 8;i ++)
	{
		switch(Textpackage[0] & (0x01 << i))
		{
			case 0x01: snack[0].y --;break;
			case 0x02: snack[0].z --;break;
			case 0x04: snack[0].z ++;break;
			case 0x08: snack[0].y ++;break;
			case 0x10: break;
			case 0x20: break;
			case 0x40: break;
			case 0x80: snack[0].x ++;break;
			default : break;
		}
	}

	if ((Textpackage[1]&0x02) == 0x02)
	{
		snack[0].x --;
	}

	set(snack[0].x,snack[0].y,snack[0].z);
}
/*end nrf���Ժ���*/

//�ⲿ�жϳ�ʼ��
void INT1_init(void)
{
	IE=0x82;
	TCON=0x01;
	TH0=0xc0;
	TL0=0;
	TR0=1;
	EA = 1;
}

/*From now on,the function below is to display the flash.*/
void main()
{		
	INT1_init();		//�жϳ�ʼ��
	init_nrf ();
	init_snack(); //����ʹ��  ������Ҫע��
	P4SW = 0xff;
	
	while (NRF24L01_Check())	 //�ж�24l01�ܷ���
	{
		init_nrf ();
		set(0,0,0);	 	//�Ҳ�������ģ�� ��0,0,0���ĵ���
	}
	clr(0,0,0);	   	//����ģ����Թ��� �� 0,0,0���ĵ���
//	set(2,3,4);
	RX_MODE();			//����ģ���ʼ������ 24l01 ����Ϊ������  �ӷ���
	while (1)
	{
		//Text();  	//���Ժ��� ��Ҫ���ң����
		Snack();
	}

	while(1);
}

//P0;   //uln2803
//P1;  //573 in
//P2;  //573 le												  
void print() interrupt 1
{
     uchar i;
     static uchar layer=0;
     P0=0;
     for (i=0;i<8;i++)
     {
               P2=1<<i;
               delay(3);
               P1=display[layer][i];
               delay(3);
     }
     P0=1<<layer;
     if (layer<7) 
               layer++;
     else 
               layer=0;
     TH0=0xc0;
     TL0=0;

	 number++;

	 if (number == 1024)
	 {
	 	number = 1;
	 }
}
