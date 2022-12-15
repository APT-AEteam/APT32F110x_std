/*
  ******************************************************************************
  * @file    apt32f110_lcd.c
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2020/12/11
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

/* Includes ------------------------------------------------------------------*/
#include "apt32f110x_lcd.h"
/* define --------------------------------------------------------------------*/

/* externs--------------------------------------------------------------------*/

/*************************************************************/
//LCD RESET VALUE
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/  
void Lcd_Reset_Value(void)
{  
	LCD->CEDR=0X00000000;
	LCD->SRR=0X00000000;
	LCD->CR=0X000000000;
	LCD->CDR=0X00000000;
	LCD->MOD=0X00000000;
	LCD->IER=0X00000000;
	LCD->DMR[0]=0X00000000;
	LCD->DMR[1]=0X00000000;
	LCD->DMR[2]=0X00000000;
	LCD->DMR[3]=0X00000000;
	LCD->DMR[4]=0X00000000;
	LCD->DMR[5]=0X00000000;
	LCD->DMR[6]=0X00000000;
	LCD->DMR[7]=0X00000000;
	LCD->DMR[8]=0X00000000;
	LCD->DMR[9]=0X00000000;
	LCD->DMR[10]=0X00000000;
	LCD->DMR[11]=0X00000000;
	LCD->DMR[12]=0X00000000;
	LCD->DMR[13]=0X00000000;
	LCD->DMR[14]=0X00000000;
	LCD->DMR[15]=0X00000000;
	LCD->DMR[16]=0X00000000;
	LCD->DMR[17]=0X00000000;
	LCD->DMR[18]=0X00000000;
	LCD->DMR[19]=0X00000000;
	LCD->DMR[20]=0X00000000;
	LCD->DMR[21]=0X00000000;
	LCD->DMR[22]=0X00000000;
	LCD->DMR[23]=0X00000000;
	LCD->DMR[24]=0X00000000;
	LCD->DMR[25]=0X00000000;
	LCD->DMR[26]=0X00000000;
	LCD->DMR[27]=0X00000000;
	LCD->DMR[28]=0X00000000;
	LCD->DMR[29]=0X00000000;
	LCD->DMR[30]=0X00000000;
	LCD->DMR[31]=0X00000000;
}

