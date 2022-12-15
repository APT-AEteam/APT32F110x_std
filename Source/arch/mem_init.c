/*
  ******************************************************************************
  * @file    mem_init.c
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
#include "string.h"

/* externs function-------------------------------------------------------------------*/
extern char _end_rodata[];
extern char _start_data[];
extern char _end_data[];
extern char _start_sram1_define[];
extern char _end_sram1_define[];
extern char _bss_start[];
extern char _ebss[];


void __main( void ) 
{

  char *dst = _start_data;
  char *src = _end_rodata;

/*********************************************************************** 
 if the start of data (dst)
 is not equal to end of text (src) then
 copy it, else it's already in the right place                
***********************************************************************/ 

  if( _start_data != _end_rodata ) {
	//__memcpy_fast( dst, src, (_end_data - _start_data));
    //memcpy( dst, src, (_end_data - _start_data));
	memcpy( dst, src, (_end_data - _start_data));
	if(!(((*(unsigned int *)0x40011090)&0X4000)||((*(unsigned int *)0x40011090)&0X0008)))
	{
		memcpy( _start_sram1_define, src + ((_end_data - _start_data)) ,(_end_sram1_define -_start_sram1_define));
	}
  }

/*********************************************************************** 
zero the bss         
***********************************************************************/ 
  if( _ebss - _bss_start ) {
	//__memset_fast( _bss_start, 0x00, ( _ebss - _bss_start ));
    memset( _bss_start, 0x00, ( _ebss - _bss_start ));
  }

	
}



/*********************************************************************** 
//				(C) COPYRIGHT 2022 APT Chip 
//						 END OF FILE         
***********************************************************************/

