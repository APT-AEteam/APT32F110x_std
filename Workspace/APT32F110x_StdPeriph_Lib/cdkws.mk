.PHONY: clean All Project_Title Project_Build

All: Project_Title Project_Build

Project_Title:
	@echo "----------Building project:[ std_apt32f110x - BuildSet ]----------"

Project_Build:
	@make -r -f std_apt32f110x.mk -j 6 -C  "D:/OneDrive/Works/Work Storage/Project/MCU/APT32F110/APT32F110_Lib/STD/APT32F110x_StdPeriph_Lib_V1_04/Source" 


clean:
	@echo "----------Cleaning project:[ std_apt32f110x - BuildSet ]----------"

