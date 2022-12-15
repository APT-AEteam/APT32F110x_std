/*
  ******************************************************************************
  * @file    apt32f110_CORET.h
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2022/02/21
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
  
#ifndef _apt32f110_CORET_H
#define _apt32f110_CORET_H

/****************************************************
//include
*****************************************************/ 
#include "apt32f110x.h"

/*********************************************************************** 
 @brief  syscon Registers Definition                  
***********************************************************************/ 
#define CORET_CSR_RST     	((CSP_REGISTER_T)0x00000004)
#define CORET_RVR_RST     	((CSP_REGISTER_T)0x00000000)
#define CORET_CVR_RST     	((CSP_REGISTER_T)0x00000000)
#define CORET_CALIB_RST     ((CSP_REGISTER_T)0x00000000)



/*********************************************************************** 
 @brief  CORET extern functions                  
***********************************************************************/ 
extern void CORET_DeInit(void);
extern void CORET_Int_Enable(void);
extern void CORET_Int_Disable(void);
extern void CORET_WakeUp_Enable(void);
extern void CORET_WakeUp_Disable(void);
extern void CORET_start(void);
extern void CORET_stop(void);
extern void CORET_CLKSOURCE_EX(void);
extern void CORET_CLKSOURCE_IN(void);
extern void CORET_TICKINT_Enable(void);
extern void CORET_TICKINT_Disable(void);
extern void CORET_reload(void);

#endif   // apt32f110_coret_H */

/*********************************************************************** 
//				(C) COPYRIGHT 2022 APT Chip 
//						 END OF FILE         
***********************************************************************/