/*
  ******************************************************************************
  * @file    apt32f110_lcd.h
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2022/01/20
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
#ifndef _apt32f110_lcd_H
#define _apt32f110_lcd_H

/* Includes ------------------------------------------------------------------*/
#include "apt32f110x.h"

//lcd cedr  
#define lcd_clken    ((CSP_REGISTER_T)(0x01))
//lcd srr 
#define lcd_swrst		((CSP_REGISTER_T)(0x01))			//复位不影响LCD_CEDR LCD_DMRX[0]~LCD_DMRX[31]
//lcd cr 
#define lcd_en			((CSP_REGISTER_T)(0x01))

#define LCD_SEG0	((CSP_REGISTER_T)(0x01<<0))
#define LCD_SEG1	((CSP_REGISTER_T)(0x01<<1))
#define LCD_SEG2	((CSP_REGISTER_T)(0x01<<2))
#define LCD_SEG3	((CSP_REGISTER_T)(0x01<<3))
#define LCD_SEG4	((CSP_REGISTER_T)(0x01<<4))
#define LCD_SEG5	((CSP_REGISTER_T)(0x01<<5))
#define LCD_SEG6	((CSP_REGISTER_T)(0x01<<6))
#define LCD_SEG7	((CSP_REGISTER_T)(0x01<<7))
#define LCD_SEG8	((CSP_REGISTER_T)(0x01<<8))
#define LCD_SEG9	((CSP_REGISTER_T)(0x01<<9))

#define LCD_SEG10	((CSP_REGISTER_T)(0x01<<10))
#define LCD_SEG11	((CSP_REGISTER_T)(0x01<<11))
#define LCD_SEG12	((CSP_REGISTER_T)(0x01<<12))
#define LCD_SEG13	((CSP_REGISTER_T)(0x01<<13))
#define LCD_SEG14	((CSP_REGISTER_T)(0x01<<14))
#define LCD_SEG15	((CSP_REGISTER_T)(0x01<<15))
#define LCD_SEG16	((CSP_REGISTER_T)(0x01<<16))
#define LCD_SEG17	((CSP_REGISTER_T)(0x01<<17))
#define LCD_SEG18	((CSP_REGISTER_T)(0x01<<18))
#define LCD_SEG19	((CSP_REGISTER_T)(0x01<<19))

#define LCD_SEG20	((CSP_REGISTER_T)(0x01<<20))
#define LCD_SEG21	((CSP_REGISTER_T)(0x01<<21))
#define LCD_SEG22	((CSP_REGISTER_T)(0x01<<22))
#define LCD_SEG23	((CSP_REGISTER_T)(0x01<<23))
#define LCD_SEG24	((CSP_REGISTER_T)(0x01<<24))
#define LCD_SEG25	((CSP_REGISTER_T)(0x01<<25))
#define LCD_SEG26	((CSP_REGISTER_T)(0x01<<26))
#define LCD_SEG27	((CSP_REGISTER_T)(0x01<<27))
#define LCD_SEG28	((CSP_REGISTER_T)(0x01<<28))
#define LCD_SEG29	((CSP_REGISTER_T)(0x01<<29))

#define LCD_SEG30	((CSP_REGISTER_T)(0x01<<30))
#define LCD_SEG31	((CSP_REGISTER_T)(0x01<<31))

#define LCD_COM0	((CSP_REGISTER_T)(0x01<<0))
#define LCD_COM1	((CSP_REGISTER_T)(0x01<<1))
#define LCD_COM2	((CSP_REGISTER_T)(0x01<<2))
#define LCD_COM3	((CSP_REGISTER_T)(0x01<<3))
#define LCD_COM4	((CSP_REGISTER_T)(0x01<<4))
#define LCD_COM5	((CSP_REGISTER_T)(0x01<<5))
#define LCD_COM6	((CSP_REGISTER_T)(0x01<<6))
#define LCD_COM7	((CSP_REGISTER_T)(0x01<<7))

typedef enum
{
	lcd_display_close	=  ((CSP_REGISTER_T)(0x00<<1)),
	lcd_display_all		=  ((CSP_REGISTER_T)(0x01<<1)),
	lcd_display_buffer	=  ((CSP_REGISTER_T)(0x02<<1))
}Lcd_display_mode_TypeDef;

typedef enum
{
	Lcd_Blink_MD_dis			=		((CSP_REGISTER_T)(0x00<<11)),
	Lcd_Blink_MD_Seg8_Com0		=		((CSP_REGISTER_T)(0x01<<11)),	
	Lcd_Blink_MD_Seg8_AllCom	=		((CSP_REGISTER_T)(0x02<<11)),
	Lcd_Blink_MD_AllLight		=		((CSP_REGISTER_T)(0x03<<11))
}Lcd_Blink_MD_TypeDef;

typedef enum
{
	Lcd_Blink_Fre_DIV_8		=		((CSP_REGISTER_T)(0x00<<13)),
	Lcd_Blink_Fre_DIV_16	=		((CSP_REGISTER_T)(0x01<<13)),
	Lcd_Blink_Fre_DIV_32	=		((CSP_REGISTER_T)(0x02<<13)),
	Lcd_Blink_Fre_DIV_64	=		((CSP_REGISTER_T)(0x03<<13)),
	Lcd_Blink_Fre_DIV_128	=		((CSP_REGISTER_T)(0x04<<13)),
	Lcd_Blink_Fre_DIV_256	=		((CSP_REGISTER_T)(0x05<<13)),
	Lcd_Blink_Fre_DIV_512	=		((CSP_REGISTER_T)(0x06<<13)),
	Lcd_Blink_Fre_DIV_CR2	=		((CSP_REGISTER_T)(0x07<<13))
}Lcd_Blink_Fre_TypeDef;

