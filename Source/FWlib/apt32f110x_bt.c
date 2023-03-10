/*
  ******************************************************************************
  * @file    apt32f110_bt.c
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
#include "apt32f110x_bt.h"

/*************************************************************/
//Deinitializes the registers to their default reset
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/    
void BT_DeInit(CSP_BT_T *BTx)
{
	BTx->RSSR=BT_RESET_VALUE;
	BTx->CR=BT_RESET_VALUE;
	BTx->PSCR=BT_RESET_VALUE;
	BTx->PRDR=BT_RESET_VALUE;
	BTx->CMP=BT_RESET_VALUE;
	BTx->CNT=BT_RESET_VALUE;
	BTx->EVTRG=BT_RESET_VALUE;
	BTx->EVSWF=BT_RESET_VALUE;
	BTx->RISR=BT_RESET_VALUE;
	BTx->IMCR=BT_RESET_VALUE;
	BTx->MISR=BT_RESET_VALUE;
	BTx->ICR=BT_RESET_VALUE;
}
/*************************************************************/
//BT IO Init
//EntryParameter:LPT_OUT_PA09,LPT_OUT_PB01,LPT_IN_PA10,
//ReturnValue:NONE
/*************************************************************/
void BT_IO_Init(BT_Pin_TypeDef BT_IONAME)
{
	if(BT_IONAME==BT0_PA1_9)
	{
		GPIOA1->CONHR=(GPIOA1->CONHR & 0XFFFFFF0F)|0x00000060;
	}
	if(BT_IONAME==BT1_PC0_0)
	{
		GPIOC0->CONLR=(GPIOC0->CONLR & 0XFFFFFFF0)|0x00000005;
	}
	if(BT_IONAME==BT1_PA0_2)
	{
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFFFFF0FF)|0x00000500;
	}
	if(BT_IONAME==BT1_PA0_5)
	{
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFF0FFFFF)|0x00500000;
	}
	if(BT_IONAME==BT1_PA0_9)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XFFFFFF0F)|0x00000070;
	}
	if(BT_IONAME==BT1_PA1_10)
	{
		GPIOA1->CONHR=(GPIOA1->CONHR & 0XFFFFF0FF)|0x00000800;
	}
}
/*************************************************************/
// BT start
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void BT_Start(CSP_BT_T *BTx)
{
	BTx->RSSR |=0X01;
}
/*************************************************************/
// BT stop
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void BT_Stop(CSP_BT_T *BTx)
{
	BTx->RSSR &=0X0;
}
/*************************************************************/
// BT stop High
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void BT_Stop_High(CSP_BT_T *BTx)
{
	BTx->CR |=(0x01<<6);
	BTx->RSSR &=0X0;
}
/*************************************************************/
// BT stop Low
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void BT_Stop_Low(CSP_BT_T *BTx)
{
	BTx->CR =BTx->CR & ~(0x01<<6);
	BTx->RSSR &=0X0;
}
/*************************************************************/
// BT soft reset
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void BT_Soft_Reset(CSP_BT_T *BTx)
{
	BTx->RSSR |= (0X5<<12);
}
/*************************************************************/
//BT Configure
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void BT_Configure(CSP_BT_T *BTx,BT_CLK_TypeDef BTCLK,U16_T PSCR_DATA,BT_SHDWSTP_TypeDef BTSHDWSTP,BT_OPM_TypeDef BTOPM,BT_EXTCKM_TypeDef BTEXTCKM)
{
	BTx->CR |=BTCLK| BTSHDWSTP| BTOPM| BTEXTCKM;
	BTx->PSCR = PSCR_DATA;
}
/*************************************************************/
//BT ControlSet
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void BT_ControlSet_Configure(CSP_BT_T *BTx,BT_STARTST_TypeDef BTSTART,BT_IDLEST_TypeDef BTIDLE,BT_CNTRLD_TypeDef BTCNTRLD)
{
	BTx->CR |=BTSTART| BTIDLE| BTCNTRLD;
}
/*************************************************************/
//BT SYN ControlSet
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void BT_SYN_Control_Config(CSP_BT_T *BTx, BT_SYNCEN_Channel_TypeDef BT_SYNCEN_Channel_x, BT_SYNCEN_TypeDef BTSYNC, BT_OSTMDX_TypeDef BTOSTMD
			,BT_SYNCMD_TypeDef BTSYNCMD, BT_AREARM_TypeDef BTAREARM)
{
	if(BT_SYNCEN_Channel_x==BT_SYN_Channel0)
	{
		BTx->CR &=0XEEFFFEFF;
		BTx->CR|=BTSYNC|BTOSTMD|BTSYNCMD|BTAREARM;
	}
	else if(BT_SYNCEN_Channel_x==BT_SYN_Channel1)
	{
		BTx->CR &=0XDDFFFDFF;
		BTx->CR|=(BTSYNC<<1)|(BTOSTMD<<1)|BTSYNCMD|BTAREARM;
	}
	else if(BT_SYNCEN_Channel_x==BT_SYN_Channel2)
	{
		BTx->CR &=0XBBFFFBFF;
		BTx->CR|=(BTSYNC<<2)|(BTOSTMD<<2)|BTSYNCMD|BTAREARM;
	}
}

