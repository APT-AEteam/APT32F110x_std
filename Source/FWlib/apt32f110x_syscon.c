/*
  ******************************************************************************
  * @file    apt32f110_syscon.c
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
#include "apt32f110x_syscon.h"
#include "apt32f110x_uart.h"
/****************************************************
//define
*****************************************************/ 

/****************************************************
//extern
*****************************************************/ 
extern void delay_nms(unsigned int t);

/*************************************************************/
//Deinitializes the syscon registers to their default reset
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/    
void SYSCON_RST_VALUE(void)									//reset value
{
	//SYSCON->IDCCR=SYSCON_IDCCR_RST;
	//SYSCON->GCER=SYSCON_GCER_RST;
	//SYSCON->GCDR=SYSCON_GCDR_RST;
	//SYSCON->GCSR=SYSCON_GCSR_RST;
	//SYSCON->CKST=SYSCON_CKST_RST;
	SYSCON->RAMCHK=SYSCON_RAMCHK_RST;
	SYSCON->EFLCHK=SYSCON_EFLCHK_RST;
	SYSCON->SCLKCR=SYSCON_SCLKCR_RST;
	//SYSCON->PCLKCR=SYSCON_PCLKCR_RST;
	//SYSCON->PCER0=SYSCON_PCER0_RST;
	//SYSCON->PCDR0=SYSCON_PCDR0_RST;
	//SYSCON->PCSR0=SYSCON_PCSR0_RST;
	//SYSCON->PCER1=SYSCON_PCER1_RST;
	//SYSCON->PCDR1=SYSCON_PCDR1_RST;
	//SYSCON->PCSR1=SYSCON_PCSR1_RST;
	SYSCON->OSTR=SYSCON_OSTR_RST;
	SYSCON->LVDCR=SYSCON_LVDCR_RST;
	//SYSCON->CLCR=SYSCON_CLCR_RST;
	//SYSCON->PWRCR=SYSCON_PWRCR_RST;
	//SYSCON->PWRKEY=SYSCON_PWRKEY_RST;
	//SYSCON->IMER=SYSCON_IMER_RST;
	//SYSCON->IMDR=SYSCON_IMDR_RST;
	//SYSCON->IMCR=SYSCON_IMCR_RST;
	//SYSCON->IAR=SYSCON_IAR_RST;
	//SYSCON->ICR=SYSCON_ICR_RST;
	//SYSCON->RISR=SYSCON_RISR_RST;
	//SYSCON->MISR=SYSCON_MISR_RST;
	SYSCON->EXIRT=SYSCON_EXIRT_RST;
	SYSCON->EXIFT=SYSCON_EXIFT_RST;
	//SYSCON->EXIER=SYSCON_EXIER_RST;
	//SYSCON->EXIDR=SYSCON_EXIDR_RST;
	//SYSCON->EXIMR=SYSCON_EXIMR_RST;
	//SYSCON->EXIAR=SYSCON_EXIAR_RST;
	//SYSCON->EXICR=SYSCON_EXICR_RST;
	//SYSCON->EXIRS=SYSCON_EXIRS_RST;
	SYSCON->IWDCR=SYSCON_IWDCR_RST;
	SYSCON->IWDCNT=SYSCON_IWDCNT_RST;
	//SYSCON->PWROPT=SYSCON_PWROPT_RST;
	SYSCON->EVTRG=SYSCON_EVTRG_RST;
	SYSCON->EVPS=SYSCON_EVPS_RST;
	SYSCON->EVSWF=SYSCON_EVSWF_RST;
	SYSCON->UREG0=SYSCON_UREG0_RST;
	SYSCON->UREG1=SYSCON_UREG1_RST;
	SYSCON->UREG2=SYSCON_UREG2_RST;
	SYSCON->UREG3=SYSCON_UREG3_RST;
}
/*************************************************************/
//EMOSC OSTR Config
//EM_CNT:0~0X3FF
//EM_GM:0~0X1F
//EM_FLEN;EM_FLEN_DIS,EM_FLEN_EN
//EM_FLSEL:EM_FLSEL_5ns,EM_FLSEL_10ns,EM_FLSEL_15ns,EM_FLSEL_20ns
/*************************************************************/  
void EMOSC_OSTR_Config(U16_T EM_CNT, U8_T EM_GM,EM_LFSEL_TypeDef EM_LFSEL_X, EM_Filter_CMD_TypeDef EM_FLEN_X, EM_Filter_TypeDef EM_FLSEL_X)
{
	SYSCON->OSTR= (SYSCON->OSTR&0xf1ff0000)|(EM_CNT|(EM_GM<<11)|EM_LFSEL_X|EM_FLEN_X|EM_FLSEL_X);
}
/*************************************************************/
//ESOSC OSTR Config
//ES_CNT:0~0XFF
//ES_GM:0~0XF
//ES_SMT_CMD;EM_SMTDIS,EM_SMTEN
/*************************************************************/  
void ESOSC_OSTR_Config(U8_T ES_CNT, U8_T ES_GM, EM_SMT_CMD_TypeDef EM_SMT_CMD)
{
	SYSCON->OSTR= (SYSCON->OSTR&0x0E00FFFF)|(ES_CNT<<16)|(ES_GM<<28)|(EM_SMT_CMD);
}
/*************************************************************/
//SYSCON General Control
//EntryParameter:NewState:,ENDIS_X
//NewState:ENABLE,DISABLE
//ENDIS_X:ENDIS_ISOSC,ENDIS_IMOSC,ENDIS_EMOSC,ENDIS_HFOSC
//ReturnValue:NONE
/*************************************************************/  
void SYSCON_General_CMD(FunctionalStatus NewState, SYSCON_General_CMD_TypeDef ENDIS_X )
{
	if (NewState != DISABLE)
	{
		if(ENDIS_X==ENDIS_EMOSC) 
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFFF00FFF)|0x00044000;					//enable EMOSC PIN
		if(ENDIS_X==ENDIS_ESOSC)
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFFFFF00F)|0x00000440;					//enable ESOSC PIN
		SYSCON->GCER|=ENDIS_X;													//enable SYSCON General Control
		while(!(SYSCON->GCSR&ENDIS_X));											//check  Enable?	
		switch(ENDIS_X)
		{
			case ENDIS_IMOSC:
				while (!(SYSCON->CKST & ENDIS_IMOSC)); 	
				break;
			case ENDIS_ESOSC:
				while (!(SYSCON->CKST & ENDIS_ESOSC)); 
				break;
			case ENDIS_EMOSC:
				while (!(SYSCON->CKST & ENDIS_EMOSC)); 
				break;	
			case ENDIS_ISOSC:
				while (!(SYSCON->CKST & ENDIS_ISOSC)); 
				break;
			case ENDIS_HFOSC:
				while (!(SYSCON->CKST & ENDIS_HFOSC)); 
				break;	
			case ENDIS_IDLE_PCLK:
				break;	
			case ENDIS_SYSTICK:
				break;	
		}
	}
	else
	{
		SYSCON->GCDR|=ENDIS_X;													//disable SYSCON General Control
		while(SYSCON->GCSR&ENDIS_X);											//check Disable?
		SYSCON->ICR|=ENDIS_X;													//Clear ENDIS_X stable bit
	}
}

