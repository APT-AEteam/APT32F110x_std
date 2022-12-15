MEMORY
{
ROM(RX)   : ORIGIN = 0x00000000,  LENGTH = 64K
RAM(RWX)  : ORIGIN = 0x20000000,  LENGTH = 8K
RAM_1(RWX)  : ORIGIN = 0x20002000,  LENGTH = 256
}
__kernel_stack = ORIGIN(RAM) + LENGTH(RAM) -8 ;
ENTRY(__start)

SECTIONS {
    .text :
    {
    . = ALIGN(0x4) ;
        *crt0.o (.text)
        *(.text)
    } >ROM

    .RomCode :
    {
    . = ALIGN(0x4) ;
        *(.text)
    } >ROM
	
    .rodata :
    {
    . = ALIGN(0x4) ;
        *(.rodata) 
        *(.rodata.*)
    . = ALIGN(0x4) ; 
        _end_rodata = .;
    } >ROM

    .data : 
    { 
    . = ALIGN(0x4) ;
	_start_data = .;
    	*( .data );
    . = ALIGN(0x4) ;
    	_end_data = .; 
    } >RAM AT > ROM

    .bss :
    {
         . = ALIGN(0x4) ;
         _bss_start = . ;
             *(.sbss)
             *(.sbss.*)
             *(.scommon)
             *(.bss)
             *(.bss.*)
             *(COMMON)
             . = ALIGN(0x4) ;
          _ebss = . ;
          _end = . ;
          end = . ;
    } >RAM

	.sram1_define : 
	{
		. = ALIGN(0x4) ;
		_start_sram1_define = .;
		*(.sram1_data.*)
		*(.sram1_data2.*)
		. = ALIGN(0x4) ;
		_end_sram1_define = .;
	} > RAM_1 AT > ROM
}

