/*
  ******************************************************************************
  * @file    apt32f110_wwdt.h
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2022/12/11
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
 
#ifndef _apt32f110_wwdt_H
#define _apt32f110_wwdt_H

/****************************************************
//include
*****************************************************/ 
#include "apt32f110x.h"

#define WWDT_RESET_VALUE  (0x00000000)
#define WWDT_EVI 0X01
/***********************************************************************
 @brief PSC DIV register
***********************************************************************/ 
typedef enum
{
    PCLK_4096_DIV0 = (0<<8),
	PCLK_4096_DIV2 = (1<<8),
	PCLK_4096_DIV4 = (2<<8),
	PCLK_4096_DIV8 = (3<<8),
}WWDT_PSCDIV_TypeDef;
/***********************************************************************
 @brief  WWDT DEBUG MODE register
***********************************************************************/ 
typedef enum
{
    WWDT_DBGDIS = (0<<10),
	WWDT_DBGEN = (1<<10),
}WWDT_DBGEN_TypeDef;


/*********************************************************************** 
 @brief  WWDT extern functions                  
***********************************************************************/ 
extern void WWDT_DeInit(void);
extern void WWDT_CONFIG(WWDT_PSCDIV_TypeDef PSCDIVX,U8_T WND_DATA,WWDT_DBGEN_TypeDef DBGENX);
extern void WWDT_CMD(FunctionalStatus NewState);
extern void WWDT_CNT_Load(U8_T cnt_data);
extern void WWDT_Int_Config(FunctionalStatus NewState);

#endif   // apt32f110_wwdt_H

/*********************************************************************** 
//				(C) COPYRIGHT 2022 APT Chip 
//						 END OF FILE         
***********************************************************************/