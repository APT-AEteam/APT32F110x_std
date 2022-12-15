/*
  ******************************************************************************
  * @file    apt32f110_gpt.h
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2022/08/05
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
 

#ifndef _apt32f110_gpt_H
#define _apt32f110_gpt_H

/****************************************************
//include
*****************************************************/ 
#include "apt32f110x.h"

/*********************************************************************** 
 @brief  GPT io Mode set               
***********************************************************************/ 
typedef enum
{
	GPT_IO_CHAX			=	 	0,
	GPT_IO_CHAY			=	 	1,
	GPT_IO_CHB			=	 	2,
	GPT_IO_EBI			=	 	7
}GPT_IO_Mode_Type;
/*********************************************************************** 
 @brief  GPT TCLK selected             
***********************************************************************/ 	
typedef enum
{
	GPT_Selecte_PCLK		=	0<<3,
	GPT_Selecte_SYNCUSR3	=	1<<3
}GPT_TCLK_Selecte_Type;
/*********************************************************************** 
 @brief  GPT TIN selected
***********************************************************************/ 
typedef enum
{
	GPT_CGSRC_CHAX		=	2,				
	GPT_CGSRC_CHBX		=	3,
	GPT_CGSRC_DIS		=	4
}GPT_CGSRC_TIN_Selecte_Type;
/*********************************************************************** 
 @brief  GPT BURST CMD
***********************************************************************/ 
typedef enum
{
	GPT_BURST_ENABLE		=	1<<9,
	GPT_BURST_DIABLE		=	0<<9
}GPT_BURST_CMD_Type;
/*********************************************************************** 
 @brief  GPT CNTMD selected
***********************************************************************/ 
typedef enum		
{
	GPT_CNTMD_increase 				=  ((CSP_REGISTER_T)(0x00ul << 0)),
	GPT_CNTMD_decrease  			=  ((CSP_REGISTER_T)(0x01ul << 0)),
	GPT_CNTMD_increaseTOdecrease	=  ((CSP_REGISTER_T)(0x02ul << 0))
}GPT_CNTMD_SELECTE_Type;
/*********************************************************************** 
 @brief  GPT GPT OPM selected
***********************************************************************/ 	
typedef enum		
{
	GPT_OPM_Once 				=  ((CSP_REGISTER_T)(0x01ul << 6)),
	GPT_OPM_Continue  			=  ((CSP_REGISTER_T)(0x00ul << 6))
}GPT_OPM_SELECTE_Type;	
/*********************************************************************** 
 @brief  GPT CAP CMD
***********************************************************************/
typedef enum		
{	
	GPT_CAP_EN			=			((CSP_REGISTER_T)(0x01ul << 8)),	
	GPT_CAP_DIS			=			((CSP_REGISTER_T)(0x00ul << 8))
}GPT_CAPLDEN_CMD_Type;
/*********************************************************************** 
 @brief  GPT CAPMD selected
***********************************************************************/
typedef enum		
{
	GPT_CAPMD_Once 					=  ((CSP_REGISTER_T)(0x01ul << 20)),
	GPT_CAPMD_Continue  			=  ((CSP_REGISTER_T)(0x00ul << 20))
}GPT_CAPMD_SELECTE_Type;

