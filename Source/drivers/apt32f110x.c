/*
  ******************************************************************************
  * @file    apt32f110.c
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

/*Includes -----------------------------------------------------------*/
#include "apt32f110x.h"
/***********************************************************************
@brief Struct pointer assignment Functions
***********************************************************************/
CSP_CK802_T   	*CK802 = (CSP_CK802_T   *)CK802_ADDR_BASE ;
CSP_IFC_T   	*IFC     = (CSP_IFC_T    *)APB_IFC_BASE ;
CSP_SYSCON_T 	*SYSCON = (CSP_SYSCON_T *)APB_SYS_BASE ;
CSP_TKEY_T  	*TKEY    = (CSP_TKEY_T  *)APB_TKEY_BASE ;
CSP_TKEY1_T  	*TKEY1    = (CSP_TKEY1_T  *)APB_TKEY1_BASE ;
CSP_TKEY2_T  	*TKEY2    = (CSP_TKEY2_T  *)APB_TKEY2_BASE ;
CSP_ADC12_T 	*ADC0    = (CSP_ADC12_T  *)APB_ADC0_BASE ;
CSP_ADC12_TEMP_T *ADC0_TEMP =(CSP_ADC12_TEMP_T  *)AHB_ADC_TEMP_BASE;
CSP_GPIO_T  	*GPIOA0   = (CSP_GPIO_T  *)APB_GPIOA0_BASE ;
CSP_GPIO_T  	*GPIOA1   = (CSP_GPIO_T  *)APB_GPIOA1_BASE ;
CSP_GPIO_T  	*GPIOB0   = (CSP_GPIO_T  *)APB_GPIOB0_BASE ;
CSP_GPIO_T  	*GPIOC0   = (CSP_GPIO_T  *)APB_GPIOC0_BASE ;
CSP_IGRP_T  	*GPIOGRP  = (CSP_IGRP_T *)APB_IGRP_BASE;
CSP_UART_T  	*UART0    = (CSP_UART_T  *)APB_UART0_BASE ;
CSP_UART_T  	*UART1    = (CSP_UART_T  *)APB_UART1_BASE ;
CSP_UART_T  	*UART2    = (CSP_UART_T  *)APB_UART2_BASE ;
CSP_USART_T  	*USART0    = (CSP_USART_T  *)APB_USART0_BASE ;
CSP_SSP_T   	*SPI0     = (CSP_SSP_T   *)APB_SPI0_BASE ;
CSP_I2C_T   	*I2C0     = (CSP_I2C_T   *)APB_I2C0_BASE ;
CSP_SIO_T   	*SIO0     = (CSP_SIO_T   *)APB_SIO0_BASE ;
CSP_CA_T    	*CA0      = (CSP_CA_T    *)APB_CNTA_BASE ;
CSP_GPTX_T		*GPTA0	  =	(CSP_GPTX_T *)APB_GPTA0_BASE;
CSP_GPTX_T		*GPTA1	  =	(CSP_GPTX_T *)APB_GPTA1_BASE;
CSP_GPTX_T		*GPTB0	  =	(CSP_GPTX_T *)APB_GPTB0_BASE;
CSP_GPTX_T		*GPTB1	  =	(CSP_GPTX_T *)APB_GPTB1_BASE;
CSP_EPT_T   	*EPT0     = (CSP_EPT_T  *)APB_EPT0_BASE ;
CSP_ETCB_T  	*ETCB     = (CSP_ETCB_T *)APB_ETCB_BASE ;
CSP_RTC_T   	*RTC      = (CSP_RTC_T  *)APB_RTC_BASE ;
CSP_LPT_T   	*LPT      = (CSP_LPT_T  *)APB_LPT_BASE ;
CSP_WWDT_T   	*WWDT      = (CSP_WWDT_T  *)APB_WWDT_BASE ;
CSP_BT_T    	*BT0      = (CSP_BT_T   *)APB_BT0_BASE ;
CSP_BT_T    	*BT1      = (CSP_BT_T   *)APB_BT1_BASE ;
CSP_CRC_T   	*CRC      = (CSP_CRC_T  *)AHB_CRC_BASE ;
CSP_HWD_T   	*HWD      = (CSP_HWD_T  *)AHB_HWD_BASE ;
CSP_LCD_T   	*LCD     = (CSP_LCD_T   *)APB_LCD0_BASE;
CSP_LED_T   	*LED0     = (CSP_LED_T   *)APB_LED0_BASE;
CSP_CMP_T   	*CMP0     = (CSP_CMP_T   *)APB_CMP0_BASE;
CSP_CMP_T   	*CMP1     = (CSP_CMP_T   *)APB_CMP1_BASE;
CSP_DMA_T		*DMA		= (CSP_DMA_T *)(AHB_DMA_BASE);
CSP_DMA_T 		*DMA0     	= (CSP_DMA_T *)(APB_DMA0_BASE);
CSP_DMA_T 		*DMA1     	= (CSP_DMA_T *)(APB_DMA1_BASE);
CSP_DMA_T 		*DMA2     	= (CSP_DMA_T *)(APB_DMA2_BASE);
CSP_DMA_T 		*DMA3     	= (CSP_DMA_T *)(APB_DMA3_BASE);

/***********************************************************************
@brief div Functions
***********************************************************************/
int __divsi3 (  int a,   int b)
{   
	int PSR;
	__asm volatile(
					"mfcr %0 , psr \n\r"
					"psrclr ie \n\r"
					: "=r"(PSR)
				   );

	HWD->CR = 0;
	HWD->DIVIDENT = a;
	HWD->DIVISOR = b;

	PSR |= 0x80000000;
	__asm volatile(
					 "mtcr %0 , psr \n\r"
					 : 
					 :"r"(PSR)
					);
					
	return HWD->QUOTIENT;
}
unsigned int __udivsi3 ( unsigned int a,  unsigned int b)
{   
	int PSR;
	__asm volatile(
					"mfcr %0 , psr \n\r"
					"psrclr ie \n\r"
					: "=r"(PSR)
				   );
	
	HWD->CR = 1;
	HWD->DIVIDENT = a;
	HWD->DIVISOR = b;

	PSR |= 0x80000000;
	__asm volatile(
					 "mtcr %0 , psr \n\r"
					 : 
					 :"r"(PSR)
					);

	return HWD->QUOTIENT;
}

int __modsi3 ( int a,  int b)
{   
	int PSR;
	__asm volatile(
					"mfcr %0 , psr \n\r"
					"psrclr ie \n\r"
					: "=r"(PSR)
				   );
	
	HWD->CR = 0;
	HWD->DIVIDENT = a;
	HWD->DIVISOR = b;

	PSR |= 0x80000000;
	__asm volatile(
					 "mtcr %0 , psr \n\r"
					 : 
					 :"r"(PSR)
					);	
	return HWD->REMAIN;
}

unsigned int __umodsi3 ( unsigned int a,  unsigned int b)
{   
	int PSR;
	__asm volatile(
					"mfcr %0 , psr \n\r"
					"psrclr ie \n\r"
					: "=r"(PSR)
				   );
	
	HWD->CR = 1;
	HWD->DIVIDENT = a;
	HWD->DIVISOR = b;

	PSR |= 0x80000000;
	__asm volatile(
					 "mtcr %0 , psr \n\r"
					 : 
					 :"r"(PSR)
					);	
	return HWD->REMAIN;
}



/*********************************************************************** 
//				(C) COPYRIGHT 2022 APT Chip 
//						 END OF FILE         
***********************************************************************/ 