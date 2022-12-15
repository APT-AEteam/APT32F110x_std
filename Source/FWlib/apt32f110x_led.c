/*
  ******************************************************************************
  * @file    apt32f110_led
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2022/01/16
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
#include "apt32f110x_led.h"
#include "apt32f110x_gpio.h"

/****************************************************
//define
*****************************************************/ 
unsigned char LED_CHAR_[11] = {
			0x3F,//0
			0x06,//1
			0x5B,//2
			0x4F,//3
			0x66,//4
			0x6D,//5
			0x7D,//6
			0x07,//7
			0x7F,//8
			0x6F,//9
			0XFF
	};

 /*************************************************************/
//LED RESET VALUE
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/  
void LED_RESET_VALUE(void)
{
	 LED0->CR			=	LED0_CR_RST;     					// CR  reset value  	*/
	 LED0->BRIGHT		=	LED0_BRIGHT_RST;                  	// BRIGHT reset value */
	 LED0->RISR			= 	LED0_RISR_RST;       		  		// RISR reset value  	*/
	 LED0->IMCR			=	LED0_IMCR_RST;             			// IMCR reset value  	*/
	 LED0->MISR			=   LED0_MISR_RST;                  	// MISR reset value  	*/
	 LED0->ICR 			=	LED0_ICR_RST;                   	// ICR reset value  	*/
	 LED0->TIMCR		=	LED0_TIMCR_RST;						// TIMCR reset value  */	
	 LED0->BLKER		=	LED0_BLKER_RST;						// BLKER reset value  */	
	 LED0->BLKDR		=	LED0_BLKDR_RST;						// BLKDR reset value  */	
	 LED0->BLKST		=	LED0_BLKST_RST;						// BLKST reset value  */	
	 LED0->SEGDATA[0] 	=	LED0_SEGDAT0_RST;                	// SEGDAT0  reset value */
	 LED0->SEGDATA[1] 	=	LED0_SEGDAT1_RST;              		// SEGDAT1  reset value */
	 LED0->SEGDATA[2]  	=	LED0_SEGDAT2_RST;               	// SEGDAT2  reset value */
	 LED0->SEGDATA[3] 	=	LED0_SEGDAT3_RST;             		// SEGDAT3  reset value */
	 LED0->SEGDATA[4] 	=	LED0_SEGDAT0_RST;                	// SEGDAT0  reset value */
	 LED0->SEGDATA[5] 	=	LED0_SEGDAT1_RST;              		// SEGDAT1  reset value */
	 LED0->SEGDATA[6]  	=	LED0_SEGDAT2_RST;               	// SEGDAT2  reset value */
	 LED0->SEGDATA[7] 	=	LED0_SEGDAT3_RST;             		// SEGDAT3  reset value */
}
/*************************************************************/
//LED scan enable
//EntryParameter:NewState
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/  
void LED_SCAN_ENABLE(FunctionalStatus NewState)
{
	if (NewState != DISABLE)
	{
		LED0->CR|=LIGHTON;
	}
	else
	{
		LED0->CR&=~LIGHTON;
	}
}
/*************************************************************/
//LED com enable
//EntryParameter:NewState
//NewState:ENABLE,DISABLE
//LED_COMx_ENABLE:0~0x3ff
//ReturnValue:NONE
/*************************************************************/  
void LED_BLKST_Config(U8_T LED_BLKST_ENABLE)
{
	uint8_t i;
	LED0->BLKER=0Xff;
	for (i=0;i<8;i++)
	{
		if ((LED_BLKST_ENABLE & (1<<i))!=0)
		{
			switch (i)
			{
				case 0:
				{
					LED0->BLKDR=0x01;													//COM1使能
					break;
				}
				case 1:
				{
					LED0->BLKDR=0x02;													//COM2使能
					break;
				}
				case 2:
				{
					LED0->BLKDR=0x04;													//COM3使能
					break;
				}
				case 3:
				{
					LED0->BLKDR=0x08;													//COM4使能
					break;
				}
				case 4:
				{
					LED0->BLKDR=0x10;													//COM5使能
					break;
				}
				case 5:
				{
					LED0->BLKDR=0x20;													//COM6使能
					break;
				}
				case 6:
				{
					LED0->BLKDR=0x40;													//COM7使能
					break;
				}
				case 7:
				{
					LED0->BLKDR=0x80;													//COM8使能
					break;
				}
			}
		}
	}
}
/*************************************************************/
//LED Control config
//EntryParameter:LED_LEDCLK,LED_Bright_X,DCOMCNT,NOVCNT
//LED_LEDCLK:LEDCLK_DIV4,LEDCLK_DIV8,LEDCLK_DIV16,LEDCLK_DIV32,LEDCLK_DIV64,LEDCLK_DIV128,LEDCLK_DIV256,LEDCLK_DIV512
//LED_COM_EN:0~0X3FF
//LED_Bright_X:LED_Bright_100,LED_Bright_87,LED_Bright_75,LED_Bright_62,LED_Bright_50,LED_Bright_37,LED_Bright_25,LED_Bright_12
//DCOMCNT:VALUE=1~0XFF(clk=LEDCLK/8)
//NOVCNT:VALUE=1~0XFF
//ReturnValue:NONE
/*************************************************************/  
  //LEDCLK=PLCK/LEDCLK_DIVx
  //LED_Bright_X:LED_Bright_100/LED_Bright_87/LED_Bright_75/LED_Bright_62/LED_Bright_50/LED_Bright_37LED_Bright_25/LED_Bright_12
  //DCOMCNT:COM显示周期长度
  //NOVCNT:相邻COM时间
