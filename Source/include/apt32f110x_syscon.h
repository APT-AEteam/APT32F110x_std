/*
  ******************************************************************************
  * @file    apt32f110_syscon.h
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2022/01/21
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
  
#ifndef _apt32f110_syscon_H
#define _apt32f110_syscon_H

/****************************************************
//include
*****************************************************/ 
#include "apt32f110x.h"

/***********************************************************************
 @brief SYSCON Registers Reset Value
***********************************************************************/

#define SYSCON_IDCCR_RST     	((CSP_REGISTER_T)0xFFFFFF01)
#define SYSCON_GCER_RST     	((CSP_REGISTER_T)0x00000000)
#define SYSCON_GCDR_RST     	((CSP_REGISTER_T)0x00000000)
#define SYSCON_GCSR_RST     	((CSP_REGISTER_T)0x00081103)
#define SYSCON_CKST_RST			((CSP_REGISTER_T)0x00000103)
#define SYSCON_RAMCHK_RST		((CSP_REGISTER_T)0x0000ffff)
#define SYSCON_EFLCHK_RST		((CSP_REGISTER_T)(0X0<<24)|0xffffff)
#define SYSCON_SCLKCR_RST      	((CSP_REGISTER_T)0xD22Dul<<16)
#define SYSCON_PCLKCR_RST     	((CSP_REGISTER_T)0x00000100)
#define SYSCON_PCER0_RST   		((CSP_REGISTER_T)0x00000000)
#define SYSCON_PCDR0_RST  		((CSP_REGISTER_T)0x00000000)
#define SYSCON_PCSR0_RST  		((CSP_REGISTER_T)0x00100001)
#define SYSCON_PCER1_RST     	((CSP_REGISTER_T)0x00000000)
#define SYSCON_PCDR1_RST     	((CSP_REGISTER_T)0x00000000)
#define SYSCON_PCSR1_RST 		((CSP_REGISTER_T)0x00000000)
#define SYSCON_OSTR_RST  		((CSP_REGISTER_T)0x70ff3bff)
#define SYSCON_LVDCR_RST  		((CSP_REGISTER_T)0x0000000a)
#define	SYSCON_CLCR_RST			((CSP_REGISTER_T)0x00000100)
#define	SYSCON_PWRCR_RST		((CSP_REGISTER_T)0x0F170040)
#define	SYSCON_PWRKEY_RST		((CSP_REGISTER_T)0x00000000)
#define SYSCON_OPT1				((CSP_REGISTER_T)0x00000000)
#define SYSCON_OPT0				((CSP_REGISTER_T)0x00000000)
#define SYSCON_WKCR				((CSP_REGISTER_T)0x00000000)
#define	SYSCON_IMER_RST			((CSP_REGISTER_T)0x00000000)
#define	SYSCON_IMDR_RST			((CSP_REGISTER_T)0x00000000)
#define	SYSCON_IMCR_RST			((CSP_REGISTER_T)0x00000000)
#define	SYSCON_IAR_RST			((CSP_REGISTER_T)0x00000000)
#define	SYSCON_ICR_RST			((CSP_REGISTER_T)0x00000000)
#define	SYSCON_RISR_RST			((CSP_REGISTER_T)0x00000000)
#define	SYSCON_MISR_RST			((CSP_REGISTER_T)0x00000000)
#define	SYSCON_EXIRT_RST		((CSP_REGISTER_T)0x00000000)
#define	SYSCON_EXIFT_RST		((CSP_REGISTER_T)0x00000000)
#define	SYSCON_EXIER_RST		((CSP_REGISTER_T)0x00000000)
#define	SYSCON_EXIDR_RST		((CSP_REGISTER_T)0x00000000)
#define	SYSCON_EXIMR_RST		((CSP_REGISTER_T)0x00000000)
#define	SYSCON_EXIAR_RST		((CSP_REGISTER_T)0x00000000)
#define	SYSCON_EXICR_RST		((CSP_REGISTER_T)0x00000000)
#define	SYSCON_EXIRS_RST		((CSP_REGISTER_T)0x00000000)
#define	SYSCON_IWDCR_RST		((CSP_REGISTER_T)0x0000070C)
#define	SYSCON_IWDCNT_RST		((CSP_REGISTER_T)0x0003FFFF)
#define	SYSCON_PWROPT_RST		((CSP_REGISTER_T)0x00004040)
#define	SYSCON_EVTRG_RST		((CSP_REGISTER_T)0x00000000)
#define	SYSCON_EVPS_RST			((CSP_REGISTER_T)0x00000000)
#define	SYSCON_EVSWF_RST		((CSP_REGISTER_T)0x00000000)
#define	SYSCON_UREG0_RST		((CSP_REGISTER_T)0x00000000)
#define	SYSCON_UREG1_RST		((CSP_REGISTER_T)0x00000000)
#define	SYSCON_UREG2_RST		((CSP_REGISTER_T)0x00000000)
#define	SYSCON_UREG3_RST		((CSP_REGISTER_T)0x00000000)

