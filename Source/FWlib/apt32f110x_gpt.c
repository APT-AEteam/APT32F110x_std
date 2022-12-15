/*
  ******************************************************************************
  * @file    apt32f110_gpt.c
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
#include "apt32f110x_gpt.h"


/*************************************************************/
// GPT soft reset
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void GPT_Soft_Reset(CSP_GPTX_T *GPT)
{
	GPT->CEDR|=0X01;
	GPT->RSSR = (GPT->RSSR&0XFFFF0FFF)|(0X5<<12);
}
/*************************************************************/
// GPT start
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void GPT_Start(CSP_GPTX_T *GPT)
{
	GPT->REGPROT = (0xA55A<<16) | 0xC73A;
	GPT->RSSR |= 0X01;
	while(!(GPT->RSSR&0x01));
}
/*************************************************************/
// GPT stop
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void GPT_Stop(CSP_GPTX_T *GPT)
{
	GPT->REGPROT = (0xA55A<<16) | 0xC73A;
	GPT->RSSR &= 0XFFFFFFFE;
	while(GPT->RSSR&0x01);
}
/*************************************************************/
//GPT IO Init
//EntryParameter:GPTA0_CHA_PB0_2,GPTA0_CHA_PA0_9,GPTA0_CHA_PC0_1
//GPTA0_CHA_PB0_6,GPTA0_CHA_PB0_10,GPTA0_CHB_PA0_10,GPTA0_CHB_PB0_11
//ReturnValue:NONE
/*************************************************************/
void GPTA0_IO_Init(GPTA0_IOSET_TypeDef IONAME)
{
	if(IONAME==GPTA0_CHA_PB0_2)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XFFFFF0FF)|0x00000400;
	}
	if(IONAME==GPTA0_CHA_PA0_9)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XFFFFFF0F)|0x00000060;
	}
	if(IONAME==GPTA0_CHA_PC0_1)
	{
		GPIOC0->CONLR=(GPIOC0->CONLR & 0XFFFFFF0F)|0x00000050;
	}
	if(IONAME==GPTA0_CHA_PB0_6)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XF0FFFFFF)|0x06000000;
	}
	if(IONAME==GPTA0_CHA_PB0_10)
	{
		GPIOB0->CONHR=(GPIOB0->CONHR & 0XFFFFF0FF)|0x00000500;
	}
	if(IONAME==GPTA0_CHB_PA0_10)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XFFFFF0FF)|0x00000600;
	}
	if(IONAME==GPTA0_CHB_PB0_11)
	{
		GPIOB0->CONHR=(GPIOB0->CONHR & 0XFFFF0FFF)|0x00005000;
	}
}

void GPTA1_IO_Init(GPTA1_IOSET_TypeDef IONAME)
{
	if(IONAME==GPTA1_CHA_PA0_11)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XFFFF0FFF)|0x00006000;
	}
	if(IONAME==GPTA1_CHA_PB0_4)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XFFF0FFFF)|0x00060000;
	}
	if(IONAME==GPTA1_CHA_PA1_7)
	{
		GPIOA1->CONLR=(GPIOA1->CONLR & 0X0FFFFFFF)|0x70000000;
	}
	if(IONAME==GPTA1_CHA_PB0_7)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0X0FFFFFFF)|0x60000000;
	}
	if(IONAME==GPTA1_CHA_PB0_10)
	{
		GPIOB0->CONHR=(GPIOB0->CONHR & 0XFFFFF0FF)|0x00000600;
	}
	if(IONAME==GPTA1_CHB_PA0_12)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XFFF0FFFF)|0x00060000;
	}
	if(IONAME==GPTA1_CHB_PA1_0)
	{
		GPIOA1->CONLR=(GPIOA1->CONLR & 0XFFFFFFF0)|0x00000006;
	}
	if(IONAME==GPTA1_CHB_PB0_11)
	{
		GPIOB0->CONHR=(GPIOB0->CONHR & 0XFFFF0FFF)|0x00006000;
	}
}
/*************************************************************/
//GPT IO Init
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void GPTB0_IO_Init(GPTB0_IOSET_TypeDef IONAME)
{
	if(IONAME==GPTB0_CHAX_PC0_0)
	{
		GPIOC0->CONLR=(GPIOC0->CONLR & 0XFFFFFFF0)|0x00000006;
	}
	if(IONAME==GPTB0_CHAX_PB0_0)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XFFFFFFF0)|0x00000005;
	}
	if(IONAME==GPTB0_CHAX_PB0_2)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XFFFFF0FF)|0x00000500;
	}
	if(IONAME==GPTB0_CHAX_PA0_13)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XFF0FFFFF)|0x00500000;
	}
	if(IONAME==GPTB0_CHAX_PA1_1)
	{
		GPIOA1->CONLR=(GPIOA1->CONLR & 0XFFFFFF0F)|0x00000060;
	}
	if(IONAME==GPTB0_CHAX_PA1_12)
	{
		GPIOA1->CONHR=(GPIOA1->CONHR & 0XFFF0FFFF)|0x00050000;
	}
	//********
	if(IONAME==GPTB0_CHAY_PA0_0)
	{
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFFFFFFF0)|0x00000006;
	}
	if(IONAME==GPTB0_CHAY_PB0_1)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XFFFFFF0F)|0x00000050;
	}
	if(IONAME==GPTB0_CHAY_PA0_14)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XF0FFFFFF)|0x05000000;
	}
	if(IONAME==GPTB0_CHAY_PA1_2)
	{
		GPIOA1->CONLR=(GPIOA1->CONLR & 0XFFFFF0FF)|0x00000600;
	}
	if(IONAME==GPTB0_CHAY_PA1_9)
	{
		GPIOA1->CONHR=(GPIOA1->CONHR & 0XFFFFFF0F)|0x00000050;
	}
	//********
	if(IONAME==GPTB0_CHB_PA0_0)
	{
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFFFFFFF0)|0x00000007;
	}
	if(IONAME==GPTB0_CHB_PA0_6)
	{
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XF0FFFFFF)|0x05000000;
	}
	if(IONAME==GPTB0_CHB_PA0_14)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XF0FFFFFF)|0x06000000;
	}
	if(IONAME==GPTB0_CHB_PB0_4)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XFFF0FFFF)|0x00050000;
	}
	if(IONAME==GPTB0_CHB_PA1_2)
	{
		GPIOA1->CONLR=(GPIOA1->CONLR & 0XFFFFF0FF)|0x00000700;
	}
}