/*********************************************************************** 
 @brief  GPT CMPA RST CMD
***********************************************************************/
typedef enum		
{
	GPT_LDARST_EN 					=  ((CSP_REGISTER_T)(0x00ul << 23)),
	GPT_LDARST_DIS  				=  ((CSP_REGISTER_T)(0x01ul << 23))
}GPT_LOAD_CMPA_RST_CMD_Type;	
/*********************************************************************** 
 @brief  GPT CMPB RST CMD
***********************************************************************/
typedef enum		
{
	GPT_LDBRST_EN 					=  ((CSP_REGISTER_T)(0x00ul << 24)),
	GPT_LDBRST_DIS  				=  ((CSP_REGISTER_T)(0x01ul << 24))
}GPT_LOAD_CMPB_RST_CMD_Type;	
/*********************************************************************** 
 @brief  GPT FLT CMD
***********************************************************************/		
typedef enum		
{
	GPT_FLT_DIS 					=  ((CSP_REGISTER_T)(0x00ul << 10)),
	GPT_FLT_EN  					=  ((CSP_REGISTER_T)(0x01ul << 10))
}GPT_FLT_CMD_Type;
/*********************************************************************** 
 @brief  GPT FLT CGFLT
***********************************************************************/		
typedef enum		
{
	GPT_FLT_Bypass 					=  ((CSP_REGISTER_T)(0x00ul << 13)),
	GPT_FLT_2  						=  ((CSP_REGISTER_T)(0x01ul << 13)),
	GPT_FLT_3  						=  ((CSP_REGISTER_T)(0x02ul << 13)),
	GPT_FLT_4  						=  ((CSP_REGISTER_T)(0x03ul << 13)),
	GPT_FLT_6  						=  ((CSP_REGISTER_T)(0x04ul << 13)),
	GPT_FLT_8  						=  ((CSP_REGISTER_T)(0x05ul << 13)),
	GPT_FLT_16  					=  ((CSP_REGISTER_T)(0x06ul << 13)),
	GPT_FLT_32  					=  ((CSP_REGISTER_T)(0x07ul << 13))
}GPT_FLT_CGFLT_Type;
/*********************************************************************** 
 @brief   GPT Triggle Mode
***********************************************************************/
typedef enum		
{
	GPT_Triggle_Continue 					=  ((CSP_REGISTER_T)(0x00ul << 8)),
	GPT_Triggle_Once  						=  ((CSP_REGISTER_T)(0x01ul << 8))
}GPT_Triggle_Mode_Type;
/*********************************************************************** 
 @brief   GPT Rearm select
***********************************************************************/
typedef enum		
{
	GPT_REARM_SYNCEN0 					=  ((CSP_REGISTER_T)(0x01ul << 16)),
	GPT_REARM_SYNCEN1 					=  ((CSP_REGISTER_T)(0x02ul << 16)),
	GPT_REARM_SYNCEN2 					=  ((CSP_REGISTER_T)(0x04ul << 16)),
	GPT_REARM_SYNCEN3 					=  ((CSP_REGISTER_T)(0x08ul << 16)),
	GPT_REARM_SYNCEN4 					=  ((CSP_REGISTER_T)(0x10ul << 16)),
	GPT_REARM_SYNCEN5 					=  ((CSP_REGISTER_T)(0x20ul << 16))
}GPT_REARMX_Type;
/*********************************************************************** 
 @brief   GPT Rearm MODE
***********************************************************************/
typedef enum		
{
	GPT_REARM_Selected_DIS				=	((CSP_REGISTER_T)(0x00ul << 30)),
	GPT_REARM_Selected_ZRO_AUTO			=	((CSP_REGISTER_T)(0x01ul << 30)),
	GPT_REARM_Selected_PRD_AUTO			=	((CSP_REGISTER_T)(0x02ul << 30)),
	GPT_REARM_Selected_ZRO_PRD_AUTO		=	((CSP_REGISTER_T)(0x03ul << 30))
}GPT_REARM_MODE_Type;
/*********************************************************************** 
 @brief   GPT Syncusr0 Trig select
***********************************************************************/
typedef enum		
{
	GPT_SYNCUSR0_REARMTrig_DIS			=	((CSP_REGISTER_T)(0x00ul << 22)),
	GPT_SYNCUSR0_REARMTrig_T1			=	((CSP_REGISTER_T)(0x01ul << 22)),
	GPT_SYNCUSR0_REARMTrig_T2			=	((CSP_REGISTER_T)(0x02ul << 22)),
	GPT_SYNCUSR0_REARMTrig_T1T2			=	((CSP_REGISTER_T)(0x03ul << 22))
}GPT_SYNCUSR0_REARMTrig_Selecte_Type;
/*********************************************************************** 
 @brief   GPT TRGSRC0 ExtSync Selecte
***********************************************************************/
typedef enum		
{
	GPT_TRGSRC0_ExtSync_SYNCUSR0			=	((CSP_REGISTER_T)(0x00ul << 24)),
	GPT_TRGSRC0_ExtSync_SYNCUSR1			=	((CSP_REGISTER_T)(0x01ul << 24)),
	GPT_TRGSRC0_ExtSync_SYNCUSR2			=	((CSP_REGISTER_T)(0x02ul << 24)),
	GPT_TRGSRC0_ExtSync_SYNCUSR3			=	((CSP_REGISTER_T)(0x03ul << 24)),
	GPT_TRGSRC0_ExtSync_SYNCUSR4			=	((CSP_REGISTER_T)(0x04ul << 24)),
	GPT_TRGSRC0_ExtSync_SYNCUSR5			=	((CSP_REGISTER_T)(0x05ul << 24))
}GPT_TRGSRC0_ExtSync_Selected_Type;
/*********************************************************************** 
 @brief   GPT TRGSRC1 ExtSync Selecte
***********************************************************************/
typedef enum		
{
	GPT_TRGSRC1_ExtSync_SYNCUSR0			=	((CSP_REGISTER_T)(0x00ul << 27)),
	GPT_TRGSRC1_ExtSync_SYNCUSR1			=	((CSP_REGISTER_T)(0x01ul << 27)),
	GPT_TRGSRC1_ExtSync_SYNCUSR2			=	((CSP_REGISTER_T)(0x02ul << 27)),
	GPT_TRGSRC1_ExtSync_SYNCUSR3			=	((CSP_REGISTER_T)(0x03ul << 27)),
	GPT_TRGSRC1_ExtSync_SYNCUSR4			=	((CSP_REGISTER_T)(0x04ul << 27)),
	GPT_TRGSRC1_ExtSync_SYNCUSR5			=	((CSP_REGISTER_T)(0x05ul << 27))
}GPT_TRGSRC1_ExtSync_Selected_Type;
/*********************************************************************** 
 @brief   GPT PHSEN CMD
***********************************************************************/
typedef enum		
{
	GPT_PHSEN_DIS			=	((CSP_REGISTER_T)(0x00ul << 8)),
	GPT_PHSEN_EN			=	((CSP_REGISTER_T)(0x01ul << 8))
}GPT_PHSEN_CMD_Type;
/*********************************************************************** 
 @brief   GPT PHSEN select
***********************************************************************/
typedef enum		
{
	GPT_PHSDIR_increase			=	((CSP_REGISTER_T)(0x01ul << 31)),
	GPT_PHSEN_decrease			=	((CSP_REGISTER_T)(0x00ul << 31))
}GPT_PHSDIR_Type;
/*********************************************************************** 
 @brief   GPT GLDCR Config
***********************************************************************/
typedef enum		
{
	GPT_GLDMD_Selecte_ZRO						=	((CSP_REGISTER_T)(0x00ul << 1)),
	GPT_GLDMD_Selecte_PRD						=	((CSP_REGISTER_T)(0x01ul << 1)),
	GPT_GLDMD_Selecte_ZRO_PRD					=	((CSP_REGISTER_T)(0x02ul << 1)),
	GPT_GLDMD_Selecte_ZRO_ExiLoad_SYNC			=	((CSP_REGISTER_T)(0x03ul << 1)),
	GPT_GLDMD_Selecte_PRD_ExiLoad_SYNC			=	((CSP_REGISTER_T)(0x04ul << 1)),
	GPT_GLDMD_Selecte_ZRO_PRD_ExiLoad_SYNC		=	((CSP_REGISTER_T)(0x05ul << 1)),
	GPT_GLDMD_Selecte_SW						=	((CSP_REGISTER_T)(0x0Ful << 1))
}GPT_GLDMD_Selecte_Type;
/*********************************************************************** 
 @brief   GPT OSTMD Selecte
***********************************************************************/
typedef enum		
{
	GPT_GLD_OneShot_DIS						=	((CSP_REGISTER_T)(0x00ul << 5)),
	GPT_GLD_OneShot_EN						=	((CSP_REGISTER_T)(0x01ul << 5))
}GPT_GLD_OneShot_CMD_Type;
/*********************************************************************** 
 @brief   GPT PRDR Event Load
***********************************************************************/
typedef enum		
{
	GPT_PRDR_EventLoad_PEND						=	((CSP_REGISTER_T)(0x00ul << 4)),
	GPT_PRDR_EventLoad_ExiLoad_SYNC				=	((CSP_REGISTER_T)(0x01ul << 4)),
	GPT_PRDR_EventLoad_Zro_ExiLoad_SYNC			=	((CSP_REGISTER_T)(0x02ul << 4)),
	GPT_PRDR_EventLoad_Immediate				=	((CSP_REGISTER_T)(0x03ul << 4))
}GPT_PRDR_EventLoad_Type;
/*********************************************************************** 
 @brief   GPT CMPX Event load
***********************************************************************/
typedef enum		
{
	GPT_CMPX_EventLoad_DIS							=		0,
	GPT_CMPX_EventLoad_Immediate					=		1,
	GPT_CMPX_EventLoad_ZRO							=		2,
	GPT_CMPX_EventLoad_PRD							=		3,
	GPT_CMPX_EventLoad_ExiLoad_SYNC					=		4
}GPT_CMPX_EventLoad_Type;
/*********************************************************************** 
 @brief   GPT AQCRX Event load 
***********************************************************************/
typedef enum		
{
	GPT_AQCRX_EventLoad_DIS							=		0,
	GPT_AQCRX_EventLoad_Immediate					=		1,
	GPT_AQCRX_EventLoad_ZRO							=		2,
	GPT_AQCRX_EventLoad_PRD							=		3,
	GPT_AQCRX_EventLoad_ExiLoad_SYNC				=		4
}GPT_AQCRX_EventLoad_Type;
/*********************************************************************** 
 @brief   GPT PWMX Selecte 
***********************************************************************/
typedef enum		
{
	GPT_PWMA				=			0,
	GPT_PWMB				=			1
}GPT_PWMX_Selecte_Type;
/*********************************************************************** 
 @brief   GPT CA Selecte
***********************************************************************/
typedef enum		
{
	GPT_CA_Selecte_CMPA				=			((CSP_REGISTER_T)(0x00ul << 20)),
	GPT_CA_Selecte_CMPB				=			((CSP_REGISTER_T)(0x01ul << 20))
}GPT_CA_Selecte_Type;
/*********************************************************************** 
 @brief   GPT CB Selecte
***********************************************************************/
typedef enum		
{
	GPT_CB_Selecte_CMPA				=			((CSP_REGISTER_T)(0x00ul << 22)),
	GPT_CB_Selecte_CMPB				=			((CSP_REGISTER_T)(0x01ul << 22))
}GPT_CB_Selecte_Type;
/*********************************************************************** 
 @brief   GPT PWM ZRO Output
***********************************************************************/
typedef enum		
{
	GPT_PWM_ZRO_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul )),
	GPT_PWM_ZRO_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul )),
	GPT_PWM_ZRO_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul )),
	GPT_PWM_ZRO_Event_Negate				=	((CSP_REGISTER_T)(0x03ul ))
}GPT_PWM_ZRO_Output_Type;
/*********************************************************************** 
 @brief   GPT PWM PRD Output
***********************************************************************/
typedef enum		
{
	GPT_PWM_PRD_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<2 )),
	GPT_PWM_PRD_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<2 )),
	GPT_PWM_PRD_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<2 )),
	GPT_PWM_PRD_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<2 ))
}GPT_PWM_PRD_Output_Type;
/*********************************************************************** 
 @brief   GPT PWM CAU Output
***********************************************************************/
typedef enum		
{
	GPT_PWM_CAU_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<4 )),
	GPT_PWM_CAU_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<4 )),
	GPT_PWM_CAU_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<4 )),
	GPT_PWM_CAU_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<4 ))
}GPT_PWM_CAU_Output_Type;
/*********************************************************************** 
 @brief   GPT PWM CAD Output
***********************************************************************/
typedef enum		
{
	GPT_PWM_CAD_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<6 )),
	GPT_PWM_CAD_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<6 )),
	GPT_PWM_CAD_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<6 )),
	GPT_PWM_CAD_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<6 ))
}GPT_PWM_CAD_Output_Type;
/*********************************************************************** 
 @brief   GPT PWM CBU Output
***********************************************************************/
typedef enum		
{
	GPT_PWM_CBU_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<8 )),
	GPT_PWM_CBU_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<8 )),
	GPT_PWM_CBU_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<8 )),
	GPT_PWM_CBU_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<8 ))
}GPT_PWM_CBU_Output_Type;
/*********************************************************************** 
 @brief   GPT PWM CBD Output
***********************************************************************/
typedef enum		
{
	GPT_PWM_CBD_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<10 )),
	GPT_PWM_CBD_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<10 )),
	GPT_PWM_CBD_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<10 )),
	GPT_PWM_CBD_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<10 ))
}GPT_PWM_CBD_Output_Type;
/*********************************************************************** 
 @brief   GPT PWM T1U Output
***********************************************************************/
typedef enum		
{
	GPT_PWM_T1U_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<12 )),
	GPT_PWM_T1U_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<12 )),
	GPT_PWM_T1U_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<12 )),
	GPT_PWM_T1U_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<12 ))
}GPT_PWM_T1U_Output_Type;
/*********************************************************************** 
 @brief   GPT PWM T1D Output
***********************************************************************/
typedef enum		
{
	GPT_PWM_T1D_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<14 )),
	GPT_PWM_T1D_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<14 )),
	GPT_PWM_T1D_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<14 )),
	GPT_PWM_T1D_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<14 ))
}GPT_PWM_T1D_Output_Type;
/*********************************************************************** 
 @brief   GPT PWM T2U Output
***********************************************************************/
typedef enum		
{
	GPT_PWM_T2U_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<16 )),
	GPT_PWM_T2U_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<16 )),
	GPT_PWM_T2U_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<16 )),
	GPT_PWM_T2U_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<16 ))
}GPT_PWM_T2U_Output_Type;
/*********************************************************************** 
 @brief   GPT PWM T2D Output
***********************************************************************/
typedef enum		
{
	GPT_PWM_T2D_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<18 )),
	GPT_PWM_T2D_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<18 )),
	GPT_PWM_T2D_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<18 )),
	GPT_PWM_T2D_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<18 ))
}GPT_PWM_T2D_Output_Type;
/*********************************************************************** 
 @brief   GPT EPX 
***********************************************************************/
typedef enum		
{
	GPT_EP0		=		0,	
	GPT_EP1		=		1,	
	GPT_EP2		=		2,	
	GPT_EP3		=		3,	
	GPT_EP4		=		4,	
	GPT_EP5		=		5,	
	GPT_EP6		=		6,	
	GPT_EP7		=		7
}GPT_EPX_Type;
/*********************************************************************** 
 @brief   GPT Input select 
***********************************************************************/
typedef enum	
{
	GPT_Input_selecte_EBI0			=		((CSP_REGISTER_T)(1)),	//EBI0	
	GPT_Input_selecte_EBI1			=		((CSP_REGISTER_T)(2)),	//EBI1
	GPT_Input_selecte_EBI2			=		((CSP_REGISTER_T)(3)),	//EBI2
	GPT_Input_selecte_EBI3			=		((CSP_REGISTER_T)(4)),	//EBI3
	GPT_Input_selecte_LVD			=		((CSP_REGISTER_T)(5)),	//LVD
	GPT_Input_selecte_CMP			=		((CSP_REGISTER_T)(6)),	//CMP
	GPT_Input_selecte_ORL0			=		((CSP_REGISTER_T)(0XE)),
	GPT_Input_selecte_ORL1			=		((CSP_REGISTER_T)(0XF))	
}GPT_Input_selecte_Type;
/*********************************************************************** 
 @brief   GPT FLT PACE0  
***********************************************************************/
typedef enum	
{
	GPT_FLT_PACE0_DIS			=			((CSP_REGISTER_T)(0<<8)),
	GPT_FLT_PACE0_2CLK			=			((CSP_REGISTER_T)(1<<8)),
	GPT_FLT_PACE0_3CLK			=			((CSP_REGISTER_T)(2<<8)),
	GPT_FLT_PACE0_4CLK			=			((CSP_REGISTER_T)(3<<8))
}GPT_FLT_PACE0_Type;
/*********************************************************************** 
 @brief   GPT FLT PACE1  
***********************************************************************/
typedef enum	
{
	GPT_FLT_PACE1_DIS			=			((CSP_REGISTER_T)(0<<10)),
	GPT_FLT_PACE1_2CLK			=			((CSP_REGISTER_T)(1<<10)),
	GPT_FLT_PACE1_3CLK			=			((CSP_REGISTER_T)(2<<10)),
	GPT_FLT_PACE1_4CLK			=			((CSP_REGISTER_T)(3<<10))
}GPT_FLT_PACE1_Type;
/*********************************************************************** 
 @brief   GPT DB EventLoad 
***********************************************************************/
typedef enum	
{
	GPT_DB_EventLoad_DIS							=		0,
	GPT_DB_EventLoad_Immediate						=		1,
	GPT_DB_EventLoad_ZRO							=		2,
	GPT_DB_EventLoad_PRD							=		3,
	GPT_DB_EventLoad_ZRO_PRD						=		4
}GPT_DB_EventLoad_Type;
/*********************************************************************** 
 @brief   GPT CHX Selecte
***********************************************************************/
typedef enum	
{
	GPT_CHA_Selecte 		=		0,
	GPT_CHB_Selecte 		=		1
}GPT_CHX_Selecte_Type;
/*********************************************************************** 
 @brief   GPT INSEL
***********************************************************************/
typedef enum	
{
	GPT_CHAINSEL_PWMA_RISE_FALL			=		((CSP_REGISTER_T)(0<<4)),
	GPT_CHAINSEL_PWMB_RISE_PWMA_FALL		=		((CSP_REGISTER_T)(1<<4)),
	GPT_CHAINSEL_PWMA_RISE_PWMB_FALL		=		((CSP_REGISTER_T)(2<<4)),
	GPT_CHAINSEL_PWMB_RISE_FALL			=		((CSP_REGISTER_T)(3<<4))
}GPT_INSEL_Type;
/*********************************************************************** 
 @brief   GPT OUTSEL
***********************************************************************/
typedef enum	
{
	GPT_CHA_OUTSEL_PWMA_PWMB_Bypass			=		((CSP_REGISTER_T)(0)),
	GPT_CHA_OUTSEL_DisRise_EnFall			=		((CSP_REGISTER_T)(1)),
	GPT_CHA_OUTSEL_EnRise_DisFall			=		((CSP_REGISTER_T)(2)),
	GPT_CHA_OUTSEL_EnRise_EnFall			=		((CSP_REGISTER_T)(3))
}GPT_OUTSEL_Type;
/*********************************************************************** 
 @brief   GPT OUT POLARITY
***********************************************************************/
typedef enum	
{
	GPT_PA_PB_OUT_Direct				=		((CSP_REGISTER_T)(0)),
	GPT_PA_OUT_Reverse					=		((CSP_REGISTER_T)(1)),
	GPT_PB_OUT_Reverse					=		((CSP_REGISTER_T)(2)),
	GPT_PA_PB_OUT_Reverse				=		((CSP_REGISTER_T)(3))
}GPT_OUT_POLARITY_Type;
/*********************************************************************** 
 @brief   GPT OUT SWAP
***********************************************************************/
typedef enum	
{
	GPT_PAtoCHX_PBtoCHY					=		((CSP_REGISTER_T)(0)),
	GPT_PBtoCHX_PBtoCHY					=		((CSP_REGISTER_T)(1)),
	GPT_PAtoCHX_PAtoCHY					=		((CSP_REGISTER_T)(2)),
	GPT_PBtoCHX_PAtoCHY					=		((CSP_REGISTER_T)(3))
}GPT_OUT_SWAP_Type;
/*********************************************************************** 
 @brief   GPT TRGSRCX Selecte
***********************************************************************/
typedef enum	
{
	GPT_TRGSRC0			=		0,
	GPT_TRGSRC1			=		1
}GPT_TRGSRCX_Select_Type;
/*********************************************************************** 
 @brief   GPT EVTRG TRGSRCX SET
***********************************************************************/
 typedef enum
{	
	GPT_EVTRG_TRGSRCX_DIS			=	((CSP_REGISTER_T)(0x00ul )),  
	GPT_EVTRG_TRGSRCX_ZRO			=	((CSP_REGISTER_T)(0x01ul )),  
	GPT_EVTRG_TRGSRCX_PRD			=	((CSP_REGISTER_T)(0x02ul )),  
	GPT_EVTRG_TRGSRCX_ZROorPRD		=	((CSP_REGISTER_T)(0x03ul )),
	GPT_EVTRG_TRGSRCX_CMPAU			=	((CSP_REGISTER_T)(0x04ul )),
	GPT_EVTRG_TRGSRCX_CMPAD			=	((CSP_REGISTER_T)(0x05ul )),
	GPT_EVTRG_TRGSRCX_CMPBU			=	((CSP_REGISTER_T)(0x06ul )),
	GPT_EVTRG_TRGSRCX_CMPBD			=	((CSP_REGISTER_T)(0x07ul )),
	GPT_EVTRG_TRGSRC01_ExtSync		=	((CSP_REGISTER_T)(0x0Cul )),
	GPT_EVTRG_TRGSRC23_PeriodEnd	=	((CSP_REGISTER_T)(0x0Cul )),
	GPT_EVTRG_TRGSRCX_PE0			=	((CSP_REGISTER_T)(0x0Dul )),
	GPT_EVTRG_TRGSRCX_PE1			=	((CSP_REGISTER_T)(0x0Eul )),
	GPT_EVTRG_TRGSRCX_PE2			=	((CSP_REGISTER_T)(0x0Ful ))
}GPT_EVTRG_TRGSRCX_TypeDef;	
/*********************************************************************** 
 @brief   GPT EVTRG TRGSRCX CMD
***********************************************************************/
 typedef enum
{
	GPT_TRGSRCX_EN	=	((CSP_REGISTER_T)0x01ul),  
	GPT_TRGSRCX_DIS	=	((CSP_REGISTER_T)0x00ul)  
}GPT_TRGSRCX_CMD_TypeDef;
/*********************************************************************** 
 @brief   GPT INT register
***********************************************************************/
typedef enum
{
	//RISR IMCR MISR ICR
	GPT_TRGEV0_INT        		=		((CSP_REGISTER_T)(0x01ul << 0)),  
	GPT_TRGEV1_INT      		=		((CSP_REGISTER_T)(0x01ul << 1)),
	GPT_CAP_LD0					=		((CSP_REGISTER_T)(0x01ul << 4)),   
	GPT_CAP_LD1					=		((CSP_REGISTER_T)(0x01ul << 5)),
	GPT_CAU						=		((CSP_REGISTER_T)(0x01ul <<8)),
	GPT_CAD						=		((CSP_REGISTER_T)(0x01ul <<9)),
	GPT_CBU						=		((CSP_REGISTER_T)(0x01ul <<10)),
	GPT_CBD						=		((CSP_REGISTER_T)(0x01ul <<11)),
	GPT_PEND					=		((CSP_REGISTER_T)(0x01ul <<16))
}GPT_INT_TypeDef;
/*********************************************************************** 
 @brief   GPT EMINT register 
***********************************************************************/
typedef enum
{
	//EMRISR EMIMCR EMMISR EMICR
	GPT_EP0_EMINT        		=		((CSP_REGISTER_T)(0x01ul << 0)),  
	GPT_EP1_EMINT      			=		((CSP_REGISTER_T)(0x01ul << 1)),    
	GPT_EP2_EMINT        		=		((CSP_REGISTER_T)(0x01ul << 2)),   
	GPT_EP3_EMINT      			=		((CSP_REGISTER_T)(0x01ul << 3)),
	GPT_CPU_FAULT_EMINT      	=		((CSP_REGISTER_T)(0x01ul << 8)),
	GPT_MEM_FAULT_EMINT      	=		((CSP_REGISTER_T)(0x01ul << 9)),
	GPT_EOM_FAULT_EMINT      	=		((CSP_REGISTER_T)(0x01ul << 10))
}GPT_EMINT_TypeDef;
/*********************************************************************** 
 @brief   GPT LKCR TRG Source
***********************************************************************/
typedef enum
{
	GPT_LKCR_TRG_EP0			=		0,
	GPT_LKCR_TRG_EP1			=		2,
	GPT_LKCR_TRG_EP2			=		4,
	GPT_LKCR_TRG_EP3			=		6,
	GPT_LKCR_TRG_CPU_FAULT		=		15,
	GPT_LKCR_TRG_MEM_FAULT		=		16,
	GPT_LKCR_TRG_EOM_FAULT		=		17
}GPT_LKCR_TRG_Source_Type;
/*********************************************************************** 
 @brief   GPT LKCR Mode Selecte
***********************************************************************/
typedef enum
{
	GPT_LKCR_Mode_LOCK_DIS				=		((CSP_REGISTER_T)0x00ul),
	GPT_LKCR_Mode_SLOCK_EN				=		((CSP_REGISTER_T)0x01ul),
	GPT_LKCR_Mode_HLOCK_EN				=		((CSP_REGISTER_T)0x02ul),
	GPT_LKCR_TRG_X_FAULT_HLOCK_EN		=		((CSP_REGISTER_T)0x03ul),
	GPT_LKCR_TRG_X_FAULT_HLOCK_DIS		=		((CSP_REGISTER_T)0x04ul),
}GPT_LKCR_Mode_Type;
/*********************************************************************** 
 @brief   GPT OUTPUT Channel
***********************************************************************/
typedef enum
{
	GPT_OUTPUT_Channel_CHAX		=		0,
	GPT_OUTPUT_Channel_CHB		=		2,
	GPT_OUTPUT_Channel_CHAY		=		8,
}GPT_OUTPUT_Channel_Type;
/*********************************************************************** 
 @brief   GPT SHLOCK OUTPUT Statue
***********************************************************************/
typedef enum
{
	GPT_SHLOCK_OUTPUT_HImpedance		=	0,
	GPT_SHLOCK_OUTPUT_High				=	1,
	GPT_SHLOCK_OUTPUT_Low				=	2,
	GPT_SHLOCK_OUTPUT_Nochange			=	3
}GPT_SHLOCK_OUTPUT_Statue_Type;
/*********************************************************************** 
 @brief   GPTA0 IO  Set
***********************************************************************/
typedef enum
{
	GPTA0_CHA_PB0_2    	=	0,  
	GPTA0_CHA_PA0_9   	=	1,      
	GPTA0_CHA_PC0_1   	=	2, 
	GPTA0_CHA_PB0_6		=	3,  
	GPTA0_CHA_PB0_10   	=	4, 
    GPTA0_CHB_PA0_10   	=	5,  
	GPTA0_CHB_PB0_11   	=	6
}GPTA0_IOSET_TypeDef;
/*********************************************************************** 
 @brief   GPTA1 IO  Set
***********************************************************************/
typedef enum
{
	GPTA1_CHA_PA0_11    =	0,  
	GPTA1_CHA_PB0_4   	=	1,      
	GPTA1_CHA_PA1_7   	=	2, 
	GPTA1_CHA_PB0_7		=	3,  
	GPTA1_CHA_PB0_10   	=	4, 
    GPTA1_CHB_PA0_12   	=	5,  
	GPTA1_CHB_PA1_0   	=	6,
	GPTA1_CHB_PB0_11   	=	7
}GPTA1_IOSET_TypeDef; 
/*********************************************************************** 
 @brief   GPTB0 IO  Set
***********************************************************************/
typedef enum
{
	GPTB0_CHAX_PC0_0    	=	0, 		//af3=6 
	GPTB0_CHAX_PB0_0   		=	1,		//AF2=5     
	GPTB0_CHAX_PB0_2   		=	2, 		//AF2=5
	GPTB0_CHAX_PA0_13		=	3,  	//AF2=5
	GPTB0_CHAX_PA1_1   		=	4,		//AF3=6
    GPTB0_CHAX_PA1_12   	=	5, 		//AF2=5 
	GPTB0_CHAY_PA0_0   		=	6,		//AF3=6
	GPTB0_CHAY_PB0_1   		=	7,		//AF2=5
	GPTB0_CHAY_PA0_14   	=	8,		//AF2=5
	GPTB0_CHAY_PA1_2   		=	9,		//AF3=6
	GPTB0_CHAY_PA1_9   		=	10,		//AF1=5
	GPTB0_CHB_PA0_0			=	11,		//AF4=7
	GPTB0_CHB_PA0_6			=	12,		//AF2=5
	GPTB0_CHB_PA0_14		=	13,		//AF3=6
	GPTB0_CHB_PB0_4			=	14,		//AF2=5
	GPTB0_CHB_PA1_2			=	15		//AF4=7
}GPTB0_IOSET_TypeDef;
/*********************************************************************** 
 @brief   GPTB1 IO  Set
***********************************************************************/
typedef enum
{
	GPTB1_CHAX_PA0_1    	=	0, 		//af3=6 
	GPTB1_CHAX_PA0_10    	=	1, 		//af4=7 
	GPTB1_CHAX_PA0_15    	=	2, 		//af2=5 
	GPTB1_CHAX_PA1_11    	=	3, 		//af2=5 
	GPTB1_CHAX_PA1_13   	=	4, 		//af2=5
	GPTB1_CHAY_PA0_2   		=	5, 		//af3=6
	GPTB1_CHAY_PB0_3   		=	6, 		//af2=5
	GPTB1_CHAY_PA1_10   	=	7, 		//af2=5
	GPTB1_CHB_PA0_2   		=	8, 		//af4=7
	GPTB1_CHB_PB0_3   		=	9, 		//af3=6
	GPTB1_CHB_PB0_9   		=	10, 	//af3=6
	
}GPTB1_IOSET_TypeDef; 
/*********************************************************************** 
 @brief   EBIX IO  Set
***********************************************************************/
typedef enum
{
	GPTB_EBI0_IO_PA0_9			=		0X1F,
	GPTB_EBI1_IO_PB0_4			=		0X20,
	GPTB_EBI2_IO_PA1_4			=		0X21,
	GPTB_EBI3_IO_PA1_5			=		0X22
}EBIX_IOSET_TypeDef;
/*********************************************************************** 
 @brief   GPT LinkREG 
***********************************************************************/
typedef enum
{
	GPT_LinkREG_PRDR	=	1,
	GPT_LinkREG_CMPA	=	2,
	GPT_LinkREG_CMPB	=	3,
	GPT_LinkREG_GLD2	=	4,
	GPT_LinkREG_RSSR	=	5,
	GPT_LinkREG_EMSLCLR	=	6,
	GPT_LinkREG_EMHLCLR	=	7,
	GPT_LinkREG_EMICR	=	8,
	GPT_LinkREG_EMFRCR	=	9,
	GPT_LinkREG_AQOSF	=	10,
	GPT_LinkREG_AQCSF	=	11
}GPT_LinkREG_TypeDef;	
/*********************************************************************** 
 @brief   GPT LinkREG IP Selecte
***********************************************************************/
typedef enum
{
	GPT_DIS_LINK	=	0,
	GPT_EPT0_LINK	=	1,
	GPT_GPTA0_LINK	=	2,
	GPT_GPTA1_LINK	=	3,
	GPT_GPTB0_LINK	=	4,
	GPT_GPTB1_LINK	=	5
}GPT_LinkREG_IP_Selecte_TypeDef;	

