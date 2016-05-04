# ifndef __NRF_H__
# define __NRF_H__

# include <STC12C5A60S2.h> 
# include <intrins.h>	  //包含_crol_的头文件  向右移动
# define uchar unsigned char 
# define uint unsigned int
# define TX_ADR_WIDTH 5		   //五字节发送地址
# define RX_ADR_WIDTH 5
# define TX_PLOAD_WIDTH 5	   //有效数据的宽度
# define RX_PLOAD_WIDTH 5
# define nops() _nop_();_nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_()  //延时12us

/*相关命令的宏定义*/
# define READ_REG        0x00  // Define read command to register 	  读配置寄存器
# define WRITE_REG       0x20  // Define write command to register 	  写配置寄存器
# define RD_RX_PLOAD     0x61  // Define RX payload register address  读RX的有效数据
# define WR_TX_PLOAD     0xA0  // Define TX payload register address  写TX的有效数据
# define FLUSH_TX        0xE1  // Define flush TX register command 	  清除寄TX FIFO寄存器 应用与发射模式下
# define FLUSH_RX        0xE2  // Define flush RX register command 	  清除寄RX FIFO寄存器 应用与发射模式下
# define REUSE_TX_PL     0xE3  // Define reuse TX payload register command 	  应用与发射端  重新发射一包有效的数据。
# define NOP             0xFF  // Define No Operation, might be used to read status	  空操作 可用来读取状态寄存器

#define MAX_TX  		0x10  //达到最大发送次数中断
#define TX_OK   		0x20  //TX发送完成中断
#define RX_OK   		0x40  //接收到数据中断

/*NRF24l01相关寄存器地址的宏定义*/
# define CONFIG          0x00  // 'Config' register address
# define EN_AA           0x01  // 'Enable Auto Acknowledgment' register address
# define EN_RXADDR       0x02  // 'Enabled RX addresses' register address
# define SETUP_AW        0x03  // 'Setup address width' register address 
# define SETUP_RETR      0x04  // 'Setup Auto. Retrans' register address
# define RF_CH           0x05  // 'RF channel' register address
# define RF_SETUP        0x06  // 'RF setup' register address
# define STATUS          0x07  // 'Status' register address
# define OBSERVE_TX      0x08  // 'Observe TX' register address
# define CD              0x09  // 'Carrier Detect' register address
# define RX_ADDR_P0      0x0A  // 'RX address pipe0' register address			数据通道-0
# define RX_ADDR_P1      0x0B  // 'RX address pipe1' register address			数据通道-1
# define RX_ADDR_P2      0x0C  // 'RX address pipe2' register address			数据通道-2
# define RX_ADDR_P3      0x0D  // 'RX address pipe3' register address			数据通道-3
# define RX_ADDR_P4      0x0E  // 'RX address pipe4' register address			数据通道-4
# define RX_ADDR_P5      0x0F  // 'RX address pipe5' register address			数据通道-5
# define TX_ADDR         0x10  // 'TX address' register address	 //达到最大发送次数中断
# define RX_PW_P0        0x11  // 'RX payload width, pipe0' register address
# define RX_PW_P1        0x12  // 'RX payload width, pipe1' register address
# define RX_PW_P2        0x13  // 'RX payload width, pipe2' register address
# define RX_PW_P3        0x14  // 'RX payload width, pipe3' register address
# define RX_PW_P4        0x15  // 'RX payload width, pipe4' register address
# define RX_PW_P5        0x16  // 'RX payload width, pipe5' register address
# define FIFO_STATUS     0x17  // 'FIFO Status Register' register address

sbit IRQ  = P4^5;
sbit MOSI = P4^4;
sbit CSN  = P4^3;
sbit MISO = P4^2;
sbit SCK  = P4^1;
sbit CE   = P4^0;

extern char SPI_write_read_byte (char dete);		   
extern char SPI_RW_REG (char reg,char value);		   //寄存器访问函数
extern char SPI_READ (char reg);					   //读取寄存器的值
extern char SPI_READ_BUF (char reg,char *pBuf,char bytes);		//接受缓冲区访问函数
extern char SPI_WRITE_BUF (char reg,char *pBuf,char bytes);	//发射缓冲区访问函数
extern uchar NRF24L01_RXPacket(uchar *rxbuf);
extern uchar nRF24l01_TxPacket(uchar *pBuf);		   //发送数据
extern void RX_MODE ();			//接受模式 
extern void TX_MODE ();			//发送模式
extern void init_nrf ();	 //初始化
extern uchar NRF24L01_Check(void);		//检测24l01能否工作

# endif 