/*
  ******************************************************************************
  * @file    apt32f110_uart.c
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2022/01/13
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
#include "apt32f110x_uart.h"

/****************************************************
//define
*****************************************************/ 
volatile U8_T RxDataFlag=0;
volatile U8_T TxDataFlag=0;
volatile U8_T f_Uart_send_Complete;
volatile U16_T Uart_send_Length_temp;
volatile U8_T Uart_send_Length;
volatile U8_T Uart_buffer[UART_BUFSIZE];



/*************************************************************/
//UART RESET,CLEAR ALL REGISTER
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART0_DeInit(void)
{
    UART0->DATA = UART_RESET_VALUE;
    UART0->SR   = UART_RESET_VALUE;
    UART0->CTRL = UART_RESET_VALUE;
    UART0->ISR  = UART_RESET_VALUE;
    UART0->BRDIV =UART_RESET_VALUE;
}
void UART1_DeInit(void)
{
    UART1->DATA = UART_RESET_VALUE;
    UART1->SR   = UART_RESET_VALUE;
    UART1->CTRL = UART_RESET_VALUE;
    UART1->ISR  = UART_RESET_VALUE;
    UART1->BRDIV =UART_RESET_VALUE;
}
void UART2_DeInit(void)
{
	UART2->DATA = UART_RESET_VALUE;
    UART2->SR   = UART_RESET_VALUE;
    UART2->CTRL = UART_RESET_VALUE;
    UART2->ISR  = UART_RESET_VALUE;
    UART2->BRDIV =UART_RESET_VALUE;
}
/*************************************************************/
//UART DMA Control
//EntryParameter:*uart,UART_Tx_Rx_CMD,UART_TX_FL_X,UART_RX_FL_X
//*uart:UART0,UART1,UART2
//UART_Tx_Rx_CMD:BIT0(RX dma cmd);BIT1(TX dam cmd)
//UART_TX_FL_X:UART_TX_FL_FIFO_NF,UART_TX_FL_Less_FIFO_1_2
//UART_RX_FL_X:UART_RX_FL_FIFO_NE,UART_RX_FL_FIFO_FLSEL
//ReturnValue:NONE
/*************************************************************/
void UART_DMA_Control(CSP_UART_T *uart , U8_T UART_Tx_Rx_CMD , UART_TX_DMA_SEL_TypeDef UART_TX_FL_X , UART_RX_DMA_SEL_TypeDef UART_RX_FL_X)
{
	uart->DMACR=(uart->DMACR&0xfffffff0)|UART_Tx_Rx_CMD|UART_TX_FL_X|UART_RX_FL_X;
}
/*************************************************************/
//UART0 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART0_Int_Enable(void)
{
    UART0->ISR=0x0F;									//clear UART0 INT status
	INTC_ISER_WRITE(UART0_INT);							//INT Vector Enable UART0/1 Interrupt in CK802
}
/*************************************************************/
//UART0 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART0_Int_Disable(void)
{
	INTC_ICER_WRITE(UART0_INT);							//INT Vector Enable UART0/1 Interrupt in CK802
}
/*************************************************************/
//UART1 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART1_Int_Enable(void)
{
    UART1->ISR=0x0F;									//clear UART1 INT status
	INTC_ISER_WRITE(UART1_INT);							//INT Vector Enable UART0/1 Interrupt in CK802
}
/*************************************************************/
//UART1 Interrupt Disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART1_Int_Disable(void)
{
    INTC_ICER_WRITE(UART1_INT);							//INT Vector Enable UART0/1 Interrupt in CK802
}
/*************************************************************/
//UART1 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART2_Int_Enable(void)
{
    UART2->ISR=0x0F;									//clear UART1 INT status
	INTC_ISER_WRITE(UART2_INT);							//INT Vector Enable UART0/1 Interrupt in CK802
}
/*************************************************************/
//UART1 Interrupt Disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART2_Int_Disable(void)
{
    INTC_ICER_WRITE(UART2_INT);							//INT Vector Enable UART0/1 Interrupt in CK802
}
/*************************************************************/
//UART0 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART0_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(UART0_INT);    
}

/*************************************************************/
//UART0 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART0_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(UART0_INT);    
}
/*************************************************************/
//UART0 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART1_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(UART1_INT);    
}