/*********************************************************************** 
 @brief  GPT extern functions                  
***********************************************************************/ 
extern void GPTA0_IO_Init(GPTA0_IOSET_TypeDef IONAME);
extern void GPTA1_IO_Init(GPTA1_IOSET_TypeDef IONAME);
extern void GPTB0_IO_Init(GPTB0_IOSET_TypeDef IONAME);
extern void GPTB1_IO_Init(GPTB1_IOSET_TypeDef IONAME);
extern void GPTBX_EBIX_Init(EBIX_IOSET_TypeDef IONAME);
extern void GPT_PWM_Config(CSP_GPTX_T *GPT ,GPT_TCLK_Selecte_Type GPT_TCLK_Selecte_X , GPT_CNTMD_SELECTE_Type GPT_CNTMD_SELECTE_X  , GPT_OPM_SELECTE_Type GPT_OPM_SELECTE_X
					, U16_T GPT_PSCR);
extern void GPT_CG_gate_Config(CSP_GPTX_T *GPT ,GPT_CGSRC_TIN_Selecte_Type GPT_CGSRC_TIN_Selecte_X , U8_T GPT_CGFLT_DIV , U8_T GPT_CGFLT_CNT , GPT_BURST_CMD_Type GPT_BURST_CMD);
extern void GPT_Capture_Config(CSP_GPTX_T *GPT ,GPT_TCLK_Selecte_Type GPT_TCLK_Selecte_X , GPT_CNTMD_SELECTE_Type GPT_CNTMD_SELECTE_X  , GPT_CAPMD_SELECTE_Type GPT_CAPMD_SELECTE_X ,GPT_CAPLDEN_CMD_Type CAP_CMD 
					, GPT_LOAD_CMPA_RST_CMD_Type GPT_LOAD_CMPA_RST_CMD , GPT_LOAD_CMPB_RST_CMD_Type GPT_LOAD_CMPB_RST_CMD , U8_T GPT_STOP_WRAP , U16_T GPT_PSCR);
