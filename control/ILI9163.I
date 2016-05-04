
#line 1 "ILI9163.c" /0





 
 
  
#line 1 "ILI9163.h" /0





 
 
 
 
 
  
#line 1 "F:\Keil\C51\Inc\STC15F2K60S2.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 sfr ACC         =   0xE0;    
 sfr B           =   0xF0;    
 sfr PSW         =   0xD0;    
 sbit CY         =   PSW^7;
 sbit AC         =   PSW^6;
 sbit F0         =   PSW^5;
 sbit RS1        =   PSW^4;
 sbit RS0        =   PSW^3;
 sbit OV         =   PSW^2;
 sbit P          =   PSW^0;
 sfr SP          =   0x81;    
 sfr DPL         =   0x82;    
 sfr DPH         =   0x83;    
 
 
 sfr P0          =   0x80;    
 sbit P00        =   P0^0;
 sbit P01        =   P0^1;
 sbit P02        =   P0^2;
 sbit P03        =   P0^3;
 sbit P04        =   P0^4;
 sbit P05        =   P0^5;
 sbit P06        =   P0^6;
 sbit P07        =   P0^7;
 sfr P1          =   0x90;    
 sbit P10        =   P1^0;
 sbit P11        =   P1^1;
 sbit P12        =   P1^2;
 sbit P13        =   P1^3;
 sbit P14        =   P1^4;
 sbit P15        =   P1^5;
 sbit P16        =   P1^6;
 sbit P17        =   P1^7;
 sfr P2          =   0xA0;    
 sbit P20        =   P2^0;
 sbit P21        =   P2^1;
 sbit P22        =   P2^2;
 sbit P23        =   P2^3;
 sbit P24        =   P2^4;
 sbit P25        =   P2^5;
 sbit P26        =   P2^6;
 sbit P27        =   P2^7;
 sfr P3          =   0xB0;    
 sbit P30        =   P3^0;
 sbit P31        =   P3^1;
 sbit P32        =   P3^2;
 sbit P33        =   P3^3;
 sbit P34        =   P3^4;
 sbit P35        =   P3^5;
 sbit P36        =   P3^6;
 sbit P37        =   P3^7;
 sfr P4          =   0xC0;    
 sbit P40        =   P4^0;
 sbit P41        =   P4^1;
 sbit P42        =   P4^2;
 sbit P43        =   P4^3;
 sbit P44        =   P4^4;
 sbit P45        =   P4^5;
 sbit P46        =   P4^6;
 sbit P47        =   P4^7;
 sfr P5          =   0xC8;    
 sbit P50        =   P5^0;
 sbit P51        =   P5^1;
 sbit P52        =   P5^2;
 sbit P53        =   P5^3;
 sbit P54        =   P5^4;
 sbit P55        =   P5^5;
 sbit P56        =   P5^6;
 sbit P57        =   P5^7;
 sfr P6          =   0xE8;    
 sbit P60        =   P6^0;
 sbit P61        =   P6^1;
 sbit P62        =   P6^2;
 sbit P63        =   P6^3;
 sbit P64        =   P6^4;
 sbit P65        =   P6^5;
 sbit P66        =   P6^6;
 sbit P67        =   P6^7;
 sfr P7          =   0xF8;    
 sbit P70        =   P7^0;
 sbit P71        =   P7^1;
 sbit P72        =   P7^2;
 sbit P73        =   P7^3;
 sbit P74        =   P7^4;
 sbit P75        =   P7^5;
 sbit P76        =   P7^6;
 sbit P77        =   P7^7;
 sfr P0M0        =   0x94;    
 sfr P0M1        =   0x93;    
 sfr P1M0        =   0x92;    
 sfr P1M1        =   0x91;    
 sfr P2M0        =   0x96;    
 sfr P2M1        =   0x95;    
 sfr P3M0        =   0xB2;    
 sfr P3M1        =   0xB1;    
 sfr P4M0        =   0xB4;    
 sfr P4M1        =   0xB3;    
 sfr P5M0        =   0xCA;    
 sfr P5M1        =   0xC9;    
 sfr P6M0        =   0xCC;    
 sfr P6M1        =   0xCB;    
 sfr P7M0        =   0xE2;    
 sfr P7M1        =   0xE1;    
 
 
 sfr PCON        =   0x87;    
 sfr AUXR        =   0x8E;    
 sfr AUXR1       =   0xA2;    
 sfr P_SW1       =   0xA2;    
 sfr CLK_DIV     =   0x97;    
 sfr BUS_SPEED   =   0xA1;    
 sfr P1ASF       =   0x9D;    
 sfr P_SW2       =   0xBA;    
 
 
 sfr IE          =   0xA8;    
 sbit EA         =   IE^7;
 sbit ELVD       =   IE^6;
 sbit EADC       =   IE^5;
 sbit ES         =   IE^4;
 sbit ET1        =   IE^3;
 sbit EX1        =   IE^2;
 sbit ET0        =   IE^1;
 sbit EX0        =   IE^0;
 sfr IP          =   0xB8;    
 sbit PPCA       =   IP^7;
 sbit PLVD       =   IP^6;
 sbit PADC       =   IP^5;
 sbit PS         =   IP^4;
 sbit PT1        =   IP^3;
 sbit PX1        =   IP^2;
 sbit PT0        =   IP^1;
 sbit PX0        =   IP^0;
 sfr IE2         =   0xAF;    
 sfr IP2         =   0xB5;    
 sfr INT_CLKO    =   0x8F;    
 
 
 sfr TCON        =   0x88;    
 sbit TF1        =   TCON^7;
 sbit TR1        =   TCON^6;
 sbit TF0        =   TCON^5;
 sbit TR0        =   TCON^4;
 sbit IE1        =   TCON^3;
 sbit IT1        =   TCON^2;
 sbit IE0        =   TCON^1;
 sbit IT0        =   TCON^0;
 sfr TMOD        =   0x89;    
 sfr TL0         =   0x8A;    
 sfr TL1         =   0x8B;    
 sfr TH0         =   0x8C;    
 sfr TH1         =   0x8D;    
 sfr T4T3M       =   0xD1;    
 sfr T3T4M       =   0xD1;    
 sfr T4H         =   0xD2;    
 sfr T4L         =   0xD3;    
 sfr T3H         =   0xD4;    
 sfr T3L         =   0xD5;    
 sfr T2H         =   0xD6;    
 sfr T2L         =   0xD7;    
 sfr WKTCL       =   0xAA;    
 sfr WKTCH       =   0xAB;    
 sfr WDT_CONTR   =   0xC1;    
 
 
 sfr SCON        =   0x98;    
 sbit SM0        =   SCON^7;
 sbit SM1        =   SCON^6;
 sbit SM2        =   SCON^5;
 sbit REN        =   SCON^4;
 sbit TB8        =   SCON^3;
 sbit RB8        =   SCON^2;
 sbit TI         =   SCON^1;
 sbit RI         =   SCON^0;
 sfr SBUF        =   0x99;    
 sfr S2CON       =   0x9A;    
 sfr S2BUF       =   0x9B;    
 sfr S3CON       =   0xAC;    
 sfr S3BUF       =   0xAD;    
 sfr S4CON       =   0x84;    
 sfr S4BUF       =   0x85;    
 sfr SADDR       =   0xA9;    
 sfr SADEN       =   0xB9;    
 
 
 sfr ADC_CONTR   =   0xBC;    
 sfr ADC_RES     =   0xBD;    
 sfr ADC_RESL    =   0xBE;    
 
 
 sfr SPSTAT      =   0xCD;    
 sfr SPCTL       =   0xCE;    
 sfr SPDAT       =   0xCF;    
 
 
 sfr IAP_DATA    =   0xC2;    
 sfr IAP_ADDRH   =   0xC3;    
 sfr IAP_ADDRL   =   0xC4;    
 sfr IAP_CMD     =   0xC5;    
 sfr IAP_TRIG    =   0xC6;    
 sfr IAP_CONTR   =   0xC7;    
 
 
 sfr CCON        =   0xD8;    
 sbit CF         =   CCON^7;
 sbit CR         =   CCON^6;
 sbit CCF2       =   CCON^2;
 sbit CCF1       =   CCON^1;
 sbit CCF0       =   CCON^0;
 sfr CMOD        =   0xD9;    
 sfr CL          =   0xE9;    
 sfr CH          =   0xF9;    
 sfr CCAPM0      =   0xDA;    
 sfr CCAPM1      =   0xDB;    
 sfr CCAPM2      =   0xDC;    
 sfr CCAP0L      =   0xEA;    
 sfr CCAP1L      =   0xEB;    
 sfr CCAP2L      =   0xEC;    
 sfr PCA_PWM0    =   0xF2;    
 sfr PCA_PWM1    =   0xF3;    
 sfr PCA_PWM2    =   0xF4;    
 sfr CCAP0H      =   0xFA;    
 sfr CCAP1H      =   0xFB;    
 sfr CCAP2H      =   0xFC;    
 
 
 sfr CMPCR1      =   0xE6;    
 sfr CMPCR2      =   0xE7;    
 
 
 sfr PWMCFG      =   0xf1;    
 sfr PWMCR       =   0xf5;    
 sfr PWMIF       =   0xf6;    
 sfr PWMFDCR     =   0xf7;    
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 11 "ILI9163.h" /0
 
  
#line 1 "delay_xs.h" /0
 
 
 
  
#line 1 "F:\Keil\C51\Inc\STC15F2K60S2.H" /0
 
