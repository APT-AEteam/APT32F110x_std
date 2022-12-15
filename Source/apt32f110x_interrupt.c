/*
  ******************************************************************************
  * @file    apt32f110_interrupt.c
  * @author  APT SZ AE Team
  * @version V1.10
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
#include "apt32f110x.h"
#include "apt32f110x_bt.h"
#include "apt32f110x_coret.h"
#include "apt32f110x_countera.h"
#include "apt32f110x_crc.h"
#include "apt32f110x_ept.h"
#include "apt32f110x_gpt.h"
#include "apt32f110x_gpio.h"
#include "apt32f110x_i2c.h"
#include "apt32f110x_ifc.h"
#include "apt32f110x_lpt.h"
#include "apt32f110x_rtc.h"
#include "apt32f110x_sio.h"
#include "apt32f110x_spi.h"
#include "apt32f110x_uart.h"
#include "apt32f110x_usart.h"
#include "apt32f110x_i2c.h"
#include "apt32f110x_syscon.h"
#include "apt32f110x_wwdt.h"
#include "apt32f110x_lcd.h"
#include "apt32f110x_led.h"
#include "apt32f110x_adc.h"
#include "apt32f110x_cmp.h"
#include "apt32f110x_dma.h"
#include "apt32f110x_types_local.h"
#include "tkey.h"
/****************************************************
//defines
*****************************************************/
volatile int R_CMPA_BUF,R_CMPB_BUF;
volatile int R_SIOTX_count,R_SIORX_count;
volatile U32_T R_SIORX_buf[10];
volatile U8_T r_usrat_cont;
volatile U8_T r_usart_buf[3];
/****************************************************
//externs
*****************************************************/
extern void delay_nms(unsigned int t);

