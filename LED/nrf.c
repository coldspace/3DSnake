# ifndef __NRF_C__
# define __NRF_C__
# include "nrf.h"

uchar code TX_ADDRESS[TX_ADR_WIDTH] = {0x34,0x43,0x10,0x10,0x01};
uchar code RX_ADDRESS[RX_ADR_WIDTH] = {0x34,0x43,0x10,0x10,0x01};
uchar TX_BUF[TX_PLOAD_WIDTH];
uchar RX_BUF[RX_PLOAD_WIDTH];

char SPI_write_read_bety (char dete)		  //基层函数
{
	uint i; 

	for (i = 0;i < 8;i ++)
	{
		MOSI = dete&0x80;
		dete <<= 1;
		SCK = 1;
		dete |= MISO;
		SCK = 0;
	}
	
	nops();

	return dete;
}

char SPI_RW_REG (char reg,char value)			//寄存器访问函数
{
	char status;

	CSN = 0;
	status = SPI_write_read_bety (reg); 
	SPI_write_read_bety (value);			  	//写数据到寄存器
	CSN = 1;
	return status;
}

char SPI_READ (uchar reg)						//读取寄存器的值
{
	uchar reg_val;

	CSN = 0;
	SPI_write_read_bety (reg);
	reg_val = SPI_write_read_bety (0xff);
	CSN = 1;
	return reg_val;
}

char SPI_READ_BUF (char reg,char *pBuf,char bytes)		  //接受缓冲区访问函数	  连续读取多个数据
{
	uchar status,byte_ctr;

	CSN = 0;
	status = SPI_write_read_bety (reg);

	for (byte_ctr = 0;byte_ctr < bytes;byte_ctr ++)
	{
		pBuf[byte_ctr] = SPI_write_read_bety (0xff);
	}
	CSN = 1;
	return status;
}

char SPI_WRITE_BUF (char reg,char *pBuf,char bytes)		 //发射缓冲区访问函数	 连续写入多个数据
{
	char status,byte_str;
	
	CSN = 0;
	status = SPI_write_read_bety (reg);
	nops();
	for (byte_str = 0;byte_str < bytes;byte_str ++)
	{
		SPI_write_read_bety (*pBuf ++);
	}
	CSN = 1;
	return status ;		
}

void RX_MODE ()			  //设定24l0l的接受方式
{
	CE = 0;
	SPI_WRITE_BUF (WRITE_REG + RX_ADDR_P0,RX_ADDRESS,TX_ADR_WIDTH);   		//接受设备接受通道为0，使用和发射设备相同的发射地址
	SPI_RW_REG(WRITE_REG + EN_AA, 0x01);     			// 使通道0可以自动应答   
	SPI_RW_REG(WRITE_REG + EN_RXADDR, 0x01); 			// 使能接受到通道0    
	SPI_RW_REG(WRITE_REG + RF_CH, 40);       			// 选择射频通道40  
	SPI_RW_REG(WRITE_REG + RX_PW_P0, RX_PLOAD_WIDTH);	// 接受通道0 选择和发送通道相同有效的数据宽度    
	SPI_RW_REG(WRITE_REG + RF_SETUP, 0x07);      	   	// 数据传输率为1Mbps，发射功率0dBm，低噪声放大器增益
	SPI_RW_REG(WRITE_REG + CONFIG, 0x0f);     			// CRC使能，16为CRC校检，上电
	CE = 1;	
}

void TX_MODE() 			  //设定24101的发送模式
{
	CE = 0;        
	SPI_WRITE_BUF(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);     	//写入发送地址  
	SPI_WRITE_BUF(WRITE_REG + RX_ADDR_P0, RX_ADDRESS, TX_ADR_WIDTH);    //为了应答接受设备，接受通道0地址和发送地址相同
	SPI_WRITE_BUF(WR_TX_PLOAD, TX_BUF, TX_PLOAD_WIDTH); // 写入数据包到TX FIFO中   
	SPI_RW_REG(WRITE_REG + EN_AA, 0x01);      // 使通道0能够自动应答    
	SPI_RW_REG(WRITE_REG + EN_RXADDR, 0x01);  // 使能接受到通道0    
	SPI_RW_REG(WRITE_REG + SETUP_RETR, 0x1a); // 自动重发延时等待500us + 86us, 自动重发10次    
	SPI_RW_REG(WRITE_REG + RF_CH, 40);        // 选择射频通道40    
	SPI_RW_REG(WRITE_REG + RF_SETUP, 0x07);   // 数据传输率为1Mbps，发射功率0dBm，低噪声放大器增益   
	SPI_RW_REG(WRITE_REG + CONFIG, 0x0e);     // CRC使能，16为CRC校检，上电 
	CE = 1;
}

uchar nRF24l01_TxPacket(uchar *pBuf)			//发送数据
{
	uchar status;

	CE = 0;
	SPI_WRITE_BUF(WR_TX_PLOAD, pBuf, TX_PLOAD_WIDTH);
	CE = 1;

	while (IRQ != 0) ;

	status = SPI_READ(STATUS);
	SPI_RW_REG(WRITE_REG + STATUS, status);

	if (status & MAX_TX)
	{
		SPI_RW_REG(FLUSH_TX, 0XFF);
		return MAX_TX;
	}
	if (status & TX_OK)
	{
		return TX_OK;
	}
	return 0;	
}


//启动NRF24L01发送一次数据
//txbuf:待发送数据首地址
//返回值:0，接收完成；其他，错误代码
uchar NRF24L01_RXPacket(uint *rxbuf)
{
	uchar status;

	status = SPI_READ(STATUS);	   //读取状态寄存器的值
	CE = 0;
	SPI_RW_REG(WRITE_REG + STATUS, status);	   //清除TX_DS或MAX_RT中断标志
	CE = 1;

	if (status & RX_OK)				//接收到数据
	{
		SPI_READ_BUF(RD_RX_PLOAD, rxbuf, RX_PLOAD_WIDTH);  //读取数据
		SPI_RW_REG(FLUSH_RX, 0XFF);	 //清除RX FIFO寄存器
		return 0;
	}
	return 1;  //没收到任何数据
}

void init_nrf ()	 //初始化
{
	int i;
	for (i = 0;i < 100;i ++);
	CE = 0;
	SCK = 0;
	CSN = 1;	
}

//检测24L01是否存在
//返回值:0，成功;1，失败	
uchar NRF24L01_Check(void)
{
	uchar buf[5]={0XA5,0XA5,0XA5,0XA5,0XA5};
	uchar i;
		 
	SPI_WRITE_BUF(WRITE_REG+TX_ADDR,buf,5);//写入5个字节的地址.	
	SPI_READ_BUF(TX_ADDR,buf,5); //读出写入的地址  
	for(i=0;i<5;i++)
		if(buf[i]!=0XA5)
			break;	 							   
	if(i!=5)
		return 1;//检测24L01错误
			
	return 0;		 //检测到24L01
}
	
#endif