/*
  ******************************************************************************
  * @file    apt32f110_spi.h
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2020/06/08
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


#ifndef _apt32f110_spi_H
#define _apt32f110_spi_H

/****************************************************
//include
*****************************************************/ 
#include "apt32f110x.h"

/*******************************************************************************
 @brief: Control Register 0
*******************************************************************************/
#define SSP_DSS(val)	(((val-1) & 0x0Ful) << 0)			// Data Size Select
#define SSP_FRF(val)	(((val) & 0x03ul) << 4)				// Frame Format
#define SSP_SPO  	   (0x01ul << 6)						// SSPCLK Polarity
#define SSP_SPH  	    (0x01ul << 7)						// SSPCLK Phase
#define SSP_SCR(val)	(((val) & 0x0FFul) << 8)			// Serial Clock Rate

/*******************************************************************************
 @brief: Control Register 1
*******************************************************************************/
#define SSP_LBM  	    (0x01ul << 0)						// Loopback mode 
#define SSP_SSE  	    (0x01ul << 1)						// Synchronous Serial Port Enable
#define SSP_MS 	 	    (0x01ul << 2)						// Master or Slave Mode Select
#define SSP_SOD  	    (0x01ul << 3)						// Slave Mode Output Disable
#define SSP_RXIFLSELFRF(val)    (((val) & 0x07ul) << 4)		// Receive interrupt FIFO level select */

/*******************************************************************************
 @brief: Data Register
*******************************************************************************/
#define SSP_DATA(val)	(((val) & 0x0FFFF) << 0)			// Transmit/Receive FIFO

/*******************************************************************************
 @brief: Status Register
*******************************************************************************/
#define SSP_TFE  	    (0x01ul << 0)						// Transmit FIFO Empty
#define SSP_TNF  	    (0x01ul << 1)						// Transmit FIFO is not Full
#define SSP_RNE 	 	(0x01ul << 2)						// Receive is not Empty
#define SSP_RFF 	 	(0x01ul << 3)						// Receive FIFO Full
#define SSP_BSY	 	    (0x01ul << 4)						// PrimeCell SSP Busy Flag

/*******************************************************************************
 @brief: Clock prescale register
*******************************************************************************/
#define SSP_CPSDVSR(val) (((val) & 0x0FF) << 0)				// Clock Prescale Devisor

/*******************************************************************************
 @brief: Interrupt mask set and clear register
*******************************************************************************/
#define SSP_RORIM  	(0x01ul << 0)							// Receive Overrun Interrupt Mask
#define SSP_RTIM  	(0x01ul << 1)							// Receive Timeout Interrupt Mask
#define SSP_RXIM 	(0x01ul << 2)							// Receive FIFO Interrupt Mask */
#define SSP_TXIM 	(0x01ul << 3)							// Transmit FIFO interrupt Mask */

/*******************************************************************************
 @brief: Raw interrupt status register
*******************************************************************************/
#define SSP_RORRIS 	(0x01ul << 0)			// Gives the Raw Interrupt Status of the SSPRORINTR Interrupt
#define SSP_RTRIS   (0x01ul << 1)			// Gives the raw interrupt state of the SSPRTINTR interrupt
#define SSP_RXRIS 	(0x01ul << 2)			// Gives the raw interrupt state of the SSPRXINTR interrupt
#define SSP_TXRIS	(0x01ul << 3)			// Gives the raw interrupt state of the SSPTXINTR interrupt

/*******************************************************************************
 @brief: Masked interrupt status register
*******************************************************************************/
#define SSP_RORRIS  (0x01ul << 0)			//Gives the receive over run masked interrupt status of SSPRORINTR interrupt
#define SSP_RTRIS  	(0x01ul << 1)			//Gives the receive timeout masked interrupt state of SSPRTINTR interrupt
#define SSP_RXRIS 	(0x01ul << 2)			//Gives the receive FIFO masked interrupt state of SSPRXINTR interrupt
#define SSP_TXRIS	(0x01ul << 3)			//Gives the transmit FIFO masked interrupt state of SSPTXINTR interrupt

/*******************************************************************************
 @brief: Interrupt clear register
*******************************************************************************/
#define SSP_RORIC 	(0x01ul << 0)			// Clears the SSPRORINTR interrupt
#define SSP_RTIC  	(0x01ul << 1)			// Clears the SSPRTINTR interrupt