extern void GPT_SYNCR_Config(CSP_GPTX_T *GPT ,U8_T GPT_Triggle_Mode , GPT_SYNCUSR0_REARMTrig_Selecte_Type GPT_SYNCUSR0_REARMTrig_Selecte , GPT_TRGSRC0_ExtSync_Selected_Type GPT_TRGSRC0_ExtSync_Selected ,
					  GPT_TRGSRC1_ExtSync_Selected_Type GPT_TRGSRC1_ExtSync_Selected , U8_T GPT_SYNCR_EN);
extern void GPT_DBCR_Config(CSP_GPTX_T *GPT ,GPT_CHX_Selecte_Type GPT_CHX_Selecte , GPT_INSEL_Type GPT_INSEL_X , GPT_OUTSEL_Type GPT_OUTSEL_X , GPT_OUT_POLARITY_Type GPT_OUT_POLARITY_X , GPT_OUT_SWAP_Type GPT_OUT_SWAP_X);
extern void GPT_DB_CLK_Config(CSP_GPTX_T *GPT ,U16_T DPSC , U16_T DTR , U16_T DTF);
extern void GPT_PWMX_Output_Control(CSP_GPTX_T *GPT ,
							GPT_PWMX_Selecte_Type GPT_PWMX_Selecte ,GPT_CA_Selecte_Type GPT_CA_Selecte_X , GPT_CB_Selecte_Type GPT_CB_Selecte_X ,
							 GPT_PWM_ZRO_Output_Type GPT_PWM_ZRO_Event_Output , GPT_PWM_PRD_Output_Type GPT_PWM_PRD_Event_Output , 
							 GPT_PWM_CAU_Output_Type GPT_PWM_CAU_Event_Output , GPT_PWM_CAD_Output_Type GPT_PWM_CAD_Event_Output ,
							 GPT_PWM_CBU_Output_Type GPT_PWM_CBU_Event_Output , GPT_PWM_CBD_Output_Type GPT_PWM_CBD_Event_Output ,
							 GPT_PWM_T1U_Output_Type GPT_PWM_T1U_Event_Output , GPT_PWM_T1D_Output_Type GPT_PWM_T1D_Event_Output ,
							 GPT_PWM_T2U_Output_Type GPT_PWM_T2U_Event_Output , GPT_PWM_T2D_Output_Type GPT_PWM_T2D_Event_Output 
							 );