/*************************************************************/
//Seleted system clk and seleted clk div
//EntryParameter:SYSCLK_X,HCLK_DIV_X,PCLK_DIV_X
//SYSCLK_X:SYSCLK_IMOSC,SYSCLK_EMOSC,SYSCLK_ISOSC,SYSCLK_HFOSC,SYSCLK_ESOSC
//HCLK_DIV_X:HCLK_DIV_1/2/3/4/5/6/7/8/12/16/24/32/64/128/256
//PCLK_DIV_X:PCLK_DIV_1,PCLK_DIV_2,PCLK_DIV_4,PCLK_DIV_8,PCLK_DIV_16
//SystemClk_data_x:EMOSC_24M,EMOSC_16M,EMOSC_12M,EMOSC_8M,EMOSC_4M,EMOSC_36K,
//ISOSC,IMOSC,HFOSC_48M,HFOSC_24M,HFOSC_12M,HFOSC_6M
//ReturnValue:NONE
/*************************************************************/ 
void SystemCLK_HCLKDIV_PCLKDIV_Config(SystemCLK_TypeDef SYSCLK_X , SystemCLK_Div_TypeDef HCLK_DIV_X , PCLK_Div_TypeDef PCLK_DIV_X , SystemClk_data_TypeDef SystemClk_data_x )
{
	if(SystemClk_data_x==HFOSC_48M)
	{
		IFC->CEDR=0X01;						//CLKEN
		IFC->MR=0X02|(0X01<<16);			//High speed mode
	}
	if((SystemClk_data_x==EMOSC_24M)||(SystemClk_data_x==HFOSC_24M))
	{
		IFC->CEDR=0X01;						//CLKEN
		IFC->MR=0X01|(0X01<<16);			//Medium speed mode
	}
	if((SystemClk_data_x==EMOSC_12M)||(SystemClk_data_x==HFOSC_12M)||(SystemClk_data_x==EMOSC_16M))
	{
		IFC->CEDR=0X01;						//CLKEN
		IFC->MR=0X01|(0X00<<16);			//Low speed mode
	}
	if((SystemClk_data_x==EMOSC_8M)||(SystemClk_data_x==EMOSC_4M)||(SystemClk_data_x==EMOSC_36K)||(SystemClk_data_x==ESOSC_32K)
		||(SystemClk_data_x==IMOSC)||(SystemClk_data_x==ISOSC)||(SystemClk_data_x==HFOSC_6M))
	{
		IFC->CEDR=0X01;						//CLKEN
		IFC->MR=0X00|(0X00<<16);			//Low speed mode
	}
	SYSCON->SCLKCR=SYSCLK_KEY | HCLK_DIV_X| SYSCLK_X;
	while (!(SYSCON->CKST & (1<<8))); 											// waiting for sysclk stable
	SYSCON->PCLKCR=PCLK_KEY|PCLK_DIV_X;											//PCLK DIV 1 2 4 6 8 16		
	while(SYSCON->PCLKCR!=PCLK_DIV_X);											//Wait PCLK DIV
}
/*************************************************************/
//clear system clk register
//ReturnValue:NONE
/*************************************************************/ 
void SystemCLK_Clear(void)
{
	SYSCON->SCLKCR=0xd22d0000;
	while(SYSCON->SCLKCR!=0);
}
/*************************************************************/
//SYSCON IMOSC SELECTE
//EntryParameter:IMOSC_SELECTE_X
//IMOSC_SELECTE_X:IMOSC_SELECTE_5556K,IMOSC_SELECTE_4194K;IMOSC_SELECTE_2097K;IMOSC_SELECTE_131K
//ReturnValue:NONE
/*************************************************************/  
void SYSCON_IMOSC_SELECTE(IMOSC_SELECTE_TypeDef IMOSC_SELECTE_X)
{		
	//SYSCON_General_CMD(DISABLE,ENDIS_IMOSC);					//disalbe IMOSC
	SYSCON->OPT1 = (SYSCON->OPT1 & 0XFFFFFFFC)|IMOSC_SELECTE_X;	//IMOSC CLK selected
	//SYSCON_General_CMD(ENABLE,ENDIS_IMOSC);						//enable IMOSC
}
/*************************************************************/
//SYSCON HFOSC SELECTE
//EntryParameter:HFOSC_SELECTE_X
//HFOSC_SELECTE_X:HFOSC_SELECTE_48M,HFOSC_SELECTE_24M;HFOSC_SELECTE_12M;HFOSC_SELECTE_6M
//ReturnValue:NONE
/*************************************************************/  
void SYSCON_HFOSC_SELECTE(HFOSC_SELECTE_TypeDef HFOSC_SELECTE_X)
{		
	SYSCON_General_CMD(DISABLE,ENDIS_HFOSC);					//disable HFOSC
	SYSCON->OPT1 = (SYSCON->OPT1 & 0XFFFFFFCF)|HFOSC_SELECTE_X;
	SYSCON_General_CMD(ENABLE,ENDIS_HFOSC);						//enable HFOSC
}
/*************************************************************/
//WDT enable and disable 
//EntryParameter:,NewState
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/
void SYSCON_WDT_CMD(FunctionalStatus NewState)
{
	if(NewState != DISABLE)
	{
		SYSCON->IWDEDR=IWDTEDR_KEY|Enable_IWDT;
		while(!(SYSCON->IWDCR&Check_IWDT_BUSY));
	}
	else
	{
		SYSCON->IWDEDR=IWDTEDR_KEY|Disable_IWDT;
		while(SYSCON->IWDCR&Check_IWDT_BUSY);
	}
}
/*************************************************************/
//reload WDT CN
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void SYSCON_IWDCNT_Reload(void)
{
	SYSCON->IWDCNT=CLR_IWDT;
}
/*************************************************************/
//IWDCNT Config
//EntryParameter:NewStateE_IWDT_SHORT,IWDT_TIME_X,IWDT_INTW_DIV_X
//NewStateE_IWDT_SHORT:ENABLE_IWDT_SHORT,DISABLE_IWDT_SHORT
//IWDT_TIME_X:IWDT_TIME_128MS,IWDT_TIME_256MS,IWDT_TIME_500MS,IWDT_TIME_1S,IWDT_TIME_2S,IWDT_TIME_3S,IWDT_TIME_4S,IWDT_TIME_8S
//IWDT_INTW_DIV_X:IWDT_INTW_DIV_1/2/3/4/4/5/6
//ReturnValue: NONE
/*************************************************************/
void SYSCON_IWDCNT_Config(IWDT_TIME_TypeDef IWDT_TIME_X , IWDT_TIMEDIV_TypeDef IWDT_INTW_DIV_X )
{
	SYSCON->IWDCR=IWDT_KEY|IWDT_TIME_X|IWDT_INTW_DIV_X;
}
/*************************************************************/
//LVD Config  and set LVD INT
//EntryParameter:X_LVDEN,INTDET_LVL_X,RSTDET_LVL_X,X_LVD_INT
//X_LVDEN:ENABLE_LVDEN,DISABLE_LVDEN
//LVDRST_CMD:LVDRST_EN,LVDRST_DIS
//INTDET_LVL_X:INTDET_LVL_1_8V,INTDET_LVL_2_1V,INTDET_LVL_2_5V,INTDET_LVL_2_9V,INTDET_LVL_3_3V,INTDET_LVL_3_7V,INTDET_LVL_4_1V,INTDET_LVL_4_5V
//RSTDET_LVL_X:RSTDET_LVL_1_6V,RSTDET_LVL_2_0V,RSTDET_LVL_2_4V,RSTDET_LVL_2_8V,RSTDET_LVL_3_2V,RSTDET_LVL_3_6V,RSTDET_LVL_4_0V,RSTDET_LVL_4_4V
//INTDET_POL_X:INTDET_POL_fall,INTDET_POL_X_rise,INTDET_POL_X_riseORfall
//ReturnValue: NONE
/*************************************************************/
void SYSCON_LVD_Config(X_LVDEN_TypeDef X_LVDEN ,LVDRST_CMD_TypeDef LVDRST_CMD , INTDET_LVL_X_TypeDef INTDET_LVL_X , RSTDET_LVL_X_TypeDef RSTDET_LVL_X , INTDET_POL_X_TypeDef INTDET_POL_X)
{
	//SYSCON->LVDCR=LVD_KEY;
	SYSCON->LVDCR=LVD_KEY|X_LVDEN|LVDRST_CMD|INTDET_LVL_X|RSTDET_LVL_X|INTDET_POL_X;
}
/*************************************************************/
//LVD INT ENABLE.
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void LVD_Int_Enable(void)
{
	SYSCON->ICR = LVD_INT_ST;				//clear LVD INT status
	SYSCON->IMER  |= LVD_INT_ST;
}
/*************************************************************/
//LVD INT DISABLE.
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void LVD_Int_Disable(void)
{
	SYSCON->IMDR  |= LVD_INT_ST;
}
/*************************************************************/
//WDT INT ENABLE.
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void IWDT_Int_Enable(void)
{
	SYSCON->ICR = IWDT_INT_ST;				//clear LVD INT status
	SYSCON->IMER  |= IWDT_INT_ST;
}
/*************************************************************/
//WDT INT DISABLE.
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void IWDT_Int_Disable(void)
{
	SYSCON->IMDR  |= IWDT_INT_ST;
}
/*************************************************************/
//Reset status.
//EntryParameter:NONE
//ReturnValue: rsr_dat
//rsr_dat=0x01 power on reset
//rsr_dat=0x02 low voltage reset
//rsr_dat=0x04 ex-pin reset
//rsr_dat=0x10 wdt reset
//rsr_dat=0x40 ex clock invalid reset
//rsr_dat=0x80 cpu request reset
//rsr_dat=0x100 software reset
/*************************************************************/
U32_T Read_Reset_Status(void)
{
	return (SYSCON->RSR & 0x1ff);
}
/*************************************************************/
//external trigger  Mode Selection Functions
//EntryParameter:NewState,EXIPIN,EXI_tringer_mode
//NewState:ENABLE,DISABLE
//EXIPIN:EXI_PIN0/1/2/3/4/5/6/7/8/9/10/11/12/13/14/15/16/17/18/19
//EXI_tringer_mode:_EXIRT,_EXIFT
//ReturnValue: LVD detection flag
/*************************************************************/
void EXTI_trigger_CMD(FunctionalStatus NewState , SYSCON_EXIPIN_TypeDef  EXIPIN , EXI_tringer_mode_TypeDef EXI_tringer_mode)
{
	switch(EXI_tringer_mode)
	{
		case _EXIRT:
		if(NewState != DISABLE)
		{
			SYSCON->EXIRT |=EXIPIN;
		}
		else
		{
			SYSCON->EXIRT &=~EXIPIN;	
		}
		break;
		case _EXIFT:
		if(NewState != DISABLE)
		{
			SYSCON->EXIFT |=EXIPIN;
		}
		else
		{
			SYSCON->EXIFT &=~EXIPIN;	
		}
		break;
	}	
}
/*************************************************************/
//external interrupt enable and disable 
//EntryParameter:NewState,EXIPIN,* GPIOX
//* GPIOX:GPIOA,GPIOB
//EXIPIN:EXI_PIN0/1/2/3/4/5/6/7/8/9/10/11/12/13/14/15/16/17/18/19
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/
void EXTI_interrupt_CMD(FunctionalStatus NewState , SYSCON_EXIPIN_TypeDef  EXIPIN)
{
	SYSCON->EXICR = 0X3FFFF;									//Claer EXI INT status
	if(NewState != DISABLE)
	{
		SYSCON->EXIER|=EXIPIN;								//EXI4 interrupt enable
		while(!(SYSCON->EXIMR&EXIPIN));						//Check EXI is enabled or not
		SYSCON->EXICR |=EXIPIN;								// Clear EXI status bit
	}
	else
	{
		SYSCON->EXIDR|=EXIPIN;
	}
}
/*************************************************************/
//GPIO EXTI interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void GPIO_EXTI_interrupt(CSP_GPIO_T * GPIOX,U32_T GPIO_IECR_VALUE)
{
	GPIOX->IECR=GPIO_IECR_VALUE;
}
/*************************************************************/
//PLCK goto SLEEP mode
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void PCLK_goto_idle_mode(void)
{
	asm ("doze");											// Enter sleep mode
}  
/*************************************************************/
//PLCK goto SLEEP mode
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
/*void org_address_in_prg(void)
{
	//禁止中断
	asm  ("psrclr ie");
	//test
	//r0,r1压栈
	asm("subi r14,4");
	asm("st.w r0,(r14,0)");
	asm("subi r14,4");
	asm("st.w r1,(r14,0)");
	//save r2~r3
	asm("lrw r0,R_r2_buf");
	asm("st.w r2,(r0,0)");
	asm("lrw r0,R_r3_buf");
	asm("st.w r3,(r0,0)");
	//r0,r1出栈
	asm("ld.w r0,(r14,0)");
	asm("lrw r3,R_r1_buf");
	asm("st.w r0,(r3,0)");
	asm("addi r14,4");
	asm("ld.w r1,(r14,0)");
	asm("lrw r3,R_r0_buf");
	asm("st.w r1,(r3,0)");
	asm("addi r14,4");
	//save r4~r8 r13~r14
	asm("lrw r0,R_r4_buf");
	asm("st.w r4,(r0,0)");
	asm("lrw r0,R_r5_buf");
	asm("st.w r5,(r0,0)");
	asm("lrw r0,R_r6_buf");
	asm("st.w r6,(r0,0)");
	asm("lrw r0,R_r7_buf");
	asm("st.w r7,(r0,0)");
	asm("lrw r0,R_r8_buf");
	asm("st.w r8,(r0,0)");
	asm("lrw r0,R_r13_buf");
	asm("st.w r13,(r0,0)");
	asm("lrw r0,R_r14_buf");
	asm("st.w r14,(r0,0)");
	asm("lrw r0,R_r15_buf");
	asm("st.w r15,(r0,0)");
	//save cr0
	asm("lrw r0,R_cr0_buf");
	asm("mfcr r1,cr<0,0>");
	asm("st.w r1,(r0,0)");
	//save r0 r1	
	asm("lrw r0,R_cr1_buf");
	asm("mfcr r1,cr<1,0>");
	asm("st.w r1,(r0,0)");
	
	asm("nop");
}
void org_address_out_prg(void)
{
	asm  ("psrclr ie");
	//提取r14
	asm("lrw r0,R_r14_buf");
	asm("ld.w r14,(r0,0)");
	//r0,r1压栈
	asm("subi r14,4");
	asm("lrw r0,R_r0_buf");
	asm("ld.w r0,(r0,0)");
	asm("st.w r0,(r14,0)");
	asm("subi r14,4");
	asm("lrw r1,R_r1_buf");
	asm("ld.w r1,(r1,0)");
	asm("st.w r1,(r14,0)");
	//提取变量到r2~r8 r13~r15
	asm("lrw r0,R_r2_buf");
	asm("ld.w r2,(r0,0)");
	asm("lrw r0,R_r3_buf");
	asm("ld.w r3,(r0,0)");
	asm("lrw r0,R_r4_buf");
	asm("ld.w r4,(r0,0)");
	asm("lrw r0,R_r5_buf");
	asm("ld.w r5,(r0,0)");
	asm("lrw r0,R_r6_buf");
	asm("ld.w r6,(r0,0)");
	asm("lrw r0,R_r7_buf");
	asm("ld.w r7,(r0,0)");
	asm("lrw r0,R_r8_buf");
	asm("ld.w r8,(r0,0)");
	asm("lrw r0,R_r13_buf");
	asm("ld.w r13,(r0,0)");
	asm("lrw r0,R_r15_buf");
	asm("ld.w r15,(r0,0)");
	//
	asm("lrw r0,R_cr0_buf");
	asm("ld.w r1,(r0,0)");
	asm("mtcr r1,cr<0,0>");
	//
	asm("lrw r0,R_cr1_buf");
	asm("ld.w r1,(r0,0)");
	asm("mtcr r1,cr<1,0>");
	//r0,r1出栈
	asm("ld.w r1,(r14,0)");
	asm("addi r14,4");
	asm("ld.w r0,(r14,0)");
	asm("addi r14,4");
	
	asm("nop");
	
	//使能中断
	asm  ("psrset ee,ie");
}
*/