void GPTB1_IO_Init(GPTB1_IOSET_TypeDef IONAME)
{
	if(IONAME==GPTB1_CHAX_PA0_1)
	{
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFFFFFF0F)|0x00000060;
	}
	if(IONAME==GPTB1_CHAX_PA0_10)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XFFFFF0FF)|0x00000700;
	}
	if(IONAME==GPTB1_CHAX_PA0_15)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0X0FFFFFFF)|0x50000000;
	}
	if(IONAME==GPTB1_CHAX_PA1_11)
	{
		GPIOA1->CONHR=(GPIOA1->CONHR & 0XFFFF0FFF)|0x00005000;
	}
	if(IONAME==GPTB1_CHAX_PA1_13)
	{
		GPIOA1->CONHR=(GPIOA1->CONHR & 0XFF0FFFFF)|0x00500000;
	}
	//********
	if(IONAME==GPTB1_CHAY_PA0_2)
	{
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFFFFF0FF)|0x00000600;
	}
	if(IONAME==GPTB1_CHAY_PB0_3)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XFFFF0FFF)|0x00005000;
	}
	if(IONAME==GPTB1_CHAY_PA1_10)
	{
		GPIOA1->CONHR=(GPIOA1->CONHR & 0XFFFFF0FF)|0x00000500;
	}
	//********
	if(IONAME==GPTB1_CHB_PA0_2)
	{
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFFFFF0FF)|0x00000700;
	}
	if(IONAME==GPTB1_CHB_PB0_3)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XFFFF0FFF)|0x00006000;
	}
	if(IONAME==GPTB1_CHB_PB0_9)
	{
		GPIOB0->CONHR=(GPIOB0->CONHR & 0XFFFFFF0F)|0x00000060;
	}
}

void GPTBX_EBIX_Init(EBIX_IOSET_TypeDef IONAME)
{
	if(IONAME==GPTB_EBI0_IO_PA0_9)
	{
		GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFF0F)|0X00000050;				//PA0.9 EBI0
	}
	else if(IONAME==GPTB_EBI1_IO_PB0_4)
	{
		GPIOB0->CONLR = (GPIOB0->CONLR&0XFFF0FFFF)|0X00070000;				//PB0.4 EBI1
	}
	else if(IONAME==GPTB_EBI2_IO_PA1_4)
	{
		GPIOA1->CONLR = (GPIOA1->CONLR&0XFFF0FFFF)|0X00060000;				//PA1.4 EBI2
	}
	else if(IONAME==GPTB_EBI3_IO_PA1_5)
	{
		GPIOA1->CONLR = (GPIOA1->CONLR&0XFF0FFFFF)|0X00600000;				//PA1.5 EBI3
	}
}
/*************************************************************/
//Deinitializes the GPT PWM Config
//EntryParameter:GPT_TCLK_Selecte_X,GPT_CNTMD_SELECTE_X,GPT_OPM_SELECTE_X,GPTT_PSCR
//GPT_TCLK_Selecte_X:GPT_Selecte_PCLK,GPT_Selecte_SYNCUSR3
//GPT_CNTMD_SELECTE_X:GPT_CNTMD_increase,GPT_CNTMD_decrease,GPT_CNTMD_increaseTOdecrease
//GPT_OPM_SELECTE_X:GPT_OPM_Once,GPT_OPM_Continue
//GPT_PSCR:0~0XFFFF(GPTB0~GPTB1),0~0XFFFFFF(GPTA0~GPTA1)
//ReturnValue:NONE
/*************************************************************/  
//Fclk=Fpclk/(PSC+1)
void GPT_PWM_Config(CSP_GPTX_T *GPT ,GPT_TCLK_Selecte_Type GPT_TCLK_Selecte_X , GPT_CNTMD_SELECTE_Type GPT_CNTMD_SELECTE_X  , GPT_OPM_SELECTE_Type GPT_OPM_SELECTE_X
					, U16_T GPT_PSCR)		