/***********************************************************************
 @brief SYSCON Registers SCLKCR Value
***********************************************************************/
#define SYSCLK_KEY 		(0xD22Dul<<16)

/***********************************************************************
 @brief SYSCON Registers PCLK CONTROL Value
***********************************************************************/
#define PCLK_KEY 	 	(0xC33Cul<<16)

/***********************************************************************
 @brief SYSCON Registers IDCCR Value
***********************************************************************/
#define	CLKEN			(0X01ul)
#define	CPUFTRST_EN		(0X00<<1)
#define	CPUFTRST_DIS	(0XA<<1)
#define	SWRST			(0X04ul<<5)
#define	CPURST			(0X05ul<<5)
#define IDCCR_KEY 		(0xE11Eul<<16)

/***********************************************************************
 @brief SYSCON Registers LVDCR Value
***********************************************************************/
#define	LVDFLAG			(0x01ul<<15)			//0: VDD is higher than LVD threshold selected with INTDET_LVL bits.   1: VDD is lower than LVD threshold selected with INTDET_LVL bits
#define LVD_KEY 		(0xB44Bul<<16)


/***********************************************************************
 @brief SYSCON Registers Interrupt Value
***********************************************************************/
#define ISOSC_ST 		(0x01ul)
#define IMOSC_ST 		(0x01ul<<1)
#define ESOSC_ST 		(0x01ul<<2)
#define EMOSC_ST 		(0x01ul<<3)
#define HFOSC_ST 		(0x01ul<<4)
#define SYSCLK_ST 		(0x01ul<<7)
#define	IWDT_INT_ST 	(0x01ul<<8)
#define	WKI_INT_ST		(0x01ul<<9)
#define RAMERRINT_ST	(0X01ul<<10)
#define	LVD_INT_ST 		(0x01ul<<11)
#define HWD_ERR_ST			(0X01ul<<12)
#define EFL_ERR_ST		(0X01ul<<13)
#define OPTERR_INT		(0X01ul<<14)
#define	EM_CMLST_ST 	(0x01ul<<18)
#define	EM_EVTRG0_ST 	(0x01ul<<19)
#define	EM_EVTRG1_ST 	(0x01ul<<20)
#define	EM_EVTRG2_ST 	(0x01ul<<21)
#define	EM_EVTRG3_ST 	(0x01ul<<22)
#define	CMD_ERR_ST		(0x01ul<<29)

/***********************************************************************
 @brief SYSCON Reset Status Register
***********************************************************************/
#define	PORST			(0X01ul)
#define	LVRRST			(0X01ul<<1)
#define	EXTRST			(0X01ul<<2)
#define	ALVRST			(0X01ul<<3)
#define	IWDRST			(0X01ul<<4)
#define	EMCMRST			(0X01ul<<6)
#define	CPURSTREQ		(0X01ul<<7)
#define	SWRST_RSR		(0X01ul<<8)
#define	CPUFAULT_RSR	(0X01ul<<9)
#define	SRAM_RSR		(0X01ul<<11)
#define	EFL_ERR			(0X01ul<<12)
#define WWDTRST			(0X01ul<<13)

