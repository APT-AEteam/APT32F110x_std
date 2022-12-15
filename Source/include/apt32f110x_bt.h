/*
  ******************************************************************************
  * @file    apt32f110_bt.h
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2022/02/21
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
  
#ifndef APT32F110X_BT_H
#define APT32F110X_BT_H

/****************************************************
//include
*****************************************************/ 
#include "apt32f110x.h"

#define BT_RESET_VALUE  (0x00000000)

/*********************************************************************** 
@brief @brief  bt pin number                                      
***********************************************************************/ 
typedef enum
{
  BT0_PA1_9    = 0,  	// Pin 0 selected */
  BT1_PC0_0	   = 1,
  BT1_PA0_2    = 2,
  BT1_PA0_5    = 3, 
  BT1_PA0_9    = 4,
  BT1_PA1_10   = 5
}BT_Pin_TypeDef;
/*********************************************************************** 
@brief BT CLK EN register                                     
***********************************************************************/ 
typedef enum
{
    BTCLK_DIS = 0,
	BTCLK_EN = 1,
}BT_CLK_TypeDef;
/*********************************************************************** 
@brief BT START SHADOW register                                 
***********************************************************************/ 
typedef enum
{
    BT_SHADOW = (0<<3),
	BT_IMMEDIATE= (1<<3),
}BT_SHDWSTP_TypeDef;
/*********************************************************************** 
@brief BT OPM register                                 
***********************************************************************/ 
typedef enum
{
    BT_CONTINUOUS= (0<<4),         
	BT_ONCE= (1<<4),	
}BT_OPM_TypeDef;
/*********************************************************************** 
@brief BT EXTCKM register                             
***********************************************************************/ 
typedef enum
{
    BT_PCLKDIV= (0<<5),         
	BT_EXTCKM= (1<<5),	
}BT_EXTCKM_TypeDef;
/*********************************************************************** 
@brief BT IDLEST register                         
***********************************************************************/ 
typedef enum
{
    BT_IDLE_LOW= (0<<6),         
	BT_IDLE_HIGH= (1<<6),	
}BT_IDLEST_TypeDef;
/*********************************************************************** 
@brief BT STARTST register                        
***********************************************************************/
typedef enum
{
    BT_START_LOW= (0<<7),         
	BT_START_HIGH= (1<<7),	
}BT_STARTST_TypeDef;
/*********************************************************************** 
@brief BT STARTST register                  
***********************************************************************/
typedef enum
{
    BT_SYNC_DIS= (0<<8),         
	BT_SYNC_EN= (1<<8),	
}BT_SYNCEN_TypeDef;
/*********************************************************************** 
@brief BT OSTMDX register                
***********************************************************************/
typedef enum
{
    BT_OSTMDX_CONTINUOUS= (0<<24),  	       
	BT_OSTMDX_ONCE= (1<<24),	
}BT_OSTMDX_TypeDef;
/*********************************************************************** 
@brief BT SYN Channel Num              
***********************************************************************/
typedef enum
{
	BT_SYN_Channel0	=	0,
	BT_SYN_Channel1 =   1,
	BT_SYN_Channel2 =   2
}BT_SYNCEN_Channel_TypeDef;
/*********************************************************************** 
@brief BT AREARM register          
***********************************************************************/
typedef enum
{
    BT_AREARM_DIS= (0<<14),  	       
	BT_AREARM_EN= (1<<14),	
}BT_AREARM_TypeDef;
/*********************************************************************** 
@brief BT SYNCMD register     
***********************************************************************/
typedef enum
{
    BT_SYNCMD_DIS= (0<<15),  	       
	BT_SYNCMD_EN= (1<<15),	
}BT_SYNCMD_TypeDef;
/*********************************************************************** 
@brief BT CNTRLD register    
***********************************************************************/
typedef enum
{
    BT_CNTRLD_EN= (0<<16),  	       
	BT_CNTRLD_DIS= (1<<16),	
}BT_CNTRLD_TypeDef;
/*********************************************************************** 
@brief BT CNTRLD register
***********************************************************************/
typedef enum
{
    BT_TRGSRC_DIS= (0<<0),  	       
	BT_TRGSRC_PEND= (1<<0),	
	BT_TRGSRC_CMP= (2<<0),	
	BT_TRGSRC_OVF= (3<<0),	
}BT_TRGSRC_TypeDef;
/*********************************************************************** 
@brief  BT CNTRLD register
***********************************************************************/
typedef enum
{
    BT_TRGOE_DIS= (0<<20),  	       
	BT_TRGOE_EN= (1<<20),	
}BT_TRGOE_TypeDef;
/*********************************************************************** 
@brief  BT INT MASK SET/CLR  Set
***********************************************************************/
typedef enum
{
	BT_PEND    	=	(0x01 << 0), 
	BT_CMP    	=	(0x01 << 1),     
	BT_OVF     	=	(0x01 << 2),  
	BT_EVTRG    =	(0x01 << 3), 
}BT_IMSCR_TypeDef;  

