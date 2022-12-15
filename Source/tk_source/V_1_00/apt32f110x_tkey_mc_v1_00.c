/*
  ******************************************************************************
  * @file    apt32f110_tkey_mc_v01.c
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
#include "apt32f110x_tkey.h"
#include "apt32f110x_gpio.h"
#include "string.h"

/****************************************************
//extern function
*****************************************************/
extern void tk_parameter_init(void);

/****************************************************
//variables 
*****************************************************/
U32_T TK_Scan_Freq0=0xd0007;		//666.7K

/****************************************************
//TK 8bits variable define
*****************************************************/
volatile U8_T tk_num;
volatile U8_T tk_seque[32];
volatile U8_T tk_track_cnt;
volatile U8_T tk_negtive_build0[32];
volatile U8_T tk_postive_build0[32];
volatile U8_T press_debounce0[32];
volatile U8_T release_debounce0[32];
volatile U8_T triger_cnt;
/****************************************************
//TK 16bits variable define
*****************************************************/
volatile S16_T offset_data0[32];
volatile U16_T sampling_data0[32];
volatile U16_T baseline_data0[32];
volatile U16_T offset_data0_abs[32];
volatile U16_T offset0_max_tempA;
volatile U16_T offset0_max_tempB;
volatile U16_T offset_max_data[32];
/****************************************************
//TK 32bits variable define
*****************************************************/
volatile U32_T Key_Map;
volatile U32_T key_map0;
volatile U32_T key_map_temp0;
volatile U32_T key_map_temp1;
volatile U32_T tkey_scan_cnt;
/****************************************************
//TK 8bits flag define
*****************************************************/
volatile U8_T base_update_f;
volatile U8_T valid_key_f;
volatile U8_T poweron_1st_f;
volatile U8_T trigger_auto_f;
/*************************************************************/
//TKEY Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void TKEYIntHandler(void)
{
	if((TKEY->TCH_RISR&TK_SEQ_DNE)==TK_SEQ_DNE)
	{
		TKEY->TCH_ICR = TK_SEQ_DNE;
	}
	if((TKEY->TCH_RISR&TK_CH_DNE)==TK_CH_DNE)
	{
		TKEY->TCH_ICR = TK_CH_DNE;
	}
	if((TKEY->TCH_RISR&TK_CH_ERR)==TK_CH_ERR)
	{
		TKEY->TCH_ICR = TK_CH_ERR;
	}
	if((TKEY->TCH_RISR&TK_TIMOVF)==TK_TIMOVF)
	{
		TKEY->TCH_ICR = TK_TIMOVF;
	}
	if((TKEY->TCH_RISR&TK_REFOVF)==TK_REFOVF)
	{
		TKEY->TCH_ICR = TK_REFOVF;
	}
	if((TKEY->TCH_RISR&TK_THROVR)==TK_THROVR)
	{
		TKEY->TCH_ICR = TK_THROVR;
	}
}
/****************************************************
//TK INT configure
*****************************************************/
void TK_ConfigInterrupt_CMD(FunctionalStatus NewState,U32_T TK_IMSCR_X)
{
	if (NewState != DISABLE)
	{
		TKEY->TCH_IMCR  |= TK_IMSCR_X;						
	}
	else
	{
		TKEY->TCH_IMCR  &= ~TK_IMSCR_X;					
	}
}
/****************************************************
//TK IO Intial
*****************************************************/
void tkey_io_enable(void)
{
	U8_T i;
	GPIOA0->CONLR=(GPIOA0->CONLR&0XFF0FFFFF) | 0x00A00000;//PA0.5 TS_CAP
	for (i=0;i<32;i++)
	{
		if ((TK_IO_ENABLE & (1<<i))!=0)
		{
			switch (i)
			{
				case 0  : 	GPIOA0->CONHR=(GPIOA0->CONHR&0XF0FFFFFF) | 0x0A000000;break; 	//PA0.14	TCH0
				case 1  : 	GPIOA0->CONHR=(GPIOA0->CONHR&0X0FFFFFFF) | 0xA0000000;break; 	//PA0.15	TCH1
				case 2  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFFFFFFF0) | 0x0000000A;break; 	//PA1.0		TCH2
				case 3  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFFFFFF0F) | 0x000000A0;break; 	//PA1.1		TCH3
				case 4  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFFFFF0FF) | 0x00000A00;break; 	//PA1.2		TCH4
				case 5  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFFFF0FFF) | 0x0000A000;break; 	//PA1.3		TCH5
				case 6  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFFF0FFFF) | 0x000A0000;break; 	//PA1.4		TCH6
				case 7  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFF0FFFFF) | 0x00A00000;break; 	//PA1.5		TCH7
				case 8  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XF0FFFFFF) | 0x0A000000;break; 	//PA1.6		TCH8
				case 9  : 	GPIOB0->CONLR=(GPIOB0->CONLR&0XFF0FFFFF) | 0x00A00000;break; 	//PB0.5		TCH9
				case 10 : 	*(uint32_t *)(0x40011128) = 0x5a;
							GPIOA1->CONLR=(GPIOA1->CONLR&0X0FFFFFFF) | 0xA0000000;			//PA1.7		TCH10
							GPIOA1->PUDR &= 0XFFFF3FFF;
					break; 
				case 11 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XF0FFFFFF) | 0x0A000000;break; 	//PB0.6		TCH11
				case 12 :	GPIOB0->CONLR=(GPIOB0->CONLR&0X0FFFFFFF) | 0xA0000000;break; 	//PB0.7		TCH12
				case 13 :	*(uint32_t *)(0x40011128) = 0x5a;
							GPIOA1->CONHR=(GPIOA1->CONHR&0XFFFFFFF0) | 0x0000000A;			//PA1.8		TCH13
							GPIOA1->PUDR &= 0XFFFCFFFF;
					break; 
				case 14 :	GPIOB0->CONHR=(GPIOB0->CONHR&0XFFFFFFF0) | 0x0000000A;break; 	//PB0.8		TCH14
				case 15 :	GPIOB0->CONHR=(GPIOB0->CONHR&0XFFFFFF0F) | 0x000000A0;break; 	//PB0.9		TCH15
				case 16 :	GPIOB0->CONHR=(GPIOB0->CONHR&0XFFFFF0FF) | 0x00000A00;break; 	//PB0.10	TCH16
				case 17 :	GPIOB0->CONHR=(GPIOB0->CONHR&0XFFFF0FFF) | 0x0000A000;break; 	//PB0.11	TCH17
				case 18 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFFFFFF0F) | 0x000000A0;break; 	//PA1.9		TCH18
				case 19 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFFFFF0FF) | 0x00000A00;break; 	//PA1.10	TCH19
				case 20 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFFFF0FFF) | 0x0000A000;break; 	//PA1.11	TCH20
				case 21 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFFF0FFFF) | 0x000A0000;break; 	//PA1.12	TCH21
				case 22 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFF0FFFFF) | 0x00A00000;break; 	//PA1.13	TCH22
				case 23 :	GPIOC0->CONLR=(GPIOC0->CONLR&0XFFFFFFF0) | 0x0000000A;break; 	//PC0.0		TCH23
				case 24 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFFFFFF0) | 0x0000000A;break; 	//PA0.0		TCH24
				case 25 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFFFFF0F) | 0x000000A0;break; 	//PA0.1		TCH25
				case 26 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFFFF0FF) | 0x00000A00;break; 	//PA0.2		TCH26
				case 27 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFFF0FFF) | 0x0000A000;break; 	//PA0.3		TCH27
				case 28 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFF0FFFF) | 0x000A0000;break; 	//PA0.4		TCH28
				case 29 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFFFFF0) | 0x0000000A;break; 	//PB0.0		TCH29
				case 30 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFFFF0F) | 0x000000A0;break; 	//PB0.1		TCH30
				case 31 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFFF0FF) | 0x00000A00;break; 	//PB0.2		TCH31
				default : break;
			}
		}
	}
}
/****************************************************
//TK power source configure
*****************************************************/
void tkey_pwrsrc_config(void)
{
	if(TK_PSEL_MODE==TK_PWRSRC_FVR)
	{
		GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFFF0)  | 0x0000000A;	
		ADC0->ECR=2;
		if(TK_FVR_LEVEL==TK_FVR_4096V)
		{					
			ADC0->CR=(ADC0->CR&0xfcffffff)|(0X01<<24)|(0X01<<25);
		}
		if(TK_FVR_LEVEL==TK_FVR_2048V)
		{
			ADC0->CR=(ADC0->CR&0xfcffffff)|(0X01<<24)|(0X00<<25);
		}
	}
}
/****************************************************
//TK get key seq
*****************************************************/
U8_T get_key_seq(void)
{                  
    int count = 0;
    int i = 0,j=0;
    for (; i<32; i++)
    {
        if (((TK_IO_ENABLE >> i) & 1) == 1)
		{
            count++;
			tk_seque[j]=i;
			j++;
		}
    }
    return count;
}
/****************************************************
//TK get key pressed
*****************************************************/
U8_T get_key_pressed(void)
{                  
    int count = 0;
    int i = 0;
    for (; i<32; i++)
    {
        if (((key_map0 >> i) & 1) == 1)
		{
            count++;
		}
    }
    return count;
}
/****************************************************
//TK baseline program
*****************************************************/
void TK_Baseline_prog(void)
{
	U8_T i,k;
	for(k=0;k<10;k++)
	{
		TKEY->TCH_RSSR = 0X1;
		while(!((TKEY->TCH_TKST&TK_BUSY)!=TK_BUSY));
		TKEY->TCH_RSSR = 0;
		for (i=0;i<tk_num;i++)
		{
			baseline_data0[(TKEY->TCH_DAT[i]&0xff000000)>>24]=TKEY->TCH_DAT[i]&0X00FFFFFF;
			sampling_data0[(TKEY->TCH_DAT[i]&0xff000000)>>24]=TKEY->TCH_DAT[i]&0X00FFFFFF;
		}
	}
}
/****************************************************
//TK Sampling 
*****************************************************/
void TK_Sampling_prog(void)
{
	U8_T i=0;
	TKEY->TCH_RSSR = 0X1;
	tkey_scan_cnt=0;
	//while(!((TKEY->TCH_TKST&TK_BUSY)!=TK_BUSY));
	for(;((TKEY->TCH_TKST&TK_BUSY)==TK_BUSY);)
	{
		tkey_scan_cnt++;
		if(tkey_scan_cnt>(TK_BaseCnt*TK_Global_Sens))
		{
			tkey_scan_cnt=0;
			tkey_init();
		}
	}
	TKEY->TCH_RSSR = 0x0;
	for (i=0;i<tk_num;i++)
	{
		sampling_data0[(TKEY->TCH_DAT[i]&0xff000000)>>24]=TKEY->TCH_DAT[i]&0X00FFFFFF;
	}
	if(poweron_1st_f<5)
	{
	for (i=0;i<32;i++)
	{
		baseline_data0[i]=sampling_data0[i];
	}
	poweron_1st_f++;
	}
	if(base_update_f==1)
	{
		TKEY->TCH_RSSR = 0X1;
		while(!((TKEY->TCH_TKST&TK_BUSY)!=TK_BUSY));
		TKEY->TCH_RSSR = 0;
		for (i=0;i<tk_num;i++)
		{
			baseline_data0[(TKEY->TCH_DAT[i]&0xff000000)>>24]=TKEY->TCH_DAT[i]&0X00FFFFFF;
			sampling_data0[(TKEY->TCH_DAT[i]&0xff000000)>>24]=TKEY->TCH_DAT[i]&0X00FFFFFF;
		}
		base_update_f=0;
	}
}
/****************************************************
//TK Sens Finetuning
*****************************************************/
void TK_Sens_Finetuning(void)
{
	U8_T i,j=0;
	U32_T max_temp;
	max_temp=sampling_data0[0];
	if(poweron_1st_f==5)
	{
		poweron_1st_f++;
		for (i=0;i<32;i++)
		{
			if(sampling_data0[i]>max_temp)
			{
				max_temp=sampling_data0[i];
				j=i;
			}
		}
		for (i=0;i<32;i++)
		{
			TK_senprd[i]=TK_senprd[i]+((sampling_data0[j]-sampling_data0[i])/12);
		}
		for(i=0;i<tk_num;i++)
		{
			TKEY->TCH_SEQxCON[i]|=(TK_senprd[tk_seque[i]]<<0);
		}
		TK_Baseline_prog();
	}
}
/****************************************************
//TK baseline tracking
*****************************************************/
void TK_Baseline_tracking(void)
{
	U8_T i;
	tk_track_cnt++;
	if (tk_track_cnt>=Base_Speed)
	{
		tk_track_cnt=0;
		//======================================
		if(key_map0==0)
		{
			for(i=0;i<32;i++)
			{
				if((offset_data0[i]<0)&&((baseline_data0[i]-sampling_data0[i])>=(TK_Triggerlevel[i]))&&((baseline_data0[i]-sampling_data0[i])<(TK_Triggerlevel[i]*3)))
				{
					tk_negtive_build0[i]++;
					if(tk_negtive_build0[i]>3)
					{
					base_update_f=1;
					tk_negtive_build0[i]=0;
					}
				}
				if((offset_data0[i]>0)&&(sampling_data0[i]-baseline_data0[i])>=(TK_Triggerlevel[i]*4))
				{
					tk_postive_build0[i]++;
					if(tk_postive_build0[i]>3)
					{
					base_update_f=1;
					tk_postive_build0[i]=0;
					}
				}
				else if((offset_data0[i]<0)&&((baseline_data0[i]-sampling_data0[i])>=(TK_Triggerlevel[i]*3)))
				{
					base_update_f=1;
				}
				if((offset_data0[i]<0)&&((baseline_data0[i]-sampling_data0[i])<TK_Triggerlevel[i]))
				{
					baseline_data0[i]-=2;
				}
				if((offset_data0[i]<0)&&((baseline_data0[i]-sampling_data0[i])>=(TK_Triggerlevel[i]/2)))
				{
					baseline_data0[i]-=4;
				}
				if ((offset_data0[i]>0)&&(offset_data0[i]<(TK_Triggerlevel[i]/2)))
				{
					baseline_data0[i]+=1;
				}
				if ((offset_data0[i]>0)&&(offset_data0[i]<TK_Triggerlevel[i])&&(offset_data0[i]>=(TK_Triggerlevel[i]/2)))
				{
					baseline_data0[i]+=2;
				}
			}
		}

	}
}
/****************************************************
//TK get key map
*****************************************************/
void TK_Keymap_prog(void)
{
	U8_T i;
	for(i=0;i<32;i++)
	{
		offset_data0[i]=sampling_data0[i]-baseline_data0[i];
		if(offset_data0[i]<0)
		{
			offset_data0_abs[i]=0;
		}
		else
		{
			offset_data0_abs[i]=offset_data0[i];
		}
	}
	for(i=0;i<32;i++)
	{
		//=================key_map0============================
		if(MultiTimes_Filter>=4)
		{
			if((offset_data0[i]>TK_Triggerlevel[i])&&(offset_data0[i]<(TK_Triggerlevel[i]*MultiTimes_Filter))&&(valid_key_f==0))
		  {
			press_debounce0[i]++;
			release_debounce0[i]=0;
			tk_postive_build0[i]=0;
			tk_negtive_build0[i]=0;
			if(press_debounce0[i]>Press_debounce)
			{
				if((Key_mode==0)&&(key_map0==0))
				{
				key_map0|=0x01<<i;
				}
				if(Key_mode==1)
				{
				key_map0|=0x01<<i;
				}
				if(Key_mode==2)
				{
				if(offset_data0[i]>(offset0_max_tempA+10))
				{
				offset0_max_tempA=offset_data0[i];
				key_map0=0;
				key_map0|=0x01<<i;
				}
				}
				if(Key_mode==3)
				{
				if(offset_data0[i]>(offset0_max_tempA+10))
				{
				offset0_max_tempA=offset_data0[i];
				key_map0=0;
				key_map0|=0x01<<i;
				}
				if((offset_data0[i]<(offset0_max_tempA-5))&&(offset_data0[i]>(offset0_max_tempB+5)))
				{
				offset0_max_tempB=offset_data0[i];
				key_map0|=0x01<<i;
				}
				}
				press_debounce0[i]=0;
			}
		 }
		 else if((offset_data0[i])>(TK_Triggerlevel[i]*MultiTimes_Filter))
			 {
				 key_map0&=~(0x01<<i);
			 }
		}
		else
		{
		if((offset_data0[i]>TK_Triggerlevel[i])&&(valid_key_f==0))
		{
			press_debounce0[i]++;
			release_debounce0[i]=0;
			tk_postive_build0[i]=0;
			tk_negtive_build0[i]=0;
			if(press_debounce0[i]>Press_debounce)
			{
				if((Key_mode==0)&&(key_map0==0))			//first single key
				{
				key_map0|=0x01<<i;
				}
				if(Key_mode==1)								//multi key
				{
				key_map0|=0x01<<i;
				}
				if(Key_mode==2)								//strongest single key
				{
				if(offset_data0[i]>(offset0_max_tempA+10))
				{
				offset0_max_tempA=offset_data0[i];
				key_map0=0;
				key_map0|=0x01<<i;
				}
				}
				if(Key_mode==3)								//stronger multi key
				{
				
				if(offset_data0[i]>(offset0_max_tempA+10))
				{
				offset0_max_tempA=offset_data0[i];
				key_map0=0;
				key_map0|=0x01<<i;
				}
				if((offset_data0[i]<(offset0_max_tempA-5))&&(offset_data0[i]>(offset0_max_tempB+5)))
				offset0_max_tempB=offset_data0[i];
				key_map0|=0x01<<i;
				}
				press_debounce0[i]=0;
			}
		}
		}
		if(offset_data0[i]<(TK_Triggerlevel[i]*4/5))
		{
			release_debounce0[i]++;
			press_debounce0[i]=0;
			if(release_debounce0[i]>Release_debounce)
			{
				key_map0&=~(0x01<<i);
				release_debounce0[i]=0;
			}
		}
	}
	if(key_map0!=0)
	{
		if(get_key_pressed()>=Valid_Key_Num)
		{
			valid_key_f=1;
		}
	}
}
/****************************************************
//TK result program
*****************************************************/
void TK_result_prog(void)
{
	if(key_map0!=0)
	{
		Key_Map=key_map0;							
	}
		else 
		{
			Key_Map=0;
			offset0_max_tempA=0;
			offset0_max_tempB=0;
		}

	if(Key_Map!=0)
	{
		if(Key_Map!=key_map_temp0)
		{
			key_map_temp0=Key_Map;
			valid_key_f=0;
		}
	}
	else
	{
		key_map_temp0=0;
		valid_key_f=0;
	}
}