/***********************************************************************
 @brief SYSCON IWDT Register
***********************************************************************/
#define	Check_IWDT_BUSY			(0x01ul<<12)					//Indicates the independent watchdog operation
#define IWDT_KEY 				(0x8778ul<<16)
#define	CLR_IWDT				(0x5aul<<24)
#define	Enable_IWDT				(0x0)
#define	Disable_IWDT			(0x55aa)
#define IWDTEDR_KEY 			(0x7887ul<<16)

/***********************************************************************
 @brief SYSCON IRQ Number
***********************************************************************/
#define CORET_IRQ   0
#define SYSCON_IRQ  1
#define IFC_IRQ     2
#define ADC_IRQ     3
#define EPT0_IRQ    4
#define DMA_IRQ		5
#define WWDT_IRQ	6
#define EXI0_IRQ	7
#define EXI1_IRQ	8
#define GPTA0_IRQ	9
#define GPTA1_IRQ	10
#define GPTB0_IRQ	11
#define RTC_IRQ		12
#define UART0_IRQ	13
#define UART1_IRQ	14
#define UART2_IRQ	15
#define USART_IRQ	16
#define GPTB1_IRQ	17
#define SIO_IRQ		18
#define I2C_IRQ		19	
#define SPI_IRQ		20	
#define EXI2_IRQ	21
#define EXI3_IRQ	22
#define EXI4_IRQ	23
#define CNTA_IRQ	24
#define TKEY_IRQ	25
#define LPT_IRQ		26
#define LED_IRQ		27
#define CMP_IRQ		28
#define BT0_IRQ		29
#define BT1_IRQ		30
#define LCD_IRQ		31

/***********************************************************************
 @brief  SYSCON General Control
***********************************************************************/
typedef enum
{
	ENDIS_ISOSC			=	 	(CSP_REGISTER_T)(0x01ul),
	ENDIS_IMOSC 		=		(CSP_REGISTER_T)(0x01ul<<1),
	ENDIS_ESOSC 		=		(CSP_REGISTER_T)(0x01ul<<2),
	ENDIS_EMOSC 		=		(CSP_REGISTER_T)(0x01ul<<3),
	ENDIS_HFOSC 		=		(CSP_REGISTER_T)(0x01ul<<4),
	ENDIS_IDLE_PCLK 	=		(CSP_REGISTER_T)(0x01ul<<8),
	ENDIS_SYSTICK 		=		(CSP_REGISTER_T)(0x01ul<<11)
}SYSCON_General_CMD_TypeDef;

/***********************************************************************
 @brief  Selected SYSCON CLK
***********************************************************************/
typedef enum
{
	SYSCLK_IMOSC	=		(CSP_REGISTER_T)0x0ul,				//IMOSC  selected
	SYSCLK_EMOSC	=		(CSP_REGISTER_T)0x1ul,				//EMOSC  selected
	SYSCLK_HFOSC	=		(CSP_REGISTER_T)0x2ul,				//HFOSC  selected
	SYSCLK_ISOSC 	=		(CSP_REGISTER_T)0x4ul,				//ISOSC	 selected
	SYSCLK_ESOSC	=		(CSP_REGISTER_T)0x5ul				//ESOSC	 selected
}SystemCLK_TypeDef;
/***********************************************************************
 @brief  SYSCON CLK Div
***********************************************************************/
typedef enum
{
	HCLK_DIV_1   =		(CSP_REGISTER_T)(0x1ul<<8),				
	HCLK_DIV_2   =		(CSP_REGISTER_T)(0x2ul<<8),
	HCLK_DIV_3   =		(CSP_REGISTER_T)(0x3ul<<8),
	HCLK_DIV_4   =		(CSP_REGISTER_T)(0x4ul<<8),
	HCLK_DIV_5   =		(CSP_REGISTER_T)(0x5ul<<8),
	HCLK_DIV_6   =		(CSP_REGISTER_T)(0x6ul<<8),
	HCLK_DIV_7   =		(CSP_REGISTER_T)(0x7ul<<8),
	HCLK_DIV_8   =		(CSP_REGISTER_T)(0x8ul<<8),
	HCLK_DIV_12  =		(CSP_REGISTER_T)(0x9ul<<8),
	HCLK_DIV_16  =		(CSP_REGISTER_T)(0xAul<<8),
	HCLK_DIV_24  =		(CSP_REGISTER_T)(0xBul<<8),
	HCLK_DIV_32  =		(CSP_REGISTER_T)(0xCul<<8),
	HCLK_DIV_64  =		(CSP_REGISTER_T)(0xDul<<8),
	HCLK_DIV_128 =		(CSP_REGISTER_T)(0xEul<<8),
	HCLK_DIV_256 =		(CSP_REGISTER_T)(0xFul<<8)
}SystemCLK_Div_TypeDef;

