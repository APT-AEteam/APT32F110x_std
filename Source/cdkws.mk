.PHONY: clean All Project_Title Project_Build

All: Project_Title Project_Build

Project_Title:
	@echo "----------Building project:[ std_apt32f110x - BuildSet ]----------"

Project_Build:
	@make -r -f std_apt32f110x.mk -j 8 -C  ./ 


clean:
	@echo "----------Cleaning project:[ std_apt32f110x - BuildSet ]----------"

