
#line 1 "nrf24.c" /0
 
  
#line 1 "F:\Keil\C51\Inc\STC12C5A60S2.H" /0
 
 
 
 
 
 
 
 
 sfr ACC  = 0xE0;  
 sfr B    = 0xF0;  
 sfr PSW  = 0xD0;  
 
 sbit CY  = PSW^7;
 sbit AC  = PSW^6;
 sbit F0  = PSW^5;
 sbit RS1 = PSW^4;
 sbit RS0 = PSW^3;
 sbit OV  = PSW^2;
 sbit P   = PSW^0;
 
 sfr SP   = 0x81;  
 sfr DPL  = 0x82;  
 sfr DPH  = 0x83;  
 
 
 
 sfr PCON   = 0x87;  
 
 sfr AUXR  = 0x8E;  
 
 sfr AUXR1 = 0xA2;  
























 
 
 sfr WAKE_CLKO = 0x8F;  












 
 
 sfr CLK_DIV = 0x97;  
 
 sfr BUS_SPEED = 0xA1;  
















 
 
 
 
 
 
 sfr IE      = 0xA8;   
 
 sbit EA       = IE^7;
 sbit ELVD     = IE^6;  
 sbit EADC     = IE^5;  
 sbit ES       = IE^4;
 sbit ET1      = IE^3;
 sbit EX1      = IE^2;
 sbit ET0      = IE^1;
 sbit EX0      = IE^0;
 
 sfr IE2       = 0xAF;   
 
 
 sfr IP      = 0xB8;  
 
 sbit PPCA     = IP^7;   
 sbit PLVD     = IP^6;   
 sbit PADC     = IP^5;   
 sbit PS       = IP^4;
 sbit PT1      = IP^3;
 sbit PX1      = IP^2;
 sbit PT0      = IP^1;
 sbit PX0      = IP^0;
 
 
 sfr IPH   = 0xB7;  
 sfr IP2   = 0xB5;  
 sfr IPH2  = 0xB6;  
 
 
 
 sfr P0   = 0x80;  
 sfr P0M0 = 0x94;  
 sfr P0M1 = 0x93;  
 sfr P1   = 0x90;  
 sfr P1M0 = 0x92;  
 sfr P1M1 = 0x91;  
 sfr P1ASF = 0x9D;  
 sfr P2   = 0xA0;  
 sfr P2M0 = 0x96;  
 sfr P2M1 = 0x95;  
 sfr P3   = 0xB0;  
 sfr P3M0 = 0xB2;  
 sfr P3M1 = 0xB1;  
 sfr P4   = 0xC0;  
 sfr P4M0 = 0xB4;  
 sfr P4M1 = 0xB3;  
 
 sfr P4SW = 0xBB;  
 
 sfr P5   = 0xC8;  
 sfr P5M0 = 0xCA;  
 sfr P5M1 = 0xC9;  
 
 
 
 sfr TCON = 0x88;  
 
 sbit TF1 = TCON^7;
 sbit TR1 = TCON^6;
 sbit TF0 = TCON^5;
 sbit TR0 = TCON^4;
 sbit IE1 = TCON^3;
 sbit IT1 = TCON^2;
 sbit IE0 = TCON^1;
 sbit IT0 = TCON^0;
 
 sfr TMOD = 0x89;  
 sfr TL0  = 0x8A;  
 sfr TH0  = 0x8C;  
 sfr TL1  = 0x8B;  
 sfr TH1  = 0x8D;  
 
 
 
 sfr SCON = 0x98;  
 
 sbit SM0 = SCON^7;   
 sbit SM1 = SCON^6;
 sbit SM2 = SCON^5;
 sbit REN = SCON^4;
 sbit TB8 = SCON^3;
 sbit RB8 = SCON^2;
 sbit TI  = SCON^1;
 sbit RI  = SCON^0;
 
 sfr SBUF = 0x99;  
 sfr SADEN = 0xB9;  
 sfr SADDR = 0xA9;  
 
 
 sfr S2CON = 0x9A;  
 sfr S2BUF = 0x9B;  
 sfr BRT = 0x9C;  
 
 
 sfr WDT_CONTR = 0xC1;  
 
 
 
 
 
 
 
 sfr CCON   = 0xD8;    
 
 sbit CF     = CCON^7;  
 sbit CR     = CCON^6;  
 
 
 sbit CCF1   = CCON^1;  
 sbit CCF0   = CCON^0;  
 
 sfr CMOD  = 0xD9;  

















 
 
 sfr CL     = 0xE9;  
 sfr CH     = 0xF9;  
 
 
 sfr CCAPM0 = 0xDA;  
 sfr CCAPM1 = 0xDB;  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 sfr CCAP0L = 0xEA;  
 sfr CCAP0H = 0xFA;  
 sfr CCAP1L = 0xEB;  
 sfr CCAP1H = 0xFB;  
 
 
 sfr PCA_PWM0 = 0xF2;  
 sfr PCA_PWM1 = 0xF3;  
 
 
 
 
 
 
 
 
 sfr ADC_CONTR = 0xBC;  
 sfr ADC_RES  = 0xBD;   
 sfr ADC_RESL = 0xBE;   
 
 
 
 sfr SPCTL  = 0xCE;  
 sfr SPSTAT = 0xCD;  
 sfr SPDAT  = 0xCF;  
 
 
 sfr IAP_DATA    = 0xC2;
 sfr IAP_ADDRH   = 0xC3;
 sfr IAP_ADDRL   = 0xC4;
 
 sfr IAP_CMD     = 0xC5;  
 sfr IAP_TRIG    = 0xC6;
 sfr IAP_CONTR   = 0xC7;  
 
 
 
 
 
 