/***********************************************************************
 @brief  PCLK Div
***********************************************************************/
typedef enum
{
	PCLK_DIV_1   =		(CSP_REGISTER_T)(0x00ul<<8),				
	PCLK_DIV_2   =		(CSP_REGISTER_T)(0x01ul<<8),
	PCLK_DIV_4   =		(CSP_REGISTER_T)(0x02ul<<8),
	PCLK_DIV_8   =		(CSP_REGISTER_T)(0x04ul<<8),
	PCLK_DIV_16  =		(CSP_REGISTER_T)(0x08ul<<8)
}PCLK_Div_TypeDef;
  
/***********************************************************************
 @brief  LVD enable and disable
***********************************************************************/
typedef enum
{
	ENABLE_LVDEN		=		(CSP_REGISTER_T)0x00,			//Power down LVD module
	DISABLE_LVDEN		=		(CSP_REGISTER_T)0x0a			//Power down LVD module
}X_LVDEN_TypeDef;
/***********************************************************************
 @brief  LVDRST enable and disable
***********************************************************************/
typedef enum
{
	LVDRST_DIS		=		(CSP_REGISTER_T)(0x01<<4),			//Power down LVR module
	LVDRST_EN		=		(CSP_REGISTER_T)(0x00<<4)			//Power down LVR module
}LVDRST_CMD_TypeDef;

/***********************************************************************
 @brief  Detection voltage level to trigger the LVD interrupt
***********************************************************************/
typedef enum
{
	INTDET_LVL_2_1V		=	(CSP_REGISTER_T)(0X00ul<<8),					//2.1V	
	INTDET_LVL_2_4V		=	(CSP_REGISTER_T)(0X01ul<<8),					//2.4V
	INTDET_LVL_2_7V		=	(CSP_REGISTER_T)(0X02ul<<8),					//2.7V
	INTDET_LVL_3_0V		=	(CSP_REGISTER_T)(0X03ul<<8),					//3.0V
	INTDET_LVL_3_3V		=	(CSP_REGISTER_T)(0X04ul<<8),					//3.3V
	INTDET_LVL_3_6V		=	(CSP_REGISTER_T)(0X05ul<<8),					//3.6V
	INTDET_LVL_3_9V		=	(CSP_REGISTER_T)(0X06ul<<8),					//3.9V
}INTDET_LVL_X_TypeDef;

/***********************************************************************
 @brief  Detection voltage level to generate reset
***********************************************************************/
typedef enum
{
	RSTDET_LVL_1_9V		=		(CSP_REGISTER_T)(0X00ul<<12),			//1.9V
	RSTDET_LVL_2_2V		=		(CSP_REGISTER_T)(0X01ul<<12),			//2.2V
    RSTDET_LVL_2_5V		=		(CSP_REGISTER_T)(0X02ul<<12),			//2.5V
	RSTDET_LVL_2_8V		=		(CSP_REGISTER_T)(0X03ul<<12),			//2.8V
	RSTDET_LVL_3_1V		=		(CSP_REGISTER_T)(0X04ul<<12),			//3.1V
	RSTDET_LVL_3_4V		=		(CSP_REGISTER_T)(0X05ul<<12),			//3.4V
	RSTDET_LVL_3_7V		=		(CSP_REGISTER_T)(0X06ul<<12),			//3.7V
	RSTDET_LVL_4_0V		=		(CSP_REGISTER_T)(0X07ul<<12)			//4.0V
}RSTDET_LVL_X_TypeDef;