/*************************************************************/
//Lcd io initial
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/  
void Lcd_io_initial(U32_T LCD_Seg_ENABLE , U16_T LCD_Com_ENABLE)
{
	uint8_t i;
	for(i=0;i<32;i++)
	{
		if ((LCD_Seg_ENABLE & (1<<i))!=0)
		{
			switch (i)
			{
				case 0:GPIOA0->CONHR=(GPIOA0->CONHR&0xFFFFFFF0) | 0x00000004;break;		//SEG0  PA0.08
				case 1:GPIOA0->CONHR=(GPIOA0->CONHR&0xFFFFFF0F) | 0x00000040;break;		//SEG1  PA0.09
				case 2:GPIOA0->CONHR=(GPIOA0->CONHR&0xFFFFF0FF) | 0x00000400;break;		//SEG2  PA0.10
				case 3:GPIOA0->CONHR=(GPIOA0->CONHR&0xFFFF0FFF) | 0x00004000;break;		//SEG3  PA0.11
				case 4:GPIOA0->CONHR=(GPIOA0->CONHR&0xFFF0FFFF) | 0x00040000;break;		//SEG4  PA0.12
				case 5:GPIOA0->CONHR=(GPIOA0->CONHR&0xFF0FFFFF) | 0x00400000;break;		//SEG5  PA0.13
				case 6:GPIOA0->CONHR=(GPIOA0->CONHR&0xF0FFFFFF) | 0x04000000;break;		//SEG6  PA0.14
				case 7:GPIOA0->CONHR=(GPIOA0->CONHR&0x0FFFFFFF) | 0x40000000;break;		//SEG7  PA0.15
				case 8:GPIOB0->CONLR=(GPIOB0->CONLR&0xFFFF0FFF) | 0x00004000;break;		//SEG8  PB0.03
				case 9:GPIOC0->CONLR=(GPIOC0->CONLR&0xFFFFFF0F) | 0x00000040;break;		//SEG9  PC0.01
				
				case 10:GPIOB0->CONLR=(GPIOB0->CONLR&0xFFF0FFFF) | 0x00040000;break;	//SEG10 PB0.04
				case 11:GPIOA1->CONLR=(GPIOA1->CONLR&0xFFFFFFF0) | 0x00000004;break;	//SEG11 PA1.00			
				case 12:GPIOA1->CONLR=(GPIOA1->CONLR&0xFFFFFF0F) | 0x00000040;break;	//SEG12 PA1.01			
				case 13:GPIOA1->CONLR=(GPIOA1->CONLR&0xFFFFF0FF) | 0x00000400;break;	//SEG13 PA1.02		
				case 14:GPIOA1->CONLR=(GPIOA1->CONLR&0xFFFF0FFF) | 0x00004000;break;	//SEG14 PA1.03		
				case 15:GPIOA1->CONLR=(GPIOA1->CONLR&0xFFF0FFFF) | 0x00040000;break;	//SEG15 PA1.04		
				case 16:GPIOA1->CONLR=(GPIOA1->CONLR&0xFF0FFFFF) | 0x00400000;break;	//SEG16 PA1.05		
				case 17:GPIOA1->CONLR=(GPIOA1->CONLR&0xF0FFFFFF) | 0x04000000;break;	//SEG17 PA1.06		
				case 18:GPIOB0->CONLR=(GPIOB0->CONLR&0xFF0FFFFF) | 0x00400000;break;	//SEG18 PB0.05		
				//case 19:GPIOA1->CONLR=(GPIOA1->CONLR&0x0FFFFFFF) | 0x40000000;break;	//SEG19 PA1.07		//swd
				
				case 20:GPIOB0->CONLR=(GPIOB0->CONLR&0xF0FFFFFF) | 0x04000000;break;	//SEG20 PB0.06	
				case 21:GPIOB0->CONLR=(GPIOB0->CONLR&0x0FFFFFFF) | 0x40000000;break;	//SEG21 PB0.07	
				//case 22:GPIOA1->CONHR=(GPIOA1->CONHR&0xFFFFFFF0) | 0x00000004;break;	//SEG22 PA1.08		//swc	  
				case 23:GPIOB0->CONHR=(GPIOB0->CONHR&0xFFFFFFF0) | 0x00000004;break;	//SEG23 PB0.08	
				case 24:GPIOB0->CONHR=(GPIOB0->CONHR&0xFFFFFF0F) | 0x00000040;break;	//SEG24 PB0.09	
				case 25:GPIOB0->CONHR=(GPIOB0->CONHR&0xFFFFF0FF) | 0x00000400;break;	//SEG25 PB0.10	
				case 26:GPIOB0->CONHR=(GPIOB0->CONHR&0xFFFF0FFF) | 0x00004000;break;	//SEG26 PB0.11	
				case 27:GPIOA1->CONHR=(GPIOA1->CONHR&0xFFFFFF0F) | 0x00000040;break;	//SEG27 PA1.09	
				case 28:GPIOA1->CONHR=(GPIOA1->CONHR&0xFFFFF0FF) | 0x00000400;break;	//SEG28 PA1.10	
				case 29:GPIOA1->CONHR=(GPIOA1->CONHR&0xFFFF0FFF) | 0x00004000;break;	//SEG29 PA1.11
				
				case 30:GPIOA1->CONHR=(GPIOA1->CONHR&0xFFF0FFFF) | 0x00040000;break;	//SEG30 PA1.12	
				case 31:GPIOA1->CONHR=(GPIOA1->CONHR&0xFF0FFFFF) | 0x00400000;break;	//SEG31 PA1.13	
			}
		}
	}
	for(i=0;i<8;i++)
	{
		if ((LCD_Com_ENABLE & (1<<i))!=0)
		{
			switch (i)
			{
				case 0:GPIOA0->CONLR=(GPIOA0->CONLR&0xF0FFFFFF) | 0x04000000;break;		//COM0 PA0.06
				case 1:GPIOA0->CONLR=(GPIOA0->CONLR&0x0FFFFFFF) | 0x40000000;break;		//COM1 PA0.07
				case 2:GPIOA0->CONHR=(GPIOA0->CONHR&0xFFFFFFF0) | 0x00000004;break;		//COM2 PA0.08
				case 3:GPIOA0->CONHR=(GPIOA0->CONHR&0xFFFFFF0F) | 0x00000040;break;		//COM3 PA0.09	
					
				case 4:GPIOA0->CONHR=(GPIOA0->CONHR&0xFFFFF0FF) | 0x00000400;break;		//COM4 PA0.10	
				case 5:GPIOA0->CONHR=(GPIOA0->CONHR&0xFFFF0FFF) | 0x00004000;break;		//COM5 PA0.11	
				case 6:GPIOA0->CONHR=(GPIOA0->CONHR&0xFFF0FFFF) | 0x00040000;break;		//COM6 PA0.12
				case 7:GPIOA0->CONHR=(GPIOA0->CONHR&0xFF0FFFFF) | 0x00400000;break;		//COM7 PA0.13	
			}
		}
	}
}
/*************************************************************/
//LCD CLK enable
//EntryParameter:NewState
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/  
void Lcd_Clk_Enable(FunctionalStatus NewState , Lcd_Clk_selected_TypeDef Lcd_Clk_x)
{
	if (NewState != DISABLE)
	{
		LCD->CEDR|=lcd_clken;
	}
	else
	{
		LCD->CEDR&=~lcd_clken;
	}
	LCD->CEDR|=Lcd_Clk_x;
}
/*************************************************************/
//LCD scan enable
//EntryParameter:NewState,Lcd_display_x
//NewState:ENABLE,DISABLE
//lcd_display_close,lcd_display_all,lcd_display_buffer
//ReturnValue:NONE
/*************************************************************/  
void Lcd_Scan_Enable(FunctionalStatus NewState)
{
	if (NewState!=ENABLE)
	{
		LCD->CR&=~lcd_en;
	}
	else
	{
		LCD->CR|=lcd_en;
	}
}
/*************************************************************/
//LCD BLINK Config
//EntryParameter:cdiv,cpre
//cdiv:0~7
//cpre:0~0xffff
//ReturnValue:NONE
/*************************************************************/  
//lcdclk=RTCclk/(2^(cdiv+1))/(cpre+1)
//Fframe=lcdclk*duty
void Lcdclk_Config( U8_T cdiv , U16_T cpre)
{
	if((cdiv==0)&&(cpre==0))
	{
		LCD->CDR=(0X00<<7);
	}
	else
	{
		LCD->CDR=(cpre<<8)|(0X01<<7)|cdiv;
	}	
}
/*************************************************************/
//LCD BLINK Config
//EntryParameter:Lcd_Blink_MD_x,Lcd_Blink_Fre_x
//Lcd_Blink_MD_x:Lcd_Blink_MD_dis,Lcd_Blink_MD_Seg8_Com0,
//Lcd_Blink_MD_Seg8_AllCom,Lcd_Blink_MD_AllLight
//Lcd_Blink_Fre_x:Lcd_Blink_Fre_DIV_8,Lcd_Blink_Fre_DIV_16,
//Lcd_Blink_Fre_DIV_32,Lcd_Blink_Fre_DIV_64,Lcd_Blink_Fre_DIV_128,Lcd_Blink_Fre_DIV_256,
//Lcd_Blink_Fre_DIV_512,Lcd_Blink_Fre_DIV_CR2
//Lcd_Blink_F2:0~0xfff
//ReturnValue:NONE
/*************************************************************/  
void Lcd_Blink_Config(Lcd_Blink_MD_TypeDef Lcd_Blink_MD_x , Lcd_Blink_Fre_TypeDef Lcd_Blink_Fre_x , U16_T Lcd_Blink_F2)
{
	LCD->CR = (LCD->CR&0xffff07ff)|Lcd_Blink_MD_x|Lcd_Blink_Fre_x;
	if(Lcd_Blink_Fre_x==Lcd_Blink_Fre_DIV_CR2)
	{
		LCD->CR2|=Lcd_Blink_F2<<16;
	}
}