void LED_Control_Config(LED_LEDCLK_TypeDef LED_LEDCLK , U16_T LED_COM_EN , LED_Bright_TypeDef LED_Bright_X , U8_T DCOMCNT , U8_T NOVCNT  )
{
	LED0->CR|=LED_LEDCLK|(0X00<<4)|(0X00<<7)|(LED_COM_EN<<16);
	LED0->BRIGHT=LED_Bright_X;
	LED0->TIMCR=DCOMCNT|(NOVCNT<<8);
}
/*************************************************************/
//GTC IO Init
//EntryParameter:LED_SEG_X,
//LED_SEG_X:LED_SEG_0,LED_SEG_1,LED_SEG_2,LED_SEG_3,LED_SEG_4,LED_SEG_5,LED_SEG_6,LED_SEG_7
//LED_IO_G:0~2
//ReturnValue:NONE
/*************************************************************/
void LED_seg_io_initial(LED_SEG_X_TypeDef LED_SEG_X , U8_T LED_IO_G)
{
	if(LED_SEG_X==LED_SEG_0)
	{
		if(LED_IO_G==0)
		{
			GPIOA0->CONLR=(GPIOA0->CONLR&0XF0FFFFFF) | 0x09000000;				//seg0 PA0.6
			GPIO_CCM_EN(GPIOA0,6);
		}
		else if(LED_IO_G==1) 
		{
			GPIOA0->CONHR=(GPIOA0->CONHR&0XFFFF0FFF) | 0x00008000;				//seg0 PA0.11
			GPIO_CCM_EN(GPIOA0,11);
		}
		else if(LED_IO_G==2)
		{
			GPIOA0->CONHR=(GPIOA0->CONHR&0XF0FFFFFF) | 0x08000000;				//seg0 PA0.14
			GPIO_CCM_EN(GPIOA0,14);
		}
	}
	else if(LED_SEG_X==LED_SEG_1)
	{
		if(LED_IO_G==0)
		{
			GPIOA0->CONLR=(GPIOA0->CONLR&0X0FFFFFFF) | 0x90000000;				//seg1 PA0.7
			GPIO_CCM_EN(GPIOA0,7);
		}
		else if(LED_IO_G==1) 
		{
			GPIOA0->CONHR=(GPIOA0->CONHR&0XFFF0FFFF) | 0x00080000;				//seg1 PA0.12
			GPIO_CCM_EN(GPIOA0,12);
		}
		else if(LED_IO_G==2) 
		{
			GPIOA0->CONHR=(GPIOA0->CONHR&0X0FFFFFFF) | 0x80000000;				//seg1 PA0.15
			GPIO_CCM_EN(GPIOA0,15);
		}
	}
	else if(LED_SEG_X==LED_SEG_2)
	{
		if(LED_IO_G==0)
		{
			GPIOA0->CONHR=(GPIOA0->CONHR&0XFFFFFFF0) | 0x00000009;				//seg2 PA0.8
			GPIO_CCM_EN(GPIOA0,8);
		}
		else if(LED_IO_G==1) 
		{
			GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFF0FFF) | 0x00008000;				//seg2 PB0.3
			GPIO_CCM_EN(GPIOB0,3);
		}
	}
	else if(LED_SEG_X==LED_SEG_3)
	{
		if(LED_IO_G==0)
		{
			GPIOA0->CONHR=(GPIOA0->CONHR&0XFFFFFF0F) | 0x00000090;				//seg3 PA0.9
			GPIO_CCM_EN(GPIOA0,9);
		}
		else if(LED_IO_G==1) 
		{
			GPIOA0->CONHR=(GPIOA0->CONHR&0XFF0FFFFF) | 0x00800000;				//seg3 PA0.13
			GPIO_CCM_EN(GPIOA0,13);
		}
		else if(LED_IO_G==2) 
		{
			GPIOC0->CONLR=(GPIOC0->CONLR&0XFFFFFF0F) | 0x00000080;				//seg3 PC0.1
			GPIO_CCM_EN(GPIOC0,1);
		}
	}
	else if(LED_SEG_X==LED_SEG_4)
	{
		if(LED_IO_G==0)
		{
			GPIOA0->CONHR=(GPIOA0->CONHR&0XFFFFF0FF) | 0x00000900;				//seg4 PA0.10
			GPIO_CCM_EN(GPIOA0,10);
		}
		else if(LED_IO_G==1) 
		{
			GPIOB0->CONLR=(GPIOB0->CONLR&0XFFF0FFFF) | 0x00080000;				//seg4 PB0.4
			GPIO_CCM_EN(GPIOB0,4);
		}
	}
	else if(LED_SEG_X==LED_SEG_5)
	{
		if(LED_IO_G==0)
		{
			GPIOA0->CONHR=(GPIOA0->CONHR&0XFFFF0FFF) | 0x00009000;				//seg5 PA0.11
			GPIO_CCM_EN(GPIOA0,11);
		}
		else if(LED_IO_G==1) 
		{
			GPIOA1->CONLR=(GPIOA1->CONLR&0XFFFFFFF0) | 0x00000008;				//seg5 PA1.0
			GPIO_CCM_EN(GPIOA1,0);
		}
	}
	else if(LED_SEG_X==LED_SEG_6)
	{
		if(LED_IO_G==0)
		{
			GPIOA0->CONHR=(GPIOA0->CONHR&0XFFF0FFFF) | 0x00090000;				//seg6 PA0.12
			GPIO_CCM_EN(GPIOA0,12);
		}
		else if(LED_IO_G==1) 
		{
			GPIOA1->CONLR=(GPIOA1->CONLR&0XFFFFFF0F) | 0x00000080;				//seg6 PA1.1
			GPIO_CCM_EN(GPIOA1,1);
		}
	}
	else if(LED_SEG_X==LED_SEG_7)
	{
		if(LED_IO_G==0)
		{
			GPIOA0->CONHR=(GPIOA0->CONHR&0XFF0FFFFF) | 0x00900000;				//seg7 PA0.13
			GPIO_CCM_EN(GPIOA0,13);
		}
		else if(LED_IO_G==1) 
		{
			GPIOA1->CONLR=(GPIOA1->CONLR&0XFFFFF0FF) | 0x00000800;				//seg7 PA1.2
			GPIO_CCM_EN(GPIOA0,12);
		}
	}
}