/*************************************************************/
//CORET Interrupt
//If you use a touch library file that does not contain coret
//you need to open this interrupt entry
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CORETHandler(void)
{
	// ISR content ...
	CK802->CORET_CVR = 0x0;	
	csi_tkey_basecnt_process();
}
/*************************************************************/
//SYSCON Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SYSCONIntHandler(void) 
{
    // ISR content ...
	if((SYSCON->MISR&ISOSC_ST)==ISOSC_ST)				//ISOSC stable interrupt
	{
		SYSCON->ICR = ISOSC_ST;
	} 
	else if((SYSCON->MISR&IMOSC_ST)==IMOSC_ST)			//IMOSC stable interrupt
	{
		SYSCON->ICR = IMOSC_ST;
	} 
	else if((SYSCON->MISR&EMOSC_ST)==EMOSC_ST)			//EMOSC stable interrupt
	{
		SYSCON->ICR = EMOSC_ST;
	} 
	else if((SYSCON->MISR&HFOSC_ST)==HFOSC_ST)			//HFOSC stable interrupt
	{
		SYSCON->ICR = HFOSC_ST;
	} 
	else if((SYSCON->MISR&SYSCLK_ST)==SYSCLK_ST)		//SYSCLK change end & stable interrupt
	{
		SYSCON->ICR = SYSCLK_ST;
	}
	else if((SYSCON->MISR&IWDT_INT_ST)==IWDT_INT_ST)	//IWDT alarm window interrupt
	{
		SYSCON->ICR = IWDT_INT_ST;
		SYSCON_IWDCNT_Reload(); 
	}
	else if((SYSCON->MISR&WKI_INT_ST)==WKI_INT_ST)
	{
		SYSCON->ICR = WKI_INT_ST;
	}
	else if((SYSCON->MISR&RAMERRINT_ST)==RAMERRINT_ST)	//SRAM check fail interrupt
	{
		SYSCON->ICR = RAMERRINT_ST;
	}
	else if((SYSCON->MISR&LVD_INT_ST)==LVD_INT_ST)		//LVD threshold interrupt
	{
		SYSCON->ICR = LVD_INT_ST;
	}
	else if((SYSCON->MISR&HWD_ERR_ST)==HWD_ERR_ST)		//Hardware Divider divisor = 0 interrupt
	{
		SYSCON->ICR = HWD_ERR_ST;
	}
	else if((SYSCON->MISR&EFL_ERR_ST)==EFL_ERR_ST)		//Flash check fail interrupt
	{
		SYSCON->ICR = EFL_ERR_ST;
	}
	else if((SYSCON->MISR&OPTERR_INT)==OPTERR_INT)		//Option load fail interrupt
	{
		SYSCON->ICR = OPTERR_INT;
	}
	else if((SYSCON->MISR&EM_CMLST_ST)==EM_CMLST_ST)	//EMOSC clock monitor fail interrupt
	{
		SYSCON->ICR = EM_CMLST_ST;
	}
	else if((SYSCON->MISR&EM_EVTRG0_ST)==EM_EVTRG0_ST)	//Event Trigger Channel 0 Interrupt
	{
		SYSCON->ICR = EM_EVTRG0_ST;
	}
	else if((SYSCON->MISR&EM_EVTRG1_ST)==EM_EVTRG1_ST)	//Event Trigger Channel 1 Interrupt
	{
		SYSCON->ICR = EM_EVTRG1_ST;
	}
	else if((SYSCON->MISR&EM_EVTRG2_ST)==EM_EVTRG2_ST)	//Event Trigger Channel 2 Interrupt
	{
		SYSCON->ICR = EM_EVTRG2_ST;
	}
	else if((SYSCON->MISR&EM_EVTRG3_ST)==EM_EVTRG3_ST)	//Event Trigger Channel 3 Interrupt
	{
		SYSCON->ICR = EM_EVTRG3_ST;
	}
	else if((SYSCON->MISR&CMD_ERR_ST)==CMD_ERR_ST)		//Command error interrupt
	{
		SYSCON->ICR = CMD_ERR_ST;
	}
}
/*************************************************************/
//IFC Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
volatile U8_T ifc_step,f_Drom_write_complete;
void IFCIntHandler(void) 
{
    // ISR content ...
	if(IFC->MISR&ERS_END_INT)			
	{
		IFC->ICR=ERS_END_INT;
		if((ifc_step==1)&&(f_Drom_writing==1))
		{
			SetUserKey;
			IFC->CMR=0x01;					//将页缓存的数据写入闪存中
			IFC->FM_ADDR=R_INT_FlashAdd;		//
			IFC->CR=0X01;					//Start Program
			ifc_step=2;
		}
	}
	else if(IFC->MISR&RGM_END_INT)		
	{
		IFC->ICR=RGM_END_INT;
		if((ifc_step==2)&&(f_Drom_writing==1))
		{
			f_Drom_writing=0;
			f_Drom_write_complete=1;
		}
	}
	else if(IFC->MISR&PEP_END_INT)		
	{
		IFC->ICR=PEP_END_INT;
		if((ifc_step==0)&&(f_Drom_writing==1))
		{
			SetUserKey;
			IFC->CMR=0x02;					//页擦除
			IFC->FM_ADDR=R_INT_FlashAdd;			//
			IFC->CR=0X01;					//Start Program
			ifc_step=1;
		}
	}
	else if(IFC->MISR&PROT_ERR_INT)		
	{
		IFC->ICR=PROT_ERR_INT;
	}
	else if(IFC->MISR&UDEF_ERR_INT)		
	{
		IFC->ICR=UDEF_ERR_INT;
	}
	else if(IFC->MISR&ADDR_ERR_INT)		
	{
		IFC->ICR=ADDR_ERR_INT;
	}
	else if(IFC->MISR&OVW_ERR_INT)		
	{
		IFC->ICR=OVW_ERR_INT;
	}
}
/*************************************************************/
//ADC Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void ADCIntHandler(void) 
{
    // ISR content ...
	if((ADC0->SR&ADC12_EOC)==ADC12_EOC)				//ADC EOC interrupt
	{
		ADC0->CSR = ADC12_EOC;
	}
	else if((ADC0->SR&ADC12_READY)==ADC12_READY)	//ADC READY interrupt
	{
		ADC0->CSR = ADC12_READY;
	}
	else if((ADC0->SR&ADC12_OVR)==ADC12_OVR)		//ADC OVR interrupt
	{
		ADC0->CSR = ADC12_OVR;
	}
	else if((ADC0->SR&ADC12_CMP0H)==ADC12_CMP0H)	//ADC CMP0H interrupt
	{
		ADC0->CSR = ADC12_CMP0H;
	}
	else if((ADC0->SR&ADC12_CMP0L)==ADC12_CMP0L)	//ADC CMP0L interrupt.
	{
		ADC0->CSR = ADC12_CMP0L;
	}
	else if((ADC0->SR&ADC12_CMP1H)==ADC12_CMP1H)	//ADC CMP1H interrupt.
	{
		ADC0->CSR = ADC12_CMP1H;
	}
	else if((ADC0->SR&ADC12_CMP1L)==ADC12_CMP1L)	//ADC CMP1L interrupt.
	{
		ADC0->CSR = ADC12_CMP1L;
	}
	else if((ADC0->SR&ADC12_SEQ_END0)==ADC12_SEQ_END0) //ADC SEQ0 interrupt,SEQ1~SEQ15 replace the parameter with ADC12_SEQ_END1~ADC12_SEQ_END15
	{
		ADC0->CSR = ADC12_SEQ_END0;
	}
}
/*************************************************************/
//EPT0 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EPT0IntHandler(void) 
{
    // ISR content ...
	if((EPT0->MISR&EPT_TRGEV0_INT)==EPT_TRGEV0_INT)			//TRGEV0 interrupt
	{
		EPT0->ICR=EPT_TRGEV0_INT;
	}
	else if((EPT0->MISR&EPT_TRGEV1_INT)==EPT_TRGEV1_INT)	//TRGEV1 interrupt
	{
		EPT0->ICR=EPT_TRGEV1_INT;
	}
	else if((EPT0->MISR&EPT_TRGEV2_INT)==EPT_TRGEV2_INT)	//TRGEV2 interrupt
	{
		EPT0->ICR=EPT_TRGEV2_INT;
	}
	else if((EPT0->MISR&EPT_TRGEV3_INT)==EPT_TRGEV3_INT)	//TRGEV3 interrupt
	{
		EPT0->ICR=EPT_TRGEV3_INT;
	}	
	else if((EPT0->MISR&EPT_CAP_LD0)==EPT_CAP_LD0)			//Capture Load to CMPA interrupt
	{
		EPT0->ICR=EPT_CAP_LD0;
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIRT);
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIFT);
		
		R_CMPA_BUF=EPT0->CMPA;			//period counter
	}
	else if((EPT0->MISR&EPT_CAP_LD1)==EPT_CAP_LD1)			//Capture Load to CMPB interrupt
	{
		EPT0->ICR=EPT_CAP_LD1;
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIRT);
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIFT);
		R_CMPB_BUF=EPT0->CMPB;			//Duty counter
	}
	else if((EPT0->MISR&EPT_CAP_LD2)==EPT_CAP_LD2)			//Capture Load to CMPC interrupt
	{
		EPT0->ICR=EPT_CAP_LD2;
	}
	else if((EPT0->MISR&EPT_CAP_LD3)==EPT_CAP_LD3)			//Capture Load to CMPD interrupt
	{
		EPT0->ICR=EPT_CAP_LD3;
	}
	else if((EPT0->MISR&EPT_CAU)==EPT_CAU)					//Up-Counting phase CNT = CMPA interrupt
	{
		EPT0->ICR=EPT_CAU;
	}
	else if((EPT0->MISR&EPT_CAD)==EPT_CAD)					//Down-Counting phase CNT = CMPA interrupt
	{
		EPT0->ICR=EPT_CAD;
	}
	else if((EPT0->MISR&EPT_CBU)==EPT_CBU)					//Up-Counting phase CNT = CMPB interrupt 
	{
		EPT0->ICR=EPT_CBU;
	}
	else if((EPT0->MISR&EPT_CBD)==EPT_CBD)					//Down-Counting phase CNT = CMPB interrupt
	{
		EPT0->ICR=EPT_CBD;
	}
	else if((EPT0->MISR&EPT_CCU)==EPT_CCU)					//Up-Counting phase CNT = CMPC interrupt 
	{
		EPT0->ICR=EPT_CCU;
	}
	else if((EPT0->MISR&EPT_CCD)==EPT_CCD)					//Down-Counting phase CNT = CMPC interrupt
	{
		EPT0->ICR=EPT_CCD;
	}
	else if((EPT0->MISR&EPT_CDU)==EPT_CDU)					//Up-Counting phase CNT = CMPD interrupt
	{
		EPT0->ICR=EPT_CDU;
	}
	else if((EPT0->MISR&EPT_CDD)==EPT_CDD)					//Down-Counting phase CNT = CMPD interrupt
	{
		EPT0->ICR=EPT_CDD;
	}
	else if((EPT0->MISR&EPT_PEND)==EPT_PEND)				//End of cycle interrupt
	{
		EPT0->ICR=EPT_PEND;
	}
	//Emergency interruption
	if((EPT0->EMMISR&EPT_EP0_EMINT)==EPT_EP0_EMINT)			//interrupt flag of EP0 event
	{
		EPT0->EMICR=EPT_EP0_EMINT;
	}
	else if((EPT0->EMMISR&EPT_EP1_EMINT)==EPT_EP1_EMINT)	//interrupt flag of EP1 event
	{
		EPT0->EMICR=EPT_EP1_EMINT;
	}
	else if((EPT0->EMMISR&EPT_EP2_EMINT)==EPT_EP2_EMINT)	//interrupt flag of EP2 event
	{
		EPT0->EMICR=EPT_EP2_EMINT;
	}
	else if((EPT0->EMMISR&EPT_EP3_EMINT)==EPT_EP3_EMINT)	//interrupt flag of EP3 event
	{
		EPT0->EMICR=EPT_EP3_EMINT;
	}
	else if((EPT0->EMMISR&EPT_EP4_EMINT)==EPT_EP4_EMINT)	//interrupt flag of EP4 event
	{
		EPT0->EMICR=EPT_EP4_EMINT;
	}
	else if((EPT0->EMMISR&EPT_EP5_EMINT)==EPT_EP5_EMINT)	//interrupt flag of EP5 event
	{
		EPT0->EMICR=EPT_EP5_EMINT;
	}
	else if((EPT0->EMMISR&EPT_EP6_EMINT)==EPT_EP6_EMINT)	//interrupt flag of EP6 event
	{
		EPT0->EMICR=EPT_EP6_EMINT;
	}
	else if((EPT0->EMMISR&EPT_EP7_EMINT)==EPT_EP7_EMINT)	//interrupt flag of EP7 event
	{
		EPT0->EMICR=EPT_EP7_EMINT;
	}
	else if((EPT0->EMMISR&EPT_CPU_FAULT_EMINT)==EPT_CPU_FAULT_EMINT)	//interrupt flag of CPU_FAULT event
	{
		EPT0->EMICR=EPT_CPU_FAULT_EMINT;
	}
	else if((EPT0->EMMISR&EPT_MEM_FAULT_EMINT)==EPT_MEM_FAULT_EMINT)	//interrupt flag of MEM_FAULT event
	{
		EPT0->EMICR=EPT_MEM_FAULT_EMINT;
	}
	else if((EPT0->EMMISR&EPT_EOM_FAULT_EMINT)==EPT_EOM_FAULT_EMINT)	//interrupt flag of EOM_FAULT event
	{
		EPT0->EMICR=EPT_EOM_FAULT_EMINT;
	}
}
/*************************************************************/
//WWDT Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void WWDTIntHandler(void)
{
	WWDT->ICR=0X01;
	WWDT_CNT_Load(0xFF);
	GPIO_Init(GPIOA0,4,0);
	GPIO_Reverse(GPIOA0,4);
	
	if((WWDT->MISR&WWDT_EVI)==WWDT_EVI)
	{
		WWDT->ICR = WWDT_EVI;
	} 
}
/*************************************************************/
//DMA Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void DMAIntHandler(void)
{
	 // ISR content ...
	if((DMA->ISR&DMA0_LTCIT)==DMA0_LTCIT)			//CH0 L 完成
	{
		nop;
		DMA->ICR=DMA0_LTCIT;
	}	
	if((DMA->ISR&DMA1_LTCIT)==DMA1_LTCIT)			//CH1 L 完成
	{
		nop;
		DMA->ICR=DMA1_LTCIT;
	}
	if((DMA->ISR&DMA2_LTCIT)==DMA2_LTCIT)			//CH2 L 完成
	{
		nop;
		DMA->ICR=DMA2_LTCIT;
	}
	if((DMA->ISR&DMA3_LTCIT)==DMA3_LTCIT)			//CH3 L 完成
	{
		nop;
		DMA->ICR=DMA3_LTCIT;
	}
	if((DMA->ISR&DMA0_TCIT)==DMA0_TCIT)				//CH0 L H 完成	
	{
		nop;
		DMA->ICR=DMA0_TCIT;
	}
	if((DMA->ISR&DMA1_TCIT)==DMA1_TCIT)				//CH1 L H 完成	
	{
		nop;
		DMA->ICR=DMA1_TCIT;
	}
	if((DMA->ISR&DMA2_TCIT)==DMA2_TCIT)				//CH2 L H 完成	
	{
		nop;
		DMA->ICR=DMA2_TCIT;
	}
	if((DMA->ISR&DMA3_TCIT)==DMA3_TCIT)				//CH3 L H 完成	
	{
		nop;
		DMA->ICR=DMA3_TCIT;
	}
}
/*************************************************************/
//WWDT Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void WWDTInTHandler(void)
{
	WWDT->ICR=0X01;
	WWDT_CNT_Load(0xFF);
	if((WWDT->MISR&WWDT_EVI)==WWDT_EVI)					//WWDT EVI interrupt
	{
		WWDT->ICR = WWDT_EVI;
	} 
}
/*************************************************************/
//GPTA0 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void GPTA0IntHandler(void) 
{
    // ISR content ...
	if((GPTA0->MISR&GPT_TRGEV0_INT)==GPT_TRGEV0_INT)			//TRGEV0 interrupt
	{
		GPTA0->ICR = GPT_TRGEV0_INT;
	} 
	else if((GPTA0->MISR&GPT_TRGEV1_INT)==GPT_TRGEV1_INT)	//TRGEV1 interrupt
	{
		GPTA0->ICR = GPT_TRGEV1_INT;
	}
	else if((GPTA0->MISR&GPT_CAP_LD0)==GPT_CAP_LD0)		//Capture Load to CMPA interrupt
	{
		GPTA0->ICR = GPT_CAP_LD0;
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIRT);
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIFT);
		
		R_CMPA_BUF=GPTA0->CMPA;			//period counter
	}
	else if((GPTA0->MISR&GPT_CAP_LD1)==GPT_CAP_LD1)		//Capture Load to CMPB interrupt
	{
		GPTA0->ICR = GPT_CAP_LD1;
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIRT);
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIFT);
		R_CMPB_BUF=GPTA0->CMPB;			//Duty counter
	}
	else if((GPTA0->MISR&GPT_CAU)==GPT_CAU)			//Up-Counting phase CNT = CMPA Interrupt
	{
		GPTA0->ICR = GPT_CAU;
		
	}
	else if((GPTA0->MISR&GPT_CAD)==GPT_CAD)			//Down-Counting phase CNT = CMPA Interrupt
	{
		GPTA0->ICR = GPT_CAD;
	}
	else if((GPTA0->MISR&GPT_CBU)==GPT_CBU)			//Up-Counting phase CNT = CMPB Interrupt
	{
		GPTA0->ICR = GPT_CBU;
	}
	else if((GPTA0->MISR&GPT_CBD)==GPT_CBD)			//Down-Counting phase CNT = CMPB Interrupt
	{
		GPTA0->ICR = GPT_CBD;
	}
	else if((GPTA0->MISR&GPT_PEND)==GPT_PEND)		//End of cycle interrupt 
	{
		GPTA0->ICR = GPT_PEND;
	}
}
/*************************************************************/
//GPTA1 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void GPTA1IntHandler(void) 
{
	 // ISR content ...
	if((GPTA1->MISR&GPT_TRGEV0_INT)==GPT_TRGEV0_INT)			//TRGEV0 interrupt
	{
		GPTA1->ICR = GPT_TRGEV0_INT;
	} 
	else if((GPTA1->MISR&GPT_TRGEV1_INT)==GPT_TRGEV1_INT)	//TRGEV1 interrupt
	{
		GPTA1->ICR = GPT_TRGEV1_INT;
	}
	else if((GPTA1->MISR&GPT_CAP_LD0)==GPT_CAP_LD0)		//Capture Load to CMPA interrupt
	{
		GPTA1->ICR = GPT_CAP_LD0;
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIRT);
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIFT);
		
		R_CMPA_BUF=GPTA1->CMPA;			//period counter
	}
	else if((GPTA1->MISR&GPT_CAP_LD1)==GPT_CAP_LD1)		//Capture Load to CMPB interrupt
	{
		GPTA1->ICR = GPT_CAP_LD1;
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIRT);
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIFT);
		R_CMPB_BUF=GPTA1->CMPB;			//Duty counter
	}
	else if((GPTA1->MISR&GPT_CAU)==GPT_CAU)			//Up-Counting phase CNT = CMPA Interrupt
	{
		GPTA1->ICR = GPT_CAU;
	}
	else if((GPTA1->MISR&GPT_CAD)==GPT_CAD)			//Down-Counting phase CNT = CMPA Interrupt
	{
		GPTA1->ICR = GPT_CAD;
	}
	else if((GPTA1->MISR&GPT_CBU)==GPT_CBU)			//Up-Counting phase CNT = CMPB Interrupt
	{
		GPTA1->ICR = GPT_CBU;
	}
	else if((GPTA1->MISR&GPT_CBD)==GPT_CBD)			//Down-Counting phase CNT = CMPB Interrupt
	{
		GPTA1->ICR = GPT_CBD;
	}
	else if((GPTA1->MISR&GPT_PEND)==GPT_PEND)		//End of cycle interrupt 
	{
		GPTA1->ICR = GPT_PEND;
	}
}

