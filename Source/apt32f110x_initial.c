/*
  ******************************************************************************
  * @file    apt32f110_initial.c
  * @author  APT SZ AE Team
  * @version V1.05
  * @date    2022/12/28
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

/* Define to prevent recursive inclusion -------------------------------------*/ 

/****************************************************
//include
*****************************************************/
#include "apt32f110x.h"
#include "apt32f110x_adc.h"
#include "apt32f110x_bt.h"
#include "apt32f110x_coret.h"
#include "apt32f110x_countera.h"
#include "apt32f110x_crc.h"
#include "apt32f110x_ept.h"
#include "apt32f110x_etcb.h"
#include "apt32f110x_gpio.h"
#include "apt32f110x_gpt.h"
#include "apt32f110x_i2c.h"
#include "apt32f110x_ifc.h"
#include "apt32f110x_lpt.h"
#include "apt32f110x_rtc.h"
#include "apt32f110x_sio.h"
#include "apt32f110x_spi.h"
#include "apt32f110x_syscon.h"
#include "apt32f110x_uart.h"
#include "apt32f110x_usart.h"
#include "apt32f110x_wwdt.h"
#include "apt32f110x_lcd.h"
#include "apt32f110x_led.h"
#include "apt32f110x_types_local.h"
#include "apt32f110x_lcd.h"
#include "apt32f110x_cmp.h"
#include "apt32f110x_dma.h"
#include "tkey.h"
/*************************************************************
//define
**************************************************************/
U8_T Lcd_data_buf[32]={0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
					   0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
					   0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
					   0XFF,0XFF};
/*************************************************************
//externs
**************************************************************/