void PCLK_goto_deepsleep_mode(void)
{
	SYSCON->WKCR=(0x00<<16)|(0X5F<<8);				//选择deepSleep模式
	delay_nms(100);					//延时一定时间确保数据写入
	asm ("stop");
}  
//bit0:touch bit1:lcd
void PCLK_goto_Snooze_mode(U8_T snooze_power_set)
{
	SYSCON->WKCR=(snooze_power_set<<24)|(0X5f<<8)|(0xaa<<16);	//选择Snooze模式 
	delay_nms(10);					//延时一定时间确保数据写入
	asm ("stop");
} 
void PCLK_goto_Shutdown_mode(void)
{
	SYSCON->WKCR=(0xa5<<16)|(0Xb<<8)|0x0f;			//选择Shutdown模式
	delay_nms(10);					//延时一定时间确保数据写入
	asm ("stop");
} 


/*************************************************************/
//EXI0 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI0_Int_Enable(void)
{
	INTC_ISER_WRITE(EXI0_INT);    
}

/*************************************************************/
//EXI0 Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI0_Int_Disable(void)
{
    INTC_ICER_WRITE(EXI0_INT);    
}

/*************************************************************/
//EXI1 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI1_Int_Enable(void)
{
	INTC_ISER_WRITE(EXI1_INT);    
}

