##
## Auto Generated makefile by CDK
## Do not modify this file, and any manual changes will be erased!!!   
##
## BuildSet
ProjectName            :=110test
ConfigurationName      :=BuildSet
WorkspacePath          :=../
ProjectPath            :=./
IntermediateDirectory  :=Obj
OutDir                 :=$(IntermediateDirectory)
User                   :=clutc
Date                   :=24/08/2022
CDKPath                :=F:/C-Sky/CDK
LinkerName             :=csky-elfabiv2-gcc
LinkerNameoption       :=
SIZE                   :=csky-elfabiv2-size
READELF                :=csky-elfabiv2-readelf
CHECKSUM               :=crc32
SharedObjectLinkerName :=
ObjectSuffix           :=.o
DependSuffix           :=.d
PreprocessSuffix       :=.i
DisassemSuffix         :=.asm
IHexSuffix             :=.ihex
BinSuffix              :=.bin
ExeSuffix              :=.elf
LibSuffix              :=.a
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
ElfInfoSwitch          :=-hlS
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
UnPreprocessorSwitch   :=-U
SourceSwitch           :=-c 
ObjdumpSwitch          :=-S
ObjcopySwitch          :=-O ihex
ObjcopyBinSwitch       :=-O binary
OutputFile             :=APT32F110_FlashTest_P0000_1FFF
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=110test.txt
MakeDirCommand         :=mkdir
LinkOptions            := -mcpu=ck802  -nostartfiles -Wl,--gc-sections -T"$(ProjectPath)/ckcpu.ld"
LinkOtherFlagsOption   :=
IncludePackagePath     :=
IncludeCPath           := $(IncludeSwitch)F:/C-Sky/CDK/CSKY/csi/csi_core/csi_cdk/ $(IncludeSwitch)F:/C-Sky/CDK/CSKY/csi/csi_core/include/ $(IncludeSwitch)F:/C-Sky/CDK/CSKY/csi/csi_driver/include/ $(IncludeSwitch). $(IncludeSwitch)include  
IncludeAPath           := $(IncludeSwitch)F:/C-Sky/CDK/CSKY/csi/csi_core/csi_cdk/ $(IncludeSwitch)F:/C-Sky/CDK/CSKY/csi/csi_core/include/ $(IncludeSwitch)F:/C-Sky/CDK/CSKY/csi/csi_driver/include/ $(IncludeSwitch). $(IncludeSwitch)include  
Libs                   := -Wl,--start-group  -Wl,--end-group  
ArLibs                 := 
PackagesLibPath        :=
LibPath                := $(PackagesLibPath) 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       :=csky-elfabiv2-ar rcu
CXX      :=csky-elfabiv2-g++
CC       :=csky-elfabiv2-gcc
AS       :=csky-elfabiv2-gcc
OBJDUMP  :=csky-elfabiv2-objdump
OBJCOPY  :=csky-elfabiv2-objcopy
CXXFLAGS := -mcpu=ck802   $(PreprocessorSwitch)CONFIG_CSKY_MMU=0   $(UnPreprocessorSwitch)__CSKY_ABIV2__  -Os  -g  -Wall -mistack 
CFLAGS   := -mcpu=ck802   $(PreprocessorSwitch)CONFIG_CSKY_MMU=0   $(UnPreprocessorSwitch)__CSKY_ABIV2__  -Os  -g  -Wall -mistack 
ASFLAGS  := -mcpu=ck802   $(PreprocessorSwitch)CONFIG_CKCPU_MMU=0   $(UnPreprocessorSwitch)__CSKY_ABIV2__  -Wa,--gdwarf2    