/*************************************************************/
//LCD Control Config 
//EntryParameter:Vlcd_Selected_x,Lcd_DutyBiase_Selected_x,Lcd_deadclk,Lcd_Contrast_x,Lcd_display_x
//Vlcd_Selected_x:Vlcd_Selected_ExtVDD,Vlcd_Selected_IntVDD_2_6V~Vlcd_Selected_IntVDD_4_0V
//Lcd_DutyBiase_Selected_x:Lcd_DutyBiase_Selected_1_8Duty_1_4_Bias~Lcd_DutyBiase_Selected_1_2Duty_1_2_Bias
//Lcd_Contrast_x:Lcd_Contrast_Selecte_1~Lcd_Contrast_Selecte_9
//lcd_display_close,lcd_display_all,lcd_display_buffer
//Lcd_deadclk:0~7
//ReturnValue:NONE
/*************************************************************/ 
//选择内部为升压时，VLCD接104电容
//1/2 Bias  VLC2接电容 （10*VLCD电容大小）
//1/3 Bias  VLC2,VLC3接电容 （10*VLCD电容大小）
//1/4 Bias  VLC1,VLC2,VLC3接电容（10*VLCD电容大小）
void Lcd_Display_Config(Vlcd_Selected_TypeDef Vlcd_Selected_x , Lcd_DutyBiase_Selected_TypeDef Lcd_DutyBiase_Selected_x , 
				Lcd_Contrast_TypeDef Lcd_Contrast_x  , Lcd_display_mode_TypeDef Lcd_display_x , Lcd_BP_CMD_TypeDef Lcd_BP_CMD , U8_T Lcd_deadclk  )
{
	LCD->CR=(LCD->CR)&0x0000f888;
	if(Lcd_BP_CMD==Lcd_BP_EN)
	{
		if((Lcd_DutyBiase_Selected_x==Lcd_DutyBiase_Selected_1_2Duty_1_2_Bias)||(Lcd_DutyBiase_Selected_x==Lcd_DutyBiase_Selected_1_3Duty_1_2_Bias))		//1/2duty
		{
			GPIOA1->CONHR=(GPIOA1->CONHR&0XFFF0FFFF) | 0x00040000;	//SEG30/VLC2		
		}
		else if((Lcd_DutyBiase_Selected_x==Lcd_DutyBiase_Selected_1_4Duty_1_3_Bias)
			||(Lcd_DutyBiase_Selected_x==Lcd_DutyBiase_Selected_1_3Duty_1_3_Bias)
			||(Lcd_DutyBiase_Selected_x==Lcd_DutyBiase_Selected_1_5Duty_1_3_Bias))//1/3 duty
		{
			GPIOA1->CONHR=(GPIOA1->CONHR&0XFFF0FFFF) | 0x00040000;	//SEG30/VLC2
			GPIOA1->CONHR=(GPIOA1->CONHR&0XFFFF0FFF) | 0x00004000;	//SEG29/VLC3			
		}
		else if((Lcd_DutyBiase_Selected_x==Lcd_DutyBiase_Selected_1_6Duty_1_4_Bias)
			||(Lcd_DutyBiase_Selected_x==Lcd_DutyBiase_Selected_1_8Duty_1_4_Bias))
		{
			GPIOA1->CONHR=(GPIOA1->CONHR&0XFF0FFFFF) | 0x00400000;	//SEG31/VLC1		
			GPIOA1->CONHR=(GPIOA1->CONHR&0XFFF0FFFF) | 0x00040000;	//SEG30/VLC2
			GPIOA1->CONHR=(GPIOA1->CONHR&0XFFFF0FFF) | 0x00004000;	//SEG29/VLC3
		}
		LCD->CR|=0x1<<6;///0x1<<6  使能
	}
	else
	{
		LCD->CR|=0x0<<6;///去耦电容禁止
	}
	//LCD->CR|=0x1<<7;
	if(Vlcd_Selected_x==Vlcd_Selected_ExtVDD)
	{
		LCD->CR|=(0x01<<3)|(0x00<<4)|(0x01<<5);
	}
	else
	{
		LCD->CR=(LCD->CR)&0xFFFFFFF7;					//使能内部VLCD
		if(Vlcd_Selected_x==Vlcd_Selected_IntVDD_2_6V)
		{
			LCD->MOD=0;
			LCD->CR|=(0x00<<3)|(0x01<<4);
			while(!(LCD->CR&0x40000000));				//升压完成
			LCD->CR|=(0x00<<3)|(0x01<<5);
			while(!(LCD->CR&0x80000000));				//偏置电压完成
		}
		else if(Vlcd_Selected_x==Vlcd_Selected_IntVDD_2_8V)
		{
			LCD->MOD=1;
			LCD->CR|=(0x00<<3)|(0x01<<4);
			while(!(LCD->CR&0x40000000));				//升压完成
			LCD->CR|=(0x00<<3)|(0x01<<5);
			while(!(LCD->CR&0x80000000));				//偏置电压完成
		}
		else if(Vlcd_Selected_x==Vlcd_Selected_IntVDD_3_0V)
		{
			LCD->MOD=2;
			LCD->CR|=(0x00<<3)|(0x01<<4);
			while(!(LCD->CR&0x40000000));				//升压完成
			LCD->CR|=(0x00<<3)|(0x01<<5);
			while(!(LCD->CR&0x80000000));				//偏置电压完成
		}
		else if(Vlcd_Selected_x==Vlcd_Selected_IntVDD_3_2V)
		{
			LCD->MOD=3;
			LCD->CR|=(0x00<<3)|(0x01<<4);
			while(!(LCD->CR&0x40000000));				//升压完成
			LCD->CR|=(0x00<<3)|(0x01<<5);
			while(!(LCD->CR&0x80000000));				//偏置电压完成
		}
		else if(Vlcd_Selected_x==Vlcd_Selected_IntVDD_3_4V)
		{
			LCD->MOD=4;
			LCD->CR|=(0x00<<3)|(0x01<<4);
			while(!(LCD->CR&0x40000000));				//升压完成
			LCD->CR|=(0x00<<3)|(0x01<<5);
			while(!(LCD->CR&0x80000000));				//偏置电压完成
		}
		else if(Vlcd_Selected_x==Vlcd_Selected_IntVDD_3_6V)
		{
			LCD->MOD=5;
			LCD->CR|=(0x00<<3)|(0x01<<4);
			while(!(LCD->CR&0x40000000));				//升压完成
			LCD->CR|=(0x00<<3)|(0x01<<5);
			while(!(LCD->CR&0x80000000));				//偏置电压完成
		}
		else if(Vlcd_Selected_x==Vlcd_Selected_IntVDD_3_8V)
		{
			LCD->MOD=6;
			LCD->CR|=(0x00<<3)|(0x01<<4);
			while(!(LCD->CR&0x40000000));				//升压完成
			LCD->CR|=(0x00<<3)|(0x01<<5);
			while(!(LCD->CR&0x80000000));				//偏置电压完成
		}
		else if(Vlcd_Selected_x==Vlcd_Selected_IntVDD_4_0V)
		{
			LCD->MOD=7;
			LCD->CR|=(0x00<<3)|(0x01<<4);
			while(!(LCD->CR&0x40000000));				//升压完成
			LCD->CR|=(0x00<<3)|(0x01<<5);
			while(!(LCD->CR&0x80000000));				//偏置电压完成
		}
	}
	if(Lcd_Contrast_x==Lcd_Contrast_Selecte_1)
	{
		LCD->CR|=(0x00<<16)|(0x00<<17)|(0x00<<28);
	}	
	else if(Lcd_Contrast_x==Lcd_Contrast_Selecte_2)
	{
		LCD->CR|=(0x01<<16)|(0x01<<17)|(0x00<<28);
	}
	else if(Lcd_Contrast_x==Lcd_Contrast_Selecte_3)
	{
		LCD->CR|=(0x01<<16)|(0x02<<17)|(0x00<<28);
	}
	else if(Lcd_Contrast_x==Lcd_Contrast_Selecte_4)
	{
		LCD->CR|=(0x01<<16)|(0x03<<17)|(0x00<<28);
	}
	else if(Lcd_Contrast_x==Lcd_Contrast_Selecte_5)
	{
		LCD->CR|=(0x01<<16)|(0x04<<17)|(0x00<<28);
	}
	else if(Lcd_Contrast_x==Lcd_Contrast_Selecte_6)
	{
		LCD->CR|=(0x01<<16)|(0x05<<17)|(0x00<<28);
	}
	else if(Lcd_Contrast_x==Lcd_Contrast_Selecte_7)
	{
		LCD->CR|=(0x01<<16)|(0x06<<17)|(0x00<<28);
	}
	else if(Lcd_Contrast_x==Lcd_Contrast_Selecte_8)
	{
		LCD->CR|=(0x01<<16)|(0x07<<17)|(0x00<<28);
		//LCD->CR|=(0x01<<16)|(0x07<<17)|(0x01<<28);
	}
	else if(Lcd_Contrast_x==Lcd_Contrast_Selecte_9)
	{
		LCD->CR|=(0x01<<16)|(0x07<<17)|(0x01<<28);
	}	
	LCD->CR|=Lcd_display_x|Lcd_DutyBiase_Selected_x|(Lcd_deadclk<<20);
}
/*************************************************************/
//lcd write data
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/   
void Lcd_Write_Data(U8_T *Lcd_data_buf )
{
	unsigned char i;
	for(i=0;i<32;i++)
	{
		LCD->DMR[i]=*(Lcd_data_buf+i);
	}
	LCD->SR=0X01<<2;
	while(!(LCD->SR&0x08));
	
}

