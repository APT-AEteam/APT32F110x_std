/*
  ******************************************************************************
  * @file    apt32f110_dma.c
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

/****************************************************
//include
*****************************************************/ 
#include "apt32f110x_dma.h"

/****************************************************
//extern
*****************************************************/ 
extern void delay_nus(unsigned int t);

/*************************************************************/
//DMA inturrpt Configure
//EntryParameter:LPT_IMSCR_X,NewState
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void DMA_ConfigInterrupt_CMD(CSP_DMA_T *DMAX , FunctionalStatus NewState , DMA_INT_TypeDef DMA_INT_X)
{
	if (NewState != DISABLE)
	{
		DMAX->CRX  |= DMA_INT_X;						
	}
	else
	{
		DMAX->CRX  &= ~DMA_INT_X;					
	}
}
/*************************************************************/
//DMA SWTRIG Start Configure
//EntryParameter:*DMAX
//*DMAX:DMA0~DMA3
//ReturnValue:NONE
/*************************************************************/ 
void DMA_SWTRIG_Start(CSP_DMA_T *DMAX )
{
	DMAX->MTRX|=0X02;
	delay_nus(1);
	DMAX->MTRX|=0X01;
}
/*************************************************************/
//DMA HWTRIG Start Configure
//EntryParameter:*DMAX
//*DMAX:DMA0~DMA3
//ReturnValue:NONE
/*************************************************************/ 
void DMA_HWTRIG_Start(CSP_DMA_T *DMAX )
{
	DMAX->MTRX|=0X02;
}
/*************************************************************/
//DMA Stop
//EntryParameter:*DMAX
//*DMAX:DMA0~DMA3
//ReturnValue:NONE
/*************************************************************/ 
void DMA_Stop(CSP_DMA_T *DMAX )
{
	DMAX->MTRX=0X04;
	while(DMAX->MTRX&0x02);
}
/*************************************************************/
//DMA Source add set
//EntryParameter:*DMAX
//*DMAX:DMA0~DMA3
//ReturnValue:NONE
/*************************************************************/ 
void DMA_Source_addr_set(CSP_DMA_T *DMAX , U32_T DAM_Source_addr , DMA_HINC_Cmd_TypeDef DMA_HINC_Cmd , DMA_LINC_Cmd_TypeDef DMA_LINC_Cmd)
{
	DMAX->ISRX=DAM_Source_addr;
	DMAX->ISCRX=DMA_HINC_Cmd|DMA_LINC_Cmd;
}
/*************************************************************/
//DMA Dest add set
//EntryParameter:*DMAX
//*DMAX:DMA0~DMA3
//ReturnValue:NONE
/*************************************************************/ 
void DMA_Dest_addr_set(CSP_DMA_T *DMAX , U32_T DAM_Dest_addr , DMA_HINC_Cmd_TypeDef DMA_HINC_Cmd , DMA_LINC_Cmd_TypeDef DMA_LINC_Cmd)
{
	DMAX->IDRX=DAM_Dest_addr;
	DMAX->IDCRX=DMA_HINC_Cmd|DMA_LINC_Cmd;
}
/*************************************************************/
//DMA CR Config
//EntryParameter:*DMAX
//*DMAX:DMA0~DMA3
//ReturnValue:NONE
/*************************************************************/ 
void DMA_CR_Config(CSP_DMA_T *DMAX , U16_T DAM_LTC , U16_T DAM_HTC , DMA_Send_TSize_TypeDef DMA_Send_TSize , DMA_Send_DSize_TypeDef DMA_Send_DSize ,
					DMA_Reload_TypeDef DMA_Reload_CMD , DMA_SendMode_TypeDef DMA_SendMode)
{
	DMAX->CRX=(DMAX->CRX&0X60000000)|DAM_LTC|(DAM_HTC<<12)|DMA_Send_TSize|DMA_Send_DSize|DMA_Reload_CMD|DMA_SendMode;
}
/*************************************************************/
//DMA Channel CMD
//EntryParameter:DMA_CESR
//DMA_CESR:CH0~CH3->BIT0~BIT3
//ReturnValue:NONE
/*************************************************************/ 
void DMA_Channel_CMD(U8_T DMA_CESR)
{
	DMA->CESR=DMA_CESR;
}
/*************************************************************/
//DMA Trig 
//EntryParameter:DMA_CESR
//DMA_CESR:CH0~CH3->BIT0~BIT3
//ReturnValue:NONE
/*************************************************************/ 
void DMA_Trig_Mode(CSP_DMA_T *DMAX , DMA_Triggle_mode_TypeDef DMA_Triggle_mode)
{
	DMA->RSRX=DMA_Triggle_mode;
}
/*************************************************************/
//DMA reset 
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void DMA_RESET(void)
{
	DMA->SRR=0X1;
}
/*************************************************************/
//DMA Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void DMA_Int_Enable(void)
{
	INTC_ISER_WRITE(DMA_INT);                             //Enable DMA interrupt
}
/*************************************************************/
//DMA Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void DMA_Int_Disable(void)
{
    INTC_ICER_WRITE(DMA_INT);                             //Disable DMA interrupt
}
/*********************************************************************** 
//						 END OF FILE         
***********************************************************************/