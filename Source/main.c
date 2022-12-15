/*
  ******************************************************************************
  * @file    main.c
  * @author  APT SZ AE Team
  * @version V1.03
  * @date    2022/10/08
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
#include "apt32f110x_cmp.h"
#include "apt32f110x_dma.h"
#include "apt32f110x_types_local.h"
#include "math.h"
#include "tkey.h"

/****************************************************
//extern
*****************************************************/
extern void delay_nms(unsigned int t);
extern void APT32F110x_init(void);

/****************************************************
//define
*****************************************************/


/***************************************************/
//main
/**************************************************/
int main(void) 
{
	delay_nms(1000);						
	APT32F110x_init();
    while(1)
	{
		SYSCON_IWDCNT_Reload();
		//....
		//....
	}

}
