/*******************************************************************************
  * @file：   APT32F110x_TKLib_Version
  * @author：  APT SZ AE Team
  * @description：This file is used to record the version update of touch library file, 
				  the latest version may fix the bugs existing in the old version, 
				  or add new features, please update in time
  ******************************************************************************/
#V1_00:初版
//lib_110tkey_F_1_00：跳频版本，Touch使用中断处理，占用更多的SRAM及程序空间，抗干扰能力最强
//lib_110tkey_C_1_00：默认版本，Touch使用中断处理，SRAM及程序占用空间更小，速度更快，抗干扰性能稍低
#V1_02:
//去耦版本，*a文件兼容std和csi库
//lib_110tkey_F_1_02：跳频版本，Touch使用中断处理，占用更多的SRAM及程序空间，抗干扰能力最强；占用coret并使能中断
//lib_110tkey_C_1_02：默认版本，Touch使用中断处理，SRAM及程序占用空间更小，速度更快，抗干扰性能稍低；占用coret并使能中断
//lib_110tkey_MC_1_02：主循环版本，使用Touch需要调用tkey_main_prog();函数，扫描时间更长，完全不占用中断，按键越多扫描时间越长，按键速度也会越慢；
//lib_110tkey_DMA_1_02：TOUCH->DMA版本，使用DMA模块传递touch采样数据，扫描不使用touch中断，速度最快，占用最多的SRAM，使用此版本后不再允许配置DMA3；占用coret并使能中断
#V1_03:
//lib_110tkey_C_1_03 库增加低功耗唤醒模式
//对跳频版本修改了负向更新的机制，避免了在单一通道持续受影响时，可能出现的连续按键造成按键释放缓慢的问题
//增加了隐藏配置
//修改了最大按键个数配置值需要比实际使用值+1的问题