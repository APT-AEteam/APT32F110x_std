/*
  ******************************************************************************
  * @file    apt32f110_CORET.c
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2022/01/02
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
#include "apt32f110x_coret.h"
#include "apt32f110x_syscon.h"


/*************************************************************/
//Deinitializes the syscon registers to their default reset
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/    
void CORET_DeInit(void)
{
	CK802->CORET_CSR=CORET_CSR_RST;
	CK802->CORET_RVR=CORET_RVR_RST;
	CK802->CORET_CVR=CORET_CVR_RST;
	CK802->CORET_CALIB=CORET_CALIB_RST;
}

/*************************************************************/
//CORET Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CORET_Int_Enable(void)
{
    CK802->CORET_CVR = 0x0;							// Clear counter and flag
	INTC_ISER_WRITE(CORET_INT);    
}

/*************************************************************/
//CORET Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CORET_Int_Disable(void)
{
    INTC_ICER_WRITE(CORET_INT);    
}

/*************************************************************/
// CORET Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void  CORET_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(CORET_INT);    
}

/*************************************************************/
// CORET Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void  CORET_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(CORET_INT);    
}

/*************************************************************/
// CORET START
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CORET_start(void)
{
	CK802->CORET_CSR|=0x01;
}
/*************************************************************/
// CORET stop
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CORET_stop(void)
{
	CK802->CORET_CSR&=0Xfffffffe;
}
/*************************************************************/
// CORET CLKSOURC EX
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CORET_CLKSOURCE_EX(void)
{
	CK802->CORET_CSR&=0Xfffffffb;
}
/*************************************************************/
// CORET CLKSOURC IN
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CORET_CLKSOURCE_IN(void)
{
	CK802->CORET_CSR|=0x04;
}
/*************************************************************/
//CORET TICKINT enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CORET_TICKINT_Enable(void)
{
    CK802->CORET_CSR|=0x02;
}

/*************************************************************/
//CORET TICKINT enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CORET_TICKINT_Disable(void)
{
   CK802->CORET_CSR&=0Xfffffffd;
}

/*************************************************************/
// CORET reload
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CORET_reload(void)
{
	CK802->CORET_CVR = 0x0;							// Clear counter and flag
}




/*********************************************************************** 
//						 END OF FILE         
***********************************************************************/