/*************************************************************/
//software delay
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/	
void delay_nms(unsigned int t)
{
    volatile unsigned int i,j ,k=0;
    j = 50* t;
    for ( i = 0; i < j; i++ )
    {
        k++;
		SYSCON_IWDCNT_Reload(); 
    }
}
void delay_nus(unsigned int t)
{
    volatile unsigned int i,j ,k=0;
    j = 1* t;
    for ( i = 0; i < j; i++ )
    {
        k++;
    }
}
/*************************************************************/
//GPIO Initial
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/	
void GPIO_CONFIG(void)
{
	//GPIO_Init(GPIOC0,0,0);				//initial GPIOC0.0 output
	//GPIO_Write_High(GPIOC0,0);			//GPIOC0.0 set high
	//GPIO_Write_Low(GPIOC0,0);				//GPIOC0.0 set low
	//GPIO_Set_Value(GPIOC0,0,1);			//GPIOC0.0 set high
	//GPIO_Set_Value(GPIOC0,0,0);			//GPIOC0.0 set low
	
	//GPIO_Init(GPIOA0,0,1);				//initial GPIOA0.0 input
	
	//GPIO_OpenDrain_EN(GPIOA0,3);			//initial GPIOA0.3 open drain
	//GPIO_PullHigh_Init(GPIOA0,0);			//initial GPIOA0.0 pull high
	//GPIO_PullLow_Init(GPIOB0,0);			//initial GPIOB0.0 pull low
	
	//GPIO_PullHighLow_DIS(GPIOA0,2);		//disable GPIOA0.2 pull high and pull low
//------------  EXI FUNTION  --------------------------------/
//EXI0_INT= EXI0/EXI16,EXI1_INT= EXI1/EXI17, EXI2_INT=EXI2~EXI3/EXI18/EXI19, EXI3_INT=EXI4~EXI9, EXI4_INT=EXI10~EXI15    
	GPIO_IntGroup_Set(PA0,0,Selete_EXI_PIN0);					//PA0.0 set as EXI0  
	GPIOA0_EXI_Init(EXI0);                                   	//PA0.0 set as input
	EXTI_trigger_CMD(ENABLE,EXI_PIN0,_EXIFT);                   //ENABLE falling edge
	EXTI_trigger_CMD(ENABLE,EXI_PIN0,_EXIRT);                   //ENABLE rising edge
    EXTI_interrupt_CMD(ENABLE,EXI_PIN0);                	   	//enable EXI
    GPIO_EXTI_interrupt(GPIOA0,0b0000000000000001);				//enable GPIOA0.0 as EXI
	
	GPIO_IntGroup_Set(PB0,0,Selete_EXI_PIN18);					//PB0.0 set as EXI18 same pin number
	GPIO_Init(GPIOB0,0,1);										//PB0.0 set as input                                	
	EXTI_trigger_CMD(ENABLE,EXI_PIN18,_EXIFT);                  //ENABLE falling edge
	//EXTI_trigger_CMD(ENABLE,EXI_PIN0,_EXIRT);                 //ENABLE rising edge
    EXTI_interrupt_CMD(ENABLE,EXI_PIN18);                	   	//enable EXI
    GPIO_EXTI_interrupt(GPIOB0,0b0000000000000001);				//enable GPIOB0.0 as EXI
	
	EXI0_Int_Enable();                                         	//EXI0 / EXI16 INT Vector
    //EXI1_Int_Enable();                                       	//EXI1 / EXI17 INT Vector
    EXI2_Int_Enable();                                       	//EXI2~EXI3 / EXI18~19 INT Vector
    //EXI3_Int_Enable();                                       	//EXI4~EXI9 INT Vector
    //EXI4_Int_Enable();                                       	//EXI10~EXI15 INT Vector
	
    //EXI0_WakeUp_Enable();										//EXI0 interrupt wake up enable
	//EXI1_WakeUp_Enable();										//EXI1 interrupt wake up enable
	//EXI2_WakeUp_Enable();										//EXI2~EXI3 interrupt wake up enable
	//EXI3_WakeUp_Enable();										//EXI4~EXI9 interrupt wake up enable
	//EXI4_WakeUp_Enable();										//EXI10~EXI15 interrupt wake up enable
}
/*************************************************************/
//CORET Functions
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void CORET_CONFIG(void)
{
	CORET_DeInit();										//coret deintial
	SYSCON_General_CMD(ENABLE,ENDIS_SYSTICK);			//enable coret systick
	CK802->CORET_RVR=59999;								//CORETCLK=sysclock/8=48M/8=6Mhz  e.g:10ms=(CORET_RVR+1)*(8/48M);CORET_RVR=60000-1=59999
	CORET_reload();										//Clear coret counter and flag					
	CORET_CLKSOURCE_EX();								//use ex clock
	CORET_TICKINT_Enable();								//clear CORET counter
	CORET_start();										//coret start
	CORET_Int_Enable();									//coret int enable
	//CORET_WakeUp_Enable();							//coret wakeup enable		 
}
/*************************************************************/
//ETP0 Functions
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void EPT0_CONFIG(void)
{
	EPT_Software_Reset();								//EPT software reset
//------------  EPT GPIO Setting  --------------------------------/
	EPT_IO_SET(EPT_IO_CHAX,IO_NUM_PA1_3);				//EPT CHAX Selection
	EPT_IO_SET(EPT_IO_CHAY,IO_NUM_PA1_0);				//EPT CHAY Selection
	EPT_IO_SET(EPT_IO_CHBX,IO_NUM_PA1_4);				//EPT CHBX Selection
	EPT_IO_SET(EPT_IO_CHBY,IO_NUM_PA1_1);				//EPT CHBY Selection
	EPT_IO_SET(EPT_IO_CHCX,IO_NUM_PA1_5);				//EPT CHCX Selection
	EPT_IO_SET(EPT_IO_CHCY,IO_NUM_PA1_2);				//EPT CHCY Selection
	EPT_IO_SET(EPT_IO_CHD,IO_NUM_PA1_6);				//EPT CHD Selection
	
	//EPT_IO_SET(EPT_IO_EBI,EBI0_IO_PA0_9);				//EBI0 Selection
	//EPT_IO_SET(EPT_IO_EBI,EBI0_IO_PB0_4);				//EBI1 Selection
	//EPT_IO_SET(EPT_IO_EBI,EBI0_IO_PA1_4);				//EBI2 Selection
	//EPT_IO_SET(EPT_IO_EBI,EBI0_IO_PA1_5);				//EBI3 Selection
//------------  EPT Control  --------------------------------/
	EPT_PWM_Config(EPT_Selecte_PCLK,EPT_CNTMD_increase,EPT_OPM_Continue,0);//PCLK as clock，increasing mode,continuous mode,TCLK=PCLK/(0+1) 
	//EPT_Tevent_Selecte(0x00,0x00);				//T1 source selection SYNCIN4,T2 source selection SYNCIN5
	//EPT_SYNCR_Config(0x00,EPT_SYNCUSR0_REARMTrig_DIS,EPT_TRGSRC0_ExtSync_SYNCUSR0,EPT_TRGSRC1_ExtSync_SYNCUSR4,0x3f);//enable SYNCUSR4 SYNCUSR5 as trigger event,continuous mode
	EPT_PWMX_Output_Control(EPT_PWMA,EPT_CA_Selecte_CMPA,EPT_CB_Selecte_CMPA,EPT_PWM_ZRO_Event_OutHigh,EPT_PWM_PRD_Event_Nochange,EPT_PWM_CAU_Event_OutLow,EPT_PWM_CAD_Event_OutLow,
							EPT_PWM_CBU_Event_Nochange,EPT_PWM_CBD_Event_Nochange,EPT_PWM_T1U_Event_Nochange,EPT_PWM_T1D_Event_Nochange,EPT_PWM_T2U_Event_Nochange,EPT_PWM_T2D_Event_Nochange);
	EPT_PWMX_Output_Control(EPT_PWMB,EPT_CA_Selecte_CMPB,EPT_CB_Selecte_CMPB,EPT_PWM_ZRO_Event_OutHigh,EPT_PWM_PRD_Event_Nochange,EPT_PWM_CAU_Event_OutLow,EPT_PWM_CAD_Event_OutLow,
							EPT_PWM_CBU_Event_Nochange,EPT_PWM_CBD_Event_Nochange,EPT_PWM_T1U_Event_Nochange,EPT_PWM_T1D_Event_Nochange,EPT_PWM_T2U_Event_Nochange,EPT_PWM_T2D_Event_Nochange);						
	EPT_PWMX_Output_Control(EPT_PWMC,EPT_CA_Selecte_CMPC,EPT_CB_Selecte_CMPC,EPT_PWM_ZRO_Event_OutHigh,EPT_PWM_PRD_Event_Nochange,EPT_PWM_CAU_Event_OutLow,EPT_PWM_CAD_Event_OutLow,
							EPT_PWM_CBU_Event_Nochange,EPT_PWM_CBD_Event_Nochange,EPT_PWM_T1U_Event_Nochange,EPT_PWM_T1D_Event_Nochange,EPT_PWM_T2U_Event_Nochange,EPT_PWM_T2D_Event_Nochange);	
	EPT_PWMX_Output_Control(EPT_PWMD,EPT_CA_Selecte_CMPD,EPT_CB_Selecte_CMPD,EPT_PWM_ZRO_Event_OutHigh,EPT_PWM_PRD_Event_Nochange,EPT_PWM_CAU_Event_OutLow,EPT_PWM_CAD_Event_OutLow,
							EPT_PWM_CBU_Event_Nochange,EPT_PWM_CBD_Event_Nochange,EPT_PWM_T1U_Event_Nochange,EPT_PWM_T1D_Event_Nochange,EPT_PWM_T2U_Event_Nochange,EPT_PWM_T2D_Event_Nochange);		
	EPT_PRDR_CMPA_CMPB_CMPC_CMPD_Config(4800,2400,1200,600,0);//PRDR=4800,CMPA=2400,CMPB=1200,CMPC=600,CMPD=0	
	EPT_DB_CLK_Config(0,24,24);//Fdbclk=Fhclk/(0+1)，DTR=24clk，DTF=24clk
	EPT_DBCR_Config(EPT_CHA_Selecte,EPT_CHAINSEL_PWMA_RISE_FALL,EPT_CHA_OUTSEL_EnRise_EnFall,EPT_PB_OUT_Reverse,EPT_PAtoCHX_PBtoCHY);//PWMA Complementary,CHX rising edge,CHY falling edge		
	EPT_DBCR_Config(EPT_CHB_Selecte,EPT_CHBINSEL_PWMB_RISE_FALL,EPT_CHB_OUTSEL_EnRise_EnFall,EPT_PB_OUT_Reverse,EPT_PAtoCHX_PBtoCHY);//PWMB Complementary,CHX rising edge,CHY falling edge		
	EPT_DBCR_Config(EPT_CHC_Selecte,EPT_CHCINSEL_PWMC_RISE_FALL,EPT_CHC_OUTSEL_EnRise_EnFall,EPT_PB_OUT_Reverse,EPT_PAtoCHX_PBtoCHY);//PWMC Complementary,CHX rising edge,CHY falling edge
	//EPT_CG_gate_Config(EPT_CGSRC_CHBX,0,0,EPT_BURST_ENABLE);//CG选择BT0OUT为输入源，CFFLT=PLCK/(0+1),滤波次数Bypass
	//EPT_CPCR_Config(0X3F,EPT_CPCR_Source_TCLK,EPT_CDUTY_7_8,3,5);//使能CHAX~CHCY斩波输出，TCLK为CPCR时钟源，duty为7/8，起始头为3*Tchop，Fchop=pclk/((5+1)*8)
//------------  EPT0 REG LINK  ----------------------------------/	
	//EPT_REG_LINK_CONFIG(EPT_LinkREG_PRDR,EPT0_GPTA0_LINK);//EPT0->PRDR链接到GPTA0->PRDR
	//EPT_REG_LINK_CONFIG(EPT_LinkREG_CMPA,EPT0_GPTA0_LINK);//EPT0->PRDR链接到GPTA0->CMPA
	//EPT_REG_LINK_CONFIG(EPT_LinkREG_CMPB,EPT0_GPTA0_LINK);//EPT0->PRDR链接到GPTA0->CMPB
	//EPT_REG_LINK_CONFIG(EPT_LinkREG_RSSR,EPT0_GPTA0_LINK);//EPT0->RSSR链接到GPTA0->RSSR
//------------  EPT EM Config	----------------------------------/
	//EPT_EPX_Config(EPT_EP0,EPT_Input_selecte_EBI0,EPT_FLT_PACE0_DIS,EPT_FLT_PACE1_DIS,0,0);//EP0选择EBI0作为输入，EP0~EP3禁止滤波，EP4~EP7禁止滤波
	//EPT_EPX_Config(EPT_EP1,EPT_Input_selecte_EBI1,EPT_FLT_PACE0_DIS,EPT_FLT_PACE1_DIS,0,0);//EP0选择EBI1作为输入，EP0~EP3禁止滤波，EP4~EP7禁止滤波
	//EPT_EPX_Config(EPT_EP2,EPT_Input_selecte_EBI2,EPT_FLT_PACE0_DIS,EPT_FLT_PACE1_DIS,0,0);//EP0选择EBI2作为输入，EP0~EP3禁止滤波，EP4~EP7禁止滤波
	//EPT_EPX_Config(EPT_EP3,EPT_Input_selecte_EBI3,EPT_FLT_PACE0_DIS,EPT_FLT_PACE1_DIS,0,0);//EP0选择EBI3作为输入，EP0~EP3禁止滤波，EP4~EP7禁止滤波
	
	//EPT_EBIX_POL_Config(0X1F);//active low
	//EPT_LKCR_TRG_Config(EPT_LKCR_TRG_EP0,EPT_LKCR_Mode_HLOCK_EN);//EP0 hard lock
	//EPT_LKCR_TRG_Config(EPT_LKCR_TRG_EP1,EPT_LKCR_Mode_SLOCK_EN);//EP1 hard lock
	//EPT_LKCR_TRG_Config(EPT_LKCR_TRG_EP2,EPT_LKCR_Mode_SLOCK_EN);//EP2 hard lock
	//EPT_LKCR_TRG_Config(EPT_LKCR_TRG_EP3,EPT_LKCR_Mode_SLOCK_EN);//EP3 hard lock
	//EPT_LKCR_TRG_Config(EPT_LKCR_TRG_EP4,EPT_LKCR_Mode_SLOCK_EN);//EP4 hard lock
	//EPT_LKCR_TRG_Config(EPT_LKCR_TRG_EP5,EPT_LKCR_Mode_SLOCK_EN);//EP5 hard lock
	//EPT_LKCR_TRG_Config(EPT_LKCR_TRG_EP6,EPT_LKCR_Mode_SLOCK_EN);//EP6 hard lock
	//EPT_LKCR_TRG_Config(EPT_LKCR_TRG_EP7,EPT_LKCR_Mode_SLOCK_EN);//EP7 hard lock
	
	//EPT_SHLOCK_OUTPUT_Config(EPT_OUTPUT_Channel_CHAX,EPT_SHLOCK_OUTPUT_HImpedance); //产生锁止后CHAX高组态
	//EPT_SHLOCK_OUTPUT_Config(EPT_OUTPUT_Channel_CHAY,EPT_SHLOCK_OUTPUT_HImpedance); //产生锁止后CHAY高组态
	//EPT_SHLOCK_OUTPUT_Config(EPT_OUTPUT_Channel_CHBX,EPT_SHLOCK_OUTPUT_HImpedance); //产生锁止后CHBX高组态
	//EPT_SHLOCK_OUTPUT_Config(EPT_OUTPUT_Channel_CHBY,EPT_SHLOCK_OUTPUT_HImpedance); //产生锁止后CHBY高组态
	//EPT_SHLOCK_OUTPUT_Config(EPT_OUTPUT_Channel_CHCX,EPT_SHLOCK_OUTPUT_HImpedance); //产生锁止后CHCX高组态
	//EPT_SHLOCK_OUTPUT_Config(EPT_OUTPUT_Channel_CHCY,EPT_SHLOCK_OUTPUT_HImpedance); //产生锁止后CHCY高组态
	//EPT_SHLOCK_OUTPUT_Config(EPT_OUTPUT_Czuotiahannel_CHD,EPT_SHLOCK_OUTPUT_HImpedance);  //产生锁止后CHD高组态
//------------  EPT EM interruption  -----------------------------/
	//EPT_EMInt_Enable(EPT_EP0_EMINT);	
	//EPT_EMInt_Enable(EPT_EP1_EMINT);	
	//EPT_EMInt_Enable(EPT_EP2_EMINT);	
	//EPT_EMInt_Enable(EPT_EP3_EMINT);	
	//EPT_EMInt_Enable(EPT_EP4_EMINT);	
	//EPT_EMInt_Enable(EPT_EP5_EMINT);	
	//EPT_EMInt_Enable(EPT_EP6_EMINT);	
	//EPT_EMInt_Enable(EPT_EP7_EMINT);
//------------  EPT TRGSRC interruption  -----------------------------/	
	//EPT_TRGSRCX_Config(EPT_TRGSRC0,EPT_EVTRG_TRGSRCX_CMPAU,EPT_TRGSRCX_EN,0);//选择CMPAU作为TRGSRC0事件源，事件计数CNT=0
	//EPT_TRGSRCX_Config(EPT_TRGSRC1,EPT_EVTRG_TRGSRCX_CMPBU,EPT_TRGSRCX_EN,0);//选择CMPBU作为TRGSRC1事件源，事件计数CNT=0
	//EPT_TRGSRCX_Config(EPT_TRGSRC2,EPT_EVTRG_TRGSRCX_CMPCU,EPT_TRGSRCX_EN,0);//选择CMPCU作为TRGSRC2事件源，事件计数CNT=0
	//EPT_TRGSRCX_Config(EPT_TRGSRC3,EPT_EVTRG_TRGSRCX_CMPDU,EPT_TRGSRCX_EN,0);//选择CMPDU作为TRGSRC3事件源，事件计数CNT=0
//------------  EPT interruption  --------------------------------/
	//EPT_Int_Enable(EPT_CAP_LD0);//CMPA load interrupt
	//EPT_Int_Enable(EPT_CAP_LD1);//CMPB load interrupt
	//EPT_Int_Enable(EPT_CAP_LD2);//CMPC load interrupt
	//EPT_Int_Enable(EPT_CAP_LD3);//CMPD load interrupt	
	//EPT_Int_Enable(EPT_CAU);//Up-Counting phase CNT = CMPA interrupt request raw status
	//EPT_Int_Enable(EPT_CAD);//Down-Counting phase CNT = CMPA interrupt request raw statu
	//EPT_Int_Enable(EPT_CBU);//Up-Counting phase CNT = CMPB interrupt request raw status
	//EPT_Int_Enable(EPT_CBD);//Down-Counting phase CNT = CMPB interrupt request raw status
	//EPT_Int_Enable(EPT_CCU);//Up-Counting phase CNT = CMPC interrupt request raw status
	//EPT_Int_Enable(EPT_CCD);//Down-Counting phase CNT = CMPC interrupt request raw status
	//EPT_Int_Enable(EPT_CDU);//Up-Counting phase CNT = CMPD interrupt request raw status
	//EPT_Int_Enable(EPT_CDD);//Down-Counting phase CNT = CMPD interrupt request raw status
	//EPT_Int_Enable(EPT_PEND);//End of cycle interrupt request raw status
	//EPT_Int_Enable(EPT_TRGEV0_INT);//TRGEV0
	//EPT_Int_Enable(EPT_TRGEV1_INT);//TRGEV1
	//EPT_Int_Enable(EPT_TRGEV2_INT);//TRGEV2
	//EPT_Int_Enable(EPT_TRGEV3_INT);//TRGEV3
	//EPT_Vector_Int_Enable();
//------------  EPT start  --------------------------------/	
	EPT_Start();
//------------  EPT capture config  --------------------------------/
	/*EPT_Software_Reset();
	EPT_Capture_Config(EPT_Selecte_PCLK,EPT_CNTMD_increase,EPT_CAPMD_Continue,EPT_CAP_EN,EPT_LDARST_EN,EPT_LDBRST_DIS,EPT_LDCRST_DIS,EPT_LDDRST_DIS,1,0);//TCLK=pclk/(1+0),CMPAload CMPBload
	EPT_SYNCR_Config(EPT_Triggle_Continue,EPT_SYNCUSR0_REARMTrig_DIS,EPT_TRGSRC0_ExtSync_SYNCUSR0,EPT_TRGSRC1_ExtSync_SYNCUSR4,0x04);//Enable SYNCUSR2 ,Continuous trigger
	EPT_PRDR_CMPA_CMPB_CMPC_CMPD_Config(0XFFFF,0,0,0,0);
	EPT_Int_Enable(EPT_CAP_LD0);//Capture Load to CMPA interrupt request raw status
	EPT_Int_Enable(EPT_CAP_LD1);//Capture Load to CMPB interrupt request raw status
	EPT_Vector_Int_Enable();
	EPT_Start();*/
}
/*************************************************************/
//GPTA0 Functions
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void GPTA0_CONFIG(void)
{
	GPT_Soft_Reset(GPTA0);								//GPTA0 software reset
//------------  GPTA0 GPIO Setting  --------------------------------/
	GPTA0_IO_Init(GPTA0_CHA_PA0_9);		
	GPTA0_IO_Init(GPTA0_CHB_PA0_10);			
//------------  GPTA0 Control  --------------------------------/
	GPT_PWM_Config(GPTA0,GPT_Selecte_PCLK,GPT_CNTMD_increase,GPT_OPM_Continue,0);//PCLK as clock，increasing mode,continuous mode,TCLK=PCLK/(0+1)	
	//GPT_SYNCR_Config(GPTA0,0x00,GPT_SYNCUSR0_REARMTrig_DIS,GPT_TRGSRC0_ExtSync_SYNCUSR0,GPT_TRGSRC1_ExtSync_SYNCUSR4,0x3f);//enable SYNCUSR4 SYNCUSR5 as trigger event,continuous mode					
	GPT_PWMX_Output_Control(GPTA0,GPT_PWMA,EPT_CA_Selecte_CMPA,GPT_CB_Selecte_CMPA,GPT_PWM_ZRO_Event_OutHigh,GPT_PWM_PRD_Event_Nochange,GPT_PWM_CAU_Event_OutLow,GPT_PWM_CAD_Event_OutLow,
							GPT_PWM_CBU_Event_Nochange,GPT_PWM_CBD_Event_Nochange,GPT_PWM_T1U_Event_Nochange,GPT_PWM_T1D_Event_Nochange,GPT_PWM_T2U_Event_Nochange,GPT_PWM_T2D_Event_Nochange);
	GPT_PWMX_Output_Control(GPTA0,GPT_PWMB,GPT_CA_Selecte_CMPB,GPT_CB_Selecte_CMPB,GPT_PWM_ZRO_Event_OutHigh,GPT_PWM_PRD_Event_Nochange,GPT_PWM_CAU_Event_OutLow,GPT_PWM_CAD_Event_OutLow,
							GPT_PWM_CBU_Event_Nochange,GPT_PWM_CBD_Event_Nochange,GPT_PWM_T1U_Event_Nochange,GPT_PWM_T1D_Event_Nochange,GPT_PWM_T2U_Event_Nochange,GPT_PWM_T2D_Event_Nochange);
	GPT_PRDR_CMPA_CMPB_Config(GPTA0,4800,2400,1200);//PRDR=4800,CMPA=2400,CMPB=1200
	//GPT_CG_gate_Config(GPTA0,GPT_CGSRC_CHAX,0,0,GPT_BURST_ENABLE);//CG选择CHAX为输入源，CFFLT=PLCK/(0+1),滤波次数Bypass	
//------------  GPTA0 REG LINK  ----------------------------------/		
	//GPT_REG_LINK_CONFIG(GPTA0,GPT_LinkREG_PRDR,GPT_DIS_LINK);//GPTA0->PRDR不链接
	//GPT_REG_LINK_CONFIG(GPTA0,GPT_LinkREG_CMPA,GPT_DIS_LINK);//GPTA0->CMPA不链接
	//GPT_REG_LINK_CONFIG(GPTA0,GPT_LinkREG_CMPB,GPT_DIS_LINK);//GPTA0->CMPB不链接
	//GPT_REG_LINK_CONFIG(GPTA0,GPT_LinkREG_RSSR,GPT_DIS_LINK);//GPTA0->RSSR不链接
//------------  GPTA0 TRGSRC interruption  -----------------------------/	
	//GPT_TRGSRCX_Config(GPTA0,GPT_TRGSRC0,GPT_EVTRG_TRGSRCX_CMPAU,GPT_TRGSRCX_EN,0);//选择CMPAU作为TRGSRC0事件源，事件计数CNT=0
	//GPT_TRGSRCX_Config(GPTA0,GPT_TRGSRC1,GPT_EVTRG_TRGSRCX_CMPBU,GPT_TRGSRCX_EN,0);//选择CMPBU作为TRGSRC1事件源，事件计数CNT=0	
//------------  GPT interruption  --------------------------------/	
	//GPT_Int_Enable(GPTA0,GPT_CAP_LD0);//CMPA load interrupt
	//GPT_Int_Enable(GPTA0,GPT_CAP_LD1);//CMPB load interrupt
	//GPT_Int_Enable(GPTA0,GPT_CAU);//Up-Counting phase CNT = CMPA interrupt request raw status
	//GPT_Int_Enable(GPTA0,GPT_CAD);//Down-Counting phase CNT = CMPA interrupt request raw statu
	//GPT_Int_Enable(GPTA0,GPT_CBU);//Up-Counting phase CNT = CMPB interrupt request raw status
	//GPT_Int_Enable(GPTA0,GPT_CBD);//Down-Counting phase CNT = CMPB interrupt request raw status
	//GPT_Int_Enable(GPTA0,GPT_PEND);//End of cycle interrupt request raw status
	//GPT_Int_Enable(GPTA0,GPT_TRGEV0_INT);//TRGEV0
	//GPT_Int_Enable(GPTA0,GPT_TRGEV1_INT);//TRGEV1
	//GPTA0_Vector_Int_Enable();
//------------  GPTA0 start  --------------------------------/	
	GPT_Start(GPTA0);
//------------  GPTA0 capture config  --------------------------------/
	/*GPT_Soft_Reset(GPTA0);
	GPT_Capture_Config(GPTA0,GPT_Selecte_PCLK,GPT_CNTMD_increase,GPT_CAPMD_Continue,GPT_CAP_EN,GPT_LDARST_EN,GPT_LDBRST_DIS,1,0);//TCLK=pclk/(1+0),CMPAload CMPBload
	GPT_SYNCR_Config(GPTA0,GPT_Triggle_Continue,GPT_SYNCUSR0_REARMTrig_DIS,GPT_TRGSRC0_ExtSync_SYNCUSR0,GPT_TRGSRC1_ExtSync_SYNCUSR4,0x04);//Enable SYNCUSR2 ,Continuous trigger
	GPT_PRDR_CMPA_CMPB_Config(GPTA0,0XFFFFFF,0,0);
	GPT_Int_Enable(GPTA0,GPT_CAP_LD0);//Capture Load to CMPA interrupt request raw status
	GPT_Int_Enable(GPTA0,GPT_CAP_LD1);//Capture Load to CMPB interrupt request raw status
	GPTA0_Vector_Int_Enable();
	GPT_Start(GPTA0);*/
}
/*************************************************************/
//GPTA1 Functions
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void GPTA1_CONFIG(void)
{
	GPT_Soft_Reset(GPTA1);								//GPTA0 software reset
//------------  GPTA1 GPIO Setting  --------------------------------/
	GPTA1_IO_Init(GPTA1_CHA_PA0_11);		
	GPTA1_IO_Init(GPTA1_CHB_PA0_12);	
//------------  GPTA1 Control  --------------------------------/
	GPT_PWM_Config(GPTA1,GPT_Selecte_PCLK,GPT_CNTMD_increase,GPT_OPM_Continue,0);//PCLK as clock，increasing mode,continuous mode,TCLK=PCLK/(0+1)	
	//GPT_SYNCR_Config(GPTA1,0x00,GPT_SYNCUSR0_REARMTrig_DIS,GPT_TRGSRC0_ExtSync_SYNCUSR0,GPT_TRGSRC1_ExtSync_SYNCUSR4,0x3f);//enable SYNCUSR4 SYNCUSR5 as trigger event,continuous mode					
	GPT_PWMX_Output_Control(GPTA1,GPT_PWMA,EPT_CA_Selecte_CMPA,GPT_CB_Selecte_CMPA,GPT_PWM_ZRO_Event_OutHigh,GPT_PWM_PRD_Event_Nochange,GPT_PWM_CAU_Event_OutLow,GPT_PWM_CAD_Event_OutLow,
							GPT_PWM_CBU_Event_Nochange,GPT_PWM_CBD_Event_Nochange,GPT_PWM_T1D_Event_Nochange,GPT_PWM_T1D_Event_Nochange,GPT_PWM_T2U_Event_Nochange,GPT_PWM_T2D_Event_Nochange);
	GPT_PWMX_Output_Control(GPTA1,GPT_PWMB,GPT_CA_Selecte_CMPB,GPT_CB_Selecte_CMPB,GPT_PWM_ZRO_Event_OutHigh,GPT_PWM_PRD_Event_Nochange,GPT_PWM_CAU_Event_OutLow,GPT_PWM_CAD_Event_OutLow,
							GPT_PWM_CBU_Event_Nochange,GPT_PWM_CBD_Event_Nochange,GPT_PWM_T1D_Event_Nochange,GPT_PWM_T1D_Event_Nochange,GPT_PWM_T2U_Event_Nochange,GPT_PWM_T2D_Event_Nochange);
	GPT_PRDR_CMPA_CMPB_Config(GPTA1,4800,2400,1200);//PRDR=4800,CMPA=2400,CMPB=1200
	//GPT_CG_gate_Config(GPTA1,GPT_CGSRC_CHAX,0,0,GPT_BURST_ENABLE);//CG选择CHAX为输入源，CFFLT=PLCK/(0+1),滤波次数Bypass	
//------------  GPTA1 REG LINK  ----------------------------------/	
	//GPT_REG_LINK_CONFIG(GPTA1,GPT_LinkREG_PRDR,GPT_GPTA0_LINK);//GPTA1->PRDR链接到GPTA0->PRDR
	//GPT_REG_LINK_CONFIG(GPTA1,GPT_LinkREG_CMPA,GPT_GPTA0_LINK);//GPTA1->CMPA链接到GPTA0->CMPA
	//GPT_REG_LINK_CONFIG(GPTA1,GPT_LinkREG_CMPB,GPT_GPTA0_LINK);//GPTA1->CMPB链接到GPTA0->CMPB
	//GPT_REG_LINK_CONFIG(GPTA1,GPT_LinkREG_RSSR,GPT_GPTA0_LINK);//GPTA1->RSSR链接到GPTA0->RSSR
//------------  GPTA1 TRGSRC interruption  -----------------------------/	
	//GPT_TRGSRCX_Config(GPTA1,GPT_TRGSRC0,GPT_EVTRG_TRGSRCX_CMPAU,GPT_TRGSRCX_EN,0);//选择CMPAU作为TRGSRC0事件源，事件计数CNT=0
	//GPT_TRGSRCX_Config(GPTA1,GPT_TRGSRC1,GPT_EVTRG_TRGSRCX_CMPBU,GPT_TRGSRCX_EN,0);//选择CMPBU作为TRGSRC1事件源，事件计数CNT=0	
//------------  GPTA1 interruption  --------------------------------/	
	//GPT_Int_Enable(GPTA1,GPT_CAP_LD0);//CMPA load interrupt
	//GPT_Int_Enable(GPTA1,GPT_CAP_LD1);//CMPB load interrupt
	//GPT_Int_Enable(GPTA1,GPT_CAU);//Up-Counting phase CNT = CMPA interrupt request raw status
	//GPT_Int_Enable(GPTA1,GPT_CAD);//Down-Counting phase CNT = CMPA interrupt request raw statu
	//GPT_Int_Enable(GPTA1,GPT_CBU);//Up-Counting phase CNT = CMPB interrupt request raw status
	//GPT_Int_Enable(GPTA1,GPT_CBD);//Down-Counting phase CNT = CMPB interrupt request raw status
	//GPT_Int_Enable(GPTA1,GPT_PEND);//End of cycle interrupt request raw status
	//GPT_Int_Enable(GPTA1,GPT_TRGEV0_INT);//TRGEV0
	//GPT_Int_Enable(GPTA1,GPT_TRGEV1_INT);//TRGEV1
	//GPTA1_Vector_Int_Enable();
//------------  GPTA1 start  --------------------------------/	
	GPT_Start(GPTA1);
//------------  GPTA1 capture config  --------------------------------/
	/*GPT_Soft_Reset(GPTA1);
	GPT_Capture_Config(GPTA1,GPT_Selecte_PCLK,GPT_CNTMD_increase,GPT_CAPMD_Continue,GPT_CAP_EN,GPT_LDARST_EN,GPT_LDBRST_DIS,1,0);//TCLK=pclk/(1+0),CMPAload CMPBload
	GPT_SYNCR_Config(GPTA1,GPT_Triggle_Continue,GPT_SYNCUSR0_REARMTrig_DIS,GPT_TRGSRC0_ExtSync_SYNCUSR0,GPT_TRGSRC1_ExtSync_SYNCUSR4,0x04);//Enable SYNCUSR2 ,Continuous trigger
	GPT_PRDR_CMPA_CMPB_Config(GPTA1,0XFFFF,0,0);
	GPT_Int_Enable(GPTA1,GPT_CAP_LD0);//Capture Load to CMPA interrupt request raw status
	GPT_Int_Enable(GPTA1,GPT_CAP_LD1);//Capture Load to CMPB interrupt request raw status
	GPTA1_Vector_Int_Enable();
	GPT_Start(GPTA1);*/
}
/*************************************************************/
//GPTB0 Functions
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void GPTB0_CONFIG(void)
{
	GPT_Soft_Reset(GPTB0);								//GPTB0 software reset
//------------  GPTB0 GPIO Setting  --------------------------------/
	GPTB0_IO_Init(GPTB0_CHAX_PB0_2);		
	GPTB0_IO_Init(GPTB0_CHAY_PB0_1);
	GPTB0_IO_Init(GPTB0_CHB_PA0_6);
	
	//GPTBX_EBIX_Init(GPTB_EBI0_IO_PA0_9);
//------------  GPTB0 Control  --------------------------------/
	GPT_PWM_Config(GPTB0,GPT_Selecte_PCLK,GPT_CNTMD_increase,GPT_OPM_Continue,0);//PCLK as clock，increasing mode,continuous mode,TCLK=PCLK/(0+1)	
	//GPT_SYNCR_Config(GPTB0,0x00,GPT_SYNCUSR0_REARMTrig_DIS,GPT_TRGSRC0_ExtSync_SYNCUSR0,GPT_TRGSRC1_ExtSync_SYNCUSR4,0x3f);//enable SYNCUSR4 SYNCUSR5 as trigger event,continuous mode					
	GPT_PWMX_Output_Control(GPTB0,GPT_PWMA,EPT_CA_Selecte_CMPA,GPT_CB_Selecte_CMPA,GPT_PWM_ZRO_Event_OutHigh,GPT_PWM_PRD_Event_Nochange,GPT_PWM_CAU_Event_OutLow,GPT_PWM_CAD_Event_OutLow,
							GPT_PWM_CBU_Event_Nochange,GPT_PWM_CBD_Event_Nochange,GPT_PWM_T1U_Event_Nochange,GPT_PWM_T1D_Event_Nochange,GPT_PWM_T2U_Event_Nochange,GPT_PWM_T2D_Event_Nochange);
	GPT_PWMX_Output_Control(GPTB0,GPT_PWMB,GPT_CA_Selecte_CMPB,GPT_CB_Selecte_CMPB,GPT_PWM_ZRO_Event_OutHigh,GPT_PWM_PRD_Event_Nochange,GPT_PWM_CAU_Event_OutLow,GPT_PWM_CAD_Event_OutLow,
							GPT_PWM_CBU_Event_Nochange,GPT_PWM_CBD_Event_Nochange,GPT_PWM_T1U_Event_Nochange,GPT_PWM_T1D_Event_Nochange,GPT_PWM_T2U_Event_Nochange,GPT_PWM_T2D_Event_Nochange);
	GPT_PRDR_CMPA_CMPB_Config(GPTB0,4800,2400,1200);//PRDR=4800,CMPA=2400,CMPB=1200
	GPT_DB_CLK_Config(GPTB0,0,24,24);//Fdbclk=Fhclk/(0+1)，DTR=24clk，DTF=24clk
	GPT_DBCR_Config(GPTB0,GPT_CHA_Selecte,GPT_CHAINSEL_PWMA_RISE_FALL,GPT_CHA_OUTSEL_EnRise_EnFall,GPT_PB_OUT_Reverse,GPT_PAtoCHX_PBtoCHY);//PWMA Complementary,CHX rising edge,CHY falling edge
	//GPT_CG_gate_Config(GPTB0,GPT_CGSRC_CHAX,0,0,GPT_BURST_ENABLE);//CG选择CHAX为输入源，CFFLT=PLCK/(0+1),滤波次数Bypass
//------------  GPTB0 EM Config	----------------------------------/
	//GPT_EPX_Config(GPTB0,GPT_EP0,GPT_Input_selecte_EBI0,GPT_FLT_PACE0_DIS,GPT_FLT_PACE1_DIS,0,0);//EP0选择EBI0作为输入，EP0~EP3禁止滤波，EP4禁止滤波
	//GPT_EPX_Config(GPTB0,GPT_EP1,GPT_Input_selecte_EBI1,GPT_FLT_PACE0_DIS,GPT_FLT_PACE1_DIS,0,0);//EP0选择EBI1作为输入，EP0~EP3禁止滤波，EP47禁止滤波
	//GPT_EPX_Config(GPTB0,GPT_EP2,GPT_Input_selecte_EBI2,GPT_FLT_PACE0_DIS,GPT_FLT_PACE1_DIS,0,0);//EP0选择EBI2作为输入，EP0~EP3禁止滤波，EP4禁止滤波
	//GPT_EPX_Config(GPTB0,GPT_EP3,GPT_Input_selecte_EBI3,GPT_FLT_PACE0_DIS,GPT_FLT_PACE1_DIS,0,0);//EP0选择EBI3作为输入，EP0~EP3禁止滤波，EP4禁止滤波
	
	//GPT_EBIX_POL_Config(GPTB0,0X1F);//低电平有效
	//GPT_LKCR_TRG_Config(GPTB0,GPT_LKCR_TRG_EP0,GPT_LKCR_Mode_HLOCK_EN);//EP0配置为硬锁止
	//GPT_LKCR_TRG_Config(GPTB0,GPT_LKCR_TRG_EP1,GPT_LKCR_Mode_SLOCK_EN);//EP1配置为软锁止
	//GPT_LKCR_TRG_Config(GPTB0,GPT_LKCR_TRG_EP2,GPT_LKCR_Mode_SLOCK_EN);//EP2配置为软锁止
	//GPT_LKCR_TRG_Config(GPTB0,GPT_LKCR_TRG_EP3,GPT_LKCR_Mode_SLOCK_EN);//EP3配置为软锁止

	//GPT_SHLOCK_OUTPUT_Config(GPTB0,GPT_OUTPUT_Channel_CHAX,GPT_SHLOCK_OUTPUT_HImpedance);	//产生锁止后CHAX高组态
	//GPT_SHLOCK_OUTPUT_Config(GPTB0,GPT_OUTPUT_Channel_CHAY,GPT_SHLOCK_OUTPUT_HImpedance); //产生锁止后CHAY高组态
	//GPT_SHLOCK_OUTPUT_Config(GPTB0,GPT_OUTPUT_Channel_CHB,GPT_SHLOCK_OUTPUT_HImpedance); //产生锁止后CHB高组态
//------------  GPTB0 REG LINK  ----------------------------------/
	//GPT_REG_LINK_CONFIG(GPTB0,GPT_LinkREG_PRDR,GPT_GPTA0_LINK);//GPTB0->PRDR不链接
	//GPT_REG_LINK_CONFIG(GPTB0,GPT_LinkREG_CMPA,GPT_GPTA0_LINK);//GPTB0->CMPA不链接
	//GPT_REG_LINK_CONFIG(GPTB0,GPT_LinkREG_CMPB,GPT_GPTA0_LINK);//GPTB0->CMPB不链接
	//GPT_REG_LINK_CONFIG(GPTB0,GPT_LinkREG_RSSR,GPT_GPTA0_LINK);//GPTB0->RSSR不链接
//------------  GPTB0 EM interruption  -----------------------------/
	//GPT_EMInt_Enable(GPTB0,GPT_EP0_EMINT);	
	//GPT_EMInt_Enable(GPTB0,GPT_EP1_EMINT);	
	//GPT_EMInt_Enable(GPTB0,GPT_EP2_EMINT);	
	//GPT_EMInt_Enable(GPTB0,GPT_EP3_EMINT);	
//------------  GPTB1 TRGSRC interruption  -----------------------------/	
	//GPT_TRGSRCX_Config(GPTB0,GPT_TRGSRC0,GPT_EVTRG_TRGSRCX_CMPAU,GPT_TRGSRCX_EN,0);//选择CMPAU作为TRGSRC0事件源，事件计数CNT=0
	//GPT_TRGSRCX_Config(GPTB0,GPT_TRGSRC1,GPT_EVTRG_TRGSRCX_CMPBU,GPT_TRGSRCX_EN,0);//选择CMPBU作为TRGSRC1事件源，事件计数CNT=0	
//------------  GPTB1 interruption  --------------------------------/	
	//GPT_Int_Enable(GPTB0,GPT_CAP_LD0);//CMPA load interrupt
	//GPT_Int_Enable(GPTB0,GPT_CAP_LD1);//CMPB load interrupt
	//GPT_Int_Enable(GPTB0,GPT_CAU);//Up-Counting phase CNT = CMPA interrupt request raw status
	//GPT_Int_Enable(GPTB0,GPT_CAD);//Down-Counting phase CNT = CMPA interrupt request raw statu
	//GPT_Int_Enable(GPTB0,GPT_CBU);//Up-Counting phase CNT = CMPB interrupt request raw status
	//GPT_Int_Enable(GPTB0,GPT_CBD);//Down-Counting phase CNT = CMPB interrupt request raw status
	//GPT_Int_Enable(GPTB0,GPT_PEND);//End of cycle interrupt request raw status
	//GPT_Int_Enable(GPTB0,GPT_TRGEV0_INT);//TRGEV0
	//GPT_Int_Enable(GPTB0,GPT_TRGEV1_INT);//TRGEV1
	//GPTB0_Vector_Int_Enable();
//------------  GPTB1 start  --------------------------------/	
	GPT_Start(GPTB0);
//------------  GPTB1 capture config  --------------------------------/
	/*GPT_Soft_Reset(GPTB0);
	GPT_Capture_Config(GPTB0,GPT_Selecte_PCLK,GPT_CNTMD_increase,GPT_CAPMD_Continue,GPT_CAP_EN,GPT_LDARST_EN,GPT_LDBRST_DIS,1,0);//TCLK=pclk/(1+0),CMPAload CMPBload
	GPT_SYNCR_Config(GPTB0,GPT_Triggle_Continue,GPT_SYNCUSR0_REARMTrig_DIS,GPT_TRGSRC0_ExtSync_SYNCUSR0,GPT_TRGSRC1_ExtSync_SYNCUSR4,0x04);//Enable SYNCUSR2 ,Continuous trigger
	GPT_PRDR_CMPA_CMPB_Config(GPTB0,0XFFFF,0,0);
	GPT_Int_Enable(GPTB0,GPT_CAP_LD0);//Capture Load to CMPA interrupt request raw status
	GPT_Int_Enable(GPTB0,GPT_CAP_LD1);//Capture Load to CMPB interrupt request raw status
	GPTB0_Vector_Int_Enable();
	GPT_Start(GPTB0);*/
}
/*************************************************************/
//GPTB0 Functions
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void GPTB1_CONFIG(void)
{
	GPT_Soft_Reset(GPTB1);								//GPTB1 software reset
//------------  GPTB1 GPIO Setting  --------------------------------/
	GPTB1_IO_Init(GPTB1_CHAX_PA1_11);		
	GPTB1_IO_Init(GPTB1_CHAY_PA1_10);
	GPTB1_IO_Init(GPTB1_CHB_PB0_3);	
	
	//GPTBX_EBIX_Init(GPTB_EBI0_IO_PA0_9);
//------------  GPTB1 Control  --------------------------------/
	GPT_PWM_Config(GPTB1,GPT_Selecte_PCLK,GPT_CNTMD_increase,GPT_OPM_Continue,0);//PCLK as clock，increasing mode,continuous mode,TCLK=PCLK/(0+1)	
	//GPT_SYNCR_Config(GPTB1,0x00,GPT_SYNCUSR0_REARMTrig_DIS,GPT_TRGSRC0_ExtSync_SYNCUSR0,GPT_TRGSRC1_ExtSync_SYNCUSR4,0x3f);//enable SYNCUSR4 SYNCUSR5 as trigger event,continuous mode					
	GPT_PWMX_Output_Control(GPTB1,GPT_PWMA,EPT_CA_Selecte_CMPA,GPT_CB_Selecte_CMPA,GPT_PWM_ZRO_Event_OutHigh,GPT_PWM_PRD_Event_Nochange,GPT_PWM_CAU_Event_OutLow,GPT_PWM_CAD_Event_OutLow,
							GPT_PWM_CBU_Event_Nochange,GPT_PWM_CBD_Event_Nochange,GPT_PWM_T1U_Event_Nochange,GPT_PWM_T1D_Event_Nochange,GPT_PWM_T2U_Event_Nochange,GPT_PWM_T2D_Event_Nochange);
	GPT_PWMX_Output_Control(GPTB1,GPT_PWMB,GPT_CA_Selecte_CMPB,GPT_CB_Selecte_CMPB,GPT_PWM_ZRO_Event_OutHigh,GPT_PWM_PRD_Event_Nochange,GPT_PWM_CAU_Event_OutLow,GPT_PWM_CAD_Event_OutLow,
							GPT_PWM_CBU_Event_Nochange,GPT_PWM_CBD_Event_Nochange,GPT_PWM_T1U_Event_Nochange,GPT_PWM_T1D_Event_Nochange,GPT_PWM_T2U_Event_Nochange,GPT_PWM_T2D_Event_Nochange);
	GPT_PRDR_CMPA_CMPB_Config(GPTB1,4800,2400,1200);//PRDR=4800,CMPA=2400,CMPB=1200
	GPT_DB_CLK_Config(GPTB1,0,24,24);//Fdbclk=Fhclk/(0+1)，DTR=24clk，DTF=24clk
	GPT_DBCR_Config(GPTB1,GPT_CHA_Selecte,GPT_CHAINSEL_PWMA_RISE_FALL,GPT_CHA_OUTSEL_EnRise_EnFall,GPT_PA_PB_OUT_Direct,GPT_PAtoCHX_PBtoCHY);//PWMA Complementary,CHX rising edge,CHY falling edge
	//GPT_CG_gate_Config(GPTB1,GPT_CGSRC_CHAX,0,0,GPT_BURST_ENABLE);//CG选择CHAX为输入源，CFFLT=PLCK/(0+1),滤波次数Bypass
//------------  GPTB1 EM Config	----------------------------------/
	//GPT_EPX_Config(GPTB1,GPT_EP0,GPT_Input_selecte_EBI0,GPT_FLT_PACE0_DIS,GPT_FLT_PACE1_DIS,0,0);//EP0选择EBI0作为输入，EP0~EP3禁止滤波，EP4禁止滤波
	//GPT_EPX_Config(GPTB1,GPT_EP1,GPT_Input_selecte_EBI1,GPT_FLT_PACE0_DIS,GPT_FLT_PACE1_DIS,0,0);//EP0选择EBI1作为输入，EP0~EP3禁止滤波，EP47禁止滤波
	//GPT_EPX_Config(GPTB1,GPT_EP2,GPT_Input_selecte_EBI2,GPT_FLT_PACE0_DIS,GPT_FLT_PACE1_DIS,0,0);//EP0选择EBI2作为输入，EP0~EP3禁止滤波，EP4禁止滤波
	//GPT_EPX_Config(GPTB1,GPT_EP3,GPT_Input_selecte_EBI3,GPT_FLT_PACE0_DIS,GPT_FLT_PACE1_DIS,0,0);//EP0选择EBI3作为输入，EP0~EP3禁止滤波，EP4禁止滤波
	
	//GPT_EBIX_POL_Config(GPTB1,0X1F);//低电平有效
	//GPT_LKCR_TRG_Config(GPTB1,GPT_LKCR_TRG_EP0,GPT_LKCR_Mode_HLOCK_EN);//EP0配置为硬锁止
	//GPT_LKCR_TRG_Config(GPTB1,GPT_LKCR_TRG_EP1,GPT_LKCR_Mode_SLOCK_EN);//EP1配置为软锁止
	//GPT_LKCR_TRG_Config(GPTB1,GPT_LKCR_TRG_EP2,GPT_LKCR_Mode_SLOCK_EN);//EP2配置为软锁止
	//GPT_LKCR_TRG_Config(GPTB1,GPT_LKCR_TRG_EP3,GPT_LKCR_Mode_SLOCK_EN);//EP3配置为软锁止

	//GPT_SHLOCK_OUTPUT_Config(GPTB1,GPT_OUTPUT_Channel_CHAX,GPT_SHLOCK_OUTPUT_HImpedance);	//产生锁止后CHAX高组态
	//GPT_SHLOCK_OUTPUT_Config(GPTB1,GPT_OUTPUT_Channel_CHAY,GPT_SHLOCK_OUTPUT_HImpedance); //产生锁止后CHAY高组态
	//GPT_SHLOCK_OUTPUT_Config(GPTB1,GPT_OUTPUT_Channel_CHB,GPT_SHLOCK_OUTPUT_HImpedance); //产生锁止后CHB高组态
//------------  GPTB1 REG LINK  ----------------------------------/
	//GPT_REG_LINK_CONFIG(GPTB1,GPT_LinkREG_PRDR,GPT_GPTA0_LINK);//GPTB1->PRDR不链接
	//GPT_REG_LINK_CONFIG(GPTB1,GPT_LinkREG_CMPA,GPT_GPTA0_LINK);//GPTB1->CMPA不链接
	//GPT_REG_LINK_CONFIG(GPTB1,GPT_LinkREG_CMPB,GPT_GPTA0_LINK);//GPTB1->CMPB不链接
	//GPT_REG_LINK_CONFIG(GPTB1,GPT_LinkREG_RSSR,GPT_GPTA0_LINK);//GPTB1->RSSR不链接
//------------  GPTB1 EM interruption  -----------------------------/
	//GPT_EMInt_Enable(GPTB1,GPT_EP0_EMINT);	
	//GPT_EMInt_Enable(GPTB1,GPT_EP1_EMINT);	
	//GPT_EMInt_Enable(GPTB1,GPT_EP2_EMINT);	
	//GPT_EMInt_Enable(GPTB1,GPT_EP3_EMINT);	
//------------  GPTB1 TRGSRC interruption  -----------------------------/	
	//GPT_TRGSRCX_Config(GPTB1,GPT_TRGSRC0,GPT_EVTRG_TRGSRCX_CMPAU,GPT_TRGSRCX_EN,0);//选择CMPAU作为TRGSRC0事件源，事件计数CNT=0
	//GPT_TRGSRCX_Config(GPTB1,GPT_TRGSRC1,GPT_EVTRG_TRGSRCX_CMPBU,GPT_TRGSRCX_EN,0);//选择CMPBU作为TRGSRC1事件源，事件计数CNT=0	
//------------  GPTB1 interruption  --------------------------------/	
	//GPT_Int_Enable(GPTB1,GPT_CAP_LD0);//CMPA load interrupt
	//GPT_Int_Enable(GPTB1,GPT_CAP_LD1);//CMPB load interrupt
	//GPT_Int_Enable(GPTB1,GPT_CAU);//Up-Counting phase CNT = CMPA interrupt request raw status
	//GPT_Int_Enable(GPTB1,GPT_CAD);//Down-Counting phase CNT = CMPA interrupt request raw statu
	//GPT_Int_Enable(GPTB1,GPT_CBU);//Up-Counting phase CNT = CMPB interrupt request raw status
	//GPT_Int_Enable(GPTB1,GPT_CBD);//Down-Counting phase CNT = CMPB interrupt request raw status
	//GPT_Int_Enable(GPTB1,GPT_PEND);//End of cycle interrupt request raw status
	//GPT_Int_Enable(GPTB1,GPT_TRGEV0_INT);//TRGEV0
	//GPT_Int_Enable(GPTB1,GPT_TRGEV1_INT);//TRGEV1
	//GPTB1_Vector_Int_Enable();
//------------  GPTB1 start  --------------------------------/	
	GPT_Start(GPTB1);
//------------  GPTB1 capture config  --------------------------------/
	/*GPT_Soft_Reset(GPTB1);
	GPT_Capture_Config(GPTB1,GPT_Selecte_PCLK,GPT_CNTMD_increase,GPT_CAPMD_Continue,GPT_CAP_EN,GPT_LDARST_EN,GPT_LDBRST_DIS,1,0);//TCLK=pclk/(1+0),CMPAload CMPBload
	GPT_SYNCR_Config(GPTB1,GPT_Triggle_Continue,GPT_SYNCUSR0_REARMTrig_DIS,GPT_TRGSRC0_ExtSync_SYNCUSR0,GPT_TRGSRC1_ExtSync_SYNCUSR4,0x04);//Enable SYNCUSR2 ,Continuous trigger
	GPT_PRDR_CMPA_CMPB_Config(GPTB1,0XFFFF,0,0);
	GPT_Int_Enable(GPTB1,GPT_CAP_LD0);//Capture Load to CMPA interrupt request raw status
	GPT_Int_Enable(GPTB1,GPT_CAP_LD1);//Capture Load to CMPB interrupt request raw status
	GPTB1_Vector_Int_Enable();
	GPT_Start(GPTB1);*/
}
/*************************************************************/
//LPT Functions
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void LPT_CONFIG(void)
{
	LPT_DeInit();										//LPT DeInit
	//LPT_IO_Init(LPT_INOUT_PA0_7);						//LPT IO Selection
	LPT_Configure(LPTCLK_EN,LPT_ISCLK,LPT_IMMEDIATE,LPT_PSC_DIV0,0,LPT_OPM_CONTINUOUS);		//
	//LPT_Debug_Mode(ENABLE);
	LPT_ControlSet_Configure(LPT_OUT_EN,LPT_SWSYNDIS,LPT_IDLE_Z,LPT_PRDLD_DUTY_END,LPT_POL_HIGH,LPT_FLTDEB_00,LPT_PSCLD_0,LPT_CMPLD_IMMEDIATELY);
	//LPT_SyncSet_Configure(LPT_TRGEN_EN,LPT_OSTMD_ONCE,LPT_AREARM_DIS);
	//LPT_Trigger_Configure(LPT_SRCSEL_EN,LPT_BLKINV_DIS,LPT_CROSSMD_DIS,LPT_TRGSRC0_CMP,LPT_ESYN0OE_EN,5,5,0X0F);
	LPT_Period_CMP_Write(27000,500);					//LPT period and comparison value setting
	LPT_ConfigInterrupt_CMD(ENABLE,LPT_PEND);			//enable LPT intterrupt condition
	LPT_Start();										//LPT start
	LPT_INT_ENABLE();									//enable LPT intterrupt
	LPT_WakeUp_Enable();								//enable LPT wakeup
}
/*************************************************************/
//BT Initial
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/	
void BT_CONFIG(void)
{
	BT_DeInit(BT0);										//BT0 DeInit
	BT_IO_Init(BT0_PA1_9);								//BT0 IO Selection
	BT_Configure(BT0,BTCLK_EN,0,BT_IMMEDIATE,BT_CONTINUOUS,BT_PCLKDIV);//TCLK=PCLK/(0+1)
	BT_ControlSet_Configure(BT0,BT_START_HIGH,BT_IDLE_LOW,BT_CNTRLD_EN);
	BT_Period_CMP_Write(BT0,12000,6000);				//BT0 period and comparison value setting
	BT_Start(BT0);										//BT0 start
	BT_ConfigInterrupt_CMD(BT0,ENABLE,BT_PEND);			//enable BT0 intterrupt condition
	BT0_INT_ENABLE();									//enable BT0 intterrupt
	
/*	BT_DeInit(BT1);									//BT1 DeInit
	BT_IO_Init(BT1_PA0_9);								//BT1 IO Selection
	BT_Configure(BT1,BTCLK_EN,0,BT_IMMEDIATE,BT_CONTINUOUS,BT_PCLKDIV);
	BT_ControlSet_Configure(BT1,BT_START_LOW,BT_IDLE_HIGH,BT_CNTRLD_EN);
	//BT_Trigger_Configure(BT1,BT_TRGSRC_PEND,BT_TRGOE_EN);
	BT_Period_CMP_Write(BT1,12000,3000);					//BT1 period and comparison value setting
	BT_Start(BT1);										//BT1 start
	BT_ConfigInterrupt_CMD(BT1,ENABLE,BT_PEND);			//enable BT1 intterrupt condition
	BT1_INT_ENABLE();		*/						//enable BT1 intterrupt
}
/*************************************************************/
//COUNTA Initial
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/	
void COUNTA_CONFIG(void)
{
    COUNT_DeInit();                                                                     //clear all countA Register
    //COUNTA_IO_Init(COUNTA_PA1_10);                                                     //counter IO Selection
    COUNTA_Init(1000,0,Period_H,DIV1,REPEAT_MODE,CARRIER_ON,OSP_LOW);                    //Data_H=Time/(1/sysclock)
    COUNTA_Config(SW_STROBE,PENDREM_OFF,MATCHREM_OFF,REMSTAT_0,ENVELOPE_0);              //countA mode set  
    COUNTA_Start();                                                                      //countA start
    //COUNTA_Stop();                                                                     //countA stop  
    COUNTA_Int_Enable();                                                                 //countA INT enable
}
/*************************************************************/
//RTC Initial
//EntryParameter:NONE
//ReturnValue:NONE
//RTC CLK=(CLKSRC_EMOSC)/(DIVS+1)/(DIVA+1)/2
//		  (ISCLK)/(DIVS+1)/(DIVA+1)/2
//		  (IMCLK)/(DIVS+1)/(DIVA+1)/2
/*************************************************************/	
void RTC_CONFIG(void)
{
	RTC_RST_VALUE();										//rtc reset
	RTC_Stop();												//if you want set time data, must be stop RTC clk.
	//RTC_ALM_IO_SET(Alarm_A_pulse_output);					//PA0.2  1pulse =1 rtc clk
	RTCCLK_CONFIG(2047,7,CLKSRC_ISOSC);						//32.768K/2/(2047+1)/(7+1)=1S
	RTC_Function_Config(RTC_24H,CPRD_1S);					//RTC Select 24h , CPRD Select 1s
	RTC_TimeDate_buf.u8Second=0x00;							//RTC second setting
	RTC_TimeDate_buf.u8Minute=0x00;							//RTC minute setting
	RTC_TimeDate_buf.u8Hour=0X08;							//RTC 24-hour setting
	RTC_TimeDate_buf.u8Day=0X29;							//RTC dat setting
	RTC_TimeDate_buf.u8Month=0X05;							//RTC month setting
	RTC_TimeDate_buf.u8Year=0X20;							//RTC year setting
	RTC_TimeDate_buf.u8DayOfWeek=0x04;						//RTC day of week setting
	RTC_TIMR_DATR_SET(&RTC_TimeDate_buf);					//20/5/20,08:09:00
	//ALARMA must be turned on to set the time to adjust the hour carry error problem
	/*RTC_AlarmA_buf.u8Second=0x59;							//					
	RTC_AlarmA_buf.u8Minute=0x19;
	RTC_AlarmA_buf.u8Hour=0X08;								
	RTC_Alarm_TIMR_DATR_SET(Alarm_A,&RTC_AlarmA_buf,
			Alarm_Second_Compare_EN,Alarm_Minute_Compare_EN,Alarm_Hour_Compare_EN,Alarm_DataOrWeek_Compare_DIS,Alarm_data_selecte);//AlarmA time 7:00:00:00, weekend alarm
	
	RTC_AlarmB_buf.u8Second=0x02;							//AlarmB second setting
	RTC_AlarmB_buf.u8Minute=0x29;							//AlarmB minute setting
	RTC_AlarmB_buf.u8Hour=0X08;								//AlarmB 24-hour setting	
	RTC_Alarm_TIMR_DATR_SET(Alarm_B,&RTC_AlarmB_buf,
			Alarm_Second_Compare_EN,Alarm_Minute_Compare_EN,Alarm_Hour_Compare_EN,Alarm_DataOrWeek_Compare_DIS,Alarm_data_selecte);//AlarmB time 7:00:00:00, weekend alarm	
	*/
	//RTC_Int_Enable(ALRA_INT);								//enable AlarmA intterrupt
	//RTC_Int_Enable(ALRB_INT);								//enable AlarmB intterrupt
	RTC_Int_Enable(CPRD_INT);								//enable Periodic events intterrupt(based on periodic events configuration)
	//RTC_Int_Enable(RTC_TRGEV0_INT);						//enable Synchronized trigger event 0 intterrupt
	//RTC_Int_Enable(RTC_TRGEV1_INT);						//enable Synchronized trigger event 1 intterrupt
	RTC_Vector_Int_Enable();								//enable RTC intterrupt
	RTC_WakeUp_Enable();									//enable RTC wakeup
	RTC_Start();											//RTC start
	//RTC EVT
	//RTC_TRGSRC0_Config(RTC_EVTRG_TRGSRC0_CPRD,RTC_ESYNxOE_EN,1);
	//RTC_TRGSRC1_Config(RTC_EVTRG_TRGSRC1_CPRD,RTC_ESYNxOE_EN,2);	
	//RTC_TRGSRC0_SWFTRG();					//RTC_TRGEV0 	SW SET
	//RTC_TRGSRC1_SWFTRG();					//RTC_TRGEV1 	SW SET
}
/*************************************************************/
//ET Initial
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/	
void ETCB_CONFIG(void)
{
	ETCB_DeInit();
	//EXI_SYCN0 -> EPT_SYNIN4
	//ET_CH0_SRCSEL(ET_SRC0,ENABLE,ET_EXI_SYNC0);
	//ET_CH0_CONTROL(ENABLE,TRG_HW,ET_EPT0_SYNCIN4);
	//EXI_SYCN1 -> EPT_SYNIN5
	ETCB_CH1_SRCSEL(ENABLE,TRG_HW,CMP1_TRGOUT);
	ETCB_CH1_CONTROL(ET_DST0,ENABLE,ET_EPT0_SYNCIN0);
	ETCB_ENABLE();
}
/*************************************************************/
//SIO Functions
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void SIO_CONFIG(void)
{
//----------------------SIO send mode---------------------------------//
	/*SIO_DeInit();										//SIO deinitial
	SIO_IO_Init(SIO_PC0_0);								//SIO IO selection
	SIO_TX_Init(SIOCLK_EN,19);							//FTXCLK=PCLK/(19+1)
	SIO_TX_Configure(SIO_IDLE_HIGH,SIO_TX_MSB,15,15,0,0,SIO_OBH_3BIT,SIO_OBL_3BIT,3,1);
	//空闲高电平，高位到低位输出，发送数据buffer长度15+1，发送序列长度为15，D0时间长度，D1时间长度，DH为3bit，DL为3bit，DH对象定义为011，DL对象定义为001
	//SIO_ConfigInterrupt_CMD(ENABLE,SIO_TXBUFEMPT);	//enable SIO intterrupt condition
	//SIO_INT_ENABLE();*/								//enable SIO intterrupt
//----------------------SIO receive mode---------------------------------//
	SIO_RESET();										//SIO reset
	SIO_DeInit();										//SIO deinitial
	SIO_IO_Init(SIO_PC0_0);								//SIO IO selection
	SIO_RX_Init(SIOCLK_EN,SIO_TXDEB_1CYCLE,0);//接收模式，去抖滤波检查周期1CYCLE，FDBCLK=PCLK/(0+1)
	SIO_RX_Configure0(SIO_RX_FALL , SIO_RX_DEB , 3 , 2 , 0 , SIO_RX_ALIGNEN , SIO_RX_MSB , SIO_RMODE1 , 31 , 31 , 4);
	//下降沿触发，选择去抖后采样，bit采样长度(3+1)Rxclk，第2位作为提取，0，使能采样对准，从第0位开始移入，采样模式1无论是否有跳变都进入下个采样，接收长度31+1，接收buf长度31+1，RXCLK=PCLK/(4+1)
	SIO_RX_Configure1(SIO_BREAKEN,SIO_BREAKLVL_HIGH,10,SIO_TORSTDIS,15);
	//使能BREAK，BREAK识别电平为High，11个采样长度，使能采样超时复位，40个采样长度
	//SIO_ConfigInterrupt_CMD(ENABLE,SIO_RXDNE);
	SIO_ConfigInterrupt_CMD(ENABLE,SIO_RXBUFEMPT);		//enable SIO intterrupt condition
	SIO_ConfigInterrupt_CMD(ENABLE,SIO_BREAK);			//enable SIO intterrupt condition
	//SIO_ConfigInterrupt_CMD(ENABLE,SIO_TIME);	//不建议使用，数据接收完后，time out失效
	SIO_INT_ENABLE();									//enable SIO intterrupt
}
/*************************************************************/
//SPI MASTER Initial
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/	
void SPI_MASTER_CONFIG(void)
{
	SPI_Reset();											//SPI reset
	SPI_DeInit();											//SPI deinitial
	SPI_NSS_IO_Init(0);										//SPI NSS io selection
	SPI_Master_Init(SPI_G0,SPI_DATA_SIZE_8BIT,SPI_SPO_0,SPI_SPH_0,SPI_LBM_0,SPI_RXIFLSEL_1_8,0,12);
	//SPI IO group1; 8bis; ; clk low when no data transmission;  first clock edge transition; Normal serial port; Receive Interrupt FIFO Level Selection 1/8; FSSPCLKOUT=48M/12=4M
	SPI_ConfigInterrupt_CMD(ENABLE,SPI_RXIM);				//enable FIFO receive interrupt
	SPI_Int_Enable();										//enable spi interrupt
}
/*************************************************************/
//SPI SLAVE Initial
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/	
void SPI_SLAVE_CONFIG(void)
{
	SPI_Reset();											//SPI reset
	SPI_DeInit();											//SPI deinitial
	SPI_NSS_IO_Init(0);										//SPI NSS io selection
	SPI_Slave_Init(SPI_G0,SPI_DATA_SIZE_8BIT,SPI_SPH_0,SPI_RXIFLSEL_1_8,0,12);			
	//SPI IO group1; 8bis; first clock edge transition;Receive Interrupt FIFO Level Selection 1/8;FSSPCLKOUT=48M/12=4M
	SPI_ConfigInterrupt_CMD(ENABLE,SPI_RXIM);				//enable FIFO receive interrupt
	SPI_Int_Enable();										//enable spi interrupt
}
/*************************************************************/
//IIC MASTER Initial
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/	
void I2C_MASTER_CONFIG(void)
{
	I2C_RESET();
	//I2C_DeInit();
	I2C_Master_CONFIG(I2C_SDA_PA1_13,I2C_SCL_PA1_12,FAST_MODE,I2C_MASTRER_7BIT,0X57,0X10,0X10);//address=0X57,SCL=IIClk*250=5us
	I2C_SDA_TSETUP_THOLD_CONFIG(0x08,0x40,0x08);										     //TSETUP=0X20*IICLK,RX_THOLD=0X20*IICLK,TX_THOLD=0X20*IICLK
	I2C_FIFO_TriggerData(7,7);
	I2C_Enable();
}
/*************************************************************/
//IIC SLAVER Initial
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/	
void I2C_SLAVE_CONFIG(void)
{
	I2C_RESET();
	//I2C_DeInit();																		   //I2C de-initial
	I2C_Slave_CONFIG(I2C_SDA_PA0_3,I2C_SCL_PA0_4,FAST_MODE,I2C_SLAVE_7BIT,0X57,0X8,0X8);//I2C IO selection,fast mode,slave 7 bit,slave address 0x57(slave address cant set as 0x00~0x07,0x78~0x7f)
	I2C_SDA_TSETUP_THOLD_CONFIG(0x02,0x03,0x08);
	I2C_FIFO_TriggerData(0,0);															  //I2C  FIFO setting
	I2C_ConfigInterrupt_CMD(ENABLE,I2C_SCL_SLOW);										  //I2C interrupt enable/disable
	I2C_ConfigInterrupt_CMD(ENABLE,I2C_STOP_DET);
	I2C_ConfigInterrupt_CMD(ENABLE,I2C_RD_REQ);
	I2C_ConfigInterrupt_CMD(ENABLE,I2C_RX_FULL);
	I2C_ConfigInterrupt_CMD(ENABLE,I2C_TX_ABRT);
	I2C_Enable();
	I2C_Int_Enable();
	
}
/*************************************************************/
//UART0  CONFIG
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/	
void UART0_CONFIG(void)
{
	UART0_DeInit();                                                	//clear all UART Register
    UART_IO_Init(IO_UART0,1);                                     	//use PB0.8->TXD0, PB0.9->RXD0
    //UARTInit(UART0,416,UART_PAR_NONE);							 //baudrate=sysclock/416=115200
	UARTInitRxTxIntEn(UART0,416,UART_PAR_NONE);	              		//baudrate=sysclock/416=115200,RX TX int enable
	UART_DMA_Control(UART0,0x01,UART_TX_FL_FIFO_NF,UART_RX_FL_FIFO_NE);
	UART0_Int_Enable();
}	
/*************************************************************/
//UART1  CONFIG
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/	
void UART1_CONFIG(void)
{
	UART1_DeInit();                                                 //clear all UART Register
    UART_IO_Init(IO_UART1,0);                                    	//use PA0.6->RXD1, PB0.2->TXD1
	//UARTInit(UART0,416,UART_PAR_NONE);							//baudrate=sysclock/416=115200
    UARTInitRxTxIntEn(UART1,416,UART_PAR_NONE);	                    //baudrate=sysclock/416=115200,RX TX int enable
	UART1_Int_Enable();
}	
/*************************************************************/
//UART2  CONFIG
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/	
void UART2_CONFIG(void)
{
	UART2_DeInit();                                                 //clear all UART Register
    UART_IO_Init(IO_UART2,2);                                    	//use PA1.12->RXD2, PA1.11->TXD2 
	//UARTInit(UART0,416,UART_PAR_NONE);							//baudrate=sysclock/416=115200
    UARTInitRxTxIntEn(UART2,416,UART_PAR_NONE);	                    //baudrate=sysclock/416=115200,RX TX int enable
	UART2_Int_Enable();
}	
/*************************************************************/
//USART Functions
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void USART_CONFIG(void)
{
	USART_DeInit();                                                              	//USART reset
    USART_CLK_Enable();																//USART CLK	En
	USART_CTRL_Config(RSTRX,ENABLE);												//Reset RX
	USART_CTRL_Config(RSTTX,ENABLE);												//Reset TX
	USART_CTRL_Config(FIFI_EN,ENABLE);
	USART_CTRL_Config(RXIFLSEL_1_8,ENABLE);
	USART_DMA_Control(0X03,USART_TX_FL_FIFO_NF,USART_RX_FL_FIFO_NE);
	USART_IO_Init(USART_TxPA1_4_RxPA1_5);                                       	//USART PA1.4->TXD0, PA=1.5->RXD0
	//USART_CLKIO_Init(CLK_PA1_3);													//PA1.3 can be selected as UARTCLK in sync mode
    USART_MODE_Config(SENDTIME0,PCLK,CHRL8,ASYNC,PAR_EVEN,NBSTOP1,CHMODE_NORMAL);	//SendTime0, CLKs=PCLK, 8bit, ASYNC, EVEN, 1 stop, normal mode
	//USART_CLKO_Config(ENABLE);													//UARTCLK needs to be enabled in sync mode
    USART_Baudrate_Cal(115200,48000000,PCLK,ASYNC);									//baudrate=115200, 48M, PCLK, ASYNC							
	//USART_CTRL_Config(TXEN,ENABLE);												//USART TX Enable
	//USART_CTRL_Config(RXEN,ENABLE);												//USART RX Enable
	//USART_INT_Config(RXRDY_INT,ENABLE);											//USART RX interrupt Enable
	//USART_INT_Config(TXRDY_INT,ENABLE);											//USART TX interrupt Enable
	//USART_Int_Enable();															//USART interrupt Enable
	//USART_WakeUp_Enable();														//USART wakeup interrupt Enable
	
}
/*************************************************************/
//adc config
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/	
void ADC12_CONFIG(void)
{
	ADC12_Software_Reset();
	ADC12_CLK_CMD(ADC_CLK_CR , ENABLE);                                         //enable ADC CLK
	ADC12_Configure_Mode(ADC12_12BIT , One_shot_mode ,0, 6 ,2 , 1);           //12BIT ADC; Continuous mode; Conversion priority selection 0; Holding cycles=6 ;ADC_CLK=PCLK/2*2=0.2us; Number of Conversions=1
	ADC12_Configure_VREF_Selecte(ADC12_VREFP_FVR4096_VREFN_VSS);					    //ADC VREF Positive FVR4.096V,negative VSS
	ADC12_ConversionChannel_Config(ADC12_ADCIN1,ADC12_CV_RepeatNum1,ADC12_AVGDIS,0);    //SEQ0 chose ADCIN0, 6 Holding cycles, Average 1 time
	//ADC12_ConversionChannel_Config(ADC12_INTVREF,ADC12_CV_RepeatNum1,ADC12_AVGDIS,1);  //SEQ1 chose ADCIN1, 6 Holding cycles , Average 1 time
	ADC12_CMD(ENABLE);                                                                  //enable ADC
	ADC12_ready_wait(); 																//wait ADC get ready
	ADC12_Control(ADC12_START);															//ADC convert start
}
/*************************************************************/
//cmp config
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CMP_CONFIG(void)
{
//---------CMP0 initial
	/*CMP_software_reset(CMP0);							//CMP0 softreset
	
	CMP_IO_Init(CMPIN0_PA0_0);
	CMP_IO_Init(CMPIN1_PA1_10);
	CMP_IO_Init(CMP0OUT_PA1_6);
	
	CMP_INPCRX_Config(CMP0,0,1);						//CMP0 negative selected as CMPIN0,positive selected asCMPIN1
	CMP_CLK_CMD(CMP0,ENABLE);							//CMP0 clock En
	CMP_CR_Config(CMP0,CMP_HYSTSEL_DIS,HYST_0mv,POLARITY_0,EVET_SEL_rise,DIS_FLTEN1,DIS_FLTEN2,CPOS_1,1);
	//CMP0 En,Hysteresis Dis,Hysteresis 0mV,Event rise,Output not reversed,filter 1 Dis,filter 2 Dis,Output without filter,Time-trigger channel enable
	//CMPX_FLT1CR_Config(CMP0,CMP_DEPTH1_8,4,199);		//FLT_CK = 48M/(199+1)/2^4=66.6us;filter time 8
	//CMPX_FLT2CR_Config(CMP0,CMP_DEPTH2_16,4,199);		//FLT_CK = 48M/(199+1)/2^4=66.6us;filter time 16
	CMP_Open(CMP0);										//open cmp2
	CMP_ConfigInterrupt_CMD(CMP0,EDGEDET,ENABLE);		//CMP0 OUT event interrupt
	CMP_ConfigInterrupt_CMD(CMP0,RAWDET,ENABLE);		//CMP0 Raw interrupt
//---------CMP1 initial	
	CMP_software_reset(CMP1);							//CMP1 softreset
	
	//CMP_IO_Init(CMP1OUT_PB0_5);
	CMP_IO_Init(CMPIN2_PA0_3);
	CMP_IO_Init(CMPIN3_PA0_4);
	//CMP_IO_Init(CMPIN5_PB0_1);
	//CMP_IO_Init(CMPIN7_PC0_0);
	
	CMP_INPCRX_Config(CMP1,2,3);						//CMP1 negative selected as internal 1V, positive selected as CMPIN3
	CMP_CLK_CMD(CMP1,ENABLE);							//CMP1 clock En
	CMP_CR_Config(CMP1,CMP_HYSTSEL_DIS,HYST_0mv,POLARITY_0,EVET_SEL_rise,DIS_FLTEN1,DIS_FLTEN2,CPOS_1,1);
	//CMP1 En,Hysteresis Dis,Hysteresis 0mV,Event rise,Output not reversed,filter 1 Dis,filter 2 Dis,Output without filter,Time-trigger channel enable
	//CMPX_FLT1CR_Config(CMP1,CMP_DEPTH1_8,4,199);		//FLT_CK = 48M/(199+1)/2^4=66.6us;filter time 8
	//CMPX_FLT2CR_Config(CMP1,CMP_DEPTH2_16,4,199);		//FLT_CK = 48M/(199+1)/2^4=66.6us;filter time 16
	CMP_Open(CMP1);										//open cmp1
	//CMP_ConfigInterrupt_CMD(CMP1,EDGEDET,ENABLE);		//CMP1 OUT event interrupt
	CMP_ConfigInterrupt_CMD(CMP1,RAWDET,ENABLE);		//CMP1 Raw interrupt *Wakeup must use this interrupt
	
	CMP_Int_Enable();									//Enable interrupt vector
	CMP_Wakeup_Enable();								//Enable interrupt wake-up*/
}