//start选immediate模式,debug挂起PWM输出高阻,pwm停止时输出高阻,start控制位同步触发,ZRO载入PSCR(bit17:bit16)
{
	GPT->CEDR=(GPT->CEDR&0XFFFFFF00)|(0X01|GPT_TCLK_Selecte_X|(0X01<<1)|(0X00<<6));
	if(GPT_TCLK_Selecte_X==GPT_Selecte_PCLK)
	{
		GPT->PSCR=GPT_PSCR;
	}
	GPT->CR=(GPT->CR&0xfff8ffc0)|GPT_CNTMD_SELECTE_X|(0x1<<2)|(0x0<<3)|(0x0<<4)|GPT_OPM_SELECTE_X|(0X0<<16)|(0x1<<18);
} 
/*************************************************************/
//Deinitializes the GPT CG gate Config
//EntryParameter:GPT_CGSRC_TIN_Selecte_X,GPT_CGFLT_DIV,GPT_CGFLT_CNT,GPT_BURST_CMD
//GPT_CGSRC_TIN_Selecte_X:GPT_CGSRC_TIN_BT0OUT,GPT_CGSRC_TIN_BT1OUT,GPT_CGSRC_CHAX,GPT_CGSRC_CHBX,GPT_CGSRC_DIS
//GPT_CGFLT_DIV:0~255
//GPT_CGFLT_CNT:0~7
//GPT_BURST_CMD:GPT_BURST_ENABLE,GPT_BURST_DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void GPT_CG_gate_Config(CSP_GPTX_T *GPT ,GPT_CGSRC_TIN_Selecte_Type GPT_CGSRC_TIN_Selecte_X , U8_T GPT_CGFLT_DIV , U8_T GPT_CGFLT_CNT , GPT_BURST_CMD_Type GPT_BURST_CMD)
{
	GPT->CR=(GPT->CR&0xffff01ff)|GPT_BURST_CMD|GPT_CGFLT_CNT<<13|0x01<<10;
	GPT->CEDR=(GPT->CEDR&0XFFFF00CF)|(GPT_CGFLT_DIV<<8);
	if(GPT_CGSRC_TIN_Selecte_X==GPT_CGSRC_DIS)
	{
		//GPT->CEDR|=0X00<<4;
		//GPT->CR|=0X03<<11;
	}
	else if(GPT_CGSRC_TIN_Selecte_X==GPT_CGSRC_CHAX)
	{
		//GPT->CEDR|=0X00<<4;
		GPT->CR|=0X00<<11;
	}
	else if(GPT_CGSRC_TIN_Selecte_X==GPT_CGSRC_CHBX)
	{
		//GPT->CEDR|=0X00<<4;
		GPT->CR|=0X01<<11;
	}
}
/*************************************************************/
//Deinitializes the GPT Caputer Config
//EntryParameter:GPT_TCLK_Selecte_X,GPT_CNTMD_SELECTE_X,GPT_CAPMD_SELECTE_X,GPT_LOAD_CMPA_RST_CMD~GPT_LOAD_CMPD_RST_CMD,GPT_STOP_WRAP,GPT_PSCR
//GPT_TCLK_Selecte_X:GPT_Selecte_PCLK,GPT_Selecte_SYNCUSR3
//GPT_CNTMD_SELECTE_X:GPT_CNTMD_increase,GPT_CNTMD_decrease,GPT_CNTMD_increaseTOdecrease
//GPT_CAPMD_SELECTE_X:GPT_CAPMD_Once,GPT_CAPMD_Continue
//GPT_LOAD_CMPA_RST_CMD:GPT_LDARST_EN,GPT_LDARST_DIS
//GPT_LOAD_CMPB_RST_CMD:GPT_LDBRST_EN,GPT_LDBRST_DIS
//GPT_STOP_WRAP:0~3
//GPT_PSCR:0~0XFFFF
//ReturnValue:NONE
/*************************************************************/  
void GPT_Capture_Config(CSP_GPTX_T *GPT ,GPT_TCLK_Selecte_Type GPT_TCLK_Selecte_X , GPT_CNTMD_SELECTE_Type GPT_CNTMD_SELECTE_X  , GPT_CAPMD_SELECTE_Type GPT_CAPMD_SELECTE_X ,GPT_CAPLDEN_CMD_Type CAP_CMD 
					, GPT_LOAD_CMPA_RST_CMD_Type GPT_LOAD_CMPA_RST_CMD , GPT_LOAD_CMPB_RST_CMD_Type GPT_LOAD_CMPB_RST_CMD , U8_T GPT_STOP_WRAP , U16_T GPT_PSCR)
{
	GPT->CEDR=(GPT->CEDR&0XFFFFFF00)|(0X01|GPT_TCLK_Selecte_X|(0X01<<1)|(0X00<<6));
	if(GPT_TCLK_Selecte_X==GPT_Selecte_PCLK)
	{
		GPT->PSCR=GPT_PSCR;
	}
	GPT->CR=(GPT->CR&0xf800fec0)|GPT_CNTMD_SELECTE_X|(0x0<<2)|(0x0<<3)|(0x0<<4)|CAP_CMD|GPT_CAPMD_SELECTE_X|(0X0<<16)|(0x0<<18)|(GPT_STOP_WRAP<<21)|
				GPT_LOAD_CMPA_RST_CMD|GPT_LOAD_CMPB_RST_CMD;
}
/*************************************************************/
//Deinitializes the GPT SYNCR Config
//EntryParameter:GPT_Triggle_X,GPT_SYNCR_EN,GPT_SYNCUSR0_REARMTrig_Selecte,GPT_TRGSRC0_ExtSync_Selected,GPT_TRGSRC1_ExtSync_Selected
//GPT_Triggle_X:bit0:OSTMD0~bit5:OSTMD5,if 0 continue mode，else 1 once mode.
//GPT_SYNCUSR0_REARMTrig_Selecte:GPT_SYNCUSR0_REARMTrig_DIS,GPT_SYNCUSR0_REARMTrig_T1,GPT_SYNCUSR0_REARMTrig_T2
//GPT_SYNCUSR0_REARMTrig_T1T2
//GPT_TRGSRC0_ExtSync_Selected:GPT_TRGSRC0_ExtSync_SYNCUSR0~GPT_TRGSRC0_ExtSync_SYNCUSR5
//GPT_TRGSRC1_ExtSync_Selected:GPT_TRGSRC1_ExtSync_SYNCUSR0~GPT_TRGSRC1_ExtSync_SYNCUSR5
//EPT_SYNCR_EN:0~0X3F
//ReturnValue:NONE
/*************************************************************/  
void GPT_SYNCR_Config(CSP_GPTX_T *GPT ,U8_T GPT_Triggle_Mode , GPT_SYNCUSR0_REARMTrig_Selecte_Type GPT_SYNCUSR0_REARMTrig_Selecte , GPT_TRGSRC0_ExtSync_Selected_Type GPT_TRGSRC0_ExtSync_Selected ,
					  GPT_TRGSRC1_ExtSync_Selected_Type GPT_TRGSRC1_ExtSync_Selected , U8_T GPT_SYNCR_EN)
{
	GPT->REGPROT = (0xA55A<<16) | 0xC73A;
	GPT->SYNCR = (GPT->SYNCR&0XC03F0000) |GPT_SYNCR_EN|(GPT_Triggle_Mode<<8)|GPT_SYNCUSR0_REARMTrig_Selecte|GPT_TRGSRC0_ExtSync_Selected|GPT_TRGSRC1_ExtSync_Selected;
}
/*************************************************************/
//Deinitializes the GPT DBCR Config,only for gptb
//EntryParameter:GPT_CHX_Selecte,GPT_INSEL_X,GPT_OUTSEL_X,GPT_OUT_POLARITY_X,GPT_OUT_SWAP_X
//GPT_CHX_Selecte:GPT_CHA_Selecte
//GPT_INSEL_X:GPT_PWMA_RISE_FALL,GPT_PWMB_RISE_PWMA_FALL,GPT_PWMA_RISE_PWMB_FALL,GPT_PWMB_RISE_FALL
//GPT_OUTSEL_X:GPT_OUTSEL_PWMA_PWMB_Bypass,GPT_OUTSEL_DisRise_EnFall,GPT_OUTSEL_EnRise_DisFall,GPT_OUTSEL_EnRise_EnFall
//GPT_OUT_POLARITY_X:GPT_PA_PB_OUT_Direct,GPT_PA_OUT_Reverse,GPT_PB_OUT_Reverse,GPT_PA_PB_OUT_Reverse
//GPT_OUT_SWAP_X:GPT_PAtoCHX_PBtoCHY,GPT_PBtoCHX_PBtoCHY,GPT_PAtoCHX_PAtoCHY,GPT_PBtoCHX_PAtoCHY
//ReturnValue:NONE
/*************************************************************/   
void GPT_DBCR_Config(CSP_GPTX_T *GPT ,GPT_CHX_Selecte_Type GPT_CHX_Selecte , GPT_INSEL_Type GPT_INSEL_X , GPT_OUTSEL_Type GPT_OUTSEL_X , GPT_OUT_POLARITY_Type GPT_OUT_POLARITY_X , GPT_OUT_SWAP_Type GPT_OUT_SWAP_X)
{	
	if(GPT_CHX_Selecte==GPT_CHA_Selecte)
	{
		GPT->DBCR=(GPT->DBCR&0XFFFFFF00)|GPT_INSEL_X|GPT_OUTSEL_X|(GPT_OUT_POLARITY_X<<2)|(GPT_OUT_SWAP_X<<6);
	}
	GPT->DBCR|=0x01<<24;
}
/*************************************************************/
//Deinitializes the GPT DB CLK Config
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/   
//Fdbclk=Fhclk/(DPSC+1)
void GPT_DB_CLK_Config(CSP_GPTX_T *GPT ,U16_T DPSC , U16_T DTR , U16_T DTF)
{
	GPT->DPSCR=DPSC;
	GPT->DBDTR=DTR;
	GPT->DBDTF=DTF;
}
/*************************************************************/
//Deinitializes the GPT PWMA~PWMB Control
//EntryParameter:GPT_PWMX_Selecte,GPT_CA_Selecte_X,GPT_CB_Selecte_X
//GPT_PWMX_Selecte:GPT_PWMA,GPT_PWMB
//GPT_CA_Selecte_X:GPT_CA_Selecte_CMPA,GPT_CA_Selecte_CMPB
//GPT_CB_Selecte_X:GPT_CB_Selecte_CMPA,GPT_CB_Selecte_CMPB
//ReturnValue:NONE
/*************************************************************/   
void GPT_PWMX_Output_Control(CSP_GPTX_T *GPT ,
							GPT_PWMX_Selecte_Type GPT_PWMX_Selecte ,GPT_CA_Selecte_Type GPT_CA_Selecte_X , GPT_CB_Selecte_Type GPT_CB_Selecte_X ,
							 GPT_PWM_ZRO_Output_Type GPT_PWM_ZRO_Event_Output , GPT_PWM_PRD_Output_Type GPT_PWM_PRD_Event_Output , 
							 GPT_PWM_CAU_Output_Type GPT_PWM_CAU_Event_Output , GPT_PWM_CAD_Output_Type GPT_PWM_CAD_Event_Output ,
							 GPT_PWM_CBU_Output_Type GPT_PWM_CBU_Event_Output , GPT_PWM_CBD_Output_Type GPT_PWM_CBD_Event_Output ,
							 GPT_PWM_T1U_Output_Type GPT_PWM_T1U_Event_Output , GPT_PWM_T1D_Output_Type GPT_PWM_T1D_Event_Output ,
							 GPT_PWM_T2U_Output_Type GPT_PWM_T2U_Event_Output , GPT_PWM_T2D_Output_Type GPT_PWM_T2D_Event_Output 
							 )
{
	if(GPT_PWMX_Selecte==GPT_PWMA)
	{
		GPT->AQCR1=GPT_CA_Selecte_X|GPT_CB_Selecte_X|GPT_PWM_ZRO_Event_Output|GPT_PWM_PRD_Event_Output|GPT_PWM_CAU_Event_Output|GPT_PWM_CAD_Event_Output|
					GPT_PWM_CBU_Event_Output|GPT_PWM_CBD_Event_Output|GPT_PWM_T1U_Event_Output|GPT_PWM_T1D_Event_Output|GPT_PWM_T2U_Event_Output|GPT_PWM_T2D_Event_Output;
	}
	else if(GPT_PWMX_Selecte==GPT_PWMB)
	{
		GPT->AQCR2=GPT_CA_Selecte_X|GPT_CB_Selecte_X|GPT_PWM_ZRO_Event_Output|GPT_PWM_PRD_Event_Output|GPT_PWM_CAU_Event_Output|GPT_PWM_CAD_Event_Output|
					GPT_PWM_CBU_Event_Output|GPT_PWM_CBD_Event_Output|GPT_PWM_T1U_Event_Output|GPT_PWM_T1D_Event_Output|GPT_PWM_T2U_Event_Output|GPT_PWM_T2D_Event_Output;
	}
}
/*************************************************************/
//Deinitializes the GPT PHSEN Config
//EntryParameter:GPT_PHSEN_CMD,GPT_PHSDIR,PHSR
//GPT_PHSEN_CMD:GPT_PHSEN_EN,GPT_PHSEN_DIS
//GPT_PHSDIR:GPT_PHSDIR_increase,GPT_PHSEN_decrease
//PHSR:0~0xffffff
//ReturnValue:NONE
/*************************************************************/  
void GPT_PHSEN_Config(CSP_GPTX_T *GPT ,GPT_PHSEN_CMD_Type GPT_PHSEN_CMD , GPT_PHSDIR_Type GPT_PHSDIR , U32_T PHSR)
{
	GPT->CR=(GPT->CR&0xffffff7f)|GPT_PHSEN_CMD;
	GPT->PHSR=PHSR|GPT_PHSDIR;
}
/*************************************************************/
//Deinitializes the GPT PRDR CMPA CMPB Config
//EntryParameter:GPT_PRDR_Value,GPT_CMPA_Value,GPT_CMPB_Value
//GPT_PRDR_Value:0~0xffff(GPTB),0~0xffffff(GPTA)
//GPT_CMPA_Value:0~0xffff(GPTB),0~0xffffff(GPTA)
//GPT_CMPB_Value:0~0xffff(GPTB),0~0xffffff(GPTA)
//GPTA0为24bit计数器，GPTA1为16bit计数器
/*************************************************************/ 
void GPT_PRDR_CMPA_CMPB_Config(CSP_GPTX_T *GPT ,U32_T GPT_PRDR_Value , U32_T GPT_CMPA_Value , U32_T GPT_CMPB_Value)
{
	GPT->PRDR=GPT_PRDR_Value;
	GPT->CMPA=GPT_CMPA_Value;
	GPT->CMPB=GPT_CMPB_Value;
}
/*************************************************************/
//Deinitializes the GPT SYNCR Rearm
//EntryParameter:GPT_REARMX,GPT_REARM_MODE
//GPT_REARMX:GPT_REARM_SYNCEN0,GPT_REARM_SYNCEN1,GPT_REARM_SYNCEN2,GPT_REARM_SYNCEN3,GPT_REARM_SYNCEN4,GPT_REARM_SYNCEN5
//ReturnValue:NONE
/*************************************************************/  
void GPT_SYNCR_RearmClr(CSP_GPTX_T *GPT ,GPT_REARMX_Type GPT_REARMX )
{
	GPT->REGPROT = (0xA55A<<16) | 0xC73A;
	GPT->SYNCR = (GPT->SYNCR&0X3FC0FFFF)|GPT_REARMX;
}
/*************************************************************/
//Deinitializes the GPT Caputer Rearm
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/  
//重置捕捉：捕捉事件计数器被清零， 自动打开CAPLDEN
void GPT_Caputure_Rearm(CSP_GPTX_T *GPT )
{
	GPT->CR=(GPT->CR&0xfffdffff)|(0x01<<19);
}
/*************************************************************/
//Deinitializes the GPT Globle Event Load
//EntryParameter:GPT_GLDMD_Selecte_X,GLDCFG_EN,GPT_GLD_OneShot_CMD,GLDPRD_CNT
//GPT_GLD_OneShot_CMD:GPT_GLD_OneShot_DIS,GPT_GLD_OneShot_EN
//GPT_GLDMD_Selecte_X:GPT_GLDMD_Selecte_ZRO,GPT_GLDMD_Selecte_PRD,GPTS_GLDMD_Selecte_ZRO_PRD,GPT_GLDMD_Selecte_ZRO_ExiLoad_SYNC
//GPT_GLDMD_Selecte_PRD_ExiLoad_SYNC,GPT_GLDMD_Selecte_ZRO_PRD_ExiLoad_SYNC,
//GLDPRD_CNT:0~7(0->立即触发,1->第二次满足条件触发,7->第八次满足条件触发)
//GLDCFG_EN:0~0x3fff
//ReturnValue:NONE
/*************************************************************/  
//PRDR/CMPA/CMPB/DBDTR/DBCR/AQCR1/AQCR2/AQCSF/EMPSR 载入配置
void GPT_Globle_Eventload_Config(CSP_GPTX_T *GPT , GPT_GLD_OneShot_CMD_Type GPT_GLD_OneShot_CMD , GPT_GLDMD_Selecte_Type GPT_GLDMD_Selecte_X , U8_T GLDPRD_CNT , U16_T GLDCFG_EN)
{
	GPT->GLDCR=0X01|GPT_GLD_OneShot_CMD|GPT_GLDMD_Selecte_X|(GLDPRD_CNT<<7);
	GPT->GLDCFG=GLDCFG_EN;
}
/*************************************************************/
//Deinitializes the GPT Globle SW Load
//EntryParameter:GLDCFG_EN
//GLDCFG_EN:0X0~0X3FFF
//EPT_GLDMD_Selecte_X:
/*************************************************************/ 
//PRDR/CMPA/CMPB/DBDTR/DBCR/AQCR1/AQCR2/AQCSF/EMPSR 载入配置
void GPT_Globle_SwLoad_CMD(CSP_GPTX_T *GPT )
{
	GPT->REGPROT = (0xA55A<<16) | 0xC73A;
	GPT->GLDCR2=0X03;
}
/*************************************************************/
//Deinitializes the GPT PRDR Load 
//EntryParameter:GPT_PRDR_EventLoad_x
//GPT_PRDR_EventLoad_x:GPT_PRDR_EventLoad_PEND,GPT_PRDR_EventLoad_ExiLoad_SYNC,GPT_PRDR_EventLoad_Zro_ExiLoad_SYNC,
//GPT_PRDR_EventLoad_Immediate
/*************************************************************/ 
void GPT_PRDR_EventLoad_Config(CSP_GPTX_T *GPT , GPT_PRDR_EventLoad_Type GPT_PRDR_EventLoad_x)
{
	GPT->GLDCR&=0XFFFFFFFE;	//使用独立单个配置
	GPT->CR=(GPT->CR&0xffffffcf)|GPT_PRDR_EventLoad_x;
}
/*************************************************************/
//Deinitializes the GPT CMPX Load Config
//EntryParameter:GPT_CMPX_EventLoad_x
//GPT_CMPX_EventLoad_x:GPT_CMPX_EventLoad_DIS,GPT_CMPX_EventLoad_Immediate,GPT_CMPX_EventLoad_ZRO,
//GPT_CMPX_EventLoad_PRD,GPT_CMPX_EventLoad_ExiLoad_SYNC
/*************************************************************/ 
//统一载入寄存器:CMPA,CMPB
void GPT_CMP_EventLoad_Config(CSP_GPTX_T *GPT ,GPT_CMPX_EventLoad_Type GPT_CMPX_EventLoad_x)
{
	GPT->GLDCR&=0XFFFFFFFE;		//使用独立单个配置
	if(GPT==GPT_CMPX_EventLoad_DIS)
	{
		GPT->CMPLDR=0;
	}
	else if(GPT_CMPX_EventLoad_x==GPT_CMPX_EventLoad_Immediate)
	{
		GPT->CMPLDR=0xf;
	}
	else if(GPT_CMPX_EventLoad_x==GPT_CMPX_EventLoad_ZRO)
	{
		GPT->CMPLDR=0x2410;	
	}
	else if(GPT_CMPX_EventLoad_x==GPT_CMPX_EventLoad_PRD)
	{
		GPT->CMPLDR=0x4920;
	}
	else if(GPT_CMPX_EventLoad_x==GPT_CMPX_EventLoad_ExiLoad_SYNC)
	{
		GPT->CMPLDR=0x8240;
	}
}
/*************************************************************/
//Deinitializes the GPT AQCRX Load Config
//EntryParameter:GPT_AQCRX_EventLoad_X
//GPT_AQCRX_EventLoad_X:GPT_AQCRX_EventLoad_DIS,GPT_AQCRX_EventLoad_Immediate,GPT_AQCRX_EventLoad_ZRO,
//GPT_AQCRX_EventLoad_PRD,GPT_AQCRX_EventLoad_ExiLoad_SYNC
/*************************************************************/ 
//统一载入寄存器:AQCRA,AQCRB
void GPT_AQCR_Eventload_Config(CSP_GPTX_T *GPT ,GPT_AQCRX_EventLoad_Type GPT_AQCRX_EventLoad_X)
{
	GPT->GLDCR&=0XFFFFFFFE;		//使用独立单个配置
	if(GPT_AQCRX_EventLoad_X==GPT_AQCRX_EventLoad_DIS)
	{
		GPT->AQLDR=0;
	}
	else if(GPT_AQCRX_EventLoad_X==GPT_AQCRX_EventLoad_Immediate)
	{
		GPT->AQLDR=0x303;
	}
	else if(GPT_AQCRX_EventLoad_X==GPT_AQCRX_EventLoad_ZRO)
	{
		GPT->AQLDR=0x2424;	
	}
	else if(GPT_AQCRX_EventLoad_X==GPT_AQCRX_EventLoad_PRD)
	{
		GPT->AQLDR=0x4848;
	}
	else if(GPT_AQCRX_EventLoad_X==GPT_AQCRX_EventLoad_ExiLoad_SYNC)
	{
		GPT->AQLDR=0x9090;
	}
}
/*************************************************************/
//GPT EVTRG Config
//EntryParameter:GPT_TRGSRCX_Select,GPT_EVTRG_TRGSRCX_X,GPT_TRGSRCX_CMD,TRGEVXPRD
//GPT_TRGSRCX_Select:GPT_TRGSRC0,GPT_TRGSRC1
//GPT_EVTRG_TRGSRCX_X:
//GPT_TRGSRCX_CMD:
//TRGEVXPRD:0~0xf
//ReturnValue: NONE
/*************************************************************/
void GPT_TRGSRCX_Config(CSP_GPTX_T *GPT ,GPT_TRGSRCX_Select_Type GPT_TRGSRCX_Select , GPT_EVTRG_TRGSRCX_TypeDef GPT_EVTRG_TRGSRCX_X , 
						GPT_TRGSRCX_CMD_TypeDef GPT_TRGSRCX_CMD , U8_T TRGEVXPRD)
{
	if(GPT_TRGSRCX_Select==GPT_TRGSRC0)
	{
		GPT->EVTRG=(GPT->EVTRG&0xffeffff0)|(GPT_EVTRG_TRGSRCX_X<<0)|(GPT_TRGSRCX_CMD<<20);
		GPT->EVPS=TRGEVXPRD;
	}
	else if(GPT_TRGSRCX_Select==GPT_TRGSRC1)
	{
		GPT->EVTRG=(GPT->EVTRG&0xffdfff0f)|(GPT_EVTRG_TRGSRCX_X<<4)|(GPT_TRGSRCX_CMD<<21);
		GPT->EVPS=TRGEVXPRD<<4;
	}
	GPT->EVTRG|=0x0f0f0000;
}
/*************************************************************/
//EPT EVTRG SWFTRG
//EntryParameter:GPT_TRGSRCX_Select
//GPT_TRGSRCX_Select:GPT_TRGSRC0,GPT_TRGSRC1
//ReturnValue: NONE
/*************************************************************/
void GPT_TRGSRCX_SWFTRG(CSP_GPTX_T *GPT ,GPT_TRGSRCX_Select_Type GPT_TRGSRCX_Select)
{
	if(GPT_TRGSRCX_Select==GPT_TRGSRC0)
	{
		GPT->EVSWF|=0X01;
	}
	else if(GPT_TRGSRCX_Select==GPT_TRGSRC1)
	{
		GPT->EVSWF|=0X02;
	}
}
/*************************************************************/
//GPT INT ENABLE.
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void GPT_Int_Enable(CSP_GPTX_T *GPT ,GPT_INT_TypeDef GPT_X_INT)
{
	GPT->ICR 	= GPT_X_INT;							//clear LVD INT status
	GPT->IMCR  |= GPT_X_INT;
}
/*************************************************************/
//GPT INT DISABLE.
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void GPT_Int_Disable(CSP_GPTX_T *GPT ,GPT_INT_TypeDef GPT_X_INT)
{
	GPT->IMCR  &= ~GPT_X_INT;
}
/*************************************************************/
//GPT EMINT ENABLE.
//EntryParameter:GPT_X_EMINT
//EPT_X_EMINT:GPT_EP0_EMINT~EPT_EP4_EMINT,EPT_CPU_FAULT_EMINT,EPT_MEM_FAULT_EMINT,EPT_EOM_FAULT_EMINT
//ReturnValue: NONE
/*************************************************************/
void GPT_EMInt_Enable(CSP_GPTX_T *GPT ,GPT_EMINT_TypeDef GPT_X_EMINT)
{
	GPT->EMICR = GPT_X_EMINT;							//clear LVD INT status
	GPT->EMIMCR  |= GPT_X_EMINT;
}
/*************************************************************/
//GPT EMINT DISABLE.
//EntryParameter:GPT_X_EMINT
//GPT_X_EMINT:GPT_EP0_EMINT~GPT_EP4_EMINT,GPT_CPU_FAULT_EMINT,GPT_MEM_FAULT_EMINT,GPT_EOM_FAULT_EMINT
//ReturnValue: NONE
/*************************************************************/
void GPT_EMInt_Disable(CSP_GPTX_T *GPT ,GPT_EMINT_TypeDef GPT_X_EMINT)
{
	GPT->EMIMCR  &= ~GPT_X_EMINT;
}
/*************************************************************/
//Deinitializes the GPT EP0~EP4 Config
//EntryParameter:GPT_EPX,GPT_Input_selecte_x,GPT_FLT_PACE0_x,GPT_FLT_PACE1_x,ORL0_EPIx,ORL1_EPIx
//GPT_EPX:GPT_EP0~GPT_EP4
//GPT_Input_selecte_x:GPT_Input_selecte_EBI0~GPT_Input_selecte_EBI4,GPT_Input_selecte_ORL0,GPT_Input_selecte_ORL1
//GPT_FLT_PACE0_x:GPT_FLT_PACE0_DIS~GPT_FLT_PACE0_4CLK(EP0~EP3)
//GPT_FLT_PACE1_x:GPT_FLT_PACE1_DIS~GPT_FLT_PACE1_4CLK(EP4)
//ORL0_EPIx:ORL0_EP0~ORL0_EP7
//ORL1_EPIx:ORL1_EP0~ORL1_EP7
//ReturnValue:NONE
/*************************************************************/   
void GPT_EPX_Config(CSP_GPTX_T *GPT ,GPT_EPX_Type GPT_EPX , GPT_Input_selecte_Type GPT_Input_selecte_x , GPT_FLT_PACE0_Type GPT_FLT_PACE0_x , GPT_FLT_PACE1_Type GPT_FLT_PACE1_x ,
					U8_T ORL0_EPIx , U8_T ORL1_EPIx)
{
	GPT->REGPROT = (0xA55A<<16) | 0xC73A;
	if(GPT_EPX==GPT_EP0)
	{
		GPT->EMSRC=(GPT->EMSRC&0XFFFFFFF0)|(GPT_Input_selecte_x<<0);
	}
	else if(GPT_EPX==GPT_EP1)
	{
		GPT->EMSRC=(GPT->EMSRC&0XFFFFFF0F)|(GPT_Input_selecte_x<<4);
	}
	else if(GPT_EPX==GPT_EP2)
	{
		GPT->EMSRC=(GPT->EMSRC&0XFFFFF0FF)|(GPT_Input_selecte_x<<8);
	}
	else if(GPT_EPX==GPT_EP3)
	{
		GPT->EMSRC=(GPT->EMSRC&0XFFFF0FFF)|(GPT_Input_selecte_x<<12);
	}
	else if(GPT_EPX==GPT_EP4)
	{
		GPT->EMSRC=(GPT->EMSRC&0XFFF0FFFF)|(GPT_Input_selecte_x<<16);
	}
	GPT->REGPROT = (0xA55A<<16) | 0xC73A;
	GPT->EMSRC2=ORL0_EPIx|(ORL1_EPIx<<16)|GPT_FLT_PACE0_x|GPT_FLT_PACE1_x;
}
/*************************************************************/
//Deinitializes GPT_EPIX POL Config
//EntryParameter:GPT_EPIX_POL
//GPT_EPIX_POL:BIT0->EBI0(0:高电平有效 1:低电平有效),BIT1->EBI1(0:高电平有效 1:低电平有效),
//BIT2->EBI2(0:高电平有效 1:低电平有效),BIT3->EBI3(0:高电平有效 1:低电平有效),BIT4->EBI4(0:高电平有效 1:低电平有效)
//ReturnValue:NONE
/*************************************************************/   
void GPT_EBIX_POL_Config(CSP_GPTX_T *GPT ,U8_T GPT_EBIX_POL)
{
	GPT->REGPROT = (0xA55A<<16) | 0xC73A;
	GPT->EMPOL=GPT_EBIX_POL;
}
/*************************************************************/
//GPT EM Config
//EntryParameter:GPT_LKCR_TRG_X,GPT_LKCR_Mode_X
//GPT_LKCR_TRG_X:GPT_LKCR_TRG_EP0~GPT_LKCR_TRG_EP4,GPT_LKCR_TRG_CPU_FAULT,GPT_LKCR_TRG_MEM_FAULT,GPT_LKCR_TRG_EOM_FAULT
//GPT_LKCR_Mode_X:GPT_LKCR_Mode_LOCK_DIS,GPT_LKCR_Mode_SLOCK_EN,GPT_LKCR_Mode_HLOCK_EN,GPT_LKCR_TRG_X_FAULT_HLOCK_EN,GPT_LKCR_TRG_X_FAULT_HLOCK_DIS
//ReturnValue:NONE
/*************************************************************/
void GPT_LKCR_TRG_Config(CSP_GPTX_T *GPT ,GPT_LKCR_TRG_Source_Type GPT_LKCR_TRG_X , GPT_LKCR_Mode_Type GPT_LKCR_Mode_X)
{
	GPT->REGPROT = (0xA55A<<16) | 0xC73A;
	GPT->EMECR|=(0X01<<21)|(0X01<<22)|(0X02<<24);			//EMOSR CNT=ZRO时载入，CNT=ZRO和PRD时软锁止自动清除
	GPT->REGPROT = (0xA55A<<16) | 0xC73A;
	if(GPT_LKCR_TRG_X==GPT_LKCR_TRG_CPU_FAULT)
	{
		if(GPT_LKCR_Mode_X==GPT_LKCR_TRG_X_FAULT_HLOCK_EN)
		{
			GPT->EMECR|=(0x01<<28);
		}
		else if(GPT_LKCR_Mode_X==GPT_LKCR_TRG_X_FAULT_HLOCK_DIS)
		{
			GPT->EMECR&=~(0x01<<28);
		}
	}
	else if(GPT_LKCR_TRG_X==GPT_LKCR_TRG_MEM_FAULT)
	{
		if(GPT_LKCR_Mode_X==GPT_LKCR_TRG_X_FAULT_HLOCK_EN)
		{
			GPT->EMECR|=(0x01<<29);
		}
		else if(GPT_LKCR_Mode_X==GPT_LKCR_TRG_X_FAULT_HLOCK_DIS)
		{
			GPT->EMECR&=~(0x01<<29);
		}
	}
	else if(GPT_LKCR_TRG_X==GPT_LKCR_TRG_EOM_FAULT)
	{
		if(GPT_LKCR_Mode_X==GPT_LKCR_TRG_X_FAULT_HLOCK_EN)
		{
			GPT->EMECR|=(0x01<<30);
		}
		else if(GPT_LKCR_Mode_X==GPT_LKCR_TRG_X_FAULT_HLOCK_DIS)
		{
			GPT->EMECR&=~(0x01<<30);
		}
	}
	else
	{
		GPT->EMECR|=(GPT_LKCR_Mode_X<<(GPT_LKCR_TRG_X))|(0X01<<26);
	}
}
/*************************************************************/
//GPT EM Config
//EntryParameter:GPT_OUTPUT_Channel_X,GPT_SHLOCK_OUTPUT_X
//GPT_OUTPUT_Channel_X:GPT_OUTPUT_Channel_CHAX,GPT_OUTPUT_Channel_CHAY,GPT_OUTPUT_Channel_CHB
//GPT_SHLOCK_OUTPUT_X:GPT_SHLOCK_OUTPUT_HImpedance,GPT_SHLOCK_OUTPUT_High,GPT_SHLOCK_OUTPUT_Low,GPT_SHLOCK_OUTPUT_Nochange
//ReturnValue:NONE
/*************************************************************/
void GPT_SHLOCK_OUTPUT_Config(CSP_GPTX_T *GPT ,GPT_OUTPUT_Channel_Type GPT_OUTPUT_Channel_X , GPT_SHLOCK_OUTPUT_Statue_Type GPT_SHLOCK_OUTPUT_X)
{
	GPT->REGPROT = (0xA55A<<16) | 0xC73A;
	GPT->EMOSR|=GPT_SHLOCK_OUTPUT_X<<GPT_OUTPUT_Channel_X;
}
/*************************************************************/
//GPT software lock clr
//EntryParameter:GPT_X_EMINT
//GPT_X_EMINT:GPT_EP0_EMINT~GPT_EP4_EMINT,GPT_CPU_FAULT_EMINT,GPT_MEM_FAULT_EMINT,GPT_EOM_FAULT_EMINT
//ReturnValue:NONE
/*************************************************************/
void GPT_SLock_CLR(CSP_GPTX_T *GPT ,GPT_EMINT_TypeDef GPT_X_EMINT)
{
	GPT->EMSLCLR|=GPT_X_EMINT;
}
/*************************************************************/
//GPT H lock clr
//EntryParameter:GPT_X_EMINT
//EPT_X_EMINT:GPT_EP0_EMINT~GPT_EP4_EMINT,GPT_CPU_FAULT_EMINT,GPT_MEM_FAULT_EMINT,GPT_EOM_FAULT_EMINT
//ReturnValue:NONE
/*************************************************************/
void GPT_HLock_CLR(CSP_GPTX_T *GPT ,GPT_EMINT_TypeDef GPT_X_EMINT)
{
	GPT->EMHLCLR|=GPT_X_EMINT;
}
/*************************************************************/
//GPT software lock SET
//EntryParameter:GPT_X_EMINT
//GPT_X_EMINT:GPT_EP0_EMINT~GPT_EP4_EMINT,GPT_CPU_FAULT_EMINT,GPT_MEM_FAULT_EMINT,GPT_EOM_FAULT_EMINT
//ReturnValue:NONE
/*************************************************************/
void GPT_SW_Set_lock(CSP_GPTX_T *GPT ,GPT_EMINT_TypeDef GPT_X_EMINT)
{
	GPT->REGPROT = (0xA55A<<16) | 0xC73A;
	GPT->EMFRCR|=GPT_X_EMINT;
}

