/*
  ******************************************************************************
  * @file    apt32f110_cmp.h
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2022/03/03
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

#ifndef _apt32f110_cmp_H
#define _apt32f110_cmp_H

/****************************************************
//include
*****************************************************/ 
#include "apt32f110x.h"

/*********************************************************************** 
 @brief  CMP IO mode                
***********************************************************************/ 
typedef enum
{  
	CPIN0	=	0,
	CPIN1	=	1,
	CPIN2	=	2,
	CPIN3	=	3,
	CPIN4	=	4,
	CPIN5	=	5,
	CPIN6	=	6,
	CPIN7	=	7
}CMP_IO_MODE_TypeDef;
/*********************************************************************** 
 @brief  CMP IO Set               
***********************************************************************/ 
typedef enum
{
	CMPIN0_PA0_0	=	1,
	CMPIN1_PA1_10	=	2,
	CMPIN2_PA0_3	=	3,
	CMPIN3_PA0_4	=	4,
	CMPIN4_PB0_0	=	5,
	CMPIN5_PB0_1	=	6,
	CMPIN6_PB0_2	=	7,
	CMPIN7_PC0_0	=	8,
	CMP1OUT_PA0_8	=	9,
	CMP1OUT_PB0_5	=	10,
	CMP0OUT_PA1_6	=	11,
	CMP0OUT_PA1_11	=	12
}CMP_IOSET_TypeDef;
/*********************************************************************** 
 @brief  CMP INT set               
***********************************************************************/ 
typedef enum
{
	EDGEDET		=		1,
	RAWDET		=		1<<16,
	MISR_EDGEDET0	= 1,
	MISR_EDGEDET1	= 1<<1,
	MISR_RAWDET0	= 1<<16,
	MISR_RAWDET1	= 1<<17

}CMP_INT_TypeDef;
/*********************************************************************** 
 @brief  CMPX CR config            
***********************************************************************/ 
typedef enum
{
	DISCMPEN			=	((CSP_REGISTER_T)0X00),
	ENCMPEN				=	((CSP_REGISTER_T)0X01)
}CMPx_CMPEN_TypeDef;	
/*********************************************************************** 
 @brief  CMPX HYST config            
***********************************************************************/
typedef enum
{	
	HYST_0mv			=	((CSP_REGISTER_T)0X00<<1),
	HYST_5mv			=	((CSP_REGISTER_T)0X01<<1),
	HYST_10mv			=	((CSP_REGISTER_T)0X02<<1),
	HYST_15mv			=	((CSP_REGISTER_T)0X03<<1),
	HYST_20mv			=	((CSP_REGISTER_T)0X04<<1),
	HYST_25mv			=	((CSP_REGISTER_T)0X05<<1),
	HYST_40mv			=	((CSP_REGISTER_T)0X06<<1),
	HYST_60mv			=	((CSP_REGISTER_T)0X07<<1)
}CMPx_HYST_TypeDef;
/*********************************************************************** 
 @brief  CMPX HYSTSEL config            
***********************************************************************/
typedef enum
{
	CMP_HYSTSEL_DIS			=	0X00<<4,
	CMP_HYSTSEL_P_EN		=	0X01<<4,
	CMP_HYSTSEL_N_EN		=	0X02<<4,
	CMP_HYSTSEL_P_N_EN		=	0X03<<4
}CMPx_HYSTSEL_TypeDef;
/*********************************************************************** 
 @brief  CMPX POLARITY config            
***********************************************************************/
typedef enum
{
	POLARITY_0			=	((CSP_REGISTER_T)0X00<<6),
	POLARITY_1			=	((CSP_REGISTER_T)0X01<<6),
}CMPx_POLARITY_TypeDef;
/*********************************************************************** 
 @brief  CMPX EVET config            
***********************************************************************/
typedef enum
{
	EVET_SEL_fall		=	((CSP_REGISTER_T)0X00<<8),
	EVET_SEL_rise		=	((CSP_REGISTER_T)0X01<<8),
	EVET_SEL_fall_rise	=	((CSP_REGISTER_T)0X02<<8),	//低功耗下配置次选项只有下降沿起作用
}CMPx_EVE_SEL_TypeDef;
/*********************************************************************** 
 @brief  CMPX FLTEN1 config            
***********************************************************************/
typedef enum
{
	DIS_FLTEN1			=	((CSP_REGISTER_T)0X00<<10),
	EN_FLTEN1			=	((CSP_REGISTER_T)0X01<<10),
}CMPx_FLTEN1_TypeDef;
/*********************************************************************** 
 @brief  CMPX FLTEN2 config            
***********************************************************************/
typedef enum
{
	DIS_FLTEN2			=	((CSP_REGISTER_T)0X00<<11),
	EN_FLTEN2			=	((CSP_REGISTER_T)0X01<<11),
}CMPx_FLTEN2_TypeDef;
/*********************************************************************** 
 @brief  CMPX CPOS config            
***********************************************************************/
typedef enum
{
	CPOS_0				=	((CSP_REGISTER_T)0X00<<23),
	CPOS_1				=	((CSP_REGISTER_T)0X01<<23)
}CMPx_CPOS_TypeDef;
/*********************************************************************** 
 @brief  CMPX DEPTH1 config            
***********************************************************************/
typedef enum
{
	CMP_DEPTH1_8	=	0,
	CMP_DEPTH1_16	=	1,
	CMP_DEPTH1_32	=	2,
	CMP_DEPTH1_64	=	3,
	CMP_DEPTH1_128	=	4,
	CMP_DEPTH1_256	=	5,
	CMP_DEPTH1_512	=	6,
	CMP_DEPTH1_1024	=	7
}CMP_DEPTH1_TypeDef;
/*********************************************************************** 
 @brief  CMPX DEPTH2 config            
***********************************************************************/
typedef enum
{
	CMP_DEPTH2_16	=	0,
	CMP_DEPTH2_32	=	1,
	CMP_DEPTH2_64	=	2,
	CMP_DEPTH2_128	=	3,
	CMP_DEPTH2_256	=	4,
	CMP_DEPTH2_512	=	5,
	CMP_DEPTH2_1024	=	6,
	CMP_DEPTH2_2048	=	7
}CMP_DEPTH2_TypeDef;
/*********************************************************************** 
 @brief  CMPX CLKDIV config            
***********************************************************************/
 typedef enum
{
	CMPX_CLKDIV_1			=		((CSP_REGISTER_T)0X00<<10),
	CMPX_CLKDIV_2			=		((CSP_REGISTER_T)0X01<<10),
	CMPX_CLKDIV_3			=		((CSP_REGISTER_T)0X02<<10),
	CMPX_CLKDIV_4			=		((CSP_REGISTER_T)0X03<<10),
	CMPX_CLKDIV_5			=		((CSP_REGISTER_T)0X04<<10),
	CMPX_CLKDIV_6			=		((CSP_REGISTER_T)0X05<<10),
	CMPX_CLKDIV_7			=		((CSP_REGISTER_T)0X06<<10),
	CMPX_CLKDIV_8			=		((CSP_REGISTER_T)0X07<<10),
	CMPX_CLKDIV_9			=		((CSP_REGISTER_T)0X08<<10),
	CMPX_CLKDIV_10			=		((CSP_REGISTER_T)0X09<<10),
	CMPX_CLKDIV_11			=		((CSP_REGISTER_T)0X0A<<10),
	CMPX_CLKDIV_12			=		((CSP_REGISTER_T)0X0B<<10),
	CMPX_CLKDIV_13			=		((CSP_REGISTER_T)0X0C<<10),
	CMPX_CLKDIV_14			=		((CSP_REGISTER_T)0X0D<<10),
	CMPX_CLKDIV_15			=		((CSP_REGISTER_T)0X0E<<10),
	CMPX_CLKDIV_16			=		((CSP_REGISTER_T)0X0F<<10),
	CMPX_CLKDIV_24			=		((CSP_REGISTER_T)0X10<<10),
	CMPX_CLKDIV_32			=		((CSP_REGISTER_T)0X11<<10),
	CMPX_CLKDIV_40			=		((CSP_REGISTER_T)0X12<<10),
	CMPX_CLKDIV_48			=		((CSP_REGISTER_T)0X13<<10),
	CMPX_CLKDIV_56			=		((CSP_REGISTER_T)0X14<<10),
	CMPX_CLKDIV_64			=		((CSP_REGISTER_T)0X15<<10),
	CMPX_CLKDIV_72			=		((CSP_REGISTER_T)0X16<<10),
	CMPX_CLKDIV_128			=		((CSP_REGISTER_T)0X17<<10),
	CMPX_CLKDIV_144			=		((CSP_REGISTER_T)0X18<<10),
	CMPX_CLKDIV_160			=		((CSP_REGISTER_T)0X19<<10),
	CMPX_CLKDIV_176			=		((CSP_REGISTER_T)0X1A<<10),
	CMPX_CLKDIV_192			=		((CSP_REGISTER_T)0X1B<<10),
	CMPX_CLKDIV_208			=		((CSP_REGISTER_T)0X1C<<10),
	CMPX_CLKDIV_224			=		((CSP_REGISTER_T)0X1D<<10),
	CMPX_CLKDIV_240			=		((CSP_REGISTER_T)0X1E<<10),
	CMPX_CLKDIV_256			=		((CSP_REGISTER_T)0X1F<<10),
	CMPX_CLKDIV_288			=		((CSP_REGISTER_T)0X20<<10),
	CMPX_CLKDIV_320			=		((CSP_REGISTER_T)0X21<<10),
	CMPX_CLKDIV_352			=		((CSP_REGISTER_T)0X22<<10),
	CMPX_CLKDIV_384			=		((CSP_REGISTER_T)0X23<<10),
	CMPX_CLKDIV_416			=		((CSP_REGISTER_T)0X24<<10),
	CMPX_CLKDIV_448			=		((CSP_REGISTER_T)0X25<<10),
	CMPX_CLKDIV_480			=		((CSP_REGISTER_T)0X26<<10),
	CMPX_CLKDIV_512			=		((CSP_REGISTER_T)0X27<<10),
	CMPX_CLKDIV_640			=		((CSP_REGISTER_T)0X28<<10),
	CMPX_CLKDIV_720			=		((CSP_REGISTER_T)0X29<<10),
	CMPX_CLKDIV_1024		=		((CSP_REGISTER_T)0X2A<<10),
	CMPX_CLKDIV_2048		=		((CSP_REGISTER_T)0X2B<<10)
}CMPX_CLKDIV_TypeDef;
/*********************************************************************** 
 @brief  CMPX Wind Out Set        
***********************************************************************/
 typedef enum
{
	CMP_Wind_Out_H		=	1<<14,	//滤波器输出高
	CMP_Wind_Out_L		=	2<<14	//滤波器输出低
}CMP_Wind_Out_Set_TypeDef;
/*********************************************************************** 
 @brief  CMPX WFALIGN CMD        
***********************************************************************/
 typedef enum
{
	CMP_WFALIGN_DIS		=	0X00<<13,//不允许窗口跨周期
	CMP_WFALIGN_EN		=	0X01<<13 //允许窗口跨周期
}CMP_WFALIGN_CMD_TypeDef;