Objects0=$(IntermediateDirectory)/arch_apt32f110_iostring$(ObjectSuffix) $(IntermediateDirectory)/arch_crt0$(ObjectSuffix) $(IntermediateDirectory)/arch_mem_init$(ObjectSuffix) $(IntermediateDirectory)/drivers_apt32f110x$(ObjectSuffix) $(IntermediateDirectory)/drivers_apt32f110x_ck802$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_adc$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_bt$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_cmp$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_coret$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_countera$(ObjectSuffix) \
	$(IntermediateDirectory)/FWlib_apt32f110x_crc$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_dma$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_ept$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_gpio$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_gpt$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_i2c$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_ifc$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_lcd$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_led$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_lpt$(ObjectSuffix) \
	$(IntermediateDirectory)/FWlib_apt32f110x_rtc$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_sio$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_spi$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_syscon$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_tkey_c_v01$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_tkey_f_v01$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_tkey_mc_v01$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_tkey_parameter$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_uart$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_usart$(ObjectSuffix) \
	$(IntermediateDirectory)/FWlib_apt32f110x_wwdt$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f110x_etcb$(ObjectSuffix) $(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/apt32f110x_initial$(ObjectSuffix) $(IntermediateDirectory)/apt32f110x_interrupt$(ObjectSuffix) $(IntermediateDirectory)/__rt_entry$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all
all: $(IntermediateDirectory)/$(OutputFile)

$(IntermediateDirectory)/$(OutputFile):  $(Objects) Always_Link 
	$(LinkerName) $(OutputSwitch) $(IntermediateDirectory)/$(OutputFile)$(ExeSuffix) $(LinkerNameoption) $(LinkOtherFlagsOption)  -Wl,--ckmap=$(ProjectPath)/Lst/$(OutputFile).map  @$(ObjectsFileList)  $(LinkOptions) $(LibPath) $(Libs)
	@mv $(ProjectPath)/Lst/$(OutputFile).map $(ProjectPath)/Lst/$(OutputFile).temp && $(READELF) $(ElfInfoSwitch) $(ProjectPath)/Obj/$(OutputFile)$(ExeSuffix) > $(ProjectPath)/Lst/$(OutputFile).map && echo ====================================================================== >> $(ProjectPath)/Lst/$(OutputFile).map && cat $(ProjectPath)/Lst/$(OutputFile).temp >> $(ProjectPath)/Lst/$(OutputFile).map && rm -rf $(ProjectPath)/Lst/$(OutputFile).temp
	$(OBJCOPY) $(ObjcopySwitch) $(ProjectPath)/$(IntermediateDirectory)/$(OutputFile)$(ExeSuffix)  $(ProjectPath)/Obj/$(OutputFile)$(IHexSuffix) 
	$(OBJDUMP) $(ObjdumpSwitch) $(ProjectPath)/$(IntermediateDirectory)/$(OutputFile)$(ExeSuffix)  > $(ProjectPath)/Lst/$(OutputFile)$(DisassemSuffix) 
	@echo size of target:
	@$(SIZE) $(ProjectPath)$(IntermediateDirectory)/$(OutputFile)$(ExeSuffix) 
	@echo -n checksum value of target:  
	@$(CHECKSUM) $(ProjectPath)/$(IntermediateDirectory)/$(OutputFile)$(ExeSuffix) 
	@$(ProjectName).modify.bat $(IntermediateDirectory) $(OutputFile)$(ExeSuffix) 

Always_Link:


##
## Objects
##
$(IntermediateDirectory)/arch_apt32f110_iostring$(ObjectSuffix): arch/apt32f110_iostring.c  
	$(CC) $(SourceSwitch) arch/apt32f110_iostring.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/arch_apt32f110_iostring$(ObjectSuffix) -MF$(IntermediateDirectory)/arch_apt32f110_iostring$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/arch_apt32f110_iostring$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/arch_apt32f110_iostring$(PreprocessSuffix): arch/apt32f110_iostring.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/arch_apt32f110_iostring$(PreprocessSuffix) arch/apt32f110_iostring.c

$(IntermediateDirectory)/arch_crt0$(ObjectSuffix): arch/crt0.S  
	$(AS) $(SourceSwitch) arch/crt0.S $(ASFLAGS) -MMD -MP -MT$(IntermediateDirectory)/arch_crt0$(ObjectSuffix) -MF$(IntermediateDirectory)/arch_crt0$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/arch_crt0$(ObjectSuffix) $(IncludeAPath) $(IncludePackagePath)
Lst/arch_crt0$(PreprocessSuffix): arch/crt0.S
	$(CC) $(CFLAGS)$(IncludeAPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/arch_crt0$(PreprocessSuffix) arch/crt0.S

$(IntermediateDirectory)/arch_mem_init$(ObjectSuffix): arch/mem_init.c  
	$(CC) $(SourceSwitch) arch/mem_init.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/arch_mem_init$(ObjectSuffix) -MF$(IntermediateDirectory)/arch_mem_init$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/arch_mem_init$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/arch_mem_init$(PreprocessSuffix): arch/mem_init.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/arch_mem_init$(PreprocessSuffix) arch/mem_init.c

$(IntermediateDirectory)/drivers_apt32f110x$(ObjectSuffix): drivers/apt32f110x.c  
	$(CC) $(SourceSwitch) drivers/apt32f110x.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/drivers_apt32f110x$(ObjectSuffix) -MF$(IntermediateDirectory)/drivers_apt32f110x$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/drivers_apt32f110x$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/drivers_apt32f110x$(PreprocessSuffix): drivers/apt32f110x.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/drivers_apt32f110x$(PreprocessSuffix) drivers/apt32f110x.c

$(IntermediateDirectory)/drivers_apt32f110x_ck802$(ObjectSuffix): drivers/apt32f110x_ck802.c  
	$(CC) $(SourceSwitch) drivers/apt32f110x_ck802.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/drivers_apt32f110x_ck802$(ObjectSuffix) -MF$(IntermediateDirectory)/drivers_apt32f110x_ck802$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/drivers_apt32f110x_ck802$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/drivers_apt32f110x_ck802$(PreprocessSuffix): drivers/apt32f110x_ck802.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/drivers_apt32f110x_ck802$(PreprocessSuffix) drivers/apt32f110x_ck802.c

$(IntermediateDirectory)/FWlib_apt32f110x_adc$(ObjectSuffix): FWlib/apt32f110x_adc.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_adc.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_adc$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_adc$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_adc$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_adc$(PreprocessSuffix): FWlib/apt32f110x_adc.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_adc$(PreprocessSuffix) FWlib/apt32f110x_adc.c

$(IntermediateDirectory)/FWlib_apt32f110x_bt$(ObjectSuffix): FWlib/apt32f110x_bt.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_bt.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_bt$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_bt$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_bt$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_bt$(PreprocessSuffix): FWlib/apt32f110x_bt.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_bt$(PreprocessSuffix) FWlib/apt32f110x_bt.c

$(IntermediateDirectory)/FWlib_apt32f110x_cmp$(ObjectSuffix): FWlib/apt32f110x_cmp.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_cmp.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_cmp$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_cmp$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_cmp$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_cmp$(PreprocessSuffix): FWlib/apt32f110x_cmp.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_cmp$(PreprocessSuffix) FWlib/apt32f110x_cmp.c

$(IntermediateDirectory)/FWlib_apt32f110x_coret$(ObjectSuffix): FWlib/apt32f110x_coret.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_coret.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_coret$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_coret$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_coret$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_coret$(PreprocessSuffix): FWlib/apt32f110x_coret.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_coret$(PreprocessSuffix) FWlib/apt32f110x_coret.c

$(IntermediateDirectory)/FWlib_apt32f110x_countera$(ObjectSuffix): FWlib/apt32f110x_countera.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_countera.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_countera$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_countera$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_countera$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_countera$(PreprocessSuffix): FWlib/apt32f110x_countera.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_countera$(PreprocessSuffix) FWlib/apt32f110x_countera.c

$(IntermediateDirectory)/FWlib_apt32f110x_crc$(ObjectSuffix): FWlib/apt32f110x_crc.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_crc.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_crc$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_crc$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_crc$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_crc$(PreprocessSuffix): FWlib/apt32f110x_crc.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_crc$(PreprocessSuffix) FWlib/apt32f110x_crc.c

$(IntermediateDirectory)/FWlib_apt32f110x_dma$(ObjectSuffix): FWlib/apt32f110x_dma.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_dma.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_dma$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_dma$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_dma$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_dma$(PreprocessSuffix): FWlib/apt32f110x_dma.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_dma$(PreprocessSuffix) FWlib/apt32f110x_dma.c

$(IntermediateDirectory)/FWlib_apt32f110x_ept$(ObjectSuffix): FWlib/apt32f110x_ept.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_ept.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_ept$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_ept$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_ept$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_ept$(PreprocessSuffix): FWlib/apt32f110x_ept.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_ept$(PreprocessSuffix) FWlib/apt32f110x_ept.c

$(IntermediateDirectory)/FWlib_apt32f110x_gpio$(ObjectSuffix): FWlib/apt32f110x_gpio.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_gpio.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_gpio$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_gpio$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_gpio$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_gpio$(PreprocessSuffix): FWlib/apt32f110x_gpio.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_gpio$(PreprocessSuffix) FWlib/apt32f110x_gpio.c

$(IntermediateDirectory)/FWlib_apt32f110x_gpt$(ObjectSuffix): FWlib/apt32f110x_gpt.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_gpt.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_gpt$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_gpt$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_gpt$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_gpt$(PreprocessSuffix): FWlib/apt32f110x_gpt.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_gpt$(PreprocessSuffix) FWlib/apt32f110x_gpt.c

$(IntermediateDirectory)/FWlib_apt32f110x_i2c$(ObjectSuffix): FWlib/apt32f110x_i2c.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_i2c.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_i2c$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_i2c$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_i2c$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_i2c$(PreprocessSuffix): FWlib/apt32f110x_i2c.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_i2c$(PreprocessSuffix) FWlib/apt32f110x_i2c.c

$(IntermediateDirectory)/FWlib_apt32f110x_ifc$(ObjectSuffix): FWlib/apt32f110x_ifc.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_ifc.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_ifc$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_ifc$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_ifc$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_ifc$(PreprocessSuffix): FWlib/apt32f110x_ifc.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_ifc$(PreprocessSuffix) FWlib/apt32f110x_ifc.c

$(IntermediateDirectory)/FWlib_apt32f110x_lcd$(ObjectSuffix): FWlib/apt32f110x_lcd.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_lcd.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_lcd$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_lcd$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_lcd$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_lcd$(PreprocessSuffix): FWlib/apt32f110x_lcd.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_lcd$(PreprocessSuffix) FWlib/apt32f110x_lcd.c

$(IntermediateDirectory)/FWlib_apt32f110x_led$(ObjectSuffix): FWlib/apt32f110x_led.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_led.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_led$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_led$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_led$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_led$(PreprocessSuffix): FWlib/apt32f110x_led.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_led$(PreprocessSuffix) FWlib/apt32f110x_led.c

$(IntermediateDirectory)/FWlib_apt32f110x_lpt$(ObjectSuffix): FWlib/apt32f110x_lpt.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_lpt.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_lpt$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_lpt$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_lpt$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_lpt$(PreprocessSuffix): FWlib/apt32f110x_lpt.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_lpt$(PreprocessSuffix) FWlib/apt32f110x_lpt.c

$(IntermediateDirectory)/FWlib_apt32f110x_rtc$(ObjectSuffix): FWlib/apt32f110x_rtc.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_rtc.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_rtc$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_rtc$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_rtc$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_rtc$(PreprocessSuffix): FWlib/apt32f110x_rtc.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_rtc$(PreprocessSuffix) FWlib/apt32f110x_rtc.c

$(IntermediateDirectory)/FWlib_apt32f110x_sio$(ObjectSuffix): FWlib/apt32f110x_sio.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_sio.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_sio$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_sio$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_sio$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_sio$(PreprocessSuffix): FWlib/apt32f110x_sio.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_sio$(PreprocessSuffix) FWlib/apt32f110x_sio.c

$(IntermediateDirectory)/FWlib_apt32f110x_spi$(ObjectSuffix): FWlib/apt32f110x_spi.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_spi.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_spi$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_spi$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_spi$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_spi$(PreprocessSuffix): FWlib/apt32f110x_spi.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_spi$(PreprocessSuffix) FWlib/apt32f110x_spi.c

$(IntermediateDirectory)/FWlib_apt32f110x_syscon$(ObjectSuffix): FWlib/apt32f110x_syscon.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_syscon.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_syscon$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_syscon$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_syscon$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_syscon$(PreprocessSuffix): FWlib/apt32f110x_syscon.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_syscon$(PreprocessSuffix) FWlib/apt32f110x_syscon.c

$(IntermediateDirectory)/FWlib_apt32f110x_tkey_c_v01$(ObjectSuffix): FWlib/apt32f110x_tkey_c_v01.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_tkey_c_v01.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_tkey_c_v01$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_tkey_c_v01$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_tkey_c_v01$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_tkey_c_v01$(PreprocessSuffix): FWlib/apt32f110x_tkey_c_v01.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_tkey_c_v01$(PreprocessSuffix) FWlib/apt32f110x_tkey_c_v01.c

$(IntermediateDirectory)/FWlib_apt32f110x_tkey_f_v01$(ObjectSuffix): FWlib/apt32f110x_tkey_f_v01.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_tkey_f_v01.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_tkey_f_v01$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_tkey_f_v01$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_tkey_f_v01$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_tkey_f_v01$(PreprocessSuffix): FWlib/apt32f110x_tkey_f_v01.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_tkey_f_v01$(PreprocessSuffix) FWlib/apt32f110x_tkey_f_v01.c

$(IntermediateDirectory)/FWlib_apt32f110x_tkey_mc_v01$(ObjectSuffix): FWlib/apt32f110x_tkey_mc_v01.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_tkey_mc_v01.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_tkey_mc_v01$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_tkey_mc_v01$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_tkey_mc_v01$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_tkey_mc_v01$(PreprocessSuffix): FWlib/apt32f110x_tkey_mc_v01.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_tkey_mc_v01$(PreprocessSuffix) FWlib/apt32f110x_tkey_mc_v01.c

$(IntermediateDirectory)/FWlib_apt32f110x_tkey_parameter$(ObjectSuffix): FWlib/apt32f110x_tkey_parameter.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_tkey_parameter.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_tkey_parameter$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_tkey_parameter$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_tkey_parameter$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_tkey_parameter$(PreprocessSuffix): FWlib/apt32f110x_tkey_parameter.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_tkey_parameter$(PreprocessSuffix) FWlib/apt32f110x_tkey_parameter.c

$(IntermediateDirectory)/FWlib_apt32f110x_uart$(ObjectSuffix): FWlib/apt32f110x_uart.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_uart.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_uart$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_uart$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_uart$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_uart$(PreprocessSuffix): FWlib/apt32f110x_uart.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_uart$(PreprocessSuffix) FWlib/apt32f110x_uart.c

$(IntermediateDirectory)/FWlib_apt32f110x_usart$(ObjectSuffix): FWlib/apt32f110x_usart.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_usart.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_usart$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_usart$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_usart$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_usart$(PreprocessSuffix): FWlib/apt32f110x_usart.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_usart$(PreprocessSuffix) FWlib/apt32f110x_usart.c

$(IntermediateDirectory)/FWlib_apt32f110x_wwdt$(ObjectSuffix): FWlib/apt32f110x_wwdt.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_wwdt.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_wwdt$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_wwdt$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_wwdt$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_wwdt$(PreprocessSuffix): FWlib/apt32f110x_wwdt.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_wwdt$(PreprocessSuffix) FWlib/apt32f110x_wwdt.c

$(IntermediateDirectory)/FWlib_apt32f110x_etcb$(ObjectSuffix): FWlib/apt32f110x_etcb.c  
	$(CC) $(SourceSwitch) FWlib/apt32f110x_etcb.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f110x_etcb$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f110x_etcb$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f110x_etcb$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f110x_etcb$(PreprocessSuffix): FWlib/apt32f110x_etcb.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f110x_etcb$(PreprocessSuffix) FWlib/apt32f110x_etcb.c

$(IntermediateDirectory)/main$(ObjectSuffix): main.c  
	$(CC) $(SourceSwitch) main.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/main$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/main$(PreprocessSuffix) main.c

$(IntermediateDirectory)/apt32f110x_initial$(ObjectSuffix): apt32f110x_initial.c  
	$(CC) $(SourceSwitch) apt32f110x_initial.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/apt32f110x_initial$(ObjectSuffix) -MF$(IntermediateDirectory)/apt32f110x_initial$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/apt32f110x_initial$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/apt32f110x_initial$(PreprocessSuffix): apt32f110x_initial.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/apt32f110x_initial$(PreprocessSuffix) apt32f110x_initial.c

$(IntermediateDirectory)/apt32f110x_interrupt$(ObjectSuffix): apt32f110x_interrupt.c  
	$(CC) $(SourceSwitch) apt32f110x_interrupt.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/apt32f110x_interrupt$(ObjectSuffix) -MF$(IntermediateDirectory)/apt32f110x_interrupt$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/apt32f110x_interrupt$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/apt32f110x_interrupt$(PreprocessSuffix): apt32f110x_interrupt.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/apt32f110x_interrupt$(PreprocessSuffix) apt32f110x_interrupt.c


$(IntermediateDirectory)/__rt_entry$(ObjectSuffix): $(IntermediateDirectory)/__rt_entry$(DependSuffix)
	@$(AS) $(SourceSwitch) $(ProjectPath)/$(IntermediateDirectory)/__rt_entry.S $(ASFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/__rt_entry$(ObjectSuffix) $(IncludeAPath)
$(IntermediateDirectory)/__rt_entry$(DependSuffix):
	@$(CC) $(CFLAGS) $(IncludeAPath) -MG -MP -MT$(IntermediateDirectory)/__rt_entry$(ObjectSuffix) -MF$(IntermediateDirectory)/__rt_entry$(DependSuffix) -MM $(ProjectPath)/$(IntermediateDirectory)/__rt_entry.S

-include $(IntermediateDirectory)/*$(DependSuffix)
