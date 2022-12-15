/*
  ******************************************************************************
  * @file    apt32f110_usart.c
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2022/08/08
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
#include "apt32f110x_usart.h"

/****************************************************
//define
*****************************************************/ 
#define LOOPBUFSIZE ((U16_T) 0x20)
volatile U8_T RxDataBuf[LOOPBUFSIZE+4];
volatile U8_T RxDataFlag;
volatile U8_T TxDataFlag;


/*************************************************************/
//USART RESET,CLEAR ALL REGISTER
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void USART_DeInit(void)
{
	USART0->IDR   	= USART_IDR_RST;
	USART0->CEDR   	= USART_CEDR_RST;
	USART0->SRR 	= USART_SRR_RST;
	USART0->CR 		= USART_CR_RST;
	USART0->MR   	= USART_MR_RST;
	USART0->IMSCR   = USART_IMSCR_RST;
	USART0->RISR  	= USART_RISR_RST;
	USART0->MISR   	= USART_MISR_RST;
	USART0->ICR   	= USART_ICR_RST;
	USART0->SR   	= USART_SR_RST;
	USART0->RHR   	= USART_RHR_RST;
	USART0->THR   	= USART_THR_RST;
	USART0->BRGR   	= USART_BRGR_RST;
	USART0->RTOR   	= USART_RTOR_RST;
	USART0->TTGR   	= USART_TTGR_RST;
}
/*************************************************************/
//USART DMA Control
//EntryParameter:USART_Tx_Rx_CMD,UART_TX_FL_X,UART_RX_FL_X
//USART_Tx_Rx_CMD:BIT0(RX dma cmd);BIT1(TX dam cmd)
//USART_TX_FL_X:USART_TX_FL_FIFO_NF,USART_TX_FL_Less_FIFO_1_2
//USART_RX_FL_X:USART_RX_FL_FIFO_NE,USART_RX_FL_FIFO_FLSEL
//ReturnValue:NONE
/*************************************************************/
void USART_DMA_Control(U8_T USART_Tx_Rx_CMD , USART_TX_DMA_SEL_TypeDef USART_TX_FL_X , USART_RX_DMA_SEL_TypeDef USART_RX_FL_X)
{
	USART0->DMACR=(USART0->DMACR&0xfffffff0)|USART_Tx_Rx_CMD|USART_TX_FL_X|USART_RX_FL_X;
}
/*************************************************************/
//USART Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void USART_Int_Enable(void)
{
    USART0->ICR=0x7FF;									//clear USART INT status
	INTC_ISER_WRITE(USART_INT);							//INT Vector Enable USART Interrupt
}
/*************************************************************/
//USART Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void USART_Int_Disable(void)
{
	INTC_ICER_WRITE(USART_INT);							//INT Vector Enable USART Interrupt
}
/*************************************************************/
//USART Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void USART_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(USART_INT);    
}