void lcd_display_mode(Lcd_Dis_mode_TypeDef Lcd_Dis_mode)
{
	LCD->CR=(LCD->CR&0xffffffffff9)|Lcd_Dis_mode;
}
/*************************************************************/
//lcd software reset
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/    
void lcd_Software_Reset(void)
{
	LCD->SRR=lcd_swrst;
}
 /*************************************************************/
//lcd INT Config
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void Lcd_Int_Config(Lcd_INT_TypeDef Lcd_X_INT)
{
	LCD->IER  |= Lcd_X_INT;
}
/*************************************************************/
//LCD Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void Lcd_Vector_Enable(void)
{
	INTC_ISER_WRITE(LCD_INT);    
}
/*************************************************************/
//LCD Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void Lcd_Vector_Disable(void)
{
    INTC_ICER_WRITE(LCD_INT);    
}
/*************************************************************/
//LCD Interrupt wakeup enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void Lcd_Wakeup_Enable(void)
{
    INTC_IWER_WRITE(LCD_INT);    
}

/*************************************************************/
//LCD Interrupt wakeup enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void Lcd_Wakeup_Disable(void)
{
    INTC_IWDR_WRITE(LCD_INT);    
}
/******************* (C) COPYRIGHT 2020 APT Chip *****END OF FILE****/