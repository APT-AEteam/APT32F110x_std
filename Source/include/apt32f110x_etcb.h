/*
  ******************************************************************************
  * @file    apt32f110_et.h
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2022/02/01
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
 

#ifndef _apt32f110_et_H
#define _apt32f110_et_H

/****************************************************
//include
*****************************************************/ 
#include "apt32f110x.h"


#define ET_RESET_VALUE  (0x00000000)
/*********************************************************************** 
 @brief  ET SWTRG register              
***********************************************************************/ 
typedef enum
{
    ET_SWTRG_CH0 = 1,
	ET_SWTRG_CH1 = (1<<1),
	ET_SWTRG_CH2 = (1<<2),
	ET_SWTRG_CH3 = (1<<3),
	ET_SWTRG_CH4 = (1<<4),
	ET_SWTRG_CH5 = (1<<5),
	ET_SWTRG_CH6 = (1<<6),
	ET_SWTRG_CH7 = (1<<7),
	ET_SWTRG_CH8 = (1<<8),
	ET_SWTRG_CH9 = (1<<9),
	ET_SWTRG_CH10 = (1<<10),
	ET_SWTRG_CH11 = (1<<11)
}CRC_ETSWTRG_TypeDef;
/*********************************************************************** 
 @brief  ET ESRC SEL              
***********************************************************************/
typedef enum
{
    ET_SRC0 = 0,
	ET_SRC1 = 1,
	ET_SRC2 = 2,
}CRC_ESRCSEL_TypeDef;
/*********************************************************************** 
 @brief  ET DST SEL           
***********************************************************************/
typedef enum
{
    ET_DST0 = 0,
	ET_DST1 = 1,
	ET_DST2 = 2,
}CRC_DSTSEL_TypeDef;
/*********************************************************************** 
 @brief  ET ETCHX SEL           
***********************************************************************/
typedef enum
{
    ET_CH3 = 0,
	ET_CH4 = 1,
	ET_CH5 = 2,
	ET_CH6 = 3,
	ET_CH7 = 4,
	ET_CH8 = 5,
	ET_CH9 = 6,
	ET_CH10 = 7,
	ET_CH11 = 8
}CRC_ETCHX_TypeDef;
/*********************************************************************** 
 @brief  ET TRIG MODE register        
***********************************************************************/
typedef enum
{
    TRG_HW = (0X00<<1),
	TRG_SW = (0X01<<1),
}CRC_TRIGMODE_TypeDef;
/*********************************************************************** 
 @brief  ET DMA DIS/EN        
***********************************************************************/
typedef enum
{
	DMA_DIS = (0X00<<2),
	DMA_EN = (0X01<<2)
}DMA_CMD_TypeDef;
/*********************************************************************** 
 @brief  Source IP Event       
***********************************************************************/
#define ET_LPT_SYNC   (0X0)
#define ET_EXI_SYNC0  (0X4)
#define ET_EXI_SYNC1  (0X5)
#define ET_EXI_SYNC2  (0X6)
#define ET_EXI_SYNC3  (0X7)
#define ET_RTC_SYNC0  (0X8)
#define ET_RTC_SYNC1  (0X9)
#define ET_BT0_SYNC0  (0XA)
#define ET_BT1_SYNC0  (0XB)
#define EPT0_TRGOUT0  (0XE)
#define EPT0_TRGOUT1  (0XF)
#define EPT0_TRGOUT2  (0X10)
#define EPT0_TRGOUT3  (0X11)
#define EXI_TRGOUT4   (0X13)
#define EXI_TRGOUT5   (0X14)
#define ADC_TRGOUT0   (0X15)
#define ADC_TRGOUT1   (0X16)
#define CMP0_TRGOUT   (0X18)
#define CMP1_TRGOUT   (0X19)
#define GPTA0_TRGOUT0 (0X1E)
#define GPTA0_TRGOUT1 (0X1F)
#define GPTA1_TRGOUT0 (0X20)
#define GPTA1_TRGOUT1 (0X21)
#define GPTB0_TRGOUT0 (0X26)
#define GPTB0_TRGOUT1 (0X27)
#define GPTB1_TRGOUT0 (0X28)
#define GPTB1_TRGOUT1 (0X29)
#define TKEY_TRGOUT	  (0X2C)
#define I2C_TXSRC     (0x30)
#define I2C_RXSRC     (0x31)	
#define SPI0_TXSRC    (0X34)
#define SPI0_RXSRC    (0X35)
#define UART0_TXSRC   (0X38)
#define UART0_RXSRC	  (0X39)
#define UART1_TXSRC   (0X3A)
#define UART1_RXSRC	  (0X3B)
#define UART2_TXSRC   (0X3C)
#define UART2_RXSRC	  (0X3D)
#define UART2_TXSRC   (0X3C)
#define USART0_TXSRC  (0X3E)
#define USART0_RXSRC  (0X3F)
/*********************************************************************** 
 @brief  Destination IP Event  
***********************************************************************/
#define ET_LPT_SYCIN0     (0X0)
#define ET_BT0_SYNCIN0    (0X2)
#define ET_BT0_SYNCIN1    (0X3)
#define ET_BT0_SYNCIN2    (0X4)
#define ET_BT1_SYNCIN0    (0X5)
#define ET_ADC_SYNCIN0    (0X6)
#define ET_ADC_SYNCIN1    (0X7)
#define ET_ADC_SYNCIN2    (0X8)
#define ET_ADC_SYNCIN3    (0X9)
#define ET_ADC_SYNCIN4    (0XA)
#define ET_ADC_SYNCIN5    (0XB)
#define ET_BT1_SYNCIN1    (0XC)
#define ET_BT1_SYNCIN2    (0XD)
#define ET_CMP0_SYNCIN    (0XE)
#define ET_CMP1_SYSCIN    (0XF)
#define ET_EPT0_SYNCIN0   (0X10)
#define ET_EPT0_SYNCIN1   (0X11)
#define ET_EPT0_SYNCIN2   (0X12)
#define ET_EPT0_SYNCIN3   (0X13)
#define ET_EPT0_SYNCIN4   (0X14)
#define ET_EPT0_SYNCIN5   (0X15)
#define ET_GPTA0_SYNCIN0  (0X18)
#define ET_GPTA0_SYNCIN1  (0X19)
#define ET_GPTA0_SYNCIN2  (0X1A)
#define ET_GPTA0_SYNCIN3  (0X1B)
#define ET_GPTA0_SYNCIN4  (0X1C)
#define ET_GPTA0_SYNCIN5  (0X1D)
#define ET_GPTA1_SYNCIN0  (0X20)
#define ET_GPTA1_SYNCIN1  (0X21)
#define ET_GPTA1_SYNCIN2  (0X22)
#define ET_GPTA1_SYNCIN3  (0X23)
#define ET_GPTA1_SYNCIN4  (0X24)
#define ET_GPTA1_SYNCIN5  (0X25)
#define ET_GPTB0_SYNCIN0  (0X28)
#define ET_GPTB0_SYNCIN1  (0X29)
#define ET_GPTB0_SYNCIN2  (0X2A)
#define ET_GPTB0_SYNCIN3  (0X2B)
#define ET_GPTB0_SYNCIN4  (0X2C)
#define ET_GPTB0_SYNCIN5  (0X2D)
#define ET_GPTB1_SYNCIN0  (0X30)
#define ET_GPTB1_SYNCIN1  (0X31)
#define ET_GPTB1_SYNCIN2  (0X32)
#define ET_GPTB1_SYNCIN3  (0X33)
#define ET_GPTB1_SYNCIN4  (0X34)
#define ET_GPTB1_SYNCIN5  (0X35)
#define TKEY_SYNIN  (0X39)
#define DMA_CH0  	(0X3C)
#define DMA_CH1  	(0X3D)
#define DMA_CH2  	(0X3E)
#define DMA_CH3  	(0X3F)
/*********************************************************************** 
 @brief  ET extern functions                  
***********************************************************************/ 
extern void ETCB_DeInit(void);
extern void ETCB_ENABLE(void);
extern void ETCB_DISABLE(void);
extern void ETCB_SWTRG_CMD(CRC_ETSWTRG_TypeDef ETSWTRG_X,FunctionalStatus NewState);
extern void ETCB_CH0_SRCSEL(CRC_ESRCSEL_TypeDef ESRCSEL_X,FunctionalStatus NewState,U8_T SRCSEL_X);
extern void ETCB_CH0_CONTROL(FunctionalStatus NewState,CRC_TRIGMODE_TypeDef TRIGMODEX,U8_T DSTSEL_X);
extern void ETCB_CH1_SRCSEL(FunctionalStatus NewState,CRC_TRIGMODE_TypeDef TRIGMODEX,U8_T SRCSEL_X);
extern void ETCB_CH1_CONTROL(CRC_DSTSEL_TypeDef DST_X,FunctionalStatus NewState,U8_T DSTSEL_X);
extern void ETCB_CH2_SRCSEL(FunctionalStatus NewState,CRC_TRIGMODE_TypeDef TRIGMODEX,U8_T SRCSEL_X);
extern void ETCB_CH2_CONTROL(CRC_DSTSEL_TypeDef DST_X,FunctionalStatus NewState,U8_T DSTSEL_X);
extern void ETCB_CH3_SRCSEL(FunctionalStatus NewState,CRC_TRIGMODE_TypeDef TRIGMODEX,U8_T SRCSEL_X);
extern void ETCB_CH3_CONTROL(CRC_DSTSEL_TypeDef DST_X,FunctionalStatus NewState,U8_T DSTSEL_X);
extern void ETCB_CHx_CONTROL(CRC_ETCHX_TypeDef ETCHX,FunctionalStatus NewState,DMA_CMD_TypeDef DMA_CMD,CRC_TRIGMODE_TypeDef TRIGMODEX,U8_T SRCSEL_X,U8_T DSTSEL_X);



#endif   // apt32f110_crc_H */

/*********************************************************************** 
//				(C) COPYRIGHT 2022 APT Chip 
//						 END OF FILE         
***********************************************************************/