#line 2 "F:\Keil\C51\Inc\STC15F2K60S2.H" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
 
#line 303 "F:\Keil\C51\Inc\STC15F2K60S2.H" /0
 
#line 4 "delay_xs.h" /0
 
 
 
 
 
 
 
 void Delay_n100_us(int us);
 void Delay_Nms(int ms);
 
 
#line 12 "ILI9163.h" /0
 
 
 
 sbit rs_tft = P2^0;
 sbit wr_tft = P4^4;
 sbit rst_tft = P4^2;
 sbit cs_tft = P4^1;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 extern unsigned int TFT_color[];
 
 extern void TFT_char(unsigned int x,unsigned int y,unsigned int font_color,unsigned int back_color,char ch);
 extern void TFT_string(unsigned int x,unsigned int y,unsigned int font_color,unsigned int back_color,char *p);
 
 extern void WriteCOM(unsigned char ID);
 extern void WriteDAT(unsigned char HD,unsigned char LD);  
 extern void WriteDAT_8(unsigned char ddate);      
 extern void Write_Data_U16(unsigned int y);
 extern void ILI9163_init(void);
 extern void add_rst(void);    
 extern void LCD_SetPos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1);
 extern void display(unsigned int colour);
 extern void LCD_ico(unsigned char xs,unsigned char ys,unsigned char x,unsigned char y,unsigned char ico[]);
 extern void LCD_clear(unsigned char xs,unsigned char ys,unsigned char x,unsigned char y);
 extern void LCD_write_kong(unsigned char y);
 extern void LCD_write_part(unsigned char y,unsigned char x,unsigned char img[]);
 extern void LCD_bot(unsigned char x,unsigned char y,unsigned int fColor);	  
 extern void TFT_Test();							    
 extern void write_ascii(unsigned char x,unsigned char y,char p);    
 void write_ascii_string(unsigned int x,unsigned int y,char *p);	    
 void dispaly_byte(int y,unsigned char P);    
 
 
