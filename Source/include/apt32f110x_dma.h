/*
  ******************************************************************************
  * @file    apt32f110_dma.h
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2022/03/10
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
  

#ifndef _apt32f110_dma_H
#define _apt32f110_dma_H

/****************************************************
//include
*****************************************************/ 
#include "apt32f110x.h"

/*********************************************************************** 
 @brief  DMA define               
***********************************************************************/
#define DMA3_TCIT		(0X01<<19)
#define DMA2_TCIT		(0X01<<18)
#define DMA1_TCIT		(0X01<<17)
#define DMA0_TCIT		(0X01<<16)
#define DMA3_LTCIT		(0X01<<3)
#define DMA2_LTCIT		(0X01<<2)
#define DMA1_LTCIT		(0X01<<1)
#define DMA0_LTCIT		(0X01<<0)
/*********************************************************************** 
 @brief  DMA INT  Set               
***********************************************************************/ 
typedef enum
{
	DMA_TCIT     	=	(0x01 << 30),  
	DMA_LTCIT    	=	(0x01 << 29)
}DMA_INT_TypeDef;  
/*********************************************************************** 
 @brief  DMA Triggle mode Set               
***********************************************************************/ 
typedef enum
{
	DMA_Triggle_SWTRIG = 0,
	DMA_Triggle_HWTRIG = 1
}DMA_Triggle_mode_TypeDef;
/*********************************************************************** 
 @brief  DMA HINC Cmd              
***********************************************************************/
typedef enum
{
	DMA_HINC_EN		=	(0X00<<1),
	DMA_HINC_DIS	=	(0X01<<1)
}DMA_HINC_Cmd_TypeDef;
/*********************************************************************** 
 @brief  DMA LINC Cmd              
***********************************************************************/
typedef enum
{
	DMA_LINC_EN		=	(0X00),
	DMA_LINC_DIS	=	0X01
}DMA_LINC_Cmd_TypeDef;
/*********************************************************************** 
 @brief  DMA send D size              
***********************************************************************/
typedef enum
{
	DMA_Send_DSize_Byte 			=	(0x0<<24),		//8
	DMA_Send_DSize_Half_Word 	=	(0x1<<24),		//16
	DMA_Send_DSize_Word 			=	(0x2<<24)		//32
}DMA_Send_DSize_TypeDef;
/*********************************************************************** 
 @brief  DMA send T size             
***********************************************************************/
typedef enum
{
	DMA_Send_TSize_1DSIZE 			=	(0x0<<28),		//每次传DSIZE*1
	DMA_Send_TSize_4DSIZE 			=	(0x1<<28)		//每次传DSIZE*4
}DMA_Send_TSize_TypeDef;
/*********************************************************************** 
 @brief  DMA Reload Config            
***********************************************************************/
typedef enum
{
	DMA_Reload_EN		=	(0X0<<26),
	DMA_Reload_DIS		=	(0X1<<26)
}DMA_Reload_TypeDef;
/*********************************************************************** 
 @brief  DMA send mode           
***********************************************************************/
typedef enum
{
	DMA_SendMode_Once	 	=	(0X0<<27),
	DMA_SendMode_Contine	=	(0X1<<27)
}DMA_SendMode_TypeDef;

/*********************************************************************** 
 @brief  DMA extern functions                  
***********************************************************************/ 
extern void DMA_RESET(void);
extern void DMA_Channel_CMD(U8_T DMA_CESR);
extern void DMA_ConfigInterrupt_CMD(CSP_DMA_T *DMAX , FunctionalStatus NewState , DMA_INT_TypeDef DMA_INT_X);
extern void DMA_Trig_Mode(CSP_DMA_T *DMAX , DMA_Triggle_mode_TypeDef DMA_Triggle_mode);
extern void DMA_SWTRIG_Start(CSP_DMA_T *DMAX );
extern void DMA_HWTRIG_Start(CSP_DMA_T *DMAX );
extern void DMA_Stop(CSP_DMA_T *DMAX );
extern void DMA_CR_Config(CSP_DMA_T *DMAX , U16_T DAM_LTC , U16_T DAM_HTC , DMA_Send_TSize_TypeDef DMA_Send_TSize , DMA_Send_DSize_TypeDef DMA_Send_DSize ,
					DMA_Reload_TypeDef DMA_Reload_CMD , DMA_SendMode_TypeDef DMA_SendMode);
extern void DMA_Int_Enable(void);
extern void DMA_Int_Disable(void);

#endif   // apt32f110_dma_H */

/*********************************************************************** 
//				(C) COPYRIGHT 2022 APT Chip 
//						 END OF FILE         
***********************************************************************/