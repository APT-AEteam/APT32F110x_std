
/*
  ******************************************************************************
  * @file    apt32f110x_tkey_parameter.c
  * @author  APT AE Team
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

#include "tkey.h"



void csi_tkey_parameter_init(void)
{
/****************************************************
//TK basic parameters
*****************************************************/
	dwTkeyIoEnable=TCH_EN(0)|TCH_EN(1)|TCH_EN(2)|TCH_EN(3)|TCH_EN(4)|TCH_EN(5)|TCH_EN(6)|TCH_EN(7)|             //TCH_EN(10)swdio TCH_EN(13)swclk  
				   TCH_EN(11)|TCH_EN(12)|TCH_EN(14)|TCH_EN(15)|TCH_EN(16)|TCH_EN(17)|TCH_EN(18)|TCH_EN(19)|
				   TCH_EN(20)|TCH_EN(21)|TCH_EN(22)|TCH_EN(23)|TCH_EN(25)|TCH_EN(26)|TCH_EN(27)|TCH_EN(28);     //TCH_EN(24)fvr  

	byTkeyGlobalSens=1;								//TK Global Tkey Sensitivity,0=invalid;
	hwTkeyGlobalTrigger=50;							//TK Global Tkey Trigger,0=invalid;
	byTkeyGlobalIcon=3;								//TK Global Tkey Icon,0=invalid;
	byPressDebounce=3;								//Press debounce 1~10
	byReleaseDebounce=3;							//Release debounce 1~10
	byKeyMode=1;									//Key mode 0=first singlekey,1=multi key,2=strongest single-key
	byMultiTimesFilter=0;							//MultiTimes Filter,>4 ENABLE <4 DISABLE
	byValidKeyNum=4;								//Valid Key number when touched
	byBaseUpdateSpeed=10;							//baseline update speed
	byTkeyRebuildTime=16;							//longpress rebuild time = byTkeyRebuildTime*1s  0=disable
	hwTkeyBaseCnt=59999;							//10ms  byTkeyBaseCnt=10ms*48M/8-1,this register need to modify when mcu's Freq changed
/****************************************************
//TK parameter fine-tuning
*****************************************************/
	byTkeyFineTurn=DISABLE;							//Tkey sensitivity fine tuning ENABLE/DISABLE
	byTkeyChxSens[0]=2;								//TCHx manual Sensitivity
	byTkeyChxSens[1]=2;								//TCHx manual Sensitivity
	byTkeyChxIcon[0]=5;								//TCHx manual ICON
	byTkeyChxIcon[1]=5;								//TCHx manual ICON
/****************************************************
//TK special parameter define
*****************************************************/
	hwTkeyPselMode=TK_PWRSRC_AVDD;					//tk power sel:TK_PWRSRC_FVR/TK_PWRSRC_AVDD   when select TK_PSEL_FVR PA0.0(TCH24) need a 104 cap
	hwTkeyEcLevel=TK_ECLVL_1V;						//C0 voltage sel:TK_ECLVL_1V/TK_ECLVL_2V/TK_ECLVL_3V/TK_ECLVL_3V6
	hwTkeyFvrLevel=TK_FVR_4096V;					//FVR level:TK_FVR_2048V/TK_FVR_4096V/TK_FVR_NONE
/****************************************************
//TK low power function define
*****************************************************/
	byTkeyLowPowerMode=ENABLE;						//touch key can goto sleep when TK lowpower mode enable
	byTkeyLowPowerLevel=5;							//0=none 1=16ms 2=32ms 3=64ms 4=128ms,>4=186ms Scan interval when sleep
	byTkeyWakeupLevel=2;							//0~7;The larger the value the higher the wakeup threshold
	dwTkeyWakeupIoEnable=TCH_EN(1);					//Sleep wakeup TCHx configuration, Currently only one channel is supported
/****************************************************
//TK Hidden function define
*****************************************************/
	//byTkeyDstStatus=1;							
	//byTkeyIntrStatus=1;							
	//byTkeyImtvtimTime=1;
	//byTkeyNegBuildBounce=10;						
	//byTkeyPosBuildBounce=10;						
}