U16_T buzz_cnt=0;
U8_T buzz_on_f=0;
U16_T sleep_cnt;
U8_T sleep_f;
/*************************************************************/
//GPTB0 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void GPTB0IntHandler(void) 
{
	buzz_cnt++;
	if(buzz_cnt>199)
	{
		buzz_cnt=0;
		buzz_on_f=1;
	}
	if((GPTB0->MISR&GPT_TRGEV0_INT)==GPT_TRGEV0_INT)			//TRGEV0 interrupt
	{
		GPTB0->ICR = GPT_TRGEV0_INT;
	} 
	else if((GPTB0->MISR&GPT_TRGEV1_INT)==GPT_TRGEV1_INT)	//TRGEV1 interrupt
	{
		GPTB0->ICR = GPT_TRGEV1_INT;
	}
	else if((GPTB0->MISR&GPT_CAP_LD0)==GPT_CAP_LD0)		//Capture Load to CMPA interrupt
	{
		GPTB0->ICR = GPT_CAP_LD0;
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIRT);
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIFT);
		
		R_CMPA_BUF=GPTB0->CMPA;			//period counter
	}
	else if((GPTB0->MISR&GPT_CAP_LD1)==GPT_CAP_LD1)		//Capture Load to CMPB interrupt
	{
		GPTB0->ICR = GPT_CAP_LD1;
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIRT);
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIFT);
		R_CMPB_BUF=GPTB0->CMPB;			//Duty counter
	}
	else if((GPTB0->MISR&GPT_CAU)==GPT_CAU)			//Up-Counting phase CNT = CMPA Interrupt
	{
		GPTB0->ICR = GPT_CAU;
	}
	else if((GPTB0->MISR&GPT_CAD)==GPT_CAD)			//Down-Counting phase CNT = CMPA Interrupt
	{
		GPTB0->ICR = GPT_CAD;
	}
	else if((GPTB0->MISR&GPT_CBU)==GPT_CBU)			//Up-Counting phase CNT = CMPB Interrupt
	{
		GPTB0->ICR = GPT_CBU;
	}
	else if((GPTB0->MISR&GPT_CBD)==GPT_CBD)			//Down-Counting phase CNT = CMPB Interrupt
	{
		GPTB0->ICR = GPT_CBD;
	}
	else if((GPTB0->MISR&GPT_PEND)==GPT_PEND)		//End of cycle interrupt 
	{
		GPTB0->ICR = GPT_PEND;
	}
	//Emergency interruption
	if((GPTB0->EMMISR&GPT_EP0_EMINT)==GPT_EP0_EMINT)			//interrupt flag of EP0 event
	{
		GPTB0->EMICR=GPT_EP0_EMINT;
	}
	else if((GPTB0->EMMISR&GPT_EP1_EMINT)==GPT_EP1_EMINT)	//interrupt flag of EP1 event
	{
		GPTB0->EMICR=EPT_EP1_EMINT;
	}
	else if((GPTB0->EMMISR&GPT_EP2_EMINT)==GPT_EP2_EMINT)	//interrupt flag of EP2 event
	{
		GPTB0->EMICR=GPT_EP2_EMINT;
	}
	else if((GPTB0->EMMISR&GPT_EP3_EMINT)==GPT_EP3_EMINT)	//interrupt flag of EP3 event
	{
		GPTB0->EMICR=GPT_EP3_EMINT;
	}
	else if((GPTB0->EMMISR&GPT_CPU_FAULT_EMINT)==GPT_CPU_FAULT_EMINT)	//interrupt flag of CPU_FAULT event
	{
		GPTB0->EMICR=GPT_CPU_FAULT_EMINT;
	}
	else if((GPTB0->EMMISR&GPT_MEM_FAULT_EMINT)==GPT_MEM_FAULT_EMINT)	//interrupt flag of MEM_FAULT event
	{
		GPTB0->EMICR=GPT_MEM_FAULT_EMINT;
	}
	else if((GPTB0->EMMISR&GPT_EOM_FAULT_EMINT)==GPT_EOM_FAULT_EMINT)	//interrupt flag of EOM_FAULT event
	{
		GPTB0->EMICR=GPT_EOM_FAULT_EMINT;
	}
}
/*************************************************************/
//GPTB1 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void GPTB1IntHandler(void) 
{
	if((GPTB1->MISR&GPT_TRGEV0_INT)==GPT_TRGEV0_INT)			//TRGEV0 interrupt
	{
		GPTB1->ICR = GPT_TRGEV0_INT;
	} 
	else if((GPTB1->MISR&GPT_TRGEV1_INT)==GPT_TRGEV1_INT)	//TRGEV1 interrupt
	{
		GPTB1->ICR = GPT_TRGEV1_INT;
	}
	else if((GPTB1->MISR&GPT_CAP_LD0)==GPT_CAP_LD0)		//Capture Load to CMPA interrupt
	{
		GPTB1->ICR = GPT_CAP_LD0;
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIRT);
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIFT);
		
		R_CMPA_BUF=GPTB1->CMPA;			//period counter
	}
	else if((GPTB1->MISR&GPT_CAP_LD1)==GPT_CAP_LD1)		//Capture Load to CMPB interrupt
	{
		GPTB1->ICR = GPT_CAP_LD1;
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIRT);
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIFT);
		R_CMPB_BUF=GPTB1->CMPB;			//Duty counter
	}
	else if((GPTB1->MISR&GPT_CAU)==GPT_CAU)			//Up-Counting phase CNT = CMPA Interrupt
	{
		GPTB1->ICR = GPT_CAU;
	}
	else if((GPTB1->MISR&GPT_CAD)==GPT_CAD)			//Down-Counting phase CNT = CMPA Interrupt
	{
		GPTB1->ICR = GPT_CAD;
	}
	else if((GPTB1->MISR&GPT_CBU)==GPT_CBU)			//Up-Counting phase CNT = CMPB Interrupt
	{
		GPTB1->ICR = GPT_CBU;
	}
	else if((GPTB1->MISR&GPT_CBD)==GPT_CBD)			//Down-Counting phase CNT = CMPB Interrupt
	{
		GPTB1->ICR = GPT_CBD;
	}
	else if((GPTB1->MISR&GPT_PEND)==GPT_PEND)		//End of cycle interrupt 
	{
		GPTB1->ICR = GPT_PEND;
	}
	//Emergency interruption
	if((GPTB1->EMMISR&GPT_EP0_EMINT)==GPT_EP0_EMINT)			//interrupt flag of EP0 event
	{
		GPTB1->EMICR=GPT_EP0_EMINT;
	}
	else if((GPTB1->EMMISR&GPT_EP1_EMINT)==GPT_EP1_EMINT)	//interrupt flag of EP1 event
	{
		GPTB1->EMICR=GPT_EP1_EMINT;
	}
	else if((GPTB1->EMMISR&GPT_EP2_EMINT)==GPT_EP2_EMINT)	//interrupt flag of EP2 event
	{
		GPTB1->EMICR=GPT_EP2_EMINT;
	}
	else if((GPTB1->EMMISR&GPT_EP3_EMINT)==GPT_EP3_EMINT)	//interrupt flag of EP3 event
	{
		GPTB1->EMICR=GPT_EP3_EMINT;
	}
	else if((GPTB1->EMMISR&GPT_CPU_FAULT_EMINT)==GPT_CPU_FAULT_EMINT)	//interrupt flag of CPU_FAULT event
	{
		GPTB1->EMICR=GPT_CPU_FAULT_EMINT;
	}
	else if((GPTB1->EMMISR&GPT_MEM_FAULT_EMINT)==GPT_MEM_FAULT_EMINT)	//interrupt flag of MEM_FAULT event
	{
		GPTB1->EMICR=GPT_MEM_FAULT_EMINT;
	}
	else if((GPTB1->EMMISR&GPT_EOM_FAULT_EMINT)==GPT_EOM_FAULT_EMINT)	//interrupt flag of EOM_FAULT event
	{
		GPTB1->EMICR=GPT_EOM_FAULT_EMINT;
	}
}
/*************************************************************/
//RTC Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void RTCIntHandler(void) 
{
    // ISR content ...
	if((RTC->MISR&ALRA_INT)==ALRA_INT)			//Interrupt of alarm A
	{
		RTC->ICR=ALRA_INT;
	}
	else if((RTC->MISR&ALRB_INT)==ALRB_INT)			//Interrupt of alarm B				
	{
		RTC->ICR=ALRB_INT;
	}
	else if((RTC->MISR&CPRD_INT)==CPRD_INT)			//Interrupt of alarm CPRD
	{
		RTC->ICR=CPRD_INT;
	}
	else if((RTC->MISR&RTC_TRGEV0_INT)==RTC_TRGEV0_INT)		//Interrupt of trigger event 0
	{
		RTC->ICR=RTC_TRGEV0_INT;
	}
	else if((RTC->MISR&RTC_TRGEV1_INT)==RTC_TRGEV1_INT)		//Interrupt of trigger event 1
	{
		RTC->ICR=RTC_TRGEV1_INT;
	}
}
/*************************************************************/
//UART0 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART0IntHandler(void) 
{
    // ISR content ...	
	if ((UART0->ISR&UART_RX_INT_S)==UART_RX_INT_S)				//RX interrupt
	{
		UART0->ISR=UART_RX_INT_S;
		RxDataFlag = TRUE;
	}
	else if( (UART0->ISR&UART_TX_INT_S)==UART_TX_INT_S ) 		//TX interrupt
    {
		UART0->ISR=UART_TX_INT_S;
		TxDataFlag = TRUE;
	}
	else if ((UART0->ISR&UART_RX_IOV_S)==UART_RX_IOV_S)			//RX overrun interrupt
	{
		UART0->ISR=UART_RX_IOV_S;
	}
	else if ((UART0->ISR&UART_TX_IOV_S)==UART_TX_IOV_S)			//TX overrun interrupt
	{
		UART0->ISR=UART_TX_IOV_S;
	}
}
/*************************************************************/
//UART1 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART1IntHandler(void) 
{
    // ISR content ...
	if ((UART1->ISR&UART_RX_INT_S)==UART_RX_INT_S)				//RX interrupt
	{
		UART1->ISR=UART_RX_INT_S;
		RxDataFlag = TRUE;
	}
	else if( (UART1->ISR&UART_TX_INT_S)==UART_TX_INT_S ) 		//TX interrupt
    {
		UART1->ISR=UART_TX_INT_S;
		TxDataFlag = TRUE;
	}
	else if ((UART1->ISR&UART_RX_IOV_S)==UART_RX_IOV_S)			//RX overrun interrupt
	{
		UART1->ISR=UART_RX_IOV_S;
	}
	else if ((UART1->ISR&UART_TX_IOV_S)==UART_TX_IOV_S)			//TX overrun interrupt
	{
		UART1->ISR=UART_TX_IOV_S;
	}
}
/*************************************************************/
//UART2 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART2IntHandler(void) 
{
    // ISR content ...
	if ((UART2->ISR&UART_RX_INT_S)==UART_RX_INT_S)				//RX interrupt
	{
		UART2->ISR=UART_RX_INT_S;
		RxDataFlag = TRUE;
	}
	else if( (UART2->ISR&UART_TX_INT_S)==UART_TX_INT_S ) 		//TX interrupt
    {
		//UART2->ISR=UART_TX_INT_S;
		TxDataFlag = TRUE;
	}
	else if ((UART2->ISR&UART_RX_IOV_S)==UART_RX_IOV_S)			//RX overrun interrupt
	{
		UART2->ISR=UART_RX_IOV_S;
	}
	else if ((UART2->ISR&UART_TX_IOV_S)==UART_TX_IOV_S)			//TX overrun interrupt
	{
		UART2->ISR=UART_TX_IOV_S;
	}
}
/*************************************************************/
//USART Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void USART0IntHandler(void) 
{
	unsigned int status;
	status = USART0->MISR & USART0->IMSCR ;
	if( status & USART_RXRDY ) 
	{
	   r_usrat_cont++;
		if(r_usrat_cont>=3)
		{
			r_usrat_cont=0;
		}
		r_usart_buf[r_usrat_cont]=CSP_USART_GET_RHR(USART0);
		CSP_USART_SET_ICR(USART0, USART_RXRDY);
	}
	if (status & USART_TXRDY) 
	{
		//CSP_USART_SET_ICR(USART0, USART_TXRDY);
	}
}
/*************************************************************/
//I2C Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2CIntHandler(void) 
{
    // ISR content ...
	I2C_Slave_Receive();										//I2C slave receive function in interruption
}
/*************************************************************/
//SPI Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SPI0IntHandler(void) 
{
	// ISR content ...
	if((SPI0->MISR&SPI_PORIM)==SPI_PORIM)					//Receive Overrun Interrupt
	{
		SPI0->ICR = SPI_PORIM;
	} 
	else if((SPI0->MISR&SPI_RTIM)==SPI_RTIM)				//Receive Timeout Interrupt
	{
		SPI0->ICR = SPI_RTIM;
	}
	else if((SPI0->MISR&SPI_RXIM)==SPI_RXIM)				//Receive FIFO Interrupt,FIFO can be set 1/8,1/4,1/2 FIFO Interrupt
	{
		SPI0->ICR = SPI_RXIM;
		if(SPI0->DR==0xaa)
		{
			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
			SPI0->DR = 0x11;
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
			
			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
			SPI0->DR = 0x12;
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
			
			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
			SPI0->DR = 0x13;
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
			
			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
			SPI0->DR = 0x14;
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
			
			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
			SPI0->DR = 0x15;
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
			
			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
			SPI0->DR = 0x16;
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
			
			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
			SPI0->DR = 0x17;
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
			
			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
			SPI0->DR = 0x18;
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
		}
		else
		{
			if(((SPI0->SR) & SSP_TFE)!=SSP_TFE)
			{
				SPI0->DR=0x0;								//FIFO空
				SPI0->DR=0x0;								//FIFO空
				SPI0->DR=0x0;								//FIFO空
				SPI0->DR=0x0;								//FIFO空
				SPI0->DR=0x0;								//FIFO空
				SPI0->DR=0x0;								//FIFO空
				SPI0->DR=0x0;								//FIFO空
				SPI0->DR=0x0;								//FIFO空
				while(((SPI0->SR) & SSP_BSY) == SSP_BSY);		//发送或接收是否完成？
			}
		}
	}
	else if((SPI0->MISR&SPI_TXIM)==SPI_TXIM)				//Transmit FIFO Interrupt
	{
		SPI0->ICR = SPI_TXIM;
	}
}
/*************************************************************/
//SIO Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SIO0IntHandler(void) 
{
    // ISR content ...
	//序列超过16bit法发送程序方法，1.在主循环查询吧中断关掉 2.在中断里面做且把优先级设置最高
	/*CK801->IPR[0]=0X40404040;
	CK801->IPR[1]=0X40404040;
	CK801->IPR[2]=0X40404040;
	CK801->IPR[3]=0X40404040;
	CK801->IPR[4]=0X40404040;
	CK801->IPR[5]=0X40404000;
	CK801->IPR[6]=0X40404040;
	CK801->IPR[7]=0X40404040;*/
	
	//序列小于16bit发送程序
	if(SIO0->MISR&SIO_TXDNE)							//TXDNE
	{
		SIO0->ICR=SIO_TXDNE;
		nop;
	}
	else if(SIO0->MISR&SIO_RXDNE)						//RXDNE 
	{
		SIO0->ICR=SIO_RXDNE;
		/*if(R_SIORX_count>=1)
		{
			R_SIORX_buf[R_SIORX_count]=SIO0->RXBUF;			
			nop;
			R_SIORX_count=0;
		}*/
	}
	else if(SIO0->MISR&SIO_TXBUFEMPT)
	{
		SIO0->ICR=SIO_TXBUFEMPT;
	}
	else if(SIO0->MISR&SIO_RXBUFEMPT)					//RXBUFFULL	
	{
		SIO0->ICR=SIO_RXBUFEMPT;
		//if(R_SIORX_count<1)
		//{
			R_SIORX_buf[R_SIORX_count]=SIO0->RXBUF;		
			R_SIORX_count++;
		//}
		if(R_SIORX_count>=2)
			R_SIORX_count=0;
	}
	else if(SIO0->MISR&SIO_BREAK)						//BREAK
	{
		SIO0->ICR=SIO_BREAK;
		nop;
	}
	else if(SIO0->MISR&SIO_TIME)						//TIMEOUT
	{
		SIO0->ICR=SIO_TIME;
	}
}
/*************************************************************/
//EXT0/16 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI0IntHandler(void) 
{
    // ISR content ...
	if ((SYSCON->EXIRS&EXI_PIN0)==EXI_PIN0) 			//EXT0 Interrupt
	{
		SYSCON->EXICR = EXI_PIN0;
	}
	else if ((SYSCON->EXIRS&EXI_PIN16)==EXI_PIN16) 		//EXT16 Interrupt
	{
		SYSCON->EXICR = EXI_PIN16;
	}
}
/*************************************************************/
//EXT1/17 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI1IntHandler(void) 
{
    // ISR content ...
	if ((SYSCON->EXIRS&EXI_PIN1)==EXI_PIN1) 			//EXT1 Interrupt
	{
		SYSCON->EXICR = EXI_PIN1;
	}
	else if ((SYSCON->EXIRS&EXI_PIN17)==EXI_PIN17) 		//EXT17 Interrupt
	{
		SYSCON->EXICR = EXI_PIN17;
	}
}
/*************************************************************/
//EXI2~3 18~19Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI2to3IntHandler(void) 
{
    // ISR content ...
	if ((SYSCON->EXIRS&EXI_PIN2)==EXI_PIN2) 			//EXT2 Interrupt
	{
		SYSCON->EXICR = EXI_PIN2;
	} 
	else if ((SYSCON->EXIRS&EXI_PIN3)==EXI_PIN3) 		//EXT3 Interrupt
	{
		SYSCON->EXICR = EXI_PIN3;
	}
	else if ((SYSCON->EXIRS&EXI_PIN18)==EXI_PIN18) 		//EXT18 Interrupt
	{
		SYSCON->EXICR = EXI_PIN18;
	}
	else if ((SYSCON->EXIRS&EXI_PIN19)==EXI_PIN19) 		//EXT19 Interrupt
	{
		SYSCON->EXICR = EXI_PIN19;
	}
}
/*************************************************************/
//EXI4~9 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI4to9IntHandler(void) 
{
    // ISR content ...
	if ((SYSCON->EXIRS&EXI_PIN4)==EXI_PIN4) 			//EXT4 Interrupt
	{
		SYSCON->EXICR = EXI_PIN4;
	} 
	else if ((SYSCON->EXIRS&EXI_PIN5)==EXI_PIN5) 		//EXT5 Interrupt
	{
		SYSCON->EXICR = EXI_PIN5;
	} 
	else if ((SYSCON->EXIRS&EXI_PIN6)==EXI_PIN6) 		//EXT6 Interrupt
	{
		SYSCON->EXICR = EXI_PIN6;
	} 
	else if ((SYSCON->EXIRS&EXI_PIN7)==EXI_PIN7) 		//EXT7 Interrupt
	{
		SYSCON->EXICR = EXI_PIN7;
	} 
	else if ((SYSCON->EXIRS&EXI_PIN8)==EXI_PIN8) 		//EXT8 Interrupt
	{
		SYSCON->EXICR = EXI_PIN8;
	}
	else if ((SYSCON->EXIRS&EXI_PIN9)==EXI_PIN9) 		//EXT9 Interrupt
	{
		SYSCON->EXICR = EXI_PIN9;
	} 

}
/*************************************************************/
//EXI4 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI10to15IntHandler(void) 
{
    // ISR content ...
	if ((SYSCON->EXIRS&EXI_PIN10)==EXI_PIN10) 			//EXT10 Interrupt
	{
		SYSCON->EXICR = EXI_PIN10;
	} 
	else if ((SYSCON->EXIRS&EXI_PIN11)==EXI_PIN11) 		//EXT11 Interrupt
	{
		SYSCON->EXICR = EXI_PIN11;
	} 
	else if ((SYSCON->EXIRS&EXI_PIN12)==EXI_PIN12) 		//EXT12 Interrupt
	{
		SYSCON->EXICR = EXI_PIN12;
	} 
	else if ((SYSCON->EXIRS&EXI_PIN13)==EXI_PIN13) 		//EXT13 Interrupt
	{
		SYSCON->EXICR = EXI_PIN13;
	}
	else if ((SYSCON->EXIRS&EXI_PIN14)==EXI_PIN14) 		//EXT14 Interrupt
	{
		SYSCON->EXICR = EXI_PIN14;
	}
	else if ((SYSCON->EXIRS&EXI_PIN15)==EXI_PIN15) 		//EXT15 Interrupt
	{
		SYSCON->EXICR = EXI_PIN15;
	}
}
/*************************************************************/
//CONTA Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CNTAIntHandler(void) 
{
    // ISR content ...
}
/*************************************************************/
//LPT Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void LPTIntHandler(void) 
{
    // ISR content ...
	if((LPT->MISR&LPT_TRGEV0)==LPT_TRGEV0)			//TRGEV0 interrupt
	{
		LPT->ICR = LPT_TRGEV0;
	} 
	else if((LPT->MISR&LPT_MATCH)==LPT_MATCH)		//MATCH interrupt
	{
		LPT->ICR = LPT_MATCH;
	}
	else if((LPT->MISR&LPT_PEND)==LPT_PEND)			//PEND interrupt
	{
		LPT->ICR = LPT_PEND;
	}
}
/*************************************************************/
//BT0 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void BT0IntHandler(void) 
{
    // ISR content ...
	if((BT0->MISR&BT_PEND)==BT_PEND)				//BT0 PEND interrupt
	{
		BT0->ICR = BT_PEND;
	} 
	else if((BT0->MISR&BT_CMP)==BT_CMP)				//BT0 CMP Match interrupt 
	{
		BT0->ICR = BT_CMP;
	}
	else if((BT0->MISR&BT_OVF)==BT_OVF)				//BT0 OVF interrupt
	{
		BT0->ICR = BT_OVF;
	} 
	else if((BT0->MISR&BT_EVTRG)==BT_EVTRG)			//BT0 Event trigger interrupt
	{
		BT0->ICR = BT_EVTRG;
	}
}
/*************************************************************/
//BT1 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void BT1IntHandler(void) 
{
    // ISR content ...
	if((BT1->MISR&BT_PEND)==BT_PEND)				//BT1 PEND interrupt
	{
		BT1->ICR = BT_PEND;
	} 
	else if((BT0->MISR&BT_CMP)==BT_CMP)				//BT1 CMP Match interrupt 
	{
		BT1->ICR = BT_CMP;
	}
	else if((BT0->MISR&BT_OVF)==BT_OVF)				//BT1 OVF interrupt
	{
		BT1->ICR = BT_OVF;
	} 
	else if((BT0->MISR&BT_EVTRG)==BT_EVTRG)			//BT1 Event trigger interrupt
	{
		BT1->ICR = BT_EVTRG;
	} 
}
/*************************************************************/
//LED Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void LEDIntHandler(void) 
{
    // ISR content ...
	if ((LED0->MISR &ICEND)==ICEND) 
    {
        LED0->ICR = ICEND;
    } 
    else if((LED0->MISR &IPEND)==IPEND) 
    {
        LED0->ICR = IPEND;
    } 
}
/*************************************************************/
//LCD Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void LCDIntHandler(void) 
{
	
}
/*************************************************************/
//CMP Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CMPIntHandler(void) 
{
	if((CMP0->MISR & MISR_EDGEDET0)==MISR_EDGEDET0) 
	{
		CMP0->ICR =	EDGEDET;
	}
	else if((CMP0->MISR & MISR_RAWDET0)==MISR_RAWDET0) 
	{
		CMP0->ICR =	RAWDET;
	}
	if((CMP1->MISR & MISR_EDGEDET1)==MISR_EDGEDET1) 
	{
		CMP1->ICR =	EDGEDET;
	}
	else if((CMP1->MISR & MISR_RAWDET1)==MISR_RAWDET1) 
	{
		CMP1->ICR =	RAWDET;
	}
}
/*************************************************************/
//TKEY Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void TKEYIntHandler(void)
{
	csi_tkey_int_process();
}
/*************************************************************/
/*************************************************************/
/*************************************************************/
void PriviledgeVioHandler(void) 
{
    // ISR content ...

}

void SystemDesPtr(void) 
{
    // ISR content ...

}

void MisalignedHandler(void) 
{
    // ISR content ...

}

void IllegalInstrHandler(void) 
{
    // ISR content ...

}

void AccessErrHandler(void) 
{
    // ISR content ...

}

void BreakPointHandler(void) 
{
    // ISR content ...

}

void UnrecExecpHandler(void) 
{
    // ISR content ...

}

void Trap0Handler(void) 
{
    // ISR content ...

}

void Trap1Handler(void) 
{
    // ISR content ...

}

void Trap2Handler(void) 
{
    // ISR content ...

}

void Trap3Handler(void) 
{
    // ISR content ...

}

void PendTrapHandler(void) 
{
    // ISR content ...

}





/*********************************************************************** 
//						 END OF FILE         
***********************************************************************/