/***********************************************************************
 @brief  Detection voltage level to trigger the LVD interrupt
***********************************************************************/
typedef enum
{
	ENABLE_LVD_INT		=		(CSP_REGISTER_T)(0X01ul<<11),			//ENABLE LVD INT
	DISABLE_LVD_INT		=		(CSP_REGISTER_T)(0X00ul<<11)			//DISABLE LVD INT
}X_LVD_INT_TypeDef;

/***********************************************************************
 @brief  EXI PIN
***********************************************************************/
typedef enum
{
	EXI_PIN0		=		(CSP_REGISTER_T)(0X01ul),						
	EXI_PIN1		=		(CSP_REGISTER_T)(0X01ul<<1),
	EXI_PIN2		=		(CSP_REGISTER_T)(0X01ul<<2),
	EXI_PIN3		=		(CSP_REGISTER_T)(0X01ul<<3),
	EXI_PIN4		=		(CSP_REGISTER_T)(0X01ul<<4),
	EXI_PIN5		=		(CSP_REGISTER_T)(0X01ul<<5),
	EXI_PIN6		=		(CSP_REGISTER_T)(0X01ul<<6),
	EXI_PIN7		=		(CSP_REGISTER_T)(0X01ul<<7),
	EXI_PIN8		=		(CSP_REGISTER_T)(0X01ul<<8),
	EXI_PIN9		=		(CSP_REGISTER_T)(0X01ul<<9),
	EXI_PIN10		=		(CSP_REGISTER_T)(0X01ul<<10),
	EXI_PIN11		=		(CSP_REGISTER_T)(0X01ul<<11),
	EXI_PIN12		=		(CSP_REGISTER_T)(0X01ul<<12),
	EXI_PIN13		=		(CSP_REGISTER_T)(0X01ul<<13),
	EXI_PIN14		=		(CSP_REGISTER_T)(0X01ul<<14),
	EXI_PIN15		=		(CSP_REGISTER_T)(0X01ul<<15),
	EXI_PIN16		=		(CSP_REGISTER_T)(0X01ul<<16),
	EXI_PIN17		=		(CSP_REGISTER_T)(0X01ul<<17),
	EXI_PIN18		=		(CSP_REGISTER_T)(0X01ul<<18),
	EXI_PIN19		=		(CSP_REGISTER_T)(0X01ul<<19),
}SYSCON_EXIPIN_TypeDef;

/***********************************************************************
 @brief  EXT register
***********************************************************************/
typedef enum
{
	_EXIRT		=		0,
	_EXIFT		=		1,	
}EXI_tringer_mode_TypeDef;


/***********************************************************************
 @brief  SYSON IWDT TIME SET
***********************************************************************/
typedef enum
{
	IWDT_TIME_125MS		=	(CSP_REGISTER_T)(0x00ul<<8),						//IWDT_TIME      0x00fff			
	IWDT_TIME_250MS		=	(CSP_REGISTER_T)(0x01ul<<8),						//IWDT_TIME      0x01fff
	IWDT_TIME_500MS		=	(CSP_REGISTER_T)(0x02ul<<8),						//IWDT_TIME      0x03fff	
	IWDT_TIME_1S		=	(CSP_REGISTER_T)(0x03ul<<8),						//IWDT_TIME      0x07fff
	IWDT_TIME_2S		=	(CSP_REGISTER_T)(0x04ul<<8),						//IWDT_TIME      0x0ffff			//2M ISOSC  2sec
	IWDT_TIME_3S		=	(CSP_REGISTER_T)(0x05ul<<8),						//IWDT_TIME      0x16fff
	IWDT_TIME_4S		=	(CSP_REGISTER_T)(0x06ul<<8),						//IWDT_TIME      0x1ffff
	IWDT_TIME_8S		=	(CSP_REGISTER_T)(0x07ul<<8)							//IWDT_TIME      0x3ffff
}IWDT_TIME_TypeDef;  

