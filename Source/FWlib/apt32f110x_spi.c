/*
  ******************************************************************************
  * @file    apt32f110_spi.c
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2022/03/06
  ******************************************************************************
  *THIS SOFTWARE WHICH IS FOR ILLUSTRATIVE PURPOSES ONLY WHICH PROVIDES 
  *CUSTOMER WITH CODING INFORMATION REGARDING THEIR PRODUCTS.
  *APT CHIP SHALL NOT BE HELD RESPONSIBILITY ADN LIABILITY FOR ANY DIRECT, 
  *INDIRECT DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF 
  *SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION 
  *CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.AND APT CHIP RESERVES 
  *THE RIGHT TO MAKE CHANGES IN THE SOFTWARE WITHOUT NOTIFICATION
  ******************************************************************************
  */

/****************************************************
//include
*****************************************************/ 
#include "apt32f110x_spi.h"

/****************************************************
//extern
*****************************************************/ 
extern void delay_nus(unsigned int t);

/*************************************************************/
//SPI RESET,CLEAR ALL REGISTER
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SPI_DeInit(void)
{
    SPI0->CR0   	= SPI_CR0_RST;
    SPI0->CR1   	= SPI_CR1_RST;
    //SPI0->DR   	 	= SPI_DR_RST;
    SPI0->SR   	 	= SPI_SR_RST;
    SPI0->CPSR   	= SPI_CPSR_RST;
    SPI0->IMSCR   	= SPI_IMSCR_RST;
    SPI0->RISR   	= SPI_RISR_RST;
    SPI0->MISR   	= SPI_MISR_RST;
    SPI0->ICR	 	= SPI_ICR_RST;
}
/*************************************************************/
//SPI software reset Initial
//ReturnValue:NONE
/*************************************************************/
void SPI_Reset(void)
{
	SPI0->SRR=0X03;
}
/*************************************************************/
//SPI DMA Control
//EntryParameter:SPI_Tx_Rx_CMD,SPI_TX_FL_Less_X,SPI_RX_FL_Greater_X
//Tx_Rx_CMD:BIT0(RX dma cmd);BIT1(TX dam cmd)
//TX_FL_Less_X:TX_FL_Less_FIFO_7,TX_FL_Less_FIFO_FLSEL
//RX_FL_Greater_X:RX_FL_Greater_FIFO_1,RX_FL_Greater_FIFO_FLSEL
//ReturnValue:NONE
/*************************************************************/
void SPI_DMA_Control(U8_T SPI_Tx_Rx_CMD , SPI_TX_DMA_SEL_TypeDef SPI_TX_FL_X , SPI_RX_DMA_SEL_TypeDef SPI_RX_FL_X)
{
	SPI0->DMACR=(SPI0->DMACR&0xfffffff0)|SPI_Tx_Rx_CMD|SPI_TX_FL_X|SPI_RX_FL_X;
}
/*************************************************************/
//SPI NSS IO Initial
//ReturnValue:NONE
/*************************************************************/
void SPI_NSS_IO_Init(U8_T SPI_NSS_IO_GROUP)
{
	if(SPI_NSS_IO_GROUP==0)
	{
		GPIOA0->CONLR = (GPIOA0->CONLR&0X0FFFFFFF)  | 0x80000000;				//PA0.7		AF5=8
	}
	else if(SPI_NSS_IO_GROUP==1)
	{
		GPIOB0->CONHR = (GPIOB0->CONHR&0XFFFFFFF0)  | 0x00000007;				//PB0.8		AF4=7
	}
	else if(SPI_NSS_IO_GROUP==2)
	{
		GPIOA1->CONHR = (GPIOA1->CONHR&0XFF0FFFFF)  | 0x00700000;				//PA1.13	AF4=7
	}
}
/*************************************************************/
//SPI Master Init 	
//EntryParameter:SPI_IO,SPI_DATA_SIZE_x,SPI_SPO_X,SPI_SPH_X,SPI_LBM_X,SPI_SCR,SPI_CPSDVSR
//SPI_IO:SPI_G0,SPI_G1,SPI_G2
//SPI_DATA_SIZE_x:SPI_DATA_SIZE_4BIT~SPI_DATA_SIZE_16BIT
//SPI_SPO_X:SPI_SPO_0,SPI_SPO_1
//SPI_SPH_X:SPI_SPH_0,SPI_SPH_1
//SPI_LBM_X:SPI_LBM_0,SPI_LBM_1
//SPI_RXIFLSEL_X:SPI_RXIFLSEL_1_8,SPI_RXIFLSEL_1_4,SPI_RXIFLSEL_1_2
//SPI_SCR:0~255
//SPI_CPSDVSR:2~254,Must be an even number between 2 and 254
//ReturnValue:NONE
/*************************************************************/
//SPI Baud rate:FSSPCLK = FPCLK / (CPSDVR × (1 + SCR))
//FPCLK (max) → 2 × FSSPCLKOUT (max) master	Fastest speed
void SPI_Master_Init(SPI_IO_TypeDef SPI_IO , SPI_DATA_SIZE_TypeDef SPI_DATA_SIZE_x , SPI_SPO_TypeDef SPI_SPO_X , SPI_SPH_TypeDef SPI_SPH_X , SPI_LBM_TypeDef SPI_LBM_X , SPI_RXIFLSEL_TypeDef SPI_RXIFLSEL_X , U8_T SPI_SCR , U8_T SPI_CPSDVSR )
{
	if (SPI_IO==SPI_G0)
    {
		GPIOA0->CONLR = (GPIOA0->CONLR&0XF0FFFFFF)  | 0x08000000;		//MOSI->PA0.6,SCK->PA0.8,MISO->PA0.9
		GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFF00)  | 0x00000088;
    }
    else if(SPI_IO==SPI_G1)
    {
		GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFF000)  | 0x00000888;		//MOSI->PA0.10,SCK->PA0.8,MISO->PA0.9
    }
	else if(SPI_IO==SPI_G2)
	{
		GPIOB0->CONHR = (GPIOB0->CONHR&0XFFFF000F)  | 0x00007770;		//MOSI->PB0.11,SCK->PB0.9,MISO->PB0.10
	}
	SPI0->CPSR=SPI_CPSDVSR;
	
	SPI0->CR0|=SPI_DATA_SIZE_x|(SPI_SPO_X<<6)|(SPI_SPH_X<<7)|(SPI_SCR<<8);
	SPI0->CR1|=0X02|SPI_LBM_X|(SPI_RXIFLSEL_X<<4);
}
/*************************************************************/
//SPI Slave Init 	
//EntryParameter:SPI_IO,SPI_DATA_SIZE_x,SPI_RXIFLSEL_X,SPI_SCR,SPI_CPSDVSR
//SPI_DATA_SIZE_x:SPI_DATA_SIZE_4BIT~SPI_DATA_SIZE_16BIT
//SPI_RXIFLSEL_X:SPI_RXIFLSEL_1_8,SPI_RXIFLSEL_1_4,SPI_RXIFLSEL_1_2
//SPI_SCR:0~255
//SPI_CPSDVSR:2~254,Must be an even number between 2 and 254
//ReturnValue:NONE
/*************************************************************/
//SPI波特率:FSSPCLK = FPCLK / (CPSDVR × (1 + SCR))
//FPCLK (max) → 12 × FSSPCLKIN (max) slave	Fastest speed
void SPI_Slave_Init(SPI_IO_TypeDef SPI_IO , SPI_DATA_SIZE_TypeDef SPI_DATA_SIZE_x , SPI_SPH_TypeDef SPI_SPH_X , SPI_RXIFLSEL_TypeDef SPI_RXIFLSEL_X , U8_T SPI_SCR , U8_T SPI_CPSDVSR)
{
	if (SPI_IO==SPI_G0)
    {
		GPIOA0->CONLR = (GPIOA0->CONLR&0XF0FFFFFF)  | 0x08000000;		//MOSI->PA0.6,SCK->PA0.8,MISO->PA0.9
		GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFF00)  | 0x00000088;
    }
    else if(SPI_IO==SPI_G1)
    {
		GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFF000)  | 0x00000888;		//MOSI->PA0.10,SCK->PA0.8,MISO->PA0.9
    }
	else if(SPI_IO==SPI_G2)
	{
		GPIOB0->CONHR = (GPIOB0->CONHR&0XFFFF000F)  | 0x00007770;		//MOSI->PB0.11,SCK->PB0.9,MISO->PB0.10
	}
	SPI0->CR0|=SPI_DATA_SIZE_x|(SPI_SPH_X<<7)|(SPI_SCR<<8);
	SPI0->CPSR=SPI_CPSDVSR;
	SPI0->CR1|=0X06|(SPI_RXIFLSEL_X<<4);
}
/*************************************************************/
//SPI WRITE BYTE
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SPI_WRITE_BYTE(U16_T wdata)
{
	while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	
	SPI0->DR = wdata;
	while(((SPI0->SR) & SSP_BSY) == SSP_BSY);		//wait for transmition finish
}
/*************************************************************/
//SPI READ BYTE
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SPI_READ_BYTE(U16_T wdata , volatile U16_T *rdata , U8_T Longth)
{
	U8_T i;
	while(((SPI0->SR) & SSP_TNF) != SSP_TNF);		//Transmit FIFO is not full？
	SPI0->DR = wdata;
	while(((SPI0->SR) & SSP_BSY) == SSP_BSY);		//Send or receive over？
	delay_nus(1);
	*rdata = SPI0->DR;
	for(i=0;i<Longth;i++)
	{
		while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	
		SPI0->DR=0;
		while(((SPI0->SR) & SSP_BSY) == SSP_BSY);
		*(rdata+i) = SPI0->DR;  	//get data from FIFO
	}
}
/*************************************************************/
//SPI inturrpt Configure
//EntryParameter:SPI_IMSCR_X,NewState
//SPI_IMSCR_X:SPI_PORIM,SPI_RTIM,SPI_RXIM,SPI_TXIM
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void SPI_ConfigInterrupt_CMD(FunctionalStatus NewState,SPI_IMSCR_TypeDef SPI_IMSCR_X)
{
	if (NewState != DISABLE)
	{
		SPI0->IMSCR  |= SPI_IMSCR_X;						//SET
	}
	else
	{
		SPI0->IMSCR  &= ~SPI_IMSCR_X;					//CLR
	}
}   
/*************************************************************/
//SPI Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SPI_Int_Enable(void)
{
    INTC_ISER_WRITE(SPI_INT);    
}
/*************************************************************/
//SPI Interrupt disalbe
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SPI_Int_Disable(void)
{
    INTC_ICER_WRITE(SPI_INT);    
}
/*************************************************************/
//SPI Interrupt wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SPI_Wakeup_Enable(void)
{
    INTC_IWER_WRITE(SPI_INT);    
}

/*************************************************************/
//SPI Interrupt wake up disalbe
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SPI_Wakeup_Disable(void)
{
    INTC_IWDR_WRITE(SPI_INT);    
}



/*********************************************************************** 
//						 END OF FILE         
***********************************************************************/