/*********************************************************************** 
 @brief  BT extern functions                  
***********************************************************************/ 
extern void BT_DeInit(CSP_BT_T *BTx);
extern void BT_IO_Init(BT_Pin_TypeDef BT_IONAME);
extern void BT_Start(CSP_BT_T *BTx);
extern void BT_Stop(CSP_BT_T *BTx);
extern void BT_Soft_Reset(CSP_BT_T *BTx);
extern void BT_Configure(CSP_BT_T *BTx,BT_CLK_TypeDef BTCLK,U16_T PSCR_DATA,BT_SHDWSTP_TypeDef BTSHDWSTP,BT_OPM_TypeDef BTOPM,BT_EXTCKM_TypeDef BTEXTCKM);
extern void BT_ControlSet_Configure(CSP_BT_T *BTx,BT_STARTST_TypeDef BTSTART,BT_IDLEST_TypeDef BTIDLE,BT_CNTRLD_TypeDef BTCNTRLD);
extern void BT_SYN_Control_Config(CSP_BT_T *BTx, BT_SYNCEN_Channel_TypeDef BT_SYNCEN_Channel_x, BT_SYNCEN_TypeDef BTSYNC, BT_OSTMDX_TypeDef BTOSTMD
			,BT_SYNCMD_TypeDef BTSYNCMD, BT_AREARM_TypeDef BTAREARM);
extern void BT_Period_CMP_Write(CSP_BT_T *BTx,U16_T BTPRDR_DATA,U16_T BTCMP_DATA);
extern void BT_CNT_Write(CSP_BT_T *BTx,U16_T BTCNT_DATA);
extern U16_T BT_PRDR_Read(CSP_BT_T *BTx);
extern U16_T BT_CMP_Read(CSP_BT_T *BTx);
extern U16_T BT_CNT_Read(CSP_BT_T *BTx);
extern void BT_Trigger_Configure(CSP_BT_T *BTx,BT_TRGSRC_TypeDef BTTRG,BT_TRGOE_TypeDef BTTRGOE);
extern void BT_Soft_Tigger(CSP_BT_T *BTx);
extern void BT_ConfigInterrupt_CMD(CSP_BT_T *BTx,FunctionalStatus NewState,BT_IMSCR_TypeDef BT_IMSCR_X);
extern void BT0_INT_ENABLE(void);
extern void BT0_INT_DISABLE(void);
extern void BT1_INT_ENABLE(void);
extern void BT1_INT_DISABLE(void);
extern void BT_Stop_High(CSP_BT_T *BTx);
extern void BT_Stop_Low(CSP_BT_T *BTx);


#endif   // apt32f110_bt_H */

/*********************************************************************** 
//				(C) COPYRIGHT 2022 APT Chip 
//						 END OF FILE         
***********************************************************************/