/*************************************************************/
//GPT Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void GPTA0_Vector_Int_Enable(void)
{
	INTC_ISER_WRITE(GPTA0_INT);
}
void GPTA1_Vector_Int_Enable(void)
{
	INTC_ISER_WRITE(GPTA1_INT);
}
/*************************************************************/
//LPT Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void GPTA0_Vector_Int_Disable(void)
{
	INTC_ICER_WRITE(GPTA0_INT);
}

void GPTA1_Vector_Int_Disable(void)
{
	INTC_ICER_WRITE(GPTA1_INT);
}
/*************************************************************/
//GPT Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void GPTB0_Vector_Int_Enable(void)
{
	INTC_ISER_WRITE(GPTB0_INT);
}
void GPTB1_Vector_Int_Enable(void)
{
	INTC_ISER_WRITE(GPTB1_INT);
}
/*************************************************************/
//LPT Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void GPTB0_Vector_Int_Disable(void)
{
	INTC_ICER_WRITE(GPTB0_INT);
}

void GPTB1_Vector_Int_Disable(void)
{
	INTC_ICER_WRITE(GPTB1_INT);
}	
/*************************************************************/
//GPT REG LINK CONFIG
//EntryParameter:GPT_LinkREG_X,GPT_LinkREG_IP_Selecte_X
//GPT_LinkREG_X:GPT_LinkREG_PRDR,GPT_LinkREG_CMPA,GPT_LinkREG_CMPB,
//GPT_LinkREG_GLD2,GPT_LinkREG_RSSR,GPT_LinkREG_EMSLCLR,GPT_LinkREG_EMHLCLR
//GPT_LinkREG_EMICR,GPT_LinkREG_EMFRCR,GPT_LinkREG_AQOSF,GPT_LinkREG_AQCSF
//GPT_LinkREG_IP_Selecte_X:DIS_LINK,EPT0_LINK,GPTA0_LINK,GPTA1_LINK,GPTB0_LINK,GPTB1_LINK
//ReturnValue:NONE
/*************************************************************/
void GPT_REG_LINK_CONFIG(CSP_GPTX_T *GPT ,GPT_LinkREG_TypeDef GPT_LinkREG_X, GPT_LinkREG_IP_Selecte_TypeDef GPT_LinkREG_IP_Selecte_X)
{
	if(GPT_LinkREG_X==GPT_LinkREG_PRDR)
	{
		GPT->REGLINK|=GPT_LinkREG_IP_Selecte_X;
	}
	else if(GPT_LinkREG_X==GPT_LinkREG_CMPA)
	{
		GPT->REGLINK|=GPT_LinkREG_IP_Selecte_X<<4;
	}
	else if(GPT_LinkREG_X==GPT_LinkREG_CMPB)
	{
		GPT->REGLINK|=GPT_LinkREG_IP_Selecte_X<<8;
	}
	else if(GPT_LinkREG_X==GPT_LinkREG_GLD2)
	{
		GPT->REGLINK|=GPT_LinkREG_IP_Selecte_X<<20;
	}
	else if(GPT_LinkREG_X==GPT_LinkREG_RSSR)
	{
		GPT->REGLINK|=GPT_LinkREG_IP_Selecte_X<<24;
	}
	else if(GPT_LinkREG_X==GPT_LinkREG_EMSLCLR)
	{
		GPT->REGLINK2|=GPT_LinkREG_IP_Selecte_X<<0;
	}
	else if(GPT_LinkREG_X==GPT_LinkREG_EMHLCLR)
	{
		GPT->REGLINK2|=GPT_LinkREG_IP_Selecte_X<<4;
	}
	else if(GPT_LinkREG_X==GPT_LinkREG_EMICR)
	{
		GPT->REGLINK2|=GPT_LinkREG_IP_Selecte_X<<8;
	}
	else if(GPT_LinkREG_X==GPT_LinkREG_EMFRCR)
	{
		GPT->REGLINK2|=GPT_LinkREG_IP_Selecte_X<<12;
	}
	else if(GPT_LinkREG_X==GPT_LinkREG_AQOSF)
	{
		GPT->REGLINK2|=GPT_LinkREG_IP_Selecte_X<<16;
	}
	else if(GPT_LinkREG_X==GPT_LinkREG_AQCSF)
	{
		GPT->REGLINK2|=GPT_LinkREG_IP_Selecte_X<<20;
	}
}



/*********************************************************************** 
//						 END OF FILE         
***********************************************************************/