/*************************************************************/
//UART0 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART1_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(UART1_INT);    
}
/*************************************************************/
//UART0 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART2_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(UART2_INT);    
}

/*************************************************************/
//UART0 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART2_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(UART2_INT);    
}
/*************************************************************/
//UART IO Init
//EntryParameter:IO_UARTX,UART_IO_G
//IO_UARTX:IO_UART0,IO_UART1
//UART_IO_G:0 1
//ReturnValue:NONE
/*************************************************************/
void UART_IO_Init(UART_NUM_TypeDef IO_UART_NUM , U8_T UART_IO_G)
{
     if (IO_UART_NUM==IO_UART0)
    {
		if(UART_IO_G==0)
		{
			GPIOA1->CONLR = (GPIOA1->CONLR&0XF0FFFFFF)  | 0x07000000;		//PA1.6->TXD0, PB0.5->RXD0
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFF0FFFFF)  | 0x00700000;      
		}
		else if(UART_IO_G==1)
		{
			GPIOB0->CONHR = (GPIOB0->CONHR&0XFFFFFF00)  | 0x00000055;      //PB0.8->TXD0, PB0.9->RXD0
		}
    }
     if (IO_UART_NUM==IO_UART1)
    {
        if(UART_IO_G==0)
		{
			GPIOA0->CONLR = (GPIOA0->CONLR&0XF0FFFFFF)  | 0x07000000;		//PB0.2->TXD0 , PA0.6->RXD0
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFF0FF)  | 0x00000700;      
		}
    }
	 if (IO_UART_NUM==IO_UART2)
    {
        if(UART_IO_G==0)
		{
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFF00)  | 0x00000044;       //PB0.0->TXD2, PB0.1->RXD2
		}
		else if(UART_IO_G==1)
		{
			GPIOB0->CONLR = (GPIOB0->CONLR&0X00FFFFFF) | 0X77000000;        //PB0.6->TXD2 , PB0.7->RXD2
		}
		else if(UART_IO_G==2)
		{
			GPIOA1->CONHR = (GPIOA1->CONHR&0XFFF00FFF) | 0X00066000;        //PA1.11->TXD2 , PA1.12->RXD2
		}
    }
}
/*************************************************************/
//UART Init
//EntryParameter:UART0,UART1,UART2 ,baudrate_u16 
//e.g:
//sys_clk@24MHz, 24/4(div)=6MHz, 6000000/115200bps=52,baudrate_u16=52
//sys_clk@24MHz, 24/2(div)=12MHz, 12000000/115200bps=104,baudrate_u16=104
//ReturnValue:NONE
/*************************************************************/
void UARTInit(CSP_UART_T *uart,U16_T baudrate_u16,UART_PAR_TypeDef PAR_DAT)
{
   // Set Transmitter Enable
   CSP_UART_SET_CTRL(uart, PAR_DAT|UART_TX | UART_RX|(0X01<<31)|(0x01<<11));		
   // Set Baudrate
   CSP_UART_SET_BRDIV(uart, baudrate_u16);
   
}
/*************************************************************/
//UART init and enable RX,TX interrupt
//EntryParameter:UART0,UART1,UART2 ,baudrate_u16 
//ReturnValue:NONE
/*************************************************************/
void UARTInitRxTxIntEn(CSP_UART_T *uart,U16_T baudrate_u16,UART_PAR_TypeDef PAR_DAT)
{
   // Set Transmitter Enable		
   CSP_UART_SET_CTRL(uart, PAR_DAT|UART_TX | UART_RX | UART_RX_INT | UART_TX_INT|(0X01<<31)|(0x01<<11));
   
   // Set Baudrate
   CSP_UART_SET_BRDIV(uart, baudrate_u16);
}
/*************************************************************/
//UART init and enable RX interrupt
//EntryParameter:UART0,UART1,UART2 ,baudrate_u16 
//ReturnValue:NONE
/*************************************************************/
void UARTInitRxIntEn(CSP_UART_T *uart,U16_T baudrate_u16,UART_PAR_TypeDef PAR_DAT)
{
   // Set Transmitter Enable			
   CSP_UART_SET_CTRL(uart, PAR_DAT|UART_TX | UART_RX | UART_RX_INT|(0X01<<31)|(0x01<<11));
   // Set Baudrate
   CSP_UART_SET_BRDIV(uart, baudrate_u16);
   
}
/*************************************************************/
//UART Close
//EntryParameter:UART0,UART1,UART2
//ReturnValue:NONE
/*************************************************************/
void UARTClose(CSP_UART_T *uart)
{
	// Set Transmitter Disable
	CSP_UART_SET_CTRL(uart, 0x00);
}
/*************************************************************/
//UART TX Byte loop send
//EntryParameter:UART0,UART1,UART2,txdata_u8
//ReturnValue:NONE
/*************************************************************/
void UARTTxByte(CSP_UART_T *uart,U8_T txdata_u8)
{
	unsigned int  DataI;
	// Write the transmit buffer
	CSP_UART_SET_DATA(uart,txdata_u8);
	do
	{
		DataI = CSP_UART_GET_SR(uart);
		DataI = DataI & UART_TX_FULL;
	}
	while(DataI == UART_TX_FULL);    //Loop  when tx is full
}
/*************************************************************/
//UART Transmit 
//EntryParameter:UART0,UART1,UART2,sourceAddress_u16,length_u16
//ReturnValue:NONE
/*************************************************************/
void UARTTransmit(CSP_UART_T *uart,U8_T *sourceAddress_u16,U16_T length_u16)
{
	unsigned int  DataI,DataJ;
	for(DataJ = 0;DataJ < length_u16 ;DataJ ++)
	{
		CSP_UART_SET_DATA(uart,*sourceAddress_u16++);
		do{
			DataI = CSP_UART_GET_SR(uart);
			DataI = DataI & UART_TX_FULL;
		}while(DataI == UART_TX_FULL);    //Loop  when tx is full
	}
}
/*************************************************************/
//UART  INT Transmit 
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void UARTTTransmit_data_set(CSP_UART_T *uart )
{
	if(!f_Uart_send_Complete)
	{
		f_Uart_send_Complete=1;
		Uart_send_Length_temp++;
		CSP_UART_SET_DATA(uart,Uart_buffer[0]);
	}
}
void UARTTransmit_INT_Send(CSP_UART_T *uart )
{
	if(f_Uart_send_Complete)
	{
		if(Uart_send_Length_temp>=Uart_send_Length)
		{
			f_Uart_send_Complete=0;
			Uart_send_Length_temp=0;
		}
		else
		{
			CSP_UART_SET_DATA(uart,Uart_buffer[Uart_send_Length_temp++]);
		}
	}	
}
/*************************************************************/
//UART RX Byte 
//EntryParameter:UART0,UART1,UART2,Rxdata_u16
//ReturnValue:NONE
/*************************************************************/
U16_T UARTRxByte(CSP_UART_T *uart,U8_T *Rxdata_u16)
{
	unsigned int  DataI;

	DataI = CSP_UART_GET_SR(uart);
	DataI = DataI & UART_RX_FULL;
	if(DataI != UART_RX_FULL)    //Loop  when rx is not full
		return FALSE;
	else
	{
		*Rxdata_u16 = CSP_UART_GET_DATA(uart);
	    return TRUE;
	}
}

/*************************************************************/
//UART RX Return Byte 
//EntryParameter:UART0,UART1,UART2
//ReturnValue:(uart)->DATA
/*************************************************************/
U8_T UART_ReturnRxByte(CSP_UART_T *uart)
{
	RxDataFlag = FALSE;
	while(RxDataFlag != TRUE);
	return CSP_UART_GET_DATA(uart);
}

/*************************************************************/
//UART Receive
//EntryParameter:UART0,UART1,UART2，destAddress_u16，length_u16
//ReturnValue:FALSE/TRUE
/*************************************************************/
U16_T UARTReceive(CSP_UART_T *uart,U8_T *destAddress_u16,U16_T length_u16)
{
	unsigned int  DataI,DataJ,LoopTime;

	DataJ = 0;
	LoopTime = 0;
	do{
		DataI = CSP_UART_GET_SR(uart);
		DataI = DataI & UART_RX_FULL;
		if(DataI == UART_RX_FULL)    //Loop  when rx is full
		{
			*destAddress_u16++ = CSP_UART_GET_DATA(uart);
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