#line 2 "nrf24.c" /0
 
  
#line 1 "F:\Keil\C51\Inc\intrins.h" /0






 
 
 
 
 
 extern void          _nop_     (void);
 extern bit           _testbit_ (bit);
 extern unsigned char _cror_    (unsigned char, unsigned char);
 extern unsigned int  _iror_    (unsigned int,  unsigned char);
 extern unsigned long _lror_    (unsigned long, unsigned char);
 extern unsigned char _crol_    (unsigned char, unsigned char);
 extern unsigned int  _irol_    (unsigned int,  unsigned char);
 extern unsigned long _lrol_    (unsigned long, unsigned char);
 extern unsigned char _chkfloat_(float);
 
 extern void          _push_    (unsigned char _sfr);
 extern void          _pop_     (unsigned char _sfr);
 
 
 
 
#line 3 "nrf24.c" /0
 
  
#line 1 "F:\Keil\C51\Inc\stdlib.h" /0






 
 
 
 
 
 
 
 typedef unsigned int size_t;
 
 
 
 
 
 
 
 
 typedef char wchar_t;
 
 
 
 
 
 
 #pragma SAVE
 #pragma REGPARMS
 
 extern int    abs  (int   val);
 extern long  labs  (long  val);
 
 extern float atof (char *s1);
 extern long  atol (char *s1);
 extern int   atoi (char *s1);
 extern int   rand ();
 extern void  srand (int);
 
 extern float         strtod  (char *, char **);
 extern long          strtol  (char *, char **, unsigned char);
 extern unsigned long strtoul (char *, char **, unsigned char);
 
 
 
 extern void init_mempool          (void xdata *p, unsigned int size);
 extern void xdata *malloc  (unsigned int size);
 extern void free                  (void xdata *p);
 extern void xdata *realloc (void xdata *p, unsigned int size);
 extern void xdata *calloc  (unsigned int size, unsigned int len);
 
 #pragma RESTORE
 
 
#line 4 "nrf24.c" /0
 
  
#line 1 "nrf.h" /0
 
 
 
  
#line 1 "F:\Keil\C51\Inc\STC12C5A60S2.h" /0
 