/*************************************************************/
//EXI1 Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI1_Int_Disable(void)
{
    INTC_ICER_WRITE(EXI1_INT);    
}

/*************************************************************/
//EXI2 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI2_Int_Enable(void)
{
	INTC_ISER_WRITE(EXI2_INT);    
}

/*************************************************************/
//EXI2 Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI2_Int_Disable(void)
{
    INTC_ICER_WRITE(EXI2_INT);    
}

/*************************************************************/
//EXI3 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI3_Int_Enable(void)
{
	INTC_ISER_WRITE(EXI3_INT);    
}

/*************************************************************/
//EXI3 Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI3_Int_Disable(void)
{
    INTC_ICER_WRITE(EXI3_INT);    
}

/*************************************************************/
//EXI4 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI4_Int_Enable(void)
{
	INTC_ISER_WRITE(EXI4_INT);    
}

/*************************************************************/
//EXI4 Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI4_Int_Disable(void)
{
    INTC_ICER_WRITE(EXI4_INT);    
}
/*************************************************************/
//EXI0 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI0_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(EXI0_INT);    
}

/*************************************************************/
//EXI0 Wake up disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI0_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(EXI0_INT);    
}

/*************************************************************/
//EXI1 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI1_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(EXI1_INT);    
}

/*************************************************************/
//EXI1 Wake up disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI1_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(EXI1_INT);    
}