/*************************************************************/
//BT Period / Compare set
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void BT_Period_CMP_Write(CSP_BT_T *BTx,U16_T BTPRDR_DATA,U16_T BTCMP_DATA)
{
	//BTx->CR|=0X01<<2;
	BTx->PRDR =BTPRDR_DATA;
	BTx->CMP =BTCMP_DATA;
}
/*************************************************************/
//BT COUNTER set
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void BT_CNT_Write(CSP_BT_T *BTx,U16_T BTCNT_DATA)
{
	BTx->CNT =BTCNT_DATA;
}
/*************************************************************/
//BT read counters
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
U16_T BT_PRDR_Read(CSP_BT_T *BTx)
{
    return BTx->PRDR;
}
U16_T BT_CMP_Read(CSP_BT_T *BTx)
{
    return BTx->CMP;
}
U16_T BT_CNT_Read(CSP_BT_T *BTx)
{
    return BTx->CNT;
}
/*************************************************************/
//BT Trigger Init
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void BT_Trigger_Configure(CSP_BT_T *BTx,BT_TRGSRC_TypeDef BTTRG,BT_TRGOE_TypeDef BTTRGOE)
{
	BTx->EVTRG|=BTTRG| BTTRGOE;
}
/*************************************************************/
//BT SOFT Trigger
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void BT_Soft_Tigger(CSP_BT_T *BTx)
{
	BTx->EVSWF=0x01;
}
/*************************************************************/
//BT inturrpt Configure
//EntryParameter:BT_IMSCR_X,NewState
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void BT_ConfigInterrupt_CMD(CSP_BT_T *BTx,FunctionalStatus NewState,BT_IMSCR_TypeDef BT_IMSCR_X)
{
	if (NewState != DISABLE)
	{
		BTx->IMCR  |= BT_IMSCR_X;						
	}
	else
	{
		BTx->IMCR  &= ~BT_IMSCR_X;					
	}
}
/*************************************************************/
//BT0 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void BT0_INT_ENABLE(void)
{
	INTC_ISER_WRITE(BT0_INT);
}
/*************************************************************/
//BT0 Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void BT0_INT_DISABLE(void)
{
	INTC_ICER_WRITE(BT0_INT);
}
/*************************************************************/
//BT0 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void BT1_INT_ENABLE(void)
{
	INTC_ISER_WRITE(BT1_INT);
}
/*************************************************************/
//BT0 Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void BT1_INT_DISABLE(void)
{
	INTC_ICER_WRITE(BT1_INT);
}



/*********************************************************************** 
//						 END OF FILE         
***********************************************************************/