/***********************************************************************
 @brief  SYSON IWDT TIME DIV SET
***********************************************************************/
typedef enum
{
	IWDT_INTW_DIV_1		=	(0x00ul<<2),						//1/8 of IWDT_TIME
	IWDT_INTW_DIV_2		=	(0x01ul<<2),						//2/8 of IWDT_TIME	
	IWDT_INTW_DIV_3		=	(0x02ul<<2),						//3/8 of IWDT_TIME
	IWDT_INTW_DIV_4		=	(0x03ul<<2),						//4/8 of IWDT_TIME
	IWDT_INTW_DIV_5		=	(0x04ul<<2),						//5/8 of IWDT_TIME
	IWDT_INTW_DIV_6		=	(0x05ul<<2),						//6/8 of IWDT_TIME
	IWDT_INTW_DIV_7		=	(0x06ul<<2)							//7/8 of IWDT_TIME
}IWDT_TIMEDIV_TypeDef;

/***********************************************************************
 @brief  IMOSC SELECTE SET
***********************************************************************/
typedef enum
{
	IMOSC_SELECTE_5556K	=	(0x00ul<<0),
	IMOSC_SELECTE_4194K	=	(0x01ul<<0),
	IMOSC_SELECTE_2097K	=	(0x02ul<<0),
	IMOSC_SELECTE_131K	=	(0x03ul<<0)
}IMOSC_SELECTE_TypeDef;

/***********************************************************************
 @brief  HFOSC SELECTE SET
***********************************************************************/
typedef enum
{
	HFOSC_SELECTE_48M	=	(0x0ul<<4),
	HFOSC_SELECTE_24M	=	(0x1ul<<4),
	HFOSC_SELECTE_12M	=	(0x2ul<<4),
	HFOSC_SELECTE_6M	=	(0x3ul<<4)
}HFOSC_SELECTE_TypeDef;

/***********************************************************************
 @brief  EM Filter set
***********************************************************************/
typedef enum
{
	EM_FLSEL_5ns	=	(0x0ul<<26),
	EM_FLSEL_10ns	=	(0x1ul<<26),
	EM_FLSEL_15ns	=	(0x2ul<<26),
	EM_FLSEL_20ns	=	(0x3ul<<26)
}EM_Filter_TypeDef;
/***********************************************************************
 @brief  EM Filter CMD
***********************************************************************/
typedef enum
{
	EM_FLEN_DIS	=	(0x0ul<<25),
	EM_FLEN_EN	=	(0x1ul<<25)
}EM_Filter_CMD_TypeDef;
/***********************************************************************
 @brief  ES SMT CMD
***********************************************************************/
typedef enum
{
	EM_SMT_DIS	=	(0x1ul<<24),
	EM_SMT_EN	=	(0x0ul<<24)
}EM_SMT_CMD_TypeDef;
/***********************************************************************
 @brief  EM LFSEL BIT
***********************************************************************/
typedef enum
{
	EM_LFSEL_DIS	=	(0x0ul<<10),
	EM_LFSEL_EN		=	(0x1ul<<10)
}EM_LFSEL_TypeDef;
/***********************************************************************
 @brief  EM Systemclk data
***********************************************************************/
typedef enum
{
	EMOSC_24M		=	0,
	EMOSC_16M		=	1,
	EMOSC_12M		=	2,
	EMOSC_8M		=	3,
	EMOSC_4M		=	4,
	EMOSC_36K		=	5,
	IMOSC			=	6,
	ISOSC			=	7,
	HFOSC_48M		=	8,
	HFOSC_24M		=	9,
	HFOSC_12M		=	10,
	HFOSC_6M		=	11,
	ESOSC_32K		=	12
}SystemClk_data_TypeDef;
/***********************************************************************
 @brief  CLO IO Selecte
***********************************************************************/
typedef enum
{
	CLO_PC00		=	0,						//PC0.0 as clo
	CLO_PA05		=	1,						//PA0.5 as clo
	CLO_PB00		=	2,						//PB0.0 as clo
	CLO_PA13		=	3						//PA1.3 as clo
}CLO_IO_TypeDef;