/*************************************************************/
//EXI2 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI2_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(EXI2_INT);    
}

/*************************************************************/
//EXI2 Wake up disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI2_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(EXI2_INT);    
}

/*************************************************************/
//EXI3 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI3_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(EXI3_INT);    
}

/*************************************************************/
//EXI3 Wake up disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI3_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(EXI3_INT);    
}

/*************************************************************/
//EXI4 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI4_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(EXI4_INT);    
}

/*************************************************************/
//EXI4 Wake up disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI4_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(EXI4_INT);    
}
/*************************************************************/
//SYSCON Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SYSCON_Int_Enable(void)
{
    INTC_ISER_WRITE(SYSCON_INT);    
}

/*************************************************************/
//SYSCON Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SYSCON_Int_Disable(void)
{
    INTC_ICER_WRITE(SYSCON_INT);    
}
/*************************************************************/
//SYSCON Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SYSCON_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(SYSCON_INT);    
}
/*************************************************************/
//set PA0.0/PA0.8 as CLO output 
//EntryParameter:CLO_PC00/CLO_PA05/CLO_PB00/CLO_PA13
//ReturnValue:NONE
/*************************************************************/
void SYSCON_CLO_CONFIG(CLO_IO_TypeDef clo_io)
{
	if (clo_io==CLO_PC00)
	{
		GPIOC0->CONLR = (GPIOC0->CONLR&0XFFFFFFF0) | 0X00000007;
	}
	if (clo_io==CLO_PA05)
	{
		GPIOA0->CONLR = (GPIOA0->CONLR&0XFF0FFFFF) | 0X00700000;
	}
	if (clo_io==CLO_PB00)
	{
		GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFF0) | 0X00000007;
	}
	if (clo_io==CLO_PA13)
	{
		GPIOA1->CONLR = (GPIOA1->CONLR&0XFFFF0FFF) | 0X00007000;
	}
}
/*************************************************************/
//set CLO clk and div
//EntryParameter:clomxr/clodivr
//ReturnValue:NONE
/*************************************************************/
void SYSCON_CLO_SRC_SET(SystemClk_CLOMX_TypeDef clomxr,SystemClk_CLODIV_TypeDef clodivr)
{
	SYSCON->OPT1=(SYSCON->OPT1 & 0XFFFF80FF)|(clomxr<<8)|(clodivr<<12);
}
/*************************************************************/
//SYSCON Wake up disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SYSCON_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(SYSCON_INT);    
}
/*************************************************************/
//Software_Reset
//EntryParameter:None
//ReturnValue:MCU reset
/*************************************************************/
void SYSCON_Software_Reset(void)
{
	SYSCON->IDCCR=IDCCR_KEY|SWRST;
}
/*************************************************************/
//CPU_Reset
//EntryParameter:None
//ReturnValue:MCU CPU reset Only
/*************************************************************/
void SYSCON_CPU_Reset(void)
{
	SYSCON->IDCCR=IDCCR_KEY|CPURST;
}
/*************************************************************/
//Debug io lock
//EntryParameter:None
//ReturnValue:
/*************************************************************/
void Debug_IO_lock(void)		//默认锁定
{
	SYSCON->DBGCR=0X00;
}
void Debug_IO_release(void)
{
	SYSCON->DBGCR=0X5a;
}
/*************************************************************/
//Interrupt Priority initial
//EntryParameter:00/40/80/C0
//----------------------
//CORET_INT   IRQ0
//SYSCON_INT  IRQ1
//IFC_INT     IRQ2
//ADC_INT     IRQ3
//----------------------
//EPT0_INT    IRQ4
//DMA_INT     IRQ5
//WWDT_INT    IRQ6
//EXI0_INT    IRQ7
//----------------------
//EXI1_INT    IRQ8
//GPTA0_INT   IRQ9 
//GPTAA_INT   IRQ10
//GPTB0_INT   IRQ11
//----------------------
//RTC_INT     IRQ12
//UART0_INT   IRQ13
//UART1_INT   IRQ14
//UART2_INT   IRQ15
//----------------------
//USART0_INT   RQ16
//GPTB1_INT    IRQ17
//SIO_INT      IRQ18
//I2C_INT      IRQ19
//----------------------
//SPI_INT     IRQ20
//EXI2_INT    IRQ21
//EXI3_INT    IRQ22
//EXI4_INT    IRQ23
//----------------------
//CA_INT      IRQ24
//TKEY_INT    IRQ25
//LPT_INT     IRQ26
//LED_INT     IRQ27
//----------------------
//CMP_INT     IRQ28
//BT0_INT     IRQ29
//BT1_INT     IRQ30
//LCD_INT     IRQ31
//----------------------
//ReturnValue:None
//00:Priority 0		highest
//40:Priority 1
//80:Priority 2
//C0:Priority 3		lowest
/*************************************************************/
void SYSCON_INT_Priority(void)
{
	INTC_IPR0_WRITE(0XC0C0C0C0);   //IQR0-3  low bit-->high bit
	INTC_IPR1_WRITE(0XC0C0C0C0);   //IQR4-7  
	INTC_IPR2_WRITE(0XC0C0C0C0);   //IQR8-11  
	INTC_IPR3_WRITE(0XC0C0C0C0);   //IQR12-15  
	INTC_IPR4_WRITE(0XC0C0C0C0);   //IQR16-19  
	INTC_IPR5_WRITE(0XC0C0C0C0);   //IQR20-23 
	INTC_IPR6_WRITE(0XC0C0C0C0);   //IQR24-27  
	INTC_IPR7_WRITE(0XC0C0C0C0);   //IQR28-31
}
/*************************************************************/
//Set Interrupt Priority
//EntryParameter:
//int_name:CORET_IRQ~BT1_IRQ
//int_level:0~3  0=highest   3=lowest
//ReturnValue:None
/*************************************************************/
void Set_INT_Priority(U8_T int_name,U8_T int_level)
{
	U8_T i_temp,j_temp;
	U32_T k_temp;
	i_temp=(int_name%4)*8;
	j_temp=int_name/4;
	k_temp=CK802 -> IPR[j_temp]&(~(0xff<<i_temp));
	CK802 -> IPR[j_temp]=k_temp|((int_level*0x40)<<(i_temp));
}
/*************************************************************/
//IO REMAP
//EntryParameter:
//G1.0=PA0.14,G1.1=PA0.15,G1.2=PB0.3,G1.3=PC0.1,G1.4=PB0.4,G1.5=PA1.0,G1.6=PA1.1,G1.7=PA1.2
//G2.0=PA0.0,G2.1=PA0.1,G2.2=PA0.2,G2.3=PA0.3,G2.4=PA0.4,G2.5=PA0.5,G2.6=PB0.6,G2.7=PB0.7
//GROUP1:0x00=I2C_SCL 0X01=I2C_SDA 0X02=USART0_TX 0X03=USART0_RX
//0X04=SPI_NSS 0X05=SPI_SCK 0X06=SPI_MISO 0X07=SPI_MOSI
//GROUP2:0x00=USART0_TX 0X01=USART0_RX 0X02=USART0_SCK 0X03=UART_TX
//0X04=UART_RX 0X05=GPTA0_CHA 0X06=GPTA1_CHA 0X07=CMP0_OUT
//ReturnValue:NONE
/*************************************************************/
void GPIO_Remap(IOMAP_TypeDef IOMAP_NUM,IOMAP_DIR_TypeDef iomap_data)
{
	U8_T i;
	if(iomap_data&0x10)
	{
		iomap_data=iomap_data&0X0F;
		if(iomap_data==0)
		{
			for(i=0;i<28;i+=4)
			{
				if((SYSCON->IOMAP1&(0xf<<i))==0)
				{
					SYSCON->IOMAP1=SYSCON->IOMAP1|(0xf<<i);
				}
			}
		}
		if(IOMAP_NUM==10){SYSCON->IOMAP1=(SYSCON->IOMAP1&0xfffffff0)|iomap_data;GPIOA0->CONHR =(GPIOA0->CONHR&0XF0FFFFFF) | 0x0B000000;}			//G2.0
		if(IOMAP_NUM==11){SYSCON->IOMAP1=(SYSCON->IOMAP1&0xffffff0f)|(iomap_data<<4);GPIOA0->CONHR =(GPIOA0->CONHR&0X0FFFFFFF) | 0xB0000000;}		//G2.1
		if(IOMAP_NUM==12){SYSCON->IOMAP1=(SYSCON->IOMAP1&0xfffff0ff)|(iomap_data<<8);GPIOB0->CONLR =(GPIOB0->CONLR&0XFFFF0FFF) | 0x0000B000;}		//G2.2
		if(IOMAP_NUM==13){SYSCON->IOMAP1=(SYSCON->IOMAP1&0xffff0fff)|(iomap_data<<12);GPIOC0->CONLR =(GPIOC0->CONLR&0XFFFFFF0F) | 0x000000B0;}		//G2.3
		if(IOMAP_NUM==14){SYSCON->IOMAP1=(SYSCON->IOMAP1&0xfff0ffff)|(iomap_data<<16);GPIOB0->CONLR =(GPIOB0->CONLR&0XFFF0FFFF) | 0x000B0000;}		//G2.4
		if(IOMAP_NUM==15){SYSCON->IOMAP1=(SYSCON->IOMAP1&0xff0fffff)|(iomap_data<<20);GPIOA1->CONLR =(GPIOA1->CONLR&0XFFFFFFF0) | 0x0000000B;}		//G2.5
		if(IOMAP_NUM==16){SYSCON->IOMAP1=(SYSCON->IOMAP1&0xf0ffffff)|(iomap_data<<24);GPIOA1->CONLR =(GPIOA1->CONLR&0XFFFFFF0F) | 0x000000B0;}		//G2.6
		if(IOMAP_NUM==17){SYSCON->IOMAP1=(SYSCON->IOMAP1&0x0fffffff)|(iomap_data<<28);GPIOA1->CONLR =(GPIOA1->CONLR&0XFFFFF0FF) | 0x00000B00;}		//G2.7
	}
	else
	{
		if(iomap_data==0)
		{
			for(i=0;i<28;i+=4)
			{
			if((SYSCON->IOMAP0&(0xf<<i))==0)
				{
					SYSCON->IOMAP0=SYSCON->IOMAP0|(0xf<<i);
				}
			}
		}
		if(IOMAP_NUM==0){SYSCON->IOMAP0=(SYSCON->IOMAP0&0xfffffff0)|iomap_data;GPIOA0->CONLR =(GPIOA0->CONLR&0XFFFFFFF0) | 0x0000000B;}			//G1.0
		if(IOMAP_NUM==1){SYSCON->IOMAP0=(SYSCON->IOMAP0&0xffffff0f)|(iomap_data<<4);GPIOA0->CONLR =(GPIOA0->CONLR&0XFFFFFF0F) | 0x000000B0;}		//G1.1
		if(IOMAP_NUM==2){SYSCON->IOMAP0=(SYSCON->IOMAP0&0xfffff0ff)|(iomap_data<<8);GPIOA0->CONLR =(GPIOA0->CONLR&0XFFFFF0FF) | 0x00000B00;}		//G1.2
		if(IOMAP_NUM==3){SYSCON->IOMAP0=(SYSCON->IOMAP0&0xffff0fff)|(iomap_data<<12);GPIOA0->CONLR =(GPIOA0->CONLR&0XFFFF0FFF) | 0x0000B000;}		//G1.3
		if(IOMAP_NUM==4){SYSCON->IOMAP0=(SYSCON->IOMAP0&0xfff0ffff)|(iomap_data<<16);GPIOA0->CONLR =(GPIOA0->CONLR&0XFFF0FFFF) | 0x000B0000;}		//G1.4
		if(IOMAP_NUM==5){SYSCON->IOMAP0=(SYSCON->IOMAP0&0xff0fffff)|(iomap_data<<20);GPIOA0->CONLR =(GPIOA0->CONLR&0XFF0FFFFF) | 0x00B00000;}		//G1.5
		if(IOMAP_NUM==6){SYSCON->IOMAP0=(SYSCON->IOMAP0&0xf0ffffff)|(iomap_data<<24);GPIOA0->CONLR =(GPIOA0->CONLR&0XF0FFFFFF) | 0x0B000000;}		//G1.6
		if(IOMAP_NUM==7){SYSCON->IOMAP0=(SYSCON->IOMAP0&0x0fffffff)|(iomap_data<<28);GPIOA0->CONLR =(GPIOA0->CONLR&0X0FFFFFFF) | 0x0B0000000;}		//G1.7
	}
}




/*********************************************************************** 
//						 END OF FILE         
***********************************************************************/