extern void GPT_PHSEN_Config(CSP_GPTX_T *GPT ,GPT_PHSEN_CMD_Type GPT_PHSEN_CMD , GPT_PHSDIR_Type GPT_PHSDIR , U32_T PHSR);
extern void GPT_PRDR_CMPA_CMPB_Config(CSP_GPTX_T *GPT ,U32_T GPT_PRDR_Value , U32_T GPT_CMPA_Value , U32_T GPT_CMPB_Value );
extern void GPT_SYNCR_RearmClr(CSP_GPTX_T *GPT ,GPT_REARMX_Type GPT_REARMX );
extern void GPT_Caputure_Rearm(CSP_GPTX_T *GPT );
extern void GPT_Globle_Eventload_Config(CSP_GPTX_T *GPT , GPT_GLD_OneShot_CMD_Type GPT_GLD_OneShot_CMD , GPT_GLDMD_Selecte_Type GPT_GLDMD_Selecte_X , U8_T GLDPRD_CNT , U16_T GLDCFG_EN);
extern void GPT_Globle_SwLoad_CMD(CSP_GPTX_T *GPT );
extern void GPT_PRDR_EventLoad_Config(CSP_GPTX_T *GPT , GPT_PRDR_EventLoad_Type GPT_PRDR_EventLoad_x);
extern void GPT_CMP_EventLoad_Config(CSP_GPTX_T *GPT ,GPT_CMPX_EventLoad_Type GPT_CMPX_EventLoad_x);
extern void GPT_AQCR_Eventload_Config(CSP_GPTX_T *GPT ,GPT_AQCRX_EventLoad_Type GPT_AQCRX_EventLoad_X);
extern void GPT_TRGSRCX_Config(CSP_GPTX_T *GPT ,GPT_TRGSRCX_Select_Type GPT_TRGSRCX_Select , GPT_EVTRG_TRGSRCX_TypeDef GPT_EVTRG_TRGSRCX_X , 
						GPT_TRGSRCX_CMD_TypeDef GPT_TRGSRCX_CMD , U8_T TRGEVXPRD);
