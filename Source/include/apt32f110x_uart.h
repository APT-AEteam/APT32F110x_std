/*
  ******************************************************************************
  * @file    apt32f110_uart.h
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
 
 
#ifndef _apt32f110_uart_H
#define _apt32f110_uart_H

/****************************************************
//include
*****************************************************/ 
#include "apt32f110x.h"

#define UART_BUFSIZE             32

/***********************************************************************
 @brief UART PAR Selecte
***********************************************************************/ 
typedef enum
{
	UART_PAR_NONE	=0<<8,			//无校验位
	UART_PAR_EVEN	=4<<8,			//偶校验位
	UART_PAR_ODD	=5<<8,			//奇校验位
	UART_PAR_SPACE	=6<<8,			//0校验位
	UART_PAR_MARK	=7<<8			//1校验位
}UART_PAR_TypeDef;
/***********************************************************************
 @brief UART IO setting
***********************************************************************/ 
typedef enum
{
    IO_UART0 = 0,
    IO_UART1 = 1,
	IO_UART2 = 2,
}UART_NUM_TypeDef;
/***********************************************************************
 @brief UART Function defined
***********************************************************************/ 
#define UART_RESET_VALUE  		(0x00000000)  		// UART Reset Regist
#define UART_TX_FULL     		(0x01ul << 0)  		// Transmitter full             
#define UART_RX_FULL     		(0x01ul << 1)  		// Receiver full                
#define UART_TX_OVER     		(0x01ul << 2)  		// Transmitter buff over      
#define UART_RX_OVER     		(0x01ul << 3)  		// Receiver buff over  
/***********************************************************************
 @brief UART Control Register	
***********************************************************************/          								  	  
#define UART_TX         		(0x01ul << 0)  		// Transmitter Enable/disable        
#define UART_RX         		(0x01ul << 1)  		// Receiver Enable/disable           
#define UART_TX_INT     		(0x01ul << 2)  		// Transmitter INT Enable/disable    
#define UART_RX_INT     		(0x01ul << 3)  		// Receiver INT Enable/disable       
#define UART_TX_IOV     		(0x01ul << 4)  		// Transmitter INTOver Enable/disable
#define UART_RX_IOV     		(0x01ul << 5)  		// Receiver INTOver Enable/disable   
#define UART_PARUTY_ERR_INT    	(0x01ul << 7)  		// PARUTY ERROR Status        
#define UART_TX_FIFO_INT    	(0x01ul << 12)  	// TX fifo int Enable/disable    
#define UART_RX_FIFO_INT    	(0x01ul << 13)  	// RX fifo int Enable/disable    
#define UART_RX_FIFOOV_INT    	(0x01ul << 18)  	// RX fifo int over Enable/disable    
#define UART_TX_DONE_INT    	(0x01ul << 19)  	// Receiver TX  done Enable/disable   

#define UART_TEST_MODE  		(0x01ul << 6)  		// =1 Test mode                      								

/***********************************************************************
 @brief UART Interrupt Status Register		
***********************************************************************/								
#define UART_TX_INT_S    		(0x01ul << 0)  		// Transmitter INT Status        
#define UART_RX_INT_S    		(0x01ul << 1)  		// Receiver INTStatus             
#define UART_TX_IOV_S    		(0x01ul << 2)  		// Transmitter INTOver Status     
#define UART_RX_IOV_S    		(0x01ul << 3)  		// Receiver INTOver Status       
#define UART_PARUTY_ERR_S    	(0x01ul << 4)  		// PARUTY ERROR Status        
#define UART_TXMIS_S    		(0x01ul << 5)  		// tx fifo Status        
#define UART_RXMIS_S    		(0x01ul << 6)  		// rx fifo Status        
#define UART_RORMIS_S    		(0x01ul << 7)  		// rx fifo over Status        
#define UART_TX_DONE_S    		(0x01ul << 19)  	// Receiver INTOver Status        

/***********************************************************************
 @brief UART DATA control         	
***********************************************************************/                                                  
#define CSP_UART_SET_DATA(uart, val)  ((uart)->DATA = (val))                                                     
#define CSP_UART_GET_DATA(uart)       ((uart)->DATA)

/***********************************************************************
 @brief UART SR control            	
***********************************************************************/                                                          
#define CSP_UART_SET_SR(uart, val)  ((uart)->SR = (val))                                                      
#define CSP_UART_GET_SR(uart)       ((uart)->SR)