/*******************************************************************************
 @briefSSP REGISTER MASK
*******************************************************************************/
#define SSP_CR0_MASK 	(0x0000FFFFul)  	// Control Register 0 mask
#define SSP_CR1_MASK 	(0x0000007Ful)  	// Control Register 1 mask
#define SSP_DR_MASK 	(0x0000FFFFul)		// Receive FIFO(read) and transmit FIFO data register(write) mask
#define SSP_SR_MASK    	(0x0000001Ful)  	// Status register  mask
#define SSP_CPSR_MASK 	(0x000000FFul)  	// Clock prescale register mask
#define SSP_IMSCR_MASK	(0x0000000Ful)		// Interrupt mask set and clear register mask
#define SSP_RISR_MASK 	(0x0000000Ful)  	// Raw interrupt status register mask
#define SSP_MISR_MASK 	(0x0000000Ful)		// Masked interrupt status register mask
#define SSP_ICR_MASK 	(0x00000003ul)  	// Interrupt clear register mask

/*******************************************************************************
 @brief SSP REGISTER RESET VALUE
*******************************************************************************/
#define SSP_CR0_RST 	(0x00000000ul) 		// Control Register 0 reset value
#define SSP_CR1_RST 	(0x00000010ul) 		// Control Register 1 reset value
#define SSP_DR_RST		(0x00000000ul)		// Receive FIFO(read) and transmit FIFO data register(write) reset value
#define SSP_SR_RST		(0x00000003ul)  	// Status register  reset value
#define SSP_CPSR_RST	(0x00000000ul)		// Clock prescale register reset value
#define SSP_IMSCR_RST 	(0x00000000ul)		// Interrupt mask set and clear register reset value
#define SSP_RISR_RST 	(0x00000008ul)		// Raw interrupt status register reset value
#define SSP_MISR_RST 	(0x00000000ul)		// Masked interrupt status register reset value
#define SSP_ICR_RST 	(0x00000000ul)		// Interrupt clear register reset value

/*******************************************************************************
 @brief SPI Registers RST  Value
*******************************************************************************/
#define SPI_CR0_RST          	(0x00000000)    	// CR0 reset value      
#define SPI_CR1_RST          	(0x00000000)    	// CR1 reset value      
#define SPI_DR_RST          	(0x00000000)   	 	// DR reset value       
#define SPI_SR_RST          	(0x00000003)    	// SR reset value       
#define SPI_CPSR_RST          	(0x00000000)    	// CPSR reset value     
#define SPI_IMSCR_RST          	(0x00000000)   	 	// IMSCR reset value  
#define SPI_RISR_RST          	(0x00000008)    	// RISR reset value     
#define SPI_MISR_RST          	(0x00000000)    	// MISR reset value   
#define SPI_ICR_RST          	(0x00000000)    	// ICR reset value     

/*******************************************************************************
 @brief SPI INT MASK SET/CLR  Set
*******************************************************************************/
typedef enum
{
	SPI_PORIM     	=	((CSP_REGISTER_T)(0x01ul << 0)),      // Receive overflow Interrupt     
	SPI_RTIM    	=	((CSP_REGISTER_T)(0x01ul << 1)),      // Receive timeout Interrupt     
	SPI_RXIM    	=	((CSP_REGISTER_T)(0x01ul << 2)),      // Receive FIFO Interrupt     
	SPI_TXIM    	=	((CSP_REGISTER_T)(0x01ul << 3))      // transmit FIFO Interrupt     
}SPI_IMSCR_TypeDef; 

/*******************************************************************************
 @brief SPI IO selection
*******************************************************************************/
typedef enum
{
	SPI_G0 = 0,
    SPI_G1 = 1,
	SPI_G2 = 2
}SPI_IO_TypeDef; 

/*******************************************************************************
 @brief SPI Data Size selection
*******************************************************************************/
typedef enum
{
	SPI_DATA_SIZE_4BIT	=	3,
	SPI_DATA_SIZE_5BIT	=	4,
	SPI_DATA_SIZE_6BIT	=	5,
	SPI_DATA_SIZE_7BIT	=	6,
	SPI_DATA_SIZE_8BIT	=	7,
	SPI_DATA_SIZE_9BIT	=	8,
	SPI_DATA_SIZE_10BIT	=	9,
	SPI_DATA_SIZE_11BIT	=	10,
	SPI_DATA_SIZE_12BIT	=	11,
	SPI_DATA_SIZE_13BIT	=	12,
	SPI_DATA_SIZE_14BIT	=	13,
	SPI_DATA_SIZE_15BIT	=	14,
	SPI_DATA_SIZE_16BIT	=	15
}SPI_DATA_SIZE_TypeDef;

