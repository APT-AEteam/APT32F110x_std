/*
  ******************************************************************************
  * @file    apt32f110_led.h
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2022/01/08
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


#ifndef _apt32f110_led_H
#define _apt32f110_led_H

/****************************************************
//include
*****************************************************/ 
#include "apt32f110x.h"

/*********************************************************************** 
 @brief  LED0 Registers reset value                 
***********************************************************************/ 
#define		 LED0_CR_RST     			((CSP_REGISTER_T)0x00000000)		// CR  reset value  	
#define		 LED0_BRIGHT_RST            ((CSP_REGISTER_T)0x00000000)      	// BRIGHT  reset value8
#define		 LED0_RISR_RST       		((CSP_REGISTER_T)0x00000000)  		// RISR reset value  	
#define		 LED0_IMCR_RST             	((CSP_REGISTER_T)0x00000000)		// IMCR   reset value 
#define		 LED0_MISR_RST              ((CSP_REGISTER_T)0x00000000)    	// MISR   reset value 
#define		 LED0_ICR_RST               ((CSP_REGISTER_T)0x00000000)    	// ICR   reset value  
#define		 LED0_TIMCR_RST             ((CSP_REGISTER_T)0x00000000)		// TIMCR  reset value 
#define		 LED0_BLKER_RST             ((CSP_REGISTER_T)0x00000000)		// BLKER  reset value 
#define		 LED0_BLKDR_RST             ((CSP_REGISTER_T)0x00000000)		// BLKDR  reset value 
#define		 LED0_BLKST_RST             ((CSP_REGISTER_T)0x00000000)		// BLKST  reset value 
#define		 LED0_SEGDAT0_RST           ((CSP_REGISTER_T)0x00000000)     	// SEGDAT0  reset value
#define		 LED0_SEGDAT1_RST           ((CSP_REGISTER_T)0x00000000)   		// SEGDAT1  reset value
#define		 LED0_SEGDAT2_RST           ((CSP_REGISTER_T)0x00000000)    	// SEGDAT2  reset value
#define		 LED0_SEGDAT3_RST           ((CSP_REGISTER_T)0x00000000)  		// SEGDAT3  reset value
#define		 LED0_SEGDAT4_RST           ((CSP_REGISTER_T)0x00000000)     	// SEGDAT4  reset value
#define		 LED0_SEGDAT5_RST           ((CSP_REGISTER_T)0x00000000)   		// SEGDAT5  reset value
#define		 LED0_SEGDAT6_RST           ((CSP_REGISTER_T)0x00000000)    	// SEGDAT6  reset value
#define		 LED0_SEGDAT7_RST           ((CSP_REGISTER_T)0x00000000)  		// SEGDAT7  reset value

/*********************************************************************** 
 @brief  LED0 Registers value                 
***********************************************************************/ 
#define LIGHTON          ((CSP_REGISTER_T)(0x00000001ul))          //led  LIGHT ON
 
/*********************************************************************** 
 @brief  LED0 CLK Control                
***********************************************************************/  
typedef enum
{
		LEDCLK_DIV4  =  ((CSP_REGISTER_T)(0x00ul << 1)),
		LEDCLK_DIV8  =  ((CSP_REGISTER_T)(0x01ul << 1)),
		LEDCLK_DIV16 =  ((CSP_REGISTER_T)(0x02ul << 1)),
		LEDCLK_DIV32 =  ((CSP_REGISTER_T)(0x03ul << 1)),
		LEDCLK_DIV64 =  ((CSP_REGISTER_T)(0x04ul << 1)),
		LEDCLK_DIV128 = ((CSP_REGISTER_T)(0x05ul << 1)),
		LEDCLK_DIV256 = ((CSP_REGISTER_T)(0x06ul << 1)),
		LEDCLK_DIV32_2 = ((CSP_REGISTER_T)(0x07ul << 1))
}LED_LEDCLK_TypeDef;