/*************************************************************/
//GTC IO Init
//EntryParameter:LED_SEG_X,
//LED_SEG_X:LED_COM_0~LED_COM_9
//LED_IO_G:0~2
//ReturnValue:NONE
/*************************************************************/
void LED_COM_IO_initial(LED_COM_X_TypeDef LED_COM_X , U8_T LED_IO_G)
{
	if(LED_COM_X==LED_COM_0)
	{
		if(LED_IO_G==0)
		{
			GPIOA1->CONLR=(GPIOA1->CONLR&0XF0FFFFFF) | 0x08000000;				//COM0 PA1.6
			GPIO_DriveStrength_EN(GPIOA1,6);
		}
	}
	else if(LED_COM_X==LED_COM_1)
	{
		if(LED_IO_G==0)
		{
			GPIOB0->CONLR=(GPIOB0->CONLR&0XFF0FFFFF) | 0x00800000;				//COM1 PB0.5
			GPIO_DriveStrength_EN(GPIOB0,5);
		}
	}
	else if(LED_COM_X==LED_COM_2)
	{
		if(LED_IO_G==0)
		{
			GPIOA1->CONLR=(GPIOA1->CONLR&0X0FFFFFFF) | 0x80000000;				//COM2 PA1.7  SWDIO
			GPIO_DriveStrength_EN(GPIOA1,7);
		}
	}
	else if(LED_COM_X==LED_COM_3)
	{
		if(LED_IO_G==0)
		{
			GPIOB0->CONLR=(GPIOB0->CONLR&0XF0FFFFFF) | 0x08000000;				//COM3 PB0.6
			GPIO_DriveStrength_EN(GPIOB0,6);
		}
	}
	else if(LED_COM_X==LED_COM_4)
	{
		if(LED_IO_G==0)
		{
			GPIOB0->CONLR=(GPIOB0->CONLR&0X0FFFFFFF) | 0x80000000;				//COM4 PB0.7
			GPIO_DriveStrength_EN(GPIOB0,7);
		}
	}
	else if(LED_COM_X==LED_COM_5)
	{
		if(LED_IO_G==0)
		{
			GPIOA1->CONHR=(GPIOA1->CONHR&0XFFFFFFF0) | 0x00000008;				//COM5 PA1.8   SWCLK
			GPIO_DriveStrength_EN(GPIOA1,8);
		}
	}
	else if(LED_COM_X==LED_COM_6)
	{
		if(LED_IO_G==0)
		{
			GPIOB0->CONHR=(GPIOB0->CONHR&0XFFFFFFF0) | 0x00000008;				//COM6 PB0.8
			GPIO_DriveStrength_EN(GPIOB0,8);
		}
		else if(LED_IO_G==1)
		{
			GPIOB0->CONHR=(GPIOB0->CONHR&0XFFFFF0FF) | 0x00000800;				//COM6 PB0.10
		}
	}
	else if(LED_COM_X==LED_COM_7)
	{
		if(LED_IO_G==0)
		{
			GPIOA1->CONHR=(GPIOA1->CONHR&0XFFFF0FFF) | 0x00008000;				//COM7 PA1.11
			GPIO_DriveStrength_EN(GPIOA1,11);
		}
		else if(LED_IO_G==1)
		{
			GPIOB0->CONHR=(GPIOB0->CONHR&0XFFFF0FFF) | 0x00008000;				//COM7 PB0.11
		}
	}
	else if(LED_COM_X==LED_COM_8)
	{
		if(LED_IO_G==0)
		{
			GPIOA1->CONHR=(GPIOA1->CONHR&0XFFF0FFFF) | 0x00080000;				//COM8 PA1.12
			GPIO_DriveStrength_EN(GPIOA1,12);
		}
		else if(LED_IO_G==1)
		{
			GPIOA1->CONHR=(GPIOA1->CONHR&0XFFFFFF0F) | 0x00000080;				//COM8 PB1.9
		}
	}
	else if(LED_COM_X==LED_COM_9)
	{
		if(LED_IO_G==0)
		{
			GPIOA1->CONHR=(GPIOA1->CONHR&0XFF0FFFFF) | 0x00800000;				//COM8 PA1.13
			GPIO_DriveStrength_EN(GPIOA1,13);
		}
	}
}
/*************************************************************/
//LED Interruput enable and disable
//EntryParameter:LED_INT_x,NewState 
//LED_INT_x:ICEND,IPEND
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/  
  //ICEND:Interrupt Masking Enable/Disable for One COM scan cycle completing
  //IPEND:Interrupt Masking Enable/Disable for All COM scan cycle is completing