/*******************************************************************************
 @brief SPI SPO selection
*******************************************************************************/
typedef enum
{
	SPI_SPO_0	=	0,
	SPI_SPO_1	=	1
}SPI_SPO_TypeDef;

/*******************************************************************************
 @brief SPI SPH selection
*******************************************************************************/
typedef enum
{
	SPI_SPH_0	=	0,
	SPI_SPH_1	=	1
}SPI_SPH_TypeDef;

/*******************************************************************************
 @brief SPI LBM selection
*******************************************************************************/
typedef enum
{
	SPI_LBM_0	=	0,
	SPI_LBM_1	=	1
}SPI_LBM_TypeDef;

/*******************************************************************************
 @brief SPI RXIFLSEL selection
*******************************************************************************/
typedef enum
{
	SPI_RXIFLSEL_1_8	=	0x01,
	SPI_RXIFLSEL_1_4	=	0x02,
	SPI_RXIFLSEL_1_2	=	0x04
}SPI_RXIFLSEL_TypeDef;

/*******************************************************************************
 @brief SPI TX DMA selection
*******************************************************************************/
typedef enum
{
	SPI_TX_FL_FIFO_NF		=	0X00<<3,			//未满
	SPI_TX_FL_Less_FIFO_1_2	=	0X01<<3				//FIFO数据占用<=1/2
}SPI_TX_DMA_SEL_TypeDef;

/*******************************************************************************
 @brief SPI RX DMA selection
*******************************************************************************/
typedef enum
{
	SPI_RX_FL_FIFO_NE		=	0X00<<2,			//非空
	SPI_RX_FL_FIFO_FLSEL	=	0X01<<2				//FIFO数据达到中断触发点
}SPI_RX_DMA_SEL_TypeDef;
/*********************************************************************** 
 @brief  SPI extern functions                  
***********************************************************************/ 
extern void SPI_DeInit(void);
extern void SPI_NSS_IO_Init(U8_T SPI_NSS_IO_GROUP);
extern void SPI_Master_Init(SPI_IO_TypeDef SPI_IO , SPI_DATA_SIZE_TypeDef SPI_DATA_SIZE_x , SPI_SPO_TypeDef SPI_SPO_X , SPI_SPH_TypeDef SPI_SPH_X , SPI_LBM_TypeDef SPI_LBM_X , SPI_RXIFLSEL_TypeDef SPI_RXIFLSEL_X , U8_T SPI_SCR , U8_T SPI_CPSDVSR );
extern void SPI_Slave_Init(SPI_IO_TypeDef SPI_IO , SPI_DATA_SIZE_TypeDef SPI_DATA_SIZE_x , SPI_SPH_TypeDef SPI_SPH_X , SPI_RXIFLSEL_TypeDef SPI_RXIFLSEL_X , U8_T SPI_SCR , U8_T SPI_CPSDVSR);
extern void SPI_WRITE_BYTE(U16_T wdata);
extern void SPI_READ_BYTE(U16_T wdata , volatile U16_T *rdata , U8_T Longth);
extern void SPI_Reset(void);
extern void SPI_ConfigInterrupt_CMD(FunctionalStatus NewState,SPI_IMSCR_TypeDef SPI_IMSCR_X);
extern void SPI_DMA_Control(U8_T SPI_Tx_Rx_CMD , SPI_TX_DMA_SEL_TypeDef SPI_TX_FL_Less_X , SPI_RX_DMA_SEL_TypeDef SPI_RX_FL_Greater_X);
extern void SPI_Int_Enable(void);
extern void SPI_Int_Disable(void);
extern void SPI_Wakeup_Enable(void);
extern void SPI_Wakeup_Disable(void);

#endif   // apt32f110_spi_H */

/*********************************************************************** 
//				(C) COPYRIGHT 2022 APT Chip 
//						 END OF FILE         
***********************************************************************/