/***********************************************************************
 @brief UART controls            	
***********************************************************************/                                                      
#define CSP_UART_SET_CTRL(uart, val)  ((uart)->CTRL = (val))                                                  
#define CSP_UART_GET_CTRL(uart)       ((uart)->CTRL)

/***********************************************************************
 @brief UART ISr control            	
***********************************************************************/                                                        
#define CSP_UART_SET_ISR(uart, val)  ((uart)->ISR = (val))                                                      
#define CSP_UART_GET_ISR(uart)       ((uart)->ISR)

/***********************************************************************
 @brief UART DIV control            	
***********************************************************************/                                                        
#define CSP_UART_SET_BRDIV(uart, val)  ((uart)->BRDIV = (val))                                                    
#define CSP_UART_GET_BRDIV(uart)       ((uart)->BRDIV)

/***********************************************************************
 @brief UART TX DMA control            	
***********************************************************************/  
typedef enum
{
	UART_TX_FL_FIFO_NF		=	0X00<<3,			//未满
	UART_TX_FL_Less_FIFO_1_2	=	0X01<<3				//FIFO数据占用<=1/2
}UART_TX_DMA_SEL_TypeDef;

/***********************************************************************
 @brief UART RX DMA control            	
***********************************************************************/  
typedef enum
{
	UART_RX_FL_FIFO_NE		=	0X00<<2,			//非空
	UART_RX_FL_FIFO_FLSEL	=	0X01<<2				//FIFO数据达到中断触发点
}UART_RX_DMA_SEL_TypeDef;


/*********************************************************************** 
 @brief  UART extern variable                 
***********************************************************************/ 
extern	volatile U16_T RxDataBuf[12];
extern	volatile U16_T RxDataPtr;
extern	volatile U16_T TxDataPtr;
extern	volatile U8_T RxDataFlag;
extern	volatile U8_T TxDataFlag;
extern	volatile U8_T Uart_send_Length;
extern volatile U16_T Uart_send_Length_temp;
extern volatile U8_T Uart_buffer[UART_BUFSIZE];

/*********************************************************************** 
 @brief  UART extern functions                  
***********************************************************************/ 
extern void UARTInit(CSP_UART_T *uart,U16_T baudrate_u16,UART_PAR_TypeDef PAR_DAT);
extern void UARTClose(CSP_UART_T *uart);
extern void UARTInitRxIntEn(CSP_UART_T *uart,U16_T baudrate_u16,UART_PAR_TypeDef PAR_DAT);
extern void UARTInitRxTxIntEn(CSP_UART_T *uart,U16_T baudrate_u16,UART_PAR_TypeDef PAR_DAT);
extern void UARTTxByte(CSP_UART_T *uart,U8_T txdata_u8);
extern void UARTTransmit(CSP_UART_T *uart,U8_T *sourceAddress_u16,U16_T length_u16);
extern U16_T UARTRxByte(CSP_UART_T *uart,U8_T *Rxdata_u16);
extern U8_T UART_ReturnRxByte(CSP_UART_T *uart);
extern U16_T UARTReceive(CSP_UART_T *uart,U8_T *destAddress_u16,U16_T length_u16);	
extern void UART0_DeInit(void);
extern void UART1_DeInit(void);
extern void UART2_DeInit(void);
extern void UART_IO_Init(UART_NUM_TypeDef IO_UART_NUM , U8_T UART_IO_G);
extern void UART0_Int_Enable(void);
extern void UART1_Int_Enable(void);
extern void UART2_Int_Enable(void);
extern void UART0_Int_Disable(void);
extern void UART1_Int_Disable(void);
extern void UART2_Int_Disable(void);
extern void UART0_WakeUp_Enable(void);
extern void UART1_WakeUp_Enable(void);
extern void UART2_WakeUp_Enable(void);
extern void UART0_WakeUp_Disable(void);
extern void UART1_WakeUp_Disable(void);
extern void UART2_WakeUp_Disable(void);
extern void UART0_CONFIG(void);
extern void UART1_CONFIG(void);
extern void UART2_CONFIG(void);
extern void UARTTTransmit_data_set(CSP_UART_T *uart );
extern void UARTTransmit_INT_Send(CSP_UART_T *uart );
extern void UART_DMA_Control(CSP_UART_T *uart , U8_T UART_Tx_Rx_CMD , UART_TX_DMA_SEL_TypeDef UART_TX_FL_X , UART_RX_DMA_SEL_TypeDef UART_RX_FL_X);
#endif		// apt32f110_types_local_H */

/*********************************************************************** 
//				(C) COPYRIGHT 2022 APT Chip 
//						 END OF FILE         
***********************************************************************/