void LED_INT_CMD(LED_INT_TypeDef LED_INT_x , FunctionalStatus NewState)
{
	if (NewState != DISABLE)
	{
		LED0->IMCR  |= LED_INT_x;						//ENABLE
	}
	else
	{
		LED0->IMCR  &= ~LED_INT_x;						//DIABLE
	}
}  
/*************************************************************/
//LED SEGDATX data write
//EntryParameter:SEGDATX,SEGDATX_data
//SEGDATX:SEGDAT_NUM0~SEGDAT_NUM9
//SEGDATX_data:VALUE=1~0XFF
//ReturnValue:NONE
/*************************************************************/  
void LED_SEGDATX_data_write(LED_SEGDATX_TypeDef SEGDATX , U8_T SEGDATX_data)
{
	switch(SEGDATX)
	{
		case SEGDAT_NUM0:
			LED0->SEGDATA[0]=SEGDATX_data;
			break;
		case SEGDAT_NUM1:
			LED0->SEGDATA[1]=SEGDATX_data;
			break;
		case SEGDAT_NUM2:
			LED0->SEGDATA[2]=SEGDATX_data;
			break;
		case SEGDAT_NUM3:
			LED0->SEGDATA[3]=SEGDATX_data;
			break;
		case SEGDAT_NUM4:
			LED0->SEGDATA[4]=SEGDATX_data;
			break;
		case SEGDAT_NUM5:
			LED0->SEGDATA[5]=SEGDATX_data;
			break;
		case SEGDAT_NUM6:
			LED0->SEGDATA[6]=SEGDATX_data;
			break;
		case SEGDAT_NUM7:
			LED0->SEGDATA[7]=SEGDATX_data;
			break;
		case SEGDAT_NUM8:
			LED0->SEGDATA[8]=SEGDATX_data;
			break;
		case SEGDAT_NUM9:
			LED0->SEGDATA[9]=SEGDATX_data;
			break;
	}		
} 

/*************************************************************/
//LED Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void LED_Int_Enable(void)
{
    INTC_ISER_WRITE(LED_INT);    
}

/*************************************************************/
//led Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void LED_Int_Disable(void)
{
    INTC_ICER_WRITE(LED_INT);    
} 




/*********************************************************************** 
//						 END OF FILE         
***********************************************************************/