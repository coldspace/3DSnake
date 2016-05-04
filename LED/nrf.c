# ifndef __NRF_C__
# define __NRF_C__
# include "nrf.h"

uchar code TX_ADDRESS[TX_ADR_WIDTH] = {0x34,0x43,0x10,0x10,0x01};
uchar code RX_ADDRESS[RX_ADR_WIDTH] = {0x34,0x43,0x10,0x10,0x01};
uchar TX_BUF[TX_PLOAD_WIDTH];
uchar RX_BUF[RX_PLOAD_WIDTH];

char SPI_write_read_bety (char dete)		  //���㺯��
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

char SPI_RW_REG (char reg,char value)			//�Ĵ������ʺ���
{
	char status;

	CSN = 0;
	status = SPI_write_read_bety (reg); 
	SPI_write_read_bety (value);			  	//д���ݵ��Ĵ���
	CSN = 1;
	return status;
}

char SPI_READ (uchar reg)						//��ȡ�Ĵ�����ֵ
{
	uchar reg_val;

	CSN = 0;
	SPI_write_read_bety (reg);
	reg_val = SPI_write_read_bety (0xff);
	CSN = 1;
	return reg_val;
}

char SPI_READ_BUF (char reg,char *pBuf,char bytes)		  //���ܻ��������ʺ���	  ������ȡ�������
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

char SPI_WRITE_BUF (char reg,char *pBuf,char bytes)		 //���仺�������ʺ���	 ����д��������
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

void RX_MODE ()			  //�趨24l0l�Ľ��ܷ�ʽ
{
	CE = 0;
	SPI_WRITE_BUF (WRITE_REG + RX_ADDR_P0,RX_ADDRESS,TX_ADR_WIDTH);   		//�����豸����ͨ��Ϊ0��ʹ�úͷ����豸��ͬ�ķ����ַ
	SPI_RW_REG(WRITE_REG + EN_AA, 0x01);     			// ʹͨ��0�����Զ�Ӧ��   
	SPI_RW_REG(WRITE_REG + EN_RXADDR, 0x01); 			// ʹ�ܽ��ܵ�ͨ��0    
	SPI_RW_REG(WRITE_REG + RF_CH, 40);       			// ѡ����Ƶͨ��40  
	SPI_RW_REG(WRITE_REG + RX_PW_P0, RX_PLOAD_WIDTH);	// ����ͨ��0 ѡ��ͷ���ͨ����ͬ��Ч�����ݿ��    
	SPI_RW_REG(WRITE_REG + RF_SETUP, 0x07);      	   	// ���ݴ�����Ϊ1Mbps�����书��0dBm���������Ŵ�������
	SPI_RW_REG(WRITE_REG + CONFIG, 0x0f);     			// CRCʹ�ܣ�16ΪCRCУ�죬�ϵ�
	CE = 1;	
}

void TX_MODE() 			  //�趨24101�ķ���ģʽ
{
	CE = 0;        
	SPI_WRITE_BUF(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);     	//д�뷢�͵�ַ  
	SPI_WRITE_BUF(WRITE_REG + RX_ADDR_P0, RX_ADDRESS, TX_ADR_WIDTH);    //Ϊ��Ӧ������豸������ͨ��0��ַ�ͷ��͵�ַ��ͬ
	SPI_WRITE_BUF(WR_TX_PLOAD, TX_BUF, TX_PLOAD_WIDTH); // д�����ݰ���TX FIFO��   
	SPI_RW_REG(WRITE_REG + EN_AA, 0x01);      // ʹͨ��0�ܹ��Զ�Ӧ��    
	SPI_RW_REG(WRITE_REG + EN_RXADDR, 0x01);  // ʹ�ܽ��ܵ�ͨ��0    
	SPI_RW_REG(WRITE_REG + SETUP_RETR, 0x1a); // �Զ��ط���ʱ�ȴ�500us + 86us, �Զ��ط�10��    
	SPI_RW_REG(WRITE_REG + RF_CH, 40);        // ѡ����Ƶͨ��40    
	SPI_RW_REG(WRITE_REG + RF_SETUP, 0x07);   // ���ݴ�����Ϊ1Mbps�����书��0dBm���������Ŵ�������   
	SPI_RW_REG(WRITE_REG + CONFIG, 0x0e);     // CRCʹ�ܣ�16ΪCRCУ�죬�ϵ� 
	CE = 1;
}

uchar nRF24l01_TxPacket(uchar *pBuf)			//��������
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


//����NRF24L01����һ������
//txbuf:�����������׵�ַ
//����ֵ:0��������ɣ��������������
uchar NRF24L01_RXPacket(uint *rxbuf)
{
	uchar status;

	status = SPI_READ(STATUS);	   //��ȡ״̬�Ĵ�����ֵ
	CE = 0;
	SPI_RW_REG(WRITE_REG + STATUS, status);	   //���TX_DS��MAX_RT�жϱ�־
	CE = 1;

	if (status & RX_OK)				//���յ�����
	{
		SPI_READ_BUF(RD_RX_PLOAD, rxbuf, RX_PLOAD_WIDTH);  //��ȡ����
		SPI_RW_REG(FLUSH_RX, 0XFF);	 //���RX FIFO�Ĵ���
		return 0;
	}
	return 1;  //û�յ��κ�����
}

void init_nrf ()	 //��ʼ��
{
	int i;
	for (i = 0;i < 100;i ++);
	CE = 0;
	SCK = 0;
	CSN = 1;	
}

//���24L01�Ƿ����
//����ֵ:0���ɹ�;1��ʧ��	
uchar NRF24L01_Check(void)
{
	uchar buf[5]={0XA5,0XA5,0XA5,0XA5,0XA5};
	uchar i;
		 
	SPI_WRITE_BUF(WRITE_REG+TX_ADDR,buf,5);//д��5���ֽڵĵ�ַ.	
	SPI_READ_BUF(TX_ADDR,buf,5); //����д��ĵ�ַ  
	for(i=0;i<5;i++)
		if(buf[i]!=0XA5)
			break;	 							   
	if(i!=5)
		return 1;//���24L01����
			
	return 0;		 //��⵽24L01
}
	
#endif