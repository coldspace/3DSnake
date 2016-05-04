
#line 1 "nrf.c" /0
 
 
  
#line 1 "nrf.h" /0
 
 
 
  
#line 1 "F:\Keil\C51\Inc\STC12C5A60S2.h" /0
 
 
 
 
 
 
 
 
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
 
 
 
 
 
 
#line 4 "nrf.h" /0
 
  
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
 
 
#line 3 "nrf.c" /0
 
 
  unsigned char code TX_ADDRESS[5] = {0x34,0x43,0x10,0x10,0x01};
  unsigned char code RX_ADDRESS[5] = {0x34,0x43,0x10,0x10,0x01};
  unsigned char TX_BUF[5];
  unsigned char RX_BUF[5];
 
 char SPI_write_read_bety (char dete)		   
 {
  unsigned int i; 
 
 for (i = 0;i < 8;i ++)
 {
 MOSI = dete&0x80;
 dete <<= 1;
 SCK = 1;
 dete |= MISO;
 SCK = 0;
 }
 
  _nop_();_nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
 
 return dete;
 }
 
 char SPI_RW_REG (char reg,char value)			 
 {
 char status;
 
 CSN = 0;
 status = SPI_write_read_bety (reg); 
 SPI_write_read_bety (value);			  	 
 CSN = 1;
 return status;
 }
 
 char SPI_READ (unsigned char reg)						 
 {
  unsigned char reg_val;
 
 CSN = 0;
 SPI_write_read_bety (reg);
 reg_val = SPI_write_read_bety (0xff);
 CSN = 1;
 return reg_val;
 }
 
 char SPI_READ_BUF (char reg,char *pBuf,char bytes)		   
 {
  unsigned char status,byte_ctr;
 
 CSN = 0;
 status = SPI_write_read_bety (reg);
 
 for (byte_ctr = 0;byte_ctr < bytes;byte_ctr ++)
 {
 pBuf[byte_ctr] = SPI_write_read_bety (0xff);
 }
 CSN = 1;
 return status;
 }
 
 char SPI_WRITE_BUF (char reg,char *pBuf,char bytes)		  
 {
 char status,byte_str;
 
 CSN = 0;
 status = SPI_write_read_bety (reg);
  _nop_();_nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
 for (byte_str = 0;byte_str < bytes;byte_str ++)
 {
 SPI_write_read_bety (*pBuf ++);
 }
 CSN = 1;
 return status ;		
 }
 
 void RX_MODE ()			   
 {
 CE = 0;
 SPI_WRITE_BUF (0x20 + 0x0A,RX_ADDRESS,5);   		 
 SPI_RW_REG(0x20 + 0x01, 0x01);     			 
 SPI_RW_REG(0x20 + 0x02, 0x01); 			 
 SPI_RW_REG(0x20 + 0x05, 40);       			 
 SPI_RW_REG(0x20 + 0x11, 5);	 
 SPI_RW_REG(0x20 + 0x06, 0x07);      	   	 
 SPI_RW_REG(0x20 + 0x00, 0x0f);     			 
 CE = 1;	
 }
 
 void TX_MODE() 			   
 {
 CE = 0;        
 SPI_WRITE_BUF(0x20 + 0x10, TX_ADDRESS, 5);     	 
 SPI_WRITE_BUF(0x20 + 0x0A, RX_ADDRESS, 5);     
 SPI_WRITE_BUF(0xA0, TX_BUF, 5);  
 SPI_RW_REG(0x20 + 0x01, 0x01);       
 SPI_RW_REG(0x20 + 0x02, 0x01);   
 SPI_RW_REG(0x20 + 0x04, 0x1a);  
 SPI_RW_REG(0x20 + 0x05, 40);         
 SPI_RW_REG(0x20 + 0x06, 0x07);    
 SPI_RW_REG(0x20 + 0x00, 0x0e);      
 CE = 1;
 }
 
  unsigned char nRF24l01_TxPacket(unsigned char *pBuf)			 
 {
  unsigned char status;
 
 CE = 0;
 SPI_WRITE_BUF(0xA0, pBuf, 5);
 CE = 1;
 
 while (IRQ != 0) ;
 
 status = SPI_READ(0x07);
 SPI_RW_REG(0x20 + 0x07, status);
 
 if (status & 0x10)
 {
 SPI_RW_REG(0xE1, 0XFF);
 return 0x10;
 }
 if (status & 0x20)
 {
 return 0x20;
 }
 return 0;	
 }
 
 
 
 
 
  unsigned char NRF24L01_RXPacket(unsigned int *rxbuf)
 {
  unsigned char status;
 
 status = SPI_READ(0x07);	    
 CE = 0;
 SPI_RW_REG(0x20 + 0x07, status);	    
 CE = 1;
 
 if (status & 0x40)				 
 {
 SPI_READ_BUF(0x61, rxbuf, 5);   
 SPI_RW_REG(0xE2, 0XFF);	  
 return 0;
 }
 return 1;   
 }
 
 void init_nrf ()	  
 {
 int i;
 for (i = 0;i < 100;i ++);
 CE = 0;
 SCK = 0;
 CSN = 1;	
 }
 
 
 
  unsigned char NRF24L01_Check(void)
 {
  unsigned char buf[5]={0XA5,0XA5,0XA5,0XA5,0XA5};
  unsigned char i;
 
 SPI_WRITE_BUF(0x20+0x10,buf,5); 
 SPI_READ_BUF(0x10,buf,5);  
 for(i=0;i<5;i++)
 if(buf[i]!=0XA5)
 break;	 							   
 if(i!=5)
 return 1; 
 
 return 0;		  
 }
 
 