/*************************************************************/
//lcd config
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/	
void LCD_CONFIG(void)
{
	Lcd_io_initial(0x0Cfffffc,0x0f);
	lcd_Software_Reset();				
	Lcd_Reset_Value();
	Lcd_Clk_Enable(ENABLE,Lcd_Clk_ISOSC);//选择ISOSC
	Lcdclk_Config(2,15);			//lcdclk=27K/(2^(1+1))/(55+1)=120Hz ， //Fframe=lcdclk/duty=120HZ/4=保持在30HZ左右
	Lcd_Display_Config(Vlcd_Selected_IntVDD_4_0V,Lcd_DutyBiase_Selected_1_4Duty_1_3_Bias,Lcd_Contrast_Selecte_1,lcd_display_buffer,Lcd_BP_EN,2);//选择内部3V;1/4duty 1/3BIas;对比度8;去耦禁止;死区0
	LCD->CR |= 7<<16;
	Lcd_Scan_Enable(ENABLE);
	Lcd_Write_Data(Lcd_data_buf);
	//lcd_display_mode(Lcd_Diplay_bufer);//显示buffer模式
	//Lcd_Int_Config(Lcd_INT_UDD);
	//Lcd_Vector_Enable();
	//Lcd_Wakeup_Enable();
	//Lcd_Blink_Config(Lcd_Blink_MD_Seg8_AllCom,Lcd_Blink_Fre_DIV_CR2,120);//FBLINK=lcdclk/120
}
/*************************************************************/
//LED Init
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/  
void LED_CONFIG(void)  
{
	//Debug_IO_release();
	LED_RESET_VALUE();                                          //LED reset
	LED_seg_io_initial(LED_SEG_0,0);							//led seg0 io initial
	LED_seg_io_initial(LED_SEG_1,0);							//led seg1 io initial
	LED_seg_io_initial(LED_SEG_2,0);							//led seg2 io initial
	LED_seg_io_initial(LED_SEG_3,0);							//led seg3 io initial
	LED_seg_io_initial(LED_SEG_4,0);							//led seg4 io initial
	LED_seg_io_initial(LED_SEG_5,0);							//led seg5 io initial
	LED_seg_io_initial(LED_SEG_6,0);							//led seg6 io initial
	LED_seg_io_initial(LED_SEG_7,0);							//led seg7 io initial
	
	LED_COM_IO_initial(LED_COM_0,0);							//led com0 io initial
	LED_COM_IO_initial(LED_COM_1,0);							//led com1 io initial
	//LED_COM_IO_initial(LED_COM_2,0);							//led com2 io initial (SWDIO Pin)
	//LED_COM_IO_initial(LED_COM_3,0);							//led com3 io initial
	//LED_COM_IO_initial(LED_COM_4,0);							//led com4 io initial
	//LED_COM_IO_initial(LED_COM_5,0);							//led com5 io initial (SWCLIK Pin)
	//LED_COM_IO_initial(LED_COM_6,0);							//led com6 io initial
	//LED_COM_IO_initial(LED_COM_7,0);							//led com7 io initial
	//LED_COM_IO_initial(LED_COM_8,0);							//led com8 io initial
	//LED_COM_IO_initial(LED_COM_9,0);							//led com9 io initial
	
	LED_Control_Config(LEDCLK_DIV32,0x3,LED_Bright_100,80,1);	//F_LedClk=32/48M;COM0~COM9Enable;Brightness100%;COM duty=(10*32/48M)*(80+7)=580US;
	LED_SEGDATX_data_write(SEGDAT_NUM0 , 0x40);                 
	LED_SEGDATX_data_write(SEGDAT_NUM1 , 0x40);                        
	LED_SEGDATX_data_write(SEGDAT_NUM8 , 0XFF);             
	LED_SEGDATX_data_write(SEGDAT_NUM9 , 0XFF);
	LED_SCAN_ENABLE(ENABLE);                                    //LED Scan enable	

	//LED_INT_CMD(IPEND,ENABLE);								//LED one com scan end interrupt enable
	//LED_INT_CMD(ICEND,ENABLE);								//LED all com scan end interrupt enable

	//LED_Int_Enable();											//LED INT Vector Enable					
}
/*************************************************************/
//coret Init for tkey
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void coret_tk_itial(void)
{
	CORET_DeInit();										//coret deintial
	SYSCON_General_CMD(ENABLE,ENDIS_SYSTICK);			//enable coret systick
	CK802->CORET_RVR=hwTkeyBaseCnt;						//CORETCLK=sysclock/8=48M/8=6Mhz  e.g:10ms=(CORET_RVR+1)*(8/48M);CORET_RVR=60000-1=59999
	CORET_reload();										//Clear coret counter and flag					
	CORET_CLKSOURCE_EX();								//use ex clock
	CORET_TICKINT_Enable();								//clear CORET counter
	CORET_start();										//coret start
	CORET_Int_Enable();									//coret int enable
}
/*************************************************************/
//Tkey Init
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void TKEY_CONFIG(void)
{
	csi_tkey_init();									//Initial Tkey IP
	coret_tk_itial();
}
/*************************************************************/
//syscon Functions
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SYSCON_CONFIG(void)
{
//------SYSTEM CLK AND PCLK FUNTION---------------------------/
	SYSCON_RST_VALUE();                                                         //SYSCON all register clr
	SYSCON_General_CMD(ENABLE,ENDIS_ISOSC);										//SYSCON enable/disable clock source
	//EMOSC_OSTR_Config(0XAD,0X1f,EM_LFSEL_DIS,EM_FLEN_EN,EM_FLSEL_10ns);		//EM_CNT=0X3FF,0xAD(36K),EM_GM=0,Low F modedisable,EM filter disable,if enable,cont set 5ns
	//SYSCON_General_CMD(ENABLE,ENDIS_EMOSC);
	//ESOSC_OSTR_Config(0XFF,7,EM_SMT_EN);										//ES_CNT=0XFF,ES_GM=7,Enable STM
	//SYSCON_General_CMD(ENABLE,ENDIS_ESOSC);
	SYSCON_HFOSC_SELECTE(HFOSC_SELECTE_48M);									//HFOSC selected 48MHz
	SystemCLK_HCLKDIV_PCLKDIV_Config(SYSCLK_HFOSC,HCLK_DIV_1,PCLK_DIV_1,HFOSC_48M);//system clock set, Hclk div ,Pclk div  set system clock=SystemCLK/Hclk div/Pclk div
//------------  WDT FUNTION  --------------------------------/
    SYSCON_IWDCNT_Config(IWDT_TIME_2S,IWDT_INTW_DIV_7);      					//WDT TIME 1s,WDT alarm interrupt time=1s-1s*1/8=0.875S
    SYSCON_WDT_CMD(DISABLE);                                                  	//enable/disable WDT		
    SYSCON_IWDCNT_Reload();                                                   	//reload WDT
	//IWDT_Int_Enable();
//------------  WWDT FUNTION  --------------------------------/
	//WWDT_CNT_Load(0xFF);
	//WWDT_CONFIG(PCLK_4096_DIV0,0xFF,WWDT_DBGDIS);
	//WWDT_Int_Config(ENABLE);													
	//WWDT_CMD(ENABLE);															//enable wwdt
//------------  CLO Output --------------------------------/	
	/*SYSCON->CLCR = ( 0x100 <<  0 |  // HFOSC.D
                     0X49 <<  9 |  	// HFOSC.FSEL
                     0XA3 << 16 |  	// IMOSC
                     0XA6 << 24 ); 	// ISOSC
	*/			 
	//SYSCON_CLO_CONFIG(CLO_PC00);												//CLO output setting
	//SYSCON_CLO_SRC_SET(0X0A,CLO_DIV8);										//CLO output clock and div
//------------ EVTRG function --------------------------------/ 	
	//SYSCON->EVTRG=0X00|(0x01<<4)|0x03<<20;									//SYSCON_trgsrc0,SYSCON_trgsrc1
	//SYSCON->EVPS=0X00;
	//SYSCON->IMER =EM_EVTRG1_ST|EM_EVTRG0_ST;
//------------  LVD FUNTION  --------------------------------/ 
    SYSCON_LVD_Config(DISABLE_LVDEN,LVDRST_DIS,INTDET_LVL_2_7V,RSTDET_LVL_1_9V,INTDET_POL_fall);   //LVD LVR Enable/Disable
    LVD_Int_Enable();	
//------------  SYSCON Vector  --------------------------------/ 	
	//SYSCON_Int_Enable();    														//SYSCON VECTOR
	//SYSCON_WakeUp_Enable();    													//Enable WDT wakeup INT	
}
/*********************************************************************************/  
/*********************************************************************************/
//APT32F110x_init                                                                  /
//EntryParameter:NONE                                                             /
//ReturnValue:NONE                                                                /
/*********************************************************************************/
/*********************************************************************************/  
/*********************************************************************************/
void APT32F110x_init(void) 
{
//------------------------------------------------------------/
//Peripheral clock enable and disable
//EntryParameter:NONE
//ReturnValue:NONE
//------------------------------------------------------------/
    SYSCON->PCER0=0xFFFFFFF;                                        //PCLK Enable
    SYSCON->PCER1=0xFFFFFFF;                                        //PCLK Enable
    while(!(SYSCON->PCSR0&0x1));                                    //Wait PCLK enabled	
//------------------------------------------------------------/
//ISOSC/IMOSC/EMOSC/SYSCLK/IWDT/LVD/EM_CMFAIL/EM_CMRCV/CMD_ERR OSC stable interrupt
//EntryParameter:NONE
//ReturnValue:NONE
//------------------------------------------------------------/
    SYSCON_CONFIG();                                                 //syscon  initial
	CK_CPU_EnAllNormalIrq();                                         //enable all IRQ
	//SYSCON_INT_Priority();										 //initial all Priority=0xC0
	//Set_INT_Priority(I2C_IRQ,0);									 //0:set int priority 1st
//------------------------------------------------------------/
//Other IP config
//------------------------------------------------------------/
	//GPIO_CONFIG();                                                //GPIO initial     
	//CORET_CONFIG();												//CORET initial
	//EPT0_CONFIG();                                               	//EPT0 initial 
	//GPTA0_CONFIG();												//GPTA0 initial 
	//GPTA1_CONFIG();												//GPTA1 initial 
	//GPTB0_CONFIG();												//GPTB0 initial 
	//GPTB1_CONFIG();												//GPTB1 initial 
	//BT_CONFIG();													//BT initial 
	//COUNTA_CONFIG();                                              //CountA initial	
	//LPT_CONFIG();													//LPT initial 
	//RTC_CONFIG();													//RCT initial		
	//UART0_CONFIG();                                               //UART0 initial 
	//UART1_CONFIG();                                               //UART1 initial 
	//UART2_CONFIG();                                               //UART2 initial 
	//USART_CONFIG();                                              	//USART0 initial 
	//I2C_MASTER_CONFIG();                                          //I2C harware master initial
	//I2C_SLAVE_CONFIG();                                           //I2C harware slave initial
	//SPI_MASTER_CONFIG();											//SPI Master initial
	//SPI_SLAVE_CONFIG();											//SPI Slaver initial
	//SIO_CONFIG();													//SIO initial
	//ETCB_CONFIG();												//ETCB initial 
	//LCD_CONFIG();													//LCD initial
	//LED_CONFIG();													//LED initial 
	//ADC12_CONFIG();                                               //ADC initial
	//CMP_CONFIG();													//CMP initial
	//TKEY_CONFIG();
}