/***********************************************************************
 @brief  POL edge
***********************************************************************/
typedef enum
{
	INTDET_POL_fall				=	(1<<6),						//fall Trigger
	INTDET_POL_X_rise			=	(2<<6),						//rise Trigger
	INTDET_POL_X_riseORfall		=	(3<<6),						//fall or rise Trigger
}INTDET_POL_X_TypeDef;

/***********************************************************************
 @brief  IOMAP DIR
***********************************************************************/
typedef enum
{
	//IOMAP0
	G1_I2C_SCL				=	0X00,						//
	G1_I2C_SDA				=	0X01,						//
	G1_USART0_TX			=	0X02,						//
	G1_USART0_RX			=	0X03,						//
	G1_SPI_NSS				=	0X04,						//
	G1_SPI_SCK				=	0X05,						//
	G1_SPI_MISO				=	0X06,						//
	G1_SPI_MOSI				=	0X07,						//
	//IOMAP1
	G2_USART0_TX			=	0X10,						//
	G2_USART0_RX			=	0X11,						//
	G2_USART0_SCK			=	0X12,						//
	G2_UART_TX				=	0X13,						//
	G2_UART_RX				=	0X14,						//
	G2_GPTA0_CHA			=	0X15,						//
	G2_GPTA1_CHA			=	0X16,						//
	G2_CMP_OUT				=	0X17,						//
}IOMAP_DIR_TypeDef;
/***********************************************************************
 @brief  IOMAP
***********************************************************************/
typedef enum
{
	PA014_G10				=	0,
	PA015_G11				=	1,
	PB03_G12				=	2,
	PC01_G13				=	3,
	PB04_G14				=	4,
	PA10_G15				=	5,
	PA11_G16				=	6,
	PA12_G17				=	7,
	
	PA00_G20				=	10,
	PA01_G21				=	11,
	PA02_G22				=	12,
	PA03_G23				=	13,
	PA04_G24				=	14,
	PA05_G25				=	15,
	PB06_G26				=	16,
	PB07_G27				=	17
}IOMAP_TypeDef;
/***********************************************************************
 @brief  CLOMX Systemclk data
***********************************************************************/
typedef enum
{
	CLO_ISCLK		=	0,
	CLO_IMCLK		=	1,
	CLO_EMCLK		=	3,
	CLO_HFCLK		=	4,
	CLO_RTCCLK		=	6,
	CLO_PCLK		=	7,
	CLO_HCLK		=	8,
	CLO_IWDTCLK		=	9,
	CLO_SYSCLK		=	0X0D,
}SystemClk_CLOMX_TypeDef;

/***********************************************************************
@brief  CLOMX Systemclk data
***********************************************************************/
typedef enum
{
	CLO_DIV0			=	1,
	CLO_DIV4			=	0,
	CLO_DIV2			=	2,
	CLO_DIV8			=	4,
	CLO_DIV16		    =	5,
}SystemClk_CLODIV_TypeDef;