/****************************************************
//TK Trigger Auto once
*****************************************************/
void TK_Trigger_Auto_Adjust(void)
{
	U8_T i;
	if((Key_Map!=0)&&(trigger_auto_f==0))
	{
		if(key_map_temp1==Key_Map)
		{
			return;
		}
		else
		{
			key_map_temp1=Key_Map;
			trigger_auto_f=1;
		}
		for(i=0;i<32;i++)
		{
		if(offset_data0_abs[i]>offset_max_data[i])
		{
			offset_max_data[i]=offset_data0_abs[i];
		}
		}
	}
	if((trigger_auto_f==1)&&(Key_Map==0))
	{
		for(i=0;i<32;i++)
		{
			if(offset_max_data[i]>(TK_Triggerlevel[i]*3/2))
			{
				trigger_auto_f=2;
			}
		}
		for(i=0;i<32;i++)
		{
			if(offset_max_data[i]>(TK_Triggerlevel[i]*4))
			{
				trigger_auto_f=3;
			}
		}
	}
	if(trigger_auto_f==3)		
	{
		trigger_auto_f=4;
		for(i=0;i<32;i++)
		{
			TK_Triggerlevel[i]=TK_Triggerlevel[i]*3;
		}
	}
	if(trigger_auto_f==2)		
	{
		trigger_auto_f=0;
		for(i=0;i<32;i++)
		{
			if ((key_map_temp1 & (1<<i))!=0)
			{
				TK_Triggerlevel[i]=offset_max_data[i]/2;
				triger_cnt++;
				if(triger_cnt==tk_num)
				{
					triger_cnt=0;
					trigger_auto_f=4;
					key_map_temp1=0;
				}
			}
		}
	}
}
/****************************************************
//TK parameter config
*****************************************************/
void tkey_para_config(void)
{
	U8_T i;
	tk_parameter_init();
	if(TK_Global_Sens!=0)
	{
		for(i=0;i<32;i++)
		{
			TK_senprd[i]=500+((TK_Global_Sens-1)*250);
		}
	}
	else
	{
		for(i=0;i<32;i++)
		{
			TK_senprd[i]=200;
		}
	}
	if((TK_Global_Trigger!=0)&&(TK_Global_Trigger>20))
	{
		for(i=0;i<32;i++)
		{
			TK_Triggerlevel[i]=TK_Global_Trigger;
		}
	}
	else
	{
		for(i=0;i<32;i++)
		{
			TK_Triggerlevel[i]=50;
		}
	}
	if(TK_Global_Icon!=0)
	{
		for(i=0;i<32;i++)
		{
			TK_icon[i]=TK_Global_Icon;
		}
	}
	else
	{
		for(i=0;i<32;i++)
		{
			TK_icon[i]=4;
		}
	}
	if(TK_Fine_Turn==ENABLE)
	{
	for(i=0;i<32;i++)
	{
	if(TK_CHx_Sens[i]!=0)
		{
			TK_senprd[i]=500+((TK_CHx_Sens[i]-1)*250);
		}
	if((TK_CHx_Trigger[i]!=0)&&(TK_CHx_Trigger[i]>20))
		{
			TK_Triggerlevel[i]=TK_CHx_Trigger[i];
		}
	if(TK_CHx_Icon[i]!=0)
		{
			TK_icon[i]=TK_CHx_Icon[i];
		}
	}
	}
}
/****************************************************
//TK init
*****************************************************/
void tkey_init(void)
{
	U8_T i;
	*(uint32_t *)0x400111FC = 0x69966996;			//使能频率调整
	if(TK_scan_freq!=0)
	{
		TK_Scan_Freq0=TK_scan_freq;	
	}
	*(uint32_t *)0x40011240 = TK_Scan_Freq0;
	tkey_para_config();
	tkey_io_enable();
	tkey_pwrsrc_config();
	TKEY->TCH_CCR = TK_CLK_EN | TK_DCHCKSEL_REFCLK | TK_PCKDIV(5) | TK_ALDTRIM_EN |  TK_TRMTARSEL_TRIM | TK_DCHCKDIV_6 | TK_TRIMCONFIG0(10) | TK_TRIMCONFIG1(13) | TK_TRIMCONFIG2(15);
	memset((void *)TKEY->TCH_SEQxCON,0,sizeof(TKEY->TCH_SEQxCON));
	memset((void *)TKEY->TCH_DAT,0,sizeof(TKEY->TCH_DAT));
	tk_num=get_key_seq();
	TKEY->TCH_CON0 = TK_HM_EN | TK_MODE_SINGLE | TK_SEQLEN(tk_num) | TK_EC_LEVEL | TK_SCTIMLMT_5ms | TK_SCTLIM_EN | TK_INTVTIM_None | TK_PWRSRC_AVDD | TK_INTREN_DIS | TK_STPATDSL_DIS | TK_STBLCNT_16 |TK_CYCSCNT_EN;
	TKEY->TCH_CON1 = TK_DST_LOW | TK_DBGSDO_DIS | TK_DBGDLEN_24bit | TK_DBGDOCKDIV_16 | TK_PHS_SHFT_SEQ_0 | TK_SHFT_STEP(2);
	for(i=0;i<tk_num;i++)
	{
	TKEY->TCH_SEQxCON[i]=(0x1<<27)|(((TK_icon[tk_seque[i]]>>4)&3)<<25)|((TK_icon[tk_seque[i]]&0xf)<<21)|(tk_seque[i]<<16)|(TK_senprd[tk_seque[i]]<<0);
	}
	TK_Baseline_prog();
}
/****************************************************
//TK main
*****************************************************/
void tkey_main_prog(void)
{
	TK_Sampling_prog();
	//TK_Sens_Finetuning();
	TK_Keymap_prog();
	TK_Baseline_tracking();
	//TK_overflow_predict();
	TK_result_prog();
	TK_Trigger_Auto_Adjust();
}	
/***************************************************/
//TKEY int process (not uesd)
/***************************************************/
void std_tkey_process(void)
{
	
}
//**************************************************
//Tkey end
//**************************************************
