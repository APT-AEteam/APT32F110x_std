/*
  ******************************************************************************
  * @file    apt32f110_cmp.c
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

/****************************************************
//include
*****************************************************/ 
#include "apt32f110x_cmp.h"
#include "apt32f110x_gpio.h"
/****************************************************
//defines
*****************************************************/
volatile U32_T CMPOUTPUT_DATE;

/*************************************************************/
//CMP software reset
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/  
void CMP_software_reset(CSP_CMP_T *CMPX )
{
	CMPX->CEDR|=(0X01<<7);
}
/*************************************************************/
//CMP CLK Enable
//EntryParameter:NewState
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/  
void CMP_CLK_CMD(CSP_CMP_T *CMPX , FunctionalStatus NewState)
{
	if(NewState != DISABLE)
	{
		CMPX->CEDR|=0X01;
	}
	else
	{
		CMPX->CEDR&=0XFFFFFFFE;
	}
}
/*************************************************************/
//CMP IO initial
//EntryParameter:CMP_IONAME
//ReturnValue:NONE
/*************************************************************/ 
void CMP_IO_Init(CMP_IOSET_TypeDef  CMP_IONAME)
{
	if(CMP_IONAME==CMPIN0_PA0_0)
	{
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFFFFFFF0)|0x0000000A;										//CPIN0(PA0.00->AF7)
	}
	else if(CMP_IONAME==CMPIN1_PA1_10)
	{
		GPIOA1->CONHR=(GPIOA1->CONHR & 0XFFFFF0FF)|0x00000A00;										//CPIN1(PA0.01->AF7)
	}
	else if(CMP_IONAME==CMPIN2_PA0_3)
	{
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFFFF0FFF)|0x0000A000;										//CPIN2(PA0.03->AF7)
	}
	else if(CMP_IONAME==CMPIN3_PA0_4)
	{
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFFF0FFFF)|0x000A0000;										//CPIN3(PA0.04->AF7)
	}
	else if(CMP_IONAME==CMPIN4_PB0_0)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XFFFFFFF0)|0x0000000A;										//CPIN4(PB0.00->AF7)
	}
	else if(CMP_IONAME==CMPIN5_PB0_1)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XFFFFFF0F)|0x000000A0;										//CPIN5(PB0.01->AF7)
	}
	else if(CMP_IONAME==CMPIN6_PB0_2)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XFFFFF0FF)|0x00000A00;										//CPIN6(PB0.02->AF7)
	}
	else if(CMP_IONAME==CMPIN7_PC0_0)
	{
		GPIOC0->CONLR=(GPIOC0->CONLR & 0XFFFFFFF0)|0x0000000A;										//CPIN7(PC0.00->AF7)
	}
	else if(CMP_IONAME==CMP1OUT_PA0_8)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XFFFFFFF0)|0x00000005;										//CMP1OUT(PA0.08->AF2)
	}
	else if(CMP_IONAME==CMP1OUT_PB0_5)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XFF0FFFFF)|0x00600000;										//CMP1OUT(PB0.05->AF3)
	}
	else if(CMP_IONAME==CMP0OUT_PA1_6)
	{
		GPIOA1->CONLR=(GPIOA1->CONLR & 0XF0FFFFFF)|0x06000000;										//CMP1OUT(PA1.6->AF3)
	}
	else if(CMP_IONAME==CMP0OUT_PA1_11)
	{
		GPIOA1->CONHR=(GPIOA1->CONHR & 0XFFFF0FFF)|0x00007000;										//CMP1OUT(PA1.11->AF4)
	}
}
/*************************************************************/
//CMP INPCR Config
//EntryParameter:*CMPX
//*CMPX:CMP0,CMP1
//CMPX_NSEL:0~252
//CMPX_PSEL:0~14
//ReturnValue:NONE
/*************************************************************/ 
//--------------NSEL(-)-------------------
//0:CMPIN0
//1:CMPIN1
//2:CMPIN2
//3:CMPIN3
//4:CMPIN4
//5:CMPIN5
//7:1.0V REF
//--------------PSEL(+)-------------------
//0:CMPIN0
//1:CMPIN1
//2:CMPIN2
//3:CMPIN3
//4:CMPIN4
//5:CMPIN5
//6:CMPIN6
//7:CMPIN7
//-------------------------------------
extern void delay_nus(unsigned int t);
void CMP_INPCRX_Config(CSP_CMP_T *CMPX , U8_T CMPX_NSEL , U8_T CMPX_PSEL )
{
	if(CMPX_NSEL==7)
	{
		CMPX->INPCR=CMPX_NSEL|CMPX_PSEL<<8|(0X01<<16);
		delay_nus(20);
	}
	else
	{
		CMPX->INPCR=CMPX_NSEL|CMPX_PSEL<<8|(0X00<<16);
	}
}
/*************************************************************/
//CMP CR Config
//EntryParameter:*CMPX,HYST_Xmv,CMPx_HYSTSEL_X,POLARITY_X,EVE_SEL_X,X_FLT1EN,X_FLT2EN,CPOS_X,CMP_TRG_EN
//*CMPX:CMP0,CMP1
//CMPx_HYSTSEL_X:HYST_0mv,HYST_5mv,HYST_10mv,HYST_15mv,HYST_20mv,HYST_25mv,HYST_40mv,HYST_60mv
//POLARITY_X:POLARITY_0,POLARITY_1
//EVE_SEL_X:EVE_SEL_fall,EVE_SEL_rise,EVE_SEL_fall_rise
//X_FLT1EN:DIS_FLT1EN,EN_FLT1EN
//X_FLT2EN:DIS_FLT2EN,EN_FLT2EN
//CPOS_X:CPOS_0,CPOS_1
//CMP_TRG_EN:1 enable，0 disalbe
//ReturnValue:NONE
/*************************************************************/ 
void CMP_CR_Config(CSP_CMP_T *CMPX , CMPx_HYSTSEL_TypeDef CMPx_HYSTSEL_X , CMPx_HYST_TypeDef HYST_Xmv , CMPx_POLARITY_TypeDef POLARITY_X ,
						 CMPx_EVE_SEL_TypeDef EVE_SEL_X , CMPx_FLTEN1_TypeDef X_FLT1EN , CMPx_FLTEN2_TypeDef X_FLT2EN , CMPx_CPOS_TypeDef CPOS_X 
						, U8_T CMP_TRG_EN)
{
	CMPX->CR0=(CMPX->CR0&0XFC7FF000)|HYST_Xmv|CMPx_HYSTSEL_X|POLARITY_X|EVE_SEL_X|X_FLT1EN|X_FLT2EN|CPOS_X|(CMP_TRG_EN<<7);
}
/*************************************************************/
//CMP Open
//EntryParameter:*CMPX
//*CMPX:CMP0,CMP1
//ReturnValue:NONE
/*************************************************************/ 
void CMP_Open(CSP_CMP_T *CMPX )
{
	CMPX->CR0|=0x01;
}
/*************************************************************/
//CMP Close
//EntryParameter:*CMPX
//*CMPX:CMP0,CMP1
//ReturnValue:NONE
/*************************************************************/ 
void CMP_Close(CSP_CMP_T *CMPX)
{
	CMPX->CR0&=0xfffffffe;
}
/*************************************************************/
//CMP FLTR Config
//EntryParameter:*CMPX,CMP_DEPTH1_X,CMP_DIVN,CMP_DIVM
//*CMPX:CMP0,CMP1
//CMP_DIVN:0~0X1F
//CMP_DIVM:0~0XFF
//ReturnValue:NONE
/*************************************************************/ 
//FLT_CK = PCLK/(CMP_DIVM+1)/2^CMP_DIVN
void CMPX_FLT1CR_Config(CSP_CMP_T *CMPX ,CMP_DEPTH1_TypeDef CMP_DEPTH1_X , U8_T CMP_DIVN , U8_T CMP_DIVM)
{
	CMPX->DFCR1&=0xFFE000F8;
	CMPX->DFCR1|=(CMP_DIVN<<16)|(CMP_DIVM<<8)|CMP_DEPTH1_X;
}