/*********************************************************************** 
 @brief  CMP extern functions                  
***********************************************************************/ 
extern void CMP_software_reset(CSP_CMP_T *CMPX);
extern void CMP_CLK_CMD(CSP_CMP_T *CMPX , FunctionalStatus NewState);
extern void CMP_IO_Init(CMP_IOSET_TypeDef  CMP_IONAME);
extern void CMP_INPCRX_Config(CSP_CMP_T *CMPX , U8_T CMPX_NSEL , U8_T CMPX_PSEL );
extern void CMP_CR_Config(CSP_CMP_T *CMPX , CMPx_HYSTSEL_TypeDef CMPx_HYSTSEL_X , CMPx_HYST_TypeDef HYST_Xmv , CMPx_POLARITY_TypeDef POLARITY_X ,
						 CMPx_EVE_SEL_TypeDef EVE_SEL_X , CMPx_FLTEN1_TypeDef X_FLT1EN , CMPx_FLTEN2_TypeDef X_FLT2EN , CMPx_CPOS_TypeDef CPOS_X 
						, U8_T CMP_TRG_EN);
extern void CMP_Open(CSP_CMP_T *CMPX );
extern void CMP_Close(CSP_CMP_T *CMPX );
extern void CMPX_FLT1CR_Config(CSP_CMP_T *CMPX ,CMP_DEPTH1_TypeDef CMP_DEPTH1_X , U8_T CMP_DIVN , U8_T CMP_DIVM);
extern void CMPX_FLT2CR_Config(CSP_CMP_T *CMPX ,CMP_DEPTH2_TypeDef CMP_DEPTH1_X , U8_T CMP_DIVN , U8_T CMP_DIVM);
extern void CMP_WCNT_Config(CSP_CMP_T *CMPX , FunctionalStatus NewState , CMP_Wind_Out_Set_TypeDef CMP_Wind_Out_X ,
				     CMP_WFALIGN_CMD_TypeDef CMP_WFALIGN_CMD , CMPX_CLKDIV_TypeDef CMPX_CLKDIV_X , U16_T CMP_WCNT , U8_T CMP_DCNT);	
extern void CMP_ConfigInterrupt_CMD(CSP_CMP_T *CMPX , CMP_INT_TypeDef CMP_INT_X , FunctionalStatus NewState);
extern void CMP_Int_Enable(void);
extern void CMP_Int_Disable(void);
extern void CMP_Wakeup_Enable(void);	
extern void CMP_Wakeup_Disable(void);					

#endif   // apt32f110_cmp_H */

/*********************************************************************** 
//				(C) COPYRIGHT 2022 APT Chip 
//						 END OF FILE         
***********************************************************************/