extern void GPT_TRGSRCX_SWFTRG(CSP_GPTX_T *GPT ,GPT_TRGSRCX_Select_Type GPT_TRGSRCX_Select);
extern void GPT_Int_Enable(CSP_GPTX_T *GPT ,GPT_INT_TypeDef GPT_X_INT);
extern void GPT_Int_Disable(CSP_GPTX_T *GPT ,GPT_INT_TypeDef GPT_X_INT);
extern void GPT_EMInt_Enable(CSP_GPTX_T *GPT ,GPT_EMINT_TypeDef GPT_X_EMINT);
extern void GPT_EMInt_Disable(CSP_GPTX_T *GPT ,GPT_EMINT_TypeDef GPT_X_EMINT);
extern void GPT_EPX_Config(CSP_GPTX_T *GPT ,GPT_EPX_Type GPT_EPX , GPT_Input_selecte_Type GPT_Input_selecte_x , GPT_FLT_PACE0_Type GPT_FLT_PACE0_x , GPT_FLT_PACE1_Type GPT_FLT_PACE1_x ,
					U8_T ORL0_EPIx , U8_T ORL1_EPIx);
extern void GPT_EBIX_POL_Config(CSP_GPTX_T *GPT ,U8_T GPT_EBIX_POL);
extern void GPT_LKCR_TRG_Config(CSP_GPTX_T *GPT ,GPT_LKCR_TRG_Source_Type GPT_LKCR_TRG_X , GPT_LKCR_Mode_Type GPT_LKCR_Mode_X);
extern void GPT_SHLOCK_OUTPUT_Config(CSP_GPTX_T *GPT ,GPT_OUTPUT_Channel_Type GPT_OUTPUT_Channel_X , GPT_SHLOCK_OUTPUT_Statue_Type GPT_SHLOCK_OUTPUT_X);
extern void GPT_SLock_CLR(CSP_GPTX_T *GPT ,GPT_EMINT_TypeDef GPT_X_EMINT);
extern void GPT_HLock_CLR(CSP_GPTX_T *GPT ,GPT_EMINT_TypeDef GPT_X_EMINT);
extern void GPT_SW_Set_lock(CSP_GPTX_T *GPT ,GPT_EMINT_TypeDef GPT_X_EMINT);
extern void GPTA0_Vector_Int_Enable(void);
extern void GPTA0_Vector_Int_DISABLE(void);
extern void GPTA1_Vector_Int_Enable(void);
extern void GPTA1_Vector_Int_DISABLE(void);
extern void GPTB0_Vector_Int_Enable(void);
extern void GPTB0_Vector_Int_DISABLE(void);
extern void GPTB1_Vector_Int_Enable(void);
extern void GPTB1_Vector_Int_DISABLE(void);
extern void GPT_REG_LINK_CONFIG(CSP_GPTX_T *GPT ,GPT_LinkREG_TypeDef GPT_LinkREG_X, GPT_LinkREG_IP_Selecte_TypeDef GPT_LinkREG_IP_Selecte_X);
extern void GPT_Soft_Reset(CSP_GPTX_T *GPT);
extern void GPT_Start(CSP_GPTX_T *GPT);
extern void GPT_Stop(CSP_GPTX_T *GPT);
/*************************************************************/

#endif   // apt32f110_gpt_H */

/*********************************************************************** 
//				(C) COPYRIGHT 2022 APT Chip 
//						 END OF FILE         
***********************************************************************/ 