#line 8 "ILI9163.c" /0
 
  
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
 
 
 
 
#line 9 "ILI9163.c" /0
 
  
#line 1 "TFT_ascii.h" /0





 
 
 
 
 
 const unsigned char Font6x8[97][6] =            
 {
 0x00,0x00,0x00,0x00,0x00,0x00,   
 
 0x00,0x00,0xFA,0x00,0x00,0x00,   
 
 0x00,0xE0,0x00,0xE0,0x00,0x00,   
 
 0x28,0xFE,0x28,0xFE,0x28,0x00,   
 
 0x24,0x74,0xDE,0x54,0x48,0x00,   
 
 0xC4,0xC8,0x10,0x26,0x46,0x00,   
 
 0x6C,0x92,0x6A,0x04,0x0A,0x00,   
 
 0x00,0x20,0xC0,0x80,0x00,0x00,   
 
 0x00,0x38,0x44,0x82,0x00,0x00,   
 
 0x00,0x82,0x44,0x38,0x00,0x00,   
 
 0x44,0x28,0xFE,0x28,0x44,0x00,   
 
 0x10,0x10,0xFE,0x10,0x10,0x00,   
 
 0x02,0x0C,0x08,0x00,0x00,0x00,   
 
 0x10,0x10,0x10,0x10,0x10,0x00,   
 
 0x00,0x06,0x06,0x00,0x00,0x00,   
 
 0x04,0x08,0x10,0x20,0x40,0x00,   
 
 0x7C,0x8A,0x92,0xA2,0x7C,0x00,   
 
 0x00,0x42,0xFE,0x02,0x00,0x00,   
 
 0x46,0x8A,0x92,0x92,0x62,0x00,   
 
 0x84,0x82,0x92,0xB2,0xCC,0x00,   
 
 0x18,0x28,0x48,0xFE,0x08,0x00,   
 
 0xE4,0xA2,0xA2,0xA2,0x9C,0x00,   
 
 0x3C,0x52,0x92,0x92,0x8C,0x00,   
 
 0x80,0x8E,0x90,0xA0,0xC0,0x00,   
 
 0x6C,0x92,0x92,0x92,0x6C,0x00,   
 
 0x62,0x92,0x92,0x94,0x78,0x00,   
 
 0x00,0x6C,0x6C,0x00,0x00,0x00,   
 
 0x02,0x6C,0x6C,0x00,0x00,0x00,   
 
 0x10,0x28,0x44,0x82,0x00,0x00,   
 
 0x28,0x28,0x28,0x28,0x28,0x00,   
 
 0x00,0x82,0x44,0x28,0x10,0x00,   
 
 0x40,0x80,0x9A,0xA0,0x40,0x00,   
 
 0x7C,0x82,0xBA,0xAA,0x7A,0x00,   
 
 0x3E,0x48,0x88,0x48,0x3E,0x00,   
 
 0xFE,0x92,0x92,0x92,0x6C,0x00,   
 
 0x7C,0x82,0x82,0x82,0x44,0x00,   
 
 0xFE,0x82,0x82,0x82,0x7C,0x00,   
 
 0xFE,0x92,0x92,0x92,0x82,0x00,   
 
 0xFE,0x90,0x90,0x90,0x80,0x00,   
 
 0x7C,0x82,0x8A,0x8A,0x4E,0x00,   
 
 0xFE,0x10,0x10,0x10,0xFE,0x00,   
 
 0x00,0x82,0xFE,0x82,0x00,0x00,   
 
 0x04,0x02,0x82,0xFC,0x80,0x00,   
 
 0xFE,0x10,0x28,0x44,0x82,0x00,   
 
 0xFE,0x02,0x02,0x02,0x02,0x00,   
 
 0xFE,0x40,0x30,0x40,0xFE,0x00,   
 
 0xFE,0x20,0x10,0x08,0xFE,0x00,   
 
 0x7C,0x82,0x82,0x82,0x7C,0x00,   
 
 0xFE,0x90,0x90,0x90,0x60,0x00,   
 
 0x7C,0x82,0x8A,0x84,0x7A,0x00,   
 
 0xFE,0x90,0x98,0x94,0x62,0x00,   
 
 0x64,0x92,0x92,0x92,0x4C,0x00,   
 
 0x80,0x80,0xFE,0x80,0x80,0x00,   
 
 0xFC,0x02,0x02,0x02,0xFC,0x00,   
 
 0xF8,0x04,0x02,0x04,0xF8,0x00,   
 
 0xFE,0x04,0x18,0x04,0xFE,0x00,   
 
 0xC6,0x28,0x10,0x28,0xC6,0x00,   
 
 0xC0,0x20,0x1E,0x20,0xC0,0x00,   
 
 0x86,0x8A,0x92,0xA2,0xC2,0x00,   
 
 0xFE,0xFE,0x82,0x82,0x00,0x00,   
 
 0x40,0x20,0x10,0x08,0x04,0x00,   
 
 0x00,0x82,0x82,0xFE,0xFE,0x00,   
 
 0x20,0x40,0xFE,0x40,0x20,0x00,   
 
 0x10,0x38,0x54,0x10,0x10,0x00,   
 
 0x00,0x00,0x80,0x40,0x20,0x00,   
 
 0x24,0x2A,0x2A,0x1C,0x02,0x00,   
 
 0xFE,0x14,0x22,0x22,0x1C,0x00,   
 
 0x1C,0x22,0x22,0x22,0x10,0x00,   
 
 0x1C,0x22,0x22,0x14,0xFE,0x00,   
 
 0x1C,0x2A,0x2A,0x2A,0x10,0x00,   
 
 0x10,0x7E,0x90,0x90,0x40,0x00,   
 
 0x19,0x25,0x25,0x25,0x1E,0x00,   
 
 0xFE,0x10,0x20,0x20,0x1E,0x00,   
 
 0x00,0x00,0x9E,0x00,0x00,0x00,   
 
 0x00,0x01,0x11,0x9E,0x00,0x00,   
 
 0xFE,0x08,0x14,0x22,0x02,0x00,   
 
 0x00,0x82,0xFE,0x02,0x00,0x00,   
 
 0x1E,0x20,0x1E,0x20,0x1E,0x00,   
 
 0x20,0x1E,0x20,0x20,0x1E,0x00,   
 
 0x1C,0x22,0x22,0x22,0x1C,0x00,   
 
 0x3F,0x24,0x24,0x24,0x18,0x00,   
 
 0x18,0x24,0x24,0x24,0x3F,0x00,   
 
 0x20,0x1E,0x20,0x20,0x10,0x00,   
 
 0x12,0x2A,0x2A,0x2A,0x24,0x00,   
 
 0x20,0xFC,0x22,0x22,0x24,0x00,   
 
 0x3C,0x02,0x02,0x3C,0x02,0x00,   
 
 0x38,0x04,0x02,0x04,0x38,0x00,   
 
 0x3C,0x02,0x3C,0x02,0x3C,0x00,   
 
 0x22,0x14,0x08,0x14,0x22,0x00,   
 
 0x39,0x05,0x05,0x09,0x3E,0x00,   
 
 0x22,0x26,0x2A,0x32,0x22,0x00,   
 
 0x10,0x6C,0x82,0x00,0x00,0x00,   
 
 0x00,0x00,0xEE,0x00,0x00,0x00,   
 
 0x00,0x00,0x82,0x6C,0x10,0x00,   
 
 0x10,0x20,0x10,0x08,0x10,0x00,   
 
 0xAA,0x54,0xAA,0x54,0xAA,0x00,   
 
 0x04,0x02,0xff,0xff,0x02,0x04,	 
 };
 
 
 