void CMPX_FLT2CR_Config(CSP_CMP_T *CMPX ,CMP_DEPTH2_TypeDef CMP_DEPTH2_X , U8_T CMP_DIVN , U8_T CMP_DIVM)
{
	CMPX->DFCR2&=0xFFE000F8;
	CMPX->DFCR2|=(CMP_DIVN<<16)|(CMP_DIVM<<8)|CMP_DEPTH2_X;
}
/*************************************************************/
//CMP WCNT Config
//EntryParameter:*CMPX,HLS_X,CMPX_Trgsel_X,CMPX_MSKMOD_X,CMPX_CLKDIV_X,CMP_DCNT,WCNT
//CMPX:CMP0,CMP1
//CMP_Wind_Out_X:CMP_Wind_Out_H,CMP_Wind_Out_L
//CMP_WFALIGN_CMD:CMP_WFALIGN_EN,CMP_WFALIGN_DIS
//CMPX_CLKDIV_X:CMPX_CLKDIV_1~CMPX_CLKDIV_2048
//CMP_DCNT:0~255
//WCNT:0~1023
//ReturnValue:NONE
/*************************************************************/  
//捕捉宽度时间:(CMP_WCNT+1)*PCLK/CLKDIV
//延时宽度时间:(CMP_DCNT+1)*PCLK/CLKDIV,如果CMP_DCNT=0，延时时间=0
void CMP_WCNT_Config(CSP_CMP_T *CMPX , FunctionalStatus NewState , CMP_Wind_Out_Set_TypeDef CMP_Wind_Out_X ,
				     CMP_WFALIGN_CMD_TypeDef CMP_WFALIGN_CMD , CMPX_CLKDIV_TypeDef CMPX_CLKDIV_X , U16_T CMP_WCNT , U8_T CMP_DCNT)		
{
	if(NewState==ENABLE)
	{
		CMPX->CR0=(CMPX->CR0&0XFFFF0FFF)|(0x01<<12)|CMP_Wind_Out_X|CMP_WFALIGN_CMD;
		CMPX->WFCR=CMPX_CLKDIV_X|(CMP_DCNT<<16)|CMP_WCNT;
	}
	else
	{
		CMPX->CR0=(CMPX->CR0&0XFFFF0FFF);
	}
}
/*************************************************************/
//CMP0 Interrupt enable
//EntryParameter:CMP_INT_X,NewState
//CMP_INT_X:EDGEDET,RAWDET
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/
void CMP_ConfigInterrupt_CMD(CSP_CMP_T *CMPX , CMP_INT_TypeDef CMP_INT_X , FunctionalStatus NewState)
{
	if (NewState != DISABLE)
	{
		CMPX->IMCR  |= CMP_INT_X;						//SET
	}
	else
	{
		CMPX->IMCR  &= ~CMP_INT_X;						//CLR
	}
	CMP0->ICR =	CMP_INT_X;
}
/*************************************************************/
//CMP0 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CMP_Int_Enable(void)
{
    INTC_ISER_WRITE(CMP_INT);    
}
/*************************************************************/
//CMP0 Interrupt disalbe
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CMP_Int_Disable(void)
{
	CMP0->CR0&=~(0x01<<20);
	CMP1->CR0&=~(0x01<<20);
    INTC_ICER_WRITE(CMP_INT);    
}
/*************************************************************/
//CMP0 Interrupt wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CMP_Wakeup_Enable(void)
{
	CMP0->CR0|=0x01<<20;
	CMP1->CR0|=0x01<<20;
    INTC_IWER_WRITE(CMP_INT);    
}



/*********************************************************************** 
//						 END OF FILE         
***********************************************************************/