#line 2 "F:\Keil\C51\Inc\STC12C5A60S2.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
























 
 
 












 
 
 
 
 
















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 303 "F:\Keil\C51\Inc\STC12C5A60S2.h" /0
 
#line 4 "nrf.h" /0
 
  
#line 1 "F:\Keil\C51\Inc\intrins.h" /0






 
 
 
#line 10 "F:\Keil\C51\Inc\intrins.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 27 "F:\Keil\C51\Inc\intrins.h" /0
 
#line 5 "nrf.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 sbit IRQ  = P4^5;
 sbit MOSI = P4^4;
 sbit CSN  = P4^3;
 sbit MISO = P4^2;
 sbit SCK  = P4^1;
 sbit CE   = P4^0;
 
 extern char SPI_write_read_byte (char dete);		   
 extern char SPI_RW_REG (char reg,char value);		    
 extern char SPI_READ (char reg);					    
 extern char SPI_READ_BUF (char reg,char *pBuf,char bytes);		 
 extern char SPI_WRITE_BUF (char reg,char *pBuf,char bytes);	 
 extern unsigned char NRF24L01_RXPacket(unsigned char *rxbuf);
 extern unsigned char nRF24l01_TxPacket(unsigned char *pBuf);		    
 extern void RX_MODE ();			 
 extern void TX_MODE ();			 
 extern void init_nrf ();	  
 extern unsigned char NRF24L01_Check(void);		 
 
 