#line 10 "ILI9163.c" /0
 
 
  unsigned int TFT_color[]={
 0x07e0, 
 0xf800, 
 0xffe0, 
 
 0x07ff, 
 0x001f, 
 0xf81f, 
 0x0000, 
 0xffff, 
 0x7bef  
 };
 
 
 void delay_ms(int x)		 
 {
 unsigned char i, j;
 
 i = 108;
 j = 145;
 do
 {
 while (--j);
 } while (--i);
 }
 
  unsigned char Flip(unsigned char Data)
 {
 int i;
  unsigned char temp = 0x00;
 
 for (i = 7;i >= 0;i--)
 {
 temp |= ((Data&0x01) << i);
 Data >>= 1; 
 }
 
 return temp;
 }
 
 void Delay10us()		 
 {													  
 
 unsigned char i;
 
 i = 2;
 while (--i);
 }
 
 void Delay100ms()		 
 {
 unsigned char i, j, k;
 
 _nop_();
 _nop_();
 i = 5;
 j = 52;
 k = 195;
 do
 {
 do
 {
 while (--k);
 } while (--j);
 } while (--i);
 }
 
 void TFT_char(unsigned int x,unsigned int y,unsigned int font_color,unsigned int back_color,char ch){
  unsigned char temp , Bytes;
  unsigned char pos,t;
  unsigned int  CHAR_W,CHAR_H;   
 
 
 
 
 CHAR_W = 6;          
 CHAR_H = 8;
 
 if(x>(128-CHAR_W)||y>(160-CHAR_H))    
 return;
 LCD_SetPos( Flip(y), Flip(y+CHAR_H-1),Flip(x), Flip(x+CHAR_W-1));  
 ch = ch-32;                        
 Bytes = (CHAR_W*CHAR_H)/8;  
 for(pos=0;pos<Bytes;pos++)   
 {
 
 temp= Font6x8[ch][pos];   
 for(t=0;t<8;t++)    
 {
 
 if(temp&0x80)    
 Write_Data_U16(Flip(font_color));   
 else    
 Write_Data_U16(Flip(back_color));   
 temp<<=1;    
 }
 
 }
 }
 
 void TFT_string(unsigned int x,unsigned int y,unsigned int font_color,unsigned int back_color,char *p){
 while(*p!='\0'){	 
 TFT_char(y,x,font_color,back_color,*p);
 x+=6;
 p++;
 }
 }
 
 
 
 void WriteCOM(unsigned char ID)
 {
 
  rs_tft = 0;
 
  cs_tft = 0;
 
 
 
  P3=0x00;
 
 
  wr_tft = 0;
 Delay10us();
  wr_tft = 1;
 
 
  P3=(ID);
 
 
  wr_tft = 0;
 Delay10us();
  wr_tft = 1;
 
  rs_tft = 1;
 
  cs_tft = 1;
 }


 
 void WriteDAT(unsigned char HD,unsigned char LD)  
 {
 
 
 
  rs_tft = 1;
 
  cs_tft = 0;
 
 
  P3=(HD);
  wr_tft = 0;
 Delay10us();
  wr_tft = 1;	
 
 
  P3=(LD);
  wr_tft = 0;
 Delay10us();
  wr_tft = 1;
 
  rs_tft = 0;
 
  cs_tft = 1;
 }
 void WriteDAT_8(unsigned char ddate)      
 {
 
 
  rs_tft = 1;
 
  cs_tft = 0;
 
 
  P3=(ddate);
  wr_tft = 0;
 Delay10us();
  wr_tft = 1;
 Delay10us();
 
  rs_tft = 0;
 
  cs_tft = 1;
 
 }


 
 void Write_Data_U16(unsigned int y)
 {
 unsigned char m,n;
 m=y>>8;  
 n=y;  
 WriteDAT(m,n);
 }
 


 
 void ILI9163_init(void)
 {
  rst_tft = 1;
 delay_ms(10);
  rst_tft = 0;
 delay_ms(10);
  rst_tft = 1;
 delay_ms(10);
 WriteCOM(0x88); 
 delay_ms(10);
 WriteCOM(0x64); 
 WriteDAT_8(0x20);
 
 
 delay_ms(10);
 WriteCOM(0x8d);    
 WriteDAT_8(0x60);
 WriteDAT_8(0x10);
 WriteDAT_8(0x90);
 
 WriteCOM(0x03);    
 WriteDAT_8(0x20);
 WriteDAT_8(0x00);
 
 WriteCOM(0x83);    
 WriteDAT_8(0xe0);
 
 WriteCOM(0xa3);    
 WriteDAT_8(0x32);   
 WriteDAT_8(0x1c);   
 
 WriteCOM(0xe3);    
 WriteDAT_8(0x02);   
 
 delay_ms(10);
 
 WriteCOM(0x5c);    
 WriteDAT_8(0xa0);

 
 
 WriteCOM(0x6c);   
 
 
 WriteDAT_8(0x14);
 
 
 WriteCOM(0xed);
 WriteDAT_8(0x00);  
 
 WriteCOM(0x4f);
 WriteDAT_8(0x80);
 delay_ms(10);
 
 
 WriteCOM(0x07); 
 WriteDAT_8(0x90); 
 WriteDAT_8(0x68); 
 WriteDAT_8(0x90); 
 WriteDAT_8(0xe4); 
 WriteDAT_8(0x74); 
 WriteDAT_8(0xa4); 
 WriteDAT_8(0x38); 
 WriteDAT_8(0x04); 
 WriteDAT_8(0x78); 
 WriteDAT_8(0x58); 
 WriteDAT_8(0x24); 
 WriteDAT_8(0xb4); 
 WriteDAT_8(0x20); 
 WriteDAT_8(0xa0); 
 WriteDAT_8(0x40); 
 WriteDAT_8(0x70); 
 WriteCOM(0x87);  
 WriteDAT_8(0xd0); 
 WriteDAT_8(0x28); 
 WriteDAT_8(0x90); 
 WriteDAT_8(0x64); 
 WriteDAT_8(0xe4); 
 WriteDAT_8(0x44); 
 WriteDAT_8(0x38); 
 WriteDAT_8(0x04); 
 WriteDAT_8(0xb8); 
 WriteDAT_8(0x58); 
 WriteDAT_8(0xa4); 
 WriteDAT_8(0xb4); 
 WriteDAT_8(0x60); 
 WriteDAT_8(0x60); 
 WriteDAT_8(0x40); 
 WriteDAT_8(0xf0); 
 
 WriteCOM(0x94);  
 delay_ms(10);
 WriteCOM(0x34);  
 }
 


 
 void add_rst(void)    
 {
 WriteCOM(0x54);       
 WriteDAT_8(0x00);
 WriteDAT_8(0x00);
 WriteDAT_8(0x00);
 WriteDAT_8(0xf9);
 
 WriteCOM(0xd4);       
 WriteDAT_8(0x00);
 WriteDAT_8(0x00);
 WriteDAT_8(0x00);
 WriteDAT_8(0x01);
 
 WriteCOM(0x34);       
 }
 void LCD_SetPos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1)
 {
 WriteCOM(0x54);     
 WriteDAT_8(x0>>8);   
 WriteDAT_8(x0);      
 
 WriteDAT_8(x1>>8);
 WriteDAT_8(x1);
 
 WriteCOM(0xd4);       
 WriteDAT_8(y0>>8);
 WriteDAT_8(y0);
 
 WriteDAT_8(y1>>8);
 WriteDAT_8(y1);
 
 WriteCOM(0x34);       
 }



 
 void display(unsigned int colour)
 {
 
 unsigned int c,s;
 add_rst(); 
 for(c=0;c<160;c++)     
 {
 for(s=0;s<128;s++)
 {
 WriteDAT(colour>>8,colour);
 }
 }
 delay_ms(200);
 }




 
 void LCD_ico(unsigned char xs,unsigned char ys,unsigned char x,unsigned char y,unsigned char ico[])
 {
 unsigned int i;
 LCD_SetPos(xs,xs+x-1,ys,ys+y-1);
 for(i=0;i<x*y*2-1;i=i+2)     
 {
 WriteDAT(ico[i],ico[i+1]);     
 }
 }



 
 void LCD_clear(unsigned char xs,unsigned char ys,unsigned char x,unsigned char y)
 {
 unsigned int i;
 LCD_SetPos(xs,xs+x-1,ys,ys+y-1);
 for(i=0;i<x*y*2-2;i=i+2)     
 {
 WriteDAT(0xff,0xff);     
 }
 }
 



 
 void LCD_write_kong(unsigned char y)
 {
 unsigned char m,n;
 LCD_SetPos((y%3)*42+y%3,(y%3)*42+42-1+y%3,(y/3)*42+y/3,(y/3)*42+42-1+y/3);  
 for(n=0;n<42;n++)  
 for(m=0;m<42;m++)
 {
 WriteDAT(0xFF,0x77);  
 }
 }




 
 void LCD_write_part(unsigned char y,unsigned char x,unsigned char img[])
 {
 unsigned char m,n;
 LCD_SetPos((y%3)*42+y%3,(y%3)*42+42-1+y%3,(y/3)*42+y/3,(y/3)*42+42-1+y/3);  
 if(x==8)
 LCD_write_kong(y);
 else
 {
 for(n=0;n<42;n++)
 {
 for(m=0;m<42;m++)
 {
 WriteDAT(img[2*(m+126*n+42*(x%3)+126*42*(x/3))],img[2*(m+126*n+42*(x%3)+126*42*(x/3))+1]);     
 }
 }
 }
 }
 


 
 void LCD_bot(unsigned char x,unsigned char y,unsigned int fColor)
 {
 LCD_SetPos(Flip(x),Flip(x+1),Flip(y),Flip(y+1));
 Write_Data_U16(fColor);
 }
 


 
 void TFT_Test()
 {
 unsigned char i;  
 
 ILI9163_init();
 for(i=0;i<8;i++)
 {		
 display(TFT_color[i]);    
 Delay100ms();
 }
 }
 
 void write_ascii(unsigned char x,unsigned char y,char p)
 {
 int i,n,temp,x0 = x;
 for (i = 0;i < 6; i++)
 {
 temp = 0x80;
 for (n = 0;n < 8;n++)				   
 {
 if ( (Font6x8[p - 32][i] & temp))
 {	
 LCD_bot(y,x,TFT_color[0]);
 }
 else 
 {
 LCD_bot(y,x,TFT_color[7]);	
 }	
 
 x --;								  
 
 temp >>= 1;
 }
 y ++;
 x = x0;
 }	
 }
 
 void write_ascii_string(unsigned int y,unsigned int x,char *p)
 {
 while(*p!='\0')
 {	
 
 write_ascii(x,y,*p);
 y+=6;
 p++;
 }	
 }
 
 void dispaly_byte(int y,unsigned char P)
 {
 int i;
  unsigned char temp;	
 
 temp = 	0x80;
 for (i = 0;i < 8;i ++)
 {	
 if ( !(P&temp))
 {	
 write_ascii_string(3+i*7,y,"0");	
 }
 else 
 {
 write_ascii_string(3+i*7,y,"1");	
 }
 
 temp >>= 1;	
 }
 
 }