/*********************************************************************** 
 @brief  SYSCON extern functions                  
***********************************************************************/ 	
extern void SYSCON_RST_VALUE(void); 
extern void SYSCON_General_CMD(FunctionalStatus NewState, SYSCON_General_CMD_TypeDef ENDIS_X );
extern void EMOSC_OSTR_Config(U16_T EM_CNT, U8_T EM_GM,EM_LFSEL_TypeDef EM_LFSEL_X, EM_Filter_CMD_TypeDef EM_FLEN_X, EM_Filter_TypeDef EM_FLSEL_X);
extern void ESOSC_OSTR_Config(U8_T ES_CNT, U8_T ES_GM, EM_SMT_CMD_TypeDef EM_SMT_CMD);
extern void SystemCLK_HCLKDIV_PCLKDIV_Config(SystemCLK_TypeDef SYSCLK_X , SystemCLK_Div_TypeDef HCLK_DIV_X , PCLK_Div_TypeDef PCLK_DIV_X , SystemClk_data_TypeDef SystemClk_data_x );
extern void SYSCON_WDT_CMD(FunctionalStatus NewState);
extern void SYSCON_IWDCNT_Reload(void);
extern void SYSCON_IWDCNT_Config(IWDT_TIME_TypeDef IWDT_TIME_X , IWDT_TIMEDIV_TypeDef IWDT_INTW_DIV_X );
extern void SYSCON_LVD_Config(X_LVDEN_TypeDef X_LVDEN ,LVDRST_CMD_TypeDef LVDRST_CMD , INTDET_LVL_X_TypeDef INTDET_LVL_X , RSTDET_LVL_X_TypeDef RSTDET_LVL_X , INTDET_POL_X_TypeDef INTDET_POL_X);
extern void EXTI_interrupt_CMD(FunctionalStatus NewState , SYSCON_EXIPIN_TypeDef  EXIPIN);
extern void SYSCON_CLO_CONFIG(CLO_IO_TypeDef clo_io);
extern U32_T SYSCON_Read_CINF0(void);
extern U32_T SYSCON_Read_CINF1(void);
extern void org_address_in_prg(void);
extern void org_address_out_prg(void);
extern void SYSCON_INT_Priority(void);
extern void EXI0_Int_Enable(void);
extern void EXI0_Int_Disable(void);
extern void EXI1_Int_Enable(void);
extern void EXI1_Int_Disable(void);
extern void EXI2_Int_Enable(void);
extern void EXI2_Int_Disable(void);
extern void EXI3_Int_Enable(void);
extern void EXI3_Int_Disable(void);
extern void EXI4_Int_Enable(void);
extern void EXI4_Int_Disable(void);
extern void SYSCON_Int_Enable(void);
extern void SYSCON_Int_Disable(void);
extern void PCLK_goto_idle_mode(void);
extern void PCLK_goto_deepsleep_mode(void);
extern void PCLK_goto_Snooze_mode(U8_T snooze_power_set);
extern void PCLK_goto_Shutdown_mode(void);
extern void LVD_Int_Enable(void);
extern void LVD_Int_Disable(void);
extern void IWDT_Int_Enable(void);
extern void IWDT_Int_Disable(void);
extern void EXI0_WakeUp_Enable(void);
extern void EXI0_WakeUp_Disable(void);
extern void EXI1_WakeUp_Enable(void);
extern void EXI1_WakeUp_Disable(void);
extern void EXI2_WakeUp_Enable(void);
extern void EXI2_WakeUp_Disable(void);
extern void EXI3_WakeUp_Enable(void);
extern void EXI3_WakeUp_Disable(void);
extern void EXI4_WakeUp_Enable(void);
extern void EXI4_WakeUp_Disable(void);
extern void SYSCON_WakeUp_Enable(void);
extern void SYSCON_WakeUp_Disable(void);
extern void GPIO_EXTI_interrupt(CSP_GPIO_T * GPIOX,U32_T GPIO_IECR_VALUE);   
extern void SYSCON_Software_Reset(void);   
extern void SYSCON_HFOSC_SELECTE(HFOSC_SELECTE_TypeDef HFOSC_SELECTE_X);
extern void SYSCON_IMOSC_SELECTE(IMOSC_SELECTE_TypeDef IMOSC_SELECTE_X);
extern void SystemCLK_Clear(void);
extern void GPIO_Remap(IOMAP_TypeDef IOMAP_NUM,IOMAP_DIR_TypeDef iomap_data);
extern void SYSCON_CLO_SRC_SET(SystemClk_CLOMX_TypeDef clomxr,SystemClk_CLODIV_TypeDef clodivr);
extern void Set_INT_Priority(U8_T int_name,U8_T int_level);
extern void Debug_IO_lock(void);
extern void Debug_IO_release(void);
extern void EXTI_trigger_CMD(FunctionalStatus NewState , SYSCON_EXIPIN_TypeDef  EXIPIN , EXI_tringer_mode_TypeDef EXI_tringer_mode);

#endif   // apt32f110_syscon_H */

/*********************************************************************** 
//				(C) COPYRIGHT 2022 APT Chip 
//						 END OF FILE         
***********************************************************************/