/*********************************************************************** 
 @brief  LED0 Bright set                
***********************************************************************/
typedef enum
{
	LED_Bright_100			=			((CSP_REGISTER_T)(0X00)),	
	LED_Bright_87			=			((CSP_REGISTER_T)(0X01)),
	LED_Bright_75			=			((CSP_REGISTER_T)(0X02)),	
	LED_Bright_62			=			((CSP_REGISTER_T)(0X03)),
	LED_Bright_50			=			((CSP_REGISTER_T)(0X04)),	
	LED_Bright_37			=			((CSP_REGISTER_T)(0X05)),
	LED_Bright_25			=			((CSP_REGISTER_T)(0X06)),	
	LED_Bright_12			=			((CSP_REGISTER_T)(0X07))
}LED_Bright_TypeDef;

/*********************************************************************** 
 @brief  LED0 INT             
***********************************************************************/
typedef enum
{
	ICEND				=			((CSP_REGISTER_T)(0X01<<0)),	
	IPEND				=			((CSP_REGISTER_T)(0X01<<1)),	
}LED_INT_TypeDef;	

/*********************************************************************** 
 @brief  LED0 SEGDATX data selected             
***********************************************************************/
typedef enum
{
	SEGDAT_NUM0				=			((CSP_REGISTER_T)(0X00)),	
	SEGDAT_NUM1				=			((CSP_REGISTER_T)(0X01)),	
	SEGDAT_NUM2				=			((CSP_REGISTER_T)(0X02)),
	SEGDAT_NUM3				=			((CSP_REGISTER_T)(0X03)),
	SEGDAT_NUM4				=			((CSP_REGISTER_T)(0X04)),	
	SEGDAT_NUM5				=			((CSP_REGISTER_T)(0X05)),	
	SEGDAT_NUM6				=			((CSP_REGISTER_T)(0X06)),
	SEGDAT_NUM7				=			((CSP_REGISTER_T)(0X07)),
	SEGDAT_NUM8				=			((CSP_REGISTER_T)(0X08)),
	SEGDAT_NUM9				=			((CSP_REGISTER_T)(0X09))
}LED_SEGDATX_TypeDef;

/*********************************************************************** 
 @brief  LED0 SEG selected            
***********************************************************************/
typedef enum
{
	LED_SEG_0		=		1,
	LED_SEG_1		=		2,
	LED_SEG_2		=		3,
	LED_SEG_3		=		4,
	LED_SEG_4		=		5,
	LED_SEG_5		=		6,
	LED_SEG_6		=		7,
	LED_SEG_7		=		8,
}LED_SEG_X_TypeDef;  

/*********************************************************************** 
 @brief  LED0 COM selected            
***********************************************************************/
typedef enum
{
	LED_COM_0		=		1,
	LED_COM_1		=		2,
	LED_COM_2		=		3,
	LED_COM_3		=		4,
	LED_COM_4		=		5,
	LED_COM_5		=		6,
	LED_COM_6		=		7,
	LED_COM_7		=		8,
	LED_COM_8		=		9,
	LED_COM_9		=		10
}LED_COM_X_TypeDef; 
/*********************************************************************** 
 @brief  led extern functions                  
***********************************************************************/ 
extern void LED_RESET_VALUE(void);
extern void LED_SCAN_ENABLE(FunctionalStatus NewState);
extern void LED_BLKST_Config(U8_T LED_BLKST_ENABLE);
extern void LED_Control_Config(LED_LEDCLK_TypeDef LED_LEDCLK , U16_T LED_COM_EN , LED_Bright_TypeDef LED_Bright_X , U8_T DCOMCNT , U8_T NOVCNT  );
extern void LED_seg_io_initial(LED_SEG_X_TypeDef LED_SEG_X , U8_T LED_IO_G);
extern void LED_INT_CMD(LED_INT_TypeDef LED_INT_x , FunctionalStatus NewState);
extern void LED_SEGDATX_data_write(LED_SEGDATX_TypeDef SEGDATX , U8_T SEGDATX_data);
extern void LED_Int_Enable(void);
extern void LED_Int_Disable(void);
extern unsigned char LED_CHAR_[11];
extern void LED_COM_IO_initial(LED_COM_X_TypeDef LED_COM_X , U8_T LED_IO_G);

#endif   // apt32f110_led_H */


/*********************************************************************** 
//				(C) COPYRIGHT 2022 APT Chip 
//						 END OF FILE         
***********************************************************************/