#line 5 "nrf24.c" /0
 
 
 
 
 
 
 
  unsigned char display[8][8];
  unsigned char Textpackage[5] = {0};
  unsigned char LED_key[2] = {0}; 
 int snack_long;	   	 
 int number = 1,food_ture = 1;
 int snack_die = 0;
 unsigned xdata nAsciiDot[] =               
 {
 0x38,0x44,0x44,0x44,0x44,0x44,0x44,0x38,   
 
 0x30,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,   
 
 0x38,0x44,0x04,0x08,0x10,0x20,0x44,0x7C,   
 
 0x38,0x44,0x04,0x18,0x04,0x04,0x44,0x38,   
 
 0x0C,0x14,0x14,0x24,0x44,0x7C,0x04,0x0C,   
 
 0x3C,0x20,0x20,0x38,0x04,0x04,0x44,0x38,   
 
 0x1C,0x20,0x40,0x78,0x44,0x44,0x44,0x38,   
 
 0x7C,0x44,0x04,0x08,0x08,0x08,0x10,0x10,   
 
 0x38,0x44,0x44,0x38,0x44,0x44,0x44,0x38,   
 
 0x38,0x44,0x44,0x44,0x3C,0x04,0x08,0x70   
 };
 
 struct Sack			  
 {
 char x;
 char y;
 char z;
 };
 
 struct Food		   
 {
  unsigned char x;
  unsigned char y;
  unsigned char z;
 }snack_food;
 
 static xdata struct Sack snack[512];	  
 
 void setfood ();
 
 void delay5us(void)    
 {
 unsigned char b;
 for(b=7;b>0;b--);
 
 }
 
 void delay(unsigned int i)
 {                                                                                                     
 
 while (i--){
 delay5us();} 
 }
 
 void delay_ms(int ms)	    
 {
  unsigned int i,n;
 
 for (i = 0;i < 24 * ms;i ++)
 for (n = 0;n < 110;n ++);
 }
 
 
 void clear(char le)		 	 
 {
  unsigned char i,j;
 for (j=0;j<8;j++)
 {
 for (i=0;i<8;i++)
 display[j][i]=le;
 }
 }
 
 void set(unsigned char x,unsigned char y,unsigned char z)	    
 {
 display[x][y] |= 0x01<<z;
 }
 
 void clr(unsigned char x,unsigned char y,unsigned char z)	    
 {
 display[x][y] &=~(0x01<<z);
 }
 
 
 
 
 void set_led(struct Sack Buf)	 		 
 {
 set(Buf.x,Buf.y,Buf.z);
 }
 
 void clr_led(struct Sack Buf)		    
 {
 clr(Buf.x,Buf.y,Buf.z);	
 }
 
 void setfood ()
 {
 int i;
 srand(number);	
 snack_food.x = (unsigned char)rand()%8;
 snack_food.y = (unsigned char)rand()%8;
 snack_food.z = (unsigned char)rand()%8;
 
 for (i = 0;i <= snack_long;i ++)
 {
 if ( (snack_food.x == snack[i].x) && (snack_food.y == snack[i].y) && (snack_food.z == snack[i].z) )
 {
 setfood();
 }
 }
 
 set(snack_food.x,snack_food.y,snack_food.z);		
 }
 
 void move()	    
 {
 int i;
 static int x = 1,y = 1,z = 1;
 struct Sack linshi_snack,last_snack;
 
 linshi_snack = snack[0];		  
 last_snack = snack[snack_long];
 
 
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
 
 else 
 {	 
 if(snack[0].x != snack[1].x)	 
 {
 if (x)
 {
 if(snack[0].x > snack[1].x)	 
 {
 linshi_snack.x ++;		 
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
 if(snack[0].x < snack[1].x)	 
 {
 linshi_snack.x ++;		 
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
 if(snack[0].y > snack[1].y)	 
 {
 linshi_snack.y ++;		 
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
 if(snack[0].y < snack[1].y)	 
 {
 linshi_snack.y ++;		 
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
 if(snack[0].z > snack[1].z)	 
 {
 linshi_snack.z ++;		 
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
 if(snack[0].z < snack[1].z)	 
 {
 linshi_snack.z ++;		 
 }
 else 
 {
 linshi_snack.z --;	
 }
 z = 1;	
 }	
 }
 } 
 clr_led (last_snack);   
 if ( (snack_food.x == snack[0].x) && (snack_food.y == snack[0].y) && (snack_food.z == snack[0].z) )
 {
 snack_long ++;
 setfood();	
 }
 
 
 for (i = snack_long;i > 0;i --)
 {
 snack[i] = snack[i - 1];
 }
 snack[0] = linshi_snack;	
 
 for (i = 1;i < snack_long;i ++)
 {
 if ( (snack[i].x == snack[0].x) && (snack[i].y == snack[0].y) && (snack[i].z == snack[0].z) )
 {
 snack_die = 1;
 }
 }
 
 for (i = 0;i <= snack_long;i ++)    
 {
 set_led(snack[i]);
 } 
 
 
 }
 
 void init_snack()
 {
  unsigned char i;
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
 
  unsigned char getkey ()
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
 






 
 
 while (1)
 {
 for (b = 0;b < 200;b++)
 {	
 for (i = 0;i < 12;i++)
 for (n = 0;n < 110;n ++);				
 
 getkey();	   
 }
 
 move();	
 if (snack_die)   
 break;
 }
 }
 
 void display_number(int number,int y)
 {
 int i,n;
  unsigned int temp;
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
  unsigned int grade_unit,grade_ten,grade_hundred;
 
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
 
 
 
 void INT1_init(void)
 {
 IE=0x82;
 TCON=0x01;
 TH0=0xc0;
 TL0=0;
 TR0=1;
 EA = 1;
 }
 
 
 void main()
 {		
 INT1_init();		 
 init_nrf ();
 init_snack();  
 P4SW = 0xff;
 
 while (NRF24L01_Check())	  
 {
 init_nrf ();
 set(0,0,0);	 	 
 }
 clr(0,0,0);	   	 
 
 RX_MODE();			 
 while (1)
 {
 
 Snack();
 }
 
 while(1);
 }
 
 
 
 
 void print() interrupt 1
 {
  unsigned char i;
 static unsigned char layer=0;
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