/*************************************************************/
//USART Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void USART_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(USART_INT);    
}
/*************************************************************/
//USART IO Init
//EntryParameter:USART_IO_G
//USART_IO_G:0 1
//ReturnValue:NONE
/*************************************************************/
void USART_IO_Init(USART_NUM_TypeDef USART_IO_G)
{
    if (USART_IO_G==USART_TxPB0_2_RxPA0_6)
    {
		GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFF0FF)  | 0x00000600; 
		GPIOA0->CONLR = (GPIOA0->CONLR&0XF0FFFFFF)  | 0x06000000; 
    }
    if (USART_IO_G==USART_TxPA0_8_RxPA0_6)
    {
		GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFF0)  | 0x00000007; 
		GPIOA0->CONLR = (GPIOA0->CONLR&0XF0FFFFFF)  | 0x06000000; 
    }
	if (USART_IO_G==USART_TxPA1_4_RxPA1_5)
    {
		GPIOA1->CONLR = (GPIOA1->CONLR&0XFF00FFFF)  | 0x00770000; 
    }
	if (USART_IO_G==USART_TxPA1_9_RxPA1_10)
    {
		GPIOA1->CONHR = (GPIOA1->CONHR&0XFFFFF00F)  | 0x00000770; 
    }
}
/*************************************************************/
//USART IO Init
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void USART_CLKIO_Init(USART_CLKNUM_TypeDef USART_CLKIO_G)
{
    if (USART_CLKIO_G==CLK_PA1_3)
    {
		GPIOA1->CONLR = (GPIOA1->CONLR&0XFFFF0FFF)  | 0x00007000;      
    }
	if (USART_CLKIO_G==CLK_PB0_9)
    {
		GPIOB0->CONHR = (GPIOB0->CONHR&0XFFFFFF0F)  | 0x00000080;       
    }
	if (USART_CLKIO_G==CLK_PB0_11)
    {
		GPIOB0->CONHR = (GPIOB0->CONHR&0XFFFF0FFF)  | 0x00009000;       
    }
	if (USART_CLKIO_G==CLK_PA1_11)
    {
		GPIOA1->CONHR = (GPIOA1->CONHR&0XFFFF0FFF)  | 0x00009000;       
    }
}
/*************************************************************/
//USART Software reset
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void USART_Software_Reset(void)
{
	USART0->SRR =0x01;
}
/*************************************************************/
//USART close
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void USART_CLK_Disable(void)
{
   USART0->CEDR |= 0; 							//Disable USART Clock 
}
/*************************************************************/
//USART CLK enable
//EntryParameter:INT_RegVal
//ReturnValue:NONE
/*************************************************************/
void USART_CLK_Enable(void)
{
   USART0->CEDR |= 1; 							//Disable USART Clock 
}
/*************************************************************/
//USART INT config
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void USART_INT_Config(USART_INT_TypeDef int_type,FunctionalStatus newState)
{
	CSP_USART_SET_ICR(USART0, 0xFFFFFFFF);			// Clear all interrupt
	if (newState != DISABLE)
	{
		USART0->IMSCR |=1<<int_type;					// Interrupt Enable
	}
	else
	{
		USART0->IMSCR |=0<<int_type;					// Interrupt Disable
	}
}
/*************************************************************/
//USART INT config from INT_RegVal
//EntryParameter:INT_RegVal
//ReturnValue:NONE
/*************************************************************/
void USART_INT_RegConfig(U32_T INT_RegVal)
{
	CSP_USART_SET_ICR(USART0, 0xFFFFFFFF);
	CSP_USART_SET_IMSCR(USART0, INT_RegVal);

}
/*************************************************************/
//USART mode config
//EntryParameter:INT_RegVal
//ReturnValue:NONE
/*************************************************************/
void USART_MODE_Config(USART_SENDTIME_TypeDef SENDTIME_DATA,USART_CLKS_TypeDef CLKS_DATA, USART_CHRL_TypeDef CHRL_DATA,
						USART_SYNC_TypeDef SYNC_DATA,USART_PAR_TypeDef PAR_DAT,USART_NBSTOP_TypeDef NBSTOP_DATA,USART_CHMODE_TypeDef CHMODE_DATA)
{
	USART0->MR |= 0<<17;
	USART0->MR |= SENDTIME_DATA | CLKS_DATA | CHRL_DATA | SYNC_DATA | PAR_DAT| NBSTOP_DATA | CHMODE_DATA;
}
/*************************************************************/
//USART control regster config
//EntryParameter:CTRL_DATA, ENABLE/DISABLE
//ReturnValue:NONE
/*************************************************************/
void USART_CTRL_Config(USART_CTRL_TypeDef CTRL_DATA,FunctionalStatus newState)
{
	if (newState!=DISABLE)
	{
		USART0->CR  |= 1<<CTRL_DATA;
	}
	else
	{
		USART0->CR  |= 0<<CTRL_DATA;
	}
}
/*************************************************************/
//USART DSB CONFIG 
//EntryParameter:LSBtoMSB / MSBtoLSB
//ReturnValue:NONE
/*************************************************************/
void USART_DSB_Config(USART_DSB_TypeDef DSB_DATA)
{
	USART0->MR |= DSB_DATA;
}
/*************************************************************/
//USART SAMRTCARD Interface config
//EntryParameter:DISABLE/ENABLE
//ReturnValue:NONE
/*************************************************************/
void USART_SAMRTCARD_Config(FunctionalStatus newState)
{
	if (newState!=DISABLE)
	{
		USART0->MR |= 1<<16;
	}
	else
	{
		USART0->MR |= 0<<16;
	}
}
/*************************************************************/
//USART CLK OUT config
//EntryParameter:DISABLE/ENABLE
//ReturnValue:NONE
/*************************************************************/
void USART_CLKO_Config(FunctionalStatus newState)
{
	if (newState!=DISABLE)
	{
		USART0->MR |= (1<<18) | (0<<4) ;
	}
	else
	{
		USART0->MR |= 0<<18;
	}
}
/*************************************************************/
//USART baudrate calculate
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void USART_Baudrate_Cal(unsigned int rate,unsigned int PCLK_Val,USART_CLKS_TypeDef CLKS_DATA,USART_SYNC_TypeDef SYNC_DATA)
{
	unsigned int PCLK_Data=0;
	unsigned int BRGR_Data=0;
	if (CLKS_DATA==PCLK_DIV8)
	{
		PCLK_Data=PCLK_Val/8;
	}
	else PCLK_Data=PCLK_Val;
	if (SYNC_DATA==SYNC)
	{
		BRGR_Data=PCLK_Data/rate;			//SYNC同步
	}
	else 
	{
		BRGR_Data=PCLK_Data/16/rate;				//ASYNC异步
	}
	USART0->BRGR = BRGR_Data<<4;
}
/*************************************************************/
//USART Receiver Time Out and Transmitter Timer Guard Initial
//EntryParameter:INT_RegVal
//ReturnValue:NONE
/*************************************************************/
void USART_TGTO_Config(U8_T timeOut_u8,U8_T timeGuard_u8)
{
    USART0->RTOR=timeOut_u8;					// Set Receiver Time Out
    USART0->TTGR=timeGuard_u8;					// Set Transmitter Timer Guard
}
/*************************************************************/
//USART TX byte
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void USART_TxByte(U16_T TXdata_u8)
{
	CSP_USART_SET_THR(USART0,TXdata_u8);		// Write the transmit buffer
	while ( (CSP_USART_GET_RISR(USART0) & USART_TXRDY) != USART_TXRDY ) {}	// Wait for the transmit done
	CSP_USART_SET_ICR(USART0, USART_TXRDY);		// Clear status bit for the next transmit
}
/*************************************************************/
//UART Transmit 
//EntryParameter:UART0,UART1,sourceAddress_u16,length_u16
//ReturnValue:NONE
/*************************************************************/
void USARTTransmit(U16_T *sourceAddress_u16,U16_T length_u16)
{
	unsigned int  DataJ;  //DataI,
	for(DataJ = 0;DataJ < length_u16 ;DataJ ++)
	{
		CSP_USART_SET_THR(USART0,*sourceAddress_u16++);
		/*do{
			DataI = CSP_USART_GET_RHR(USART0);
			DataI = DataI & USART_TXRDY;
		}while(DataI == USART_TXRDY);    //Loop  when tx is full
		*/
		while ( (CSP_USART_GET_RISR(USART0) & USART_TXRDY) != USART_TXRDY ) {}	// Wait for the transmit done
		CSP_USART_SET_ICR(USART0, USART_TXRDY);		// Clear status bit for the next transmit
	}
}
/*************************************************************/
//UART RX Byte 
//EntryParameter:UART0,UART1,Rxdata_u16
//ReturnValue:NONE
/*************************************************************/
U16_T USARTRxByte(CSP_UART_T *uart,U16_T *Rxdata_u16)
{
	unsigned int  DataI;

	DataI = CSP_USART_GET_RHR(USART0);
	DataI = DataI & USART_RXRDY;
	if(DataI != USART_RXRDY)    //Loop  when rx is not full
		return FALSE;
	else
	{
		*Rxdata_u16 = CSP_USART_GET_RHR(USART0);
	    return TRUE;
	}
}

/*************************************************************/
//USART Return RX byte by interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
U16_T USART_ReturnRxByte(void)
{
	RxDataFlag = FALSE;
	while(RxDataFlag != TRUE);
	return CSP_USART_GET_RHR(USART0);
}
/*************************************************************/
//USART Receive 
//EntryParameter:destAddress_u16,length_u16
//ReturnValue:NONE
/*************************************************************/
U16_T USARTReceive(U16_T *destAddress_u16,U16_T length_u16)
{
	unsigned int  DataI,DataJ,LoopTime;

	DataJ = 0;
	LoopTime = 0;
	do{
		DataI = CSP_USART_GET_RHR(USART0);
		DataI = DataI & USART_RXRDY;
		if(DataI == USART_RXRDY)    //Loop  when rx is full
		{
			*destAddress_u16++ = CSP_USART_GET_RHR(USART0);
			DataJ++;
			LoopTime = 0;
		}
		if(LoopTime ++ >= 0xfff0)
			return FALSE;
	}while(DataJ < length_u16);
	return TRUE;
}



/*********************************************************************** 
//						 END OF FILE         
***********************************************************************/