typedef enum
{
	Vlcd_Selected_ExtVDD		=		1,
	Vlcd_Selected_IntVDD_2_6V	=		2,
	Vlcd_Selected_IntVDD_2_8V	=		3,
	Vlcd_Selected_IntVDD_3_0V	=		4,
	Vlcd_Selected_IntVDD_3_2V	=		5,
	Vlcd_Selected_IntVDD_3_4V	=		6,
	Vlcd_Selected_IntVDD_3_6V	=		7,
	Vlcd_Selected_IntVDD_3_8V	=		8,	
	Vlcd_Selected_IntVDD_4_0V	=		9,	
	
}Vlcd_Selected_TypeDef;

typedef enum
{
	Lcd_DutyBiase_Selected_1_8Duty_1_4_Bias	=	((CSP_REGISTER_T)(0x00<<8)),
	Lcd_DutyBiase_Selected_1_6Duty_1_4_Bias	=	((CSP_REGISTER_T)(0x01<<8)),
	Lcd_DutyBiase_Selected_1_5Duty_1_3_Bias	=	((CSP_REGISTER_T)(0x02<<8)),
	Lcd_DutyBiase_Selected_1_4Duty_1_3_Bias	=	((CSP_REGISTER_T)(0x03<<8)),
	Lcd_DutyBiase_Selected_1_3Duty_1_3_Bias	=	((CSP_REGISTER_T)(0x04<<8)),
	Lcd_DutyBiase_Selected_1_3Duty_1_2_Bias	=	((CSP_REGISTER_T)(0x05<<8)),
	Lcd_DutyBiase_Selected_1_2Duty_1_2_Bias	=	((CSP_REGISTER_T)(0x06<<8))
}Lcd_DutyBiase_Selected_TypeDef;

typedef enum
{
	Lcd_Contrast_Selecte_1		=	1,
	Lcd_Contrast_Selecte_2		=	2,
	Lcd_Contrast_Selecte_3		=	3,
	Lcd_Contrast_Selecte_4		=	4,
	Lcd_Contrast_Selecte_5		=	5,
	Lcd_Contrast_Selecte_6		=	6,
	Lcd_Contrast_Selecte_7		=	7,
	Lcd_Contrast_Selecte_8		=	8,
	Lcd_Contrast_Selecte_9		=	9
}Lcd_Contrast_TypeDef;

typedef enum
{
	Lcd_INT_SOF					=	((CSP_REGISTER_T)(0x02)),
	Lcd_INT_UDD					=	((CSP_REGISTER_T)(0x08))
}Lcd_INT_TypeDef;

typedef enum
{
	Lcd_BP_EN  =	1,
	Lcd_BP_DIS =	0
}Lcd_BP_CMD_TypeDef;

typedef enum
{
	Lcd_Clk_RTC = 0<<1,		//选择RTC所选择的时钟
	Lcd_Clk_ISOSC = 1<<1
}Lcd_Clk_selected_TypeDef;

typedef enum
{
	Lcd_Display_allclose	=   0<<1,
	Lcd_Display_allopen   	=   1<<1,
	Lcd_Diplay_bufer		=	2<<1
}Lcd_Dis_mode_TypeDef;

extern void Lcd_Reset_Value(void);
extern void Lcd_Clk_Enable(FunctionalStatus NewState , Lcd_Clk_selected_TypeDef Lcd_Clk_x);
extern void Lcd_Scan_Enable(FunctionalStatus NewState);
extern void lcd_Software_Reset(void);
extern void Lcd_io_initial(U32_T LCD_Seg_ENABLE , U16_T LCD_Com_ENABLE);
extern void Lcdclk_Config( U8_T cdiv , U16_T cpre);
extern void Lcd_Blink_Config(Lcd_Blink_MD_TypeDef Lcd_Blink_MD_x , Lcd_Blink_Fre_TypeDef Lcd_Blink_Fre_x , U16_T Lcd_Blink_F2);
extern void Lcd_Display_Config(Vlcd_Selected_TypeDef Vlcd_Selected_x , Lcd_DutyBiase_Selected_TypeDef Lcd_DutyBiase_Selected_x , 
				Lcd_Contrast_TypeDef Lcd_Contrast_x  , Lcd_display_mode_TypeDef Lcd_display_x , Lcd_BP_CMD_TypeDef Lcd_BP_CMD , U8_T Lcd_deadclk  );
extern void Lcd_Write_Data(U8_T *Lcd_data_buf );
extern void Lcd_Int_Config(Lcd_INT_TypeDef Lcd_X_INT);
extern void lcd_display_mode(Lcd_Dis_mode_TypeDef Lcd_Dis_mode);
extern void Lcd_Vector_Enable(void);
extern void Lcd_Vector_Disable(void);
extern void Lcd_Wakeup_Enable(void);
extern void Lcd_Wakeup_Disable(void);

#endif   /**< apt32f110_ifc_H */

/******************* (C) COPYRIGHT 2022 APT Chip *****END OF FILE****/