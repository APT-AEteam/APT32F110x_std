
.//Obj/apt32f110_std_release.elf:     file format elf32-csky-little


Disassembly of section .text:

00000000 <vector_table>:
		IFC->CR=0X01;					//Start Program
	}
}
//Normal mode, when the call is completed once, it will delay 4.2ms in the program
void Page_ProgramData(unsigned int FlashAdd,unsigned int DataSize,volatile unsigned char *BufArry)
{
       0:	00000108 	.long	0x00000108
	int i,DataBuffer;

	//Page cache wipe 1
	SetUserKey;
       4:	00003486 	.long	0x00003486
       8:	00003476 	.long	0x00003476
	IFC->CMR=0x07;					
       c:	00000188 	.long	0x00000188
	IFC->FM_ADDR=FlashAdd;
	IFC->CR=0X01;					//Start Program
      10:	0000347e 	.long	0x0000347e
      14:	0000343c 	.long	0x0000343c
	while(IFC->CR!=0x0);			//Wait for the operation to complete
      18:	00000188 	.long	0x00000188
	//Write data to the cache 2
	for(i=0;i<((DataSize+3)/4);i++)   //sizeof structure
      1c:	0000346e 	.long	0x0000346e
      20:	00003466 	.long	0x00003466
      24:	00000188 	.long	0x00000188
      28:	00000188 	.long	0x00000188
      2c:	00000188 	.long	0x00000188
		*(volatile unsigned int *)(FlashAdd+4*i)=DataBuffer;
		BufArry  +=4;
	}
	//Pre-programmed operation settings 3
	SetUserKey;
	IFC->CMR=0x06;					
      30:	00000188 	.long	0x00000188
	SetUserKey;
      34:	00000188 	.long	0x00000188
	IFC->FM_ADDR=FlashAdd;
	IFC->CR=0X01;					//Start Program
      38:	00000188 	.long	0x00000188
      3c:	00000188 	.long	0x00000188
	while(IFC->CR!=0x0);			//Wait for the operation to complete
      40:	0000345e 	.long	0x0000345e
	//Perform pre-programming 4
	SetUserKey;
      44:	00003456 	.long	0x00003456
	IFC->CMR=0x01;					
      48:	0000344e 	.long	0x0000344e
	IFC->FM_ADDR=FlashAdd;			//
	IFC->CR=0X01;					//Start Program
      4c:	00003446 	.long	0x00003446
	while(IFC->RISR!=PEP_END_INT);			//Wait for the operation to complete
      50:	00000188 	.long	0x00000188
	//Page erase 5
	SetUserKey;
	IFC->CMR=0x02;					
      54:	00000188 	.long	0x00000188
	SetUserKey;
      58:	00000188 	.long	0x00000188
	IFC->FM_ADDR=FlashAdd;			//
	IFC->CR=0X01;					//Start Program
      5c:	00000188 	.long	0x00000188
      60:	00000188 	.long	0x00000188
	while(IFC->RISR!=ERS_END_INT);			//Wait for the operation to complete
      64:	00000188 	.long	0x00000188
	//Write page cache data to flash memory 6
	SetUserKey;
      68:	00000188 	.long	0x00000188
	IFC->CMR=0x01;					
      6c:	00000188 	.long	0x00000188
	IFC->FM_ADDR=FlashAdd;		//
	IFC->CR=0X01;					//Start Program
      70:	00000188 	.long	0x00000188
	while(IFC->RISR!=RGM_END_INT);			//Wait for the operation to complete
      74:	00000188 	.long	0x00000188
}
      78:	00000188 	.long	0x00000188
		DataBuffer=*BufArry+(*(BufArry+1)<<8)+(*(BufArry+2)<<16)+(*(BufArry+3)<<24);
      7c:	0000343e 	.long	0x0000343e
      80:	000022b0 	.long	0x000022b0
      84:	000022d0 	.long	0x000022d0
      88:	0000240c 	.long	0x0000240c
      8c:	000024f8 	.long	0x000024f8
      90:	00002578 	.long	0x00002578
      94:	000027f4 	.long	0x000027f4
		BufArry  +=4;
      98:	000027a4 	.long	0x000027a4
      9c:	00003134 	.long	0x00003134
      a0:	00003168 	.long	0x00003168
		{
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFF00)  | 0x00000044;       //PB0.0->TXD2, PB0.1->RXD2
		}
		else if(UART_IO_G==1)
		{
			GPIOB0->CONLR = (GPIOB0->CONLR&0X00FFFFFF) | 0X77000000;        //PB0.6->TXD2 , PB0.7->RXD2
      a4:	000028a4 	.long	0x000028a4
      a8:	000029a0 	.long	0x000029a0
		}
		else if(UART_IO_G==2)
      ac:	00002a9c 	.long	0x00002a9c
		{
			GPIOA1->CONHR = (GPIOA1->CONHR&0XFFF00FFF) | 0X00066000;        //PA1.11->TXD2 , PA1.12->RXD2
      b0:	00002da4 	.long	0x00002da4
      b4:	00002dfc 	.long	0x00002dfc
      b8:	00002e58 	.long	0x00002e58
      bc:	00002eb4 	.long	0x00002eb4
      c0:	00002f0c 	.long	0x00002f0c
      c4:	00002c30 	.long	0x00002c30
      c8:	000030a4 	.long	0x000030a4
      cc:	00002f58 	.long	0x00002f58
      d0:	00002f6c 	.long	0x00002f6c
      d4:	0000319c 	.long	0x0000319c
      d8:	000031ec 	.long	0x000031ec
      dc:	00003264 	.long	0x00003264
      e0:	00003496 	.long	0x00003496
      e4:	00003428 	.long	0x00003428
      e8:	000032d4 	.long	0x000032d4
      ec:	000033a8 	.long	0x000033a8
      f0:	000033d4 	.long	0x000033d4
      f4:	00003310 	.long	0x00003310
      f8:	00003358 	.long	0x00003358
      fc:	0000348e 	.long	0x0000348e
	...

00000108 <__start>:
.long 0x00000000
.long 0x00000000
//  .long __start
__start:
  //initialize all registers
  movi r0, 0
     108:	3000      	movi      	r0, 0
  movi r1, 0
     10a:	3100      	movi      	r1, 0
  movi r2, 0
     10c:	3200      	movi      	r2, 0
  movi r3, 0
     10e:	3300      	movi      	r3, 0
  movi r4, 0
     110:	3400      	movi      	r4, 0
  movi r5, 0
     112:	3500      	movi      	r5, 0
  movi r6, 0
     114:	3600      	movi      	r6, 0
  movi r7, 0
     116:	3700      	movi      	r7, 0
  //movi r13, 0
  //movi r14, 0
  //movi r15, 0

//set VBR
  lrw r2, vector_table				//vector_table -> r2
     118:	105d      	lrw      	r2, 0x0	// 18c <DummyHandler+0x4>
  mtcr r2, cr<1,0>					//r2 -> cr<1,0>(vbr)
     11a:	c0026421 	mtcr      	r2, cr<1, 0>

//enable EE bit of psr
  mfcr r2, cr<0,0>					//cr<0,0>(psr) -> r2;  
     11e:	c0006022 	mfcr      	r2, cr<0, 0>
  bseti r2, r2, 8					//set the 8th bit of r2 
     122:	3aa8      	bseti      	r2, 8
  mtcr r2, cr<0,0>					//r2 -> cr<0,0>(psr)
     124:	c0026420 	mtcr      	r2, cr<0, 0>
//  st.w    r2, (r1,0x4)
//  movi    r2, 0x1
//  st.w    r2, (r1,0x0)

//disable power peak 
  lrw     r1, 0xe000ef90
     128:	103a      	lrw      	r1, 0xe000ef90	// 190 <DummyHandler+0x8>
  movi    r2, 0x0
     12a:	3200      	movi      	r2, 0
  st.w    r2, (r1, 0x0)				//r2 -> r1(0xe000ef90 + 0); clr mem(0xe000ef90)
     12c:	b140      	st.w      	r2, (r1, 0x0)

//initialize kernel stack
  lrw  r7, __kernel_stack			//__kernel_stack is defined in gcc_xxx.ld; 
     12e:	10fa      	lrw      	r7, 0x20001ff8	// 194 <DummyHandler+0xc>
  mov  r14,r7						//r14(sp) = stack address				
     130:	6f9f      	mov      	r14, r7
  subi r6,r7,0x4					//(r7 - 4) -> r6				
     132:	5fcf      	subi      	r6, r7, 4

  //lrw  r3, 0x40
  lrw  r3, 0x04					
     134:	3304      	movi      	r3, 4
	
  subu r4, r7, r3					//(r7 - r3)	-> r4			
     136:	5f8d      	subu      	r4, r7, r3
  lrw  r5, 0x0
     138:	3500      	movi      	r5, 0

0000013a <INIT_KERLE_STACK>:
INIT_KERLE_STACK:
  addi r4, 0x4
     13a:	2403      	addi      	r4, 4
  st.w r5, (r4)
     13c:	b4a0      	st.w      	r5, (r4, 0x0)
  //cmphs r7, r4						//r7 = r4; c = 1
  cmphs r6, r4						//r6 < r4; c = 0
     13e:	6518      	cmphs      	r6, r4
  bt  INIT_KERLE_STACK				//c = 1, jmp		
     140:	0bfd      	bt      	0x13a	// 13a <INIT_KERLE_STACK>

00000142 <__to_main>:
        
__to_main:
  lrw r0,__main						//__main is defined in mem_init.c; 
     142:	1016      	lrw      	r0, 0x1858	// 198 <DummyHandler+0x10>
  jsr r0							//jmp __main and r15(lr) = (pc + 4) 
     144:	7bc1      	jsr      	r0
  mov r0, r0
     146:	6c03      	mov      	r0, r0
  mov r0, r0
     148:	6c03      	mov      	r0, r0

  lrw r15, __exit
     14a:	ea8f0015 	lrw      	r15, 0x15c	// 19c <DummyHandler+0x14>
  lrw r0,main
     14e:	1015      	lrw      	r0, 0x349e	// 1a0 <DummyHandler+0x18>
  jmp r0
     150:	7800      	jmp      	r0
  mov r0, r0
     152:	6c03      	mov      	r0, r0
  mov r0, r0
     154:	6c03      	mov      	r0, r0
  mov r0, r0
     156:	6c03      	mov      	r0, r0
  mov r0, r0
     158:	6c03      	mov      	r0, r0
  mov r0, r0
     15a:	6c03      	mov      	r0, r0

0000015c <__exit>:

.export __exit
__exit:

  lrw r4, 0x20003000
     15c:	1092      	lrw      	r4, 0x20003000	// 1a4 <DummyHandler+0x1c>
  //lrw r5, 0x0
  mov r5, r0
     15e:	6d43      	mov      	r5, r0
  st.w r5, (r4)
     160:	b4a0      	st.w      	r5, (r4, 0x0)

  mfcr r1, cr<0,0>
     162:	c0006021 	mfcr      	r1, cr<0, 0>
  lrw  r1, 0xFFFF
     166:	ea01ffff 	movi      	r1, 65535
  mtcr r1, cr<11,0>
     16a:	c001642b 	mtcr      	r1, cr<11, 0>
  lrw     r1, 0xFFF
     16e:	ea010fff 	movi      	r1, 4095
  movi    r0, 0x0
     172:	3000      	movi      	r0, 0
  st      r1, (r0)
     174:	b020      	st.w      	r1, (r0, 0x0)

00000176 <__fail>:

.export __fail
__fail:
  lrw  r1, 0xEEEE
     176:	ea01eeee 	movi      	r1, 61166
  mtcr r1, cr<11,0>
     17a:	c001642b 	mtcr      	r1, cr<11, 0>
  lrw     r1, 0xEEE
     17e:	ea010eee 	movi      	r1, 3822
  movi    r0, 0x0
     182:	3000      	movi      	r0, 0
  st      r1, (r0)
     184:	b020      	st.w      	r1, (r0, 0x0)

00000186 <__dummy>:

__dummy:
  br      __fail
     186:	07f8      	br      	0x176	// 176 <__fail>

00000188 <DummyHandler>:

.export DummyHandler
DummyHandler:
  br      __fail
     188:	07f7      	br      	0x176	// 176 <__fail>
     18a:	0000      	.short	0x0000
     18c:	00000000 	.long	0x00000000
     190:	e000ef90 	.long	0xe000ef90
     194:	20001ff8 	.long	0x20001ff8
     198:	00001858 	.long	0x00001858
     19c:	0000015c 	.long	0x0000015c
     1a0:	0000349e 	.long	0x0000349e
     1a4:	20003000 	.long	0x20003000

000001a8 <tkey_io_enable>:

/****************************************************
//TK IO configure
*****************************************************/
void tkey_io_enable(void)
{
     1a8:	14d3      	push      	r4-r6, r15
	unsigned char i;
	GPIOA0_CONLR=(GPIOA0_CONLR&0XFF0FFFFF) | 0x00A00000;//PA0.5 TS_CAP
     1aa:	33c0      	movi      	r3, 192
     1ac:	4377      	lsli      	r3, r3, 23
     1ae:	9340      	ld.w      	r2, (r3, 0x0)
     1b0:	ea21ff10 	movih      	r1, 65296
     1b4:	2900      	subi      	r1, 1
     1b6:	6884      	and      	r2, r1
     1b8:	3ab5      	bseti      	r2, 21
     1ba:	3ab7      	bseti      	r2, 23
	{
		if ((dwTkeyIoEnable & (1<<i))!=0)
		{
			switch (i)
			{
				case 0  : 	GPIOA0_CONHR=(GPIOA0_CONHR&0XF0FFFFFF) | 0x0A000000;break; 	//PA0.14	TCH0
     1bc:	34f0      	movi      	r4, 240
	GPIOA0_CONLR=(GPIOA0_CONLR&0XFF0FFFFF) | 0x00A00000;//PA0.5 TS_CAP
     1be:	b340      	st.w      	r2, (r3, 0x0)
     1c0:	3100      	movi      	r1, 0
		if ((dwTkeyIoEnable & (1<<i))!=0)
     1c2:	03bf      	lrw      	r5, 0x200004f0	// 3c0 <tkey_io_enable+0x218>
				case 0  : 	GPIOA0_CONHR=(GPIOA0_CONHR&0XF0FFFFFF) | 0x0A000000;break; 	//PA0.14	TCH0
     1c4:	4494      	lsli      	r4, r4, 20
		if ((dwTkeyIoEnable & (1<<i))!=0)
     1c6:	3201      	movi      	r2, 1
     1c8:	95c0      	ld.w      	r6, (r5, 0x0)
     1ca:	7084      	lsl      	r2, r1
     1cc:	6898      	and      	r2, r6
     1ce:	7404      	zextb      	r0, r1
     1d0:	3a40      	cmpnei      	r2, 0
     1d2:	0c2a      	bf      	0x226	// 226 <tkey_io_enable+0x7e>
			switch (i)
     1d4:	2800      	subi      	r0, 1
     1d6:	381e      	cmphsi      	r0, 31
     1d8:	0822      	bt      	0x21c	// 21c <tkey_io_enable+0x74>
     1da:	e0000a9d 	bsr      	0x1714	// 1714 <___gnu_csky_case_uhi>
     1de:	0029      	.short	0x0029
     1e0:	0037002f 	.long	0x0037002f
     1e4:	0046003f 	.long	0x0046003f
     1e8:	0057004e 	.long	0x0057004e
     1ec:	00660060 	.long	0x00660060
     1f0:	00770068 	.long	0x00770068
     1f4:	00800079 	.long	0x00800079
     1f8:	0098008f 	.long	0x0098008f
     1fc:	00a700a0 	.long	0x00a700a0
     200:	00b000ae 	.long	0x00b000ae
     204:	00b400b2 	.long	0x00b400b2
     208:	00c600bd 	.long	0x00c600bd
     20c:	00d000c8 	.long	0x00d000c8
     210:	00dd00d7 	.long	0x00dd00d7
     214:	00eb00e3 	.long	0x00eb00e3
     218:	00ef00ed 	.long	0x00ef00ed
				case 0  : 	GPIOA0_CONHR=(GPIOA0_CONHR&0XF0FFFFFF) | 0x0A000000;break; 	//PA0.14	TCH0
     21c:	9341      	ld.w      	r2, (r3, 0x4)
     21e:	6891      	andn      	r2, r4
     220:	3ab9      	bseti      	r2, 25
     222:	3abb      	bseti      	r2, 27
				case 1  : 	GPIOA0_CONHR=(GPIOA0_CONHR&0X0FFFFFFF) | 0xA0000000;break; 	//PA0.15	TCH1
     224:	b341      	st.w      	r2, (r3, 0x4)
     226:	2100      	addi      	r1, 1
	for (i=0;i<32;i++)
     228:	eb410020 	cmpnei      	r1, 32
     22c:	0bcd      	bt      	0x1c6	// 1c6 <tkey_io_enable+0x1e>
				case 31 :	GPIOB0_CONLR=(GPIOB0_CONLR&0XFFFFF0FF) | 0x00000A00;break; 	//PB0.2		TCH31
				default : break;
			}
		}
	}
}
     22e:	1493      	pop      	r4-r6, r15
				case 1  : 	GPIOA0_CONHR=(GPIOA0_CONHR&0X0FFFFFFF) | 0xA0000000;break; 	//PA0.15	TCH1
     230:	9341      	ld.w      	r2, (r3, 0x4)
     232:	4244      	lsli      	r2, r2, 4
     234:	4a44      	lsri      	r2, r2, 4
     236:	3abd      	bseti      	r2, 29
     238:	3abf      	bseti      	r2, 31
     23a:	07f5      	br      	0x224	// 224 <tkey_io_enable+0x7c>
				case 2  : 	GPIOA1_CONLR=(GPIOA1_CONLR&0XFFFFFFF0) | 0x0000000A;break; 	//PA1.0		TCH2
     23c:	1302      	lrw      	r0, 0x60001000	// 3c4 <tkey_io_enable+0x21c>
				case 29 :	GPIOB0_CONLR=(GPIOB0_CONLR&0XFFFFFFF0) | 0x0000000A;break; 	//PB0.0		TCH29
     23e:	9040      	ld.w      	r2, (r0, 0x0)
     240:	3600      	movi      	r6, 0
     242:	2e0f      	subi      	r6, 16
     244:	6898      	and      	r2, r6
     246:	ec42000a 	ori      	r2, r2, 10
     24a:	0416      	br      	0x276	// 276 <tkey_io_enable+0xce>
				case 3  : 	GPIOA1_CONLR=(GPIOA1_CONLR&0XFFFFFF0F) | 0x000000A0;break; 	//PA1.1		TCH3
     24c:	121e      	lrw      	r0, 0x60001000	// 3c4 <tkey_io_enable+0x21c>
				case 30 :	GPIOB0_CONLR=(GPIOB0_CONLR&0XFFFFFF0F) | 0x000000A0;break; 	//PB0.1		TCH30
     24e:	9040      	ld.w      	r2, (r0, 0x0)
     250:	3600      	movi      	r6, 0
     252:	2ef0      	subi      	r6, 241
     254:	6898      	and      	r2, r6
     256:	ec4200a0 	ori      	r2, r2, 160
     25a:	040e      	br      	0x276	// 276 <tkey_io_enable+0xce>
				case 4  : 	GPIOA1_CONLR=(GPIOA1_CONLR&0XFFFFF0FF) | 0x00000A00;break; 	//PA1.2		TCH4
     25c:	121a      	lrw      	r0, 0x60001000	// 3c4 <tkey_io_enable+0x21c>
				case 31 :	GPIOB0_CONLR=(GPIOB0_CONLR&0XFFFFF0FF) | 0x00000A00;break; 	//PB0.2		TCH31
     25e:	9040      	ld.w      	r2, (r0, 0x0)
     260:	12da      	lrw      	r6, 0xfffff0ff	// 3c8 <tkey_io_enable+0x220>
     262:	6898      	and      	r2, r6
     264:	ec420a00 	ori      	r2, r2, 2560
     268:	0407      	br      	0x276	// 276 <tkey_io_enable+0xce>
				case 5  : 	GPIOA1_CONLR=(GPIOA1_CONLR&0XFFFF0FFF) | 0x0000A000;break; 	//PA1.3		TCH5
     26a:	1217      	lrw      	r0, 0x60001000	// 3c4 <tkey_io_enable+0x21c>
     26c:	12d8      	lrw      	r6, 0xffff0fff	// 3cc <tkey_io_enable+0x224>
     26e:	9040      	ld.w      	r2, (r0, 0x0)
     270:	6898      	and      	r2, r6
     272:	ec42a000 	ori      	r2, r2, 40960
				case 31 :	GPIOB0_CONLR=(GPIOB0_CONLR&0XFFFFF0FF) | 0x00000A00;break; 	//PB0.2		TCH31
     276:	b040      	st.w      	r2, (r0, 0x0)
     278:	07d7      	br      	0x226	// 226 <tkey_io_enable+0x7e>
				case 6  : 	GPIOA1_CONLR=(GPIOA1_CONLR&0XFFF0FFFF) | 0x000A0000;break; 	//PA1.4		TCH6
     27a:	1213      	lrw      	r0, 0x60001000	// 3c4 <tkey_io_enable+0x21c>
     27c:	ea26fff1 	movih      	r6, 65521
     280:	9040      	ld.w      	r2, (r0, 0x0)
     282:	2e00      	subi      	r6, 1
     284:	6898      	and      	r2, r6
     286:	3ab1      	bseti      	r2, 17
     288:	3ab3      	bseti      	r2, 19
     28a:	07f6      	br      	0x276	// 276 <tkey_io_enable+0xce>
				case 7  : 	GPIOA1_CONLR=(GPIOA1_CONLR&0XFF0FFFFF) | 0x00A00000;break; 	//PA1.5		TCH7
     28c:	120e      	lrw      	r0, 0x60001000	// 3c4 <tkey_io_enable+0x21c>
				case 9  : 	GPIOB0_CONLR=(GPIOB0_CONLR&0XFF0FFFFF) | 0x00A00000;break; 	//PB0.5		TCH9
     28e:	9040      	ld.w      	r2, (r0, 0x0)
     290:	ea26ff10 	movih      	r6, 65296
     294:	2e00      	subi      	r6, 1
     296:	6898      	and      	r2, r6
     298:	3ab5      	bseti      	r2, 21
     29a:	3ab7      	bseti      	r2, 23
     29c:	07ed      	br      	0x276	// 276 <tkey_io_enable+0xce>
				case 8  : 	GPIOA1_CONLR=(GPIOA1_CONLR&0XF0FFFFFF) | 0x0A000000;break; 	//PA1.6		TCH8
     29e:	120a      	lrw      	r0, 0x60001000	// 3c4 <tkey_io_enable+0x21c>
				case 11 :	GPIOB0_CONLR=(GPIOB0_CONLR&0XF0FFFFFF) | 0x0A000000;break; 	//PB0.6		TCH11
     2a0:	9040      	ld.w      	r2, (r0, 0x0)
     2a2:	6891      	andn      	r2, r4
     2a4:	3ab9      	bseti      	r2, 25
     2a6:	3abb      	bseti      	r2, 27
     2a8:	07e7      	br      	0x276	// 276 <tkey_io_enable+0xce>
				case 9  : 	GPIOB0_CONLR=(GPIOB0_CONLR&0XFF0FFFFF) | 0x00A00000;break; 	//PB0.5		TCH9
     2aa:	120a      	lrw      	r0, 0x60002000	// 3d0 <tkey_io_enable+0x228>
     2ac:	07f1      	br      	0x28e	// 28e <tkey_io_enable+0xe6>
				case 10 : 	*(uint32_t *)(0x40011128) = 0x5a;
     2ae:	124a      	lrw      	r2, 0x40011100	// 3d4 <tkey_io_enable+0x22c>
     2b0:	305a      	movi      	r0, 90
     2b2:	b20a      	st.w      	r0, (r2, 0x28)
							GPIOA1_CONLR=(GPIOA1_CONLR&0X0FFFFFFF) | 0xA0000000;			//PA1.7		TCH10
     2b4:	1204      	lrw      	r0, 0x60001000	// 3c4 <tkey_io_enable+0x21c>
     2b6:	9040      	ld.w      	r2, (r0, 0x0)
     2b8:	4244      	lsli      	r2, r2, 4
     2ba:	4a44      	lsri      	r2, r2, 4
     2bc:	3abd      	bseti      	r2, 29
     2be:	3abf      	bseti      	r2, 31
     2c0:	b040      	st.w      	r2, (r0, 0x0)
							GPIOA1_PUDR &= 0XFFFF3FFF;
     2c2:	9048      	ld.w      	r2, (r0, 0x20)
     2c4:	3a8e      	bclri      	r2, 14
     2c6:	3a8f      	bclri      	r2, 15
							GPIOA1_PUDR &= 0XFFFCFFFF;
     2c8:	b048      	st.w      	r2, (r0, 0x20)
					break; 
     2ca:	07ae      	br      	0x226	// 226 <tkey_io_enable+0x7e>
				case 11 :	GPIOB0_CONLR=(GPIOB0_CONLR&0XF0FFFFFF) | 0x0A000000;break; 	//PB0.6		TCH11
     2cc:	1201      	lrw      	r0, 0x60002000	// 3d0 <tkey_io_enable+0x228>
     2ce:	07e9      	br      	0x2a0	// 2a0 <tkey_io_enable+0xf8>
				case 12 :	GPIOB0_CONLR=(GPIOB0_CONLR&0X0FFFFFFF) | 0xA0000000;break; 	//PB0.7		TCH12
     2d0:	1200      	lrw      	r0, 0x60002000	// 3d0 <tkey_io_enable+0x228>
     2d2:	9040      	ld.w      	r2, (r0, 0x0)
     2d4:	4244      	lsli      	r2, r2, 4
     2d6:	4a44      	lsri      	r2, r2, 4
     2d8:	3abd      	bseti      	r2, 29
     2da:	3abf      	bseti      	r2, 31
     2dc:	07cd      	br      	0x276	// 276 <tkey_io_enable+0xce>
				case 13 :	*(uint32_t *)(0x40011128) = 0x5a;
     2de:	115e      	lrw      	r2, 0x40011100	// 3d4 <tkey_io_enable+0x22c>
     2e0:	305a      	movi      	r0, 90
							GPIOA1_CONHR=(GPIOA1_CONHR&0XFFFFFFF0) | 0x0000000A;			//PA1.8		TCH13
     2e2:	3600      	movi      	r6, 0
				case 13 :	*(uint32_t *)(0x40011128) = 0x5a;
     2e4:	b20a      	st.w      	r0, (r2, 0x28)
							GPIOA1_CONHR=(GPIOA1_CONHR&0XFFFFFFF0) | 0x0000000A;			//PA1.8		TCH13
     2e6:	1118      	lrw      	r0, 0x60001000	// 3c4 <tkey_io_enable+0x21c>
     2e8:	2e0f      	subi      	r6, 16
     2ea:	9041      	ld.w      	r2, (r0, 0x4)
     2ec:	6898      	and      	r2, r6
     2ee:	ec42000a 	ori      	r2, r2, 10
     2f2:	b041      	st.w      	r2, (r0, 0x4)
							GPIOA1_PUDR &= 0XFFFCFFFF;
     2f4:	9048      	ld.w      	r2, (r0, 0x20)
     2f6:	3a90      	bclri      	r2, 16
     2f8:	3a91      	bclri      	r2, 17
     2fa:	07e7      	br      	0x2c8	// 2c8 <tkey_io_enable+0x120>
				case 14 :	GPIOB0_CONHR=(GPIOB0_CONHR&0XFFFFFFF0) | 0x0000000A;break; 	//PB0.8		TCH14
     2fc:	1115      	lrw      	r0, 0x60002000	// 3d0 <tkey_io_enable+0x228>
     2fe:	3600      	movi      	r6, 0
     300:	9041      	ld.w      	r2, (r0, 0x4)
     302:	2e0f      	subi      	r6, 16
     304:	6898      	and      	r2, r6
     306:	ec42000a 	ori      	r2, r2, 10
				case 22 :	GPIOA1_CONHR=(GPIOA1_CONHR&0XFF0FFFFF) | 0x00A00000;break; 	//PA1.13	TCH22
     30a:	b041      	st.w      	r2, (r0, 0x4)
     30c:	078d      	br      	0x226	// 226 <tkey_io_enable+0x7e>
				case 15 :	GPIOB0_CONHR=(GPIOB0_CONHR&0XFFFFFF0F) | 0x000000A0;break; 	//PB0.9		TCH15
     30e:	1111      	lrw      	r0, 0x60002000	// 3d0 <tkey_io_enable+0x228>
				case 18 :	GPIOA1_CONHR=(GPIOA1_CONHR&0XFFFFFF0F) | 0x000000A0;break; 	//PA1.9		TCH18
     310:	9041      	ld.w      	r2, (r0, 0x4)
     312:	3600      	movi      	r6, 0
     314:	2ef0      	subi      	r6, 241
     316:	6898      	and      	r2, r6
     318:	ec4200a0 	ori      	r2, r2, 160
     31c:	07f7      	br      	0x30a	// 30a <tkey_io_enable+0x162>
				case 16 :	GPIOB0_CONHR=(GPIOB0_CONHR&0XFFFFF0FF) | 0x00000A00;break; 	//PB0.10	TCH16
     31e:	110d      	lrw      	r0, 0x60002000	// 3d0 <tkey_io_enable+0x228>
				case 19 :	GPIOA1_CONHR=(GPIOA1_CONHR&0XFFFFF0FF) | 0x00000A00;break; 	//PA1.10	TCH19
     320:	9041      	ld.w      	r2, (r0, 0x4)
     322:	11ca      	lrw      	r6, 0xfffff0ff	// 3c8 <tkey_io_enable+0x220>
     324:	6898      	and      	r2, r6
     326:	ec420a00 	ori      	r2, r2, 2560
     32a:	07f0      	br      	0x30a	// 30a <tkey_io_enable+0x162>
				case 17 :	GPIOB0_CONHR=(GPIOB0_CONHR&0XFFFF0FFF) | 0x0000A000;break; 	//PB0.11	TCH17
     32c:	1109      	lrw      	r0, 0x60002000	// 3d0 <tkey_io_enable+0x228>
				case 20 :	GPIOA1_CONHR=(GPIOA1_CONHR&0XFFFF0FFF) | 0x0000A000;break; 	//PA1.11	TCH20
     32e:	9041      	ld.w      	r2, (r0, 0x4)
     330:	11c7      	lrw      	r6, 0xffff0fff	// 3cc <tkey_io_enable+0x224>
     332:	6898      	and      	r2, r6
     334:	ec42a000 	ori      	r2, r2, 40960
     338:	07e9      	br      	0x30a	// 30a <tkey_io_enable+0x162>
				case 18 :	GPIOA1_CONHR=(GPIOA1_CONHR&0XFFFFFF0F) | 0x000000A0;break; 	//PA1.9		TCH18
     33a:	1103      	lrw      	r0, 0x60001000	// 3c4 <tkey_io_enable+0x21c>
     33c:	07ea      	br      	0x310	// 310 <tkey_io_enable+0x168>
				case 19 :	GPIOA1_CONHR=(GPIOA1_CONHR&0XFFFFF0FF) | 0x00000A00;break; 	//PA1.10	TCH19
     33e:	1102      	lrw      	r0, 0x60001000	// 3c4 <tkey_io_enable+0x21c>
     340:	07f0      	br      	0x320	// 320 <tkey_io_enable+0x178>
				case 20 :	GPIOA1_CONHR=(GPIOA1_CONHR&0XFFFF0FFF) | 0x0000A000;break; 	//PA1.11	TCH20
     342:	1101      	lrw      	r0, 0x60001000	// 3c4 <tkey_io_enable+0x21c>
     344:	07f5      	br      	0x32e	// 32e <tkey_io_enable+0x186>
				case 21 :	GPIOA1_CONHR=(GPIOA1_CONHR&0XFFF0FFFF) | 0x000A0000;break; 	//PA1.12	TCH21
     346:	1100      	lrw      	r0, 0x60001000	// 3c4 <tkey_io_enable+0x21c>
     348:	ea26fff1 	movih      	r6, 65521
     34c:	9041      	ld.w      	r2, (r0, 0x4)
     34e:	2e00      	subi      	r6, 1
     350:	6898      	and      	r2, r6
     352:	3ab1      	bseti      	r2, 17
     354:	3ab3      	bseti      	r2, 19
     356:	07da      	br      	0x30a	// 30a <tkey_io_enable+0x162>
				case 22 :	GPIOA1_CONHR=(GPIOA1_CONHR&0XFF0FFFFF) | 0x00A00000;break; 	//PA1.13	TCH22
     358:	101b      	lrw      	r0, 0x60001000	// 3c4 <tkey_io_enable+0x21c>
     35a:	ea26ff10 	movih      	r6, 65296
     35e:	9041      	ld.w      	r2, (r0, 0x4)
     360:	2e00      	subi      	r6, 1
     362:	6898      	and      	r2, r6
     364:	3ab5      	bseti      	r2, 21
     366:	3ab7      	bseti      	r2, 23
     368:	07d1      	br      	0x30a	// 30a <tkey_io_enable+0x162>
				case 23 :	GPIOC0_CONLR=(GPIOC0_CONLR&0XFFFFFFF0) | 0x0000000A;break; 	//PC0.0		TCH23
     36a:	101c      	lrw      	r0, 0x60004000	// 3d8 <tkey_io_enable+0x230>
     36c:	0769      	br      	0x23e	// 23e <tkey_io_enable+0x96>
				case 24 :	GPIOA0_CONLR=(GPIOA0_CONLR&0XFFFFFFF0) | 0x0000000A;break; 	//PA0.0		TCH24
     36e:	9340      	ld.w      	r2, (r3, 0x0)
     370:	3000      	movi      	r0, 0
     372:	280f      	subi      	r0, 16
     374:	6880      	and      	r2, r0
     376:	ec42000a 	ori      	r2, r2, 10
				case 28 :	GPIOA0_CONLR=(GPIOA0_CONLR&0XFFF0FFFF) | 0x000A0000;break; 	//PA0.4		TCH28
     37a:	b340      	st.w      	r2, (r3, 0x0)
     37c:	0755      	br      	0x226	// 226 <tkey_io_enable+0x7e>
				case 25 :	GPIOA0_CONLR=(GPIOA0_CONLR&0XFFFFFF0F) | 0x000000A0;break; 	//PA0.1		TCH25
     37e:	9340      	ld.w      	r2, (r3, 0x0)
     380:	3000      	movi      	r0, 0
     382:	28f0      	subi      	r0, 241
     384:	6880      	and      	r2, r0
     386:	ec4200a0 	ori      	r2, r2, 160
     38a:	07f8      	br      	0x37a	// 37a <tkey_io_enable+0x1d2>
				case 26 :	GPIOA0_CONLR=(GPIOA0_CONLR&0XFFFFF0FF) | 0x00000A00;break; 	//PA0.2		TCH26
     38c:	9340      	ld.w      	r2, (r3, 0x0)
     38e:	100f      	lrw      	r0, 0xfffff0ff	// 3c8 <tkey_io_enable+0x220>
     390:	6880      	and      	r2, r0
     392:	ec420a00 	ori      	r2, r2, 2560
     396:	07f2      	br      	0x37a	// 37a <tkey_io_enable+0x1d2>
				case 27 :	GPIOA0_CONLR=(GPIOA0_CONLR&0XFFFF0FFF) | 0x0000A000;break; 	//PA0.3		TCH27
     398:	9340      	ld.w      	r2, (r3, 0x0)
     39a:	100d      	lrw      	r0, 0xffff0fff	// 3cc <tkey_io_enable+0x224>
     39c:	6880      	and      	r2, r0
     39e:	ec42a000 	ori      	r2, r2, 40960
     3a2:	07ec      	br      	0x37a	// 37a <tkey_io_enable+0x1d2>
				case 28 :	GPIOA0_CONLR=(GPIOA0_CONLR&0XFFF0FFFF) | 0x000A0000;break; 	//PA0.4		TCH28
     3a4:	9340      	ld.w      	r2, (r3, 0x0)
     3a6:	ea20fff1 	movih      	r0, 65521
     3aa:	2800      	subi      	r0, 1
     3ac:	6880      	and      	r2, r0
     3ae:	3ab1      	bseti      	r2, 17
     3b0:	3ab3      	bseti      	r2, 19
     3b2:	07e4      	br      	0x37a	// 37a <tkey_io_enable+0x1d2>
				case 29 :	GPIOB0_CONLR=(GPIOB0_CONLR&0XFFFFFFF0) | 0x0000000A;break; 	//PB0.0		TCH29
     3b4:	1007      	lrw      	r0, 0x60002000	// 3d0 <tkey_io_enable+0x228>
     3b6:	0744      	br      	0x23e	// 23e <tkey_io_enable+0x96>
				case 30 :	GPIOB0_CONLR=(GPIOB0_CONLR&0XFFFFFF0F) | 0x000000A0;break; 	//PB0.1		TCH30
     3b8:	1006      	lrw      	r0, 0x60002000	// 3d0 <tkey_io_enable+0x228>
     3ba:	074a      	br      	0x24e	// 24e <tkey_io_enable+0xa6>
				case 31 :	GPIOB0_CONLR=(GPIOB0_CONLR&0XFFFFF0FF) | 0x00000A00;break; 	//PB0.2		TCH31
     3bc:	1005      	lrw      	r0, 0x60002000	// 3d0 <tkey_io_enable+0x228>
     3be:	0750      	br      	0x25e	// 25e <tkey_io_enable+0xb6>
     3c0:	200004f0 	.long	0x200004f0
     3c4:	60001000 	.long	0x60001000
     3c8:	fffff0ff 	.long	0xfffff0ff
     3cc:	ffff0fff 	.long	0xffff0fff
     3d0:	60002000 	.long	0x60002000
     3d4:	40011100 	.long	0x40011100
     3d8:	60004000 	.long	0x60004000

000003dc <tkey_wakeup_io_config>:
void tkey_wakeup_io_config(void)
{
     3dc:	14d4      	push      	r4-r7, r15
     3de:	1423      	subi      	r14, r14, 12
				case 25 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFFFFF0F) | 0x00000000;break; 	//PA0.1		TCH25
				case 26 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFFFF0FF) | 0x00000000;break; 	//PA0.2		TCH26
				case 27 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFFF0FFF) | 0x00000000;break; 	//PA0.3		TCH27
				case 28 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFF0FFFF) | 0x00000000;break; 	//PA0.4		TCH28
				case 29 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFFFFF0) | 0x00000000;break; 	//PB0.0		TCH29
				case 30 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFFFF0F) | 0x00000000;break; 	//PB0.1		TCH30
     3e0:	0173      	lrw      	r3, 0x20000080	// 710 <tkey_wakeup_io_config+0x334>
		if ((dwTkeyIoEnable & (1<<i))!=0)
     3e2:	0112      	lrw      	r0, 0x200004f0	// 714 <tkey_wakeup_io_config+0x338>
				case 0  : 	GPIOA0->CONHR=(GPIOA0->CONHR&0XF0FFFFFF) | 0x00000000;break; 	//PA0.14	TCH0
     3e4:	34f0      	movi      	r4, 240
				case 30 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFFFF0F) | 0x00000000;break; 	//PB0.1		TCH30
     3e6:	9340      	ld.w      	r2, (r3, 0x0)
		if ((dwTkeyIoEnable & (1<<i))!=0)
     3e8:	b801      	st.w      	r0, (r14, 0x4)
				case 22 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFF0FFFFF) | 0x00000000;break; 	//PA1.13	TCH22
     3ea:	3600      	movi      	r6, 0
				case 28 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFF0FFFF) | 0x00000000;break; 	//PA0.4		TCH28
     3ec:	0174      	lrw      	r3, 0x20000088	// 718 <tkey_wakeup_io_config+0x33c>
				case 31 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFFF0FF) | 0x00000000;break; 	//PB0.2		TCH31
				default : break;
			}
		}
		if ((dwTkeyWakeupIoEnable & (1<<i))!=0)
     3ee:	0113      	lrw      	r0, 0x200004f8	// 71c <tkey_wakeup_io_config+0x340>
				case 0  : 	GPIOA0->CONHR=(GPIOA0->CONHR&0XF0FFFFFF) | 0x00000000;break; 	//PA0.14	TCH0
     3f0:	4494      	lsli      	r4, r4, 20
				case 28 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFF0FFFF) | 0x00000000;break; 	//PA0.4		TCH28
     3f2:	9320      	ld.w      	r1, (r3, 0x0)
		if ((dwTkeyWakeupIoEnable & (1<<i))!=0)
     3f4:	b802      	st.w      	r0, (r14, 0x8)
				case 23 :	GPIOC0->CONLR=(GPIOC0->CONLR&0XFFFFFFF0) | 0x00000000;break; 	//PC0.0		TCH23
     3f6:	0174      	lrw      	r3, 0x2000007c	// 720 <tkey_wakeup_io_config+0x344>
     3f8:	93e0      	ld.w      	r7, (r3, 0x0)
				case 22 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFF0FFFFF) | 0x00000000;break; 	//PA1.13	TCH22
     3fa:	0174      	lrw      	r3, 0x20000084	// 724 <tkey_wakeup_io_config+0x348>
     3fc:	9360      	ld.w      	r3, (r3, 0x0)
		if ((dwTkeyIoEnable & (1<<i))!=0)
     3fe:	3501      	movi      	r5, 1
     400:	c4c54020 	lsl      	r0, r5, r6
     404:	b800      	st.w      	r0, (r14, 0x0)
     406:	9801      	ld.w      	r0, (r14, 0x4)
     408:	98a0      	ld.w      	r5, (r14, 0x0)
     40a:	9000      	ld.w      	r0, (r0, 0x0)
     40c:	6814      	and      	r0, r5
     40e:	3840      	cmpnei      	r0, 0
     410:	0c29      	bf      	0x462	// 462 <tkey_wakeup_io_config+0x86>
			switch (i)
     412:	7418      	zextb      	r0, r6
     414:	2800      	subi      	r0, 1
     416:	381e      	cmphsi      	r0, 31
     418:	0822      	bt      	0x45c	// 45c <tkey_wakeup_io_config+0x80>
     41a:	e000097d 	bsr      	0x1714	// 1714 <___gnu_csky_case_uhi>
     41e:	004d      	.short	0x004d
     420:	00570051 	.long	0x00570051
     424:	005e005b 	.long	0x005e005b
     428:	00660061 	.long	0x00660061
     42c:	006d006a 	.long	0x006d006a
     430:	007f0073 	.long	0x007f0073
     434:	00870083 	.long	0x00870083
     438:	00990093 	.long	0x00990093
     43c:	00a0009d 	.long	0x00a0009d
     440:	00a900a3 	.long	0x00a900a3
     444:	00af00ac 	.long	0x00af00ac
     448:	00b800b4 	.long	0x00b800b4
     44c:	00c400be 	.long	0x00c400be
     450:	00cb00c8 	.long	0x00cb00c8
     454:	00d300ce 	.long	0x00d300ce
     458:	00db00d7 	.long	0x00db00d7
				case 0  : 	GPIOA0->CONHR=(GPIOA0->CONHR&0XF0FFFFFF) | 0x00000000;break; 	//PA0.14	TCH0
     45c:	9101      	ld.w      	r0, (r1, 0x4)
     45e:	6811      	andn      	r0, r4
				case 1  : 	GPIOA0->CONHR=(GPIOA0->CONHR&0X0FFFFFFF) | 0x00000000;break; 	//PA0.15	TCH1
     460:	b101      	st.w      	r0, (r1, 0x4)
		if ((dwTkeyWakeupIoEnable & (1<<i))!=0)
     462:	9802      	ld.w      	r0, (r14, 0x8)
     464:	98a0      	ld.w      	r5, (r14, 0x0)
     466:	9000      	ld.w      	r0, (r0, 0x0)
     468:	6940      	and      	r5, r0
     46a:	3d40      	cmpnei      	r5, 0
     46c:	0cbc      	bf      	0x5e4	// 5e4 <tkey_wakeup_io_config+0x208>
		{
			switch (i)
     46e:	7418      	zextb      	r0, r6
     470:	2800      	subi      	r0, 1
     472:	381e      	cmphsi      	r0, 31
     474:	08b3      	bt      	0x5da	// 5da <tkey_wakeup_io_config+0x1fe>
     476:	e000094f 	bsr      	0x1714	// 1714 <___gnu_csky_case_uhi>
     47a:	00bb      	.short	0x00bb
     47c:	00c900c1 	.long	0x00c900c1
     480:	00d600d0 	.long	0x00d600d0
     484:	00e400dc 	.long	0x00e400dc
     488:	00f100ec 	.long	0x00f100ec
     48c:	010800fa 	.long	0x010800fa
     490:	0113010d 	.long	0x0113010d
     494:	01290121 	.long	0x01290121
     498:	01360130 	.long	0x01360130
     49c:	0144013c 	.long	0x0144013c
     4a0:	0163015d 	.long	0x0163015d
     4a4:	0173016b 	.long	0x0173016b
     4a8:	0183017b 	.long	0x0183017b
     4ac:	0190018a 	.long	0x0190018a
     4b0:	019e0196 	.long	0x019e0196
     4b4:	01ac01a5 	.long	0x01ac01a5
				case 1  : 	GPIOA0->CONHR=(GPIOA0->CONHR&0X0FFFFFFF) | 0x00000000;break; 	//PA0.15	TCH1
     4b8:	9101      	ld.w      	r0, (r1, 0x4)
     4ba:	4004      	lsli      	r0, r0, 4
     4bc:	4804      	lsri      	r0, r0, 4
     4be:	07d1      	br      	0x460	// 460 <tkey_wakeup_io_config+0x84>
				case 2  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFFFFFFF0) | 0x00000000;break; 	//PA1.0		TCH2
     4c0:	9300      	ld.w      	r0, (r3, 0x0)
     4c2:	3500      	movi      	r5, 0
     4c4:	2d0f      	subi      	r5, 16
				case 3  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFFFFFF0F) | 0x00000000;break; 	//PA1.1		TCH3
     4c6:	6814      	and      	r0, r5
     4c8:	b300      	st.w      	r0, (r3, 0x0)
     4ca:	07cc      	br      	0x462	// 462 <tkey_wakeup_io_config+0x86>
     4cc:	3500      	movi      	r5, 0
     4ce:	9300      	ld.w      	r0, (r3, 0x0)
     4d0:	2df0      	subi      	r5, 241
     4d2:	07fa      	br      	0x4c6	// 4c6 <tkey_wakeup_io_config+0xea>
				case 4  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFFFFF0FF) | 0x00000000;break; 	//PA1.2		TCH4
     4d4:	9300      	ld.w      	r0, (r3, 0x0)
     4d6:	03aa      	lrw      	r5, 0xfffff0ff	// 728 <tkey_wakeup_io_config+0x34c>
     4d8:	07f7      	br      	0x4c6	// 4c6 <tkey_wakeup_io_config+0xea>
				case 5  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFFFF0FFF) | 0x00000000;break; 	//PA1.3		TCH5
     4da:	9300      	ld.w      	r0, (r3, 0x0)
     4dc:	03ab      	lrw      	r5, 0xffff0fff	// 72c <tkey_wakeup_io_config+0x350>
     4de:	07f4      	br      	0x4c6	// 4c6 <tkey_wakeup_io_config+0xea>
				case 6  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFFF0FFFF) | 0x00000000;break; 	//PA1.4		TCH6
     4e0:	9300      	ld.w      	r0, (r3, 0x0)
     4e2:	ea25fff1 	movih      	r5, 65521
				case 7  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFF0FFFFF) | 0x00000000;break; 	//PA1.5		TCH7
     4e6:	2d00      	subi      	r5, 1
     4e8:	07ef      	br      	0x4c6	// 4c6 <tkey_wakeup_io_config+0xea>
     4ea:	9300      	ld.w      	r0, (r3, 0x0)
     4ec:	ea25ff10 	movih      	r5, 65296
     4f0:	07fb      	br      	0x4e6	// 4e6 <tkey_wakeup_io_config+0x10a>
				case 8  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XF0FFFFFF) | 0x00000000;break; 	//PA1.6		TCH8
     4f2:	9300      	ld.w      	r0, (r3, 0x0)
     4f4:	6811      	andn      	r0, r4
     4f6:	07e9      	br      	0x4c8	// 4c8 <tkey_wakeup_io_config+0xec>
				case 9  : 	GPIOB0->CONLR=(GPIOB0->CONLR&0XFF0FFFFF) | 0x00000000;break; 	//PB0.5		TCH9
     4f8:	9200      	ld.w      	r0, (r2, 0x0)
     4fa:	ea25ff10 	movih      	r5, 65296
     4fe:	2d00      	subi      	r5, 1
				case 31 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFFF0FF) | 0x00000000;break; 	//PB0.2		TCH31
     500:	6814      	and      	r0, r5
     502:	040f      	br      	0x520	// 520 <tkey_wakeup_io_config+0x144>
				case 10 : 	*(uint32_t *)(0x40011128) = 0x5a;
     504:	0314      	lrw      	r0, 0x40011100	// 730 <tkey_wakeup_io_config+0x354>
     506:	355a      	movi      	r5, 90
     508:	b0aa      	st.w      	r5, (r0, 0x28)
							GPIOA1->CONLR=(GPIOA1->CONLR&0X0FFFFFFF) | 0x00000000;			//PA1.7		TCH10
     50a:	9300      	ld.w      	r0, (r3, 0x0)
     50c:	4004      	lsli      	r0, r0, 4
     50e:	4804      	lsri      	r0, r0, 4
     510:	b300      	st.w      	r0, (r3, 0x0)
							GPIOA1->PUDR &= 0XFFFF3FFF;
     512:	9308      	ld.w      	r0, (r3, 0x20)
     514:	388e      	bclri      	r0, 14
     516:	388f      	bclri      	r0, 15
							GPIOA1->PUDR &= 0XFFFCFFFF;
     518:	b308      	st.w      	r0, (r3, 0x20)
					break; 
     51a:	07a4      	br      	0x462	// 462 <tkey_wakeup_io_config+0x86>
				case 11 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XF0FFFFFF) | 0x00000000;break; 	//PB0.6		TCH11
     51c:	9200      	ld.w      	r0, (r2, 0x0)
     51e:	6811      	andn      	r0, r4
				case 31 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFFF0FF) | 0x00000000;break; 	//PB0.2		TCH31
     520:	b200      	st.w      	r0, (r2, 0x0)
     522:	07a0      	br      	0x462	// 462 <tkey_wakeup_io_config+0x86>
				case 12 :	GPIOB0->CONLR=(GPIOB0->CONLR&0X0FFFFFFF) | 0x00000000;break; 	//PB0.7		TCH12
     524:	9200      	ld.w      	r0, (r2, 0x0)
     526:	4004      	lsli      	r0, r0, 4
     528:	4804      	lsri      	r0, r0, 4
     52a:	07fb      	br      	0x520	// 520 <tkey_wakeup_io_config+0x144>
				case 13 :	*(uint32_t *)(0x40011128) = 0x5a;
     52c:	031e      	lrw      	r0, 0x40011100	// 730 <tkey_wakeup_io_config+0x354>
     52e:	355a      	movi      	r5, 90
     530:	b0aa      	st.w      	r5, (r0, 0x28)
							GPIOA1->CONHR=(GPIOA1->CONHR&0XFFFFFFF0) | 0x00000000;			//PA1.8		TCH13
     532:	3500      	movi      	r5, 0
     534:	9301      	ld.w      	r0, (r3, 0x4)
     536:	2d0f      	subi      	r5, 16
     538:	6814      	and      	r0, r5
     53a:	b301      	st.w      	r0, (r3, 0x4)
							GPIOA1->PUDR &= 0XFFFCFFFF;
     53c:	9308      	ld.w      	r0, (r3, 0x20)
     53e:	3890      	bclri      	r0, 16
     540:	3891      	bclri      	r0, 17
     542:	07eb      	br      	0x518	// 518 <tkey_wakeup_io_config+0x13c>
				case 14 :	GPIOB0->CONHR=(GPIOB0->CONHR&0XFFFFFFF0) | 0x00000000;break; 	//PB0.8		TCH14
     544:	9201      	ld.w      	r0, (r2, 0x4)
     546:	3500      	movi      	r5, 0
     548:	2d0f      	subi      	r5, 16
				case 17 :	GPIOB0->CONHR=(GPIOB0->CONHR&0XFFFF0FFF) | 0x00000000;break; 	//PB0.11	TCH17
     54a:	6814      	and      	r0, r5
     54c:	b201      	st.w      	r0, (r2, 0x4)
     54e:	078a      	br      	0x462	// 462 <tkey_wakeup_io_config+0x86>
				case 15 :	GPIOB0->CONHR=(GPIOB0->CONHR&0XFFFFFF0F) | 0x00000000;break; 	//PB0.9		TCH15
     550:	3500      	movi      	r5, 0
     552:	9201      	ld.w      	r0, (r2, 0x4)
     554:	2df0      	subi      	r5, 241
     556:	07fa      	br      	0x54a	// 54a <tkey_wakeup_io_config+0x16e>
				case 16 :	GPIOB0->CONHR=(GPIOB0->CONHR&0XFFFFF0FF) | 0x00000000;break; 	//PB0.10	TCH16
     558:	9201      	ld.w      	r0, (r2, 0x4)
     55a:	13b4      	lrw      	r5, 0xfffff0ff	// 728 <tkey_wakeup_io_config+0x34c>
     55c:	07f7      	br      	0x54a	// 54a <tkey_wakeup_io_config+0x16e>
				case 17 :	GPIOB0->CONHR=(GPIOB0->CONHR&0XFFFF0FFF) | 0x00000000;break; 	//PB0.11	TCH17
     55e:	9201      	ld.w      	r0, (r2, 0x4)
     560:	13b3      	lrw      	r5, 0xffff0fff	// 72c <tkey_wakeup_io_config+0x350>
     562:	07f4      	br      	0x54a	// 54a <tkey_wakeup_io_config+0x16e>
				case 18 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFFFFFF0F) | 0x00000000;break; 	//PA1.9		TCH18
     564:	9301      	ld.w      	r0, (r3, 0x4)
     566:	3500      	movi      	r5, 0
     568:	2df0      	subi      	r5, 241
				case 22 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFF0FFFFF) | 0x00000000;break; 	//PA1.13	TCH22
     56a:	6814      	and      	r0, r5
     56c:	b301      	st.w      	r0, (r3, 0x4)
     56e:	077a      	br      	0x462	// 462 <tkey_wakeup_io_config+0x86>
				case 19 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFFFFF0FF) | 0x00000000;break; 	//PA1.10	TCH19
     570:	9301      	ld.w      	r0, (r3, 0x4)
     572:	13ae      	lrw      	r5, 0xfffff0ff	// 728 <tkey_wakeup_io_config+0x34c>
     574:	07fb      	br      	0x56a	// 56a <tkey_wakeup_io_config+0x18e>
				case 20 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFFFF0FFF) | 0x00000000;break; 	//PA1.11	TCH20
     576:	9301      	ld.w      	r0, (r3, 0x4)
     578:	13ad      	lrw      	r5, 0xffff0fff	// 72c <tkey_wakeup_io_config+0x350>
     57a:	07f8      	br      	0x56a	// 56a <tkey_wakeup_io_config+0x18e>
				case 21 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFFF0FFFF) | 0x00000000;break; 	//PA1.12	TCH21
     57c:	9301      	ld.w      	r0, (r3, 0x4)
     57e:	ea25fff1 	movih      	r5, 65521
				case 22 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFF0FFFFF) | 0x00000000;break; 	//PA1.13	TCH22
     582:	2d00      	subi      	r5, 1
     584:	07f3      	br      	0x56a	// 56a <tkey_wakeup_io_config+0x18e>
     586:	9301      	ld.w      	r0, (r3, 0x4)
     588:	ea25ff10 	movih      	r5, 65296
     58c:	07fb      	br      	0x582	// 582 <tkey_wakeup_io_config+0x1a6>
				case 23 :	GPIOC0->CONLR=(GPIOC0->CONLR&0XFFFFFFF0) | 0x00000000;break; 	//PC0.0		TCH23
     58e:	9700      	ld.w      	r0, (r7, 0x0)
     590:	3500      	movi      	r5, 0
     592:	2d0f      	subi      	r5, 16
     594:	6814      	and      	r0, r5
     596:	b700      	st.w      	r0, (r7, 0x0)
     598:	0765      	br      	0x462	// 462 <tkey_wakeup_io_config+0x86>
				case 24 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFFFFFF0) | 0x00000000;break; 	//PA0.0		TCH24
     59a:	9100      	ld.w      	r0, (r1, 0x0)
     59c:	3500      	movi      	r5, 0
     59e:	2d0f      	subi      	r5, 16
				case 28 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFF0FFFF) | 0x00000000;break; 	//PA0.4		TCH28
     5a0:	6814      	and      	r0, r5
     5a2:	b100      	st.w      	r0, (r1, 0x0)
     5a4:	075f      	br      	0x462	// 462 <tkey_wakeup_io_config+0x86>
				case 25 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFFFFF0F) | 0x00000000;break; 	//PA0.1		TCH25
     5a6:	3500      	movi      	r5, 0
     5a8:	9100      	ld.w      	r0, (r1, 0x0)
     5aa:	2df0      	subi      	r5, 241
     5ac:	07fa      	br      	0x5a0	// 5a0 <tkey_wakeup_io_config+0x1c4>
				case 26 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFFFF0FF) | 0x00000000;break; 	//PA0.2		TCH26
     5ae:	9100      	ld.w      	r0, (r1, 0x0)
     5b0:	12be      	lrw      	r5, 0xfffff0ff	// 728 <tkey_wakeup_io_config+0x34c>
     5b2:	07f7      	br      	0x5a0	// 5a0 <tkey_wakeup_io_config+0x1c4>
				case 27 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFFF0FFF) | 0x00000000;break; 	//PA0.3		TCH27
     5b4:	9100      	ld.w      	r0, (r1, 0x0)
     5b6:	12be      	lrw      	r5, 0xffff0fff	// 72c <tkey_wakeup_io_config+0x350>
     5b8:	07f4      	br      	0x5a0	// 5a0 <tkey_wakeup_io_config+0x1c4>
				case 28 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFF0FFFF) | 0x00000000;break; 	//PA0.4		TCH28
     5ba:	ea25fff1 	movih      	r5, 65521
     5be:	9100      	ld.w      	r0, (r1, 0x0)
     5c0:	2d00      	subi      	r5, 1
     5c2:	07ef      	br      	0x5a0	// 5a0 <tkey_wakeup_io_config+0x1c4>
				case 29 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFFFFF0) | 0x00000000;break; 	//PB0.0		TCH29
     5c4:	3500      	movi      	r5, 0
     5c6:	9200      	ld.w      	r0, (r2, 0x0)
     5c8:	2d0f      	subi      	r5, 16
     5ca:	079b      	br      	0x500	// 500 <tkey_wakeup_io_config+0x124>
				case 30 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFFFF0F) | 0x00000000;break; 	//PB0.1		TCH30
     5cc:	3500      	movi      	r5, 0
     5ce:	9200      	ld.w      	r0, (r2, 0x0)
     5d0:	2df0      	subi      	r5, 241
     5d2:	0797      	br      	0x500	// 500 <tkey_wakeup_io_config+0x124>
				case 31 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFFF0FF) | 0x00000000;break; 	//PB0.2		TCH31
     5d4:	9200      	ld.w      	r0, (r2, 0x0)
     5d6:	12b5      	lrw      	r5, 0xfffff0ff	// 728 <tkey_wakeup_io_config+0x34c>
     5d8:	0794      	br      	0x500	// 500 <tkey_wakeup_io_config+0x124>
			{
				case 0  : 	GPIOA0->CONHR=(GPIOA0->CONHR&0XF0FFFFFF) | 0x0A000000;break; 	//PA0.14	TCH0
     5da:	9101      	ld.w      	r0, (r1, 0x4)
     5dc:	6811      	andn      	r0, r4
     5de:	38b9      	bseti      	r0, 25
     5e0:	38bb      	bseti      	r0, 27
				case 1  : 	GPIOA0->CONHR=(GPIOA0->CONHR&0X0FFFFFFF) | 0xA0000000;break; 	//PA0.15	TCH1
     5e2:	b101      	st.w      	r0, (r1, 0x4)
     5e4:	2600      	addi      	r6, 1
	for (i=0;i<32;i++)
     5e6:	eb460020 	cmpnei      	r6, 32
     5ea:	0b0a      	bt      	0x3fe	// 3fe <tkey_wakeup_io_config+0x22>
				case 31 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFFF0FF) | 0x00000A00;break; 	//PB0.2		TCH31
				default : break;
			}
		}
	}
}
     5ec:	1403      	addi      	r14, r14, 12
     5ee:	1494      	pop      	r4-r7, r15
				case 1  : 	GPIOA0->CONHR=(GPIOA0->CONHR&0X0FFFFFFF) | 0xA0000000;break; 	//PA0.15	TCH1
     5f0:	9101      	ld.w      	r0, (r1, 0x4)
     5f2:	4004      	lsli      	r0, r0, 4
     5f4:	4804      	lsri      	r0, r0, 4
     5f6:	38bd      	bseti      	r0, 29
     5f8:	38bf      	bseti      	r0, 31
     5fa:	07f4      	br      	0x5e2	// 5e2 <tkey_wakeup_io_config+0x206>
				case 2  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFFFFFFF0) | 0x0000000A;break; 	//PA1.0		TCH2
     5fc:	9300      	ld.w      	r0, (r3, 0x0)
     5fe:	3500      	movi      	r5, 0
     600:	2d0f      	subi      	r5, 16
     602:	6814      	and      	r0, r5
     604:	ec00000a 	ori      	r0, r0, 10
				case 3  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFFFFFF0F) | 0x000000A0;break; 	//PA1.1		TCH3
     608:	b300      	st.w      	r0, (r3, 0x0)
     60a:	07ed      	br      	0x5e4	// 5e4 <tkey_wakeup_io_config+0x208>
     60c:	9300      	ld.w      	r0, (r3, 0x0)
     60e:	3500      	movi      	r5, 0
     610:	2df0      	subi      	r5, 241
     612:	6814      	and      	r0, r5
     614:	ec0000a0 	ori      	r0, r0, 160
     618:	07f8      	br      	0x608	// 608 <tkey_wakeup_io_config+0x22c>
				case 4  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFFFFF0FF) | 0x00000A00;break; 	//PA1.2		TCH4
     61a:	9300      	ld.w      	r0, (r3, 0x0)
     61c:	12a3      	lrw      	r5, 0xfffff0ff	// 728 <tkey_wakeup_io_config+0x34c>
     61e:	6814      	and      	r0, r5
     620:	ec000a00 	ori      	r0, r0, 2560
     624:	07f2      	br      	0x608	// 608 <tkey_wakeup_io_config+0x22c>
				case 5  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFFFF0FFF) | 0x0000A000;break; 	//PA1.3		TCH5
     626:	9300      	ld.w      	r0, (r3, 0x0)
     628:	12a1      	lrw      	r5, 0xffff0fff	// 72c <tkey_wakeup_io_config+0x350>
     62a:	6814      	and      	r0, r5
     62c:	ec00a000 	ori      	r0, r0, 40960
     630:	07ec      	br      	0x608	// 608 <tkey_wakeup_io_config+0x22c>
				case 6  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFFF0FFFF) | 0x000A0000;break; 	//PA1.4		TCH6
     632:	9300      	ld.w      	r0, (r3, 0x0)
     634:	ea25fff1 	movih      	r5, 65521
     638:	2d00      	subi      	r5, 1
     63a:	6814      	and      	r0, r5
     63c:	38b1      	bseti      	r0, 17
     63e:	38b3      	bseti      	r0, 19
     640:	07e4      	br      	0x608	// 608 <tkey_wakeup_io_config+0x22c>
				case 7  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XFF0FFFFF) | 0x00A00000;break; 	//PA1.5		TCH7
     642:	9300      	ld.w      	r0, (r3, 0x0)
     644:	ea25ff10 	movih      	r5, 65296
     648:	2d00      	subi      	r5, 1
     64a:	6814      	and      	r0, r5
     64c:	38b5      	bseti      	r0, 21
     64e:	38b7      	bseti      	r0, 23
     650:	07dc      	br      	0x608	// 608 <tkey_wakeup_io_config+0x22c>
				case 8  : 	GPIOA1->CONLR=(GPIOA1->CONLR&0XF0FFFFFF) | 0x0A000000;break; 	//PA1.6		TCH8
     652:	9300      	ld.w      	r0, (r3, 0x0)
     654:	6811      	andn      	r0, r4
     656:	38b9      	bseti      	r0, 25
     658:	38bb      	bseti      	r0, 27
     65a:	07d7      	br      	0x608	// 608 <tkey_wakeup_io_config+0x22c>
				case 9  : 	GPIOB0->CONLR=(GPIOB0->CONLR&0XFF0FFFFF) | 0x00A00000;break; 	//PB0.5		TCH9
     65c:	9200      	ld.w      	r0, (r2, 0x0)
     65e:	ea25ff10 	movih      	r5, 65296
     662:	2d00      	subi      	r5, 1
     664:	6814      	and      	r0, r5
     666:	38b5      	bseti      	r0, 21
     668:	38b7      	bseti      	r0, 23
				case 31 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFFF0FF) | 0x00000A00;break; 	//PB0.2		TCH31
     66a:	b200      	st.w      	r0, (r2, 0x0)
     66c:	07bc      	br      	0x5e4	// 5e4 <tkey_wakeup_io_config+0x208>
				case 10 : 	*(uint32_t *)(0x40011128) = 0x5a;
     66e:	1111      	lrw      	r0, 0x40011100	// 730 <tkey_wakeup_io_config+0x354>
     670:	355a      	movi      	r5, 90
     672:	b0aa      	st.w      	r5, (r0, 0x28)
							GPIOA1->CONLR=(GPIOA1->CONLR&0X0FFFFFFF) | 0xA0000000;			//PA1.7		TCH10
     674:	9300      	ld.w      	r0, (r3, 0x0)
     676:	4004      	lsli      	r0, r0, 4
     678:	4804      	lsri      	r0, r0, 4
     67a:	38bd      	bseti      	r0, 29
     67c:	38bf      	bseti      	r0, 31
     67e:	b300      	st.w      	r0, (r3, 0x0)
							GPIOA1->PUDR &= 0XFFFF3FFF;
     680:	9308      	ld.w      	r0, (r3, 0x20)
     682:	388e      	bclri      	r0, 14
     684:	388f      	bclri      	r0, 15
							GPIOA1->PUDR &= 0XFFFCFFFF;
     686:	b308      	st.w      	r0, (r3, 0x20)
					break; 
     688:	07ae      	br      	0x5e4	// 5e4 <tkey_wakeup_io_config+0x208>
				case 11 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XF0FFFFFF) | 0x0A000000;break; 	//PB0.6		TCH11
     68a:	9200      	ld.w      	r0, (r2, 0x0)
     68c:	6811      	andn      	r0, r4
     68e:	38b9      	bseti      	r0, 25
     690:	38bb      	bseti      	r0, 27
     692:	07ec      	br      	0x66a	// 66a <tkey_wakeup_io_config+0x28e>
				case 12 :	GPIOB0->CONLR=(GPIOB0->CONLR&0X0FFFFFFF) | 0xA0000000;break; 	//PB0.7		TCH12
     694:	9200      	ld.w      	r0, (r2, 0x0)
     696:	4004      	lsli      	r0, r0, 4
     698:	4804      	lsri      	r0, r0, 4
     69a:	38bd      	bseti      	r0, 29
     69c:	38bf      	bseti      	r0, 31
     69e:	07e6      	br      	0x66a	// 66a <tkey_wakeup_io_config+0x28e>
				case 13 :	*(uint32_t *)(0x40011128) = 0x5a;
     6a0:	1104      	lrw      	r0, 0x40011100	// 730 <tkey_wakeup_io_config+0x354>
     6a2:	355a      	movi      	r5, 90
     6a4:	b0aa      	st.w      	r5, (r0, 0x28)
							GPIOA1->CONHR=(GPIOA1->CONHR&0XFFFFFFF0) | 0x0000000A;			//PA1.8		TCH13
     6a6:	3500      	movi      	r5, 0
     6a8:	9301      	ld.w      	r0, (r3, 0x4)
     6aa:	2d0f      	subi      	r5, 16
     6ac:	6814      	and      	r0, r5
     6ae:	ec00000a 	ori      	r0, r0, 10
     6b2:	b301      	st.w      	r0, (r3, 0x4)
							GPIOA1->PUDR &= 0XFFFCFFFF;
     6b4:	9308      	ld.w      	r0, (r3, 0x20)
     6b6:	3890      	bclri      	r0, 16
     6b8:	3891      	bclri      	r0, 17
     6ba:	07e6      	br      	0x686	// 686 <tkey_wakeup_io_config+0x2aa>
				case 14 :	GPIOB0->CONHR=(GPIOB0->CONHR&0XFFFFFFF0) | 0x0000000A;break; 	//PB0.8		TCH14
     6bc:	9201      	ld.w      	r0, (r2, 0x4)
     6be:	3500      	movi      	r5, 0
     6c0:	2d0f      	subi      	r5, 16
     6c2:	6814      	and      	r0, r5
     6c4:	ec00000a 	ori      	r0, r0, 10
				case 17 :	GPIOB0->CONHR=(GPIOB0->CONHR&0XFFFF0FFF) | 0x0000A000;break; 	//PB0.11	TCH17
     6c8:	b201      	st.w      	r0, (r2, 0x4)
     6ca:	078d      	br      	0x5e4	// 5e4 <tkey_wakeup_io_config+0x208>
				case 15 :	GPIOB0->CONHR=(GPIOB0->CONHR&0XFFFFFF0F) | 0x000000A0;break; 	//PB0.9		TCH15
     6cc:	9201      	ld.w      	r0, (r2, 0x4)
     6ce:	3500      	movi      	r5, 0
     6d0:	2df0      	subi      	r5, 241
     6d2:	6814      	and      	r0, r5
     6d4:	ec0000a0 	ori      	r0, r0, 160
     6d8:	07f8      	br      	0x6c8	// 6c8 <tkey_wakeup_io_config+0x2ec>
				case 16 :	GPIOB0->CONHR=(GPIOB0->CONHR&0XFFFFF0FF) | 0x00000A00;break; 	//PB0.10	TCH16
     6da:	9201      	ld.w      	r0, (r2, 0x4)
     6dc:	10b3      	lrw      	r5, 0xfffff0ff	// 728 <tkey_wakeup_io_config+0x34c>
     6de:	6814      	and      	r0, r5
     6e0:	ec000a00 	ori      	r0, r0, 2560
     6e4:	07f2      	br      	0x6c8	// 6c8 <tkey_wakeup_io_config+0x2ec>
				case 17 :	GPIOB0->CONHR=(GPIOB0->CONHR&0XFFFF0FFF) | 0x0000A000;break; 	//PB0.11	TCH17
     6e6:	9201      	ld.w      	r0, (r2, 0x4)
     6e8:	10b1      	lrw      	r5, 0xffff0fff	// 72c <tkey_wakeup_io_config+0x350>
     6ea:	6814      	and      	r0, r5
     6ec:	ec00a000 	ori      	r0, r0, 40960
     6f0:	07ec      	br      	0x6c8	// 6c8 <tkey_wakeup_io_config+0x2ec>
				case 18 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFFFFFF0F) | 0x000000A0;break; 	//PA1.9		TCH18
     6f2:	9301      	ld.w      	r0, (r3, 0x4)
     6f4:	3500      	movi      	r5, 0
     6f6:	2df0      	subi      	r5, 241
     6f8:	6814      	and      	r0, r5
     6fa:	ec0000a0 	ori      	r0, r0, 160
				case 22 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFF0FFFFF) | 0x00A00000;break; 	//PA1.13	TCH22
     6fe:	b301      	st.w      	r0, (r3, 0x4)
     700:	0772      	br      	0x5e4	// 5e4 <tkey_wakeup_io_config+0x208>
				case 19 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFFFFF0FF) | 0x00000A00;break; 	//PA1.10	TCH19
     702:	9301      	ld.w      	r0, (r3, 0x4)
     704:	10a9      	lrw      	r5, 0xfffff0ff	// 728 <tkey_wakeup_io_config+0x34c>
     706:	6814      	and      	r0, r5
     708:	ec000a00 	ori      	r0, r0, 2560
     70c:	07f9      	br      	0x6fe	// 6fe <tkey_wakeup_io_config+0x322>
     70e:	0000      	bkpt
     710:	20000080 	.long	0x20000080
     714:	200004f0 	.long	0x200004f0
     718:	20000088 	.long	0x20000088
     71c:	200004f8 	.long	0x200004f8
     720:	2000007c 	.long	0x2000007c
     724:	20000084 	.long	0x20000084
     728:	fffff0ff 	.long	0xfffff0ff
     72c:	ffff0fff 	.long	0xffff0fff
     730:	40011100 	.long	0x40011100
				case 20 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFFFF0FFF) | 0x0000A000;break; 	//PA1.11	TCH20
     734:	9301      	ld.w      	r0, (r3, 0x4)
     736:	01a3      	lrw      	r5, 0xffff0fff	// aa4 <tkey_baseline_tracking+0x48>
     738:	6814      	and      	r0, r5
     73a:	ec00a000 	ori      	r0, r0, 40960
     73e:	07e0      	br      	0x6fe	// 6fe <tkey_wakeup_io_config+0x322>
				case 21 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFFF0FFFF) | 0x000A0000;break; 	//PA1.12	TCH21
     740:	9301      	ld.w      	r0, (r3, 0x4)
     742:	ea25fff1 	movih      	r5, 65521
     746:	2d00      	subi      	r5, 1
     748:	6814      	and      	r0, r5
     74a:	38b1      	bseti      	r0, 17
     74c:	38b3      	bseti      	r0, 19
     74e:	07d8      	br      	0x6fe	// 6fe <tkey_wakeup_io_config+0x322>
				case 22 :	GPIOA1->CONHR=(GPIOA1->CONHR&0XFF0FFFFF) | 0x00A00000;break; 	//PA1.13	TCH22
     750:	9301      	ld.w      	r0, (r3, 0x4)
     752:	ea25ff10 	movih      	r5, 65296
     756:	2d00      	subi      	r5, 1
     758:	6814      	and      	r0, r5
     75a:	38b5      	bseti      	r0, 21
     75c:	38b7      	bseti      	r0, 23
     75e:	07d0      	br      	0x6fe	// 6fe <tkey_wakeup_io_config+0x322>
				case 23 :	GPIOC0->CONLR=(GPIOC0->CONLR&0XFFFFFFF0) | 0x0000000A;break; 	//PC0.0		TCH23
     760:	9700      	ld.w      	r0, (r7, 0x0)
     762:	3500      	movi      	r5, 0
     764:	2d0f      	subi      	r5, 16
     766:	6814      	and      	r0, r5
     768:	ec00000a 	ori      	r0, r0, 10
     76c:	b700      	st.w      	r0, (r7, 0x0)
     76e:	073b      	br      	0x5e4	// 5e4 <tkey_wakeup_io_config+0x208>
				case 24 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFFFFFF0) | 0x0000000A;break; 	//PA0.0		TCH24
     770:	9100      	ld.w      	r0, (r1, 0x0)
     772:	3500      	movi      	r5, 0
     774:	2d0f      	subi      	r5, 16
     776:	6814      	and      	r0, r5
     778:	ec00000a 	ori      	r0, r0, 10
				case 28 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFF0FFFF) | 0x000A0000;break; 	//PA0.4		TCH28
     77c:	b100      	st.w      	r0, (r1, 0x0)
     77e:	0733      	br      	0x5e4	// 5e4 <tkey_wakeup_io_config+0x208>
				case 25 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFFFFF0F) | 0x000000A0;break; 	//PA0.1		TCH25
     780:	9100      	ld.w      	r0, (r1, 0x0)
     782:	3500      	movi      	r5, 0
     784:	2df0      	subi      	r5, 241
     786:	6814      	and      	r0, r5
     788:	ec0000a0 	ori      	r0, r0, 160
     78c:	07f8      	br      	0x77c	// 77c <tkey_wakeup_io_config+0x3a0>
				case 26 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFFFF0FF) | 0x00000A00;break; 	//PA0.2		TCH26
     78e:	9100      	ld.w      	r0, (r1, 0x0)
     790:	01b9      	lrw      	r5, 0xfffff0ff	// aa8 <tkey_baseline_tracking+0x4c>
     792:	6814      	and      	r0, r5
     794:	ec000a00 	ori      	r0, r0, 2560
     798:	07f2      	br      	0x77c	// 77c <tkey_wakeup_io_config+0x3a0>
				case 27 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFFF0FFF) | 0x0000A000;break; 	//PA0.3		TCH27
     79a:	9100      	ld.w      	r0, (r1, 0x0)
     79c:	01bd      	lrw      	r5, 0xffff0fff	// aa4 <tkey_baseline_tracking+0x48>
     79e:	6814      	and      	r0, r5
     7a0:	ec00a000 	ori      	r0, r0, 40960
     7a4:	07ec      	br      	0x77c	// 77c <tkey_wakeup_io_config+0x3a0>
				case 28 :	GPIOA0->CONLR=(GPIOA0->CONLR&0XFFF0FFFF) | 0x000A0000;break; 	//PA0.4		TCH28
     7a6:	9100      	ld.w      	r0, (r1, 0x0)
     7a8:	ea25fff1 	movih      	r5, 65521
     7ac:	2d00      	subi      	r5, 1
     7ae:	6814      	and      	r0, r5
     7b0:	38b1      	bseti      	r0, 17
     7b2:	38b3      	bseti      	r0, 19
     7b4:	07e4      	br      	0x77c	// 77c <tkey_wakeup_io_config+0x3a0>
				case 29 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFFFFF0) | 0x0000000A;break; 	//PB0.0		TCH29
     7b6:	9200      	ld.w      	r0, (r2, 0x0)
     7b8:	3500      	movi      	r5, 0
     7ba:	2d0f      	subi      	r5, 16
     7bc:	6814      	and      	r0, r5
     7be:	ec00000a 	ori      	r0, r0, 10
     7c2:	0754      	br      	0x66a	// 66a <tkey_wakeup_io_config+0x28e>
				case 30 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFFFF0F) | 0x000000A0;break; 	//PB0.1		TCH30
     7c4:	9200      	ld.w      	r0, (r2, 0x0)
     7c6:	3500      	movi      	r5, 0
     7c8:	2df0      	subi      	r5, 241
     7ca:	6814      	and      	r0, r5
     7cc:	ec0000a0 	ori      	r0, r0, 160
     7d0:	074d      	br      	0x66a	// 66a <tkey_wakeup_io_config+0x28e>
				case 31 :	GPIOB0->CONLR=(GPIOB0->CONLR&0XFFFFF0FF) | 0x00000A00;break; 	//PB0.2		TCH31
     7d2:	9200      	ld.w      	r0, (r2, 0x0)
     7d4:	02aa      	lrw      	r5, 0xfffff0ff	// aa8 <tkey_baseline_tracking+0x4c>
     7d6:	6814      	and      	r0, r5
     7d8:	ec000a00 	ori      	r0, r0, 2560
     7dc:	0747      	br      	0x66a	// 66a <tkey_wakeup_io_config+0x28e>

000007de <tkey_pwrsrc_config>:
/****************************************************
//TK power source configure
*****************************************************/
void tkey_pwrsrc_config(void)
{
	if(hwTkeyPselMode==TK_PWRSRC_FVR)
     7de:	026b      	lrw      	r3, 0x20000650	// aac <tkey_baseline_tracking+0x50>
     7e0:	8b60      	ld.h      	r3, (r3, 0x0)
     7e2:	74cd      	zexth      	r3, r3
     7e4:	3b40      	cmpnei      	r3, 0
     7e6:	0822      	bt      	0x82a	// 82a <tkey_pwrsrc_config+0x4c>
	{
		GPIOA0_CONLR = (GPIOA0_CONLR&0XFFFFFFF0)  | 0x0000000A;	
     7e8:	32c0      	movi      	r2, 192
     7ea:	4257      	lsli      	r2, r2, 23
     7ec:	9260      	ld.w      	r3, (r2, 0x0)
     7ee:	3100      	movi      	r1, 0
     7f0:	290f      	subi      	r1, 16
     7f2:	68c4      	and      	r3, r1
     7f4:	ec63000a 	ori      	r3, r3, 10
     7f8:	b260      	st.w      	r3, (r2, 0x0)
		ADC0_ECR=2;
     7fa:	3302      	movi      	r3, 2
     7fc:	ea224003 	movih      	r2, 16387
     800:	b260      	st.w      	r3, (r2, 0x0)
		if(hwTkeyFvrLevel==TK_FVR_4096V)
     802:	0273      	lrw      	r3, 0x2000036e	// ab0 <tkey_baseline_tracking+0x54>
     804:	8b20      	ld.h      	r1, (r3, 0x0)
     806:	7445      	zexth      	r1, r1
     808:	3941      	cmpnei      	r1, 1
     80a:	0805      	bt      	0x814	// 814 <tkey_pwrsrc_config+0x36>
		{					
			 ADC0_CR=( ADC0_CR&0xfcffffff)|(0X01<<24)|(0X01<<25);
     80c:	9224      	ld.w      	r1, (r2, 0x10)
     80e:	39b8      	bseti      	r1, 24
     810:	39b9      	bseti      	r1, 25
     812:	b224      	st.w      	r1, (r2, 0x10)
		}
		if(hwTkeyFvrLevel==TK_FVR_2048V)
     814:	8b60      	ld.h      	r3, (r3, 0x0)
     816:	74cd      	zexth      	r3, r3
     818:	3b40      	cmpnei      	r3, 0
     81a:	0808      	bt      	0x82a	// 82a <tkey_pwrsrc_config+0x4c>
		{
			 ADC0_CR=( ADC0_CR&0xfcffffff)|(0X01<<24)|(0X00<<25);
     81c:	ea224003 	movih      	r2, 16387
     820:	9264      	ld.w      	r3, (r2, 0x10)
     822:	3b98      	bclri      	r3, 24
     824:	3b99      	bclri      	r3, 25
     826:	3bb8      	bseti      	r3, 24
     828:	b264      	st.w      	r3, (r2, 0x10)
		}
	}
}
     82a:	783c      	jmp      	r15

0000082c <get_key_seq>:
/****************************************************
//TK get key seq
*****************************************************/
unsigned char get_key_seq(unsigned long key_seq)
{                  
     82c:	14c3      	push      	r4-r6
    int count = 0;
    int i = 0,j=0;
     82e:	3200      	movi      	r2, 0
    int count = 0;
     830:	3300      	movi      	r3, 0
    for (; i<32; i++)
    {
        if (((key_seq >> i) & 1) == 1)
     832:	3401      	movi      	r4, 1
		{
            count++;
			byTk_seque[j]=i;
     834:	02bf      	lrw      	r5, 0x20000525	// ab4 <tkey_baseline_tracking+0x58>
        if (((key_seq >> i) & 1) == 1)
     836:	c4404041 	lsr      	r1, r0, r2
     83a:	6850      	and      	r1, r4
     83c:	3940      	cmpnei      	r1, 0
     83e:	0c05      	bf      	0x848	// 848 <get_key_seq+0x1c>
			byTk_seque[j]=i;
     840:	7448      	zextb      	r1, r2
     842:	5dcc      	addu      	r6, r5, r3
     844:	a620      	st.b      	r1, (r6, 0x0)
            count++;
     846:	2300      	addi      	r3, 1
    for (; i<32; i++)
     848:	2200      	addi      	r2, 1
     84a:	eb420020 	cmpnei      	r2, 32
     84e:	0bf4      	bt      	0x836	// 836 <get_key_seq+0xa>
			j++;
		}
    }
    return count;
     850:	740c      	zextb      	r0, r3
}
     852:	1483      	pop      	r4-r6

00000854 <tkey_baseline_prog>:
/****************************************************
//TK baseline program
*****************************************************/
void tkey_baseline_prog(void)
{
     854:	14c4      	push      	r4-r7
     856:	1421      	subi      	r14, r14, 4
	unsigned char i,k;
	for(k=0;k<10;k++)
	{
		for (i=0;i<byTk_num;i++)
		{
			hwBaseline_data0[(TKEYA->TCH_DAT[i]&0xff000000)>>24]=TKEYA->TCH_DAT[i]&0X00FFFFFF;
     858:	0367      	lrw      	r3, 0x200000ac	// ab8 <tkey_baseline_tracking+0x5c>
     85a:	300a      	movi      	r0, 10
     85c:	93a0      	ld.w      	r5, (r3, 0x0)
		for (i=0;i<byTk_num;i++)
     85e:	03c7      	lrw      	r6, 0x200003b2	// abc <tkey_baseline_tracking+0x60>
			hwBaseline_data0[(TKEYA->TCH_DAT[i]&0xff000000)>>24]=TKEYA->TCH_DAT[i]&0X00FFFFFF;
     860:	03e7      	lrw      	r7, 0x20000328	// ac0 <tkey_baseline_tracking+0x64>
			hwSampling_data0[(TKEYA->TCH_DAT[i]&0xff000000)>>24]=TKEYA->TCH_DAT[i]&0X00FFFFFF;
     862:	0366      	lrw      	r3, 0x20000466	// ac4 <tkey_baseline_tracking+0x68>
{
     864:	3200      	movi      	r2, 0
			hwSampling_data0[(TKEYA->TCH_DAT[i]&0xff000000)>>24]=TKEYA->TCH_DAT[i]&0X00FFFFFF;
     866:	b860      	st.w      	r3, (r14, 0x0)
     868:	0414      	br      	0x890	// 890 <tkey_baseline_prog+0x3c>
     86a:	4222      	lsli      	r1, r2, 2
     86c:	6054      	addu      	r1, r5
			hwBaseline_data0[(TKEYA->TCH_DAT[i]&0xff000000)>>24]=TKEYA->TCH_DAT[i]&0X00FFFFFF;
     86e:	9160      	ld.w      	r3, (r1, 0x0)
     870:	4b78      	lsri      	r3, r3, 24
     872:	9180      	ld.w      	r4, (r1, 0x0)
     874:	7511      	zexth      	r4, r4
     876:	4361      	lsli      	r3, r3, 1
     878:	60dc      	addu      	r3, r7
     87a:	ab80      	st.h      	r4, (r3, 0x0)
			hwSampling_data0[(TKEYA->TCH_DAT[i]&0xff000000)>>24]=TKEYA->TCH_DAT[i]&0X00FFFFFF;
     87c:	9880      	ld.w      	r4, (r14, 0x0)
     87e:	9160      	ld.w      	r3, (r1, 0x0)
     880:	4b78      	lsri      	r3, r3, 24
     882:	9120      	ld.w      	r1, (r1, 0x0)
     884:	7445      	zexth      	r1, r1
     886:	4361      	lsli      	r3, r3, 1
     888:	60d0      	addu      	r3, r4
		for (i=0;i<byTk_num;i++)
     88a:	2200      	addi      	r2, 1
			hwSampling_data0[(TKEYA->TCH_DAT[i]&0xff000000)>>24]=TKEYA->TCH_DAT[i]&0X00FFFFFF;
     88c:	ab20      	st.h      	r1, (r3, 0x0)
		for (i=0;i<byTk_num;i++)
     88e:	7488      	zextb      	r2, r2
     890:	8660      	ld.b      	r3, (r6, 0x0)
     892:	64c8      	cmphs      	r2, r3
     894:	0feb      	bf      	0x86a	// 86a <tkey_baseline_prog+0x16>
     896:	2800      	subi      	r0, 1
     898:	7400      	zextb      	r0, r0
	for(k=0;k<10;k++)
     89a:	3840      	cmpnei      	r0, 0
     89c:	0be3      	bt      	0x862	// 862 <tkey_baseline_prog+0xe>
		}
	}
}
     89e:	1401      	addi      	r14, r14, 4
     8a0:	1484      	pop      	r4-r7

000008a2 <tkey_timeover_tune>:
}
/****************************************************
//TK Sens Finetuning
*****************************************************/
void tkey_timeover_tune(void)
{
     8a2:	14d4      	push      	r4-r7, r15
     8a4:	1421      	subi      	r14, r14, 4
	unsigned char i=0,u8_cnt=0;
	if((byPoweron_1st_f>=5)&&(bySens_fine_over_f==0))
     8a6:	0356      	lrw      	r2, 0x20000461	// ac8 <tkey_baseline_tracking+0x6c>
     8a8:	8260      	ld.b      	r3, (r2, 0x0)
     8aa:	74cc      	zextb      	r3, r3
     8ac:	3b04      	cmphsi      	r3, 5
     8ae:	0c3a      	bf      	0x922	// 922 <tkey_timeover_tune+0x80>
     8b0:	0318      	lrw      	r0, 0x2000062f	// acc <tkey_baseline_tracking+0x70>
     8b2:	8060      	ld.b      	r3, (r0, 0x0)
     8b4:	3b40      	cmpnei      	r3, 0
     8b6:	0836      	bt      	0x922	// 922 <tkey_timeover_tune+0x80>
	{
		byPoweron_1st_f++;
     8b8:	8260      	ld.b      	r3, (r2, 0x0)
     8ba:	2300      	addi      	r3, 1
     8bc:	74cc      	zextb      	r3, r3
     8be:	a260      	st.b      	r3, (r2, 0x0)
     8c0:	3300      	movi      	r3, 0
	unsigned char i=0,u8_cnt=0;
     8c2:	3200      	movi      	r2, 0
		for (i=0;i<32;i++)
		{
			if((dwTkeyIoEnable & (1<<i))!=0)
     8c4:	03bc      	lrw      	r5, 0x200004f0	// ad0 <tkey_baseline_tracking+0x74>
			{
			if(hwSampling_data0[i]==0)
     8c6:	03df      	lrw      	r6, 0x20000466	// ac4 <tkey_baseline_tracking+0x68>
			{
				if(byTkeyIcon[i]<7)
     8c8:	03fc      	lrw      	r7, 0x200005cd	// ad4 <tkey_baseline_tracking+0x78>
			if((dwTkeyIoEnable & (1<<i))!=0)
     8ca:	3101      	movi      	r1, 1
     8cc:	9580      	ld.w      	r4, (r5, 0x0)
     8ce:	704c      	lsl      	r1, r3
     8d0:	6850      	and      	r1, r4
     8d2:	3940      	cmpnei      	r1, 0
     8d4:	0c12      	bf      	0x8f8	// 8f8 <tkey_timeover_tune+0x56>
			if(hwSampling_data0[i]==0)
     8d6:	4321      	lsli      	r1, r3, 1
     8d8:	6058      	addu      	r1, r6
     8da:	8920      	ld.h      	r1, (r1, 0x0)
     8dc:	7445      	zexth      	r1, r1
     8de:	3940      	cmpnei      	r1, 0
     8e0:	080c      	bt      	0x8f8	// 8f8 <tkey_timeover_tune+0x56>
				if(byTkeyIcon[i]<7)
     8e2:	5f8c      	addu      	r4, r7, r3
     8e4:	8420      	ld.b      	r1, (r4, 0x0)
     8e6:	7444      	zextb      	r1, r1
     8e8:	3906      	cmphsi      	r1, 7
     8ea:	0805      	bt      	0x8f4	// 8f4 <tkey_timeover_tune+0x52>
				{
				byTkeyIcon[i]++;
     8ec:	8420      	ld.b      	r1, (r4, 0x0)
     8ee:	2100      	addi      	r1, 1
     8f0:	7444      	zextb      	r1, r1
     8f2:	a420      	st.b      	r1, (r4, 0x0)
				}
				u8_cnt++;
     8f4:	2200      	addi      	r2, 1
     8f6:	7488      	zextb      	r2, r2
     8f8:	2300      	addi      	r3, 1
		for (i=0;i<32;i++)
     8fa:	eb430020 	cmpnei      	r3, 32
     8fe:	0be6      	bt      	0x8ca	// 8ca <tkey_timeover_tune+0x28>
			}
			}
		}
		if(u8_cnt==0)
     900:	3a40      	cmpnei      	r2, 0
     902:	0803      	bt      	0x908	// 908 <tkey_timeover_tune+0x66>
			{
				bySens_fine_over_f=1;
     904:	3301      	movi      	r3, 1
     906:	a060      	st.b      	r3, (r0, 0x0)
			}
		for(i=0;i<byTk_num;i++)
		{
			TKEYB->TCH_SEQxCON[i]=(TKEYB->TCH_SEQxCON[i]&0xfe1fffff)|(byTkeyIcon[byTk_seque[i]]<<21);
     908:	136c      	lrw      	r3, 0x200000ac	// ab8 <tkey_baseline_tracking+0x5c>
		for(i=0;i<byTk_num;i++)
     90a:	134d      	lrw      	r2, 0x200003b2	// abc <tkey_baseline_tracking+0x60>
			TKEYB->TCH_SEQxCON[i]=(TKEYB->TCH_SEQxCON[i]&0xfe1fffff)|(byTkeyIcon[byTk_seque[i]]<<21);
     90c:	13aa      	lrw      	r5, 0x20000525	// ab4 <tkey_baseline_tracking+0x58>
     90e:	13d2      	lrw      	r6, 0x200005cd	// ad4 <tkey_baseline_tracking+0x78>
     910:	9381      	ld.w      	r4, (r3, 0x4)
		for(i=0;i<byTk_num;i++)
     912:	b840      	st.w      	r2, (r14, 0x0)
			TKEYB->TCH_SEQxCON[i]=(TKEYB->TCH_SEQxCON[i]&0xfe1fffff)|(byTkeyIcon[byTk_seque[i]]<<21);
     914:	3300      	movi      	r3, 0
		for(i=0;i<byTk_num;i++)
     916:	9840      	ld.w      	r2, (r14, 0x0)
     918:	8240      	ld.b      	r2, (r2, 0x0)
     91a:	648c      	cmphs      	r3, r2
     91c:	0c05      	bf      	0x926	// 926 <tkey_timeover_tune+0x84>
		}
		tkey_baseline_prog();
     91e:	e3ffff9b 	bsr      	0x854	// 854 <tkey_baseline_prog>
	}
}
     922:	1401      	addi      	r14, r14, 4
     924:	1494      	pop      	r4-r7, r15
     926:	4322      	lsli      	r1, r3, 2
			TKEYB->TCH_SEQxCON[i]=(TKEYB->TCH_SEQxCON[i]&0xfe1fffff)|(byTkeyIcon[byTk_seque[i]]<<21);
     928:	5dec      	addu      	r7, r5, r3
     92a:	6050      	addu      	r1, r4
     92c:	9140      	ld.w      	r2, (r1, 0x0)
     92e:	87e0      	ld.b      	r7, (r7, 0x0)
     930:	61d8      	addu      	r7, r6
     932:	87e0      	ld.b      	r7, (r7, 0x0)
     934:	ea20fe20 	movih      	r0, 65056
     938:	47f5      	lsli      	r7, r7, 21
     93a:	2800      	subi      	r0, 1
     93c:	6880      	and      	r2, r0
     93e:	6c9c      	or      	r2, r7
		for(i=0;i<byTk_num;i++)
     940:	2300      	addi      	r3, 1
			TKEYB->TCH_SEQxCON[i]=(TKEYB->TCH_SEQxCON[i]&0xfe1fffff)|(byTkeyIcon[byTk_seque[i]]<<21);
     942:	b140      	st.w      	r2, (r1, 0x0)
		for(i=0;i<byTk_num;i++)
     944:	74cc      	zextb      	r3, r3
     946:	07e8      	br      	0x916	// 916 <tkey_timeover_tune+0x74>

00000948 <tkey_overflow_predict>:
/****************************************************
//TK overflow predict
*****************************************************/
void tkey_overflow_predict(void)
{
     948:	14d4      	push      	r4-r7, r15
     94a:	1423      	subi      	r14, r14, 12
	unsigned char i=0,u8_cnt1=0;
	if(byAutoAdjustDis!=0x01)
     94c:	1363      	lrw      	r3, 0x200003fa	// ad8 <tkey_baseline_tracking+0x7c>
     94e:	8360      	ld.b      	r3, (r3, 0x0)
     950:	3b41      	cmpnei      	r3, 1
     952:	0c62      	bf      	0xa16	// a16 <tkey_overflow_predict+0xce>
	{
	byTk_sens_cnt++;
     954:	1342      	lrw      	r2, 0x200004ef	// adc <tkey_baseline_tracking+0x80>
     956:	8260      	ld.b      	r3, (r2, 0x0)
     958:	2300      	addi      	r3, 1
     95a:	74cc      	zextb      	r3, r3
     95c:	a260      	st.b      	r3, (r2, 0x0)
	if(byTk_sens_cnt>10)
     95e:	8260      	ld.b      	r3, (r2, 0x0)
     960:	74cc      	zextb      	r3, r3
     962:	3b0a      	cmphsi      	r3, 11
     964:	0c59      	bf      	0xa16	// a16 <tkey_overflow_predict+0xce>
	{
	for (i=0;i<32;i++)
	{
		if(((dwTkeyIoEnable & (1<<i))!=0)&&(dwKey_Map==0))
     966:	125b      	lrw      	r2, 0x200004f0	// ad0 <tkey_baseline_tracking+0x74>
     968:	3000      	movi      	r0, 0
     96a:	b840      	st.w      	r2, (r14, 0x0)
     96c:	3300      	movi      	r3, 0
     96e:	125d      	lrw      	r2, 0x20000324	// ae0 <tkey_baseline_tracking+0x84>
     970:	b841      	st.w      	r2, (r14, 0x4)
		{
		if((byTkeyFineTurn==ENABLE)&&(byTkeyChxSens[i]!=0))
     972:	125d      	lrw      	r2, 0x200003b5	// ae4 <tkey_baseline_tracking+0x88>
     974:	b842      	st.w      	r2, (r14, 0x8)
		if(((dwTkeyIoEnable & (1<<i))!=0)&&(dwKey_Map==0))
     976:	9840      	ld.w      	r2, (r14, 0x0)
     978:	9220      	ld.w      	r1, (r2, 0x0)
     97a:	3201      	movi      	r2, 1
     97c:	7080      	lsl      	r2, r0
     97e:	6884      	and      	r2, r1
     980:	3a40      	cmpnei      	r2, 0
     982:	0c39      	bf      	0x9f4	// 9f4 <tkey_overflow_predict+0xac>
     984:	9841      	ld.w      	r2, (r14, 0x4)
     986:	9240      	ld.w      	r2, (r2, 0x0)
     988:	3a40      	cmpnei      	r2, 0
     98a:	0835      	bt      	0x9f4	// 9f4 <tkey_overflow_predict+0xac>
		if((byTkeyFineTurn==ENABLE)&&(byTkeyChxSens[i]!=0))
     98c:	9842      	ld.w      	r2, (r14, 0x8)
     98e:	128e      	lrw      	r4, 0x20000466	// ac4 <tkey_baseline_tracking+0x68>
     990:	8240      	ld.b      	r2, (r2, 0x0)
     992:	12d6      	lrw      	r6, 0x200005ac	// ae8 <tkey_baseline_tracking+0x8c>
     994:	3a41      	cmpnei      	r2, 1
     996:	4041      	lsli      	r2, r0, 1
     998:	081a      	bt      	0x9cc	// 9cc <tkey_overflow_predict+0x84>
     99a:	1235      	lrw      	r1, 0x20000500	// aec <tkey_baseline_tracking+0x90>
     99c:	6040      	addu      	r1, r0
     99e:	8120      	ld.b      	r1, (r1, 0x0)
     9a0:	3940      	cmpnei      	r1, 0
     9a2:	0c15      	bf      	0x9cc	// 9cc <tkey_overflow_predict+0x84>
		{
			if(hwSampling_data0[i]>((700+((byTkeyGlobalSens-1)*250))*5))
     9a4:	5c28      	addu      	r1, r4, r2
     9a6:	89a0      	ld.h      	r5, (r1, 0x0)
     9a8:	7555      	zexth      	r5, r5
     9aa:	ea0704e2 	movi      	r7, 1250
     9ae:	8620      	ld.b      	r1, (r6, 0x0)
     9b0:	2900      	subi      	r1, 1
     9b2:	7c5c      	mult      	r1, r7
     9b4:	e4210dab 	addi      	r1, r1, 3500
     9b8:	6545      	cmplt      	r1, r5
     9ba:	0c09      	bf      	0x9cc	// 9cc <tkey_overflow_predict+0x84>
			{
			hwTkeySenprd[i]=hwTkeySenprd[i]-20;
     9bc:	12ad      	lrw      	r5, 0x200004ae	// af0 <tkey_baseline_tracking+0x94>
     9be:	6148      	addu      	r5, r2
     9c0:	8d20      	ld.h      	r1, (r5, 0x0)
     9c2:	2913      	subi      	r1, 20
     9c4:	7445      	zexth      	r1, r1
			u8_cnt1++;
     9c6:	2300      	addi      	r3, 1
			hwTkeySenprd[i]=hwTkeySenprd[i]-20;
     9c8:	ad20      	st.h      	r1, (r5, 0x0)
			u8_cnt1++;
     9ca:	74cc      	zextb      	r3, r3
			}
		}
		if(hwSampling_data0[i]>((700+((byTkeyGlobalSens-1)*250))*5))
     9cc:	6108      	addu      	r4, r2
     9ce:	8c80      	ld.h      	r4, (r4, 0x0)
     9d0:	7511      	zexth      	r4, r4
     9d2:	ea0504e2 	movi      	r5, 1250
     9d6:	8620      	ld.b      	r1, (r6, 0x0)
     9d8:	2900      	subi      	r1, 1
     9da:	7c54      	mult      	r1, r5
     9dc:	e4210dab 	addi      	r1, r1, 3500
     9e0:	6505      	cmplt      	r1, r4
     9e2:	0c09      	bf      	0x9f4	// 9f4 <tkey_overflow_predict+0xac>
		{
			hwTkeySenprd[i]=hwTkeySenprd[i]-20;
     9e4:	1223      	lrw      	r1, 0x200004ae	// af0 <tkey_baseline_tracking+0x94>
     9e6:	6084      	addu      	r2, r1
     9e8:	8a20      	ld.h      	r1, (r2, 0x0)
     9ea:	2913      	subi      	r1, 20
     9ec:	7445      	zexth      	r1, r1
			u8_cnt1++;
     9ee:	2300      	addi      	r3, 1
			hwTkeySenprd[i]=hwTkeySenprd[i]-20;
     9f0:	aa20      	st.h      	r1, (r2, 0x0)
			u8_cnt1++;
     9f2:	74cc      	zextb      	r3, r3
     9f4:	2000      	addi      	r0, 1
	for (i=0;i<32;i++)
     9f6:	eb400020 	cmpnei      	r0, 32
     9fa:	0bbe      	bt      	0x976	// 976 <tkey_overflow_predict+0x2e>
		}
		}
	}
	if(u8_cnt1!=0)
     9fc:	3b40      	cmpnei      	r3, 0
     9fe:	0c0c      	bf      	0xa16	// a16 <tkey_overflow_predict+0xce>
	{
		for(i=0;i<byTk_num;i++)
	{
		TKEYB->TCH_SEQxCON[i]=(TKEYB->TCH_SEQxCON[i]&0xffff0000)|(hwTkeySenprd[byTk_seque[i]]<<0);
     a00:	116e      	lrw      	r3, 0x200000ac	// ab8 <tkey_baseline_tracking+0x5c>
		for(i=0;i<byTk_num;i++)
     a02:	110f      	lrw      	r0, 0x200003b2	// abc <tkey_baseline_tracking+0x60>
		TKEYB->TCH_SEQxCON[i]=(TKEYB->TCH_SEQxCON[i]&0xffff0000)|(hwTkeySenprd[byTk_seque[i]]<<0);
     a04:	11ac      	lrw      	r5, 0x20000525	// ab4 <tkey_baseline_tracking+0x58>
     a06:	11db      	lrw      	r6, 0x200004ae	// af0 <tkey_baseline_tracking+0x94>
     a08:	9381      	ld.w      	r4, (r3, 0x4)
     a0a:	3300      	movi      	r3, 0
		for(i=0;i<byTk_num;i++)
     a0c:	8040      	ld.b      	r2, (r0, 0x0)
     a0e:	648c      	cmphs      	r3, r2
     a10:	0c05      	bf      	0xa1a	// a1a <tkey_overflow_predict+0xd2>
	}
		tkey_baseline_prog();
     a12:	e3ffff21 	bsr      	0x854	// 854 <tkey_baseline_prog>
	}
	}
	}
}
     a16:	1403      	addi      	r14, r14, 12
     a18:	1494      	pop      	r4-r7, r15
     a1a:	4322      	lsli      	r1, r3, 2
		TKEYB->TCH_SEQxCON[i]=(TKEYB->TCH_SEQxCON[i]&0xffff0000)|(hwTkeySenprd[byTk_seque[i]]<<0);
     a1c:	5dec      	addu      	r7, r5, r3
     a1e:	6050      	addu      	r1, r4
     a20:	9140      	ld.w      	r2, (r1, 0x0)
     a22:	87e0      	ld.b      	r7, (r7, 0x0)
     a24:	47e1      	lsli      	r7, r7, 1
     a26:	61d8      	addu      	r7, r6
     a28:	8fe0      	ld.h      	r7, (r7, 0x0)
     a2a:	4a50      	lsri      	r2, r2, 16
     a2c:	75dd      	zexth      	r7, r7
     a2e:	4250      	lsli      	r2, r2, 16
     a30:	6c9c      	or      	r2, r7
		for(i=0;i<byTk_num;i++)
     a32:	2300      	addi      	r3, 1
		TKEYB->TCH_SEQxCON[i]=(TKEYB->TCH_SEQxCON[i]&0xffff0000)|(hwTkeySenprd[byTk_seque[i]]<<0);
     a34:	b140      	st.w      	r2, (r1, 0x0)
		for(i=0;i<byTk_num;i++)
     a36:	74cc      	zextb      	r3, r3
     a38:	07ea      	br      	0xa0c	// a0c <tkey_overflow_predict+0xc4>

00000a3a <get_key_pressed>:
/****************************************************
//TK get key pressed
*****************************************************/
unsigned char get_key_pressed(void)
{                  
     a3a:	14c1      	push      	r4
    int count = 0;
    int i = 0;
     a3c:	3200      	movi      	r2, 0
    int count = 0;
     a3e:	3000      	movi      	r0, 0
    for (; i<32; i++)
    {
        if (((dwKey_Map0 >> i) & 1) == 1)
     a40:	118d      	lrw      	r4, 0x20000654	// af4 <tkey_baseline_tracking+0x98>
     a42:	3101      	movi      	r1, 1
     a44:	9460      	ld.w      	r3, (r4, 0x0)
     a46:	70c9      	lsr      	r3, r2
     a48:	68c4      	and      	r3, r1
    for (; i<32; i++)
     a4a:	2200      	addi      	r2, 1
		{
            count++;
     a4c:	3b40      	cmpnei      	r3, 0
     a4e:	c4000c41 	inct      	r0, r0, 1
    for (; i<32; i++)
     a52:	eb420020 	cmpnei      	r2, 32
     a56:	0bf7      	bt      	0xa44	// a44 <get_key_pressed+0xa>
		}
    }
    return count;
     a58:	7400      	zextb      	r0, r0
}
     a5a:	1481      	pop      	r4

00000a5c <tkey_baseline_tracking>:
/****************************************************
//TK baseline tracking
*****************************************************/
void tkey_baseline_tracking(void)
{
     a5c:	14c4      	push      	r4-r7
     a5e:	1423      	subi      	r14, r14, 12
	unsigned char i;
	byTk_track_cnt++;
     a60:	1146      	lrw      	r2, 0x200003b3	// af8 <tkey_baseline_tracking+0x9c>
     a62:	8260      	ld.b      	r3, (r2, 0x0)
     a64:	2300      	addi      	r3, 1
     a66:	74cc      	zextb      	r3, r3
     a68:	a260      	st.b      	r3, (r2, 0x0)
	if (byTk_track_cnt>=byBaseUpdateSpeed)
     a6a:	1165      	lrw      	r3, 0x2000036d	// afc <tkey_baseline_tracking+0xa0>
     a6c:	8220      	ld.b      	r1, (r2, 0x0)
     a6e:	8360      	ld.b      	r3, (r3, 0x0)
     a70:	64c4      	cmphs      	r1, r3
     a72:	0cf3      	bf      	0xc58	// c58 <tkey_baseline_tracking+0x1fc>
	{
		byTk_track_cnt=0;
     a74:	3300      	movi      	r3, 0
     a76:	a260      	st.b      	r3, (r2, 0x0)
		//======================================
		if(dwKey_Map0==0)
     a78:	107f      	lrw      	r3, 0x20000654	// af4 <tkey_baseline_tracking+0x98>
     a7a:	9360      	ld.w      	r3, (r3, 0x0)
     a7c:	3b40      	cmpnei      	r3, 0
     a7e:	08ed      	bt      	0xc58	// c58 <tkey_baseline_tracking+0x1fc>
		{
			for(i=0;i<32;i++)
			{
				if((nOffset_data0[i]<0)&&((hwBaseline_data0[i]-hwSampling_data0[i])>=(hwTkeyTriggerLevel[i])))
     a80:	1160      	lrw      	r3, 0x200003b8	// b00 <tkey_baseline_tracking+0xa4>
     a82:	3200      	movi      	r2, 0
     a84:	b862      	st.w      	r3, (r14, 0x8)
     a86:	6c0f      	mov      	r0, r3
     a88:	102e      	lrw      	r1, 0x20000328	// ac0 <tkey_baseline_tracking+0x64>
     a8a:	4261      	lsli      	r3, r2, 1
     a8c:	9882      	ld.w      	r4, (r14, 0x8)
     a8e:	610c      	addu      	r4, r3
     a90:	8c80      	ld.h      	r4, (r4, 0x0)
     a92:	7513      	sexth      	r4, r4
     a94:	3cdf      	btsti      	r4, 31
     a96:	0c50      	bf      	0xb36	// b36 <tkey_baseline_tracking+0xda>
     a98:	598c      	addu      	r4, r1, r3
     a9a:	10ab      	lrw      	r5, 0x20000466	// ac4 <tkey_baseline_tracking+0x68>
     a9c:	614c      	addu      	r5, r3
     a9e:	8c80      	ld.h      	r4, (r4, 0x0)
     aa0:	8dc0      	ld.h      	r6, (r5, 0x0)
     aa2:	0431      	br      	0xb04	// b04 <tkey_baseline_tracking+0xa8>
     aa4:	ffff0fff 	.long	0xffff0fff
     aa8:	fffff0ff 	.long	0xfffff0ff
     aac:	20000650 	.long	0x20000650
     ab0:	2000036e 	.long	0x2000036e
     ab4:	20000525 	.long	0x20000525
     ab8:	200000ac 	.long	0x200000ac
     abc:	200003b2 	.long	0x200003b2
     ac0:	20000328 	.long	0x20000328
     ac4:	20000466 	.long	0x20000466
     ac8:	20000461 	.long	0x20000461
     acc:	2000062f 	.long	0x2000062f
     ad0:	200004f0 	.long	0x200004f0
     ad4:	200005cd 	.long	0x200005cd
     ad8:	200003fa 	.long	0x200003fa
     adc:	200004ef 	.long	0x200004ef
     ae0:	20000324 	.long	0x20000324
     ae4:	200003b5 	.long	0x200003b5
     ae8:	200005ac 	.long	0x200005ac
     aec:	20000500 	.long	0x20000500
     af0:	200004ae 	.long	0x200004ae
     af4:	20000654 	.long	0x20000654
     af8:	200003b3 	.long	0x200003b3
     afc:	2000036d 	.long	0x2000036d
     b00:	200003b8 	.long	0x200003b8
     b04:	01ae      	lrw      	r5, 0x200003fc	// e48 <tkey_keymap_prog+0x1ec>
     b06:	614c      	addu      	r5, r3
     b08:	8da0      	ld.h      	r5, (r5, 0x0)
     b0a:	7555      	zexth      	r5, r5
     b0c:	7511      	zexth      	r4, r4
     b0e:	7599      	zexth      	r6, r6
     b10:	611a      	subu      	r4, r6
     b12:	6551      	cmplt      	r4, r5
     b14:	0811      	bt      	0xb36	// b36 <tkey_baseline_tracking+0xda>
				{
					byTk_negtive_build0[i]++;
     b16:	01b1      	lrw      	r5, 0x20000566	// e4c <tkey_keymap_prog+0x1f0>
     b18:	6148      	addu      	r5, r2
     b1a:	8580      	ld.b      	r4, (r5, 0x0)
     b1c:	2400      	addi      	r4, 1
     b1e:	7510      	zextb      	r4, r4
     b20:	a580      	st.b      	r4, (r5, 0x0)
					if(byTk_negtive_build0[i]>byTkeyNegBuildBounce)
     b22:	0193      	lrw      	r4, 0x200003b6	// e50 <tkey_keymap_prog+0x1f4>
     b24:	85c0      	ld.b      	r6, (r5, 0x0)
     b26:	8480      	ld.b      	r4, (r4, 0x0)
     b28:	6590      	cmphs      	r4, r6
     b2a:	0806      	bt      	0xb36	// b36 <tkey_baseline_tracking+0xda>
					{
					byForceReBuild=1;
     b2c:	0195      	lrw      	r4, 0x20000370	// e54 <tkey_keymap_prog+0x1f8>
     b2e:	3601      	movi      	r6, 1
     b30:	a4c0      	st.b      	r6, (r4, 0x0)
					byTk_negtive_build0[i]=0;
     b32:	3400      	movi      	r4, 0
     b34:	a580      	st.b      	r4, (r5, 0x0)
					}
				}
				if((nOffset_data0[i]>0)&&(hwSampling_data0[i]-hwBaseline_data0[i])>=(hwTkeyTriggerLevel[i]*4))
     b36:	588c      	addu      	r4, r0, r3
     b38:	8c80      	ld.h      	r4, (r4, 0x0)
     b3a:	7513      	sexth      	r4, r4
     b3c:	3c20      	cmplti      	r4, 1
     b3e:	0820      	bt      	0xb7e	// b7e <tkey_baseline_tracking+0x122>
     b40:	0199      	lrw      	r4, 0x20000466	// e58 <tkey_keymap_prog+0x1fc>
     b42:	610c      	addu      	r4, r3
     b44:	8ca0      	ld.h      	r5, (r4, 0x0)
     b46:	598c      	addu      	r4, r1, r3
     b48:	8cc0      	ld.h      	r6, (r4, 0x0)
     b4a:	019f      	lrw      	r4, 0x200003fc	// e48 <tkey_keymap_prog+0x1ec>
     b4c:	610c      	addu      	r4, r3
     b4e:	8c80      	ld.h      	r4, (r4, 0x0)
     b50:	7511      	zexth      	r4, r4
     b52:	4482      	lsli      	r4, r4, 2
     b54:	7555      	zexth      	r5, r5
     b56:	7599      	zexth      	r6, r6
     b58:	615a      	subu      	r5, r6
     b5a:	6515      	cmplt      	r5, r4
     b5c:	0811      	bt      	0xb7e	// b7e <tkey_baseline_tracking+0x122>
				{
					byTk_postive_build0[i]++;
     b5e:	01bf      	lrw      	r5, 0x20000546	// e5c <tkey_keymap_prog+0x200>
     b60:	6148      	addu      	r5, r2
     b62:	8580      	ld.b      	r4, (r5, 0x0)
     b64:	2400      	addi      	r4, 1
     b66:	7510      	zextb      	r4, r4
     b68:	a580      	st.b      	r4, (r5, 0x0)
					if(byTk_postive_build0[i]>byTkeyPosBuildBounce)
     b6a:	0281      	lrw      	r4, 0x200004ee	// e60 <tkey_keymap_prog+0x204>
     b6c:	85c0      	ld.b      	r6, (r5, 0x0)
     b6e:	8480      	ld.b      	r4, (r4, 0x0)
     b70:	6590      	cmphs      	r4, r6
     b72:	0806      	bt      	0xb7e	// b7e <tkey_baseline_tracking+0x122>
					{
					byForceReBuild=1;
     b74:	0287      	lrw      	r4, 0x20000370	// e54 <tkey_keymap_prog+0x1f8>
     b76:	3601      	movi      	r6, 1
     b78:	a4c0      	st.b      	r6, (r4, 0x0)
					byTk_postive_build0[i]=0;
     b7a:	3400      	movi      	r4, 0
     b7c:	a580      	st.b      	r4, (r5, 0x0)
					}
				}
				if((nOffset_data0[i]<0)&&((hwBaseline_data0[i]-hwSampling_data0[i])<hwTkeyTriggerLevel[i]))
     b7e:	588c      	addu      	r4, r0, r3
     b80:	8c80      	ld.h      	r4, (r4, 0x0)
     b82:	7513      	sexth      	r4, r4
     b84:	3cdf      	btsti      	r4, 31
     b86:	0c13      	bf      	0xbac	// bac <tkey_baseline_tracking+0x150>
     b88:	59ac      	addu      	r5, r1, r3
     b8a:	02cb      	lrw      	r6, 0x20000466	// e58 <tkey_keymap_prog+0x1fc>
     b8c:	618c      	addu      	r6, r3
     b8e:	8d80      	ld.h      	r4, (r5, 0x0)
     b90:	8ee0      	ld.h      	r7, (r6, 0x0)
     b92:	02d1      	lrw      	r6, 0x200003fc	// e48 <tkey_keymap_prog+0x1ec>
     b94:	618c      	addu      	r6, r3
     b96:	8ec0      	ld.h      	r6, (r6, 0x0)
     b98:	7599      	zexth      	r6, r6
     b9a:	7511      	zexth      	r4, r4
     b9c:	75dd      	zexth      	r7, r7
     b9e:	611e      	subu      	r4, r7
     ba0:	6591      	cmplt      	r4, r6
     ba2:	0c05      	bf      	0xbac	// bac <tkey_baseline_tracking+0x150>
				{
					hwBaseline_data0[i]-=2;
     ba4:	8d80      	ld.h      	r4, (r5, 0x0)
     ba6:	2c01      	subi      	r4, 2
     ba8:	7511      	zexth      	r4, r4
     baa:	ad80      	st.h      	r4, (r5, 0x0)
				}
				if((nOffset_data0[i]<0)&&((hwBaseline_data0[i]-hwSampling_data0[i])>=(hwTkeyTriggerLevel[i]/2))&&((hwBaseline_data0[i]-hwSampling_data0[i])<hwTkeyTriggerLevel[i]))
     bac:	588c      	addu      	r4, r0, r3
     bae:	8c80      	ld.h      	r4, (r4, 0x0)
     bb0:	7513      	sexth      	r4, r4
     bb2:	3cdf      	btsti      	r4, 31
     bb4:	0c21      	bf      	0xbf6	// bf6 <tkey_baseline_tracking+0x19a>
     bb6:	59ac      	addu      	r5, r1, r3
     bb8:	8d80      	ld.h      	r4, (r5, 0x0)
     bba:	7511      	zexth      	r4, r4
     bbc:	b880      	st.w      	r4, (r14, 0x0)
     bbe:	02f8      	lrw      	r7, 0x20000466	// e58 <tkey_keymap_prog+0x1fc>
     bc0:	029d      	lrw      	r4, 0x200003fc	// e48 <tkey_keymap_prog+0x1ec>
     bc2:	61cc      	addu      	r7, r3
     bc4:	60d0      	addu      	r3, r4
     bc6:	8fc0      	ld.h      	r6, (r7, 0x0)
     bc8:	8b80      	ld.h      	r4, (r3, 0x0)
     bca:	7511      	zexth      	r4, r4
     bcc:	b881      	st.w      	r4, (r14, 0x4)
     bce:	7599      	zexth      	r6, r6
     bd0:	9880      	ld.w      	r4, (r14, 0x0)
     bd2:	5cd9      	subu      	r6, r4, r6
     bd4:	9881      	ld.w      	r4, (r14, 0x4)
     bd6:	4c81      	lsri      	r4, r4, 1
     bd8:	6519      	cmplt      	r6, r4
     bda:	080e      	bt      	0xbf6	// bf6 <tkey_baseline_tracking+0x19a>
     bdc:	8d80      	ld.h      	r4, (r5, 0x0)
     bde:	8fc0      	ld.h      	r6, (r7, 0x0)
     be0:	8b60      	ld.h      	r3, (r3, 0x0)
     be2:	74cd      	zexth      	r3, r3
     be4:	7511      	zexth      	r4, r4
     be6:	7599      	zexth      	r6, r6
     be8:	611a      	subu      	r4, r6
     bea:	64d1      	cmplt      	r4, r3
     bec:	0c05      	bf      	0xbf6	// bf6 <tkey_baseline_tracking+0x19a>
				{
					hwBaseline_data0[i]-=4;
     bee:	8d60      	ld.h      	r3, (r5, 0x0)
     bf0:	2b03      	subi      	r3, 4
     bf2:	74cd      	zexth      	r3, r3
     bf4:	ad60      	st.h      	r3, (r5, 0x0)
				}
				if ((nOffset_data0[i]>0)&&(nOffset_data0[i]<(hwTkeyTriggerLevel[i]/2)))
     bf6:	4261      	lsli      	r3, r2, 1
     bf8:	58ac      	addu      	r5, r0, r3
     bfa:	8d80      	ld.h      	r4, (r5, 0x0)
     bfc:	7513      	sexth      	r4, r4
     bfe:	3c20      	cmplti      	r4, 1
     c00:	080f      	bt      	0xc1e	// c1e <tkey_baseline_tracking+0x1c2>
     c02:	038d      	lrw      	r4, 0x200003fc	// e48 <tkey_keymap_prog+0x1ec>
     c04:	610c      	addu      	r4, r3
     c06:	8da0      	ld.h      	r5, (r5, 0x0)
     c08:	8c80      	ld.h      	r4, (r4, 0x0)
     c0a:	7511      	zexth      	r4, r4
     c0c:	7557      	sexth      	r5, r5
     c0e:	4c81      	lsri      	r4, r4, 1
     c10:	6515      	cmplt      	r5, r4
     c12:	0c06      	bf      	0xc1e	// c1e <tkey_baseline_tracking+0x1c2>
				{
					hwBaseline_data0[i]+=1;
     c14:	59ac      	addu      	r5, r1, r3
     c16:	8d80      	ld.h      	r4, (r5, 0x0)
     c18:	2400      	addi      	r4, 1
     c1a:	7511      	zexth      	r4, r4
     c1c:	ad80      	st.h      	r4, (r5, 0x0)
				}
				if ((nOffset_data0[i]>0)&&(nOffset_data0[i]<hwTkeyTriggerLevel[i])&&(nOffset_data0[i]>=(hwTkeyTriggerLevel[i]/2)))
     c1e:	588c      	addu      	r4, r0, r3
     c20:	8ca0      	ld.h      	r5, (r4, 0x0)
     c22:	7557      	sexth      	r5, r5
     c24:	3d20      	cmplti      	r5, 1
     c26:	0815      	bt      	0xc50	// c50 <tkey_baseline_tracking+0x1f4>
     c28:	03f7      	lrw      	r7, 0x200003fc	// e48 <tkey_keymap_prog+0x1ec>
     c2a:	61cc      	addu      	r7, r3
     c2c:	8cc0      	ld.h      	r6, (r4, 0x0)
     c2e:	8fa0      	ld.h      	r5, (r7, 0x0)
     c30:	759b      	sexth      	r6, r6
     c32:	7555      	zexth      	r5, r5
     c34:	6559      	cmplt      	r6, r5
     c36:	0c0d      	bf      	0xc50	// c50 <tkey_baseline_tracking+0x1f4>
     c38:	8ca0      	ld.h      	r5, (r4, 0x0)
     c3a:	8f80      	ld.h      	r4, (r7, 0x0)
     c3c:	7511      	zexth      	r4, r4
     c3e:	7557      	sexth      	r5, r5
     c40:	4c81      	lsri      	r4, r4, 1
     c42:	6515      	cmplt      	r5, r4
     c44:	0806      	bt      	0xc50	// c50 <tkey_baseline_tracking+0x1f4>
				{
					hwBaseline_data0[i]+=2;
     c46:	60c4      	addu      	r3, r1
     c48:	8b80      	ld.h      	r4, (r3, 0x0)
     c4a:	2401      	addi      	r4, 2
     c4c:	7511      	zexth      	r4, r4
     c4e:	ab80      	st.h      	r4, (r3, 0x0)
     c50:	2200      	addi      	r2, 1
			for(i=0;i<32;i++)
     c52:	eb420020 	cmpnei      	r2, 32
     c56:	0b1a      	bt      	0xa8a	// a8a <tkey_baseline_tracking+0x2e>
				}
			}
		}
	}
}
     c58:	1403      	addi      	r14, r14, 12
     c5a:	1484      	pop      	r4-r7

00000c5c <tkey_keymap_prog>:
/****************************************************
//TK get key map
*****************************************************/
void tkey_keymap_prog(void)
{
     c5c:	14d4      	push      	r4-r7, r15
     c5e:	1423      	subi      	r14, r14, 12
	unsigned char i;
	for(i=0;i<32;i++)
	{
		nOffset_data0[i]=hwSampling_data0[i]-hwBaseline_data0[i];
     c60:	031e      	lrw      	r0, 0x200003b8	// e64 <tkey_keymap_prog+0x208>
{
     c62:	3100      	movi      	r1, 0
		nOffset_data0[i]=hwSampling_data0[i]-hwBaseline_data0[i];
     c64:	139d      	lrw      	r4, 0x20000466	// e58 <tkey_keymap_prog+0x1fc>
     c66:	6d43      	mov      	r5, r0
     c68:	4161      	lsli      	r3, r1, 1
     c6a:	03df      	lrw      	r6, 0x20000328	// e68 <tkey_keymap_prog+0x20c>
     c6c:	5c4c      	addu      	r2, r4, r3
     c6e:	618c      	addu      	r6, r3
     c70:	8a40      	ld.h      	r2, (r2, 0x0)
     c72:	8ec0      	ld.h      	r6, (r6, 0x0)
     c74:	609a      	subu      	r2, r6
     c76:	58cc      	addu      	r6, r0, r3
     c78:	748b      	sexth      	r2, r2
     c7a:	ae40      	st.h      	r2, (r6, 0x0)
		if(nOffset_data0[i]<0)
     c7c:	8e40      	ld.h      	r2, (r6, 0x0)
     c7e:	748b      	sexth      	r2, r2
     c80:	3adf      	btsti      	r2, 31
     c82:	135b      	lrw      	r2, 0x20000372	// e6c <tkey_keymap_prog+0x210>
     c84:	60c8      	addu      	r3, r2
     c86:	0c9f      	bf      	0xdc4	// dc4 <tkey_keymap_prog+0x168>
		{
			hwOffset_data0_abs[i]=0;
     c88:	3200      	movi      	r2, 0
     c8a:	2100      	addi      	r1, 1
	for(i=0;i<32;i++)
     c8c:	eb410020 	cmpnei      	r1, 32
		}
		else
		{
			hwOffset_data0_abs[i]=nOffset_data0[i];
     c90:	ab40      	st.h      	r2, (r3, 0x0)
	for(i=0;i<32;i++)
     c92:	0beb      	bt      	0xc68	// c68 <tkey_keymap_prog+0xc>
		}
	}
	for(i=0;i<32;i++)
	{
		//=================dwKey_Map0============================
		if(byMultiTimesFilter>=4)
     c94:	1377      	lrw      	r3, 0x2000062e	// e70 <tkey_keymap_prog+0x214>
     c96:	3400      	movi      	r4, 0
     c98:	b861      	st.w      	r3, (r14, 0x4)
     c9a:	b862      	st.w      	r3, (r14, 0x8)
     c9c:	136b      	lrw      	r3, 0x200003fc	// e48 <tkey_keymap_prog+0x1ec>
     c9e:	b860      	st.w      	r3, (r14, 0x0)
     ca0:	9861      	ld.w      	r3, (r14, 0x4)
     ca2:	8360      	ld.b      	r3, (r3, 0x0)
     ca4:	74cc      	zextb      	r3, r3
     ca6:	3b03      	cmphsi      	r3, 4
     ca8:	4461      	lsli      	r3, r4, 1
     caa:	0cf7      	bf      	0xe98	// e98 <tkey_keymap_prog+0x23c>
		{
			if((nOffset_data0[i]>hwTkeyTriggerLevel[i])&&(nOffset_data0[i]<(hwTkeyTriggerLevel[i]*byMultiTimesFilter))&&(byValid_key_f==0))
     cac:	5dcc      	addu      	r6, r5, r3
     cae:	9800      	ld.w      	r0, (r14, 0x0)
     cb0:	600c      	addu      	r0, r3
     cb2:	8e20      	ld.h      	r1, (r6, 0x0)
     cb4:	8840      	ld.h      	r2, (r0, 0x0)
     cb6:	7447      	sexth      	r1, r1
     cb8:	7489      	zexth      	r2, r2
     cba:	6449      	cmplt      	r2, r1
     cbc:	0c87      	bf      	0xdca	// dca <tkey_keymap_prog+0x16e>
     cbe:	8e20      	ld.h      	r1, (r6, 0x0)
     cc0:	8840      	ld.h      	r2, (r0, 0x0)
     cc2:	9801      	ld.w      	r0, (r14, 0x4)
     cc4:	7489      	zexth      	r2, r2
     cc6:	8000      	ld.b      	r0, (r0, 0x0)
     cc8:	7447      	sexth      	r1, r1
     cca:	7c80      	mult      	r2, r0
     ccc:	6485      	cmplt      	r1, r2
     cce:	0c7e      	bf      	0xdca	// dca <tkey_keymap_prog+0x16e>
     cd0:	1349      	lrw      	r2, 0x200004fe	// e74 <tkey_keymap_prog+0x218>
     cd2:	8240      	ld.b      	r2, (r2, 0x0)
     cd4:	3a40      	cmpnei      	r2, 0
     cd6:	087a      	bt      	0xdca	// dca <tkey_keymap_prog+0x16e>
		}
		else
		{
		if((nOffset_data0[i]>hwTkeyTriggerLevel[i])&&(byValid_key_f==0))
		{
			byPress_debounce0[i]++;
     cd8:	13e8      	lrw      	r7, 0x200005ad	// e78 <tkey_keymap_prog+0x21c>
     cda:	61d0      	addu      	r7, r4
     cdc:	8740      	ld.b      	r2, (r7, 0x0)
			byRelease_debounce0[i]=0;
     cde:	3100      	movi      	r1, 0
			byPress_debounce0[i]++;
     ce0:	2200      	addi      	r2, 1
     ce2:	7488      	zextb      	r2, r2
     ce4:	a740      	st.b      	r2, (r7, 0x0)
			byRelease_debounce0[i]=0;
     ce6:	1346      	lrw      	r2, 0x20000630	// e7c <tkey_keymap_prog+0x220>
     ce8:	6090      	addu      	r2, r4
     cea:	a220      	st.b      	r1, (r2, 0x0)
			byTk_postive_build0[i]=0;
     cec:	125c      	lrw      	r2, 0x20000546	// e5c <tkey_keymap_prog+0x200>
     cee:	6090      	addu      	r2, r4
     cf0:	a220      	st.b      	r1, (r2, 0x0)
			byTk_negtive_build0[i]=0;
     cf2:	1257      	lrw      	r2, 0x20000566	// e4c <tkey_keymap_prog+0x1f0>
     cf4:	6090      	addu      	r2, r4
     cf6:	a220      	st.b      	r1, (r2, 0x0)
			if(byPress_debounce0[i]>byPressDebounce)
     cf8:	1342      	lrw      	r2, 0x20000545	// e80 <tkey_keymap_prog+0x224>
     cfa:	8720      	ld.b      	r1, (r7, 0x0)
     cfc:	8240      	ld.b      	r2, (r2, 0x0)
     cfe:	6448      	cmphs      	r2, r1
     d00:	0878      	bt      	0xdf0	// df0 <tkey_keymap_prog+0x194>
			{
				if((byKeyMode==0)&&(dwKey_Map0==0))			//first single key
     d02:	1321      	lrw      	r1, 0x200004a6	// e84 <tkey_keymap_prog+0x228>
     d04:	8140      	ld.b      	r2, (r1, 0x0)
     d06:	3a40      	cmpnei      	r2, 0
     d08:	080a      	bt      	0xd1c	// d1c <tkey_keymap_prog+0xc0>
     d0a:	1300      	lrw      	r0, 0x20000654	// e88 <tkey_keymap_prog+0x22c>
     d0c:	9040      	ld.w      	r2, (r0, 0x0)
     d0e:	3a40      	cmpnei      	r2, 0
     d10:	0806      	bt      	0xd1c	// d1c <tkey_keymap_prog+0xc0>
				{
				dwKey_Map0|=0x01<<i;
     d12:	3201      	movi      	r2, 1
     d14:	90c0      	ld.w      	r6, (r0, 0x0)
     d16:	7090      	lsl      	r2, r4
     d18:	6c98      	or      	r2, r6
     d1a:	b040      	st.w      	r2, (r0, 0x0)
				}
				if(byKeyMode==1)								//multi key
     d1c:	8140      	ld.b      	r2, (r1, 0x0)
     d1e:	7488      	zextb      	r2, r2
     d20:	3a41      	cmpnei      	r2, 1
     d22:	0806      	bt      	0xd2e	// d2e <tkey_keymap_prog+0xd2>
				{
				dwKey_Map0|=0x01<<i;
     d24:	1219      	lrw      	r0, 0x20000654	// e88 <tkey_keymap_prog+0x22c>
     d26:	7090      	lsl      	r2, r4
     d28:	90c0      	ld.w      	r6, (r0, 0x0)
     d2a:	6c98      	or      	r2, r6
     d2c:	b040      	st.w      	r2, (r0, 0x0)
				}
				if(byKeyMode==2)								//strongest single key
     d2e:	8140      	ld.b      	r2, (r1, 0x0)
     d30:	3a42      	cmpnei      	r2, 2
     d32:	0816      	bt      	0xd5e	// d5e <tkey_keymap_prog+0x102>
				{
				if(nOffset_data0[i]>(hwOffset0_max_tempA+10))
     d34:	5d4c      	addu      	r2, r5, r3
     d36:	8a00      	ld.h      	r0, (r2, 0x0)
     d38:	12d5      	lrw      	r6, 0x20000320	// e8c <tkey_keymap_prog+0x230>
     d3a:	7403      	sexth      	r0, r0
     d3c:	8e40      	ld.h      	r2, (r6, 0x0)
     d3e:	7489      	zexth      	r2, r2
     d40:	2209      	addi      	r2, 10
     d42:	6409      	cmplt      	r2, r0
     d44:	0c0d      	bf      	0xd5e	// d5e <tkey_keymap_prog+0x102>
				{
				hwOffset0_max_tempA=nOffset_data0[i];
     d46:	5d4c      	addu      	r2, r5, r3
     d48:	8a40      	ld.h      	r2, (r2, 0x0)
     d4a:	7489      	zexth      	r2, r2
     d4c:	ae40      	st.h      	r2, (r6, 0x0)
				dwKey_Map0=0;
     d4e:	3200      	movi      	r2, 0
     d50:	120e      	lrw      	r0, 0x20000654	// e88 <tkey_keymap_prog+0x22c>
     d52:	b040      	st.w      	r2, (r0, 0x0)
				dwKey_Map0|=0x01<<i;
     d54:	3201      	movi      	r2, 1
     d56:	90c0      	ld.w      	r6, (r0, 0x0)
     d58:	7090      	lsl      	r2, r4
     d5a:	6c98      	or      	r2, r6
     d5c:	b040      	st.w      	r2, (r0, 0x0)
				}
				}
				if(byKeyMode==3)								//stronger multi key
     d5e:	8140      	ld.b      	r2, (r1, 0x0)
     d60:	3a43      	cmpnei      	r2, 3
     d62:	082e      	bt      	0xdbe	// dbe <tkey_keymap_prog+0x162>
				{
				if(nOffset_data0[i]>(hwOffset0_max_tempA+10))
     d64:	5dcc      	addu      	r6, r5, r3
     d66:	8e20      	ld.h      	r1, (r6, 0x0)
     d68:	1209      	lrw      	r0, 0x20000320	// e8c <tkey_keymap_prog+0x230>
     d6a:	7447      	sexth      	r1, r1
     d6c:	8840      	ld.h      	r2, (r0, 0x0)
     d6e:	7489      	zexth      	r2, r2
     d70:	2209      	addi      	r2, 10
     d72:	6449      	cmplt      	r2, r1
     d74:	0c0c      	bf      	0xd8c	// d8c <tkey_keymap_prog+0x130>
				{
				hwOffset0_max_tempA=nOffset_data0[i];
     d76:	8e40      	ld.h      	r2, (r6, 0x0)
     d78:	7489      	zexth      	r2, r2
     d7a:	a840      	st.h      	r2, (r0, 0x0)
				dwKey_Map0=0;
     d7c:	3200      	movi      	r2, 0
     d7e:	1223      	lrw      	r1, 0x20000654	// e88 <tkey_keymap_prog+0x22c>
     d80:	b140      	st.w      	r2, (r1, 0x0)
				dwKey_Map0|=0x01<<i;
     d82:	3201      	movi      	r2, 1
     d84:	91c0      	ld.w      	r6, (r1, 0x0)
     d86:	7090      	lsl      	r2, r4
     d88:	6c98      	or      	r2, r6
     d8a:	b140      	st.w      	r2, (r1, 0x0)
				}
				if((nOffset_data0[i]<(hwOffset0_max_tempA-5))&&(nOffset_data0[i]>(hwOffset0_max_tempB+5)))
     d8c:	5d2c      	addu      	r1, r5, r3
     d8e:	8940      	ld.h      	r2, (r1, 0x0)
     d90:	748b      	sexth      	r2, r2
     d92:	8800      	ld.h      	r0, (r0, 0x0)
     d94:	7401      	zexth      	r0, r0
     d96:	2804      	subi      	r0, 5
     d98:	6409      	cmplt      	r2, r0
     d9a:	0c12      	bf      	0xdbe	// dbe <tkey_keymap_prog+0x162>
     d9c:	8900      	ld.h      	r0, (r1, 0x0)
     d9e:	11dd      	lrw      	r6, 0x20000522	// e90 <tkey_keymap_prog+0x234>
     da0:	7403      	sexth      	r0, r0
     da2:	8e40      	ld.h      	r2, (r6, 0x0)
     da4:	7489      	zexth      	r2, r2
     da6:	2204      	addi      	r2, 5
     da8:	6409      	cmplt      	r2, r0
     daa:	0c0a      	bf      	0xdbe	// dbe <tkey_keymap_prog+0x162>
				{
				hwOffset0_max_tempB=nOffset_data0[i];
     dac:	8940      	ld.h      	r2, (r1, 0x0)
     dae:	7489      	zexth      	r2, r2
     db0:	ae40      	st.h      	r2, (r6, 0x0)
				dwKey_Map0|=0x01<<i;
     db2:	3201      	movi      	r2, 1
     db4:	1135      	lrw      	r1, 0x20000654	// e88 <tkey_keymap_prog+0x22c>
     db6:	7090      	lsl      	r2, r4
     db8:	9100      	ld.w      	r0, (r1, 0x0)
     dba:	6c80      	or      	r2, r0
     dbc:	b140      	st.w      	r2, (r1, 0x0)
				}
				}
				byPress_debounce0[i]=0;
     dbe:	3200      	movi      	r2, 0
     dc0:	a740      	st.b      	r2, (r7, 0x0)
     dc2:	0417      	br      	0xdf0	// df0 <tkey_keymap_prog+0x194>
			hwOffset_data0_abs[i]=nOffset_data0[i];
     dc4:	8e40      	ld.h      	r2, (r6, 0x0)
     dc6:	7489      	zexth      	r2, r2
     dc8:	0761      	br      	0xc8a	// c8a <tkey_keymap_prog+0x2e>
		 else if((nOffset_data0[i])>(hwTkeyTriggerLevel[i]*byMultiTimesFilter))
     dca:	5d4c      	addu      	r2, r5, r3
     dcc:	8a20      	ld.h      	r1, (r2, 0x0)
     dce:	9802      	ld.w      	r0, (r14, 0x8)
     dd0:	9840      	ld.w      	r2, (r14, 0x0)
     dd2:	608c      	addu      	r2, r3
     dd4:	8a40      	ld.h      	r2, (r2, 0x0)
     dd6:	7489      	zexth      	r2, r2
     dd8:	8000      	ld.b      	r0, (r0, 0x0)
     dda:	7447      	sexth      	r1, r1
     ddc:	7c80      	mult      	r2, r0
     dde:	6449      	cmplt      	r2, r1
     de0:	0c08      	bf      	0xdf0	// df0 <tkey_keymap_prog+0x194>
				 dwKey_Map0&=~(0x01<<i);
     de2:	112a      	lrw      	r1, 0x20000654	// e88 <tkey_keymap_prog+0x22c>
     de4:	3200      	movi      	r2, 0
     de6:	9100      	ld.w      	r0, (r1, 0x0)
     de8:	2a01      	subi      	r2, 2
     dea:	7093      	rotl      	r2, r4
     dec:	6880      	and      	r2, r0
     dee:	b140      	st.w      	r2, (r1, 0x0)
			}
		}
		}
		if(nOffset_data0[i]<(hwTkeyTriggerLevel[i]*4/5))
     df0:	5d4c      	addu      	r2, r5, r3
     df2:	8ac0      	ld.h      	r6, (r2, 0x0)
     df4:	9840      	ld.w      	r2, (r14, 0x0)
     df6:	60c8      	addu      	r3, r2
     df8:	8b00      	ld.h      	r0, (r3, 0x0)
     dfa:	7401      	zexth      	r0, r0
     dfc:	4002      	lsli      	r0, r0, 2
     dfe:	3105      	movi      	r1, 5
     e00:	759b      	sexth      	r6, r6
     e02:	e000055d 	bsr      	0x18bc	// 18bc <__divsi3>
     e06:	6419      	cmplt      	r6, r0
     e08:	0c19      	bf      	0xe3a	// e3a <tkey_keymap_prog+0x1de>
		{
			byRelease_debounce0[i]++;
     e0a:	105d      	lrw      	r2, 0x20000630	// e7c <tkey_keymap_prog+0x220>
     e0c:	6090      	addu      	r2, r4
     e0e:	8260      	ld.b      	r3, (r2, 0x0)
			byPress_debounce0[i]=0;
     e10:	3100      	movi      	r1, 0
			byRelease_debounce0[i]++;
     e12:	2300      	addi      	r3, 1
     e14:	74cc      	zextb      	r3, r3
     e16:	a260      	st.b      	r3, (r2, 0x0)
			byPress_debounce0[i]=0;
     e18:	1078      	lrw      	r3, 0x200005ad	// e78 <tkey_keymap_prog+0x21c>
     e1a:	60d0      	addu      	r3, r4
     e1c:	a320      	st.b      	r1, (r3, 0x0)
			if(byRelease_debounce0[i]>byReleaseDebounce)
     e1e:	107e      	lrw      	r3, 0x20000440	// e94 <tkey_keymap_prog+0x238>
     e20:	8220      	ld.b      	r1, (r2, 0x0)
     e22:	8360      	ld.b      	r3, (r3, 0x0)
     e24:	644c      	cmphs      	r3, r1
     e26:	080a      	bt      	0xe3a	// e3a <tkey_keymap_prog+0x1de>
			{
				dwKey_Map0&=~(0x01<<i);
     e28:	1038      	lrw      	r1, 0x20000654	// e88 <tkey_keymap_prog+0x22c>
     e2a:	3300      	movi      	r3, 0
     e2c:	9100      	ld.w      	r0, (r1, 0x0)
     e2e:	2b01      	subi      	r3, 2
     e30:	70d3      	rotl      	r3, r4
     e32:	68c0      	and      	r3, r0
     e34:	b160      	st.w      	r3, (r1, 0x0)
				byRelease_debounce0[i]=0;
     e36:	3300      	movi      	r3, 0
     e38:	a260      	st.b      	r3, (r2, 0x0)
     e3a:	2400      	addi      	r4, 1
	for(i=0;i<32;i++)
     e3c:	eb440020 	cmpnei      	r4, 32
     e40:	0b30      	bt      	0xca0	// ca0 <tkey_keymap_prog+0x44>
			}
		}
		
	}
}
     e42:	1403      	addi      	r14, r14, 12
     e44:	1494      	pop      	r4-r7, r15
     e46:	0000      	bkpt
     e48:	200003fc 	.long	0x200003fc
     e4c:	20000566 	.long	0x20000566
     e50:	200003b6 	.long	0x200003b6
     e54:	20000370 	.long	0x20000370
     e58:	20000466 	.long	0x20000466
     e5c:	20000546 	.long	0x20000546
     e60:	200004ee 	.long	0x200004ee
     e64:	200003b8 	.long	0x200003b8
     e68:	20000328 	.long	0x20000328
     e6c:	20000372 	.long	0x20000372
     e70:	2000062e 	.long	0x2000062e
     e74:	200004fe 	.long	0x200004fe
     e78:	200005ad 	.long	0x200005ad
     e7c:	20000630 	.long	0x20000630
     e80:	20000545 	.long	0x20000545
     e84:	200004a6 	.long	0x200004a6
     e88:	20000654 	.long	0x20000654
     e8c:	20000320 	.long	0x20000320
     e90:	20000522 	.long	0x20000522
     e94:	20000440 	.long	0x20000440
		if((nOffset_data0[i]>hwTkeyTriggerLevel[i])&&(byValid_key_f==0))
     e98:	5d4c      	addu      	r2, r5, r3
     e9a:	8a20      	ld.h      	r1, (r2, 0x0)
     e9c:	9840      	ld.w      	r2, (r14, 0x0)
     e9e:	608c      	addu      	r2, r3
     ea0:	8a40      	ld.h      	r2, (r2, 0x0)
     ea2:	7447      	sexth      	r1, r1
     ea4:	7489      	zexth      	r2, r2
     ea6:	6449      	cmplt      	r2, r1
     ea8:	0fa4      	bf      	0xdf0	// df0 <tkey_keymap_prog+0x194>
     eaa:	015c      	lrw      	r2, 0x200004fe	// 11b4 <csi_tkey_setup_sleep+0x9c>
     eac:	8240      	ld.b      	r2, (r2, 0x0)
     eae:	3a40      	cmpnei      	r2, 0
     eb0:	0ba0      	bt      	0xdf0	// df0 <tkey_keymap_prog+0x194>
     eb2:	0713      	br      	0xcd8	// cd8 <tkey_keymap_prog+0x7c>

00000eb4 <tkey_trigger_auto_adjust>:

/****************************************************
//TK Trigger Auto once
*****************************************************/
void tkey_trigger_auto_adjust(void)
{
     eb4:	14c4      	push      	r4-r7
     eb6:	1421      	subi      	r14, r14, 4
	unsigned char i;
	if(byAutoAdjustDis!=0x01)
     eb8:	017f      	lrw      	r3, 0x200003fa	// 11b8 <csi_tkey_setup_sleep+0xa0>
     eba:	8360      	ld.b      	r3, (r3, 0x0)
     ebc:	3b41      	cmpnei      	r3, 1
     ebe:	0c70      	bf      	0xf9e	// f9e <tkey_trigger_auto_adjust+0xea>
	{
	if((dwKey_Map!=0)&&(byTrigger_auto_f==0))
     ec0:	0240      	lrw      	r2, 0x20000324	// 11bc <csi_tkey_setup_sleep+0xa4>
     ec2:	9260      	ld.w      	r3, (r2, 0x0)
     ec4:	3b40      	cmpnei      	r3, 0
     ec6:	0260      	lrw      	r3, 0x2000036c	// 11c0 <csi_tkey_setup_sleep+0xa8>
     ec8:	086d      	bt      	0xfa2	// fa2 <tkey_trigger_auto_adjust+0xee>
		{
			hwOffset_max_data[i]=hwOffset_data0_abs[i];
		}
		}
	}
	if((byTrigger_auto_f==1)&&(dwKey_Map==0))
     eca:	8320      	ld.b      	r1, (r3, 0x0)
     ecc:	3941      	cmpnei      	r1, 1
     ece:	082b      	bt      	0xf24	// f24 <tkey_trigger_auto_adjust+0x70>
     ed0:	9240      	ld.w      	r2, (r2, 0x0)
     ed2:	3a40      	cmpnei      	r2, 0
     ed4:	0828      	bt      	0xf24	// f24 <tkey_trigger_auto_adjust+0x70>
	{
		for(i=0;i<32;i++)
		{
			if(hwOffset_max_data[i]>(hwTkeyTriggerLevel[i]*3/2))
     ed6:	02c3      	lrw      	r6, 0x200005ee	// 11c4 <csi_tkey_setup_sleep+0xac>
     ed8:	3400      	movi      	r4, 0
     eda:	0223      	lrw      	r1, 0x200003fc	// 11c8 <csi_tkey_setup_sleep+0xb0>
     edc:	6c1b      	mov      	r0, r6
     ede:	4441      	lsli      	r2, r4, 1
     ee0:	5ea8      	addu      	r5, r6, r2
     ee2:	6084      	addu      	r2, r1
     ee4:	8da0      	ld.h      	r5, (r5, 0x0)
     ee6:	8a40      	ld.h      	r2, (r2, 0x0)
     ee8:	75c9      	zexth      	r7, r2
     eea:	7555      	zexth      	r5, r5
     eec:	4741      	lsli      	r2, r7, 1
     eee:	609c      	addu      	r2, r7
     ef0:	5241      	asri      	r2, r2, 1
     ef2:	6549      	cmplt      	r2, r5
     ef4:	0c03      	bf      	0xefa	// efa <tkey_trigger_auto_adjust+0x46>
			{
				byTrigger_auto_f=2;
     ef6:	3202      	movi      	r2, 2
     ef8:	a340      	st.b      	r2, (r3, 0x0)
     efa:	2400      	addi      	r4, 1
		for(i=0;i<32;i++)
     efc:	eb440020 	cmpnei      	r4, 32
     f00:	0bef      	bt      	0xede	// ede <tkey_trigger_auto_adjust+0x2a>
     f02:	3400      	movi      	r4, 0
			}
		}
		for(i=0;i<32;i++)
		{
			if(hwOffset_max_data[i]>(hwTkeyTriggerLevel[i]*4))
     f04:	4441      	lsli      	r2, r4, 1
     f06:	58a8      	addu      	r5, r0, r2
     f08:	6084      	addu      	r2, r1
     f0a:	8da0      	ld.h      	r5, (r5, 0x0)
     f0c:	8a40      	ld.h      	r2, (r2, 0x0)
     f0e:	7489      	zexth      	r2, r2
     f10:	7555      	zexth      	r5, r5
     f12:	4242      	lsli      	r2, r2, 2
     f14:	6549      	cmplt      	r2, r5
     f16:	0c03      	bf      	0xf1c	// f1c <tkey_trigger_auto_adjust+0x68>
			{
				byTrigger_auto_f=3;
     f18:	3203      	movi      	r2, 3
     f1a:	a340      	st.b      	r2, (r3, 0x0)
     f1c:	2400      	addi      	r4, 1
		for(i=0;i<32;i++)
     f1e:	eb440020 	cmpnei      	r4, 32
     f22:	0bf1      	bt      	0xf04	// f04 <tkey_trigger_auto_adjust+0x50>
			}
		}
	}
	if(byTrigger_auto_f==3)		
     f24:	8340      	ld.b      	r2, (r3, 0x0)
     f26:	3a43      	cmpnei      	r2, 3
     f28:	0811      	bt      	0xf4a	// f4a <tkey_trigger_auto_adjust+0x96>
	{
		byTrigger_auto_f=4;
     f2a:	3204      	movi      	r2, 4
     f2c:	3100      	movi      	r1, 0
     f2e:	a340      	st.b      	r2, (r3, 0x0)
		for(i=0;i<32;i++)
		{
			hwTkeyTriggerLevel[i]=hwTkeyTriggerLevel[i]*3;
     f30:	0299      	lrw      	r4, 0x200003fc	// 11c8 <csi_tkey_setup_sleep+0xb0>
     f32:	4101      	lsli      	r0, r1, 1
     f34:	6010      	addu      	r0, r4
     f36:	8840      	ld.h      	r2, (r0, 0x0)
     f38:	7489      	zexth      	r2, r2
     f3a:	2100      	addi      	r1, 1
		for(i=0;i<32;i++)
     f3c:	eb410020 	cmpnei      	r1, 32
			hwTkeyTriggerLevel[i]=hwTkeyTriggerLevel[i]*3;
     f40:	42a1      	lsli      	r5, r2, 1
     f42:	6094      	addu      	r2, r5
     f44:	7489      	zexth      	r2, r2
     f46:	a840      	st.h      	r2, (r0, 0x0)
		for(i=0;i<32;i++)
     f48:	0bf5      	bt      	0xf32	// f32 <tkey_trigger_auto_adjust+0x7e>
		}
	}
	if(byTrigger_auto_f==2)		
     f4a:	8340      	ld.b      	r2, (r3, 0x0)
     f4c:	3a42      	cmpnei      	r2, 2
     f4e:	0828      	bt      	0xf9e	// f9e <tkey_trigger_auto_adjust+0xea>
	{
		byTrigger_auto_f=0;
     f50:	3200      	movi      	r2, 0
		for(i=0;i<32;i++)
		{
			if ((dwKey_Map_temp1 & (1<<i))!=0)
     f52:	0380      	lrw      	r4, 0x2000043c	// 11cc <csi_tkey_setup_sleep+0xb4>
			{
				hwTkeyTriggerLevel[i]=hwOffset_max_data[i]/2;
     f54:	03a3      	lrw      	r5, 0x200005ee	// 11c4 <csi_tkey_setup_sleep+0xac>
     f56:	03c2      	lrw      	r6, 0x200003fc	// 11c8 <csi_tkey_setup_sleep+0xb0>
		byTrigger_auto_f=0;
     f58:	a340      	st.b      	r2, (r3, 0x0)
     f5a:	3200      	movi      	r2, 0
			if ((dwKey_Map_temp1 & (1<<i))!=0)
     f5c:	3101      	movi      	r1, 1
     f5e:	9400      	ld.w      	r0, (r4, 0x0)
     f60:	7048      	lsl      	r1, r2
     f62:	6840      	and      	r1, r0
     f64:	3940      	cmpnei      	r1, 0
     f66:	0c18      	bf      	0xf96	// f96 <tkey_trigger_auto_adjust+0xe2>
				hwTkeyTriggerLevel[i]=hwOffset_max_data[i]/2;
     f68:	4201      	lsli      	r0, r2, 1
     f6a:	5d20      	addu      	r1, r5, r0
     f6c:	8920      	ld.h      	r1, (r1, 0x0)
     f6e:	7445      	zexth      	r1, r1
     f70:	4921      	lsri      	r1, r1, 1
     f72:	6018      	addu      	r0, r6
     f74:	a820      	st.h      	r1, (r0, 0x0)
				byTrigger_cnt++;
     f76:	0308      	lrw      	r0, 0x20000520	// 11d0 <csi_tkey_setup_sleep+0xb8>
     f78:	8020      	ld.b      	r1, (r0, 0x0)
     f7a:	2100      	addi      	r1, 1
     f7c:	7444      	zextb      	r1, r1
     f7e:	a020      	st.b      	r1, (r0, 0x0)
				if(byTrigger_cnt==byTk_num)
     f80:	032a      	lrw      	r1, 0x200003b2	// 11d4 <csi_tkey_setup_sleep+0xbc>
     f82:	80e0      	ld.b      	r7, (r0, 0x0)
     f84:	8120      	ld.b      	r1, (r1, 0x0)
     f86:	645e      	cmpne      	r7, r1
     f88:	0807      	bt      	0xf96	// f96 <tkey_trigger_auto_adjust+0xe2>
				{
					byTrigger_cnt=0;
     f8a:	3100      	movi      	r1, 0
     f8c:	a020      	st.b      	r1, (r0, 0x0)
					byTrigger_auto_f=4;
     f8e:	3104      	movi      	r1, 4
     f90:	a320      	st.b      	r1, (r3, 0x0)
					dwKey_Map_temp1=0;
     f92:	3100      	movi      	r1, 0
     f94:	b420      	st.w      	r1, (r4, 0x0)
     f96:	2200      	addi      	r2, 1
		for(i=0;i<32;i++)
     f98:	eb420020 	cmpnei      	r2, 32
     f9c:	0be0      	bt      	0xf5c	// f5c <tkey_trigger_auto_adjust+0xa8>
				}
			}
		}
	}
	}
}
     f9e:	1401      	addi      	r14, r14, 4
     fa0:	1484      	pop      	r4-r7
	if((dwKey_Map!=0)&&(byTrigger_auto_f==0))
     fa2:	8320      	ld.b      	r1, (r3, 0x0)
     fa4:	3940      	cmpnei      	r1, 0
     fa6:	0b92      	bt      	0xeca	// eca <tkey_trigger_auto_adjust+0x16>
		if(dwKey_Map_temp1==dwKey_Map)
     fa8:	0336      	lrw      	r1, 0x2000043c	// 11cc <csi_tkey_setup_sleep+0xb4>
     faa:	9180      	ld.w      	r4, (r1, 0x0)
     fac:	9200      	ld.w      	r0, (r2, 0x0)
     fae:	6412      	cmpne      	r4, r0
     fb0:	0ff7      	bf      	0xf9e	// f9e <tkey_trigger_auto_adjust+0xea>
			dwKey_Map_temp1=dwKey_Map;
     fb2:	9200      	ld.w      	r0, (r2, 0x0)
		if(hwOffset_data0_abs[i]>hwOffset_max_data[i])
     fb4:	03fb      	lrw      	r7, 0x200005ee	// 11c4 <csi_tkey_setup_sleep+0xac>
			dwKey_Map_temp1=dwKey_Map;
     fb6:	b100      	st.w      	r0, (r1, 0x0)
			byTrigger_auto_f=1;
     fb8:	3101      	movi      	r1, 1
     fba:	3000      	movi      	r0, 0
     fbc:	a320      	st.b      	r1, (r3, 0x0)
		if(hwOffset_data0_abs[i]>hwOffset_max_data[i])
     fbe:	0338      	lrw      	r1, 0x20000372	// 11d8 <csi_tkey_setup_sleep+0xc0>
     fc0:	b820      	st.w      	r1, (r14, 0x0)
     fc2:	4021      	lsli      	r1, r0, 1
     fc4:	98c0      	ld.w      	r6, (r14, 0x0)
     fc6:	6184      	addu      	r6, r1
     fc8:	605c      	addu      	r1, r7
     fca:	8ea0      	ld.h      	r5, (r6, 0x0)
     fcc:	8980      	ld.h      	r4, (r1, 0x0)
     fce:	7555      	zexth      	r5, r5
     fd0:	7511      	zexth      	r4, r4
     fd2:	6550      	cmphs      	r4, r5
     fd4:	0804      	bt      	0xfdc	// fdc <tkey_trigger_auto_adjust+0x128>
			hwOffset_max_data[i]=hwOffset_data0_abs[i];
     fd6:	8e80      	ld.h      	r4, (r6, 0x0)
     fd8:	7511      	zexth      	r4, r4
     fda:	a980      	st.h      	r4, (r1, 0x0)
     fdc:	2000      	addi      	r0, 1
		for(i=0;i<32;i++)
     fde:	eb400020 	cmpnei      	r0, 32
     fe2:	0bf0      	bt      	0xfc2	// fc2 <tkey_trigger_auto_adjust+0x10e>
     fe4:	0773      	br      	0xeca	// eca <tkey_trigger_auto_adjust+0x16>

00000fe6 <csi_tkey_hiddenpara_init>:
/****************************************************
//TK hidden parameter config
*****************************************************/
void csi_tkey_hiddenpara_init(void)
{
	byTkeyDstStatus=2;
     fe6:	137e      	lrw      	r3, 0x200004fd	// 11dc <csi_tkey_setup_sleep+0xc4>
     fe8:	3202      	movi      	r2, 2
     fea:	a340      	st.b      	r2, (r3, 0x0)
	byTkeyIntrStatus=0;
     fec:	3200      	movi      	r2, 0
     fee:	137d      	lrw      	r3, 0x200004a7	// 11e0 <csi_tkey_setup_sleep+0xc8>
     ff0:	a340      	st.b      	r2, (r3, 0x0)
	byTkeyImtvtimTime=0;
     ff2:	137d      	lrw      	r3, 0x200003b4	// 11e4 <csi_tkey_setup_sleep+0xcc>
     ff4:	a340      	st.b      	r2, (r3, 0x0)
	byTkeyNegBuildBounce=3;
     ff6:	3203      	movi      	r2, 3
     ff8:	137c      	lrw      	r3, 0x200003b6	// 11e8 <csi_tkey_setup_sleep+0xd0>
     ffa:	a340      	st.b      	r2, (r3, 0x0)
	byTkeyPosBuildBounce=3;
     ffc:	137c      	lrw      	r3, 0x200004ee	// 11ec <csi_tkey_setup_sleep+0xd4>
     ffe:	a340      	st.b      	r2, (r3, 0x0)
}
    1000:	783c      	jmp      	r15

00001002 <tkey_para_config>:
/****************************************************
//TK parameter config
*****************************************************/
void tkey_para_config(void)
{
    1002:	14d4      	push      	r4-r7, r15
    1004:	1421      	subi      	r14, r14, 4
	unsigned char i;
	csi_tkey_hiddenpara_init();
    1006:	e3fffff0 	bsr      	0xfe6	// fe6 <csi_tkey_hiddenpara_init>
	csi_tkey_parameter_init();
    100a:	e000046f 	bsr      	0x18e8	// 18e8 <csi_tkey_parameter_init>
	if(byTkeyGlobalSens!=0)
    100e:	1319      	lrw      	r0, 0x200005ac	// 11f0 <csi_tkey_setup_sleep+0xd8>
    1010:	1339      	lrw      	r1, 0x200004ae	// 11f4 <csi_tkey_setup_sleep+0xdc>
    1012:	8060      	ld.b      	r3, (r0, 0x0)
    1014:	3b40      	cmpnei      	r3, 0
    1016:	0c20      	bf      	0x1056	// 1056 <tkey_para_config+0x54>
    1018:	3200      	movi      	r2, 0
	{
		for(i=0;i<32;i++)
		{
			hwTkeySenprd[i]=500+((byTkeyGlobalSens-1)*250);
    101a:	34fa      	movi      	r4, 250
    101c:	42a1      	lsli      	r5, r2, 1
    101e:	2200      	addi      	r2, 1
		for(i=0;i<32;i++)
    1020:	eb420020 	cmpnei      	r2, 32
			hwTkeySenprd[i]=500+((byTkeyGlobalSens-1)*250);
    1024:	8060      	ld.b      	r3, (r0, 0x0)
    1026:	6144      	addu      	r5, r1
    1028:	2b00      	subi      	r3, 1
    102a:	7cd0      	mult      	r3, r4
    102c:	e46301f3 	addi      	r3, r3, 500
    1030:	74cd      	zexth      	r3, r3
    1032:	ad60      	st.h      	r3, (r5, 0x0)
		for(i=0;i<32;i++)
    1034:	0bf4      	bt      	0x101c	// 101c <tkey_para_config+0x1a>
		for(i=0;i<32;i++)
		{
			hwTkeySenprd[i]=200;
		}
	}
	if((hwTkeyGlobalTrigger!=0)&&(hwTkeyGlobalTrigger>20))
    1036:	1371      	lrw      	r3, 0x200003f8	// 11f8 <csi_tkey_setup_sleep+0xe0>
    1038:	1304      	lrw      	r0, 0x200003fc	// 11c8 <csi_tkey_setup_sleep+0xb0>
    103a:	8b40      	ld.h      	r2, (r3, 0x0)
    103c:	7489      	zexth      	r2, r2
    103e:	3a40      	cmpnei      	r2, 0
    1040:	0815      	bt      	0x106a	// 106a <tkey_para_config+0x68>
    1042:	3300      	movi      	r3, 0
	}
	else
	{
		for(i=0;i<32;i++)
		{
			hwTkeyTriggerLevel[i]=50;
    1044:	4341      	lsli      	r2, r3, 1
    1046:	3432      	movi      	r4, 50
    1048:	2300      	addi      	r3, 1
		for(i=0;i<32;i++)
    104a:	eb430020 	cmpnei      	r3, 32
			hwTkeyTriggerLevel[i]=50;
    104e:	6080      	addu      	r2, r0
    1050:	aa80      	st.h      	r4, (r2, 0x0)
		for(i=0;i<32;i++)
    1052:	0bf9      	bt      	0x1044	// 1044 <tkey_para_config+0x42>
    1054:	0419      	br      	0x1086	// 1086 <tkey_para_config+0x84>
    1056:	3300      	movi      	r3, 0
			hwTkeySenprd[i]=200;
    1058:	4341      	lsli      	r2, r3, 1
    105a:	30c8      	movi      	r0, 200
    105c:	2300      	addi      	r3, 1
		for(i=0;i<32;i++)
    105e:	eb430020 	cmpnei      	r3, 32
			hwTkeySenprd[i]=200;
    1062:	6084      	addu      	r2, r1
    1064:	aa00      	st.h      	r0, (r2, 0x0)
		for(i=0;i<32;i++)
    1066:	0bf9      	bt      	0x1058	// 1058 <tkey_para_config+0x56>
    1068:	07e7      	br      	0x1036	// 1036 <tkey_para_config+0x34>
	if((hwTkeyGlobalTrigger!=0)&&(hwTkeyGlobalTrigger>20))
    106a:	8b40      	ld.h      	r2, (r3, 0x0)
    106c:	7489      	zexth      	r2, r2
    106e:	3a14      	cmphsi      	r2, 21
    1070:	0fe9      	bf      	0x1042	// 1042 <tkey_para_config+0x40>
    1072:	3200      	movi      	r2, 0
			hwTkeyTriggerLevel[i]=hwTkeyGlobalTrigger;
    1074:	8ba0      	ld.h      	r5, (r3, 0x0)
    1076:	4281      	lsli      	r4, r2, 1
    1078:	2200      	addi      	r2, 1
		for(i=0;i<32;i++)
    107a:	eb420020 	cmpnei      	r2, 32
			hwTkeyTriggerLevel[i]=hwTkeyGlobalTrigger;
    107e:	7555      	zexth      	r5, r5
    1080:	6100      	addu      	r4, r0
    1082:	aca0      	st.h      	r5, (r4, 0x0)
		for(i=0;i<32;i++)
    1084:	0bf8      	bt      	0x1074	// 1074 <tkey_para_config+0x72>
		}
	}
	if(byTkeyGlobalIcon!=0)
    1086:	127e      	lrw      	r3, 0x20000462	// 11fc <csi_tkey_setup_sleep+0xe4>
    1088:	129e      	lrw      	r4, 0x200005cd	// 1200 <csi_tkey_setup_sleep+0xe8>
    108a:	8340      	ld.b      	r2, (r3, 0x0)
    108c:	3a40      	cmpnei      	r2, 0
    108e:	6c8f      	mov      	r2, r3
    1090:	3300      	movi      	r3, 0
    1092:	0809      	bt      	0x10a4	// 10a4 <tkey_para_config+0xa2>
	}
	else
	{
		for(i=0;i<32;i++)
		{
			byTkeyIcon[i]=4;
    1094:	5c4c      	addu      	r2, r4, r3
    1096:	3504      	movi      	r5, 4
    1098:	2300      	addi      	r3, 1
		for(i=0;i<32;i++)
    109a:	eb430020 	cmpnei      	r3, 32
			byTkeyIcon[i]=4;
    109e:	a2a0      	st.b      	r5, (r2, 0x0)
		for(i=0;i<32;i++)
    10a0:	0bfa      	bt      	0x1094	// 1094 <tkey_para_config+0x92>
    10a2:	0409      	br      	0x10b4	// 10b4 <tkey_para_config+0xb2>
			byTkeyIcon[i]=byTkeyGlobalIcon;
    10a4:	82a0      	ld.b      	r5, (r2, 0x0)
    10a6:	5ccc      	addu      	r6, r4, r3
    10a8:	2300      	addi      	r3, 1
		for(i=0;i<32;i++)
    10aa:	eb430020 	cmpnei      	r3, 32
			byTkeyIcon[i]=byTkeyGlobalIcon;
    10ae:	7554      	zextb      	r5, r5
    10b0:	a6a0      	st.b      	r5, (r6, 0x0)
		for(i=0;i<32;i++)
    10b2:	0bf9      	bt      	0x10a4	// 10a4 <tkey_para_config+0xa2>
		}
	}
	if(byTkeyFineTurn==ENABLE)
    10b4:	1274      	lrw      	r3, 0x200003b5	// 1204 <csi_tkey_setup_sleep+0xec>
    10b6:	8360      	ld.b      	r3, (r3, 0x0)
    10b8:	3b41      	cmpnei      	r3, 1
    10ba:	082d      	bt      	0x1114	// 1114 <tkey_para_config+0x112>
	{
	for(i=0;i<32;i++)
	{
	if(byTkeyChxSens[i]!=0)
    10bc:	1253      	lrw      	r2, 0x20000500	// 1208 <csi_tkey_setup_sleep+0xf0>
    10be:	3300      	movi      	r3, 0
    10c0:	b840      	st.w      	r2, (r14, 0x0)
		{
			hwTkeySenprd[i]=500+((byTkeyChxSens[i]-1)*250);
		}
	if((byTkeyChxTrigger[i]!=0)&&(byTkeyChxTrigger[i]>20))
    10c2:	12b3      	lrw      	r5, 0x2000058c	// 120c <csi_tkey_setup_sleep+0xf4>
		{
			hwTkeyTriggerLevel[i]=byTkeyChxTrigger[i];
		}
	if(byTkeyChxIcon[i]!=0)
    10c4:	12d3      	lrw      	r6, 0x20000441	// 1210 <csi_tkey_setup_sleep+0xf8>
	if(byTkeyChxSens[i]!=0)
    10c6:	9840      	ld.w      	r2, (r14, 0x0)
    10c8:	608c      	addu      	r2, r3
    10ca:	82e0      	ld.b      	r7, (r2, 0x0)
    10cc:	3f40      	cmpnei      	r7, 0
    10ce:	0c0b      	bf      	0x10e4	// 10e4 <tkey_para_config+0xe2>
			hwTkeySenprd[i]=500+((byTkeyChxSens[i]-1)*250);
    10d0:	37fa      	movi      	r7, 250
    10d2:	8240      	ld.b      	r2, (r2, 0x0)
    10d4:	2a00      	subi      	r2, 1
    10d6:	7c9c      	mult      	r2, r7
    10d8:	43e1      	lsli      	r7, r3, 1
    10da:	e44201f3 	addi      	r2, r2, 500
    10de:	61c4      	addu      	r7, r1
    10e0:	7489      	zexth      	r2, r2
    10e2:	af40      	st.h      	r2, (r7, 0x0)
	if((byTkeyChxTrigger[i]!=0)&&(byTkeyChxTrigger[i]>20))
    10e4:	5d4c      	addu      	r2, r5, r3
    10e6:	82e0      	ld.b      	r7, (r2, 0x0)
    10e8:	3f40      	cmpnei      	r7, 0
    10ea:	0c09      	bf      	0x10fc	// 10fc <tkey_para_config+0xfa>
    10ec:	82e0      	ld.b      	r7, (r2, 0x0)
    10ee:	75dc      	zextb      	r7, r7
    10f0:	3f14      	cmphsi      	r7, 21
    10f2:	0c05      	bf      	0x10fc	// 10fc <tkey_para_config+0xfa>
			hwTkeyTriggerLevel[i]=byTkeyChxTrigger[i];
    10f4:	82e0      	ld.b      	r7, (r2, 0x0)
    10f6:	4341      	lsli      	r2, r3, 1
    10f8:	6080      	addu      	r2, r0
    10fa:	aae0      	st.h      	r7, (r2, 0x0)
	if(byTkeyChxIcon[i]!=0)
    10fc:	5e4c      	addu      	r2, r6, r3
    10fe:	82e0      	ld.b      	r7, (r2, 0x0)
    1100:	3f40      	cmpnei      	r7, 0
    1102:	0c05      	bf      	0x110c	// 110c <tkey_para_config+0x10a>
		{
			byTkeyIcon[i]=byTkeyChxIcon[i];
    1104:	8240      	ld.b      	r2, (r2, 0x0)
    1106:	7488      	zextb      	r2, r2
    1108:	5cec      	addu      	r7, r4, r3
    110a:	a740      	st.b      	r2, (r7, 0x0)
    110c:	2300      	addi      	r3, 1
	for(i=0;i<32;i++)
    110e:	eb430020 	cmpnei      	r3, 32
    1112:	0bda      	bt      	0x10c6	// 10c6 <tkey_para_config+0xc4>
		}
	}
	}
}
    1114:	1401      	addi      	r14, r14, 4
    1116:	1494      	pop      	r4-r7, r15

00001118 <csi_tkey_setup_sleep>:
//Tkey Sleep Functions
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void csi_tkey_setup_sleep(void)
{
    1118:	14d4      	push      	r4-r7, r15
    111a:	1424      	subi      	r14, r14, 16
	unsigned short INTVTIM_x=0;
	unsigned char i;
	switch (byTkeyLowPowerLevel)
    111c:	117e      	lrw      	r3, 0x200004a8	// 1214 <csi_tkey_setup_sleep+0xfc>
    111e:	8360      	ld.b      	r3, (r3, 0x0)
    1120:	2b00      	subi      	r3, 1
    1122:	74cc      	zextb      	r3, r3
    1124:	3b04      	cmphsi      	r3, 5
    1126:	0844      	bt      	0x11ae	// 11ae <csi_tkey_setup_sleep+0x96>
    1128:	4361      	lsli      	r3, r3, 1
    112a:	115c      	lrw      	r2, 0x34b4	// 1218 <csi_tkey_setup_sleep+0x100>
    112c:	60c8      	addu      	r3, r2
    112e:	8b80      	ld.h      	r4, (r3, 0x0)
			case 2: INTVTIM_x=2<<12;break;
			case 3: INTVTIM_x=3<<12;break;
			case 4: INTVTIM_x=4<<12;break;
			case 5: INTVTIM_x=5<<12;break;
        }
	TKEY_RSSR = 0;
    1130:	3200      	movi      	r2, 0
    1132:	ea234002 	movih      	r3, 16386
	while(!((TKEY_TKST&TK_BUSY)!=TK_BUSY));
    1136:	3180      	movi      	r1, 128
	TKEY_RSSR = 0;
    1138:	b344      	st.w      	r2, (r3, 0x10)
	while(!((TKEY_TKST&TK_BUSY)!=TK_BUSY));
    113a:	4125      	lsli      	r1, r1, 5
    113c:	9347      	ld.w      	r2, (r3, 0x1c)
    113e:	6884      	and      	r2, r1
    1140:	3a40      	cmpnei      	r2, 0
    1142:	0bfd      	bt      	0x113c	// 113c <csi_tkey_setup_sleep+0x24>
	tkey_wakeup_io_config();
    1144:	e3fff94c 	bsr      	0x3dc	// 3dc <tkey_wakeup_io_config>
	byTk_num=get_key_seq(dwTkeyWakeupIoEnable);
    1148:	1175      	lrw      	r3, 0x200004f8	// 121c <csi_tkey_setup_sleep+0x104>
	memset((void *)TKEYB->TCH_SEQxCON,0,sizeof(TKEYB->TCH_SEQxCON));
    114a:	11d6      	lrw      	r6, 0x200000ac	// 1220 <csi_tkey_setup_sleep+0x108>
	byTk_num=get_key_seq(dwTkeyWakeupIoEnable);
    114c:	11a2      	lrw      	r5, 0x200003b2	// 11d4 <csi_tkey_setup_sleep+0xbc>
	for(i=0;i<byTk_num;i++)
	{
	TKEYB->TCH_SEQxCON[i]=(0x1<<27)|(((byTkeyIcon[byTk_seque[i]]>>4)&3)<<25)|((byTkeyIcon[byTk_seque[i]]&0xf)<<21)|(byTk_seque[i]<<16)|(hwTkeySenprd[byTk_seque[i]]<<0);
    114e:	11ed      	lrw      	r7, 0x200005cd	// 1200 <csi_tkey_setup_sleep+0xe8>
	byTk_num=get_key_seq(dwTkeyWakeupIoEnable);
    1150:	9300      	ld.w      	r0, (r3, 0x0)
    1152:	e3fffb6d 	bsr      	0x82c	// 82c <get_key_seq>
	memset((void *)TKEYB->TCH_SEQxCON,0,sizeof(TKEYB->TCH_SEQxCON));
    1156:	3280      	movi      	r2, 128
	byTk_num=get_key_seq(dwTkeyWakeupIoEnable);
    1158:	a500      	st.b      	r0, (r5, 0x0)
	memset((void *)TKEYB->TCH_SEQxCON,0,sizeof(TKEYB->TCH_SEQxCON));
    115a:	3100      	movi      	r1, 0
    115c:	9601      	ld.w      	r0, (r6, 0x4)
    115e:	e00002e9 	bsr      	0x1730	// 1730 <__memset_fast>
	TKEYB->TCH_SEQxCON[i]=(0x1<<27)|(((byTkeyIcon[byTk_seque[i]]>>4)&3)<<25)|((byTkeyIcon[byTk_seque[i]]&0xf)<<21)|(byTk_seque[i]<<16)|(hwTkeySenprd[byTk_seque[i]]<<0);
    1162:	1151      	lrw      	r2, 0x20000525	// 1224 <csi_tkey_setup_sleep+0x10c>
    1164:	9661      	ld.w      	r3, (r6, 0x4)
    1166:	b842      	st.w      	r2, (r14, 0x8)
    1168:	b860      	st.w      	r3, (r14, 0x0)
	for(i=0;i<byTk_num;i++)
    116a:	3300      	movi      	r3, 0
	TKEYB->TCH_SEQxCON[i]=(0x1<<27)|(((byTkeyIcon[byTk_seque[i]]>>4)&3)<<25)|((byTkeyIcon[byTk_seque[i]]&0xf)<<21)|(byTk_seque[i]<<16)|(hwTkeySenprd[byTk_seque[i]]<<0);
    116c:	1142      	lrw      	r2, 0x200004ae	// 11f4 <csi_tkey_setup_sleep+0xdc>
    116e:	b843      	st.w      	r2, (r14, 0xc)
	for(i=0;i<byTk_num;i++)
    1170:	8540      	ld.b      	r2, (r5, 0x0)
    1172:	648c      	cmphs      	r3, r2
    1174:	0c5c      	bf      	0x122c	// 122c <csi_tkey_setup_sleep+0x114>
	}
	TKEY_CON0=(TKEY_CON0&0xffff8f83)|INTVTIM_x|((byTk_num-1)<<2);
    1176:	ea234002 	movih      	r3, 16386
    117a:	9322      	ld.w      	r1, (r3, 0x8)
    117c:	110b      	lrw      	r0, 0xffff8f83	// 1228 <csi_tkey_setup_sleep+0x110>
    117e:	8540      	ld.b      	r2, (r5, 0x0)
    1180:	6840      	and      	r1, r0
    1182:	2a00      	subi      	r2, 1
    1184:	4242      	lsli      	r2, r2, 2
    1186:	6c84      	or      	r2, r1
    1188:	6d08      	or      	r4, r2
	TKEY_EVTRG=0;
    118a:	3200      	movi      	r2, 0
	TKEY_CON0=(TKEY_CON0&0xffff8f83)|INTVTIM_x|((byTk_num-1)<<2);
    118c:	b382      	st.w      	r4, (r3, 0x8)
	TKEY_EVTRG=0;
    118e:	b34d      	st.w      	r2, (r3, 0x34)
	TKEY_IMCR = (TKEY_IMCR&0x00)|TK_THROVR;
	TKEY_ICR=0x7f;
	TKEY_RSSR = 1;	
	while(!((TKEY_TKST&TK_BUSY)==TK_BUSY));
    1190:	3180      	movi      	r1, 128
	TKEY_IMCR = (TKEY_IMCR&0x00)|TK_THROVR;
    1192:	934b      	ld.w      	r2, (r3, 0x2c)
    1194:	3220      	movi      	r2, 32
	while(!((TKEY_TKST&TK_BUSY)==TK_BUSY));
    1196:	4125      	lsli      	r1, r1, 5
	TKEY_IMCR = (TKEY_IMCR&0x00)|TK_THROVR;
    1198:	b34b      	st.w      	r2, (r3, 0x2c)
	TKEY_ICR=0x7f;
    119a:	327f      	movi      	r2, 127
    119c:	b34c      	st.w      	r2, (r3, 0x30)
	TKEY_RSSR = 1;	
    119e:	3201      	movi      	r2, 1
    11a0:	b344      	st.w      	r2, (r3, 0x10)
	while(!((TKEY_TKST&TK_BUSY)==TK_BUSY));
    11a2:	9347      	ld.w      	r2, (r3, 0x1c)
    11a4:	6884      	and      	r2, r1
    11a6:	3a40      	cmpnei      	r2, 0
    11a8:	0ffd      	bf      	0x11a2	// 11a2 <csi_tkey_setup_sleep+0x8a>
}
    11aa:	1404      	addi      	r14, r14, 16
    11ac:	1494      	pop      	r4-r7, r15
	switch (byTkeyLowPowerLevel)
    11ae:	3400      	movi      	r4, 0
    11b0:	07c0      	br      	0x1130	// 1130 <csi_tkey_setup_sleep+0x18>
    11b2:	0000      	bkpt
    11b4:	200004fe 	.long	0x200004fe
    11b8:	200003fa 	.long	0x200003fa
    11bc:	20000324 	.long	0x20000324
    11c0:	2000036c 	.long	0x2000036c
    11c4:	200005ee 	.long	0x200005ee
    11c8:	200003fc 	.long	0x200003fc
    11cc:	2000043c 	.long	0x2000043c
    11d0:	20000520 	.long	0x20000520
    11d4:	200003b2 	.long	0x200003b2
    11d8:	20000372 	.long	0x20000372
    11dc:	200004fd 	.long	0x200004fd
    11e0:	200004a7 	.long	0x200004a7
    11e4:	200003b4 	.long	0x200003b4
    11e8:	200003b6 	.long	0x200003b6
    11ec:	200004ee 	.long	0x200004ee
    11f0:	200005ac 	.long	0x200005ac
    11f4:	200004ae 	.long	0x200004ae
    11f8:	200003f8 	.long	0x200003f8
    11fc:	20000462 	.long	0x20000462
    1200:	200005cd 	.long	0x200005cd
    1204:	200003b5 	.long	0x200003b5
    1208:	20000500 	.long	0x20000500
    120c:	2000058c 	.long	0x2000058c
    1210:	20000441 	.long	0x20000441
    1214:	200004a8 	.long	0x200004a8
    1218:	000034b4 	.long	0x000034b4
    121c:	200004f8 	.long	0x200004f8
    1220:	200000ac 	.long	0x200000ac
    1224:	20000525 	.long	0x20000525
    1228:	ffff8f83 	.long	0xffff8f83
	TKEYB->TCH_SEQxCON[i]=(0x1<<27)|(((byTkeyIcon[byTk_seque[i]]>>4)&3)<<25)|((byTkeyIcon[byTk_seque[i]]&0xf)<<21)|(byTk_seque[i]<<16)|(hwTkeySenprd[byTk_seque[i]]<<0);
    122c:	98c2      	ld.w      	r6, (r14, 0x8)
    122e:	618c      	addu      	r6, r3
    1230:	8640      	ld.b      	r2, (r6, 0x0)
    1232:	609c      	addu      	r2, r7
    1234:	8240      	ld.b      	r2, (r2, 0x0)
    1236:	8620      	ld.b      	r1, (r6, 0x0)
    1238:	605c      	addu      	r1, r7
    123a:	8120      	ld.b      	r1, (r1, 0x0)
    123c:	8600      	ld.b      	r0, (r6, 0x0)
    123e:	86c0      	ld.b      	r6, (r6, 0x0)
    1240:	b841      	st.w      	r2, (r14, 0x4)
    1242:	46c1      	lsli      	r6, r6, 1
    1244:	9843      	ld.w      	r2, (r14, 0xc)
    1246:	6188      	addu      	r6, r2
    1248:	8ec0      	ld.h      	r6, (r6, 0x0)
    124a:	4010      	lsli      	r0, r0, 16
    124c:	32f0      	movi      	r2, 240
    124e:	7599      	zexth      	r6, r6
    1250:	4135      	lsli      	r1, r1, 21
    1252:	4251      	lsli      	r2, r2, 17
    1254:	38bb      	bseti      	r0, 27
    1256:	6c18      	or      	r0, r6
    1258:	c4412026 	and      	r6, r1, r2
    125c:	9841      	ld.w      	r2, (r14, 0x4)
    125e:	6c18      	or      	r0, r6
    1260:	42d5      	lsli      	r6, r2, 21
    1262:	32c0      	movi      	r2, 192
    1264:	4253      	lsli      	r2, r2, 19
    1266:	6988      	and      	r6, r2
    1268:	6d80      	or      	r6, r0
    126a:	4342      	lsli      	r2, r3, 2
    126c:	9820      	ld.w      	r1, (r14, 0x0)
    126e:	6084      	addu      	r2, r1
	for(i=0;i<byTk_num;i++)
    1270:	2300      	addi      	r3, 1
	TKEYB->TCH_SEQxCON[i]=(0x1<<27)|(((byTkeyIcon[byTk_seque[i]]>>4)&3)<<25)|((byTkeyIcon[byTk_seque[i]]&0xf)<<21)|(byTk_seque[i]<<16)|(hwTkeySenprd[byTk_seque[i]]<<0);
    1272:	b2c0      	st.w      	r6, (r2, 0x0)
	for(i=0;i<byTk_num;i++)
    1274:	74cc      	zextb      	r3, r3
    1276:	077d      	br      	0x1170	// 1170 <csi_tkey_setup_sleep+0x58>

00001278 <csi_tkey_quit_sleep>:

void csi_tkey_quit_sleep(void)
{
    1278:	14d4      	push      	r4-r7, r15
    127a:	1422      	subi      	r14, r14, 8
	unsigned char i;
	TKEY_EVTRG=(0X01<<8)|(0X01<<0);
    127c:	ea020101 	movi      	r2, 257
    1280:	ea234002 	movih      	r3, 16386
    1284:	b34d      	st.w      	r2, (r3, 0x34)
	TKEY_IMCR = (TKEY_IMCR&0x00)|TK_REFOVF|TK_SEQ_DNE|TK_CH_ERR;
	TKEY_ICR=0x7f;
	TKEY_RSSR = 0;
	while(!((TKEY_TKST&TK_BUSY)!=TK_BUSY));
    1286:	3180      	movi      	r1, 128
	TKEY_IMCR = (TKEY_IMCR&0x00)|TK_REFOVF|TK_SEQ_DNE|TK_CH_ERR;
    1288:	934b      	ld.w      	r2, (r3, 0x2c)
    128a:	3215      	movi      	r2, 21
	while(!((TKEY_TKST&TK_BUSY)!=TK_BUSY));
    128c:	4125      	lsli      	r1, r1, 5
	TKEY_IMCR = (TKEY_IMCR&0x00)|TK_REFOVF|TK_SEQ_DNE|TK_CH_ERR;
    128e:	b34b      	st.w      	r2, (r3, 0x2c)
	TKEY_ICR=0x7f;
    1290:	327f      	movi      	r2, 127
    1292:	b34c      	st.w      	r2, (r3, 0x30)
	TKEY_RSSR = 0;
    1294:	3200      	movi      	r2, 0
    1296:	b344      	st.w      	r2, (r3, 0x10)
	while(!((TKEY_TKST&TK_BUSY)!=TK_BUSY));
    1298:	9347      	ld.w      	r2, (r3, 0x1c)
    129a:	6884      	and      	r2, r1
    129c:	3a40      	cmpnei      	r2, 0
    129e:	0bfd      	bt      	0x1298	// 1298 <csi_tkey_quit_sleep+0x20>
	tkey_io_enable();
    12a0:	e3fff784 	bsr      	0x1a8	// 1a8 <tkey_io_enable>
	byTk_num=get_key_seq(dwTkeyIoEnable);
    12a4:	016e      	lrw      	r3, 0x200004f0	// 15e8 <csi_tkey_int_process+0x12>
	memset((void *)TKEYB->TCH_SEQxCON,0,sizeof(TKEYB->TCH_SEQxCON));
    12a6:	01ad      	lrw      	r5, 0x200000ac	// 15ec <csi_tkey_int_process+0x16>
	byTk_num=get_key_seq(dwTkeyIoEnable);
    12a8:	018d      	lrw      	r4, 0x200003b2	// 15f0 <csi_tkey_int_process+0x1a>
	for(i=0;i<byTk_num;i++)
	{
	TKEYB->TCH_SEQxCON[i]=(0x1<<27)|(((byTkeyIcon[byTk_seque[i]]>>4)&3)<<25)|((byTkeyIcon[byTk_seque[i]]&0xf)<<21)|(byTk_seque[i]<<16)|(hwTkeySenprd[byTk_seque[i]]<<0);
    12aa:	01cc      	lrw      	r6, 0x200005cd	// 15f4 <csi_tkey_int_process+0x1e>
    12ac:	01ec      	lrw      	r7, 0x200004ae	// 15f8 <csi_tkey_int_process+0x22>
	byTk_num=get_key_seq(dwTkeyIoEnable);
    12ae:	9300      	ld.w      	r0, (r3, 0x0)
    12b0:	e3fffabe 	bsr      	0x82c	// 82c <get_key_seq>
	memset((void *)TKEYB->TCH_SEQxCON,0,sizeof(TKEYB->TCH_SEQxCON));
    12b4:	3280      	movi      	r2, 128
	byTk_num=get_key_seq(dwTkeyIoEnable);
    12b6:	a400      	st.b      	r0, (r4, 0x0)
	memset((void *)TKEYB->TCH_SEQxCON,0,sizeof(TKEYB->TCH_SEQxCON));
    12b8:	3100      	movi      	r1, 0
    12ba:	9501      	ld.w      	r0, (r5, 0x4)
    12bc:	e000023a 	bsr      	0x1730	// 1730 <__memset_fast>
	TKEYB->TCH_SEQxCON[i]=(0x1<<27)|(((byTkeyIcon[byTk_seque[i]]>>4)&3)<<25)|((byTkeyIcon[byTk_seque[i]]&0xf)<<21)|(byTk_seque[i]<<16)|(hwTkeySenprd[byTk_seque[i]]<<0);
    12c0:	9561      	ld.w      	r3, (r5, 0x4)
    12c2:	0150      	lrw      	r2, 0x20000525	// 15fc <csi_tkey_int_process+0x26>
    12c4:	b860      	st.w      	r3, (r14, 0x0)
    12c6:	b841      	st.w      	r2, (r14, 0x4)
	for(i=0;i<byTk_num;i++)
    12c8:	3300      	movi      	r3, 0
    12ca:	8440      	ld.b      	r2, (r4, 0x0)
    12cc:	648c      	cmphs      	r3, r2
    12ce:	0c18      	bf      	0x12fe	// 12fe <csi_tkey_quit_sleep+0x86>
	}
	TKEY_CON0=(TKEY_CON0&0xffff8f83)|byTkeyImtvtimTime|((byTk_num-1)<<2);
    12d0:	0133      	lrw      	r1, 0x200003b4	// 1600 <csi_tkey_int_process+0x2a>
    12d2:	ea224002 	movih      	r2, 16386
    12d6:	9262      	ld.w      	r3, (r2, 0x8)
    12d8:	8100      	ld.b      	r0, (r1, 0x0)
    12da:	8420      	ld.b      	r1, (r4, 0x0)
    12dc:	0195      	lrw      	r4, 0xffff8f83	// 1604 <csi_tkey_int_process+0x2e>
    12de:	68d0      	and      	r3, r4
    12e0:	6cc0      	or      	r3, r0
    12e2:	2900      	subi      	r1, 1
    12e4:	4122      	lsli      	r1, r1, 2
    12e6:	6cc4      	or      	r3, r1
    12e8:	b262      	st.w      	r3, (r2, 0x8)
	TKEY_RSSR = 1;	
    12ea:	3301      	movi      	r3, 1
	while(!((TKEY_TKST&TK_BUSY)==TK_BUSY));
    12ec:	3180      	movi      	r1, 128
	TKEY_RSSR = 1;	
    12ee:	b264      	st.w      	r3, (r2, 0x10)
	while(!((TKEY_TKST&TK_BUSY)==TK_BUSY));
    12f0:	4125      	lsli      	r1, r1, 5
    12f2:	9267      	ld.w      	r3, (r2, 0x1c)
    12f4:	68c4      	and      	r3, r1
    12f6:	3b40      	cmpnei      	r3, 0
    12f8:	0ffd      	bf      	0x12f2	// 12f2 <csi_tkey_quit_sleep+0x7a>
}
    12fa:	1402      	addi      	r14, r14, 8
    12fc:	1494      	pop      	r4-r7, r15
	TKEYB->TCH_SEQxCON[i]=(0x1<<27)|(((byTkeyIcon[byTk_seque[i]]>>4)&3)<<25)|((byTkeyIcon[byTk_seque[i]]&0xf)<<21)|(byTk_seque[i]<<16)|(hwTkeySenprd[byTk_seque[i]]<<0);
    12fe:	98a1      	ld.w      	r5, (r14, 0x4)
    1300:	614c      	addu      	r5, r3
    1302:	8540      	ld.b      	r2, (r5, 0x0)
    1304:	6098      	addu      	r2, r6
    1306:	8240      	ld.b      	r2, (r2, 0x0)
    1308:	8520      	ld.b      	r1, (r5, 0x0)
    130a:	6058      	addu      	r1, r6
    130c:	8120      	ld.b      	r1, (r1, 0x0)
    130e:	8500      	ld.b      	r0, (r5, 0x0)
    1310:	85a0      	ld.b      	r5, (r5, 0x0)
    1312:	45a1      	lsli      	r5, r5, 1
    1314:	615c      	addu      	r5, r7
    1316:	8da0      	ld.h      	r5, (r5, 0x0)
    1318:	4010      	lsli      	r0, r0, 16
    131a:	7555      	zexth      	r5, r5
    131c:	38bb      	bseti      	r0, 27
    131e:	6c14      	or      	r0, r5
    1320:	35f0      	movi      	r5, 240
    1322:	4135      	lsli      	r1, r1, 21
    1324:	45b1      	lsli      	r5, r5, 17
    1326:	6944      	and      	r5, r1
    1328:	6c14      	or      	r0, r5
    132a:	42b5      	lsli      	r5, r2, 21
    132c:	32c0      	movi      	r2, 192
    132e:	4253      	lsli      	r2, r2, 19
    1330:	6948      	and      	r5, r2
    1332:	6d40      	or      	r5, r0
    1334:	4342      	lsli      	r2, r3, 2
    1336:	9820      	ld.w      	r1, (r14, 0x0)
    1338:	6084      	addu      	r2, r1
	for(i=0;i<byTk_num;i++)
    133a:	2300      	addi      	r3, 1
	TKEYB->TCH_SEQxCON[i]=(0x1<<27)|(((byTkeyIcon[byTk_seque[i]]>>4)&3)<<25)|((byTkeyIcon[byTk_seque[i]]&0xf)<<21)|(byTk_seque[i]<<16)|(hwTkeySenprd[byTk_seque[i]]<<0);
    133c:	b2a0      	st.w      	r5, (r2, 0x0)
	for(i=0;i<byTk_num;i++)
    133e:	74cc      	zextb      	r3, r3
    1340:	07c5      	br      	0x12ca	// 12ca <csi_tkey_quit_sleep+0x52>

00001342 <tkey_sleep_para_init>:

void tkey_sleep_para_init(void)
{
	if(byTkeyLowPowerMode==ENABLE)
    1342:	026d      	lrw      	r3, 0x200004fc	// 1608 <csi_tkey_int_process+0x32>
    1344:	8360      	ld.b      	r3, (r3, 0x0)
    1346:	3b41      	cmpnei      	r3, 1
    1348:	0812      	bt      	0x136c	// 136c <tkey_sleep_para_init+0x2a>
	{
		TKEY_CON0 &=~(0x01<<20);
    134a:	ea234002 	movih      	r3, 16386
    134e:	9342      	ld.w      	r2, (r3, 0x8)
    1350:	3a94      	bclri      	r2, 20
    1352:	b342      	st.w      	r2, (r3, 0x8)
		TKEY_CCR =(TKEY_CCR&0xffff7fff) |(10<<17)|(10<<22)|(10<<27);
    1354:	0231      	lrw      	r1, 0xad6b7fff	// 160c <csi_tkey_int_process+0x36>
    1356:	9341      	ld.w      	r2, (r3, 0x4)
    1358:	6884      	and      	r2, r1
    135a:	ea215294 	movih      	r1, 21140
    135e:	6c84      	or      	r2, r1
    1360:	b341      	st.w      	r2, (r3, 0x4)
		TKEY_THR = (byTkeyWakeupLevel<<0)|(1<<8);
    1362:	0253      	lrw      	r2, 0x200003fb	// 1610 <csi_tkey_int_process+0x3a>
    1364:	8240      	ld.b      	r2, (r2, 0x0)
    1366:	ec420100 	ori      	r2, r2, 256
    136a:	b345      	st.w      	r2, (r3, 0x14)
	}
}
    136c:	783c      	jmp      	r15

0000136e <tkey_result_prog>:
/****************************************************
//TK result program
*****************************************************/
void tkey_result_prog(void)
{
    136e:	14d1      	push      	r4, r15
	if(dwKey_Map0!=0)
    1370:	0276      	lrw      	r3, 0x20000654	// 1614 <csi_tkey_int_process+0x3e>
    1372:	0295      	lrw      	r4, 0x20000324	// 1618 <csi_tkey_int_process+0x42>
    1374:	9340      	ld.w      	r2, (r3, 0x0)
    1376:	3a40      	cmpnei      	r2, 0
    1378:	0c1c      	bf      	0x13b0	// 13b0 <tkey_result_prog+0x42>
	{
		dwKey_Map=dwKey_Map0;							
    137a:	9360      	ld.w      	r3, (r3, 0x0)
    137c:	b460      	st.w      	r3, (r4, 0x0)
			dwKey_Map=0;
			hwOffset0_max_tempA=0;
			hwOffset0_max_tempB=0;
		}

	if(dwKey_Map!=0)
    137e:	9460      	ld.w      	r3, (r4, 0x0)
    1380:	3b40      	cmpnei      	r3, 0
    1382:	0278      	lrw      	r3, 0x20000588	// 161c <csi_tkey_int_process+0x46>
    1384:	0c1e      	bf      	0x13c0	// 13c0 <tkey_result_prog+0x52>
	{
		if(dwKey_Map!=dwKey_Map_temp0)
    1386:	9420      	ld.w      	r1, (r4, 0x0)
    1388:	9340      	ld.w      	r2, (r3, 0x0)
    138a:	6486      	cmpne      	r1, r2
    138c:	0c06      	bf      	0x1398	// 1398 <tkey_result_prog+0x2a>
		{
			dwKey_Map_temp0=dwKey_Map;
    138e:	9440      	ld.w      	r2, (r4, 0x0)
    1390:	b340      	st.w      	r2, (r3, 0x0)
			byValid_key_f=0;
    1392:	3200      	movi      	r2, 0
    1394:	027c      	lrw      	r3, 0x200004fe	// 1620 <csi_tkey_int_process+0x4a>
    1396:	a340      	st.b      	r2, (r3, 0x0)
		}
		if(get_key_pressed()>byValidKeyNum)
    1398:	e3fffb51 	bsr      	0xa3a	// a3a <get_key_pressed>
    139c:	027d      	lrw      	r3, 0x20000524	// 1624 <csi_tkey_int_process+0x4e>
    139e:	8360      	ld.b      	r3, (r3, 0x0)
    13a0:	640c      	cmphs      	r3, r0
    13a2:	0806      	bt      	0x13ae	// 13ae <tkey_result_prog+0x40>
		{
			dwKey_Map=0;
    13a4:	3300      	movi      	r3, 0
			byValid_key_f=1;
    13a6:	3201      	movi      	r2, 1
			dwKey_Map=0;
    13a8:	b460      	st.w      	r3, (r4, 0x0)
			byValid_key_f=1;
    13aa:	0361      	lrw      	r3, 0x200004fe	// 1620 <csi_tkey_int_process+0x4a>
    13ac:	a340      	st.b      	r2, (r3, 0x0)
	{
		dwKey_Map_temp0=0;
		byValid_key_f=0;
		dwTk_press_time_cnt=0;
	}
}
    13ae:	1491      	pop      	r4, r15
			dwKey_Map=0;
    13b0:	3300      	movi      	r3, 0
			hwOffset0_max_tempA=0;
    13b2:	3200      	movi      	r2, 0
			dwKey_Map=0;
    13b4:	b460      	st.w      	r3, (r4, 0x0)
			hwOffset0_max_tempA=0;
    13b6:	0362      	lrw      	r3, 0x20000320	// 1628 <csi_tkey_int_process+0x52>
    13b8:	ab40      	st.h      	r2, (r3, 0x0)
			hwOffset0_max_tempB=0;
    13ba:	0362      	lrw      	r3, 0x20000522	// 162c <csi_tkey_int_process+0x56>
    13bc:	ab40      	st.h      	r2, (r3, 0x0)
    13be:	07e0      	br      	0x137e	// 137e <tkey_result_prog+0x10>
		dwKey_Map_temp0=0;
    13c0:	3200      	movi      	r2, 0
    13c2:	b340      	st.w      	r2, (r3, 0x0)
		byValid_key_f=0;
    13c4:	0368      	lrw      	r3, 0x200004fe	// 1620 <csi_tkey_int_process+0x4a>
    13c6:	a340      	st.b      	r2, (r3, 0x0)
		dwTk_press_time_cnt=0;
    13c8:	3200      	movi      	r2, 0
    13ca:	0365      	lrw      	r3, 0x2000031c	// 1630 <csi_tkey_int_process+0x5a>
    13cc:	b340      	st.w      	r2, (r3, 0x0)
}
    13ce:	07f0      	br      	0x13ae	// 13ae <tkey_result_prog+0x40>

000013d0 <tkey_error_detect>:
/*************************************************************/
//TKEY error detect
/*************************************************************/
void tkey_error_detect(void)
{
    13d0:	14d0      	push      	r15
	byTk_error_cnt++;
    13d2:	0346      	lrw      	r2, 0x200004ac	// 1634 <csi_tkey_int_process+0x5e>
    13d4:	8260      	ld.b      	r3, (r2, 0x0)
    13d6:	2300      	addi      	r3, 1
    13d8:	74cc      	zextb      	r3, r3
    13da:	a260      	st.b      	r3, (r2, 0x0)
	if(byTk_error_cnt>=5)
    13dc:	8260      	ld.b      	r3, (r2, 0x0)
    13de:	74cc      	zextb      	r3, r3
    13e0:	3b04      	cmphsi      	r3, 5
    13e2:	0c0f      	bf      	0x1400	// 1400 <tkey_error_detect+0x30>
	{
		byTk_error_cnt=0;
    13e4:	3300      	movi      	r3, 0
    13e6:	a260      	st.b      	r3, (r2, 0x0)
		if((byTk_error_f&0x02)!=0)				//time over
    13e8:	036b      	lrw      	r3, 0x200004f4	// 1638 <csi_tkey_int_process+0x62>
    13ea:	8340      	ld.b      	r2, (r3, 0x0)
    13ec:	e4422002 	andi      	r2, r2, 2
    13f0:	3a40      	cmpnei      	r2, 0
    13f2:	0c07      	bf      	0x1400	// 1400 <tkey_error_detect+0x30>
		{
			byTk_error_f&=~(0x01<<1);
    13f4:	8340      	ld.b      	r2, (r3, 0x0)
    13f6:	e44220fd 	andi      	r2, r2, 253
    13fa:	a340      	st.b      	r2, (r3, 0x0)
			tkey_timeover_tune();
    13fc:	e3fffa53 	bsr      	0x8a2	// 8a2 <tkey_timeover_tune>
		}
	}
}
    1400:	1490      	pop      	r15

00001402 <csi_tkey_basecnt_process>:
}
/*************************************************************/
//TKEY int process
/*************************************************************/
void csi_tkey_basecnt_process(void)
{
    1402:	14d0      	push      	r15
	tkey_keymap_prog();
    1404:	e3fffc2c 	bsr      	0xc5c	// c5c <tkey_keymap_prog>
	tkey_baseline_tracking();
    1408:	e3fffb2a 	bsr      	0xa5c	// a5c <tkey_baseline_tracking>
	tkey_result_prog();
    140c:	e3ffffb1 	bsr      	0x136e	// 136e <tkey_result_prog>
	tkey_trigger_auto_adjust();
    1410:	e3fffd52 	bsr      	0xeb4	// eb4 <tkey_trigger_auto_adjust>
	tkey_overflow_predict();
    1414:	e3fffa9a 	bsr      	0x948	// 948 <tkey_overflow_predict>
	tkey_error_detect();
    1418:	e3ffffdc 	bsr      	0x13d0	// 13d0 <tkey_error_detect>
	if((dwKey_Map!=0)&&(byTkeyRebuildTime!=0))
    141c:	137f      	lrw      	r3, 0x20000324	// 1618 <csi_tkey_int_process+0x42>
    141e:	9360      	ld.w      	r3, (r3, 0x0)
    1420:	3b40      	cmpnei      	r3, 0
    1422:	0c14      	bf      	0x144a	// 144a <csi_tkey_basecnt_process+0x48>
    1424:	0339      	lrw      	r1, 0x20000322	// 163c <csi_tkey_int_process+0x66>
    1426:	8160      	ld.b      	r3, (r1, 0x0)
    1428:	3b40      	cmpnei      	r3, 0
    142a:	0c10      	bf      	0x144a	// 144a <csi_tkey_basecnt_process+0x48>
	{ 
		dwTk_press_time_cnt++;
    142c:	037e      	lrw      	r3, 0x2000031c	// 1630 <csi_tkey_int_process+0x5a>
		if(dwTk_press_time_cnt>(byTkeyRebuildTime*100))		//cnt base 10ms*100=1s
    142e:	3064      	movi      	r0, 100
		dwTk_press_time_cnt++;
    1430:	9340      	ld.w      	r2, (r3, 0x0)
    1432:	2200      	addi      	r2, 1
    1434:	b340      	st.w      	r2, (r3, 0x0)
		if(dwTk_press_time_cnt>(byTkeyRebuildTime*100))		//cnt base 10ms*100=1s
    1436:	8140      	ld.b      	r2, (r1, 0x0)
    1438:	7c80      	mult      	r2, r0
    143a:	9320      	ld.w      	r1, (r3, 0x0)
    143c:	6448      	cmphs      	r2, r1
    143e:	0806      	bt      	0x144a	// 144a <csi_tkey_basecnt_process+0x48>
		{
			byForceReBuild=1;
    1440:	035f      	lrw      	r2, 0x20000370	// 1640 <csi_tkey_int_process+0x6a>
    1442:	3101      	movi      	r1, 1
    1444:	a220      	st.b      	r1, (r2, 0x0)
			dwTk_press_time_cnt=0;
    1446:	3200      	movi      	r2, 0
    1448:	b340      	st.w      	r2, (r3, 0x0)
		}
	}
}
    144a:	1490      	pop      	r15

0000144c <csi_tkey_init>:
/****************************************************
//TK init
*****************************************************/
void csi_tkey_init(void)
{
    144c:	14d4      	push      	r4-r7, r15
    144e:	1422      	subi      	r14, r14, 8
	unsigned char i;
	byPoweron_1st_f=0;
    1450:	137d      	lrw      	r3, 0x20000461	// 1644 <csi_tkey_int_process+0x6e>
    1452:	3200      	movi      	r2, 0
    1454:	1386      	lrw      	r4, 0x200000ac	// 15ec <csi_tkey_int_process+0x16>
    1456:	a340      	st.b      	r2, (r3, 0x0)
	*(unsigned int *)0x40011028 |= 1<<6;			//使能频率调整
    1458:	135c      	lrw      	r2, 0x40011000	// 1648 <csi_tkey_int_process+0x72>
    145a:	926a      	ld.w      	r3, (r2, 0x28)
    145c:	ec630040 	ori      	r3, r3, 64
    1460:	b26a      	st.w      	r3, (r2, 0x28)
	*(unsigned int *)0x400111FC = 0x69966996;		//写入key
    1462:	137b      	lrw      	r3, 0x40011180	// 164c <csi_tkey_int_process+0x76>
    1464:	135b      	lrw      	r2, 0x69966996	// 1650 <csi_tkey_int_process+0x7a>
    1466:	b35f      	st.w      	r2, (r3, 0x7c)
	if(dwTkeyScanFreq!=0)
    1468:	137b      	lrw      	r3, 0x20000368	// 1654 <csi_tkey_int_process+0x7e>
    146a:	9340      	ld.w      	r2, (r3, 0x0)
    146c:	3a40      	cmpnei      	r2, 0
    146e:	0c03      	bf      	0x1474	// 1474 <csi_tkey_init+0x28>
	{
		hwTK_Scan_Freq0=dwTkeyScanFreq;				//如果对dwTkeyScanFreq修改值将调整整体扫描频率，默认d0007，保留隐藏
    1470:	9360      	ld.w      	r3, (r3, 0x0)
    1472:	b462      	st.w      	r3, (r4, 0x8)
	}
	*(uint32_t *)0x40011240 = hwTK_Scan_Freq0;
    1474:	9442      	ld.w      	r2, (r4, 0x8)
    1476:	1379      	lrw      	r3, 0x40011200	// 1658 <csi_tkey_int_process+0x82>
	tkey_para_config();
	tkey_io_enable();
	tkey_pwrsrc_config();
	TKEY_CCR = TK_CLK_EN | TK_DCHCKSEL_REFCLK | TK_PCKDIV(5) | TK_ALDTRIM_DIS |  TK_TRMTARSEL_TRIM | TK_DCHCKDIV_6 | TK_TRIMCONFIG0(10) | TK_TRIMCONFIG1(13) | TK_TRIMCONFIG2(15);
    1478:	ea254002 	movih      	r5, 16386
	*(uint32_t *)0x40011240 = hwTK_Scan_Freq0;
    147c:	b350      	st.w      	r2, (r3, 0x40)
	byTk_num=get_key_seq(dwTkeyIoEnable);
	TKEY_CON0 = TK_HM_EN | TK_MODE_SEQ | TK_SEQLEN(byTk_num) | hwTkeyEcLevel | TK_SCTIMLMT_10ms | TK_SCTLIM_DIS | TK_INTVTIM_None | hwTkeyPselMode | TK_INTREN_DIS | TK_STPATDSL_DIS | TK_STBLCNT_16 |TK_CYCSCNT_EN;
	TKEY_CON1 = TK_DST_LOW| TK_DBGSDO_DIS | TK_DBGDLEN_24bit | TK_DBGDOCKDIV_16 | TK_PHS_SHFT_SEQ_0 | TK_SHFT_STEP(2);
	for(i=0;i<byTk_num;i++)
	{
	TKEYB->TCH_SEQxCON[i]=(0x1<<27)|(((byTkeyIcon[byTk_seque[i]]>>4)&3)<<25)|((byTkeyIcon[byTk_seque[i]]&0xf)<<21)|(byTk_seque[i]<<16)|(hwTkeySenprd[byTk_seque[i]]<<0);
    147e:	13c0      	lrw      	r6, 0x20000525	// 15fc <csi_tkey_int_process+0x26>
	tkey_para_config();
    1480:	e3fffdc1 	bsr      	0x1002	// 1002 <tkey_para_config>
	TKEYB->TCH_SEQxCON[i]=(0x1<<27)|(((byTkeyIcon[byTk_seque[i]]>>4)&3)<<25)|((byTkeyIcon[byTk_seque[i]]&0xf)<<21)|(byTk_seque[i]<<16)|(hwTkeySenprd[byTk_seque[i]]<<0);
    1484:	12fd      	lrw      	r7, 0x200004ae	// 15f8 <csi_tkey_int_process+0x22>
	tkey_io_enable();
    1486:	e3fff691 	bsr      	0x1a8	// 1a8 <tkey_io_enable>
	tkey_pwrsrc_config();
    148a:	e3fff9aa 	bsr      	0x7de	// 7de <tkey_pwrsrc_config>
	TKEY_CCR = TK_CLK_EN | TK_DCHCKSEL_REFCLK | TK_PCKDIV(5) | TK_ALDTRIM_DIS |  TK_TRMTARSEL_TRIM | TK_DCHCKDIV_6 | TK_TRIMCONFIG0(10) | TK_TRIMCONFIG1(13) | TK_TRIMCONFIG2(15);
    148e:	1374      	lrw      	r3, 0x7b540251	// 165c <csi_tkey_int_process+0x86>
	memset((void *)TKEYB->TCH_SEQxCON,0,sizeof(TKEYB->TCH_SEQxCON));
    1490:	3280      	movi      	r2, 128
	TKEY_CCR = TK_CLK_EN | TK_DCHCKSEL_REFCLK | TK_PCKDIV(5) | TK_ALDTRIM_DIS |  TK_TRMTARSEL_TRIM | TK_DCHCKDIV_6 | TK_TRIMCONFIG0(10) | TK_TRIMCONFIG1(13) | TK_TRIMCONFIG2(15);
    1492:	b561      	st.w      	r3, (r5, 0x4)
	memset((void *)TKEYB->TCH_SEQxCON,0,sizeof(TKEYB->TCH_SEQxCON));
    1494:	3100      	movi      	r1, 0
    1496:	9401      	ld.w      	r0, (r4, 0x4)
    1498:	e000014c 	bsr      	0x1730	// 1730 <__memset_fast>
	memset((void *)TKEYA->TCH_DAT,0,sizeof(TKEYA->TCH_DAT));
    149c:	3280      	movi      	r2, 128
    149e:	3100      	movi      	r1, 0
    14a0:	9400      	ld.w      	r0, (r4, 0x0)
    14a2:	e0000147 	bsr      	0x1730	// 1730 <__memset_fast>
	byTk_num=get_key_seq(dwTkeyIoEnable);
    14a6:	1271      	lrw      	r3, 0x200004f0	// 15e8 <csi_tkey_int_process+0x12>
    14a8:	9300      	ld.w      	r0, (r3, 0x0)
    14aa:	e3fff9c1 	bsr      	0x82c	// 82c <get_key_seq>
    14ae:	1251      	lrw      	r2, 0x200003b2	// 15f0 <csi_tkey_int_process+0x1a>
	TKEY_CON0 = TK_HM_EN | TK_MODE_SEQ | TK_SEQLEN(byTk_num) | hwTkeyEcLevel | TK_SCTIMLMT_10ms | TK_SCTLIM_DIS | TK_INTVTIM_None | hwTkeyPselMode | TK_INTREN_DIS | TK_STPATDSL_DIS | TK_STBLCNT_16 |TK_CYCSCNT_EN;
    14b0:	132c      	lrw      	r1, 0x20000464	// 1660 <csi_tkey_int_process+0x8a>
	byTk_num=get_key_seq(dwTkeyIoEnable);
    14b2:	a200      	st.b      	r0, (r2, 0x0)
	TKEY_CON0 = TK_HM_EN | TK_MODE_SEQ | TK_SEQLEN(byTk_num) | hwTkeyEcLevel | TK_SCTIMLMT_10ms | TK_SCTLIM_DIS | TK_INTVTIM_None | hwTkeyPselMode | TK_INTREN_DIS | TK_STPATDSL_DIS | TK_STBLCNT_16 |TK_CYCSCNT_EN;
    14b4:	8260      	ld.b      	r3, (r2, 0x0)
    14b6:	8900      	ld.h      	r0, (r1, 0x0)
    14b8:	132b      	lrw      	r1, 0x20000650	// 1664 <csi_tkey_int_process+0x8e>
    14ba:	2b00      	subi      	r3, 1
    14bc:	8920      	ld.h      	r1, (r1, 0x0)
    14be:	6c40      	or      	r1, r0
    14c0:	4362      	lsli      	r3, r3, 2
    14c2:	7445      	zexth      	r1, r1
    14c4:	1309      	lrw      	r0, 0x1e0a03	// 1668 <csi_tkey_int_process+0x92>
    14c6:	e463207c 	andi      	r3, r3, 124
    14ca:	6c40      	or      	r1, r0
    14cc:	6cc4      	or      	r3, r1
    14ce:	b562      	st.w      	r3, (r5, 0x8)
	TKEY_CON1 = TK_DST_LOW| TK_DBGSDO_DIS | TK_DBGDLEN_24bit | TK_DBGDOCKDIV_16 | TK_PHS_SHFT_SEQ_0 | TK_SHFT_STEP(2);
    14d0:	1367      	lrw      	r3, 0x20000e2	// 166c <csi_tkey_int_process+0x96>
    14d2:	b563      	st.w      	r3, (r5, 0xc)
	TKEYB->TCH_SEQxCON[i]=(0x1<<27)|(((byTkeyIcon[byTk_seque[i]]>>4)&3)<<25)|((byTkeyIcon[byTk_seque[i]]&0xf)<<21)|(byTk_seque[i]<<16)|(hwTkeySenprd[byTk_seque[i]]<<0);
    14d4:	9461      	ld.w      	r3, (r4, 0x4)
    14d6:	b841      	st.w      	r2, (r14, 0x4)
    14d8:	b860      	st.w      	r3, (r14, 0x0)
	for(i=0;i<byTk_num;i++)
    14da:	3300      	movi      	r3, 0
	TKEYB->TCH_SEQxCON[i]=(0x1<<27)|(((byTkeyIcon[byTk_seque[i]]>>4)&3)<<25)|((byTkeyIcon[byTk_seque[i]]&0xf)<<21)|(byTk_seque[i]<<16)|(hwTkeySenprd[byTk_seque[i]]<<0);
    14dc:	12a6      	lrw      	r5, 0x200005cd	// 15f4 <csi_tkey_int_process+0x1e>
	for(i=0;i<byTk_num;i++)
    14de:	9841      	ld.w      	r2, (r14, 0x4)
    14e0:	8240      	ld.b      	r2, (r2, 0x0)
    14e2:	648c      	cmphs      	r3, r2
    14e4:	0c12      	bf      	0x1508	// 1508 <csi_tkey_init+0xbc>
	}
	TKEY_IMCR |= TK_SEQ_DNE|TK_CH_ERR|TK_TIMOVF|TK_REFOVF;
    14e6:	ea244002 	movih      	r4, 16386
    14ea:	946b      	ld.w      	r3, (r4, 0x2c)
    14ec:	ec63001d 	ori      	r3, r3, 29
    14f0:	b46b      	st.w      	r3, (r4, 0x2c)
	CK802_ISER=0x01ul<<25;
    14f2:	1340      	lrw      	r2, 0xe000e100	// 1670 <csi_tkey_int_process+0x9a>
    14f4:	3380      	movi      	r3, 128
    14f6:	4372      	lsli      	r3, r3, 18
    14f8:	b260      	st.w      	r3, (r2, 0x0)
	CK802_IWER=0x01ul<<25;
    14fa:	b270      	st.w      	r3, (r2, 0x40)
	tkey_sleep_para_init();
    14fc:	e3ffff23 	bsr      	0x1342	// 1342 <tkey_sleep_para_init>
	TKEY_RSSR = 0X1;
    1500:	3301      	movi      	r3, 1
    1502:	b464      	st.w      	r3, (r4, 0x10)
}
    1504:	1402      	addi      	r14, r14, 8
    1506:	1494      	pop      	r4-r7, r15
	TKEYB->TCH_SEQxCON[i]=(0x1<<27)|(((byTkeyIcon[byTk_seque[i]]>>4)&3)<<25)|((byTkeyIcon[byTk_seque[i]]&0xf)<<21)|(byTk_seque[i]<<16)|(hwTkeySenprd[byTk_seque[i]]<<0);
    1508:	5e8c      	addu      	r4, r6, r3
    150a:	8440      	ld.b      	r2, (r4, 0x0)
    150c:	6094      	addu      	r2, r5
    150e:	8240      	ld.b      	r2, (r2, 0x0)
    1510:	8420      	ld.b      	r1, (r4, 0x0)
    1512:	6054      	addu      	r1, r5
    1514:	8120      	ld.b      	r1, (r1, 0x0)
    1516:	8400      	ld.b      	r0, (r4, 0x0)
    1518:	8480      	ld.b      	r4, (r4, 0x0)
    151a:	4481      	lsli      	r4, r4, 1
    151c:	611c      	addu      	r4, r7
    151e:	8c80      	ld.h      	r4, (r4, 0x0)
    1520:	4010      	lsli      	r0, r0, 16
    1522:	7511      	zexth      	r4, r4
    1524:	38bb      	bseti      	r0, 27
    1526:	6c10      	or      	r0, r4
    1528:	34f0      	movi      	r4, 240
    152a:	4135      	lsli      	r1, r1, 21
    152c:	4491      	lsli      	r4, r4, 17
    152e:	6904      	and      	r4, r1
    1530:	6c10      	or      	r0, r4
    1532:	4295      	lsli      	r4, r2, 21
    1534:	32c0      	movi      	r2, 192
    1536:	4253      	lsli      	r2, r2, 19
    1538:	6908      	and      	r4, r2
    153a:	6d00      	or      	r4, r0
    153c:	4342      	lsli      	r2, r3, 2
    153e:	9820      	ld.w      	r1, (r14, 0x0)
    1540:	6084      	addu      	r2, r1
	for(i=0;i<byTk_num;i++)
    1542:	2300      	addi      	r3, 1
	TKEYB->TCH_SEQxCON[i]=(0x1<<27)|(((byTkeyIcon[byTk_seque[i]]>>4)&3)<<25)|((byTkeyIcon[byTk_seque[i]]&0xf)<<21)|(byTk_seque[i]<<16)|(hwTkeySenprd[byTk_seque[i]]<<0);
    1544:	b280      	st.w      	r4, (r2, 0x0)
	for(i=0;i<byTk_num;i++)
    1546:	74cc      	zextb      	r3, r3
    1548:	07cb      	br      	0x14de	// 14de <csi_tkey_init+0x92>

0000154a <tkey_sampling_prog>:
{
    154a:	14d2      	push      	r4-r5, r15
		hwSampling_data0[(TKEYA->TCH_DAT[i]&0xff000000)>>24]=TKEYA->TCH_DAT[i]&0X00FFFFFF;
    154c:	1168      	lrw      	r3, 0x200000ac	// 15ec <csi_tkey_int_process+0x16>
	for (i=0;i<byTk_num;i++)
    154e:	3200      	movi      	r2, 0
		hwSampling_data0[(TKEYA->TCH_DAT[i]&0xff000000)>>24]=TKEYA->TCH_DAT[i]&0X00FFFFFF;
    1550:	9300      	ld.w      	r0, (r3, 0x0)
	for (i=0;i<byTk_num;i++)
    1552:	1128      	lrw      	r1, 0x200003b2	// 15f0 <csi_tkey_int_process+0x1a>
		hwSampling_data0[(TKEYA->TCH_DAT[i]&0xff000000)>>24]=TKEYA->TCH_DAT[i]&0X00FFFFFF;
    1554:	1288      	lrw      	r4, 0x20000466	// 1674 <csi_tkey_int_process+0x9e>
	for (i=0;i<byTk_num;i++)
    1556:	8160      	ld.b      	r3, (r1, 0x0)
    1558:	64c8      	cmphs      	r2, r3
    155a:	0c32      	bf      	0x15be	// 15be <tkey_sampling_prog+0x74>
	if(byPoweron_1st_f<5)
    155c:	117a      	lrw      	r3, 0x20000461	// 1644 <csi_tkey_int_process+0x6e>
    155e:	8340      	ld.b      	r2, (r3, 0x0)
    1560:	7488      	zextb      	r2, r2
    1562:	3a04      	cmphsi      	r2, 5
    1564:	0812      	bt      	0x1588	// 1588 <tkey_sampling_prog+0x3e>
    1566:	3200      	movi      	r2, 0
		hwBaseline_data0[i]=hwSampling_data0[i];
    1568:	12a3      	lrw      	r5, 0x20000466	// 1674 <csi_tkey_int_process+0x9e>
    156a:	1284      	lrw      	r4, 0x20000328	// 1678 <csi_tkey_int_process+0xa2>
    156c:	4221      	lsli      	r1, r2, 1
    156e:	5d04      	addu      	r0, r5, r1
    1570:	8800      	ld.h      	r0, (r0, 0x0)
    1572:	2200      	addi      	r2, 1
	for (i=0;i<32;i++)
    1574:	eb420020 	cmpnei      	r2, 32
		hwBaseline_data0[i]=hwSampling_data0[i];
    1578:	7401      	zexth      	r0, r0
    157a:	6050      	addu      	r1, r4
    157c:	a900      	st.h      	r0, (r1, 0x0)
	for (i=0;i<32;i++)
    157e:	0bf7      	bt      	0x156c	// 156c <tkey_sampling_prog+0x22>
	byPoweron_1st_f++;
    1580:	8340      	ld.b      	r2, (r3, 0x0)
    1582:	2200      	addi      	r2, 1
    1584:	7488      	zextb      	r2, r2
    1586:	a340      	st.b      	r2, (r3, 0x0)
	if(byForceReBuild==1)
    1588:	118e      	lrw      	r4, 0x20000370	// 1640 <csi_tkey_int_process+0x6a>
    158a:	8460      	ld.b      	r3, (r4, 0x0)
    158c:	3b41      	cmpnei      	r3, 1
    158e:	0810      	bt      	0x15ae	// 15ae <tkey_sampling_prog+0x64>
    1590:	3300      	movi      	r3, 0
			hwBaseline_data0[i]=hwSampling_data0[i];
    1592:	11b9      	lrw      	r5, 0x20000466	// 1674 <csi_tkey_int_process+0x9e>
    1594:	1119      	lrw      	r0, 0x20000328	// 1678 <csi_tkey_int_process+0xa2>
    1596:	4341      	lsli      	r2, r3, 1
    1598:	5d28      	addu      	r1, r5, r2
    159a:	8920      	ld.h      	r1, (r1, 0x0)
    159c:	2300      	addi      	r3, 1
		for (i=0;i<32;i++)
    159e:	eb430020 	cmpnei      	r3, 32
			hwBaseline_data0[i]=hwSampling_data0[i];
    15a2:	7445      	zexth      	r1, r1
    15a4:	6080      	addu      	r2, r0
    15a6:	aa20      	st.h      	r1, (r2, 0x0)
		for (i=0;i<32;i++)
    15a8:	0bf7      	bt      	0x1596	// 1596 <tkey_sampling_prog+0x4c>
		byForceReBuild=0;
    15aa:	3300      	movi      	r3, 0
    15ac:	a460      	st.b      	r3, (r4, 0x0)
	if(byForceReBuild==2)
    15ae:	8460      	ld.b      	r3, (r4, 0x0)
    15b0:	3b42      	cmpnei      	r3, 2
    15b2:	0805      	bt      	0x15bc	// 15bc <tkey_sampling_prog+0x72>
		csi_tkey_init();
    15b4:	e3ffff4c 	bsr      	0x144c	// 144c <csi_tkey_init>
		byForceReBuild=0;
    15b8:	3300      	movi      	r3, 0
    15ba:	a460      	st.b      	r3, (r4, 0x0)
}
    15bc:	1492      	pop      	r4-r5, r15
    15be:	42a2      	lsli      	r5, r2, 2
    15c0:	6140      	addu      	r5, r0
		hwSampling_data0[(TKEYA->TCH_DAT[i]&0xff000000)>>24]=TKEYA->TCH_DAT[i]&0X00FFFFFF;
    15c2:	9560      	ld.w      	r3, (r5, 0x0)
    15c4:	4b78      	lsri      	r3, r3, 24
    15c6:	95a0      	ld.w      	r5, (r5, 0x0)
    15c8:	7555      	zexth      	r5, r5
    15ca:	4361      	lsli      	r3, r3, 1
    15cc:	60d0      	addu      	r3, r4
	for (i=0;i<byTk_num;i++)
    15ce:	2200      	addi      	r2, 1
		hwSampling_data0[(TKEYA->TCH_DAT[i]&0xff000000)>>24]=TKEYA->TCH_DAT[i]&0X00FFFFFF;
    15d0:	aba0      	st.h      	r5, (r3, 0x0)
	for (i=0;i<byTk_num;i++)
    15d2:	7488      	zextb      	r2, r2
    15d4:	07c1      	br      	0x1556	// 1556 <tkey_sampling_prog+0xc>

000015d6 <csi_tkey_int_process>:
{
    15d6:	14d1      	push      	r4, r15
	if((TKEY_RISR&TK_SEQ_DNE)==TK_SEQ_DNE)
    15d8:	ea244002 	movih      	r4, 16386
    15dc:	9469      	ld.w      	r3, (r4, 0x24)
    15de:	e4632001 	andi      	r3, r3, 1
    15e2:	3b40      	cmpnei      	r3, 0
    15e4:	0c50      	bf      	0x1684	// 1684 <csi_tkey_int_process+0xae>
    15e6:	044b      	br      	0x167c	// 167c <csi_tkey_int_process+0xa6>
    15e8:	200004f0 	.long	0x200004f0
    15ec:	200000ac 	.long	0x200000ac
    15f0:	200003b2 	.long	0x200003b2
    15f4:	200005cd 	.long	0x200005cd
    15f8:	200004ae 	.long	0x200004ae
    15fc:	20000525 	.long	0x20000525
    1600:	200003b4 	.long	0x200003b4
    1604:	ffff8f83 	.long	0xffff8f83
    1608:	200004fc 	.long	0x200004fc
    160c:	ad6b7fff 	.long	0xad6b7fff
    1610:	200003fb 	.long	0x200003fb
    1614:	20000654 	.long	0x20000654
    1618:	20000324 	.long	0x20000324
    161c:	20000588 	.long	0x20000588
    1620:	200004fe 	.long	0x200004fe
    1624:	20000524 	.long	0x20000524
    1628:	20000320 	.long	0x20000320
    162c:	20000522 	.long	0x20000522
    1630:	2000031c 	.long	0x2000031c
    1634:	200004ac 	.long	0x200004ac
    1638:	200004f4 	.long	0x200004f4
    163c:	20000322 	.long	0x20000322
    1640:	20000370 	.long	0x20000370
    1644:	20000461 	.long	0x20000461
    1648:	40011000 	.long	0x40011000
    164c:	40011180 	.long	0x40011180
    1650:	69966996 	.long	0x69966996
    1654:	20000368 	.long	0x20000368
    1658:	40011200 	.long	0x40011200
    165c:	7b540251 	.long	0x7b540251
    1660:	20000464 	.long	0x20000464
    1664:	20000650 	.long	0x20000650
    1668:	001e0a03 	.long	0x001e0a03
    166c:	020000e2 	.long	0x020000e2
    1670:	e000e100 	.long	0xe000e100
    1674:	20000466 	.long	0x20000466
    1678:	20000328 	.long	0x20000328
		TKEY_ICR = TK_SEQ_DNE;
    167c:	3301      	movi      	r3, 1
    167e:	b46c      	st.w      	r3, (r4, 0x30)
		tkey_sampling_prog();
    1680:	e3ffff65 	bsr      	0x154a	// 154a <tkey_sampling_prog>
	if((TKEY_RISR&TK_CH_DNE)==TK_CH_DNE)
    1684:	9469      	ld.w      	r3, (r4, 0x24)
    1686:	e4632002 	andi      	r3, r3, 2
    168a:	3b40      	cmpnei      	r3, 0
    168c:	0c03      	bf      	0x1692	// 1692 <csi_tkey_int_process+0xbc>
		TKEY_ICR = TK_CH_DNE;
    168e:	3302      	movi      	r3, 2
    1690:	b46c      	st.w      	r3, (r4, 0x30)
	if((TKEY_RISR&TK_CH_ERR)==TK_CH_ERR)
    1692:	ea224002 	movih      	r2, 16386
    1696:	9269      	ld.w      	r3, (r2, 0x24)
    1698:	e4632004 	andi      	r3, r3, 4
    169c:	3b40      	cmpnei      	r3, 0
    169e:	0c08      	bf      	0x16ae	// 16ae <csi_tkey_int_process+0xd8>
		byTk_error_f|=0x01;
    16a0:	1037      	lrw      	r1, 0x200004f4	// 16fc <csi_tkey_main_prog+0x2>
    16a2:	8160      	ld.b      	r3, (r1, 0x0)
    16a4:	ec630001 	ori      	r3, r3, 1
    16a8:	a160      	st.b      	r3, (r1, 0x0)
		TKEY_ICR = TK_CH_ERR;
    16aa:	3304      	movi      	r3, 4
    16ac:	b26c      	st.w      	r3, (r2, 0x30)
	if((TKEY_RISR&TK_TIMOVF)==TK_TIMOVF)
    16ae:	ea224002 	movih      	r2, 16386
    16b2:	9269      	ld.w      	r3, (r2, 0x24)
    16b4:	e4632008 	andi      	r3, r3, 8
    16b8:	3b40      	cmpnei      	r3, 0
    16ba:	0c08      	bf      	0x16ca	// 16ca <csi_tkey_int_process+0xf4>
		byTk_error_f|=0x02;
    16bc:	1030      	lrw      	r1, 0x200004f4	// 16fc <csi_tkey_main_prog+0x2>
    16be:	8160      	ld.b      	r3, (r1, 0x0)
    16c0:	ec630002 	ori      	r3, r3, 2
    16c4:	a160      	st.b      	r3, (r1, 0x0)
		TKEY_ICR = TK_TIMOVF;
    16c6:	3308      	movi      	r3, 8
    16c8:	b26c      	st.w      	r3, (r2, 0x30)
	if((TKEY_RISR&TK_REFOVF)==TK_REFOVF)
    16ca:	ea224002 	movih      	r2, 16386
    16ce:	9269      	ld.w      	r3, (r2, 0x24)
    16d0:	e4632010 	andi      	r3, r3, 16
    16d4:	3b40      	cmpnei      	r3, 0
    16d6:	0c08      	bf      	0x16e6	// 16e6 <csi_tkey_int_process+0x110>
		byTk_error_f|=0x04;
    16d8:	1029      	lrw      	r1, 0x200004f4	// 16fc <csi_tkey_main_prog+0x2>
    16da:	8160      	ld.b      	r3, (r1, 0x0)
    16dc:	ec630004 	ori      	r3, r3, 4
    16e0:	a160      	st.b      	r3, (r1, 0x0)
		TKEY_ICR = TK_REFOVF;
    16e2:	3310      	movi      	r3, 16
    16e4:	b26c      	st.w      	r3, (r2, 0x30)
	if((TKEY_RISR&TK_THROVR)==TK_THROVR)
    16e6:	ea224002 	movih      	r2, 16386
    16ea:	9269      	ld.w      	r3, (r2, 0x24)
    16ec:	e4632020 	andi      	r3, r3, 32
    16f0:	3b40      	cmpnei      	r3, 0
    16f2:	0c03      	bf      	0x16f8	// 16f8 <csi_tkey_int_process+0x122>
		TKEY_ICR = TK_THROVR;
    16f4:	3320      	movi      	r3, 32
    16f6:	b26c      	st.w      	r3, (r2, 0x30)
}
    16f8:	1491      	pop      	r4, r15

000016fa <csi_tkey_main_prog>:
//TK main prgm (not used)
*****************************************************/
void csi_tkey_main_prog(void)
{
	
}
    16fa:	783c      	jmp      	r15
    16fc:	200004f4 	.long	0x200004f4

00001700 <___gnu_csky_case_uqi>:
    1700:	1421      	subi      	r14, r14, 4
    1702:	b820      	st.w      	r1, (r14, 0x0)
    1704:	6c7f      	mov      	r1, r15
    1706:	6040      	addu      	r1, r0
    1708:	8120      	ld.b      	r1, (r1, 0x0)
    170a:	4121      	lsli      	r1, r1, 1
    170c:	63c4      	addu      	r15, r1
    170e:	9820      	ld.w      	r1, (r14, 0x0)
    1710:	1401      	addi      	r14, r14, 4
    1712:	783c      	jmp      	r15

00001714 <___gnu_csky_case_uhi>:
    1714:	1422      	subi      	r14, r14, 8
    1716:	b801      	st.w      	r0, (r14, 0x4)
    1718:	b820      	st.w      	r1, (r14, 0x0)
    171a:	6c7f      	mov      	r1, r15
    171c:	4001      	lsli      	r0, r0, 1
    171e:	6040      	addu      	r1, r0
    1720:	8920      	ld.h      	r1, (r1, 0x0)
    1722:	4121      	lsli      	r1, r1, 1
    1724:	63c4      	addu      	r15, r1
    1726:	9801      	ld.w      	r0, (r14, 0x4)
    1728:	9820      	ld.w      	r1, (r14, 0x0)
    172a:	1402      	addi      	r14, r14, 8
    172c:	783c      	jmp      	r15
	...

00001730 <__memset_fast>:
    1730:	7444      	zextb      	r1, r1
    1732:	3a40      	cmpnei      	r2, 0
    1734:	0c25      	bf      	0x177e	// 177e <__memset_fast+0x4e>
    1736:	6f43      	mov      	r13, r0
    1738:	e5802003 	andi      	r12, r0, 3
    173c:	eb4c0000 	cmpnei      	r12, 0
    1740:	0c20      	bf      	0x1780	// 1780 <__memset_fast+0x50>
    1742:	dc2d0000 	st.b      	r1, (r13, 0x0)
    1746:	2a00      	subi      	r2, 1
    1748:	3a40      	cmpnei      	r2, 0
    174a:	0c1a      	bf      	0x177e	// 177e <__memset_fast+0x4e>
    174c:	e5ad0000 	addi      	r13, r13, 1
    1750:	e58d2003 	andi      	r12, r13, 3
    1754:	eb4c0000 	cmpnei      	r12, 0
    1758:	0c14      	bf      	0x1780	// 1780 <__memset_fast+0x50>
    175a:	dc2d0000 	st.b      	r1, (r13, 0x0)
    175e:	2a00      	subi      	r2, 1
    1760:	3a40      	cmpnei      	r2, 0
    1762:	0c0e      	bf      	0x177e	// 177e <__memset_fast+0x4e>
    1764:	e5ad0000 	addi      	r13, r13, 1
    1768:	e58d2003 	andi      	r12, r13, 3
    176c:	eb4c0000 	cmpnei      	r12, 0
    1770:	0c08      	bf      	0x1780	// 1780 <__memset_fast+0x50>
    1772:	dc2d0000 	st.b      	r1, (r13, 0x0)
    1776:	2a00      	subi      	r2, 1
    1778:	e5ad0000 	addi      	r13, r13, 1
    177c:	0402      	br      	0x1780	// 1780 <__memset_fast+0x50>
    177e:	783c      	jmp      	r15
    1780:	4168      	lsli      	r3, r1, 8
    1782:	6c4c      	or      	r1, r3
    1784:	4170      	lsli      	r3, r1, 16
    1786:	6c4c      	or      	r1, r3
    1788:	3a2f      	cmplti      	r2, 16
    178a:	080e      	bt      	0x17a6	// 17a6 <__memset_fast+0x76>
    178c:	dc2d2000 	st.w      	r1, (r13, 0x0)
    1790:	dc2d2001 	st.w      	r1, (r13, 0x4)
    1794:	dc2d2002 	st.w      	r1, (r13, 0x8)
    1798:	dc2d2003 	st.w      	r1, (r13, 0xc)
    179c:	2a0f      	subi      	r2, 16
    179e:	e5ad000f 	addi      	r13, r13, 16
    17a2:	3a2f      	cmplti      	r2, 16
    17a4:	0ff4      	bf      	0x178c	// 178c <__memset_fast+0x5c>
    17a6:	3a23      	cmplti      	r2, 4
    17a8:	0808      	bt      	0x17b8	// 17b8 <__memset_fast+0x88>
    17aa:	2a03      	subi      	r2, 4
    17ac:	dc2d2000 	st.w      	r1, (r13, 0x0)
    17b0:	e5ad0003 	addi      	r13, r13, 4
    17b4:	3a23      	cmplti      	r2, 4
    17b6:	0ffa      	bf      	0x17aa	// 17aa <__memset_fast+0x7a>
    17b8:	3a40      	cmpnei      	r2, 0
    17ba:	0fe2      	bf      	0x177e	// 177e <__memset_fast+0x4e>
    17bc:	2a00      	subi      	r2, 1
    17be:	dc2d0000 	st.b      	r1, (r13, 0x0)
    17c2:	3a40      	cmpnei      	r2, 0
    17c4:	0fdd      	bf      	0x177e	// 177e <__memset_fast+0x4e>
    17c6:	2a00      	subi      	r2, 1
    17c8:	dc2d0001 	st.b      	r1, (r13, 0x1)
    17cc:	3a40      	cmpnei      	r2, 0
    17ce:	0fd8      	bf      	0x177e	// 177e <__memset_fast+0x4e>
    17d0:	dc2d0002 	st.b      	r1, (r13, 0x2)
    17d4:	783c      	jmp      	r15
	...

000017d8 <__memcpy_fast>:
    17d8:	14c1      	push      	r4
    17da:	6f03      	mov      	r12, r0
    17dc:	c401242d 	or      	r13, r1, r0
    17e0:	e48d2003 	andi      	r4, r13, 3
    17e4:	3c40      	cmpnei      	r4, 0
    17e6:	0c0d      	bf      	0x1800	// 1800 <__memcpy_fast+0x28>
    17e8:	3a40      	cmpnei      	r2, 0
    17ea:	0c0a      	bf      	0x17fe	// 17fe <__memcpy_fast+0x26>
    17ec:	8160      	ld.b      	r3, (r1, 0x0)
    17ee:	2100      	addi      	r1, 1
    17f0:	2a00      	subi      	r2, 1
    17f2:	dc6c0000 	st.b      	r3, (r12, 0x0)
    17f6:	e58c0000 	addi      	r12, r12, 1
    17fa:	3a40      	cmpnei      	r2, 0
    17fc:	0bf8      	bt      	0x17ec	// 17ec <__memcpy_fast+0x14>
    17fe:	1481      	pop      	r4
    1800:	3a2f      	cmplti      	r2, 16
    1802:	0815      	bt      	0x182c	// 182c <__memcpy_fast+0x54>
    1804:	d9a12000 	ld.w      	r13, (r1, 0x0)
    1808:	9161      	ld.w      	r3, (r1, 0x4)
    180a:	9182      	ld.w      	r4, (r1, 0x8)
    180c:	ddac2000 	st.w      	r13, (r12, 0x0)
    1810:	d9a12003 	ld.w      	r13, (r1, 0xc)
    1814:	dc6c2001 	st.w      	r3, (r12, 0x4)
    1818:	dc8c2002 	st.w      	r4, (r12, 0x8)
    181c:	ddac2003 	st.w      	r13, (r12, 0xc)
    1820:	2a0f      	subi      	r2, 16
    1822:	210f      	addi      	r1, 16
    1824:	e58c000f 	addi      	r12, r12, 16
    1828:	3a2f      	cmplti      	r2, 16
    182a:	0fed      	bf      	0x1804	// 1804 <__memcpy_fast+0x2c>
    182c:	3a23      	cmplti      	r2, 4
    182e:	080a      	bt      	0x1842	// 1842 <__memcpy_fast+0x6a>
    1830:	9160      	ld.w      	r3, (r1, 0x0)
    1832:	2a03      	subi      	r2, 4
    1834:	2103      	addi      	r1, 4
    1836:	dc6c2000 	st.w      	r3, (r12, 0x0)
    183a:	e58c0003 	addi      	r12, r12, 4
    183e:	3a23      	cmplti      	r2, 4
    1840:	0ff8      	bf      	0x1830	// 1830 <__memcpy_fast+0x58>
    1842:	3a40      	cmpnei      	r2, 0
    1844:	0fdd      	bf      	0x17fe	// 17fe <__memcpy_fast+0x26>
    1846:	8160      	ld.b      	r3, (r1, 0x0)
    1848:	2100      	addi      	r1, 1
    184a:	2a00      	subi      	r2, 1
    184c:	dc6c0000 	st.b      	r3, (r12, 0x0)
    1850:	e58c0000 	addi      	r12, r12, 1
    1854:	07f7      	br      	0x1842	// 1842 <__memcpy_fast+0x6a>

Disassembly of section .text.__main:

00001858 <__main>:
extern char _bss_start[];
extern char _ebss[];


void __main( void ) 
{
    1858:	14d1      	push      	r4, r15
 if the start of data (dst)
 is not equal to end of text (src) then
 copy it, else it's already in the right place                
***********************************************************************/ 

  if( _start_data != _end_rodata ) {
    185a:	1011      	lrw      	r0, 0x20000000	// 189c <__main+0x44>
    185c:	1031      	lrw      	r1, 0x34c0	// 18a0 <__main+0x48>
    185e:	6442      	cmpne      	r0, r1
    1860:	0c15      	bf      	0x188a	// 188a <__main+0x32>
	//__memcpy_fast( dst, src, (_end_data - _start_data));
    //memcpy( dst, src, (_end_data - _start_data));
	memcpy( dst, src, (_end_data - _start_data));
    1862:	1091      	lrw      	r4, 0x200000b8	// 18a4 <__main+0x4c>
    1864:	6102      	subu      	r4, r0
    1866:	6c93      	mov      	r2, r4
    1868:	e3ffffb8 	bsr      	0x17d8	// 17d8 <__memcpy_fast>
	if(!(((*(unsigned int *)0x40011090)&0X4000)||((*(unsigned int *)0x40011090)&0X0008)))
    186c:	106f      	lrw      	r3, 0x40011080	// 18a8 <__main+0x50>
    186e:	ea024008 	movi      	r2, 16392
    1872:	9364      	ld.w      	r3, (r3, 0x10)
    1874:	68c8      	and      	r3, r2
    1876:	3b40      	cmpnei      	r3, 0
    1878:	0809      	bt      	0x188a	// 188a <__main+0x32>
	{
		memcpy( _start_sram1_define, src + ((_end_data - _start_data)) ,(_end_sram1_define -_start_sram1_define));
    187a:	106d      	lrw      	r3, 0x20002000	// 18ac <__main+0x54>
    187c:	6c0f      	mov      	r0, r3
    187e:	1029      	lrw      	r1, 0x34c0	// 18a0 <__main+0x48>
    1880:	104c      	lrw      	r2, 0x20002000	// 18b0 <__main+0x58>
    1882:	6050      	addu      	r1, r4
    1884:	608e      	subu      	r2, r3
    1886:	e3ffffa9 	bsr      	0x17d8	// 17d8 <__memcpy_fast>
  }

/*********************************************************************** 
zero the bss         
***********************************************************************/ 
  if( _ebss - _bss_start ) {
    188a:	104b      	lrw      	r2, 0x20000658	// 18b4 <__main+0x5c>
    188c:	100b      	lrw      	r0, 0x200000b8	// 18b8 <__main+0x60>
    188e:	640a      	cmpne      	r2, r0
    1890:	0c05      	bf      	0x189a	// 189a <__main+0x42>
	//__memset_fast( _bss_start, 0x00, ( _ebss - _bss_start ));
    memset( _bss_start, 0x00, ( _ebss - _bss_start ));
    1892:	3100      	movi      	r1, 0
    1894:	6082      	subu      	r2, r0
    1896:	e3ffff4d 	bsr      	0x1730	// 1730 <__memset_fast>
  }

	
}
    189a:	1491      	pop      	r4, r15
    189c:	20000000 	.long	0x20000000
    18a0:	000034c0 	.long	0x000034c0
    18a4:	200000b8 	.long	0x200000b8
    18a8:	40011080 	.long	0x40011080
    18ac:	20002000 	.long	0x20002000
    18b0:	20002000 	.long	0x20002000
    18b4:	20000658 	.long	0x20000658
    18b8:	200000b8 	.long	0x200000b8

Disassembly of section .text.__divsi3:

000018bc <__divsi3>:

/***********************************************************************
@brief div Functions
***********************************************************************/
int __divsi3 (  int a,   int b)
{   
    18bc:	14c1      	push      	r4
	int PSR;
	__asm volatile(
    18be:	c0006023 	mfcr      	r3, cr<0, 0>
    18c2:	c0807020 	psrclr      	ie
					"mfcr %0 , psr \n\r"
					"psrclr ie \n\r"
					: "=r"(PSR)
				   );

	HWD->CR = 0;
    18c6:	1046      	lrw      	r2, 0x20000000	// 18dc <__divsi3+0x20>
    18c8:	3400      	movi      	r4, 0
    18ca:	9240      	ld.w      	r2, (r2, 0x0)
	HWD->DIVIDENT = a;
	HWD->DIVISOR = b;

	PSR |= 0x80000000;
    18cc:	3bbf      	bseti      	r3, 31
	HWD->CR = 0;
    18ce:	b284      	st.w      	r4, (r2, 0x10)
	HWD->DIVIDENT = a;
    18d0:	b200      	st.w      	r0, (r2, 0x0)
	HWD->DIVISOR = b;
    18d2:	b221      	st.w      	r1, (r2, 0x4)
	__asm volatile(
    18d4:	c0036420 	mtcr      	r3, cr<0, 0>
					 "mtcr %0 , psr \n\r"
					 : 
					 :"r"(PSR)
					);
					
	return HWD->QUOTIENT;
    18d8:	9202      	ld.w      	r0, (r2, 0x8)
}
    18da:	1481      	pop      	r4
    18dc:	20000000 	.long	0x20000000

Disassembly of section .text.CK_CPU_EnAllNormalIrq:

000018e0 <CK_CPU_EnAllNormalIrq>:
/***********************************************************************
@brief CPU IRQ Enable
***********************************************************************/
void CK_CPU_EnAllNormalIrq(void)
{
  asm  ("psrset ee,ie");
    18e0:	c1807420 	psrset      	ee, ie
}
    18e4:	783c      	jmp      	r15

Disassembly of section .text.csi_tkey_parameter_init:

000018e8 <csi_tkey_parameter_init>:
void csi_tkey_parameter_init(void)
{
/****************************************************
//TK basic parameters
*****************************************************/
	dwTkeyIoEnable=TCH_EN(0)|TCH_EN(1)|TCH_EN(2)|TCH_EN(3)|TCH_EN(4)|TCH_EN(5)|TCH_EN(6)|TCH_EN(7)|             //TCH_EN(10)swdio TCH_EN(13)swclk  
    18e8:	1163      	lrw      	r3, 0x200004f0	// 1974 <csi_tkey_parameter_init+0x8c>
    18ea:	1144      	lrw      	r2, 0x1effd8ff	// 1978 <csi_tkey_parameter_init+0x90>
    18ec:	b340      	st.w      	r2, (r3, 0x0)
				   TCH_EN(11)|TCH_EN(12)|TCH_EN(14)|TCH_EN(15)|TCH_EN(16)|TCH_EN(17)|TCH_EN(18)|TCH_EN(19)|
				   TCH_EN(20)|TCH_EN(21)|TCH_EN(22)|TCH_EN(23)|TCH_EN(25)|TCH_EN(26)|TCH_EN(27)|TCH_EN(28);     //TCH_EN(24)fvr  

	byTkeyGlobalSens=1;								//TK Global Tkey Sensitivity,0=invalid;
    18ee:	3201      	movi      	r2, 1
    18f0:	1163      	lrw      	r3, 0x200005ac	// 197c <csi_tkey_parameter_init+0x94>
    18f2:	a340      	st.b      	r2, (r3, 0x0)
	hwTkeyGlobalTrigger=50;							//TK Global Tkey Trigger,0=invalid;
    18f4:	3232      	movi      	r2, 50
    18f6:	1163      	lrw      	r3, 0x200003f8	// 1980 <csi_tkey_parameter_init+0x98>
    18f8:	ab40      	st.h      	r2, (r3, 0x0)
	byTkeyGlobalIcon=3;								//TK Global Tkey Icon,0=invalid;
    18fa:	3203      	movi      	r2, 3
    18fc:	1162      	lrw      	r3, 0x20000462	// 1984 <csi_tkey_parameter_init+0x9c>
    18fe:	a340      	st.b      	r2, (r3, 0x0)
	byPressDebounce=3;								//Press debounce 1~10
    1900:	1162      	lrw      	r3, 0x20000545	// 1988 <csi_tkey_parameter_init+0xa0>
    1902:	a340      	st.b      	r2, (r3, 0x0)
	byReleaseDebounce=3;							//Release debounce 1~10
    1904:	1162      	lrw      	r3, 0x20000440	// 198c <csi_tkey_parameter_init+0xa4>
    1906:	a340      	st.b      	r2, (r3, 0x0)
	byKeyMode=1;									//Key mode 0=first singlekey,1=multi key,2=strongest single-key
    1908:	3201      	movi      	r2, 1
    190a:	1162      	lrw      	r3, 0x200004a6	// 1990 <csi_tkey_parameter_init+0xa8>
    190c:	a340      	st.b      	r2, (r3, 0x0)
	byMultiTimesFilter=0;							//MultiTimes Filter,>4 ENABLE <4 DISABLE
    190e:	3200      	movi      	r2, 0
    1910:	1161      	lrw      	r3, 0x2000062e	// 1994 <csi_tkey_parameter_init+0xac>
    1912:	a340      	st.b      	r2, (r3, 0x0)
	byValidKeyNum=4;								//Valid Key number when touched
    1914:	3204      	movi      	r2, 4
    1916:	1161      	lrw      	r3, 0x20000524	// 1998 <csi_tkey_parameter_init+0xb0>
    1918:	a340      	st.b      	r2, (r3, 0x0)
	byBaseUpdateSpeed=10;							//baseline update speed
    191a:	320a      	movi      	r2, 10
    191c:	1160      	lrw      	r3, 0x2000036d	// 199c <csi_tkey_parameter_init+0xb4>
    191e:	a340      	st.b      	r2, (r3, 0x0)
	byTkeyRebuildTime=16;							//longpress rebuild time = byTkeyRebuildTime*1s  0=disable
    1920:	3210      	movi      	r2, 16
    1922:	1160      	lrw      	r3, 0x20000322	// 19a0 <csi_tkey_parameter_init+0xb8>
    1924:	a340      	st.b      	r2, (r3, 0x0)
	hwTkeyBaseCnt=59999;							//10ms  byTkeyBaseCnt=10ms*48M/8-1,this register need to modify when mcu's Freq changed
    1926:	ea0215a0 	movi      	r2, 5536
    192a:	6c8a      	nor      	r2, r2
    192c:	107e      	lrw      	r3, 0x200004aa	// 19a4 <csi_tkey_parameter_init+0xbc>
    192e:	ab40      	st.h      	r2, (r3, 0x0)
/****************************************************
//TK parameter fine-tuning
*****************************************************/
	byTkeyFineTurn=DISABLE;							//Tkey sensitivity fine tuning ENABLE/DISABLE
    1930:	3200      	movi      	r2, 0
    1932:	107e      	lrw      	r3, 0x200003b5	// 19a8 <csi_tkey_parameter_init+0xc0>
    1934:	a340      	st.b      	r2, (r3, 0x0)
	byTkeyChxSens[0]=2;								//TCHx manual Sensitivity
    1936:	3202      	movi      	r2, 2
    1938:	107d      	lrw      	r3, 0x20000500	// 19ac <csi_tkey_parameter_init+0xc4>
    193a:	a340      	st.b      	r2, (r3, 0x0)
	byTkeyChxSens[1]=2;								//TCHx manual Sensitivity
    193c:	a341      	st.b      	r2, (r3, 0x1)
	byTkeyChxIcon[0]=5;								//TCHx manual ICON
    193e:	3205      	movi      	r2, 5
    1940:	107c      	lrw      	r3, 0x20000441	// 19b0 <csi_tkey_parameter_init+0xc8>
    1942:	a340      	st.b      	r2, (r3, 0x0)
	byTkeyChxIcon[1]=5;								//TCHx manual ICON
    1944:	a341      	st.b      	r2, (r3, 0x1)
/****************************************************
//TK special parameter define
*****************************************************/
	hwTkeyPselMode=TK_PWRSRC_AVDD;					//tk power sel:TK_PWRSRC_FVR/TK_PWRSRC_AVDD   when select TK_PSEL_FVR PA0.0(TCH24) need a 104 cap
    1946:	ea027fff 	movi      	r2, 32767
    194a:	6c8a      	nor      	r2, r2
    194c:	107a      	lrw      	r3, 0x20000650	// 19b4 <csi_tkey_parameter_init+0xcc>
    194e:	ab40      	st.h      	r2, (r3, 0x0)
	hwTkeyEcLevel=TK_ECLVL_1V;						//C0 voltage sel:TK_ECLVL_1V/TK_ECLVL_2V/TK_ECLVL_3V/TK_ECLVL_3V6
    1950:	3200      	movi      	r2, 0
    1952:	107a      	lrw      	r3, 0x20000464	// 19b8 <csi_tkey_parameter_init+0xd0>
    1954:	ab40      	st.h      	r2, (r3, 0x0)
	hwTkeyFvrLevel=TK_FVR_4096V;					//FVR level:TK_FVR_2048V/TK_FVR_4096V/TK_FVR_NONE
    1956:	3201      	movi      	r2, 1
    1958:	1079      	lrw      	r3, 0x2000036e	// 19bc <csi_tkey_parameter_init+0xd4>
    195a:	ab40      	st.h      	r2, (r3, 0x0)
/****************************************************
//TK low power function define
*****************************************************/
	byTkeyLowPowerMode=ENABLE;						//touch key can goto sleep when TK lowpower mode enable
    195c:	1079      	lrw      	r3, 0x200004fc	// 19c0 <csi_tkey_parameter_init+0xd8>
    195e:	a340      	st.b      	r2, (r3, 0x0)
	byTkeyLowPowerLevel=5;							//0=none 1=16ms 2=32ms 3=64ms 4=128ms,>4=186ms Scan interval when sleep
    1960:	3205      	movi      	r2, 5
    1962:	1079      	lrw      	r3, 0x200004a8	// 19c4 <csi_tkey_parameter_init+0xdc>
    1964:	a340      	st.b      	r2, (r3, 0x0)
	byTkeyWakeupLevel=2;							//0~7;The larger the value the higher the wakeup threshold
    1966:	3202      	movi      	r2, 2
    1968:	1078      	lrw      	r3, 0x200003fb	// 19c8 <csi_tkey_parameter_init+0xe0>
    196a:	a340      	st.b      	r2, (r3, 0x0)
	dwTkeyWakeupIoEnable=TCH_EN(1);					//Sleep wakeup TCHx configuration, Currently only one channel is supported
    196c:	3202      	movi      	r2, 2
    196e:	1078      	lrw      	r3, 0x200004f8	// 19cc <csi_tkey_parameter_init+0xe4>
    1970:	b340      	st.w      	r2, (r3, 0x0)
	//byTkeyDstStatus=1;							
	//byTkeyIntrStatus=1;							
	//byTkeyImtvtimTime=1;
	//byTkeyNegBuildBounce=10;						
	//byTkeyPosBuildBounce=10;						
}
    1972:	783c      	jmp      	r15
    1974:	200004f0 	.long	0x200004f0
    1978:	1effd8ff 	.long	0x1effd8ff
    197c:	200005ac 	.long	0x200005ac
    1980:	200003f8 	.long	0x200003f8
    1984:	20000462 	.long	0x20000462
    1988:	20000545 	.long	0x20000545
    198c:	20000440 	.long	0x20000440
    1990:	200004a6 	.long	0x200004a6
    1994:	2000062e 	.long	0x2000062e
    1998:	20000524 	.long	0x20000524
    199c:	2000036d 	.long	0x2000036d
    19a0:	20000322 	.long	0x20000322
    19a4:	200004aa 	.long	0x200004aa
    19a8:	200003b5 	.long	0x200003b5
    19ac:	20000500 	.long	0x20000500
    19b0:	20000441 	.long	0x20000441
    19b4:	20000650 	.long	0x20000650
    19b8:	20000464 	.long	0x20000464
    19bc:	2000036e 	.long	0x2000036e
    19c0:	200004fc 	.long	0x200004fc
    19c4:	200004a8 	.long	0x200004a8
    19c8:	200003fb 	.long	0x200003fb
    19cc:	200004f8 	.long	0x200004f8

Disassembly of section .text.GPIO_Init:

000019d0 <GPIO_Init>:
//byte:Lowbyte(PIN_0~7),Highbyte(PIN_8~15)
//Dir:0:output 1:input
//ReturnValue:NONE
/*************************************************************/  
void GPIO_Init(CSP_GPIO_T *GPIOx,uint8_t PinNum,GPIO_Dir_TypeDef Dir)
{
    19d0:	14d1      	push      	r4, r15
    19d2:	6d03      	mov      	r4, r0
    uint32_t data_temp;
    uint8_t GPIO_Pin;
    if(PinNum<8)
    19d4:	3907      	cmphsi      	r1, 8
    19d6:	0834      	bt      	0x1a3e	// 1a3e <GPIO_Init+0x6e>
    {
    switch (PinNum)
    19d8:	5903      	subi      	r0, r1, 1
    19da:	3806      	cmphsi      	r0, 7
    19dc:	082b      	bt      	0x1a32	// 1a32 <GPIO_Init+0x62>
    19de:	e3fffe91 	bsr      	0x1700	// 1700 <___gnu_csky_case_uqi>
    19e2:	1104      	.short	0x1104
    19e4:	201c1714 	.long	0x201c1714
    19e8:	0024      	.short	0x0024
    {
        case 0:data_temp=0xfffffff0;GPIO_Pin=0;break;
        case 1:data_temp=0xffffff0f;GPIO_Pin=4;break;
    19ea:	3104      	movi      	r1, 4
    19ec:	3300      	movi      	r3, 0
    19ee:	2bf0      	subi      	r3, 241
        case 4:data_temp=0xfff0ffff;GPIO_Pin=16;break;
        case 5:data_temp=0xff0fffff;GPIO_Pin=20;break;
        case 6:data_temp=0xf0ffffff;GPIO_Pin=24;break;
        case 7:data_temp=0x0fffffff;GPIO_Pin=28;break;
    }
        if (Dir)
    19f0:	3a40      	cmpnei      	r2, 0
        {
          (GPIOx)->CONLR =((GPIOx)->CONLR & data_temp) | 1<<GPIO_Pin;
    19f2:	9440      	ld.w      	r2, (r4, 0x0)
    19f4:	68c8      	and      	r3, r2
        if (Dir)
    19f6:	0c22      	bf      	0x1a3a	// 1a3a <GPIO_Init+0x6a>
          (GPIOx)->CONLR =((GPIOx)->CONLR & data_temp) | 1<<GPIO_Pin;
    19f8:	3201      	movi      	r2, 1
        }
        else
        {
         (GPIOx)->CONLR = ((GPIOx)->CONLR & data_temp) | 2<<GPIO_Pin; 
    19fa:	c4224021 	lsl      	r1, r2, r1
    19fe:	6cc4      	or      	r3, r1
    1a00:	b460      	st.w      	r3, (r4, 0x0)
        else
        {
         (GPIOx)->CONHR = ((GPIOx)->CONHR & data_temp) | 2<<GPIO_Pin;    
        }
    }
}
    1a02:	1491      	pop      	r4, r15
        case 2:data_temp=0xfffff0ff;GPIO_Pin=8;break;
    1a04:	3108      	movi      	r1, 8
    1a06:	116a      	lrw      	r3, 0xfffff0ff	// 1aac <GPIO_Init+0xdc>
    1a08:	07f4      	br      	0x19f0	// 19f0 <GPIO_Init+0x20>
        case 3:data_temp=0xffff0fff;GPIO_Pin=12;break;
    1a0a:	310c      	movi      	r1, 12
    1a0c:	1169      	lrw      	r3, 0xffff0fff	// 1ab0 <GPIO_Init+0xe0>
    1a0e:	07f1      	br      	0x19f0	// 19f0 <GPIO_Init+0x20>
        case 4:data_temp=0xfff0ffff;GPIO_Pin=16;break;
    1a10:	3110      	movi      	r1, 16
    1a12:	ea23fff1 	movih      	r3, 65521
        case 6:data_temp=0xf0ffffff;GPIO_Pin=24;break;
    1a16:	2b00      	subi      	r3, 1
    1a18:	07ec      	br      	0x19f0	// 19f0 <GPIO_Init+0x20>
        case 5:data_temp=0xff0fffff;GPIO_Pin=20;break;
    1a1a:	3114      	movi      	r1, 20
    1a1c:	ea23ff10 	movih      	r3, 65296
    1a20:	07fb      	br      	0x1a16	// 1a16 <GPIO_Init+0x46>
        case 6:data_temp=0xf0ffffff;GPIO_Pin=24;break;
    1a22:	33f1      	movi      	r3, 241
    1a24:	3118      	movi      	r1, 24
    1a26:	4378      	lsli      	r3, r3, 24
    1a28:	07f7      	br      	0x1a16	// 1a16 <GPIO_Init+0x46>
        case 7:data_temp=0x0fffffff;GPIO_Pin=28;break;
    1a2a:	311c      	movi      	r1, 28
    1a2c:	c7605023 	bmaski      	r3, 28
    1a30:	07e0      	br      	0x19f0	// 19f0 <GPIO_Init+0x20>
        case 0:data_temp=0xfffffff0;GPIO_Pin=0;break;
    1a32:	3300      	movi      	r3, 0
    1a34:	3100      	movi      	r1, 0
    1a36:	2b0f      	subi      	r3, 16
    1a38:	07dc      	br      	0x19f0	// 19f0 <GPIO_Init+0x20>
         (GPIOx)->CONLR = ((GPIOx)->CONLR & data_temp) | 2<<GPIO_Pin; 
    1a3a:	3202      	movi      	r2, 2
    1a3c:	07df      	br      	0x19fa	// 19fa <GPIO_Init+0x2a>
    else if (PinNum<16)
    1a3e:	390f      	cmphsi      	r1, 16
    1a40:	0be1      	bt      	0x1a02	// 1a02 <GPIO_Init+0x32>
        switch (PinNum)
    1a42:	2908      	subi      	r1, 9
    1a44:	3906      	cmphsi      	r1, 7
    1a46:	6c07      	mov      	r0, r1
    1a48:	082b      	bt      	0x1a9e	// 1a9e <GPIO_Init+0xce>
    1a4a:	e3fffe5b 	bsr      	0x1700	// 1700 <___gnu_csky_case_uqi>
    1a4e:	1104      	.short	0x1104
    1a50:	201c1714 	.long	0x201c1714
    1a54:	0024      	.short	0x0024
        case 9:data_temp=0xffffff0f;GPIO_Pin=4;break;
    1a56:	3104      	movi      	r1, 4
    1a58:	3300      	movi      	r3, 0
    1a5a:	2bf0      	subi      	r3, 241
      if (Dir)
    1a5c:	3a40      	cmpnei      	r2, 0
        (GPIOx)->CONHR = ((GPIOx)->CONHR & data_temp) | 1<<GPIO_Pin;  
    1a5e:	9441      	ld.w      	r2, (r4, 0x4)
    1a60:	68c8      	and      	r3, r2
      if (Dir)
    1a62:	0c22      	bf      	0x1aa6	// 1aa6 <GPIO_Init+0xd6>
        (GPIOx)->CONHR = ((GPIOx)->CONHR & data_temp) | 1<<GPIO_Pin;  
    1a64:	3201      	movi      	r2, 1
         (GPIOx)->CONHR = ((GPIOx)->CONHR & data_temp) | 2<<GPIO_Pin;    
    1a66:	c4224021 	lsl      	r1, r2, r1
    1a6a:	6cc4      	or      	r3, r1
    1a6c:	b461      	st.w      	r3, (r4, 0x4)
}
    1a6e:	07ca      	br      	0x1a02	// 1a02 <GPIO_Init+0x32>
        case 10:data_temp=0xfffff0ff;GPIO_Pin=8;break;
    1a70:	3108      	movi      	r1, 8
    1a72:	106f      	lrw      	r3, 0xfffff0ff	// 1aac <GPIO_Init+0xdc>
    1a74:	07f4      	br      	0x1a5c	// 1a5c <GPIO_Init+0x8c>
        case 11:data_temp=0xffff0fff;GPIO_Pin=12;break;
    1a76:	310c      	movi      	r1, 12
    1a78:	106e      	lrw      	r3, 0xffff0fff	// 1ab0 <GPIO_Init+0xe0>
    1a7a:	07f1      	br      	0x1a5c	// 1a5c <GPIO_Init+0x8c>
        case 12:data_temp=0xfff0ffff;GPIO_Pin=16;break;
    1a7c:	3110      	movi      	r1, 16
    1a7e:	ea23fff1 	movih      	r3, 65521
        case 14:data_temp=0xf0ffffff;GPIO_Pin=24;break;
    1a82:	2b00      	subi      	r3, 1
    1a84:	07ec      	br      	0x1a5c	// 1a5c <GPIO_Init+0x8c>
        case 13:data_temp=0xff0fffff;GPIO_Pin=20;break;
    1a86:	3114      	movi      	r1, 20
    1a88:	ea23ff10 	movih      	r3, 65296
    1a8c:	07fb      	br      	0x1a82	// 1a82 <GPIO_Init+0xb2>
        case 14:data_temp=0xf0ffffff;GPIO_Pin=24;break;
    1a8e:	33f1      	movi      	r3, 241
    1a90:	3118      	movi      	r1, 24
    1a92:	4378      	lsli      	r3, r3, 24
    1a94:	07f7      	br      	0x1a82	// 1a82 <GPIO_Init+0xb2>
        case 15:data_temp=0x0fffffff;GPIO_Pin=28;break;
    1a96:	311c      	movi      	r1, 28
    1a98:	c7605023 	bmaski      	r3, 28
    1a9c:	07e0      	br      	0x1a5c	// 1a5c <GPIO_Init+0x8c>
        case 8:data_temp=0xfffffff0;GPIO_Pin=0;break;
    1a9e:	3300      	movi      	r3, 0
    1aa0:	3100      	movi      	r1, 0
    1aa2:	2b0f      	subi      	r3, 16
    1aa4:	07dc      	br      	0x1a5c	// 1a5c <GPIO_Init+0x8c>
         (GPIOx)->CONHR = ((GPIOx)->CONHR & data_temp) | 2<<GPIO_Pin;    
    1aa6:	3202      	movi      	r2, 2
    1aa8:	07df      	br      	0x1a66	// 1a66 <GPIO_Init+0x96>
    1aaa:	0000      	bkpt
    1aac:	fffff0ff 	.long	0xfffff0ff
    1ab0:	ffff0fff 	.long	0xffff0fff

Disassembly of section .text.GPIO_Reverse:

00001ab4 <GPIO_Reverse>:
//ReturnValue:VALUE
/*************************************************************/
void GPIO_Reverse(CSP_GPIO_T *GPIOx,uint8_t bit)
{
     uint32_t dat = 0;
     dat=((GPIOx)->ODSR>>bit)&1ul;
    1ab4:	3301      	movi      	r3, 1
    1ab6:	9045      	ld.w      	r2, (r0, 0x14)
    1ab8:	7085      	lsr      	r2, r1
    1aba:	688c      	and      	r2, r3
    1abc:	c4234021 	lsl      	r1, r3, r1
     {
       if (dat==1)  
    1ac0:	3a40      	cmpnei      	r2, 0
    1ac2:	0c03      	bf      	0x1ac8	// 1ac8 <GPIO_Reverse+0x14>
       {
           (GPIOx)->CODR = (1ul<<bit);
    1ac4:	b024      	st.w      	r1, (r0, 0x10)
       {
           (GPIOx)->SODR = (1ul<<bit);
           return;
       }
     }
}
    1ac6:	783c      	jmp      	r15
           (GPIOx)->SODR = (1ul<<bit);
    1ac8:	b023      	st.w      	r1, (r0, 0xc)
           return;
    1aca:	07fe      	br      	0x1ac6	// 1ac6 <GPIO_Reverse+0x12>

Disassembly of section .text.I2C_Slave_CONFIG:

00001acc <I2C_Slave_CONFIG>:
//I2C_SALVE_ADD:I2C SLAVE ADDRESS
//ReturnValue:NONE
/*************************************************************/
void I2C_Slave_CONFIG(I2C_SDA_TypeDef I2C_SDA_IO,I2C_SCL_TypeDef I2C_SCL_IO,I2C_SPEEDMODE_TypeDef SPEEDMODE,
						I2C_SLAVEBITS_TypeDef SLAVEBITS,U16_T I2C_SALVE_ADDS,U16_T SS_SCLHX,U16_T SS_SCLLX)
{
    1acc:	14c4      	push      	r4-r7
    1ace:	1421      	subi      	r14, r14, 4
	//SDA IO Initial
    if(I2C_SDA_IO==I2C_SDA_PA0_3)
    1ad0:	3840      	cmpnei      	r0, 0
{
    1ad2:	b860      	st.w      	r3, (r14, 0x0)
    1ad4:	d8ce100a 	ld.h      	r6, (r14, 0x14)
    1ad8:	d8ae100c 	ld.h      	r5, (r14, 0x18)
    1adc:	d88e100e 	ld.h      	r4, (r14, 0x1c)
    if(I2C_SDA_IO==I2C_SDA_PA0_3)
    1ae0:	0829      	bt      	0x1b32	// 1b32 <I2C_Slave_CONFIG+0x66>
    {
    GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFF0FFF)  | 0x00005000;          
    1ae2:	121c      	lrw      	r0, 0x20000088	// 1c50 <I2C_Slave_CONFIG+0x184>
    1ae4:	127c      	lrw      	r3, 0xffff0fff	// 1c54 <I2C_Slave_CONFIG+0x188>
    1ae6:	90e0      	ld.w      	r7, (r0, 0x0)
    1ae8:	9700      	ld.w      	r0, (r7, 0x0)
    1aea:	680c      	and      	r0, r3
    1aec:	ec005000 	ori      	r0, r0, 20480
    {
    GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFF0)  | 0x00000006;          
    }
	if(I2C_SDA_IO==I2C_SDA_PB0_7)
    {
    GPIOB0->CONLR = (GPIOB0->CONLR&0X0FFFFFFF)  | 0x50000000;          
    1af0:	b700      	st.w      	r0, (r7, 0x0)
	if(I2C_SDA_IO==I2C_SDA_PA1_13)
    {
    GPIOA1->CONHR = (GPIOA1->CONHR&0XFF0FFFFF)  | 0x00900000;          
    }
	//SCL IO Initial
	if (I2C_SCL_IO==I2C_SCL_PA0_3)
    1af2:	3940      	cmpnei      	r1, 0
    1af4:	0863      	bt      	0x1bba	// 1bba <I2C_Slave_CONFIG+0xee>
    {
    GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFF0FFF)  | 0x00007000;               
    1af6:	1237      	lrw      	r1, 0x20000088	// 1c50 <I2C_Slave_CONFIG+0x184>
    1af8:	1277      	lrw      	r3, 0xffff0fff	// 1c54 <I2C_Slave_CONFIG+0x188>
    1afa:	9100      	ld.w      	r0, (r1, 0x0)
    1afc:	9020      	ld.w      	r1, (r0, 0x0)
    1afe:	684c      	and      	r1, r3
    1b00:	ec217000 	ori      	r1, r1, 28672
    {
    GPIOA0->CONLR = (GPIOA0->CONLR&0X0FFFFFFF)  | 0x60000000;               
    }
	if (I2C_SCL_IO==I2C_SCL_PB0_6)
    {
    GPIOB0->CONLR = (GPIOB0->CONLR&0XF0FFFFFF)  | 0x05000000;               
    1b04:	b020      	st.w      	r1, (r0, 0x0)
    {
    GPIOA1->CONHR = (GPIOA1->CONHR&0XFFF0FFFF)  | 0x00090000;               
    }


	I2C0->ENABLE = (I2C0->ENABLE&0XFFFFFFFE)|I2C_DISABLE;
    1b06:	1235      	lrw      	r1, 0x20000060	// 1c58 <I2C_Slave_CONFIG+0x18c>
	I2C0->CR =(I2C0->CR&0XFFFFF000)| I2C_MASTER_DIS |I2C_SLAVE_EN | SPEEDMODE | SLAVEBITS;
    1b08:	1275      	lrw      	r3, 0xfffff000	// 1c5c <I2C_Slave_CONFIG+0x190>
	I2C0->ENABLE = (I2C0->ENABLE&0XFFFFFFFE)|I2C_DISABLE;
    1b0a:	9120      	ld.w      	r1, (r1, 0x0)
	I2C0->SADDR = I2C_SALVE_ADDS;
	if(SPEEDMODE==FAST_MODE)
    1b0c:	3a44      	cmpnei      	r2, 4
	I2C0->ENABLE = (I2C0->ENABLE&0XFFFFFFFE)|I2C_DISABLE;
    1b0e:	910f      	ld.w      	r0, (r1, 0x3c)
    1b10:	3880      	bclri      	r0, 0
    1b12:	b10f      	st.w      	r0, (r1, 0x3c)
	I2C0->CR =(I2C0->CR&0XFFFFF000)| I2C_MASTER_DIS |I2C_SLAVE_EN | SPEEDMODE | SLAVEBITS;
    1b14:	9100      	ld.w      	r0, (r1, 0x0)
    1b16:	680c      	and      	r0, r3
    1b18:	9860      	ld.w      	r3, (r14, 0x0)
    1b1a:	6cc0      	or      	r3, r0
    1b1c:	6cc8      	or      	r3, r2
    1b1e:	b160      	st.w      	r3, (r1, 0x0)
	I2C0->SADDR = I2C_SALVE_ADDS;
    1b20:	b1c2      	st.w      	r6, (r1, 0x8)
	if(SPEEDMODE==FAST_MODE)
    1b22:	0891      	bt      	0x1c44	// 1c44 <I2C_Slave_CONFIG+0x178>
	{
		I2C0->FS_SCLH  = SS_SCLHX;  							//SCL high time
    1b24:	b1a7      	st.w      	r5, (r1, 0x1c)
		I2C0->FS_SCLL  = SS_SCLLX;  							//SCL low  time
    1b26:	b188      	st.w      	r4, (r1, 0x20)
	else if(SPEEDMODE==STANDARD_MODE)
	{
		I2C0->SS_SCLH  = SS_SCLHX;  							//SCL high time
		I2C0->SS_SCLL  = SS_SCLLX;  							//SCL low  time
	}
	INTC_IPR4_WRITE(0X40400040);   								//setting highest INT Priority when using i2c as salve
    1b28:	126e      	lrw      	r3, 0xe000e400	// 1c60 <I2C_Slave_CONFIG+0x194>
    1b2a:	124f      	lrw      	r2, 0x40400040	// 1c64 <I2C_Slave_CONFIG+0x198>
    1b2c:	b344      	st.w      	r2, (r3, 0x10)
}
    1b2e:	1401      	addi      	r14, r14, 4
    1b30:	1484      	pop      	r4-r7
    if(I2C_SDA_IO==I2C_SDA_PA0_4)
    1b32:	3841      	cmpnei      	r0, 1
    1b34:	080c      	bt      	0x1b4c	// 1b4c <I2C_Slave_CONFIG+0x80>
    GPIOA0->CONLR = (GPIOA0->CONLR&0XFFF0FFFF)  | 0x00070000;          
    1b36:	1207      	lrw      	r0, 0x20000088	// 1c50 <I2C_Slave_CONFIG+0x184>
    1b38:	ea23fff1 	movih      	r3, 65521
    1b3c:	90e0      	ld.w      	r7, (r0, 0x0)
    1b3e:	2b00      	subi      	r3, 1
    1b40:	9700      	ld.w      	r0, (r7, 0x0)
    1b42:	680c      	and      	r0, r3
    1b44:	33e0      	movi      	r3, 224
    1b46:	436b      	lsli      	r3, r3, 11
    1b48:	6c0c      	or      	r0, r3
    1b4a:	07d3      	br      	0x1af0	// 1af0 <I2C_Slave_CONFIG+0x24>
	if(I2C_SDA_IO==I2C_SDA_PB0_1)
    1b4c:	3842      	cmpnei      	r0, 2
    1b4e:	080a      	bt      	0x1b62	// 1b62 <I2C_Slave_CONFIG+0x96>
    GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFF0F)  | 0x00000060;          
    1b50:	1206      	lrw      	r0, 0x20000080	// 1c68 <I2C_Slave_CONFIG+0x19c>
    1b52:	3300      	movi      	r3, 0
    1b54:	90e0      	ld.w      	r7, (r0, 0x0)
    1b56:	2bf0      	subi      	r3, 241
    1b58:	9700      	ld.w      	r0, (r7, 0x0)
    1b5a:	680c      	and      	r0, r3
    1b5c:	ec000060 	ori      	r0, r0, 96
    1b60:	07c8      	br      	0x1af0	// 1af0 <I2C_Slave_CONFIG+0x24>
	if(I2C_SDA_IO==I2C_SDA_PA0_8)
    1b62:	3843      	cmpnei      	r0, 3
    1b64:	080b      	bt      	0x1b7a	// 1b7a <I2C_Slave_CONFIG+0xae>
    GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFF0)  | 0x00000006;          
    1b66:	111b      	lrw      	r0, 0x20000088	// 1c50 <I2C_Slave_CONFIG+0x184>
    1b68:	3300      	movi      	r3, 0
    1b6a:	90e0      	ld.w      	r7, (r0, 0x0)
    1b6c:	2b0f      	subi      	r3, 16
    1b6e:	9701      	ld.w      	r0, (r7, 0x4)
    1b70:	680c      	and      	r0, r3
    1b72:	ec000006 	ori      	r0, r0, 6
    GPIOA1->CONHR = (GPIOA1->CONHR&0XFF0FFFFF)  | 0x00900000;          
    1b76:	b701      	st.w      	r0, (r7, 0x4)
    1b78:	07bd      	br      	0x1af2	// 1af2 <I2C_Slave_CONFIG+0x26>
	if(I2C_SDA_IO==I2C_SDA_PB0_7)
    1b7a:	3844      	cmpnei      	r0, 4
    1b7c:	0809      	bt      	0x1b8e	// 1b8e <I2C_Slave_CONFIG+0xc2>
    GPIOB0->CONLR = (GPIOB0->CONLR&0X0FFFFFFF)  | 0x50000000;          
    1b7e:	111b      	lrw      	r0, 0x20000080	// 1c68 <I2C_Slave_CONFIG+0x19c>
    1b80:	90e0      	ld.w      	r7, (r0, 0x0)
    1b82:	9700      	ld.w      	r0, (r7, 0x0)
    1b84:	4004      	lsli      	r0, r0, 4
    1b86:	4804      	lsri      	r0, r0, 4
    1b88:	38bc      	bseti      	r0, 28
    1b8a:	38be      	bseti      	r0, 30
    1b8c:	07b2      	br      	0x1af0	// 1af0 <I2C_Slave_CONFIG+0x24>
	if(I2C_SDA_IO==I2C_SDA_PA1_10)
    1b8e:	3845      	cmpnei      	r0, 5
    1b90:	0809      	bt      	0x1ba2	// 1ba2 <I2C_Slave_CONFIG+0xd6>
    GPIOA1->CONHR = (GPIOA1->CONHR&0XFFFFF0FF)  | 0x00000900;          
    1b92:	1117      	lrw      	r0, 0x20000084	// 1c6c <I2C_Slave_CONFIG+0x1a0>
    1b94:	1177      	lrw      	r3, 0xfffff0ff	// 1c70 <I2C_Slave_CONFIG+0x1a4>
    1b96:	90e0      	ld.w      	r7, (r0, 0x0)
    1b98:	9701      	ld.w      	r0, (r7, 0x4)
    1b9a:	680c      	and      	r0, r3
    1b9c:	ec000900 	ori      	r0, r0, 2304
    1ba0:	07eb      	br      	0x1b76	// 1b76 <I2C_Slave_CONFIG+0xaa>
	if(I2C_SDA_IO==I2C_SDA_PA1_13)
    1ba2:	3846      	cmpnei      	r0, 6
    1ba4:	0ba7      	bt      	0x1af2	// 1af2 <I2C_Slave_CONFIG+0x26>
    GPIOA1->CONHR = (GPIOA1->CONHR&0XFF0FFFFF)  | 0x00900000;          
    1ba6:	1112      	lrw      	r0, 0x20000084	// 1c6c <I2C_Slave_CONFIG+0x1a0>
    1ba8:	ea23ff10 	movih      	r3, 65296
    1bac:	90e0      	ld.w      	r7, (r0, 0x0)
    1bae:	2b00      	subi      	r3, 1
    1bb0:	9701      	ld.w      	r0, (r7, 0x4)
    1bb2:	680c      	and      	r0, r3
    1bb4:	38b4      	bseti      	r0, 20
    1bb6:	38b7      	bseti      	r0, 23
    1bb8:	07df      	br      	0x1b76	// 1b76 <I2C_Slave_CONFIG+0xaa>
	if (I2C_SCL_IO==I2C_SCL_PA0_4)
    1bba:	3941      	cmpnei      	r1, 1
    1bbc:	080b      	bt      	0x1bd2	// 1bd2 <I2C_Slave_CONFIG+0x106>
    GPIOA0->CONLR = (GPIOA0->CONLR&0XFFF0FFFF)  | 0x00050000;               
    1bbe:	1125      	lrw      	r1, 0x20000088	// 1c50 <I2C_Slave_CONFIG+0x184>
    1bc0:	ea23fff1 	movih      	r3, 65521
    1bc4:	9100      	ld.w      	r0, (r1, 0x0)
    1bc6:	2b00      	subi      	r3, 1
    1bc8:	9020      	ld.w      	r1, (r0, 0x0)
    1bca:	684c      	and      	r1, r3
    1bcc:	39b0      	bseti      	r1, 16
    1bce:	39b2      	bseti      	r1, 18
    1bd0:	079a      	br      	0x1b04	// 1b04 <I2C_Slave_CONFIG+0x38>
	if (I2C_SCL_IO==I2C_SCL_PB0_0)
    1bd2:	3942      	cmpnei      	r1, 2
    1bd4:	080a      	bt      	0x1be8	// 1be8 <I2C_Slave_CONFIG+0x11c>
    GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFF0)  | 0x00000006;               
    1bd6:	1125      	lrw      	r1, 0x20000080	// 1c68 <I2C_Slave_CONFIG+0x19c>
    1bd8:	3300      	movi      	r3, 0
    1bda:	9100      	ld.w      	r0, (r1, 0x0)
    1bdc:	2b0f      	subi      	r3, 16
    1bde:	9020      	ld.w      	r1, (r0, 0x0)
    1be0:	684c      	and      	r1, r3
    1be2:	ec210006 	ori      	r1, r1, 6
    1be6:	078f      	br      	0x1b04	// 1b04 <I2C_Slave_CONFIG+0x38>
	if (I2C_SCL_IO==I2C_SCL_PA0_7)
    1be8:	3943      	cmpnei      	r1, 3
    1bea:	0809      	bt      	0x1bfc	// 1bfc <I2C_Slave_CONFIG+0x130>
    GPIOA0->CONLR = (GPIOA0->CONLR&0X0FFFFFFF)  | 0x60000000;               
    1bec:	1039      	lrw      	r1, 0x20000088	// 1c50 <I2C_Slave_CONFIG+0x184>
    1bee:	9100      	ld.w      	r0, (r1, 0x0)
    1bf0:	9020      	ld.w      	r1, (r0, 0x0)
    1bf2:	4124      	lsli      	r1, r1, 4
    1bf4:	4924      	lsri      	r1, r1, 4
    1bf6:	39bd      	bseti      	r1, 29
    1bf8:	39be      	bseti      	r1, 30
    1bfa:	0785      	br      	0x1b04	// 1b04 <I2C_Slave_CONFIG+0x38>
	if (I2C_SCL_IO==I2C_SCL_PB0_6)
    1bfc:	3944      	cmpnei      	r1, 4
    1bfe:	080b      	bt      	0x1c14	// 1c14 <I2C_Slave_CONFIG+0x148>
    GPIOB0->CONLR = (GPIOB0->CONLR&0XF0FFFFFF)  | 0x05000000;               
    1c00:	103a      	lrw      	r1, 0x20000080	// 1c68 <I2C_Slave_CONFIG+0x19c>
    1c02:	33f1      	movi      	r3, 241
    1c04:	9100      	ld.w      	r0, (r1, 0x0)
    1c06:	4378      	lsli      	r3, r3, 24
    1c08:	9020      	ld.w      	r1, (r0, 0x0)
    1c0a:	2b00      	subi      	r3, 1
    1c0c:	684c      	and      	r1, r3
    1c0e:	39b8      	bseti      	r1, 24
    1c10:	39ba      	bseti      	r1, 26
    1c12:	0779      	br      	0x1b04	// 1b04 <I2C_Slave_CONFIG+0x38>
	if (I2C_SCL_IO==I2C_SCL_PA1_9)
    1c14:	3945      	cmpnei      	r1, 5
    1c16:	080b      	bt      	0x1c2c	// 1c2c <I2C_Slave_CONFIG+0x160>
    GPIOA1->CONHR = (GPIOA1->CONHR&0XFFFFFF0F)  | 0x00000090;               
    1c18:	1035      	lrw      	r1, 0x20000084	// 1c6c <I2C_Slave_CONFIG+0x1a0>
    1c1a:	3300      	movi      	r3, 0
    1c1c:	9100      	ld.w      	r0, (r1, 0x0)
    1c1e:	2bf0      	subi      	r3, 241
    1c20:	9021      	ld.w      	r1, (r0, 0x4)
    1c22:	684c      	and      	r1, r3
    1c24:	ec210090 	ori      	r1, r1, 144
    GPIOA1->CONHR = (GPIOA1->CONHR&0XFFF0FFFF)  | 0x00090000;               
    1c28:	b021      	st.w      	r1, (r0, 0x4)
    1c2a:	076e      	br      	0x1b06	// 1b06 <I2C_Slave_CONFIG+0x3a>
	if (I2C_SCL_IO==I2C_SCL_PA1_12)
    1c2c:	3946      	cmpnei      	r1, 6
    1c2e:	0b6c      	bt      	0x1b06	// 1b06 <I2C_Slave_CONFIG+0x3a>
    GPIOA1->CONHR = (GPIOA1->CONHR&0XFFF0FFFF)  | 0x00090000;               
    1c30:	102f      	lrw      	r1, 0x20000084	// 1c6c <I2C_Slave_CONFIG+0x1a0>
    1c32:	ea23fff1 	movih      	r3, 65521
    1c36:	9100      	ld.w      	r0, (r1, 0x0)
    1c38:	2b00      	subi      	r3, 1
    1c3a:	9021      	ld.w      	r1, (r0, 0x4)
    1c3c:	684c      	and      	r1, r3
    1c3e:	39b0      	bseti      	r1, 16
    1c40:	39b3      	bseti      	r1, 19
    1c42:	07f3      	br      	0x1c28	// 1c28 <I2C_Slave_CONFIG+0x15c>
	else if(SPEEDMODE==STANDARD_MODE)
    1c44:	3a42      	cmpnei      	r2, 2
    1c46:	0b71      	bt      	0x1b28	// 1b28 <I2C_Slave_CONFIG+0x5c>
		I2C0->SS_SCLH  = SS_SCLHX;  							//SCL high time
    1c48:	b1a5      	st.w      	r5, (r1, 0x14)
		I2C0->SS_SCLL  = SS_SCLLX;  							//SCL low  time
    1c4a:	b186      	st.w      	r4, (r1, 0x18)
    1c4c:	076e      	br      	0x1b28	// 1b28 <I2C_Slave_CONFIG+0x5c>
    1c4e:	0000      	bkpt
    1c50:	20000088 	.long	0x20000088
    1c54:	ffff0fff 	.long	0xffff0fff
    1c58:	20000060 	.long	0x20000060
    1c5c:	fffff000 	.long	0xfffff000
    1c60:	e000e400 	.long	0xe000e400
    1c64:	40400040 	.long	0x40400040
    1c68:	20000080 	.long	0x20000080
    1c6c:	20000084 	.long	0x20000084
    1c70:	fffff0ff 	.long	0xfffff0ff

Disassembly of section .text.I2C_SDA_TSETUP_THOLD_CONFIG:

00001c74 <I2C_SDA_TSETUP_THOLD_CONFIG>:
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_SDA_TSETUP_THOLD_CONFIG(U8_T SDA_TSETUP , U8_T SDA_RX_THOLD , U16_T SDA_TX_THOLD)
{
	I2C0->SDA_TSETUP=SDA_TSETUP;
    1c74:	1064      	lrw      	r3, 0x20000060	// 1c84 <I2C_SDA_TSETUP_THOLD_CONFIG+0x10>
	I2C0->SDA_THOLD=(SDA_RX_THOLD<<16)|SDA_TX_THOLD;
    1c76:	4130      	lsli      	r1, r1, 16
	I2C0->SDA_TSETUP=SDA_TSETUP;
    1c78:	9360      	ld.w      	r3, (r3, 0x0)
	I2C0->SDA_THOLD=(SDA_RX_THOLD<<16)|SDA_TX_THOLD;
    1c7a:	6c84      	or      	r2, r1
	I2C0->SDA_TSETUP=SDA_TSETUP;
    1c7c:	b312      	st.w      	r0, (r3, 0x48)
	I2C0->SDA_THOLD=(SDA_RX_THOLD<<16)|SDA_TX_THOLD;
    1c7e:	b353      	st.w      	r2, (r3, 0x4c)
}
    1c80:	783c      	jmp      	r15
    1c82:	0000      	bkpt
    1c84:	20000060 	.long	0x20000060

Disassembly of section .text.I2C_ConfigInterrupt_CMD:

00001c88 <I2C_ConfigInterrupt_CMD>:
//				 I2C_RESTART_DET,I2C_MST_ON_HOLD,I2C_SCL_SLOW   
//NewState:ENABLE/DISABLE
//ReturnValue:NONE
/*************************************************************/
void I2C_ConfigInterrupt_CMD(FunctionalStatus NewState,U32_T INT_TYPE)
{
    1c88:	1066      	lrw      	r3, 0x20000060	// 1ca0 <I2C_ConfigInterrupt_CMD+0x18>
	if(NewState != DISABLE)
    1c8a:	3840      	cmpnei      	r0, 0
	{
		I2C0->IMSCR |= INT_TYPE;
    1c8c:	9360      	ld.w      	r3, (r3, 0x0)
    1c8e:	9357      	ld.w      	r2, (r3, 0x5c)
	if(NewState != DISABLE)
    1c90:	0c04      	bf      	0x1c98	// 1c98 <I2C_ConfigInterrupt_CMD+0x10>
		I2C0->IMSCR |= INT_TYPE;
    1c92:	6c48      	or      	r1, r2
	}
	else
	{
		I2C0->IMSCR &= (~INT_TYPE);
    1c94:	b337      	st.w      	r1, (r3, 0x5c)
	}
}
    1c96:	783c      	jmp      	r15
		I2C0->IMSCR &= (~INT_TYPE);
    1c98:	c4222041 	andn      	r1, r2, r1
    1c9c:	07fc      	br      	0x1c94	// 1c94 <I2C_ConfigInterrupt_CMD+0xc>
    1c9e:	0000      	bkpt
    1ca0:	20000060 	.long	0x20000060

Disassembly of section .text.I2C_FIFO_TriggerData:

00001ca4 <I2C_FIFO_TriggerData>:
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_FIFO_TriggerData(U16_T RX_FLSEL,U16_T TX_FLSEL)
{
	I2C0->RX_FLSEL = RX_FLSEL;  							
    1ca4:	1063      	lrw      	r3, 0x20000060	// 1cb0 <I2C_FIFO_TriggerData+0xc>
    1ca6:	9360      	ld.w      	r3, (r3, 0x0)
    1ca8:	b30b      	st.w      	r0, (r3, 0x2c)
	I2C0->TX_FLSEL = TX_FLSEL;  							
    1caa:	b32c      	st.w      	r1, (r3, 0x30)
}
    1cac:	783c      	jmp      	r15
    1cae:	0000      	bkpt
    1cb0:	20000060 	.long	0x20000060

Disassembly of section .text.I2C_Enable:

00001cb4 <I2C_Enable>:
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_Enable(void)
{
	I2C0->ENABLE = (I2C0->ENABLE&0XFFFFFFFE)|I2C_ENABLE;                         //Enable I2C
    1cb4:	1067      	lrw      	r3, 0x20000060	// 1cd0 <I2C_Enable+0x1c>
	while((I2C0->STATUS&0x1000)!=0x1000);
    1cb6:	3280      	movi      	r2, 128
	I2C0->ENABLE = (I2C0->ENABLE&0XFFFFFFFE)|I2C_ENABLE;                         //Enable I2C
    1cb8:	9320      	ld.w      	r1, (r3, 0x0)
	while((I2C0->STATUS&0x1000)!=0x1000);
    1cba:	4245      	lsli      	r2, r2, 5
	I2C0->ENABLE = (I2C0->ENABLE&0XFFFFFFFE)|I2C_ENABLE;                         //Enable I2C
    1cbc:	916f      	ld.w      	r3, (r1, 0x3c)
    1cbe:	ec630001 	ori      	r3, r3, 1
    1cc2:	b16f      	st.w      	r3, (r1, 0x3c)
	while((I2C0->STATUS&0x1000)!=0x1000);
    1cc4:	9170      	ld.w      	r3, (r1, 0x40)
    1cc6:	68c8      	and      	r3, r2
    1cc8:	3b40      	cmpnei      	r3, 0
    1cca:	0ffd      	bf      	0x1cc4	// 1cc4 <I2C_Enable+0x10>
}
    1ccc:	783c      	jmp      	r15
    1cce:	0000      	bkpt
    1cd0:	20000060 	.long	0x20000060

Disassembly of section .text.I2C_Disable:

00001cd4 <I2C_Disable>:
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_Disable(void)
{
	I2C0->ENABLE =(I2C0->ENABLE&0XFFFFFFFE)|I2C_DISABLE;                         //Disable I2C
    1cd4:	1066      	lrw      	r3, 0x20000060	// 1cec <I2C_Disable+0x18>
	while((I2C0->STATUS&0x1000)==0x1000);
    1cd6:	3280      	movi      	r2, 128
	I2C0->ENABLE =(I2C0->ENABLE&0XFFFFFFFE)|I2C_DISABLE;                         //Disable I2C
    1cd8:	9320      	ld.w      	r1, (r3, 0x0)
	while((I2C0->STATUS&0x1000)==0x1000);
    1cda:	4245      	lsli      	r2, r2, 5
	I2C0->ENABLE =(I2C0->ENABLE&0XFFFFFFFE)|I2C_DISABLE;                         //Disable I2C
    1cdc:	916f      	ld.w      	r3, (r1, 0x3c)
    1cde:	3b80      	bclri      	r3, 0
    1ce0:	b16f      	st.w      	r3, (r1, 0x3c)
	while((I2C0->STATUS&0x1000)==0x1000);
    1ce2:	9170      	ld.w      	r3, (r1, 0x40)
    1ce4:	68c8      	and      	r3, r2
    1ce6:	3b40      	cmpnei      	r3, 0
    1ce8:	0bfd      	bt      	0x1ce2	// 1ce2 <I2C_Disable+0xe>
}
    1cea:	783c      	jmp      	r15
    1cec:	20000060 	.long	0x20000060

Disassembly of section .text.I2C_Int_Enable:

00001cf0 <I2C_Int_Enable>:
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_Int_Enable(void)
{
	INTC_ISER_WRITE(I2C_INT);                             //Enable I2C interrupt
    1cf0:	1043      	lrw      	r2, 0xe000e100	// 1cfc <I2C_Int_Enable+0xc>
    1cf2:	3380      	movi      	r3, 128
    1cf4:	436c      	lsli      	r3, r3, 12
    1cf6:	b260      	st.w      	r3, (r2, 0x0)
}
    1cf8:	783c      	jmp      	r15
    1cfa:	0000      	bkpt
    1cfc:	e000e100 	.long	0xe000e100

Disassembly of section .text.I2C_RESET:

00001d00 <I2C_RESET>:
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_RESET(void)
{
	I2C0->SRR=0X3;
    1d00:	1063      	lrw      	r3, 0x20000060	// 1d0c <I2C_RESET+0xc>
    1d02:	3203      	movi      	r2, 3
    1d04:	9360      	ld.w      	r3, (r3, 0x0)
    1d06:	dc432023 	st.w      	r2, (r3, 0x8c)
}
    1d0a:	783c      	jmp      	r15
    1d0c:	20000060 	.long	0x20000060

Disassembly of section .text.I2C_Slave_Receive:

00001d10 <I2C_Slave_Receive>:
//I2C slave Receive
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_Slave_Receive(void)
{
    1d10:	14d2      	push      	r4-r5, r15
	
	if(!(((I2C0->MISR&I2C_SCL_SLOW)==I2C_SCL_SLOW)
    1d12:	1381      	lrw      	r4, 0x20000060	// 1e94 <I2C_Slave_Receive+0x184>
    1d14:	3180      	movi      	r1, 128
    1d16:	9460      	ld.w      	r3, (r4, 0x0)
    1d18:	4127      	lsli      	r1, r1, 7
    1d1a:	9356      	ld.w      	r2, (r3, 0x58)
    1d1c:	6884      	and      	r2, r1
    1d1e:	3a40      	cmpnei      	r2, 0
    1d20:	08a3      	bt      	0x1e66	// 1e66 <I2C_Slave_Receive+0x156>
			||((I2C0->MISR&I2C_TX_ABRT)==I2C_TX_ABRT)))				 //SCLK锁死,IIC发送中止))
    1d22:	9356      	ld.w      	r2, (r3, 0x58)
    1d24:	e4422040 	andi      	r2, r2, 64
	if(!(((I2C0->MISR&I2C_SCL_SLOW)==I2C_SCL_SLOW)
    1d28:	3a40      	cmpnei      	r2, 0
    1d2a:	089e      	bt      	0x1e66	// 1e66 <I2C_Slave_Receive+0x156>
	{
	if((I2C0->MISR&I2C_RX_FULL)==I2C_RX_FULL)        //有接收到数据
    1d2c:	9356      	ld.w      	r2, (r3, 0x58)
    1d2e:	e4422004 	andi      	r2, r2, 4
    1d32:	3a40      	cmpnei      	r2, 0
    1d34:	0c14      	bf      	0x1d5c	// 1d5c <I2C_Slave_Receive+0x4c>
	{
		if(RdIndex==0)
    1d36:	1259      	lrw      	r2, 0x200000b8	// 1e98 <I2C_Slave_Receive+0x188>
    1d38:	8221      	ld.b      	r1, (r2, 0x1)
    1d3a:	3940      	cmpnei      	r1, 0
    1d3c:	086c      	bt      	0x1e14	// 1e14 <I2C_Slave_Receive+0x104>
		{
			RdIndex=1;
    1d3e:	3101      	movi      	r1, 1
    1d40:	a221      	st.b      	r1, (r2, 0x1)
			I2C_Data_Adress=I2C0->DATA_CMD&0XFF;
    1d42:	1237      	lrw      	r1, 0x200001d0	// 1e9c <I2C_Slave_Receive+0x18c>
    1d44:	9344      	ld.w      	r2, (r3, 0x10)
    1d46:	7488      	zextb      	r2, r2
    1d48:	a140      	st.b      	r2, (r1, 0x0)
			I2C_St_Adress=I2C_Data_Adress;
    1d4a:	8140      	ld.b      	r2, (r1, 0x0)
    1d4c:	1235      	lrw      	r1, 0x200000d0	// 1ea0 <I2C_Slave_Receive+0x190>
    1d4e:	7488      	zextb      	r2, r2
    1d50:	a140      	st.b      	r2, (r1, 0x0)
			{
				I2CRdBuffer[I2C_Data_Adress]= I2C0->DATA_CMD&0XFF;
			}
			I2C_Data_Adress++;
		}
		I2C0->ICR = I2C_RX_FULL;
    1d52:	3204      	movi      	r2, 4
		R_IIC_ERROR_CONT=0;
    1d54:	3100      	movi      	r1, 0
		I2C0->ICR = I2C_RX_FULL;
    1d56:	b359      	st.w      	r2, (r3, 0x64)
		R_IIC_ERROR_CONT=0;
    1d58:	1253      	lrw      	r2, 0x200000cc	// 1ea4 <I2C_Slave_Receive+0x194>
    1d5a:	b220      	st.w      	r1, (r2, 0x0)
	}
		
	if((I2C0->MISR&I2C_RD_REQ)==I2C_RD_REQ)			//读请求产生
    1d5c:	9356      	ld.w      	r2, (r3, 0x58)
    1d5e:	e4422020 	andi      	r2, r2, 32
    1d62:	3a40      	cmpnei      	r2, 0
    1d64:	0c22      	bf      	0x1da8	// 1da8 <I2C_Slave_Receive+0x98>
	{
		if(RdIndex==1)
    1d66:	122d      	lrw      	r1, 0x200000b8	// 1e98 <I2C_Slave_Receive+0x188>
    1d68:	8141      	ld.b      	r2, (r1, 0x1)
    1d6a:	3a41      	cmpnei      	r2, 1
    1d6c:	0819      	bt      	0x1d9e	// 1d9e <I2C_Slave_Receive+0x8e>
		{
			RdIndex=2;
    1d6e:	3202      	movi      	r2, 2
    1d70:	a141      	st.b      	r2, (r1, 0x1)
			WrIndex = I2C_St_Adress;
    1d72:	124c      	lrw      	r2, 0x200000d0	// 1ea0 <I2C_Slave_Receive+0x190>
    1d74:	8240      	ld.b      	r2, (r2, 0x0)
    1d76:	7488      	zextb      	r2, r2
    1d78:	a142      	st.b      	r2, (r1, 0x2)
		I2C0->IMSCR |= INT_TYPE;
    1d7a:	9357      	ld.w      	r2, (r3, 0x5c)
    1d7c:	ec420010 	ori      	r2, r2, 16
    1d80:	b357      	st.w      	r2, (r3, 0x5c)
			I2C_ConfigInterrupt_CMD(ENABLE,I2C_TX_EMPTY);
			if(WrIndex<BUFSIZE)
    1d82:	8142      	ld.b      	r2, (r1, 0x2)
    1d84:	eb4200ff 	cmpnei      	r2, 255
    1d88:	0c0b      	bf      	0x1d9e	// 1d9e <I2C_Slave_Receive+0x8e>
			{
				I2C0->DATA_CMD= (I2C0->DATA_CMD&0XFFFFFF00) |I2CWrBuffer[WrIndex];
    1d8a:	9344      	ld.w      	r2, (r3, 0x10)
    1d8c:	8122      	ld.b      	r1, (r1, 0x2)
    1d8e:	1207      	lrw      	r0, 0x200000d1	// 1ea8 <I2C_Slave_Receive+0x198>
    1d90:	6040      	addu      	r1, r0
    1d92:	8120      	ld.b      	r1, (r1, 0x0)
    1d94:	3000      	movi      	r0, 0
    1d96:	28ff      	subi      	r0, 256
    1d98:	6880      	and      	r2, r0
    1d9a:	6c84      	or      	r2, r1
    1d9c:	b344      	st.w      	r2, (r3, 0x10)
			}	
		}	
		I2C0->ICR = I2C_RD_REQ;
    1d9e:	3220      	movi      	r2, 32
		R_IIC_ERROR_CONT=0;
    1da0:	3100      	movi      	r1, 0
		I2C0->ICR = I2C_RD_REQ;
    1da2:	b359      	st.w      	r2, (r3, 0x64)
		R_IIC_ERROR_CONT=0;
    1da4:	1240      	lrw      	r2, 0x200000cc	// 1ea4 <I2C_Slave_Receive+0x194>
    1da6:	b220      	st.w      	r1, (r2, 0x0)
	} 
                         
	if((I2C0->MISR&I2C_TX_EMPTY)==I2C_TX_EMPTY)				//IIC发送为空
    1da8:	9356      	ld.w      	r2, (r3, 0x58)
    1daa:	e4422010 	andi      	r2, r2, 16
    1dae:	3a40      	cmpnei      	r2, 0
    1db0:	0c1b      	bf      	0x1de6	// 1de6 <I2C_Slave_Receive+0xd6>
	{
		if(RdIndex==2)
    1db2:	115a      	lrw      	r2, 0x200000b8	// 1e98 <I2C_Slave_Receive+0x188>
    1db4:	8221      	ld.b      	r1, (r2, 0x1)
    1db6:	3942      	cmpnei      	r1, 2
    1db8:	0842      	bt      	0x1e3c	// 1e3c <I2C_Slave_Receive+0x12c>
		{
			if(WrIndex+1<BUFSIZE)
    1dba:	8222      	ld.b      	r1, (r2, 0x2)
    1dbc:	7444      	zextb      	r1, r1
    1dbe:	eb2100fd 	cmplti      	r1, 254
    1dc2:	0c0b      	bf      	0x1dd8	// 1dd8 <I2C_Slave_Receive+0xc8>
			{
				I2C0->DATA_CMD= (I2C0->DATA_CMD&0XFFFFFF00) |I2CWrBuffer[WrIndex+1];
    1dc4:	9324      	ld.w      	r1, (r3, 0x10)
    1dc6:	11ba      	lrw      	r5, 0x200000d2	// 1eac <I2C_Slave_Receive+0x19c>
    1dc8:	8202      	ld.b      	r0, (r2, 0x2)
    1dca:	6014      	addu      	r0, r5
    1dcc:	8000      	ld.b      	r0, (r0, 0x0)
    1dce:	3500      	movi      	r5, 0
    1dd0:	2dff      	subi      	r5, 256
    1dd2:	6854      	and      	r1, r5
    1dd4:	6c40      	or      	r1, r0
    1dd6:	b324      	st.w      	r1, (r3, 0x10)
			}
			WrIndex++;
    1dd8:	8262      	ld.b      	r3, (r2, 0x2)
    1dda:	2300      	addi      	r3, 1
    1ddc:	74cc      	zextb      	r3, r3
    1dde:	a262      	st.b      	r3, (r2, 0x2)
			else
			{
				R_IIC_ERROR_CONT++;
			}
		}
		I2C0->CR = I2C_TX_EMPTY;
    1de0:	9460      	ld.w      	r3, (r4, 0x0)
    1de2:	3210      	movi      	r2, 16
    1de4:	b340      	st.w      	r2, (r3, 0x0)
	}	
							
	if((I2C0->MISR&I2C_STOP_DET)==I2C_STOP_DET)
    1de6:	9440      	ld.w      	r2, (r4, 0x0)
    1de8:	9276      	ld.w      	r3, (r2, 0x58)
    1dea:	e4632200 	andi      	r3, r3, 512
    1dee:	3b40      	cmpnei      	r3, 0
    1df0:	0c11      	bf      	0x1e12	// 1e12 <I2C_Slave_Receive+0x102>
	{
		I2C0->ICR =I2C_STOP_DET;
    1df2:	3380      	movi      	r3, 128
    1df4:	4362      	lsli      	r3, r3, 2
    1df6:	b279      	st.w      	r3, (r2, 0x64)
		if(RdIndex!=0)
    1df8:	1168      	lrw      	r3, 0x200000b8	// 1e98 <I2C_Slave_Receive+0x188>
    1dfa:	8341      	ld.b      	r2, (r3, 0x1)
    1dfc:	3a40      	cmpnei      	r2, 0
    1dfe:	0c07      	bf      	0x1e0c	// 1e0c <I2C_Slave_Receive+0xfc>
		{
			RdIndex=0;
    1e00:	3200      	movi      	r2, 0
			I2C_ConfigInterrupt_CMD(DISABLE,I2C_TX_EMPTY);
    1e02:	3110      	movi      	r1, 16
    1e04:	3000      	movi      	r0, 0
			RdIndex=0;
    1e06:	a341      	st.b      	r2, (r3, 0x1)
			I2C_ConfigInterrupt_CMD(DISABLE,I2C_TX_EMPTY);
    1e08:	e3ffff40 	bsr      	0x1c88	// 1c88 <I2C_ConfigInterrupt_CMD>
		I2C0->DATA_CMD= (I2C0->DATA_CMD&0XFFFFFF00);
		I2C_SLAVE_CONFIG(); 
		RdIndex=0;	
		I2C_ConfigInterrupt_CMD(ENABLE,I2C_TX_EMPTY);				
		I2C0->ICR = I2C_SCL_SLOW|I2C_TX_ABRT;
		R_IIC_ERROR_CONT=0;
    1e0c:	1166      	lrw      	r3, 0x200000cc	// 1ea4 <I2C_Slave_Receive+0x194>
    1e0e:	3200      	movi      	r2, 0
    1e10:	b340      	st.w      	r2, (r3, 0x0)
	
}
}
    1e12:	1492      	pop      	r4-r5, r15
		else if(RdIndex==1)
    1e14:	8241      	ld.b      	r2, (r2, 0x1)
    1e16:	3a41      	cmpnei      	r2, 1
    1e18:	0b9d      	bt      	0x1d52	// 1d52 <I2C_Slave_Receive+0x42>
			__asm volatile("nop"
    1e1a:	6c03      	mov      	r0, r0
			if(I2C_Data_Adress<BUFSIZE)
    1e1c:	1140      	lrw      	r2, 0x200001d0	// 1e9c <I2C_Slave_Receive+0x18c>
    1e1e:	8220      	ld.b      	r1, (r2, 0x0)
    1e20:	eb4100ff 	cmpnei      	r1, 255
    1e24:	0c07      	bf      	0x1e32	// 1e32 <I2C_Slave_Receive+0x122>
				I2CRdBuffer[I2C_Data_Adress]= I2C0->DATA_CMD&0XFF;
    1e26:	8220      	ld.b      	r1, (r2, 0x0)
    1e28:	9304      	ld.w      	r0, (r3, 0x10)
    1e2a:	7400      	zextb      	r0, r0
    1e2c:	11a1      	lrw      	r5, 0x200001d1	// 1eb0 <I2C_Slave_Receive+0x1a0>
    1e2e:	6054      	addu      	r1, r5
    1e30:	a100      	st.b      	r0, (r1, 0x0)
			I2C_Data_Adress++;
    1e32:	8220      	ld.b      	r1, (r2, 0x0)
    1e34:	2100      	addi      	r1, 1
    1e36:	7444      	zextb      	r1, r1
    1e38:	a220      	st.b      	r1, (r2, 0x0)
    1e3a:	078c      	br      	0x1d52	// 1d52 <I2C_Slave_Receive+0x42>
			if(R_IIC_ERROR_CONT>10000)
    1e3c:	10ba      	lrw      	r5, 0x200000cc	// 1ea4 <I2C_Slave_Receive+0x194>
    1e3e:	9560      	ld.w      	r3, (r5, 0x0)
    1e40:	eb032710 	cmphsi      	r3, 10001
    1e44:	0c0e      	bf      	0x1e60	// 1e60 <I2C_Slave_Receive+0x150>
				I2C_Disable();
    1e46:	e3ffff47 	bsr      	0x1cd4	// 1cd4 <I2C_Disable>
				I2C0->DATA_CMD= (I2C0->DATA_CMD&0XFFFFFF00);
    1e4a:	9440      	ld.w      	r2, (r4, 0x0)
    1e4c:	3100      	movi      	r1, 0
    1e4e:	9264      	ld.w      	r3, (r2, 0x10)
    1e50:	29ff      	subi      	r1, 256
    1e52:	68c4      	and      	r3, r1
    1e54:	b264      	st.w      	r3, (r2, 0x10)
				I2C_SLAVE_CONFIG();
    1e56:	e00001bc 	bsr      	0x21ce	// 21ce <I2C_SLAVE_CONFIG>
				R_IIC_ERROR_CONT=0;
    1e5a:	3300      	movi      	r3, 0
				R_IIC_ERROR_CONT++;
    1e5c:	b560      	st.w      	r3, (r5, 0x0)
    1e5e:	07c1      	br      	0x1de0	// 1de0 <I2C_Slave_Receive+0xd0>
    1e60:	9560      	ld.w      	r3, (r5, 0x0)
    1e62:	2300      	addi      	r3, 1
    1e64:	07fc      	br      	0x1e5c	// 1e5c <I2C_Slave_Receive+0x14c>
		I2C_Disable();
    1e66:	e3ffff37 	bsr      	0x1cd4	// 1cd4 <I2C_Disable>
		I2C0->DATA_CMD= (I2C0->DATA_CMD&0XFFFFFF00);
    1e6a:	9440      	ld.w      	r2, (r4, 0x0)
    1e6c:	3100      	movi      	r1, 0
    1e6e:	9264      	ld.w      	r3, (r2, 0x10)
    1e70:	29ff      	subi      	r1, 256
    1e72:	68c4      	and      	r3, r1
    1e74:	b264      	st.w      	r3, (r2, 0x10)
		I2C_SLAVE_CONFIG(); 
    1e76:	e00001ac 	bsr      	0x21ce	// 21ce <I2C_SLAVE_CONFIG>
		RdIndex=0;	
    1e7a:	1068      	lrw      	r3, 0x200000b8	// 1e98 <I2C_Slave_Receive+0x188>
    1e7c:	3200      	movi      	r2, 0
    1e7e:	a341      	st.b      	r2, (r3, 0x1)
		I2C0->IMSCR |= INT_TYPE;
    1e80:	9460      	ld.w      	r3, (r4, 0x0)
    1e82:	9357      	ld.w      	r2, (r3, 0x5c)
    1e84:	ec420010 	ori      	r2, r2, 16
    1e88:	b357      	st.w      	r2, (r3, 0x5c)
		I2C0->ICR = I2C_SCL_SLOW|I2C_TX_ABRT;
    1e8a:	ea024040 	movi      	r2, 16448
    1e8e:	b359      	st.w      	r2, (r3, 0x64)
    1e90:	07be      	br      	0x1e0c	// 1e0c <I2C_Slave_Receive+0xfc>
    1e92:	0000      	bkpt
    1e94:	20000060 	.long	0x20000060
    1e98:	200000b8 	.long	0x200000b8
    1e9c:	200001d0 	.long	0x200001d0
    1ea0:	200000d0 	.long	0x200000d0
    1ea4:	200000cc 	.long	0x200000cc
    1ea8:	200000d1 	.long	0x200000d1
    1eac:	200000d2 	.long	0x200000d2
    1eb0:	200001d1 	.long	0x200001d1

Disassembly of section .text.SYSCON_General_CMD.part.0:

00001eb4 <SYSCON_General_CMD.part.0>:
//EntryParameter:NewState:,ENDIS_X
//NewState:ENABLE,DISABLE
//ENDIS_X:ENDIS_ISOSC,ENDIS_IMOSC,ENDIS_EMOSC,ENDIS_HFOSC
//ReturnValue:NONE
/*************************************************************/  
void SYSCON_General_CMD(FunctionalStatus NewState, SYSCON_General_CMD_TypeDef ENDIS_X )
    1eb4:	14d0      	push      	r15
{
	if (NewState != DISABLE)
	{
		if(ENDIS_X==ENDIS_EMOSC) 
    1eb6:	3848      	cmpnei      	r0, 8
    1eb8:	081f      	bt      	0x1ef6	// 1ef6 <SYSCON_General_CMD.part.0+0x42>
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFFF00FFF)|0x00044000;					//enable EMOSC PIN
    1eba:	1164      	lrw      	r3, 0x20000088	// 1f48 <SYSCON_General_CMD.part.0+0x94>
    1ebc:	1124      	lrw      	r1, 0xfff00fff	// 1f4c <SYSCON_General_CMD.part.0+0x98>
    1ebe:	9340      	ld.w      	r2, (r3, 0x0)
    1ec0:	9260      	ld.w      	r3, (r2, 0x0)
    1ec2:	68c4      	and      	r3, r1
    1ec4:	3bae      	bseti      	r3, 14
    1ec6:	3bb2      	bseti      	r3, 18
		if(ENDIS_X==ENDIS_ESOSC)
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFFFFF00F)|0x00000440;					//enable ESOSC PIN
    1ec8:	b260      	st.w      	r3, (r2, 0x0)
		SYSCON->GCER|=ENDIS_X;													//enable SYSCON General Control
    1eca:	1162      	lrw      	r3, 0x200000a0	// 1f50 <SYSCON_General_CMD.part.0+0x9c>
    1ecc:	9360      	ld.w      	r3, (r3, 0x0)
    1ece:	9341      	ld.w      	r2, (r3, 0x4)
    1ed0:	6c80      	or      	r2, r0
    1ed2:	b341      	st.w      	r2, (r3, 0x4)
		while(!(SYSCON->GCSR&ENDIS_X));											//check  Enable?	
    1ed4:	9343      	ld.w      	r2, (r3, 0xc)
    1ed6:	6880      	and      	r2, r0
    1ed8:	3a40      	cmpnei      	r2, 0
    1eda:	0ffd      	bf      	0x1ed4	// 1ed4 <SYSCON_General_CMD.part.0+0x20>
		switch(ENDIS_X)
    1edc:	2800      	subi      	r0, 1
    1ede:	380f      	cmphsi      	r0, 16
    1ee0:	081a      	bt      	0x1f14	// 1f14 <SYSCON_General_CMD.part.0+0x60>
    1ee2:	e3fffc0f 	bsr      	0x1700	// 1700 <___gnu_csky_case_uqi>
    1ee6:	1224      	.short	0x1224
    1ee8:	17171817 	.long	0x17171817
    1eec:	17171e17 	.long	0x17171e17
    1ef0:	17171717 	.long	0x17171717
    1ef4:	2a17      	.short	0x2a17
		if(ENDIS_X==ENDIS_ESOSC)
    1ef6:	3844      	cmpnei      	r0, 4
    1ef8:	0be9      	bt      	0x1eca	// 1eca <SYSCON_General_CMD.part.0+0x16>
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFFFFF00F)|0x00000440;					//enable ESOSC PIN
    1efa:	1074      	lrw      	r3, 0x20000088	// 1f48 <SYSCON_General_CMD.part.0+0x94>
    1efc:	1036      	lrw      	r1, 0xfffff00f	// 1f54 <SYSCON_General_CMD.part.0+0xa0>
    1efe:	9340      	ld.w      	r2, (r3, 0x0)
    1f00:	9260      	ld.w      	r3, (r2, 0x0)
    1f02:	68c4      	and      	r3, r1
    1f04:	ec630440 	ori      	r3, r3, 1088
    1f08:	07e0      	br      	0x1ec8	// 1ec8 <SYSCON_General_CMD.part.0+0x14>
		{
			case ENDIS_IMOSC:
				while (!(SYSCON->CKST & ENDIS_IMOSC)); 	
    1f0a:	3102      	movi      	r1, 2
    1f0c:	9344      	ld.w      	r2, (r3, 0x10)
    1f0e:	6884      	and      	r2, r1
    1f10:	3a40      	cmpnei      	r2, 0
    1f12:	0ffd      	bf      	0x1f0c	// 1f0c <SYSCON_General_CMD.part.0+0x58>
	{
		SYSCON->GCDR|=ENDIS_X;													//disable SYSCON General Control
		while(SYSCON->GCSR&ENDIS_X);											//check Disable?
		SYSCON->ICR|=ENDIS_X;													//Clear ENDIS_X stable bit
	}
}
    1f14:	1490      	pop      	r15
				while (!(SYSCON->CKST & ENDIS_ESOSC)); 
    1f16:	3104      	movi      	r1, 4
    1f18:	9344      	ld.w      	r2, (r3, 0x10)
    1f1a:	6884      	and      	r2, r1
    1f1c:	3a40      	cmpnei      	r2, 0
    1f1e:	0ffd      	bf      	0x1f18	// 1f18 <SYSCON_General_CMD.part.0+0x64>
    1f20:	07fa      	br      	0x1f14	// 1f14 <SYSCON_General_CMD.part.0+0x60>
				while (!(SYSCON->CKST & ENDIS_EMOSC)); 
    1f22:	3108      	movi      	r1, 8
    1f24:	9344      	ld.w      	r2, (r3, 0x10)
    1f26:	6884      	and      	r2, r1
    1f28:	3a40      	cmpnei      	r2, 0
    1f2a:	0ffd      	bf      	0x1f24	// 1f24 <SYSCON_General_CMD.part.0+0x70>
    1f2c:	07f4      	br      	0x1f14	// 1f14 <SYSCON_General_CMD.part.0+0x60>
				while (!(SYSCON->CKST & ENDIS_ISOSC)); 
    1f2e:	3101      	movi      	r1, 1
    1f30:	9344      	ld.w      	r2, (r3, 0x10)
    1f32:	6884      	and      	r2, r1
    1f34:	3a40      	cmpnei      	r2, 0
    1f36:	0ffd      	bf      	0x1f30	// 1f30 <SYSCON_General_CMD.part.0+0x7c>
    1f38:	07ee      	br      	0x1f14	// 1f14 <SYSCON_General_CMD.part.0+0x60>
				while (!(SYSCON->CKST & ENDIS_HFOSC)); 
    1f3a:	3110      	movi      	r1, 16
    1f3c:	9344      	ld.w      	r2, (r3, 0x10)
    1f3e:	6884      	and      	r2, r1
    1f40:	3a40      	cmpnei      	r2, 0
    1f42:	0ffd      	bf      	0x1f3c	// 1f3c <SYSCON_General_CMD.part.0+0x88>
    1f44:	07e8      	br      	0x1f14	// 1f14 <SYSCON_General_CMD.part.0+0x60>
    1f46:	0000      	bkpt
    1f48:	20000088 	.long	0x20000088
    1f4c:	fff00fff 	.long	0xfff00fff
    1f50:	200000a0 	.long	0x200000a0
    1f54:	fffff00f 	.long	0xfffff00f

Disassembly of section .text.SYSCON_RST_VALUE:

00001f58 <SYSCON_RST_VALUE>:
	SYSCON->RAMCHK=SYSCON_RAMCHK_RST;
    1f58:	1076      	lrw      	r3, 0x200000a0	// 1fb0 <SYSCON_RST_VALUE+0x58>
    1f5a:	ea02ffff 	movi      	r2, 65535
    1f5e:	9360      	ld.w      	r3, (r3, 0x0)
    1f60:	b345      	st.w      	r2, (r3, 0x14)
	SYSCON->EFLCHK=SYSCON_EFLCHK_RST;
    1f62:	c6e05022 	bmaski      	r2, 24
    1f66:	b346      	st.w      	r2, (r3, 0x18)
	SYSCON->SCLKCR=SYSCON_SCLKCR_RST;
    1f68:	ea22d22d 	movih      	r2, 53805
    1f6c:	b347      	st.w      	r2, (r3, 0x1c)
	SYSCON->OSTR=SYSCON_OSTR_RST;
    1f6e:	1052      	lrw      	r2, 0x70ff3bff	// 1fb4 <SYSCON_RST_VALUE+0x5c>
    1f70:	b350      	st.w      	r2, (r3, 0x40)
	SYSCON->LVDCR=SYSCON_LVDCR_RST;
    1f72:	320a      	movi      	r2, 10
    1f74:	b353      	st.w      	r2, (r3, 0x4c)
	SYSCON->EXIRT=SYSCON_EXIRT_RST;
    1f76:	3200      	movi      	r2, 0
    1f78:	dc432025 	st.w      	r2, (r3, 0x94)
	SYSCON->EXIFT=SYSCON_EXIFT_RST;
    1f7c:	dc432026 	st.w      	r2, (r3, 0x98)
	SYSCON->IWDCR=SYSCON_IWDCR_RST;
    1f80:	ea02070c 	movi      	r2, 1804
    1f84:	dc43202d 	st.w      	r2, (r3, 0xb4)
	SYSCON->IWDCNT=SYSCON_IWDCNT_RST;
    1f88:	c6205022 	bmaski      	r2, 18
    1f8c:	dc43202e 	st.w      	r2, (r3, 0xb8)
	SYSCON->EVTRG=SYSCON_EVTRG_RST;
    1f90:	3200      	movi      	r2, 0
    1f92:	dc43203d 	st.w      	r2, (r3, 0xf4)
	SYSCON->EVPS=SYSCON_EVPS_RST;
    1f96:	dc43203e 	st.w      	r2, (r3, 0xf8)
	SYSCON->EVSWF=SYSCON_EVSWF_RST;
    1f9a:	dc43203f 	st.w      	r2, (r3, 0xfc)
	SYSCON->UREG0=SYSCON_UREG0_RST;
    1f9e:	dc432040 	st.w      	r2, (r3, 0x100)
	SYSCON->UREG1=SYSCON_UREG1_RST;
    1fa2:	dc432041 	st.w      	r2, (r3, 0x104)
	SYSCON->UREG2=SYSCON_UREG2_RST;
    1fa6:	dc432042 	st.w      	r2, (r3, 0x108)
	SYSCON->UREG3=SYSCON_UREG3_RST;
    1faa:	dc432043 	st.w      	r2, (r3, 0x10c)
}
    1fae:	783c      	jmp      	r15
    1fb0:	200000a0 	.long	0x200000a0
    1fb4:	70ff3bff 	.long	0x70ff3bff

Disassembly of section .text.SYSCON_General_CMD:

00001fb8 <SYSCON_General_CMD>:
{
    1fb8:	14d0      	push      	r15
	if (NewState != DISABLE)
    1fba:	3840      	cmpnei      	r0, 0
    1fbc:	0c05      	bf      	0x1fc6	// 1fc6 <SYSCON_General_CMD+0xe>
    1fbe:	6c07      	mov      	r0, r1
    1fc0:	e3ffff7a 	bsr      	0x1eb4	// 1eb4 <SYSCON_General_CMD.part.0>
}
    1fc4:	1490      	pop      	r15
		SYSCON->GCDR|=ENDIS_X;													//disable SYSCON General Control
    1fc6:	1068      	lrw      	r3, 0x200000a0	// 1fe4 <SYSCON_General_CMD+0x2c>
    1fc8:	9360      	ld.w      	r3, (r3, 0x0)
    1fca:	9342      	ld.w      	r2, (r3, 0x8)
    1fcc:	6c84      	or      	r2, r1
    1fce:	b342      	st.w      	r2, (r3, 0x8)
		while(SYSCON->GCSR&ENDIS_X);											//check Disable?
    1fd0:	9343      	ld.w      	r2, (r3, 0xc)
    1fd2:	6884      	and      	r2, r1
    1fd4:	3a40      	cmpnei      	r2, 0
    1fd6:	0bfd      	bt      	0x1fd0	// 1fd0 <SYSCON_General_CMD+0x18>
		SYSCON->ICR|=ENDIS_X;													//Clear ENDIS_X stable bit
    1fd8:	d8032021 	ld.w      	r0, (r3, 0x84)
    1fdc:	6c40      	or      	r1, r0
    1fde:	dc232021 	st.w      	r1, (r3, 0x84)
}
    1fe2:	07f1      	br      	0x1fc4	// 1fc4 <SYSCON_General_CMD+0xc>
    1fe4:	200000a0 	.long	0x200000a0

Disassembly of section .text.SystemCLK_HCLKDIV_PCLKDIV_Config:

00001fe8 <SystemCLK_HCLKDIV_PCLKDIV_Config>:
//SystemClk_data_x:EMOSC_24M,EMOSC_16M,EMOSC_12M,EMOSC_8M,EMOSC_4M,EMOSC_36K,
//ISOSC,IMOSC,HFOSC_48M,HFOSC_24M,HFOSC_12M,HFOSC_6M
//ReturnValue:NONE
/*************************************************************/ 
void SystemCLK_HCLKDIV_PCLKDIV_Config(SystemCLK_TypeDef SYSCLK_X , SystemCLK_Div_TypeDef HCLK_DIV_X , PCLK_Div_TypeDef PCLK_DIV_X , SystemClk_data_TypeDef SystemClk_data_x )
{
    1fe8:	14c2      	push      	r4-r5
	if(SystemClk_data_x==HFOSC_48M)
    1fea:	3b48      	cmpnei      	r3, 8
    1fec:	082a      	bt      	0x2040	// 2040 <SystemCLK_HCLKDIV_PCLKDIV_Config+0x58>
	{
		IFC->CEDR=0X01;						//CLKEN
    1fee:	109e      	lrw      	r4, 0x200000a4	// 2064 <SystemCLK_HCLKDIV_PCLKDIV_Config+0x7c>
    1ff0:	3501      	movi      	r5, 1
    1ff2:	9480      	ld.w      	r4, (r4, 0x0)
    1ff4:	b4a1      	st.w      	r5, (r4, 0x4)
		IFC->MR=0X02|(0X01<<16);			//High speed mode
    1ff6:	10bd      	lrw      	r5, 0x10002	// 2068 <SystemCLK_HCLKDIV_PCLKDIV_Config+0x80>
    1ff8:	b4a5      	st.w      	r5, (r4, 0x14)
	if((SystemClk_data_x==EMOSC_24M)||(SystemClk_data_x==HFOSC_24M))
	{
		IFC->CEDR=0X01;						//CLKEN
		IFC->MR=0X01|(0X01<<16);			//Medium speed mode
	}
	if((SystemClk_data_x==EMOSC_12M)||(SystemClk_data_x==HFOSC_12M)||(SystemClk_data_x==EMOSC_16M))
    1ffa:	5b83      	subi      	r4, r3, 1
    1ffc:	3c01      	cmphsi      	r4, 2
    1ffe:	0c2d      	bf      	0x2058	// 2058 <SystemCLK_HCLKDIV_PCLKDIV_Config+0x70>
	{
		IFC->CEDR=0X01;						//CLKEN
		IFC->MR=0X01|(0X00<<16);			//Low speed mode
	}
	if((SystemClk_data_x==EMOSC_8M)||(SystemClk_data_x==EMOSC_4M)||(SystemClk_data_x==EMOSC_36K)||(SystemClk_data_x==ESOSC_32K)
    2000:	5b8b      	subi      	r4, r3, 3
    2002:	3c04      	cmphsi      	r4, 5
    2004:	0c04      	bf      	0x200c	// 200c <SystemCLK_HCLKDIV_PCLKDIV_Config+0x24>
		||(SystemClk_data_x==IMOSC)||(SystemClk_data_x==ISOSC)||(SystemClk_data_x==HFOSC_6M))
    2006:	2b0a      	subi      	r3, 11
    2008:	3b01      	cmphsi      	r3, 2
    200a:	0807      	bt      	0x2018	// 2018 <SystemCLK_HCLKDIV_PCLKDIV_Config+0x30>
	{
		IFC->CEDR=0X01;						//CLKEN
    200c:	1076      	lrw      	r3, 0x200000a4	// 2064 <SystemCLK_HCLKDIV_PCLKDIV_Config+0x7c>
    200e:	3401      	movi      	r4, 1
    2010:	9360      	ld.w      	r3, (r3, 0x0)
    2012:	b381      	st.w      	r4, (r3, 0x4)
		IFC->MR=0X00|(0X00<<16);			//Low speed mode
    2014:	3400      	movi      	r4, 0
    2016:	b385      	st.w      	r4, (r3, 0x14)
	}
	SYSCON->SCLKCR=SYSCLK_KEY | HCLK_DIV_X| SYSCLK_X;
    2018:	1075      	lrw      	r3, 0x200000a0	// 206c <SystemCLK_HCLKDIV_PCLKDIV_Config+0x84>
    201a:	ea24d22d 	movih      	r4, 53805
    201e:	9360      	ld.w      	r3, (r3, 0x0)
    2020:	6c10      	or      	r0, r4
    2022:	6c40      	or      	r1, r0
    2024:	b327      	st.w      	r1, (r3, 0x1c)
	while (!(SYSCON->CKST & (1<<8))); 											// waiting for sysclk stable
    2026:	9324      	ld.w      	r1, (r3, 0x10)
    2028:	e4212100 	andi      	r1, r1, 256
    202c:	3940      	cmpnei      	r1, 0
    202e:	0ffc      	bf      	0x2026	// 2026 <SystemCLK_HCLKDIV_PCLKDIV_Config+0x3e>
	SYSCON->PCLKCR=PCLK_KEY|PCLK_DIV_X;											//PCLK DIV 1 2 4 6 8 16		
    2030:	ea21c33c 	movih      	r1, 49980
    2034:	6c48      	or      	r1, r2
    2036:	b328      	st.w      	r1, (r3, 0x20)
	while(SYSCON->PCLKCR!=PCLK_DIV_X);											//Wait PCLK DIV
    2038:	9328      	ld.w      	r1, (r3, 0x20)
    203a:	644a      	cmpne      	r2, r1
    203c:	0bfe      	bt      	0x2038	// 2038 <SystemCLK_HCLKDIV_PCLKDIV_Config+0x50>
}
    203e:	1482      	pop      	r4-r5
	if((SystemClk_data_x==EMOSC_24M)||(SystemClk_data_x==HFOSC_24M))
    2040:	3b40      	cmpnei      	r3, 0
    2042:	0c03      	bf      	0x2048	// 2048 <SystemCLK_HCLKDIV_PCLKDIV_Config+0x60>
    2044:	3b49      	cmpnei      	r3, 9
    2046:	0807      	bt      	0x2054	// 2054 <SystemCLK_HCLKDIV_PCLKDIV_Config+0x6c>
		IFC->CEDR=0X01;						//CLKEN
    2048:	1087      	lrw      	r4, 0x200000a4	// 2064 <SystemCLK_HCLKDIV_PCLKDIV_Config+0x7c>
    204a:	3501      	movi      	r5, 1
    204c:	9480      	ld.w      	r4, (r4, 0x0)
    204e:	b4a1      	st.w      	r5, (r4, 0x4)
		IFC->MR=0X01|(0X01<<16);			//Medium speed mode
    2050:	10a8      	lrw      	r5, 0x10001	// 2070 <SystemCLK_HCLKDIV_PCLKDIV_Config+0x88>
    2052:	b4a5      	st.w      	r5, (r4, 0x14)
	if((SystemClk_data_x==EMOSC_12M)||(SystemClk_data_x==HFOSC_12M)||(SystemClk_data_x==EMOSC_16M))
    2054:	3b4a      	cmpnei      	r3, 10
    2056:	0bd2      	bt      	0x1ffa	// 1ffa <SystemCLK_HCLKDIV_PCLKDIV_Config+0x12>
		IFC->CEDR=0X01;						//CLKEN
    2058:	1083      	lrw      	r4, 0x200000a4	// 2064 <SystemCLK_HCLKDIV_PCLKDIV_Config+0x7c>
    205a:	3501      	movi      	r5, 1
    205c:	9480      	ld.w      	r4, (r4, 0x0)
    205e:	b4a1      	st.w      	r5, (r4, 0x4)
		IFC->MR=0X01|(0X00<<16);			//Low speed mode
    2060:	b4a5      	st.w      	r5, (r4, 0x14)
    2062:	07cf      	br      	0x2000	// 2000 <SystemCLK_HCLKDIV_PCLKDIV_Config+0x18>
    2064:	200000a4 	.long	0x200000a4
    2068:	00010002 	.long	0x00010002
    206c:	200000a0 	.long	0x200000a0
    2070:	00010001 	.long	0x00010001

Disassembly of section .text.SYSCON_HFOSC_SELECTE:

00002074 <SYSCON_HFOSC_SELECTE>:
//EntryParameter:HFOSC_SELECTE_X
//HFOSC_SELECTE_X:HFOSC_SELECTE_48M,HFOSC_SELECTE_24M;HFOSC_SELECTE_12M;HFOSC_SELECTE_6M
//ReturnValue:NONE
/*************************************************************/  
void SYSCON_HFOSC_SELECTE(HFOSC_SELECTE_TypeDef HFOSC_SELECTE_X)
{		
    2074:	14d1      	push      	r4, r15
    2076:	6d03      	mov      	r4, r0
	SYSCON_General_CMD(DISABLE,ENDIS_HFOSC);					//disable HFOSC
    2078:	3110      	movi      	r1, 16
    207a:	3000      	movi      	r0, 0
    207c:	e3ffff9e 	bsr      	0x1fb8	// 1fb8 <SYSCON_General_CMD>
	SYSCON->OPT1 = (SYSCON->OPT1 & 0XFFFFFFCF)|HFOSC_SELECTE_X;
    2080:	1066      	lrw      	r3, 0x200000a0	// 2098 <SYSCON_HFOSC_SELECTE+0x24>
    2082:	9360      	ld.w      	r3, (r3, 0x0)
    2084:	9319      	ld.w      	r0, (r3, 0x64)
    2086:	3884      	bclri      	r0, 4
    2088:	3885      	bclri      	r0, 5
    208a:	6c10      	or      	r0, r4
    208c:	b319      	st.w      	r0, (r3, 0x64)
    208e:	3010      	movi      	r0, 16
    2090:	e3ffff12 	bsr      	0x1eb4	// 1eb4 <SYSCON_General_CMD.part.0>
	SYSCON_General_CMD(ENABLE,ENDIS_HFOSC);						//enable HFOSC
}
    2094:	1491      	pop      	r4, r15
    2096:	0000      	bkpt
    2098:	200000a0 	.long	0x200000a0

Disassembly of section .text.SYSCON_WDT_CMD:

0000209c <SYSCON_WDT_CMD>:
//EntryParameter:,NewState
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/
void SYSCON_WDT_CMD(FunctionalStatus NewState)
{
    209c:	106e      	lrw      	r3, 0x200000a0	// 20d4 <SYSCON_WDT_CMD+0x38>
	if(NewState != DISABLE)
    209e:	3840      	cmpnei      	r0, 0
	{
		SYSCON->IWDEDR=IWDTEDR_KEY|Enable_IWDT;
    20a0:	9320      	ld.w      	r1, (r3, 0x0)
	if(NewState != DISABLE)
    20a2:	0c0d      	bf      	0x20bc	// 20bc <SYSCON_WDT_CMD+0x20>
		SYSCON->IWDEDR=IWDTEDR_KEY|Enable_IWDT;
    20a4:	ea237887 	movih      	r3, 30855
		while(!(SYSCON->IWDCR&Check_IWDT_BUSY));
    20a8:	3280      	movi      	r2, 128
		SYSCON->IWDEDR=IWDTEDR_KEY|Enable_IWDT;
    20aa:	dc61202f 	st.w      	r3, (r1, 0xbc)
		while(!(SYSCON->IWDCR&Check_IWDT_BUSY));
    20ae:	4245      	lsli      	r2, r2, 5
    20b0:	d861202d 	ld.w      	r3, (r1, 0xb4)
    20b4:	68c8      	and      	r3, r2
    20b6:	3b40      	cmpnei      	r3, 0
    20b8:	0ffc      	bf      	0x20b0	// 20b0 <SYSCON_WDT_CMD+0x14>
	else
	{
		SYSCON->IWDEDR=IWDTEDR_KEY|Disable_IWDT;
		while(SYSCON->IWDCR&Check_IWDT_BUSY);
	}
}
    20ba:	783c      	jmp      	r15
		SYSCON->IWDEDR=IWDTEDR_KEY|Disable_IWDT;
    20bc:	1067      	lrw      	r3, 0x788755aa	// 20d8 <SYSCON_WDT_CMD+0x3c>
		while(SYSCON->IWDCR&Check_IWDT_BUSY);
    20be:	3280      	movi      	r2, 128
		SYSCON->IWDEDR=IWDTEDR_KEY|Disable_IWDT;
    20c0:	dc61202f 	st.w      	r3, (r1, 0xbc)
		while(SYSCON->IWDCR&Check_IWDT_BUSY);
    20c4:	4245      	lsli      	r2, r2, 5
    20c6:	d861202d 	ld.w      	r3, (r1, 0xb4)
    20ca:	68c8      	and      	r3, r2
    20cc:	3b40      	cmpnei      	r3, 0
    20ce:	0bfc      	bt      	0x20c6	// 20c6 <SYSCON_WDT_CMD+0x2a>
    20d0:	07f5      	br      	0x20ba	// 20ba <SYSCON_WDT_CMD+0x1e>
    20d2:	0000      	bkpt
    20d4:	200000a0 	.long	0x200000a0
    20d8:	788755aa 	.long	0x788755aa

Disassembly of section .text.SYSCON_IWDCNT_Reload:

000020dc <SYSCON_IWDCNT_Reload>:
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void SYSCON_IWDCNT_Reload(void)
{
	SYSCON->IWDCNT=CLR_IWDT;
    20dc:	1064      	lrw      	r3, 0x200000a0	// 20ec <SYSCON_IWDCNT_Reload+0x10>
    20de:	9340      	ld.w      	r2, (r3, 0x0)
    20e0:	33b4      	movi      	r3, 180
    20e2:	4377      	lsli      	r3, r3, 23
    20e4:	dc62202e 	st.w      	r3, (r2, 0xb8)
}
    20e8:	783c      	jmp      	r15
    20ea:	0000      	bkpt
    20ec:	200000a0 	.long	0x200000a0

Disassembly of section .text.SYSCON_IWDCNT_Config:

000020f0 <SYSCON_IWDCNT_Config>:
//IWDT_INTW_DIV_X:IWDT_INTW_DIV_1/2/3/4/4/5/6
//ReturnValue: NONE
/*************************************************************/
void SYSCON_IWDCNT_Config(IWDT_TIME_TypeDef IWDT_TIME_X , IWDT_TIMEDIV_TypeDef IWDT_INTW_DIV_X )
{
	SYSCON->IWDCR=IWDT_KEY|IWDT_TIME_X|IWDT_INTW_DIV_X;
    20f0:	1065      	lrw      	r3, 0x200000a0	// 2104 <SYSCON_IWDCNT_Config+0x14>
    20f2:	ea228778 	movih      	r2, 34680
    20f6:	9360      	ld.w      	r3, (r3, 0x0)
    20f8:	6c48      	or      	r1, r2
    20fa:	6c04      	or      	r0, r1
    20fc:	dc03202d 	st.w      	r0, (r3, 0xb4)
}
    2100:	783c      	jmp      	r15
    2102:	0000      	bkpt
    2104:	200000a0 	.long	0x200000a0

Disassembly of section .text.SYSCON_LVD_Config:

00002108 <SYSCON_LVD_Config>:
//RSTDET_LVL_X:RSTDET_LVL_1_6V,RSTDET_LVL_2_0V,RSTDET_LVL_2_4V,RSTDET_LVL_2_8V,RSTDET_LVL_3_2V,RSTDET_LVL_3_6V,RSTDET_LVL_4_0V,RSTDET_LVL_4_4V
//INTDET_POL_X:INTDET_POL_fall,INTDET_POL_X_rise,INTDET_POL_X_riseORfall
//ReturnValue: NONE
/*************************************************************/
void SYSCON_LVD_Config(X_LVDEN_TypeDef X_LVDEN ,LVDRST_CMD_TypeDef LVDRST_CMD , INTDET_LVL_X_TypeDef INTDET_LVL_X , RSTDET_LVL_X_TypeDef RSTDET_LVL_X , INTDET_POL_X_TypeDef INTDET_POL_X)
{
    2108:	14c3      	push      	r4-r6
	//SYSCON->LVDCR=LVD_KEY;
	SYSCON->LVDCR=LVD_KEY|X_LVDEN|LVDRST_CMD|INTDET_LVL_X|RSTDET_LVL_X|INTDET_POL_X;
    210a:	ea26b44b 	movih      	r6, 46155
{
    210e:	9883      	ld.w      	r4, (r14, 0xc)
	SYSCON->LVDCR=LVD_KEY|X_LVDEN|LVDRST_CMD|INTDET_LVL_X|RSTDET_LVL_X|INTDET_POL_X;
    2110:	6d18      	or      	r4, r6
    2112:	6cd0      	or      	r3, r4
    2114:	10a4      	lrw      	r5, 0x200000a0	// 2124 <SYSCON_LVD_Config+0x1c>
    2116:	6c8c      	or      	r2, r3
    2118:	95a0      	ld.w      	r5, (r5, 0x0)
    211a:	6c48      	or      	r1, r2
    211c:	6c04      	or      	r0, r1
    211e:	b513      	st.w      	r0, (r5, 0x4c)
}
    2120:	1483      	pop      	r4-r6
    2122:	0000      	bkpt
    2124:	200000a0 	.long	0x200000a0

Disassembly of section .text.LVD_Int_Enable:

00002128 <LVD_Int_Enable>:
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void LVD_Int_Enable(void)
{
	SYSCON->ICR = LVD_INT_ST;				//clear LVD INT status
    2128:	1066      	lrw      	r3, 0x200000a0	// 2140 <LVD_Int_Enable+0x18>
    212a:	3280      	movi      	r2, 128
    212c:	9360      	ld.w      	r3, (r3, 0x0)
    212e:	4244      	lsli      	r2, r2, 4
    2130:	dc432021 	st.w      	r2, (r3, 0x84)
	SYSCON->IMER  |= LVD_INT_ST;
    2134:	935d      	ld.w      	r2, (r3, 0x74)
    2136:	ec420800 	ori      	r2, r2, 2048
    213a:	b35d      	st.w      	r2, (r3, 0x74)
}
    213c:	783c      	jmp      	r15
    213e:	0000      	bkpt
    2140:	200000a0 	.long	0x200000a0

Disassembly of section .text.EXTI_trigger_CMD:

00002144 <EXTI_trigger_CMD>:
//EXI_tringer_mode:_EXIRT,_EXIFT
//ReturnValue: LVD detection flag
/*************************************************************/
void EXTI_trigger_CMD(FunctionalStatus NewState , SYSCON_EXIPIN_TypeDef  EXIPIN , EXI_tringer_mode_TypeDef EXI_tringer_mode)
{
	switch(EXI_tringer_mode)
    2144:	3a40      	cmpnei      	r2, 0
    2146:	0c04      	bf      	0x214e	// 214e <EXTI_trigger_CMD+0xa>
    2148:	3a41      	cmpnei      	r2, 1
    214a:	0c0f      	bf      	0x2168	// 2168 <EXTI_trigger_CMD+0x24>
		{
			SYSCON->EXIFT &=~EXIPIN;	
		}
		break;
	}	
}
    214c:	783c      	jmp      	r15
    214e:	1070      	lrw      	r3, 0x200000a0	// 218c <EXTI_trigger_CMD+0x48>
		if(NewState != DISABLE)
    2150:	3840      	cmpnei      	r0, 0
			SYSCON->EXIRT |=EXIPIN;
    2152:	9340      	ld.w      	r2, (r3, 0x0)
    2154:	d8622025 	ld.w      	r3, (r2, 0x94)
		if(NewState != DISABLE)
    2158:	0c05      	bf      	0x2162	// 2162 <EXTI_trigger_CMD+0x1e>
			SYSCON->EXIRT |=EXIPIN;
    215a:	6c4c      	or      	r1, r3
			SYSCON->EXIRT &=~EXIPIN;	
    215c:	dc222025 	st.w      	r1, (r2, 0x94)
    2160:	07f6      	br      	0x214c	// 214c <EXTI_trigger_CMD+0x8>
    2162:	c4232041 	andn      	r1, r3, r1
    2166:	07fb      	br      	0x215c	// 215c <EXTI_trigger_CMD+0x18>
		if(NewState != DISABLE)
    2168:	3840      	cmpnei      	r0, 0
    216a:	1069      	lrw      	r3, 0x200000a0	// 218c <EXTI_trigger_CMD+0x48>
    216c:	0c08      	bf      	0x217c	// 217c <EXTI_trigger_CMD+0x38>
			SYSCON->EXIFT |=EXIPIN;
    216e:	9340      	ld.w      	r2, (r3, 0x0)
    2170:	d8622026 	ld.w      	r3, (r2, 0x98)
    2174:	6c4c      	or      	r1, r3
    2176:	dc222026 	st.w      	r1, (r2, 0x98)
    217a:	07e9      	br      	0x214c	// 214c <EXTI_trigger_CMD+0x8>
			SYSCON->EXIFT &=~EXIPIN;	
    217c:	9360      	ld.w      	r3, (r3, 0x0)
    217e:	d8432026 	ld.w      	r2, (r3, 0x98)
    2182:	c4222041 	andn      	r1, r2, r1
    2186:	dc232026 	st.w      	r1, (r3, 0x98)
}
    218a:	07e1      	br      	0x214c	// 214c <EXTI_trigger_CMD+0x8>
    218c:	200000a0 	.long	0x200000a0

Disassembly of section .text.WWDT_CNT_Load:

00002190 <WWDT_CNT_Load>:
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void WWDT_CNT_Load(U8_T cnt_data)
{
	WWDT->CR  |= cnt_data;						//SET
    2190:	1063      	lrw      	r3, 0x20000034	// 219c <WWDT_CNT_Load+0xc>
    2192:	9360      	ld.w      	r3, (r3, 0x0)
    2194:	9340      	ld.w      	r2, (r3, 0x0)
    2196:	6c08      	or      	r0, r2
    2198:	b300      	st.w      	r0, (r3, 0x0)
}
    219a:	783c      	jmp      	r15
    219c:	20000034 	.long	0x20000034

Disassembly of section .text.delay_nms:

000021a0 <delay_nms>:
//software delay
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/	
void delay_nms(unsigned int t)
{
    21a0:	14d0      	push      	r15
    21a2:	1423      	subi      	r14, r14, 12
    volatile unsigned int i,j ,k=0;
    21a4:	3300      	movi      	r3, 0
    21a6:	b862      	st.w      	r3, (r14, 0x8)
    j = 50* t;
    21a8:	3332      	movi      	r3, 50
    21aa:	7c0c      	mult      	r0, r3
    21ac:	b801      	st.w      	r0, (r14, 0x4)
    for ( i = 0; i < j; i++ )
    21ae:	3300      	movi      	r3, 0
    21b0:	b860      	st.w      	r3, (r14, 0x0)
    21b2:	9840      	ld.w      	r2, (r14, 0x0)
    21b4:	9861      	ld.w      	r3, (r14, 0x4)
    21b6:	64c8      	cmphs      	r2, r3
    21b8:	0c03      	bf      	0x21be	// 21be <delay_nms+0x1e>
    {
        k++;
		SYSCON_IWDCNT_Reload(); 
    }
}
    21ba:	1403      	addi      	r14, r14, 12
    21bc:	1490      	pop      	r15
        k++;
    21be:	9862      	ld.w      	r3, (r14, 0x8)
    21c0:	2300      	addi      	r3, 1
    21c2:	b862      	st.w      	r3, (r14, 0x8)
		SYSCON_IWDCNT_Reload(); 
    21c4:	e3ffff8c 	bsr      	0x20dc	// 20dc <SYSCON_IWDCNT_Reload>
    for ( i = 0; i < j; i++ )
    21c8:	9860      	ld.w      	r3, (r14, 0x0)
    21ca:	2300      	addi      	r3, 1
    21cc:	07f2      	br      	0x21b0	// 21b0 <delay_nms+0x10>

Disassembly of section .text.I2C_SLAVE_CONFIG:

000021ce <I2C_SLAVE_CONFIG>:
//IIC SLAVER Initial
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/	
void I2C_SLAVE_CONFIG(void)
{
    21ce:	14d0      	push      	r15
    21d0:	1423      	subi      	r14, r14, 12
	I2C_RESET();
    21d2:	e3fffd97 	bsr      	0x1d00	// 1d00 <I2C_RESET>
	//I2C_DeInit();																		   //I2C de-initial
	I2C_Slave_CONFIG(I2C_SDA_PA0_3,I2C_SCL_PA0_4,FAST_MODE,I2C_SLAVE_7BIT,0X57,0X8,0X8);//I2C IO selection,fast mode,slave 7 bit,slave address 0x57(slave address cant set as 0x00~0x07,0x78~0x7f)
    21d6:	3308      	movi      	r3, 8
    21d8:	3204      	movi      	r2, 4
    21da:	b862      	st.w      	r3, (r14, 0x8)
    21dc:	b861      	st.w      	r3, (r14, 0x4)
    21de:	3357      	movi      	r3, 87
    21e0:	3101      	movi      	r1, 1
    21e2:	b860      	st.w      	r3, (r14, 0x0)
    21e4:	3000      	movi      	r0, 0
    21e6:	3300      	movi      	r3, 0
    21e8:	e3fffc72 	bsr      	0x1acc	// 1acc <I2C_Slave_CONFIG>
	I2C_SDA_TSETUP_THOLD_CONFIG(0x02,0x03,0x08);
    21ec:	3208      	movi      	r2, 8
    21ee:	3103      	movi      	r1, 3
    21f0:	3002      	movi      	r0, 2
    21f2:	e3fffd41 	bsr      	0x1c74	// 1c74 <I2C_SDA_TSETUP_THOLD_CONFIG>
	I2C_FIFO_TriggerData(0,0);															  //I2C  FIFO setting
    21f6:	3100      	movi      	r1, 0
    21f8:	3000      	movi      	r0, 0
    21fa:	e3fffd55 	bsr      	0x1ca4	// 1ca4 <I2C_FIFO_TriggerData>
	I2C_ConfigInterrupt_CMD(ENABLE,I2C_SCL_SLOW);										  //I2C interrupt enable/disable
    21fe:	3180      	movi      	r1, 128
    2200:	4127      	lsli      	r1, r1, 7
    2202:	3001      	movi      	r0, 1
    2204:	e3fffd42 	bsr      	0x1c88	// 1c88 <I2C_ConfigInterrupt_CMD>
	I2C_ConfigInterrupt_CMD(ENABLE,I2C_STOP_DET);
    2208:	3180      	movi      	r1, 128
    220a:	4122      	lsli      	r1, r1, 2
    220c:	3001      	movi      	r0, 1
    220e:	e3fffd3d 	bsr      	0x1c88	// 1c88 <I2C_ConfigInterrupt_CMD>
	I2C_ConfigInterrupt_CMD(ENABLE,I2C_RD_REQ);
    2212:	3120      	movi      	r1, 32
    2214:	3001      	movi      	r0, 1
    2216:	e3fffd39 	bsr      	0x1c88	// 1c88 <I2C_ConfigInterrupt_CMD>
	I2C_ConfigInterrupt_CMD(ENABLE,I2C_RX_FULL);
    221a:	3104      	movi      	r1, 4
    221c:	3001      	movi      	r0, 1
    221e:	e3fffd35 	bsr      	0x1c88	// 1c88 <I2C_ConfigInterrupt_CMD>
	I2C_ConfigInterrupt_CMD(ENABLE,I2C_TX_ABRT);
    2222:	3140      	movi      	r1, 64
    2224:	3001      	movi      	r0, 1
    2226:	e3fffd31 	bsr      	0x1c88	// 1c88 <I2C_ConfigInterrupt_CMD>
	I2C_Enable();
    222a:	e3fffd45 	bsr      	0x1cb4	// 1cb4 <I2C_Enable>
	I2C_Int_Enable();
    222e:	e3fffd61 	bsr      	0x1cf0	// 1cf0 <I2C_Int_Enable>
	
}
    2232:	1403      	addi      	r14, r14, 12
    2234:	1490      	pop      	r15

Disassembly of section .text.SYSCON_CONFIG:

00002236 <SYSCON_CONFIG>:
//syscon Functions
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SYSCON_CONFIG(void)
{
    2236:	14d0      	push      	r15
    2238:	1421      	subi      	r14, r14, 4
//------SYSTEM CLK AND PCLK FUNTION---------------------------/
	SYSCON_RST_VALUE();                                                         //SYSCON all register clr
    223a:	e3fffe8f 	bsr      	0x1f58	// 1f58 <SYSCON_RST_VALUE>
	SYSCON_General_CMD(ENABLE,ENDIS_ISOSC);										//SYSCON enable/disable clock source
    223e:	3101      	movi      	r1, 1
    2240:	3001      	movi      	r0, 1
    2242:	e3fffebb 	bsr      	0x1fb8	// 1fb8 <SYSCON_General_CMD>
	//ESOSC_OSTR_Config(0XFF,7,EM_SMT_EN);										//ES_CNT=0XFF,ES_GM=7,Enable STM
	//SYSCON_General_CMD(ENABLE,ENDIS_ESOSC);
	SYSCON_HFOSC_SELECTE(HFOSC_SELECTE_48M);									//HFOSC selected 48MHz
    2246:	3000      	movi      	r0, 0
    2248:	e3ffff16 	bsr      	0x2074	// 2074 <SYSCON_HFOSC_SELECTE>
	SystemCLK_HCLKDIV_PCLKDIV_Config(SYSCLK_HFOSC,HCLK_DIV_1,PCLK_DIV_1,HFOSC_48M);//system clock set, Hclk div ,Pclk div  set system clock=SystemCLK/Hclk div/Pclk div
    224c:	3180      	movi      	r1, 128
    224e:	3308      	movi      	r3, 8
    2250:	3200      	movi      	r2, 0
    2252:	4121      	lsli      	r1, r1, 1
    2254:	3002      	movi      	r0, 2
    2256:	e3fffec9 	bsr      	0x1fe8	// 1fe8 <SystemCLK_HCLKDIV_PCLKDIV_Config>
//------------  WDT FUNTION  --------------------------------/
    SYSCON_IWDCNT_Config(IWDT_TIME_2S,IWDT_INTW_DIV_7);      					//WDT TIME 1s,WDT alarm interrupt time=1s-1s*1/8=0.875S
    225a:	3080      	movi      	r0, 128
    225c:	3118      	movi      	r1, 24
    225e:	4003      	lsli      	r0, r0, 3
    2260:	e3ffff48 	bsr      	0x20f0	// 20f0 <SYSCON_IWDCNT_Config>
    SYSCON_WDT_CMD(DISABLE);                                                  	//enable/disable WDT		
    2264:	3000      	movi      	r0, 0
    2266:	e3ffff1b 	bsr      	0x209c	// 209c <SYSCON_WDT_CMD>
    SYSCON_IWDCNT_Reload();                                                   	//reload WDT
    226a:	e3ffff39 	bsr      	0x20dc	// 20dc <SYSCON_IWDCNT_Reload>
//------------ EVTRG function --------------------------------/ 	
	//SYSCON->EVTRG=0X00|(0x01<<4)|0x03<<20;									//SYSCON_trgsrc0,SYSCON_trgsrc1
	//SYSCON->EVPS=0X00;
	//SYSCON->IMER =EM_EVTRG1_ST|EM_EVTRG0_ST;
//------------  LVD FUNTION  --------------------------------/ 
    SYSCON_LVD_Config(DISABLE_LVDEN,LVDRST_DIS,INTDET_LVL_2_7V,RSTDET_LVL_1_9V,INTDET_POL_fall);   //LVD LVR Enable/Disable
    226e:	3340      	movi      	r3, 64
    2270:	3280      	movi      	r2, 128
    2272:	b860      	st.w      	r3, (r14, 0x0)
    2274:	4242      	lsli      	r2, r2, 2
    2276:	3300      	movi      	r3, 0
    2278:	3110      	movi      	r1, 16
    227a:	300a      	movi      	r0, 10
    227c:	e3ffff46 	bsr      	0x2108	// 2108 <SYSCON_LVD_Config>
    LVD_Int_Enable();	
    2280:	e3ffff54 	bsr      	0x2128	// 2128 <LVD_Int_Enable>
//------------  SYSCON Vector  --------------------------------/ 	
	//SYSCON_Int_Enable();    														//SYSCON VECTOR
	//SYSCON_WakeUp_Enable();    													//Enable WDT wakeup INT	
}
    2284:	1401      	addi      	r14, r14, 4
    2286:	1490      	pop      	r15

Disassembly of section .text.APT32F110x_init:

00002288 <APT32F110x_init>:
//ReturnValue:NONE                                                                /
/*********************************************************************************/
/*********************************************************************************/  
/*********************************************************************************/
void APT32F110x_init(void) 
{
    2288:	14d0      	push      	r15
//------------------------------------------------------------/
//Peripheral clock enable and disable
//EntryParameter:NONE
//ReturnValue:NONE
//------------------------------------------------------------/
    SYSCON->PCER0=0xFFFFFFF;                                        //PCLK Enable
    228a:	1069      	lrw      	r3, 0x200000a0	// 22ac <APT32F110x_init+0x24>
    SYSCON->PCER1=0xFFFFFFF;                                        //PCLK Enable
    while(!(SYSCON->PCSR0&0x1));                                    //Wait PCLK enabled	
    228c:	3101      	movi      	r1, 1
    SYSCON->PCER0=0xFFFFFFF;                                        //PCLK Enable
    228e:	9340      	ld.w      	r2, (r3, 0x0)
    2290:	c7605023 	bmaski      	r3, 28
    2294:	b26a      	st.w      	r3, (r2, 0x28)
    SYSCON->PCER1=0xFFFFFFF;                                        //PCLK Enable
    2296:	b26d      	st.w      	r3, (r2, 0x34)
    while(!(SYSCON->PCSR0&0x1));                                    //Wait PCLK enabled	
    2298:	926c      	ld.w      	r3, (r2, 0x30)
    229a:	68c4      	and      	r3, r1
    229c:	3b40      	cmpnei      	r3, 0
    229e:	0ffd      	bf      	0x2298	// 2298 <APT32F110x_init+0x10>
//------------------------------------------------------------/
//ISOSC/IMOSC/EMOSC/SYSCLK/IWDT/LVD/EM_CMFAIL/EM_CMRCV/CMD_ERR OSC stable interrupt
//EntryParameter:NONE
//ReturnValue:NONE
//------------------------------------------------------------/
    SYSCON_CONFIG();                                                 //syscon  initial
    22a0:	e3ffffcb 	bsr      	0x2236	// 2236 <SYSCON_CONFIG>
	CK_CPU_EnAllNormalIrq();                                         //enable all IRQ
    22a4:	e3fffb1e 	bsr      	0x18e0	// 18e0 <CK_CPU_EnAllNormalIrq>
	//LCD_CONFIG();													//LCD initial
	//LED_CONFIG();													//LED initial 
	//ADC12_CONFIG();                                               //ADC initial
	//CMP_CONFIG();													//CMP initial
	//TKEY_CONFIG();
}
    22a8:	1490      	pop      	r15
    22aa:	0000      	bkpt
    22ac:	200000a0 	.long	0x200000a0

Disassembly of section .text.CORETHandler:

000022b0 <CORETHandler>:
//you need to open this interrupt entry
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CORETHandler(void)
{
    22b0:	1460      	nie
    22b2:	1462      	ipush
    22b4:	14d0      	push      	r15
	// ISR content ...
	CK802->CORET_CVR = 0x0;	
    22b6:	1066      	lrw      	r3, 0x200000a8	// 22cc <CORETHandler+0x1c>
    22b8:	3200      	movi      	r2, 0
    22ba:	9360      	ld.w      	r3, (r3, 0x0)
    22bc:	b346      	st.w      	r2, (r3, 0x18)
	csi_tkey_basecnt_process();
    22be:	e3fff8a2 	bsr      	0x1402	// 1402 <csi_tkey_basecnt_process>
}
    22c2:	d9ee2000 	ld.w      	r15, (r14, 0x0)
    22c6:	1401      	addi      	r14, r14, 4
    22c8:	1463      	ipop
    22ca:	1461      	nir
    22cc:	200000a8 	.long	0x200000a8

Disassembly of section .text.SYSCONIntHandler:

000022d0 <SYSCONIntHandler>:
//SYSCON Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SYSCONIntHandler(void) 
{
    22d0:	1460      	nie
    22d2:	1462      	ipush
    22d4:	14d0      	push      	r15
    // ISR content ...
	if((SYSCON->MISR&ISOSC_ST)==ISOSC_ST)				//ISOSC stable interrupt
    22d6:	126d      	lrw      	r3, 0x200000a0	// 2408 <SYSCONIntHandler+0x138>
    22d8:	9360      	ld.w      	r3, (r3, 0x0)
    22da:	d8432023 	ld.w      	r2, (r3, 0x8c)
    22de:	e4422001 	andi      	r2, r2, 1
    22e2:	3a40      	cmpnei      	r2, 0
    22e4:	0c05      	bf      	0x22ee	// 22ee <SYSCONIntHandler+0x1e>
	{
		SYSCON->ICR = ISOSC_ST;
    22e6:	3201      	movi      	r2, 1
	{
		SYSCON->ICR = EM_EVTRG3_ST;
	}
	else if((SYSCON->MISR&CMD_ERR_ST)==CMD_ERR_ST)		//Command error interrupt
	{
		SYSCON->ICR = CMD_ERR_ST;
    22e8:	dc432021 	st.w      	r2, (r3, 0x84)
	}
}
    22ec:	042d      	br      	0x2346	// 2346 <SYSCONIntHandler+0x76>
	else if((SYSCON->MISR&IMOSC_ST)==IMOSC_ST)			//IMOSC stable interrupt
    22ee:	d8432023 	ld.w      	r2, (r3, 0x8c)
    22f2:	e4422002 	andi      	r2, r2, 2
    22f6:	3a40      	cmpnei      	r2, 0
    22f8:	0c03      	bf      	0x22fe	// 22fe <SYSCONIntHandler+0x2e>
		SYSCON->ICR = IMOSC_ST;
    22fa:	3202      	movi      	r2, 2
    22fc:	07f6      	br      	0x22e8	// 22e8 <SYSCONIntHandler+0x18>
	else if((SYSCON->MISR&EMOSC_ST)==EMOSC_ST)			//EMOSC stable interrupt
    22fe:	d8432023 	ld.w      	r2, (r3, 0x8c)
    2302:	e4422008 	andi      	r2, r2, 8
    2306:	3a40      	cmpnei      	r2, 0
    2308:	0c03      	bf      	0x230e	// 230e <SYSCONIntHandler+0x3e>
		SYSCON->ICR = EMOSC_ST;
    230a:	3208      	movi      	r2, 8
    230c:	07ee      	br      	0x22e8	// 22e8 <SYSCONIntHandler+0x18>
	else if((SYSCON->MISR&HFOSC_ST)==HFOSC_ST)			//HFOSC stable interrupt
    230e:	d8432023 	ld.w      	r2, (r3, 0x8c)
    2312:	e4422010 	andi      	r2, r2, 16
    2316:	3a40      	cmpnei      	r2, 0
    2318:	0c03      	bf      	0x231e	// 231e <SYSCONIntHandler+0x4e>
		SYSCON->ICR = HFOSC_ST;
    231a:	3210      	movi      	r2, 16
    231c:	07e6      	br      	0x22e8	// 22e8 <SYSCONIntHandler+0x18>
	else if((SYSCON->MISR&SYSCLK_ST)==SYSCLK_ST)		//SYSCLK change end & stable interrupt
    231e:	d8432023 	ld.w      	r2, (r3, 0x8c)
    2322:	e4422080 	andi      	r2, r2, 128
    2326:	3a40      	cmpnei      	r2, 0
    2328:	0c03      	bf      	0x232e	// 232e <SYSCONIntHandler+0x5e>
		SYSCON->ICR = SYSCLK_ST;
    232a:	3280      	movi      	r2, 128
    232c:	07de      	br      	0x22e8	// 22e8 <SYSCONIntHandler+0x18>
	else if((SYSCON->MISR&IWDT_INT_ST)==IWDT_INT_ST)	//IWDT alarm window interrupt
    232e:	d8432023 	ld.w      	r2, (r3, 0x8c)
    2332:	e4422100 	andi      	r2, r2, 256
    2336:	3a40      	cmpnei      	r2, 0
    2338:	0c0c      	bf      	0x2350	// 2350 <SYSCONIntHandler+0x80>
		SYSCON->ICR = IWDT_INT_ST;
    233a:	3280      	movi      	r2, 128
    233c:	4241      	lsli      	r2, r2, 1
    233e:	dc432021 	st.w      	r2, (r3, 0x84)
		SYSCON_IWDCNT_Reload(); 
    2342:	e3fffecd 	bsr      	0x20dc	// 20dc <SYSCON_IWDCNT_Reload>
}
    2346:	d9ee2000 	ld.w      	r15, (r14, 0x0)
    234a:	1401      	addi      	r14, r14, 4
    234c:	1463      	ipop
    234e:	1461      	nir
	else if((SYSCON->MISR&WKI_INT_ST)==WKI_INT_ST)
    2350:	d8432023 	ld.w      	r2, (r3, 0x8c)
    2354:	e4422200 	andi      	r2, r2, 512
    2358:	3a40      	cmpnei      	r2, 0
    235a:	0c04      	bf      	0x2362	// 2362 <SYSCONIntHandler+0x92>
		SYSCON->ICR = WKI_INT_ST;
    235c:	3280      	movi      	r2, 128
    235e:	4242      	lsli      	r2, r2, 2
    2360:	07c4      	br      	0x22e8	// 22e8 <SYSCONIntHandler+0x18>
	else if((SYSCON->MISR&RAMERRINT_ST)==RAMERRINT_ST)	//SRAM check fail interrupt
    2362:	d8432023 	ld.w      	r2, (r3, 0x8c)
    2366:	e4422400 	andi      	r2, r2, 1024
    236a:	3a40      	cmpnei      	r2, 0
    236c:	0c04      	bf      	0x2374	// 2374 <SYSCONIntHandler+0xa4>
		SYSCON->ICR = RAMERRINT_ST;
    236e:	3280      	movi      	r2, 128
    2370:	4243      	lsli      	r2, r2, 3
    2372:	07bb      	br      	0x22e8	// 22e8 <SYSCONIntHandler+0x18>
	else if((SYSCON->MISR&LVD_INT_ST)==LVD_INT_ST)		//LVD threshold interrupt
    2374:	d8432023 	ld.w      	r2, (r3, 0x8c)
    2378:	e4422800 	andi      	r2, r2, 2048
    237c:	3a40      	cmpnei      	r2, 0
    237e:	0c04      	bf      	0x2386	// 2386 <SYSCONIntHandler+0xb6>
		SYSCON->ICR = LVD_INT_ST;
    2380:	3280      	movi      	r2, 128
    2382:	4244      	lsli      	r2, r2, 4
    2384:	07b2      	br      	0x22e8	// 22e8 <SYSCONIntHandler+0x18>
	else if((SYSCON->MISR&HWD_ERR_ST)==HWD_ERR_ST)		//Hardware Divider divisor = 0 interrupt
    2386:	3280      	movi      	r2, 128
    2388:	d8232023 	ld.w      	r1, (r3, 0x8c)
    238c:	4245      	lsli      	r2, r2, 5
    238e:	6848      	and      	r1, r2
    2390:	3940      	cmpnei      	r1, 0
    2392:	0bab      	bt      	0x22e8	// 22e8 <SYSCONIntHandler+0x18>
	else if((SYSCON->MISR&EFL_ERR_ST)==EFL_ERR_ST)		//Flash check fail interrupt
    2394:	3280      	movi      	r2, 128
    2396:	d8232023 	ld.w      	r1, (r3, 0x8c)
    239a:	4246      	lsli      	r2, r2, 6
    239c:	6848      	and      	r1, r2
    239e:	3940      	cmpnei      	r1, 0
    23a0:	0ba4      	bt      	0x22e8	// 22e8 <SYSCONIntHandler+0x18>
	else if((SYSCON->MISR&OPTERR_INT)==OPTERR_INT)		//Option load fail interrupt
    23a2:	3280      	movi      	r2, 128
    23a4:	d8232023 	ld.w      	r1, (r3, 0x8c)
    23a8:	4247      	lsli      	r2, r2, 7
    23aa:	6848      	and      	r1, r2
    23ac:	3940      	cmpnei      	r1, 0
    23ae:	0b9d      	bt      	0x22e8	// 22e8 <SYSCONIntHandler+0x18>
	else if((SYSCON->MISR&EM_CMLST_ST)==EM_CMLST_ST)	//EMOSC clock monitor fail interrupt
    23b0:	3280      	movi      	r2, 128
    23b2:	d8232023 	ld.w      	r1, (r3, 0x8c)
    23b6:	424b      	lsli      	r2, r2, 11
    23b8:	6848      	and      	r1, r2
    23ba:	3940      	cmpnei      	r1, 0
    23bc:	0b96      	bt      	0x22e8	// 22e8 <SYSCONIntHandler+0x18>
	else if((SYSCON->MISR&EM_EVTRG0_ST)==EM_EVTRG0_ST)	//Event Trigger Channel 0 Interrupt
    23be:	3280      	movi      	r2, 128
    23c0:	d8232023 	ld.w      	r1, (r3, 0x8c)
    23c4:	424c      	lsli      	r2, r2, 12
    23c6:	6848      	and      	r1, r2
    23c8:	3940      	cmpnei      	r1, 0
    23ca:	0b8f      	bt      	0x22e8	// 22e8 <SYSCONIntHandler+0x18>
	else if((SYSCON->MISR&EM_EVTRG1_ST)==EM_EVTRG1_ST)	//Event Trigger Channel 1 Interrupt
    23cc:	3280      	movi      	r2, 128
    23ce:	d8232023 	ld.w      	r1, (r3, 0x8c)
    23d2:	424d      	lsli      	r2, r2, 13
    23d4:	6848      	and      	r1, r2
    23d6:	3940      	cmpnei      	r1, 0
    23d8:	0b88      	bt      	0x22e8	// 22e8 <SYSCONIntHandler+0x18>
	else if((SYSCON->MISR&EM_EVTRG2_ST)==EM_EVTRG2_ST)	//Event Trigger Channel 2 Interrupt
    23da:	3280      	movi      	r2, 128
    23dc:	d8232023 	ld.w      	r1, (r3, 0x8c)
    23e0:	424e      	lsli      	r2, r2, 14
    23e2:	6848      	and      	r1, r2
    23e4:	3940      	cmpnei      	r1, 0
    23e6:	0b81      	bt      	0x22e8	// 22e8 <SYSCONIntHandler+0x18>
	else if((SYSCON->MISR&EM_EVTRG3_ST)==EM_EVTRG3_ST)	//Event Trigger Channel 3 Interrupt
    23e8:	3280      	movi      	r2, 128
    23ea:	d8232023 	ld.w      	r1, (r3, 0x8c)
    23ee:	424f      	lsli      	r2, r2, 15
    23f0:	6848      	and      	r1, r2
    23f2:	3940      	cmpnei      	r1, 0
    23f4:	0b7a      	bt      	0x22e8	// 22e8 <SYSCONIntHandler+0x18>
	else if((SYSCON->MISR&CMD_ERR_ST)==CMD_ERR_ST)		//Command error interrupt
    23f6:	3280      	movi      	r2, 128
    23f8:	d8232023 	ld.w      	r1, (r3, 0x8c)
    23fc:	4256      	lsli      	r2, r2, 22
    23fe:	6848      	and      	r1, r2
    2400:	3940      	cmpnei      	r1, 0
    2402:	0b73      	bt      	0x22e8	// 22e8 <SYSCONIntHandler+0x18>
    2404:	07a1      	br      	0x2346	// 2346 <SYSCONIntHandler+0x76>
    2406:	0000      	bkpt
    2408:	200000a0 	.long	0x200000a0

Disassembly of section .text.IFCIntHandler:

0000240c <IFCIntHandler>:
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
volatile U8_T ifc_step,f_Drom_write_complete;
void IFCIntHandler(void) 
{
    240c:	1460      	nie
    240e:	1462      	ipush
    // ISR content ...
	if(IFC->MISR&ERS_END_INT)			
    2410:	1174      	lrw      	r3, 0x200000a4	// 24e0 <IFCIntHandler+0xd4>
    2412:	9360      	ld.w      	r3, (r3, 0x0)
    2414:	934b      	ld.w      	r2, (r3, 0x2c)
    2416:	e4422001 	andi      	r2, r2, 1
    241a:	3a40      	cmpnei      	r2, 0
    241c:	0c17      	bf      	0x244a	// 244a <IFCIntHandler+0x3e>
	{
		IFC->ICR=ERS_END_INT;
    241e:	3201      	movi      	r2, 1
    2420:	b34c      	st.w      	r2, (r3, 0x30)
		if((ifc_step==1)&&(f_Drom_writing==1))
    2422:	1151      	lrw      	r2, 0x200002e1	// 24e4 <IFCIntHandler+0xd8>
    2424:	8220      	ld.b      	r1, (r2, 0x0)
    2426:	3941      	cmpnei      	r1, 1
    2428:	0825      	bt      	0x2472	// 2472 <IFCIntHandler+0x66>
    242a:	1130      	lrw      	r1, 0x200000be	// 24e8 <IFCIntHandler+0xdc>
    242c:	8120      	ld.b      	r1, (r1, 0x0)
    242e:	3941      	cmpnei      	r1, 1
    2430:	0821      	bt      	0x2472	// 2472 <IFCIntHandler+0x66>
		{
			SetUserKey;
    2432:	112f      	lrw      	r1, 0x5a5a5a5a	// 24ec <IFCIntHandler+0xe0>
    2434:	b328      	st.w      	r1, (r3, 0x20)
			IFC->CMR=0x01;					//将页缓存的数据写入闪存中
    2436:	3101      	movi      	r1, 1
    2438:	b323      	st.w      	r1, (r3, 0xc)
			IFC->FM_ADDR=R_INT_FlashAdd;		//
    243a:	112e      	lrw      	r1, 0x200002d0	// 24f0 <IFCIntHandler+0xe4>
    243c:	9120      	ld.w      	r1, (r1, 0x0)
    243e:	b326      	st.w      	r1, (r3, 0x18)
			IFC->CR=0X01;					//Start Program
    2440:	3101      	movi      	r1, 1
    2442:	b324      	st.w      	r1, (r3, 0x10)
			ifc_step=2;
    2444:	3302      	movi      	r3, 2
		{
			SetUserKey;
			IFC->CMR=0x02;					//页擦除
			IFC->FM_ADDR=R_INT_FlashAdd;			//
			IFC->CR=0X01;					//Start Program
			ifc_step=1;
    2446:	a260      	st.b      	r3, (r2, 0x0)
    2448:	0415      	br      	0x2472	// 2472 <IFCIntHandler+0x66>
	else if(IFC->MISR&RGM_END_INT)		
    244a:	934b      	ld.w      	r2, (r3, 0x2c)
    244c:	e4422002 	andi      	r2, r2, 2
    2450:	3a40      	cmpnei      	r2, 0
    2452:	0c12      	bf      	0x2476	// 2476 <IFCIntHandler+0x6a>
		IFC->ICR=RGM_END_INT;
    2454:	3202      	movi      	r2, 2
    2456:	b34c      	st.w      	r2, (r3, 0x30)
		if((ifc_step==2)&&(f_Drom_writing==1))
    2458:	1163      	lrw      	r3, 0x200002e1	// 24e4 <IFCIntHandler+0xd8>
    245a:	8360      	ld.b      	r3, (r3, 0x0)
    245c:	3b42      	cmpnei      	r3, 2
    245e:	080a      	bt      	0x2472	// 2472 <IFCIntHandler+0x66>
    2460:	1162      	lrw      	r3, 0x200000be	// 24e8 <IFCIntHandler+0xdc>
    2462:	8340      	ld.b      	r2, (r3, 0x0)
    2464:	3a41      	cmpnei      	r2, 1
    2466:	0806      	bt      	0x2472	// 2472 <IFCIntHandler+0x66>
			f_Drom_writing=0;
    2468:	3200      	movi      	r2, 0
    246a:	a340      	st.b      	r2, (r3, 0x0)
			f_Drom_write_complete=1;
    246c:	3201      	movi      	r2, 1
    246e:	1162      	lrw      	r3, 0x200002e0	// 24f4 <IFCIntHandler+0xe8>
    2470:	a340      	st.b      	r2, (r3, 0x0)
	}
	else if(IFC->MISR&OVW_ERR_INT)		
	{
		IFC->ICR=OVW_ERR_INT;
	}
}
    2472:	1463      	ipop
    2474:	1461      	nir
	else if(IFC->MISR&PEP_END_INT)		
    2476:	934b      	ld.w      	r2, (r3, 0x2c)
    2478:	e4422004 	andi      	r2, r2, 4
    247c:	3a40      	cmpnei      	r2, 0
    247e:	0c16      	bf      	0x24aa	// 24aa <IFCIntHandler+0x9e>
		IFC->ICR=PEP_END_INT;
    2480:	3204      	movi      	r2, 4
    2482:	b34c      	st.w      	r2, (r3, 0x30)
		if((ifc_step==0)&&(f_Drom_writing==1))
    2484:	1058      	lrw      	r2, 0x200002e1	// 24e4 <IFCIntHandler+0xd8>
    2486:	8220      	ld.b      	r1, (r2, 0x0)
    2488:	3940      	cmpnei      	r1, 0
    248a:	0bf4      	bt      	0x2472	// 2472 <IFCIntHandler+0x66>
    248c:	1037      	lrw      	r1, 0x200000be	// 24e8 <IFCIntHandler+0xdc>
    248e:	8120      	ld.b      	r1, (r1, 0x0)
    2490:	3941      	cmpnei      	r1, 1
    2492:	0bf0      	bt      	0x2472	// 2472 <IFCIntHandler+0x66>
			SetUserKey;
    2494:	1036      	lrw      	r1, 0x5a5a5a5a	// 24ec <IFCIntHandler+0xe0>
    2496:	b328      	st.w      	r1, (r3, 0x20)
			IFC->CMR=0x02;					//页擦除
    2498:	3102      	movi      	r1, 2
    249a:	b323      	st.w      	r1, (r3, 0xc)
			IFC->FM_ADDR=R_INT_FlashAdd;			//
    249c:	1035      	lrw      	r1, 0x200002d0	// 24f0 <IFCIntHandler+0xe4>
    249e:	9120      	ld.w      	r1, (r1, 0x0)
    24a0:	b326      	st.w      	r1, (r3, 0x18)
			IFC->CR=0X01;					//Start Program
    24a2:	3101      	movi      	r1, 1
    24a4:	b324      	st.w      	r1, (r3, 0x10)
			ifc_step=1;
    24a6:	3301      	movi      	r3, 1
    24a8:	07cf      	br      	0x2446	// 2446 <IFCIntHandler+0x3a>
	else if(IFC->MISR&PROT_ERR_INT)		
    24aa:	3280      	movi      	r2, 128
    24ac:	932b      	ld.w      	r1, (r3, 0x2c)
    24ae:	4245      	lsli      	r2, r2, 5
    24b0:	6848      	and      	r1, r2
    24b2:	3940      	cmpnei      	r1, 0
    24b4:	0c03      	bf      	0x24ba	// 24ba <IFCIntHandler+0xae>
		IFC->ICR=OVW_ERR_INT;
    24b6:	b34c      	st.w      	r2, (r3, 0x30)
}
    24b8:	07dd      	br      	0x2472	// 2472 <IFCIntHandler+0x66>
	else if(IFC->MISR&UDEF_ERR_INT)		
    24ba:	3280      	movi      	r2, 128
    24bc:	932b      	ld.w      	r1, (r3, 0x2c)
    24be:	4246      	lsli      	r2, r2, 6
    24c0:	6848      	and      	r1, r2
    24c2:	3940      	cmpnei      	r1, 0
    24c4:	0bf9      	bt      	0x24b6	// 24b6 <IFCIntHandler+0xaa>
	else if(IFC->MISR&ADDR_ERR_INT)		
    24c6:	3280      	movi      	r2, 128
    24c8:	932b      	ld.w      	r1, (r3, 0x2c)
    24ca:	4247      	lsli      	r2, r2, 7
    24cc:	6848      	and      	r1, r2
    24ce:	3940      	cmpnei      	r1, 0
    24d0:	0bf3      	bt      	0x24b6	// 24b6 <IFCIntHandler+0xaa>
	else if(IFC->MISR&OVW_ERR_INT)		
    24d2:	3280      	movi      	r2, 128
    24d4:	932b      	ld.w      	r1, (r3, 0x2c)
    24d6:	4248      	lsli      	r2, r2, 8
    24d8:	6848      	and      	r1, r2
    24da:	3940      	cmpnei      	r1, 0
    24dc:	0bed      	bt      	0x24b6	// 24b6 <IFCIntHandler+0xaa>
    24de:	07ca      	br      	0x2472	// 2472 <IFCIntHandler+0x66>
    24e0:	200000a4 	.long	0x200000a4
    24e4:	200002e1 	.long	0x200002e1
    24e8:	200000be 	.long	0x200000be
    24ec:	5a5a5a5a 	.long	0x5a5a5a5a
    24f0:	200002d0 	.long	0x200002d0
    24f4:	200002e0 	.long	0x200002e0

Disassembly of section .text.ADCIntHandler:

000024f8 <ADCIntHandler>:
//ADC Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void ADCIntHandler(void) 
{
    24f8:	1460      	nie
    24fa:	1462      	ipush
    // ISR content ...
	if((ADC0->SR&ADC12_EOC)==ADC12_EOC)				//ADC EOC interrupt
    24fc:	107e      	lrw      	r3, 0x20000090	// 2574 <ADCIntHandler+0x7c>
    24fe:	9360      	ld.w      	r3, (r3, 0x0)
    2500:	9348      	ld.w      	r2, (r3, 0x20)
    2502:	e4422001 	andi      	r2, r2, 1
    2506:	3a40      	cmpnei      	r2, 0
    2508:	0c04      	bf      	0x2510	// 2510 <ADCIntHandler+0x18>
	{
		ADC0->CSR = ADC12_EOC;
    250a:	3201      	movi      	r2, 1
	{
		ADC0->CSR = ADC12_CMP1L;
	}
	else if((ADC0->SR&ADC12_SEQ_END0)==ADC12_SEQ_END0) //ADC SEQ0 interrupt,SEQ1~SEQ15 replace the parameter with ADC12_SEQ_END1~ADC12_SEQ_END15
	{
		ADC0->CSR = ADC12_SEQ_END0;
    250c:	b347      	st.w      	r2, (r3, 0x1c)
	}
}
    250e:	0431      	br      	0x2570	// 2570 <ADCIntHandler+0x78>
	else if((ADC0->SR&ADC12_READY)==ADC12_READY)	//ADC READY interrupt
    2510:	9348      	ld.w      	r2, (r3, 0x20)
    2512:	e4422002 	andi      	r2, r2, 2
    2516:	3a40      	cmpnei      	r2, 0
    2518:	0c03      	bf      	0x251e	// 251e <ADCIntHandler+0x26>
		ADC0->CSR = ADC12_READY;
    251a:	3202      	movi      	r2, 2
    251c:	07f8      	br      	0x250c	// 250c <ADCIntHandler+0x14>
	else if((ADC0->SR&ADC12_OVR)==ADC12_OVR)		//ADC OVR interrupt
    251e:	9348      	ld.w      	r2, (r3, 0x20)
    2520:	e4422004 	andi      	r2, r2, 4
    2524:	3a40      	cmpnei      	r2, 0
    2526:	0c03      	bf      	0x252c	// 252c <ADCIntHandler+0x34>
		ADC0->CSR = ADC12_OVR;
    2528:	3204      	movi      	r2, 4
    252a:	07f1      	br      	0x250c	// 250c <ADCIntHandler+0x14>
	else if((ADC0->SR&ADC12_CMP0H)==ADC12_CMP0H)	//ADC CMP0H interrupt
    252c:	9348      	ld.w      	r2, (r3, 0x20)
    252e:	e4422010 	andi      	r2, r2, 16
    2532:	3a40      	cmpnei      	r2, 0
    2534:	0c03      	bf      	0x253a	// 253a <ADCIntHandler+0x42>
		ADC0->CSR = ADC12_CMP0H;
    2536:	3210      	movi      	r2, 16
    2538:	07ea      	br      	0x250c	// 250c <ADCIntHandler+0x14>
	else if((ADC0->SR&ADC12_CMP0L)==ADC12_CMP0L)	//ADC CMP0L interrupt.
    253a:	9348      	ld.w      	r2, (r3, 0x20)
    253c:	e4422020 	andi      	r2, r2, 32
    2540:	3a40      	cmpnei      	r2, 0
    2542:	0c03      	bf      	0x2548	// 2548 <ADCIntHandler+0x50>
		ADC0->CSR = ADC12_CMP0L;
    2544:	3220      	movi      	r2, 32
    2546:	07e3      	br      	0x250c	// 250c <ADCIntHandler+0x14>
	else if((ADC0->SR&ADC12_CMP1H)==ADC12_CMP1H)	//ADC CMP1H interrupt.
    2548:	9348      	ld.w      	r2, (r3, 0x20)
    254a:	e4422040 	andi      	r2, r2, 64
    254e:	3a40      	cmpnei      	r2, 0
    2550:	0c03      	bf      	0x2556	// 2556 <ADCIntHandler+0x5e>
		ADC0->CSR = ADC12_CMP1H;
    2552:	3240      	movi      	r2, 64
    2554:	07dc      	br      	0x250c	// 250c <ADCIntHandler+0x14>
	else if((ADC0->SR&ADC12_CMP1L)==ADC12_CMP1L)	//ADC CMP1L interrupt.
    2556:	9348      	ld.w      	r2, (r3, 0x20)
    2558:	e4422080 	andi      	r2, r2, 128
    255c:	3a40      	cmpnei      	r2, 0
    255e:	0c03      	bf      	0x2564	// 2564 <ADCIntHandler+0x6c>
		ADC0->CSR = ADC12_CMP1L;
    2560:	3280      	movi      	r2, 128
    2562:	07d5      	br      	0x250c	// 250c <ADCIntHandler+0x14>
	else if((ADC0->SR&ADC12_SEQ_END0)==ADC12_SEQ_END0) //ADC SEQ0 interrupt,SEQ1~SEQ15 replace the parameter with ADC12_SEQ_END1~ADC12_SEQ_END15
    2564:	3280      	movi      	r2, 128
    2566:	9328      	ld.w      	r1, (r3, 0x20)
    2568:	4249      	lsli      	r2, r2, 9
    256a:	6848      	and      	r1, r2
    256c:	3940      	cmpnei      	r1, 0
    256e:	0bcf      	bt      	0x250c	// 250c <ADCIntHandler+0x14>
}
    2570:	1463      	ipop
    2572:	1461      	nir
    2574:	20000090 	.long	0x20000090

Disassembly of section .text.EPT0IntHandler:

00002578 <EPT0IntHandler>:
//EPT0 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EPT0IntHandler(void) 
{
    2578:	1460      	nie
    257a:	1462      	ipush
    257c:	14d1      	push      	r4, r15
    // ISR content ...
	if((EPT0->MISR&EPT_TRGEV0_INT)==EPT_TRGEV0_INT)			//TRGEV0 interrupt
    257e:	0398      	lrw      	r4, 0x20000044	// 2798 <EPT0IntHandler+0x220>
    2580:	9460      	ld.w      	r3, (r4, 0x0)
    2582:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2586:	e4422001 	andi      	r2, r2, 1
    258a:	3a40      	cmpnei      	r2, 0
    258c:	0c05      	bf      	0x2596	// 2596 <EPT0IntHandler+0x1e>
	{
		EPT0->ICR=EPT_TRGEV0_INT;
    258e:	3201      	movi      	r2, 1
	{
		EPT0->ICR=EPT_CDD;
	}
	else if((EPT0->MISR&EPT_PEND)==EPT_PEND)				//End of cycle interrupt
	{
		EPT0->ICR=EPT_PEND;
    2590:	dc432037 	st.w      	r2, (r3, 0xdc)
    2594:	0430      	br      	0x25f4	// 25f4 <EPT0IntHandler+0x7c>
	else if((EPT0->MISR&EPT_TRGEV1_INT)==EPT_TRGEV1_INT)	//TRGEV1 interrupt
    2596:	d8432035 	ld.w      	r2, (r3, 0xd4)
    259a:	e4422002 	andi      	r2, r2, 2
    259e:	3a40      	cmpnei      	r2, 0
    25a0:	0c03      	bf      	0x25a6	// 25a6 <EPT0IntHandler+0x2e>
		EPT0->ICR=EPT_TRGEV1_INT;
    25a2:	3202      	movi      	r2, 2
    25a4:	07f6      	br      	0x2590	// 2590 <EPT0IntHandler+0x18>
	else if((EPT0->MISR&EPT_TRGEV2_INT)==EPT_TRGEV2_INT)	//TRGEV2 interrupt
    25a6:	d8432035 	ld.w      	r2, (r3, 0xd4)
    25aa:	e4422004 	andi      	r2, r2, 4
    25ae:	3a40      	cmpnei      	r2, 0
    25b0:	0c03      	bf      	0x25b6	// 25b6 <EPT0IntHandler+0x3e>
		EPT0->ICR=EPT_TRGEV2_INT;
    25b2:	3204      	movi      	r2, 4
    25b4:	07ee      	br      	0x2590	// 2590 <EPT0IntHandler+0x18>
	else if((EPT0->MISR&EPT_TRGEV3_INT)==EPT_TRGEV3_INT)	//TRGEV3 interrupt
    25b6:	d8432035 	ld.w      	r2, (r3, 0xd4)
    25ba:	e4422008 	andi      	r2, r2, 8
    25be:	3a40      	cmpnei      	r2, 0
    25c0:	0c03      	bf      	0x25c6	// 25c6 <EPT0IntHandler+0x4e>
		EPT0->ICR=EPT_TRGEV3_INT;
    25c2:	3208      	movi      	r2, 8
    25c4:	07e6      	br      	0x2590	// 2590 <EPT0IntHandler+0x18>
	else if((EPT0->MISR&EPT_CAP_LD0)==EPT_CAP_LD0)			//Capture Load to CMPA interrupt
    25c6:	d8432035 	ld.w      	r2, (r3, 0xd4)
    25ca:	e4422010 	andi      	r2, r2, 16
    25ce:	3a40      	cmpnei      	r2, 0
    25d0:	0c22      	bf      	0x2614	// 2614 <EPT0IntHandler+0x9c>
		EPT0->ICR=EPT_CAP_LD0;
    25d2:	3210      	movi      	r2, 16
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIRT);
    25d4:	3102      	movi      	r1, 2
		EPT0->ICR=EPT_CAP_LD0;
    25d6:	dc432037 	st.w      	r2, (r3, 0xdc)
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIRT);
    25da:	3000      	movi      	r0, 0
    25dc:	3200      	movi      	r2, 0
    25de:	e3fffdb3 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIFT);
    25e2:	3201      	movi      	r2, 1
    25e4:	3102      	movi      	r1, 2
    25e6:	3001      	movi      	r0, 1
    25e8:	e3fffdae 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		R_CMPA_BUF=EPT0->CMPA;			//period counter
    25ec:	9460      	ld.w      	r3, (r4, 0x0)
    25ee:	934b      	ld.w      	r2, (r3, 0x2c)
    25f0:	136b      	lrw      	r3, 0x200002ec	// 279c <EPT0IntHandler+0x224>
		R_CMPB_BUF=EPT0->CMPB;			//Duty counter
    25f2:	b340      	st.w      	r2, (r3, 0x0)
	}
	//Emergency interruption
	if((EPT0->EMMISR&EPT_EP0_EMINT)==EPT_EP0_EMINT)			//interrupt flag of EP0 event
    25f4:	9460      	ld.w      	r3, (r4, 0x0)
    25f6:	d843202b 	ld.w      	r2, (r3, 0xac)
    25fa:	e4422001 	andi      	r2, r2, 1
    25fe:	3a40      	cmpnei      	r2, 0
    2600:	0c79      	bf      	0x26f2	// 26f2 <EPT0IntHandler+0x17a>
	{
		EPT0->EMICR=EPT_EP0_EMINT;
    2602:	3201      	movi      	r2, 1
	{
		EPT0->EMICR=EPT_MEM_FAULT_EMINT;
	}
	else if((EPT0->EMMISR&EPT_EOM_FAULT_EMINT)==EPT_EOM_FAULT_EMINT)	//interrupt flag of EOM_FAULT event
	{
		EPT0->EMICR=EPT_EOM_FAULT_EMINT;
    2604:	dc43202d 	st.w      	r2, (r3, 0xb4)
	}
}
    2608:	d9ee2001 	ld.w      	r15, (r14, 0x4)
    260c:	9880      	ld.w      	r4, (r14, 0x0)
    260e:	1402      	addi      	r14, r14, 8
    2610:	1463      	ipop
    2612:	1461      	nir
	else if((EPT0->MISR&EPT_CAP_LD1)==EPT_CAP_LD1)			//Capture Load to CMPB interrupt
    2614:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2618:	e4422020 	andi      	r2, r2, 32
    261c:	3a40      	cmpnei      	r2, 0
    261e:	0c12      	bf      	0x2642	// 2642 <EPT0IntHandler+0xca>
		EPT0->ICR=EPT_CAP_LD1;
    2620:	3220      	movi      	r2, 32
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIRT);
    2622:	3102      	movi      	r1, 2
		EPT0->ICR=EPT_CAP_LD1;
    2624:	dc432037 	st.w      	r2, (r3, 0xdc)
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIRT);
    2628:	3001      	movi      	r0, 1
    262a:	3200      	movi      	r2, 0
    262c:	e3fffd8c 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIFT);
    2630:	3201      	movi      	r2, 1
    2632:	3102      	movi      	r1, 2
    2634:	3000      	movi      	r0, 0
    2636:	e3fffd87 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		R_CMPB_BUF=EPT0->CMPB;			//Duty counter
    263a:	9460      	ld.w      	r3, (r4, 0x0)
    263c:	934c      	ld.w      	r2, (r3, 0x30)
    263e:	1279      	lrw      	r3, 0x200002d4	// 27a0 <EPT0IntHandler+0x228>
    2640:	07d9      	br      	0x25f2	// 25f2 <EPT0IntHandler+0x7a>
	else if((EPT0->MISR&EPT_CAP_LD2)==EPT_CAP_LD2)			//Capture Load to CMPC interrupt
    2642:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2646:	e4422040 	andi      	r2, r2, 64
    264a:	3a40      	cmpnei      	r2, 0
    264c:	0c03      	bf      	0x2652	// 2652 <EPT0IntHandler+0xda>
		EPT0->ICR=EPT_CAP_LD2;
    264e:	3240      	movi      	r2, 64
    2650:	07a0      	br      	0x2590	// 2590 <EPT0IntHandler+0x18>
	else if((EPT0->MISR&EPT_CAP_LD3)==EPT_CAP_LD3)			//Capture Load to CMPD interrupt
    2652:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2656:	e4422080 	andi      	r2, r2, 128
    265a:	3a40      	cmpnei      	r2, 0
    265c:	0c03      	bf      	0x2662	// 2662 <EPT0IntHandler+0xea>
		EPT0->ICR=EPT_CAP_LD3;
    265e:	3280      	movi      	r2, 128
    2660:	0798      	br      	0x2590	// 2590 <EPT0IntHandler+0x18>
	else if((EPT0->MISR&EPT_CAU)==EPT_CAU)					//Up-Counting phase CNT = CMPA interrupt
    2662:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2666:	e4422100 	andi      	r2, r2, 256
    266a:	3a40      	cmpnei      	r2, 0
    266c:	0c04      	bf      	0x2674	// 2674 <EPT0IntHandler+0xfc>
		EPT0->ICR=EPT_CAU;
    266e:	3280      	movi      	r2, 128
    2670:	4241      	lsli      	r2, r2, 1
    2672:	078f      	br      	0x2590	// 2590 <EPT0IntHandler+0x18>
	else if((EPT0->MISR&EPT_CAD)==EPT_CAD)					//Down-Counting phase CNT = CMPA interrupt
    2674:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2678:	e4422200 	andi      	r2, r2, 512
    267c:	3a40      	cmpnei      	r2, 0
    267e:	0c04      	bf      	0x2686	// 2686 <EPT0IntHandler+0x10e>
		EPT0->ICR=EPT_CAD;
    2680:	3280      	movi      	r2, 128
    2682:	4242      	lsli      	r2, r2, 2
    2684:	0786      	br      	0x2590	// 2590 <EPT0IntHandler+0x18>
	else if((EPT0->MISR&EPT_CBU)==EPT_CBU)					//Up-Counting phase CNT = CMPB interrupt 
    2686:	d8432035 	ld.w      	r2, (r3, 0xd4)
    268a:	e4422400 	andi      	r2, r2, 1024
    268e:	3a40      	cmpnei      	r2, 0
    2690:	0c04      	bf      	0x2698	// 2698 <EPT0IntHandler+0x120>
		EPT0->ICR=EPT_CBU;
    2692:	3280      	movi      	r2, 128
    2694:	4243      	lsli      	r2, r2, 3
    2696:	077d      	br      	0x2590	// 2590 <EPT0IntHandler+0x18>
	else if((EPT0->MISR&EPT_CBD)==EPT_CBD)					//Down-Counting phase CNT = CMPB interrupt
    2698:	d8432035 	ld.w      	r2, (r3, 0xd4)
    269c:	e4422800 	andi      	r2, r2, 2048
    26a0:	3a40      	cmpnei      	r2, 0
    26a2:	0c04      	bf      	0x26aa	// 26aa <EPT0IntHandler+0x132>
		EPT0->ICR=EPT_CBD;
    26a4:	3280      	movi      	r2, 128
    26a6:	4244      	lsli      	r2, r2, 4
    26a8:	0774      	br      	0x2590	// 2590 <EPT0IntHandler+0x18>
	else if((EPT0->MISR&EPT_CCU)==EPT_CCU)					//Up-Counting phase CNT = CMPC interrupt 
    26aa:	3280      	movi      	r2, 128
    26ac:	d8232035 	ld.w      	r1, (r3, 0xd4)
    26b0:	4245      	lsli      	r2, r2, 5
    26b2:	6848      	and      	r1, r2
    26b4:	3940      	cmpnei      	r1, 0
    26b6:	0b6d      	bt      	0x2590	// 2590 <EPT0IntHandler+0x18>
	else if((EPT0->MISR&EPT_CCD)==EPT_CCD)					//Down-Counting phase CNT = CMPC interrupt
    26b8:	3280      	movi      	r2, 128
    26ba:	d8232035 	ld.w      	r1, (r3, 0xd4)
    26be:	4246      	lsli      	r2, r2, 6
    26c0:	6848      	and      	r1, r2
    26c2:	3940      	cmpnei      	r1, 0
    26c4:	0b66      	bt      	0x2590	// 2590 <EPT0IntHandler+0x18>
	else if((EPT0->MISR&EPT_CDU)==EPT_CDU)					//Up-Counting phase CNT = CMPD interrupt
    26c6:	3280      	movi      	r2, 128
    26c8:	d8232035 	ld.w      	r1, (r3, 0xd4)
    26cc:	4247      	lsli      	r2, r2, 7
    26ce:	6848      	and      	r1, r2
    26d0:	3940      	cmpnei      	r1, 0
    26d2:	0b5f      	bt      	0x2590	// 2590 <EPT0IntHandler+0x18>
	else if((EPT0->MISR&EPT_CDD)==EPT_CDD)					//Down-Counting phase CNT = CMPD interrupt
    26d4:	3280      	movi      	r2, 128
    26d6:	d8232035 	ld.w      	r1, (r3, 0xd4)
    26da:	4248      	lsli      	r2, r2, 8
    26dc:	6848      	and      	r1, r2
    26de:	3940      	cmpnei      	r1, 0
    26e0:	0b58      	bt      	0x2590	// 2590 <EPT0IntHandler+0x18>
	else if((EPT0->MISR&EPT_PEND)==EPT_PEND)				//End of cycle interrupt
    26e2:	3280      	movi      	r2, 128
    26e4:	d8232035 	ld.w      	r1, (r3, 0xd4)
    26e8:	4249      	lsli      	r2, r2, 9
    26ea:	6848      	and      	r1, r2
    26ec:	3940      	cmpnei      	r1, 0
    26ee:	0f83      	bf      	0x25f4	// 25f4 <EPT0IntHandler+0x7c>
    26f0:	0750      	br      	0x2590	// 2590 <EPT0IntHandler+0x18>
	else if((EPT0->EMMISR&EPT_EP1_EMINT)==EPT_EP1_EMINT)	//interrupt flag of EP1 event
    26f2:	d843202b 	ld.w      	r2, (r3, 0xac)
    26f6:	e4422002 	andi      	r2, r2, 2
    26fa:	3a40      	cmpnei      	r2, 0
    26fc:	0c03      	bf      	0x2702	// 2702 <EPT0IntHandler+0x18a>
		EPT0->EMICR=EPT_EP1_EMINT;
    26fe:	3202      	movi      	r2, 2
    2700:	0782      	br      	0x2604	// 2604 <EPT0IntHandler+0x8c>
	else if((EPT0->EMMISR&EPT_EP2_EMINT)==EPT_EP2_EMINT)	//interrupt flag of EP2 event
    2702:	d843202b 	ld.w      	r2, (r3, 0xac)
    2706:	e4422004 	andi      	r2, r2, 4
    270a:	3a40      	cmpnei      	r2, 0
    270c:	0c03      	bf      	0x2712	// 2712 <EPT0IntHandler+0x19a>
		EPT0->EMICR=EPT_EP2_EMINT;
    270e:	3204      	movi      	r2, 4
    2710:	077a      	br      	0x2604	// 2604 <EPT0IntHandler+0x8c>
	else if((EPT0->EMMISR&EPT_EP3_EMINT)==EPT_EP3_EMINT)	//interrupt flag of EP3 event
    2712:	d843202b 	ld.w      	r2, (r3, 0xac)
    2716:	e4422008 	andi      	r2, r2, 8
    271a:	3a40      	cmpnei      	r2, 0
    271c:	0c03      	bf      	0x2722	// 2722 <EPT0IntHandler+0x1aa>
		EPT0->EMICR=EPT_EP3_EMINT;
    271e:	3208      	movi      	r2, 8
    2720:	0772      	br      	0x2604	// 2604 <EPT0IntHandler+0x8c>
	else if((EPT0->EMMISR&EPT_EP4_EMINT)==EPT_EP4_EMINT)	//interrupt flag of EP4 event
    2722:	d843202b 	ld.w      	r2, (r3, 0xac)
    2726:	e4422010 	andi      	r2, r2, 16
    272a:	3a40      	cmpnei      	r2, 0
    272c:	0c03      	bf      	0x2732	// 2732 <EPT0IntHandler+0x1ba>
		EPT0->EMICR=EPT_EP4_EMINT;
    272e:	3210      	movi      	r2, 16
    2730:	076a      	br      	0x2604	// 2604 <EPT0IntHandler+0x8c>
	else if((EPT0->EMMISR&EPT_EP5_EMINT)==EPT_EP5_EMINT)	//interrupt flag of EP5 event
    2732:	d843202b 	ld.w      	r2, (r3, 0xac)
    2736:	e4422020 	andi      	r2, r2, 32
    273a:	3a40      	cmpnei      	r2, 0
    273c:	0c03      	bf      	0x2742	// 2742 <EPT0IntHandler+0x1ca>
		EPT0->EMICR=EPT_EP5_EMINT;
    273e:	3220      	movi      	r2, 32
    2740:	0762      	br      	0x2604	// 2604 <EPT0IntHandler+0x8c>
	else if((EPT0->EMMISR&EPT_EP6_EMINT)==EPT_EP6_EMINT)	//interrupt flag of EP6 event
    2742:	d843202b 	ld.w      	r2, (r3, 0xac)
    2746:	e4422040 	andi      	r2, r2, 64
    274a:	3a40      	cmpnei      	r2, 0
    274c:	0c03      	bf      	0x2752	// 2752 <EPT0IntHandler+0x1da>
		EPT0->EMICR=EPT_EP6_EMINT;
    274e:	3240      	movi      	r2, 64
    2750:	075a      	br      	0x2604	// 2604 <EPT0IntHandler+0x8c>
	else if((EPT0->EMMISR&EPT_EP7_EMINT)==EPT_EP7_EMINT)	//interrupt flag of EP7 event
    2752:	d843202b 	ld.w      	r2, (r3, 0xac)
    2756:	e4422080 	andi      	r2, r2, 128
    275a:	3a40      	cmpnei      	r2, 0
    275c:	0c03      	bf      	0x2762	// 2762 <EPT0IntHandler+0x1ea>
		EPT0->EMICR=EPT_EP7_EMINT;
    275e:	3280      	movi      	r2, 128
    2760:	0752      	br      	0x2604	// 2604 <EPT0IntHandler+0x8c>
	else if((EPT0->EMMISR&EPT_CPU_FAULT_EMINT)==EPT_CPU_FAULT_EMINT)	//interrupt flag of CPU_FAULT event
    2762:	d843202b 	ld.w      	r2, (r3, 0xac)
    2766:	e4422100 	andi      	r2, r2, 256
    276a:	3a40      	cmpnei      	r2, 0
    276c:	0c04      	bf      	0x2774	// 2774 <EPT0IntHandler+0x1fc>
		EPT0->EMICR=EPT_CPU_FAULT_EMINT;
    276e:	3280      	movi      	r2, 128
    2770:	4241      	lsli      	r2, r2, 1
    2772:	0749      	br      	0x2604	// 2604 <EPT0IntHandler+0x8c>
	else if((EPT0->EMMISR&EPT_MEM_FAULT_EMINT)==EPT_MEM_FAULT_EMINT)	//interrupt flag of MEM_FAULT event
    2774:	d843202b 	ld.w      	r2, (r3, 0xac)
    2778:	e4422200 	andi      	r2, r2, 512
    277c:	3a40      	cmpnei      	r2, 0
    277e:	0c04      	bf      	0x2786	// 2786 <EPT0IntHandler+0x20e>
		EPT0->EMICR=EPT_MEM_FAULT_EMINT;
    2780:	3280      	movi      	r2, 128
    2782:	4242      	lsli      	r2, r2, 2
    2784:	0740      	br      	0x2604	// 2604 <EPT0IntHandler+0x8c>
	else if((EPT0->EMMISR&EPT_EOM_FAULT_EMINT)==EPT_EOM_FAULT_EMINT)	//interrupt flag of EOM_FAULT event
    2786:	d843202b 	ld.w      	r2, (r3, 0xac)
    278a:	e4422400 	andi      	r2, r2, 1024
    278e:	3a40      	cmpnei      	r2, 0
    2790:	0f3c      	bf      	0x2608	// 2608 <EPT0IntHandler+0x90>
		EPT0->EMICR=EPT_EOM_FAULT_EMINT;
    2792:	3280      	movi      	r2, 128
    2794:	4243      	lsli      	r2, r2, 3
    2796:	0737      	br      	0x2604	// 2604 <EPT0IntHandler+0x8c>
    2798:	20000044 	.long	0x20000044
    279c:	200002ec 	.long	0x200002ec
    27a0:	200002d4 	.long	0x200002d4

Disassembly of section .text.WWDTIntHandler:

000027a4 <WWDTIntHandler>:
//WWDT Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void WWDTIntHandler(void)
{
    27a4:	1460      	nie
    27a6:	1462      	ipush
    27a8:	14d2      	push      	r4-r5, r15
	WWDT->ICR=0X01;
    27aa:	1091      	lrw      	r4, 0x20000034	// 27ec <WWDTIntHandler+0x48>
    27ac:	3201      	movi      	r2, 1
    27ae:	9460      	ld.w      	r3, (r4, 0x0)
	WWDT_CNT_Load(0xFF);
    27b0:	30ff      	movi      	r0, 255
	WWDT->ICR=0X01;
    27b2:	b345      	st.w      	r2, (r3, 0x14)
	GPIO_Init(GPIOA0,4,0);
    27b4:	10af      	lrw      	r5, 0x20000088	// 27f0 <WWDTIntHandler+0x4c>
	WWDT_CNT_Load(0xFF);
    27b6:	e3fffced 	bsr      	0x2190	// 2190 <WWDT_CNT_Load>
	GPIO_Init(GPIOA0,4,0);
    27ba:	3200      	movi      	r2, 0
    27bc:	3104      	movi      	r1, 4
    27be:	9500      	ld.w      	r0, (r5, 0x0)
    27c0:	e3fff908 	bsr      	0x19d0	// 19d0 <GPIO_Init>
	GPIO_Reverse(GPIOA0,4);
    27c4:	9500      	ld.w      	r0, (r5, 0x0)
    27c6:	3104      	movi      	r1, 4
    27c8:	e3fff976 	bsr      	0x1ab4	// 1ab4 <GPIO_Reverse>
	
	if((WWDT->MISR&WWDT_EVI)==WWDT_EVI)
    27cc:	9440      	ld.w      	r2, (r4, 0x0)
    27ce:	9263      	ld.w      	r3, (r2, 0xc)
    27d0:	e4632001 	andi      	r3, r3, 1
    27d4:	3b40      	cmpnei      	r3, 0
    27d6:	0c03      	bf      	0x27dc	// 27dc <WWDTIntHandler+0x38>
	{
		WWDT->ICR = WWDT_EVI;
    27d8:	3301      	movi      	r3, 1
    27da:	b265      	st.w      	r3, (r2, 0x14)
	} 
}
    27dc:	d9ee2002 	ld.w      	r15, (r14, 0x8)
    27e0:	98a1      	ld.w      	r5, (r14, 0x4)
    27e2:	9880      	ld.w      	r4, (r14, 0x0)
    27e4:	1403      	addi      	r14, r14, 12
    27e6:	1463      	ipop
    27e8:	1461      	nir
    27ea:	0000      	bkpt
    27ec:	20000034 	.long	0x20000034
    27f0:	20000088 	.long	0x20000088

Disassembly of section .text.DMAIntHandler:

000027f4 <DMAIntHandler>:
//DMA Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void DMAIntHandler(void)
{
    27f4:	1460      	nie
    27f6:	1462      	ipush
	 // ISR content ...
	if((DMA->ISR&DMA0_LTCIT)==DMA0_LTCIT)			//CH0 L 完成
    27f8:	116a      	lrw      	r3, 0x20000014	// 28a0 <DMAIntHandler+0xac>
    27fa:	9360      	ld.w      	r3, (r3, 0x0)
    27fc:	d8432143 	ld.w      	r2, (r3, 0x50c)
    2800:	e4422001 	andi      	r2, r2, 1
    2804:	3a40      	cmpnei      	r2, 0
    2806:	0c05      	bf      	0x2810	// 2810 <DMAIntHandler+0x1c>
	{
		nop;
    2808:	6c03      	mov      	r0, r0
		DMA->ICR=DMA0_LTCIT;
    280a:	3201      	movi      	r2, 1
    280c:	dc432144 	st.w      	r2, (r3, 0x510)
	}	
	if((DMA->ISR&DMA1_LTCIT)==DMA1_LTCIT)			//CH1 L 完成
    2810:	d8432143 	ld.w      	r2, (r3, 0x50c)
    2814:	e4422002 	andi      	r2, r2, 2
    2818:	3a40      	cmpnei      	r2, 0
    281a:	0c05      	bf      	0x2824	// 2824 <DMAIntHandler+0x30>
	{
		nop;
    281c:	6c03      	mov      	r0, r0
		DMA->ICR=DMA1_LTCIT;
    281e:	3202      	movi      	r2, 2
    2820:	dc432144 	st.w      	r2, (r3, 0x510)
	}
	if((DMA->ISR&DMA2_LTCIT)==DMA2_LTCIT)			//CH2 L 完成
    2824:	d8432143 	ld.w      	r2, (r3, 0x50c)
    2828:	e4422004 	andi      	r2, r2, 4
    282c:	3a40      	cmpnei      	r2, 0
    282e:	0c05      	bf      	0x2838	// 2838 <DMAIntHandler+0x44>
	{
		nop;
    2830:	6c03      	mov      	r0, r0
		DMA->ICR=DMA2_LTCIT;
    2832:	3204      	movi      	r2, 4
    2834:	dc432144 	st.w      	r2, (r3, 0x510)
	}
	if((DMA->ISR&DMA3_LTCIT)==DMA3_LTCIT)			//CH3 L 完成
    2838:	d8432143 	ld.w      	r2, (r3, 0x50c)
    283c:	e4422008 	andi      	r2, r2, 8
    2840:	3a40      	cmpnei      	r2, 0
    2842:	0c05      	bf      	0x284c	// 284c <DMAIntHandler+0x58>
	{
		nop;
    2844:	6c03      	mov      	r0, r0
		DMA->ICR=DMA3_LTCIT;
    2846:	3208      	movi      	r2, 8
    2848:	dc432144 	st.w      	r2, (r3, 0x510)
	}
	if((DMA->ISR&DMA0_TCIT)==DMA0_TCIT)				//CH0 L H 完成	
    284c:	3280      	movi      	r2, 128
    284e:	d8232143 	ld.w      	r1, (r3, 0x50c)
    2852:	4249      	lsli      	r2, r2, 9
    2854:	6848      	and      	r1, r2
    2856:	3940      	cmpnei      	r1, 0
    2858:	0c04      	bf      	0x2860	// 2860 <DMAIntHandler+0x6c>
	{
		nop;
    285a:	6c03      	mov      	r0, r0
		DMA->ICR=DMA0_TCIT;
    285c:	dc432144 	st.w      	r2, (r3, 0x510)
	}
	if((DMA->ISR&DMA1_TCIT)==DMA1_TCIT)				//CH1 L H 完成	
    2860:	3280      	movi      	r2, 128
    2862:	d8232143 	ld.w      	r1, (r3, 0x50c)
    2866:	424a      	lsli      	r2, r2, 10
    2868:	6848      	and      	r1, r2
    286a:	3940      	cmpnei      	r1, 0
    286c:	0c04      	bf      	0x2874	// 2874 <DMAIntHandler+0x80>
	{
		nop;
    286e:	6c03      	mov      	r0, r0
		DMA->ICR=DMA1_TCIT;
    2870:	dc432144 	st.w      	r2, (r3, 0x510)
	}
	if((DMA->ISR&DMA2_TCIT)==DMA2_TCIT)				//CH2 L H 完成	
    2874:	3280      	movi      	r2, 128
    2876:	d8232143 	ld.w      	r1, (r3, 0x50c)
    287a:	424b      	lsli      	r2, r2, 11
    287c:	6848      	and      	r1, r2
    287e:	3940      	cmpnei      	r1, 0
    2880:	0c04      	bf      	0x2888	// 2888 <DMAIntHandler+0x94>
	{
		nop;
    2882:	6c03      	mov      	r0, r0
		DMA->ICR=DMA2_TCIT;
    2884:	dc432144 	st.w      	r2, (r3, 0x510)
	}
	if((DMA->ISR&DMA3_TCIT)==DMA3_TCIT)				//CH3 L H 完成	
    2888:	3280      	movi      	r2, 128
    288a:	d8232143 	ld.w      	r1, (r3, 0x50c)
    288e:	424c      	lsli      	r2, r2, 12
    2890:	6848      	and      	r1, r2
    2892:	3940      	cmpnei      	r1, 0
    2894:	0c04      	bf      	0x289c	// 289c <DMAIntHandler+0xa8>
	{
		nop;
    2896:	6c03      	mov      	r0, r0
		DMA->ICR=DMA3_TCIT;
    2898:	dc432144 	st.w      	r2, (r3, 0x510)
	}
}
    289c:	1463      	ipop
    289e:	1461      	nir
    28a0:	20000014 	.long	0x20000014

Disassembly of section .text.GPTA0IntHandler:

000028a4 <GPTA0IntHandler>:
//GPTA0 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void GPTA0IntHandler(void) 
{
    28a4:	1460      	nie
    28a6:	1462      	ipush
    28a8:	14d1      	push      	r4, r15
    // ISR content ...
	if((GPTA0->MISR&GPT_TRGEV0_INT)==GPT_TRGEV0_INT)			//TRGEV0 interrupt
    28aa:	119b      	lrw      	r4, 0x20000054	// 2994 <GPTA0IntHandler+0xf0>
    28ac:	9460      	ld.w      	r3, (r4, 0x0)
    28ae:	d8432035 	ld.w      	r2, (r3, 0xd4)
    28b2:	e4422001 	andi      	r2, r2, 1
    28b6:	3a40      	cmpnei      	r2, 0
    28b8:	0c05      	bf      	0x28c2	// 28c2 <GPTA0IntHandler+0x1e>
	{
		GPTA0->ICR = GPT_TRGEV0_INT;
    28ba:	3201      	movi      	r2, 1
	{
		GPTA0->ICR = GPT_CBD;
	}
	else if((GPTA0->MISR&GPT_PEND)==GPT_PEND)		//End of cycle interrupt 
	{
		GPTA0->ICR = GPT_PEND;
    28bc:	dc432037 	st.w      	r2, (r3, 0xdc)
	}
}
    28c0:	0420      	br      	0x2900	// 2900 <GPTA0IntHandler+0x5c>
	else if((GPTA0->MISR&GPT_TRGEV1_INT)==GPT_TRGEV1_INT)	//TRGEV1 interrupt
    28c2:	d8432035 	ld.w      	r2, (r3, 0xd4)
    28c6:	e4422002 	andi      	r2, r2, 2
    28ca:	3a40      	cmpnei      	r2, 0
    28cc:	0c03      	bf      	0x28d2	// 28d2 <GPTA0IntHandler+0x2e>
		GPTA0->ICR = GPT_TRGEV1_INT;
    28ce:	3202      	movi      	r2, 2
    28d0:	07f6      	br      	0x28bc	// 28bc <GPTA0IntHandler+0x18>
	else if((GPTA0->MISR&GPT_CAP_LD0)==GPT_CAP_LD0)		//Capture Load to CMPA interrupt
    28d2:	d8432035 	ld.w      	r2, (r3, 0xd4)
    28d6:	e4422010 	andi      	r2, r2, 16
    28da:	3a40      	cmpnei      	r2, 0
    28dc:	0c18      	bf      	0x290c	// 290c <GPTA0IntHandler+0x68>
		GPTA0->ICR = GPT_CAP_LD0;
    28de:	3210      	movi      	r2, 16
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIRT);
    28e0:	3102      	movi      	r1, 2
		GPTA0->ICR = GPT_CAP_LD0;
    28e2:	dc432037 	st.w      	r2, (r3, 0xdc)
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIRT);
    28e6:	3000      	movi      	r0, 0
    28e8:	3200      	movi      	r2, 0
    28ea:	e3fffc2d 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIFT);
    28ee:	3201      	movi      	r2, 1
    28f0:	3102      	movi      	r1, 2
    28f2:	3001      	movi      	r0, 1
    28f4:	e3fffc28 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		R_CMPA_BUF=GPTA0->CMPA;			//period counter
    28f8:	9460      	ld.w      	r3, (r4, 0x0)
    28fa:	934b      	ld.w      	r2, (r3, 0x2c)
    28fc:	1167      	lrw      	r3, 0x200002ec	// 2998 <GPTA0IntHandler+0xf4>
		R_CMPB_BUF=GPTA0->CMPB;			//Duty counter
    28fe:	b340      	st.w      	r2, (r3, 0x0)
}
    2900:	d9ee2001 	ld.w      	r15, (r14, 0x4)
    2904:	9880      	ld.w      	r4, (r14, 0x0)
    2906:	1402      	addi      	r14, r14, 8
    2908:	1463      	ipop
    290a:	1461      	nir
	else if((GPTA0->MISR&GPT_CAP_LD1)==GPT_CAP_LD1)		//Capture Load to CMPB interrupt
    290c:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2910:	e4422020 	andi      	r2, r2, 32
    2914:	3a40      	cmpnei      	r2, 0
    2916:	0c12      	bf      	0x293a	// 293a <GPTA0IntHandler+0x96>
		GPTA0->ICR = GPT_CAP_LD1;
    2918:	3220      	movi      	r2, 32
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIRT);
    291a:	3102      	movi      	r1, 2
		GPTA0->ICR = GPT_CAP_LD1;
    291c:	dc432037 	st.w      	r2, (r3, 0xdc)
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIRT);
    2920:	3001      	movi      	r0, 1
    2922:	3200      	movi      	r2, 0
    2924:	e3fffc10 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIFT);
    2928:	3201      	movi      	r2, 1
    292a:	3102      	movi      	r1, 2
    292c:	3000      	movi      	r0, 0
    292e:	e3fffc0b 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		R_CMPB_BUF=GPTA0->CMPB;			//Duty counter
    2932:	9460      	ld.w      	r3, (r4, 0x0)
    2934:	934c      	ld.w      	r2, (r3, 0x30)
    2936:	107a      	lrw      	r3, 0x200002d4	// 299c <GPTA0IntHandler+0xf8>
    2938:	07e3      	br      	0x28fe	// 28fe <GPTA0IntHandler+0x5a>
	else if((GPTA0->MISR&GPT_CAU)==GPT_CAU)			//Up-Counting phase CNT = CMPA Interrupt
    293a:	d8432035 	ld.w      	r2, (r3, 0xd4)
    293e:	e4422100 	andi      	r2, r2, 256
    2942:	3a40      	cmpnei      	r2, 0
    2944:	0c04      	bf      	0x294c	// 294c <GPTA0IntHandler+0xa8>
		GPTA0->ICR = GPT_CAU;
    2946:	3280      	movi      	r2, 128
    2948:	4241      	lsli      	r2, r2, 1
    294a:	07b9      	br      	0x28bc	// 28bc <GPTA0IntHandler+0x18>
	else if((GPTA0->MISR&GPT_CAD)==GPT_CAD)			//Down-Counting phase CNT = CMPA Interrupt
    294c:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2950:	e4422200 	andi      	r2, r2, 512
    2954:	3a40      	cmpnei      	r2, 0
    2956:	0c04      	bf      	0x295e	// 295e <GPTA0IntHandler+0xba>
		GPTA0->ICR = GPT_CAD;
    2958:	3280      	movi      	r2, 128
    295a:	4242      	lsli      	r2, r2, 2
    295c:	07b0      	br      	0x28bc	// 28bc <GPTA0IntHandler+0x18>
	else if((GPTA0->MISR&GPT_CBU)==GPT_CBU)			//Up-Counting phase CNT = CMPB Interrupt
    295e:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2962:	e4422400 	andi      	r2, r2, 1024
    2966:	3a40      	cmpnei      	r2, 0
    2968:	0c04      	bf      	0x2970	// 2970 <GPTA0IntHandler+0xcc>
		GPTA0->ICR = GPT_CBU;
    296a:	3280      	movi      	r2, 128
    296c:	4243      	lsli      	r2, r2, 3
    296e:	07a7      	br      	0x28bc	// 28bc <GPTA0IntHandler+0x18>
	else if((GPTA0->MISR&GPT_CBD)==GPT_CBD)			//Down-Counting phase CNT = CMPB Interrupt
    2970:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2974:	e4422800 	andi      	r2, r2, 2048
    2978:	3a40      	cmpnei      	r2, 0
    297a:	0c04      	bf      	0x2982	// 2982 <GPTA0IntHandler+0xde>
		GPTA0->ICR = GPT_CBD;
    297c:	3280      	movi      	r2, 128
    297e:	4244      	lsli      	r2, r2, 4
    2980:	079e      	br      	0x28bc	// 28bc <GPTA0IntHandler+0x18>
	else if((GPTA0->MISR&GPT_PEND)==GPT_PEND)		//End of cycle interrupt 
    2982:	3280      	movi      	r2, 128
    2984:	d8232035 	ld.w      	r1, (r3, 0xd4)
    2988:	4249      	lsli      	r2, r2, 9
    298a:	6848      	and      	r1, r2
    298c:	3940      	cmpnei      	r1, 0
    298e:	0b97      	bt      	0x28bc	// 28bc <GPTA0IntHandler+0x18>
    2990:	07b8      	br      	0x2900	// 2900 <GPTA0IntHandler+0x5c>
    2992:	0000      	bkpt
    2994:	20000054 	.long	0x20000054
    2998:	200002ec 	.long	0x200002ec
    299c:	200002d4 	.long	0x200002d4

Disassembly of section .text.GPTA1IntHandler:

000029a0 <GPTA1IntHandler>:
//GPTA1 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void GPTA1IntHandler(void) 
{
    29a0:	1460      	nie
    29a2:	1462      	ipush
    29a4:	14d1      	push      	r4, r15
	 // ISR content ...
	if((GPTA1->MISR&GPT_TRGEV0_INT)==GPT_TRGEV0_INT)			//TRGEV0 interrupt
    29a6:	119b      	lrw      	r4, 0x20000050	// 2a90 <GPTA1IntHandler+0xf0>
    29a8:	9460      	ld.w      	r3, (r4, 0x0)
    29aa:	d8432035 	ld.w      	r2, (r3, 0xd4)
    29ae:	e4422001 	andi      	r2, r2, 1
    29b2:	3a40      	cmpnei      	r2, 0
    29b4:	0c05      	bf      	0x29be	// 29be <GPTA1IntHandler+0x1e>
	{
		GPTA1->ICR = GPT_TRGEV0_INT;
    29b6:	3201      	movi      	r2, 1
	{
		GPTA1->ICR = GPT_CBD;
	}
	else if((GPTA1->MISR&GPT_PEND)==GPT_PEND)		//End of cycle interrupt 
	{
		GPTA1->ICR = GPT_PEND;
    29b8:	dc432037 	st.w      	r2, (r3, 0xdc)
	}
}
    29bc:	0420      	br      	0x29fc	// 29fc <GPTA1IntHandler+0x5c>
	else if((GPTA1->MISR&GPT_TRGEV1_INT)==GPT_TRGEV1_INT)	//TRGEV1 interrupt
    29be:	d8432035 	ld.w      	r2, (r3, 0xd4)
    29c2:	e4422002 	andi      	r2, r2, 2
    29c6:	3a40      	cmpnei      	r2, 0
    29c8:	0c03      	bf      	0x29ce	// 29ce <GPTA1IntHandler+0x2e>
		GPTA1->ICR = GPT_TRGEV1_INT;
    29ca:	3202      	movi      	r2, 2
    29cc:	07f6      	br      	0x29b8	// 29b8 <GPTA1IntHandler+0x18>
	else if((GPTA1->MISR&GPT_CAP_LD0)==GPT_CAP_LD0)		//Capture Load to CMPA interrupt
    29ce:	d8432035 	ld.w      	r2, (r3, 0xd4)
    29d2:	e4422010 	andi      	r2, r2, 16
    29d6:	3a40      	cmpnei      	r2, 0
    29d8:	0c18      	bf      	0x2a08	// 2a08 <GPTA1IntHandler+0x68>
		GPTA1->ICR = GPT_CAP_LD0;
    29da:	3210      	movi      	r2, 16
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIRT);
    29dc:	3102      	movi      	r1, 2
		GPTA1->ICR = GPT_CAP_LD0;
    29de:	dc432037 	st.w      	r2, (r3, 0xdc)
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIRT);
    29e2:	3000      	movi      	r0, 0
    29e4:	3200      	movi      	r2, 0
    29e6:	e3fffbaf 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIFT);
    29ea:	3201      	movi      	r2, 1
    29ec:	3102      	movi      	r1, 2
    29ee:	3001      	movi      	r0, 1
    29f0:	e3fffbaa 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		R_CMPA_BUF=GPTA1->CMPA;			//period counter
    29f4:	9460      	ld.w      	r3, (r4, 0x0)
    29f6:	934b      	ld.w      	r2, (r3, 0x2c)
    29f8:	1167      	lrw      	r3, 0x200002ec	// 2a94 <GPTA1IntHandler+0xf4>
		R_CMPB_BUF=GPTA1->CMPB;			//Duty counter
    29fa:	b340      	st.w      	r2, (r3, 0x0)
}
    29fc:	d9ee2001 	ld.w      	r15, (r14, 0x4)
    2a00:	9880      	ld.w      	r4, (r14, 0x0)
    2a02:	1402      	addi      	r14, r14, 8
    2a04:	1463      	ipop
    2a06:	1461      	nir
	else if((GPTA1->MISR&GPT_CAP_LD1)==GPT_CAP_LD1)		//Capture Load to CMPB interrupt
    2a08:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2a0c:	e4422020 	andi      	r2, r2, 32
    2a10:	3a40      	cmpnei      	r2, 0
    2a12:	0c12      	bf      	0x2a36	// 2a36 <GPTA1IntHandler+0x96>
		GPTA1->ICR = GPT_CAP_LD1;
    2a14:	3220      	movi      	r2, 32
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIRT);
    2a16:	3102      	movi      	r1, 2
		GPTA1->ICR = GPT_CAP_LD1;
    2a18:	dc432037 	st.w      	r2, (r3, 0xdc)
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIRT);
    2a1c:	3001      	movi      	r0, 1
    2a1e:	3200      	movi      	r2, 0
    2a20:	e3fffb92 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIFT);
    2a24:	3201      	movi      	r2, 1
    2a26:	3102      	movi      	r1, 2
    2a28:	3000      	movi      	r0, 0
    2a2a:	e3fffb8d 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		R_CMPB_BUF=GPTA1->CMPB;			//Duty counter
    2a2e:	9460      	ld.w      	r3, (r4, 0x0)
    2a30:	934c      	ld.w      	r2, (r3, 0x30)
    2a32:	107a      	lrw      	r3, 0x200002d4	// 2a98 <GPTA1IntHandler+0xf8>
    2a34:	07e3      	br      	0x29fa	// 29fa <GPTA1IntHandler+0x5a>
	else if((GPTA1->MISR&GPT_CAU)==GPT_CAU)			//Up-Counting phase CNT = CMPA Interrupt
    2a36:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2a3a:	e4422100 	andi      	r2, r2, 256
    2a3e:	3a40      	cmpnei      	r2, 0
    2a40:	0c04      	bf      	0x2a48	// 2a48 <GPTA1IntHandler+0xa8>
		GPTA1->ICR = GPT_CAU;
    2a42:	3280      	movi      	r2, 128
    2a44:	4241      	lsli      	r2, r2, 1
    2a46:	07b9      	br      	0x29b8	// 29b8 <GPTA1IntHandler+0x18>
	else if((GPTA1->MISR&GPT_CAD)==GPT_CAD)			//Down-Counting phase CNT = CMPA Interrupt
    2a48:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2a4c:	e4422200 	andi      	r2, r2, 512
    2a50:	3a40      	cmpnei      	r2, 0
    2a52:	0c04      	bf      	0x2a5a	// 2a5a <GPTA1IntHandler+0xba>
		GPTA1->ICR = GPT_CAD;
    2a54:	3280      	movi      	r2, 128
    2a56:	4242      	lsli      	r2, r2, 2
    2a58:	07b0      	br      	0x29b8	// 29b8 <GPTA1IntHandler+0x18>
	else if((GPTA1->MISR&GPT_CBU)==GPT_CBU)			//Up-Counting phase CNT = CMPB Interrupt
    2a5a:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2a5e:	e4422400 	andi      	r2, r2, 1024
    2a62:	3a40      	cmpnei      	r2, 0
    2a64:	0c04      	bf      	0x2a6c	// 2a6c <GPTA1IntHandler+0xcc>
		GPTA1->ICR = GPT_CBU;
    2a66:	3280      	movi      	r2, 128
    2a68:	4243      	lsli      	r2, r2, 3
    2a6a:	07a7      	br      	0x29b8	// 29b8 <GPTA1IntHandler+0x18>
	else if((GPTA1->MISR&GPT_CBD)==GPT_CBD)			//Down-Counting phase CNT = CMPB Interrupt
    2a6c:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2a70:	e4422800 	andi      	r2, r2, 2048
    2a74:	3a40      	cmpnei      	r2, 0
    2a76:	0c04      	bf      	0x2a7e	// 2a7e <GPTA1IntHandler+0xde>
		GPTA1->ICR = GPT_CBD;
    2a78:	3280      	movi      	r2, 128
    2a7a:	4244      	lsli      	r2, r2, 4
    2a7c:	079e      	br      	0x29b8	// 29b8 <GPTA1IntHandler+0x18>
	else if((GPTA1->MISR&GPT_PEND)==GPT_PEND)		//End of cycle interrupt 
    2a7e:	3280      	movi      	r2, 128
    2a80:	d8232035 	ld.w      	r1, (r3, 0xd4)
    2a84:	4249      	lsli      	r2, r2, 9
    2a86:	6848      	and      	r1, r2
    2a88:	3940      	cmpnei      	r1, 0
    2a8a:	0b97      	bt      	0x29b8	// 29b8 <GPTA1IntHandler+0x18>
    2a8c:	07b8      	br      	0x29fc	// 29fc <GPTA1IntHandler+0x5c>
    2a8e:	0000      	bkpt
    2a90:	20000050 	.long	0x20000050
    2a94:	200002ec 	.long	0x200002ec
    2a98:	200002d4 	.long	0x200002d4

Disassembly of section .text.GPTB0IntHandler:

00002a9c <GPTB0IntHandler>:
//GPTB0 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void GPTB0IntHandler(void) 
{
    2a9c:	1460      	nie
    2a9e:	1462      	ipush
    2aa0:	14d1      	push      	r4, r15
	buzz_cnt++;
    2aa2:	1340      	lrw      	r2, 0x200000c2	// 2c20 <GPTB0IntHandler+0x184>
    2aa4:	8a60      	ld.h      	r3, (r2, 0x0)
    2aa6:	2300      	addi      	r3, 1
    2aa8:	74cd      	zexth      	r3, r3
	if(buzz_cnt>199)
    2aaa:	eb0300c7 	cmphsi      	r3, 200
    2aae:	080e      	bt      	0x2aca	// 2aca <GPTB0IntHandler+0x2e>
	buzz_cnt++;
    2ab0:	aa60      	st.h      	r3, (r2, 0x0)
	{
		buzz_cnt=0;
		buzz_on_f=1;
	}
	if((GPTB0->MISR&GPT_TRGEV0_INT)==GPT_TRGEV0_INT)			//TRGEV0 interrupt
    2ab2:	129d      	lrw      	r4, 0x2000004c	// 2c24 <GPTB0IntHandler+0x188>
    2ab4:	9460      	ld.w      	r3, (r4, 0x0)
    2ab6:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2aba:	e4422001 	andi      	r2, r2, 1
    2abe:	3a40      	cmpnei      	r2, 0
    2ac0:	0c0a      	bf      	0x2ad4	// 2ad4 <GPTB0IntHandler+0x38>
	{
		GPTB0->ICR = GPT_TRGEV0_INT;
    2ac2:	3201      	movi      	r2, 1
	{
		GPTB0->ICR = GPT_CBD;
	}
	else if((GPTB0->MISR&GPT_PEND)==GPT_PEND)		//End of cycle interrupt 
	{
		GPTB0->ICR = GPT_PEND;
    2ac4:	dc432037 	st.w      	r2, (r3, 0xdc)
    2ac8:	0425      	br      	0x2b12	// 2b12 <GPTB0IntHandler+0x76>
		buzz_cnt=0;
    2aca:	3300      	movi      	r3, 0
    2acc:	aa60      	st.h      	r3, (r2, 0x0)
		buzz_on_f=1;
    2ace:	3301      	movi      	r3, 1
    2ad0:	a262      	st.b      	r3, (r2, 0x2)
    2ad2:	07f0      	br      	0x2ab2	// 2ab2 <GPTB0IntHandler+0x16>
	else if((GPTB0->MISR&GPT_TRGEV1_INT)==GPT_TRGEV1_INT)	//TRGEV1 interrupt
    2ad4:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2ad8:	e4422002 	andi      	r2, r2, 2
    2adc:	3a40      	cmpnei      	r2, 0
    2ade:	0c03      	bf      	0x2ae4	// 2ae4 <GPTB0IntHandler+0x48>
		GPTB0->ICR = GPT_TRGEV1_INT;
    2ae0:	3202      	movi      	r2, 2
    2ae2:	07f1      	br      	0x2ac4	// 2ac4 <GPTB0IntHandler+0x28>
	else if((GPTB0->MISR&GPT_CAP_LD0)==GPT_CAP_LD0)		//Capture Load to CMPA interrupt
    2ae4:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2ae8:	e4422010 	andi      	r2, r2, 16
    2aec:	3a40      	cmpnei      	r2, 0
    2aee:	0c22      	bf      	0x2b32	// 2b32 <GPTB0IntHandler+0x96>
		GPTB0->ICR = GPT_CAP_LD0;
    2af0:	3210      	movi      	r2, 16
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIRT);
    2af2:	3102      	movi      	r1, 2
		GPTB0->ICR = GPT_CAP_LD0;
    2af4:	dc432037 	st.w      	r2, (r3, 0xdc)
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIRT);
    2af8:	3000      	movi      	r0, 0
    2afa:	3200      	movi      	r2, 0
    2afc:	e3fffb24 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIFT);
    2b00:	3201      	movi      	r2, 1
    2b02:	3102      	movi      	r1, 2
    2b04:	3001      	movi      	r0, 1
    2b06:	e3fffb1f 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		R_CMPA_BUF=GPTB0->CMPA;			//period counter
    2b0a:	9460      	ld.w      	r3, (r4, 0x0)
    2b0c:	934b      	ld.w      	r2, (r3, 0x2c)
    2b0e:	1267      	lrw      	r3, 0x200002ec	// 2c28 <GPTB0IntHandler+0x18c>
		R_CMPB_BUF=GPTB0->CMPB;			//Duty counter
    2b10:	b340      	st.w      	r2, (r3, 0x0)
	}
	//Emergency interruption
	if((GPTB0->EMMISR&GPT_EP0_EMINT)==GPT_EP0_EMINT)			//interrupt flag of EP0 event
    2b12:	9460      	ld.w      	r3, (r4, 0x0)
    2b14:	d843202b 	ld.w      	r2, (r3, 0xac)
    2b18:	e4422001 	andi      	r2, r2, 1
    2b1c:	3a40      	cmpnei      	r2, 0
    2b1e:	0c4d      	bf      	0x2bb8	// 2bb8 <GPTB0IntHandler+0x11c>
	{
		GPTB0->EMICR=GPT_EP0_EMINT;
    2b20:	3201      	movi      	r2, 1
	{
		GPTB0->EMICR=GPT_MEM_FAULT_EMINT;
	}
	else if((GPTB0->EMMISR&GPT_EOM_FAULT_EMINT)==GPT_EOM_FAULT_EMINT)	//interrupt flag of EOM_FAULT event
	{
		GPTB0->EMICR=GPT_EOM_FAULT_EMINT;
    2b22:	dc43202d 	st.w      	r2, (r3, 0xb4)
	}
}
    2b26:	d9ee2001 	ld.w      	r15, (r14, 0x4)
    2b2a:	9880      	ld.w      	r4, (r14, 0x0)
    2b2c:	1402      	addi      	r14, r14, 8
    2b2e:	1463      	ipop
    2b30:	1461      	nir
	else if((GPTB0->MISR&GPT_CAP_LD1)==GPT_CAP_LD1)		//Capture Load to CMPB interrupt
    2b32:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2b36:	e4422020 	andi      	r2, r2, 32
    2b3a:	3a40      	cmpnei      	r2, 0
    2b3c:	0c12      	bf      	0x2b60	// 2b60 <GPTB0IntHandler+0xc4>
		GPTB0->ICR = GPT_CAP_LD1;
    2b3e:	3220      	movi      	r2, 32
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIRT);
    2b40:	3102      	movi      	r1, 2
		GPTB0->ICR = GPT_CAP_LD1;
    2b42:	dc432037 	st.w      	r2, (r3, 0xdc)
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIRT);
    2b46:	3001      	movi      	r0, 1
    2b48:	3200      	movi      	r2, 0
    2b4a:	e3fffafd 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIFT);
    2b4e:	3201      	movi      	r2, 1
    2b50:	3102      	movi      	r1, 2
    2b52:	3000      	movi      	r0, 0
    2b54:	e3fffaf8 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		R_CMPB_BUF=GPTB0->CMPB;			//Duty counter
    2b58:	9460      	ld.w      	r3, (r4, 0x0)
    2b5a:	934c      	ld.w      	r2, (r3, 0x30)
    2b5c:	1174      	lrw      	r3, 0x200002d4	// 2c2c <GPTB0IntHandler+0x190>
    2b5e:	07d9      	br      	0x2b10	// 2b10 <GPTB0IntHandler+0x74>
	else if((GPTB0->MISR&GPT_CAU)==GPT_CAU)			//Up-Counting phase CNT = CMPA Interrupt
    2b60:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2b64:	e4422100 	andi      	r2, r2, 256
    2b68:	3a40      	cmpnei      	r2, 0
    2b6a:	0c04      	bf      	0x2b72	// 2b72 <GPTB0IntHandler+0xd6>
		GPTB0->ICR = GPT_CAU;
    2b6c:	3280      	movi      	r2, 128
    2b6e:	4241      	lsli      	r2, r2, 1
    2b70:	07aa      	br      	0x2ac4	// 2ac4 <GPTB0IntHandler+0x28>
	else if((GPTB0->MISR&GPT_CAD)==GPT_CAD)			//Down-Counting phase CNT = CMPA Interrupt
    2b72:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2b76:	e4422200 	andi      	r2, r2, 512
    2b7a:	3a40      	cmpnei      	r2, 0
    2b7c:	0c04      	bf      	0x2b84	// 2b84 <GPTB0IntHandler+0xe8>
		GPTB0->ICR = GPT_CAD;
    2b7e:	3280      	movi      	r2, 128
    2b80:	4242      	lsli      	r2, r2, 2
    2b82:	07a1      	br      	0x2ac4	// 2ac4 <GPTB0IntHandler+0x28>
	else if((GPTB0->MISR&GPT_CBU)==GPT_CBU)			//Up-Counting phase CNT = CMPB Interrupt
    2b84:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2b88:	e4422400 	andi      	r2, r2, 1024
    2b8c:	3a40      	cmpnei      	r2, 0
    2b8e:	0c04      	bf      	0x2b96	// 2b96 <GPTB0IntHandler+0xfa>
		GPTB0->ICR = GPT_CBU;
    2b90:	3280      	movi      	r2, 128
    2b92:	4243      	lsli      	r2, r2, 3
    2b94:	0798      	br      	0x2ac4	// 2ac4 <GPTB0IntHandler+0x28>
	else if((GPTB0->MISR&GPT_CBD)==GPT_CBD)			//Down-Counting phase CNT = CMPB Interrupt
    2b96:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2b9a:	e4422800 	andi      	r2, r2, 2048
    2b9e:	3a40      	cmpnei      	r2, 0
    2ba0:	0c04      	bf      	0x2ba8	// 2ba8 <GPTB0IntHandler+0x10c>
		GPTB0->ICR = GPT_CBD;
    2ba2:	3280      	movi      	r2, 128
    2ba4:	4244      	lsli      	r2, r2, 4
    2ba6:	078f      	br      	0x2ac4	// 2ac4 <GPTB0IntHandler+0x28>
	else if((GPTB0->MISR&GPT_PEND)==GPT_PEND)		//End of cycle interrupt 
    2ba8:	3280      	movi      	r2, 128
    2baa:	d8232035 	ld.w      	r1, (r3, 0xd4)
    2bae:	4249      	lsli      	r2, r2, 9
    2bb0:	6848      	and      	r1, r2
    2bb2:	3940      	cmpnei      	r1, 0
    2bb4:	0faf      	bf      	0x2b12	// 2b12 <GPTB0IntHandler+0x76>
    2bb6:	0787      	br      	0x2ac4	// 2ac4 <GPTB0IntHandler+0x28>
	else if((GPTB0->EMMISR&GPT_EP1_EMINT)==GPT_EP1_EMINT)	//interrupt flag of EP1 event
    2bb8:	d843202b 	ld.w      	r2, (r3, 0xac)
    2bbc:	e4422002 	andi      	r2, r2, 2
    2bc0:	3a40      	cmpnei      	r2, 0
    2bc2:	0c03      	bf      	0x2bc8	// 2bc8 <GPTB0IntHandler+0x12c>
		GPTB0->EMICR=EPT_EP1_EMINT;
    2bc4:	3202      	movi      	r2, 2
    2bc6:	07ae      	br      	0x2b22	// 2b22 <GPTB0IntHandler+0x86>
	else if((GPTB0->EMMISR&GPT_EP2_EMINT)==GPT_EP2_EMINT)	//interrupt flag of EP2 event
    2bc8:	d843202b 	ld.w      	r2, (r3, 0xac)
    2bcc:	e4422004 	andi      	r2, r2, 4
    2bd0:	3a40      	cmpnei      	r2, 0
    2bd2:	0c03      	bf      	0x2bd8	// 2bd8 <GPTB0IntHandler+0x13c>
		GPTB0->EMICR=GPT_EP2_EMINT;
    2bd4:	3204      	movi      	r2, 4
    2bd6:	07a6      	br      	0x2b22	// 2b22 <GPTB0IntHandler+0x86>
	else if((GPTB0->EMMISR&GPT_EP3_EMINT)==GPT_EP3_EMINT)	//interrupt flag of EP3 event
    2bd8:	d843202b 	ld.w      	r2, (r3, 0xac)
    2bdc:	e4422008 	andi      	r2, r2, 8
    2be0:	3a40      	cmpnei      	r2, 0
    2be2:	0c03      	bf      	0x2be8	// 2be8 <GPTB0IntHandler+0x14c>
		GPTB0->EMICR=GPT_EP3_EMINT;
    2be4:	3208      	movi      	r2, 8
    2be6:	079e      	br      	0x2b22	// 2b22 <GPTB0IntHandler+0x86>
	else if((GPTB0->EMMISR&GPT_CPU_FAULT_EMINT)==GPT_CPU_FAULT_EMINT)	//interrupt flag of CPU_FAULT event
    2be8:	d843202b 	ld.w      	r2, (r3, 0xac)
    2bec:	e4422100 	andi      	r2, r2, 256
    2bf0:	3a40      	cmpnei      	r2, 0
    2bf2:	0c04      	bf      	0x2bfa	// 2bfa <GPTB0IntHandler+0x15e>
		GPTB0->EMICR=GPT_CPU_FAULT_EMINT;
    2bf4:	3280      	movi      	r2, 128
    2bf6:	4241      	lsli      	r2, r2, 1
    2bf8:	0795      	br      	0x2b22	// 2b22 <GPTB0IntHandler+0x86>
	else if((GPTB0->EMMISR&GPT_MEM_FAULT_EMINT)==GPT_MEM_FAULT_EMINT)	//interrupt flag of MEM_FAULT event
    2bfa:	d843202b 	ld.w      	r2, (r3, 0xac)
    2bfe:	e4422200 	andi      	r2, r2, 512
    2c02:	3a40      	cmpnei      	r2, 0
    2c04:	0c04      	bf      	0x2c0c	// 2c0c <GPTB0IntHandler+0x170>
		GPTB0->EMICR=GPT_MEM_FAULT_EMINT;
    2c06:	3280      	movi      	r2, 128
    2c08:	4242      	lsli      	r2, r2, 2
    2c0a:	078c      	br      	0x2b22	// 2b22 <GPTB0IntHandler+0x86>
	else if((GPTB0->EMMISR&GPT_EOM_FAULT_EMINT)==GPT_EOM_FAULT_EMINT)	//interrupt flag of EOM_FAULT event
    2c0c:	d843202b 	ld.w      	r2, (r3, 0xac)
    2c10:	e4422400 	andi      	r2, r2, 1024
    2c14:	3a40      	cmpnei      	r2, 0
    2c16:	0f88      	bf      	0x2b26	// 2b26 <GPTB0IntHandler+0x8a>
		GPTB0->EMICR=GPT_EOM_FAULT_EMINT;
    2c18:	3280      	movi      	r2, 128
    2c1a:	4243      	lsli      	r2, r2, 3
    2c1c:	0783      	br      	0x2b22	// 2b22 <GPTB0IntHandler+0x86>
    2c1e:	0000      	bkpt
    2c20:	200000c2 	.long	0x200000c2
    2c24:	2000004c 	.long	0x2000004c
    2c28:	200002ec 	.long	0x200002ec
    2c2c:	200002d4 	.long	0x200002d4

Disassembly of section .text.GPTB1IntHandler:

00002c30 <GPTB1IntHandler>:
//GPTB1 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void GPTB1IntHandler(void) 
{
    2c30:	1460      	nie
    2c32:	1462      	ipush
    2c34:	14d1      	push      	r4, r15
	if((GPTB1->MISR&GPT_TRGEV0_INT)==GPT_TRGEV0_INT)			//TRGEV0 interrupt
    2c36:	1299      	lrw      	r4, 0x20000048	// 2d98 <GPTB1IntHandler+0x168>
    2c38:	9460      	ld.w      	r3, (r4, 0x0)
    2c3a:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2c3e:	e4422001 	andi      	r2, r2, 1
    2c42:	3a40      	cmpnei      	r2, 0
    2c44:	0c05      	bf      	0x2c4e	// 2c4e <GPTB1IntHandler+0x1e>
	{
		GPTB1->ICR = GPT_TRGEV0_INT;
    2c46:	3201      	movi      	r2, 1
	{
		GPTB1->ICR = GPT_CBD;
	}
	else if((GPTB1->MISR&GPT_PEND)==GPT_PEND)		//End of cycle interrupt 
	{
		GPTB1->ICR = GPT_PEND;
    2c48:	dc432037 	st.w      	r2, (r3, 0xdc)
    2c4c:	0420      	br      	0x2c8c	// 2c8c <GPTB1IntHandler+0x5c>
	else if((GPTB1->MISR&GPT_TRGEV1_INT)==GPT_TRGEV1_INT)	//TRGEV1 interrupt
    2c4e:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2c52:	e4422002 	andi      	r2, r2, 2
    2c56:	3a40      	cmpnei      	r2, 0
    2c58:	0c03      	bf      	0x2c5e	// 2c5e <GPTB1IntHandler+0x2e>
		GPTB1->ICR = GPT_TRGEV1_INT;
    2c5a:	3202      	movi      	r2, 2
    2c5c:	07f6      	br      	0x2c48	// 2c48 <GPTB1IntHandler+0x18>
	else if((GPTB1->MISR&GPT_CAP_LD0)==GPT_CAP_LD0)		//Capture Load to CMPA interrupt
    2c5e:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2c62:	e4422010 	andi      	r2, r2, 16
    2c66:	3a40      	cmpnei      	r2, 0
    2c68:	0c22      	bf      	0x2cac	// 2cac <GPTB1IntHandler+0x7c>
		GPTB1->ICR = GPT_CAP_LD0;
    2c6a:	3210      	movi      	r2, 16
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIRT);
    2c6c:	3102      	movi      	r1, 2
		GPTB1->ICR = GPT_CAP_LD0;
    2c6e:	dc432037 	st.w      	r2, (r3, 0xdc)
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIRT);
    2c72:	3000      	movi      	r0, 0
    2c74:	3200      	movi      	r2, 0
    2c76:	e3fffa67 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIFT);
    2c7a:	3201      	movi      	r2, 1
    2c7c:	3102      	movi      	r1, 2
    2c7e:	3001      	movi      	r0, 1
    2c80:	e3fffa62 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		R_CMPA_BUF=GPTB1->CMPA;			//period counter
    2c84:	9460      	ld.w      	r3, (r4, 0x0)
    2c86:	934b      	ld.w      	r2, (r3, 0x2c)
    2c88:	1265      	lrw      	r3, 0x200002ec	// 2d9c <GPTB1IntHandler+0x16c>
		R_CMPB_BUF=GPTB1->CMPB;			//Duty counter
    2c8a:	b340      	st.w      	r2, (r3, 0x0)
	}
	//Emergency interruption
	if((GPTB1->EMMISR&GPT_EP0_EMINT)==GPT_EP0_EMINT)			//interrupt flag of EP0 event
    2c8c:	9460      	ld.w      	r3, (r4, 0x0)
    2c8e:	d843202b 	ld.w      	r2, (r3, 0xac)
    2c92:	e4422001 	andi      	r2, r2, 1
    2c96:	3a40      	cmpnei      	r2, 0
    2c98:	0c4d      	bf      	0x2d32	// 2d32 <GPTB1IntHandler+0x102>
	{
		GPTB1->EMICR=GPT_EP0_EMINT;
    2c9a:	3201      	movi      	r2, 1
	{
		GPTB1->EMICR=GPT_MEM_FAULT_EMINT;
	}
	else if((GPTB1->EMMISR&GPT_EOM_FAULT_EMINT)==GPT_EOM_FAULT_EMINT)	//interrupt flag of EOM_FAULT event
	{
		GPTB1->EMICR=GPT_EOM_FAULT_EMINT;
    2c9c:	dc43202d 	st.w      	r2, (r3, 0xb4)
	}
}
    2ca0:	d9ee2001 	ld.w      	r15, (r14, 0x4)
    2ca4:	9880      	ld.w      	r4, (r14, 0x0)
    2ca6:	1402      	addi      	r14, r14, 8
    2ca8:	1463      	ipop
    2caa:	1461      	nir
	else if((GPTB1->MISR&GPT_CAP_LD1)==GPT_CAP_LD1)		//Capture Load to CMPB interrupt
    2cac:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2cb0:	e4422020 	andi      	r2, r2, 32
    2cb4:	3a40      	cmpnei      	r2, 0
    2cb6:	0c12      	bf      	0x2cda	// 2cda <GPTB1IntHandler+0xaa>
		GPTB1->ICR = GPT_CAP_LD1;
    2cb8:	3220      	movi      	r2, 32
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIRT);
    2cba:	3102      	movi      	r1, 2
		GPTB1->ICR = GPT_CAP_LD1;
    2cbc:	dc432037 	st.w      	r2, (r3, 0xdc)
		EXTI_trigger_CMD(ENABLE,EXI_PIN1,_EXIRT);
    2cc0:	3001      	movi      	r0, 1
    2cc2:	3200      	movi      	r2, 0
    2cc4:	e3fffa40 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		EXTI_trigger_CMD(DISABLE,EXI_PIN1,_EXIFT);
    2cc8:	3201      	movi      	r2, 1
    2cca:	3102      	movi      	r1, 2
    2ccc:	3000      	movi      	r0, 0
    2cce:	e3fffa3b 	bsr      	0x2144	// 2144 <EXTI_trigger_CMD>
		R_CMPB_BUF=GPTB1->CMPB;			//Duty counter
    2cd2:	9460      	ld.w      	r3, (r4, 0x0)
    2cd4:	934c      	ld.w      	r2, (r3, 0x30)
    2cd6:	1173      	lrw      	r3, 0x200002d4	// 2da0 <GPTB1IntHandler+0x170>
    2cd8:	07d9      	br      	0x2c8a	// 2c8a <GPTB1IntHandler+0x5a>
	else if((GPTB1->MISR&GPT_CAU)==GPT_CAU)			//Up-Counting phase CNT = CMPA Interrupt
    2cda:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2cde:	e4422100 	andi      	r2, r2, 256
    2ce2:	3a40      	cmpnei      	r2, 0
    2ce4:	0c04      	bf      	0x2cec	// 2cec <GPTB1IntHandler+0xbc>
		GPTB1->ICR = GPT_CAU;
    2ce6:	3280      	movi      	r2, 128
    2ce8:	4241      	lsli      	r2, r2, 1
    2cea:	07af      	br      	0x2c48	// 2c48 <GPTB1IntHandler+0x18>
	else if((GPTB1->MISR&GPT_CAD)==GPT_CAD)			//Down-Counting phase CNT = CMPA Interrupt
    2cec:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2cf0:	e4422200 	andi      	r2, r2, 512
    2cf4:	3a40      	cmpnei      	r2, 0
    2cf6:	0c04      	bf      	0x2cfe	// 2cfe <GPTB1IntHandler+0xce>
		GPTB1->ICR = GPT_CAD;
    2cf8:	3280      	movi      	r2, 128
    2cfa:	4242      	lsli      	r2, r2, 2
    2cfc:	07a6      	br      	0x2c48	// 2c48 <GPTB1IntHandler+0x18>
	else if((GPTB1->MISR&GPT_CBU)==GPT_CBU)			//Up-Counting phase CNT = CMPB Interrupt
    2cfe:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2d02:	e4422400 	andi      	r2, r2, 1024
    2d06:	3a40      	cmpnei      	r2, 0
    2d08:	0c04      	bf      	0x2d10	// 2d10 <GPTB1IntHandler+0xe0>
		GPTB1->ICR = GPT_CBU;
    2d0a:	3280      	movi      	r2, 128
    2d0c:	4243      	lsli      	r2, r2, 3
    2d0e:	079d      	br      	0x2c48	// 2c48 <GPTB1IntHandler+0x18>
	else if((GPTB1->MISR&GPT_CBD)==GPT_CBD)			//Down-Counting phase CNT = CMPB Interrupt
    2d10:	d8432035 	ld.w      	r2, (r3, 0xd4)
    2d14:	e4422800 	andi      	r2, r2, 2048
    2d18:	3a40      	cmpnei      	r2, 0
    2d1a:	0c04      	bf      	0x2d22	// 2d22 <GPTB1IntHandler+0xf2>
		GPTB1->ICR = GPT_CBD;
    2d1c:	3280      	movi      	r2, 128
    2d1e:	4244      	lsli      	r2, r2, 4
    2d20:	0794      	br      	0x2c48	// 2c48 <GPTB1IntHandler+0x18>
	else if((GPTB1->MISR&GPT_PEND)==GPT_PEND)		//End of cycle interrupt 
    2d22:	3280      	movi      	r2, 128
    2d24:	d8232035 	ld.w      	r1, (r3, 0xd4)
    2d28:	4249      	lsli      	r2, r2, 9
    2d2a:	6848      	and      	r1, r2
    2d2c:	3940      	cmpnei      	r1, 0
    2d2e:	0faf      	bf      	0x2c8c	// 2c8c <GPTB1IntHandler+0x5c>
    2d30:	078c      	br      	0x2c48	// 2c48 <GPTB1IntHandler+0x18>
	else if((GPTB1->EMMISR&GPT_EP1_EMINT)==GPT_EP1_EMINT)	//interrupt flag of EP1 event
    2d32:	d843202b 	ld.w      	r2, (r3, 0xac)
    2d36:	e4422002 	andi      	r2, r2, 2
    2d3a:	3a40      	cmpnei      	r2, 0
    2d3c:	0c03      	bf      	0x2d42	// 2d42 <GPTB1IntHandler+0x112>
		GPTB1->EMICR=GPT_EP1_EMINT;
    2d3e:	3202      	movi      	r2, 2
    2d40:	07ae      	br      	0x2c9c	// 2c9c <GPTB1IntHandler+0x6c>
	else if((GPTB1->EMMISR&GPT_EP2_EMINT)==GPT_EP2_EMINT)	//interrupt flag of EP2 event
    2d42:	d843202b 	ld.w      	r2, (r3, 0xac)
    2d46:	e4422004 	andi      	r2, r2, 4
    2d4a:	3a40      	cmpnei      	r2, 0
    2d4c:	0c03      	bf      	0x2d52	// 2d52 <GPTB1IntHandler+0x122>
		GPTB1->EMICR=GPT_EP2_EMINT;
    2d4e:	3204      	movi      	r2, 4
    2d50:	07a6      	br      	0x2c9c	// 2c9c <GPTB1IntHandler+0x6c>
	else if((GPTB1->EMMISR&GPT_EP3_EMINT)==GPT_EP3_EMINT)	//interrupt flag of EP3 event
    2d52:	d843202b 	ld.w      	r2, (r3, 0xac)
    2d56:	e4422008 	andi      	r2, r2, 8
    2d5a:	3a40      	cmpnei      	r2, 0
    2d5c:	0c03      	bf      	0x2d62	// 2d62 <GPTB1IntHandler+0x132>
		GPTB1->EMICR=GPT_EP3_EMINT;
    2d5e:	3208      	movi      	r2, 8
    2d60:	079e      	br      	0x2c9c	// 2c9c <GPTB1IntHandler+0x6c>
	else if((GPTB1->EMMISR&GPT_CPU_FAULT_EMINT)==GPT_CPU_FAULT_EMINT)	//interrupt flag of CPU_FAULT event
    2d62:	d843202b 	ld.w      	r2, (r3, 0xac)
    2d66:	e4422100 	andi      	r2, r2, 256
    2d6a:	3a40      	cmpnei      	r2, 0
    2d6c:	0c04      	bf      	0x2d74	// 2d74 <GPTB1IntHandler+0x144>
		GPTB1->EMICR=GPT_CPU_FAULT_EMINT;
    2d6e:	3280      	movi      	r2, 128
    2d70:	4241      	lsli      	r2, r2, 1
    2d72:	0795      	br      	0x2c9c	// 2c9c <GPTB1IntHandler+0x6c>
	else if((GPTB1->EMMISR&GPT_MEM_FAULT_EMINT)==GPT_MEM_FAULT_EMINT)	//interrupt flag of MEM_FAULT event
    2d74:	d843202b 	ld.w      	r2, (r3, 0xac)
    2d78:	e4422200 	andi      	r2, r2, 512
    2d7c:	3a40      	cmpnei      	r2, 0
    2d7e:	0c04      	bf      	0x2d86	// 2d86 <GPTB1IntHandler+0x156>
		GPTB1->EMICR=GPT_MEM_FAULT_EMINT;
    2d80:	3280      	movi      	r2, 128
    2d82:	4242      	lsli      	r2, r2, 2
    2d84:	078c      	br      	0x2c9c	// 2c9c <GPTB1IntHandler+0x6c>
	else if((GPTB1->EMMISR&GPT_EOM_FAULT_EMINT)==GPT_EOM_FAULT_EMINT)	//interrupt flag of EOM_FAULT event
    2d86:	d843202b 	ld.w      	r2, (r3, 0xac)
    2d8a:	e4422400 	andi      	r2, r2, 1024
    2d8e:	3a40      	cmpnei      	r2, 0
    2d90:	0f88      	bf      	0x2ca0	// 2ca0 <GPTB1IntHandler+0x70>
		GPTB1->EMICR=GPT_EOM_FAULT_EMINT;
    2d92:	3280      	movi      	r2, 128
    2d94:	4243      	lsli      	r2, r2, 3
    2d96:	0783      	br      	0x2c9c	// 2c9c <GPTB1IntHandler+0x6c>
    2d98:	20000048 	.long	0x20000048
    2d9c:	200002ec 	.long	0x200002ec
    2da0:	200002d4 	.long	0x200002d4

Disassembly of section .text.RTCIntHandler:

00002da4 <RTCIntHandler>:
//RTC Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void RTCIntHandler(void) 
{
    2da4:	1460      	nie
    2da6:	1462      	ipush
    // ISR content ...
	if((RTC->MISR&ALRA_INT)==ALRA_INT)			//Interrupt of alarm A
    2da8:	1074      	lrw      	r3, 0x2000003c	// 2df8 <RTCIntHandler+0x54>
    2daa:	9360      	ld.w      	r3, (r3, 0x0)
    2dac:	934a      	ld.w      	r2, (r3, 0x28)
    2dae:	e4422001 	andi      	r2, r2, 1
    2db2:	3a40      	cmpnei      	r2, 0
    2db4:	0c05      	bf      	0x2dbe	// 2dbe <RTCIntHandler+0x1a>
	{
		RTC->ICR=ALRA_INT;
    2db6:	3201      	movi      	r2, 1
	{
		RTC->ICR=RTC_TRGEV0_INT;
	}
	else if((RTC->MISR&RTC_TRGEV1_INT)==RTC_TRGEV1_INT)		//Interrupt of trigger event 1
	{
		RTC->ICR=RTC_TRGEV1_INT;
    2db8:	b34b      	st.w      	r2, (r3, 0x2c)
	}
}
    2dba:	1463      	ipop
    2dbc:	1461      	nir
	else if((RTC->MISR&ALRB_INT)==ALRB_INT)			//Interrupt of alarm B				
    2dbe:	934a      	ld.w      	r2, (r3, 0x28)
    2dc0:	e4422002 	andi      	r2, r2, 2
    2dc4:	3a40      	cmpnei      	r2, 0
    2dc6:	0c03      	bf      	0x2dcc	// 2dcc <RTCIntHandler+0x28>
		RTC->ICR=ALRB_INT;
    2dc8:	3202      	movi      	r2, 2
    2dca:	07f7      	br      	0x2db8	// 2db8 <RTCIntHandler+0x14>
	else if((RTC->MISR&CPRD_INT)==CPRD_INT)			//Interrupt of alarm CPRD
    2dcc:	934a      	ld.w      	r2, (r3, 0x28)
    2dce:	e4422004 	andi      	r2, r2, 4
    2dd2:	3a40      	cmpnei      	r2, 0
    2dd4:	0c03      	bf      	0x2dda	// 2dda <RTCIntHandler+0x36>
		RTC->ICR=CPRD_INT;
    2dd6:	3204      	movi      	r2, 4
    2dd8:	07f0      	br      	0x2db8	// 2db8 <RTCIntHandler+0x14>
	else if((RTC->MISR&RTC_TRGEV0_INT)==RTC_TRGEV0_INT)		//Interrupt of trigger event 0
    2dda:	934a      	ld.w      	r2, (r3, 0x28)
    2ddc:	e4422008 	andi      	r2, r2, 8
    2de0:	3a40      	cmpnei      	r2, 0
    2de2:	0c03      	bf      	0x2de8	// 2de8 <RTCIntHandler+0x44>
		RTC->ICR=RTC_TRGEV0_INT;
    2de4:	3208      	movi      	r2, 8
    2de6:	07e9      	br      	0x2db8	// 2db8 <RTCIntHandler+0x14>
	else if((RTC->MISR&RTC_TRGEV1_INT)==RTC_TRGEV1_INT)		//Interrupt of trigger event 1
    2de8:	934a      	ld.w      	r2, (r3, 0x28)
    2dea:	e4422010 	andi      	r2, r2, 16
    2dee:	3a40      	cmpnei      	r2, 0
    2df0:	0fe5      	bf      	0x2dba	// 2dba <RTCIntHandler+0x16>
		RTC->ICR=RTC_TRGEV1_INT;
    2df2:	3210      	movi      	r2, 16
    2df4:	07e2      	br      	0x2db8	// 2db8 <RTCIntHandler+0x14>
    2df6:	0000      	bkpt
    2df8:	2000003c 	.long	0x2000003c

Disassembly of section .text.UART0IntHandler:

00002dfc <UART0IntHandler>:
//UART0 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART0IntHandler(void) 
{
    2dfc:	1460      	nie
    2dfe:	1462      	ipush
    // ISR content ...	
	if ((UART0->ISR&UART_RX_INT_S)==UART_RX_INT_S)				//RX interrupt
    2e00:	1073      	lrw      	r3, 0x20000074	// 2e4c <UART0IntHandler+0x50>
    2e02:	9360      	ld.w      	r3, (r3, 0x0)
    2e04:	9343      	ld.w      	r2, (r3, 0xc)
    2e06:	e4422002 	andi      	r2, r2, 2
    2e0a:	3a40      	cmpnei      	r2, 0
    2e0c:	0c08      	bf      	0x2e1c	// 2e1c <UART0IntHandler+0x20>
	{
		UART0->ISR=UART_RX_INT_S;
    2e0e:	3202      	movi      	r2, 2
    2e10:	b343      	st.w      	r2, (r3, 0xc)
		RxDataFlag = TRUE;
    2e12:	3201      	movi      	r2, 1
    2e14:	106f      	lrw      	r3, 0x200000bf	// 2e50 <UART0IntHandler+0x54>
	}
	else if( (UART0->ISR&UART_TX_INT_S)==UART_TX_INT_S ) 		//TX interrupt
    {
		UART0->ISR=UART_TX_INT_S;
		TxDataFlag = TRUE;
    2e16:	a340      	st.b      	r2, (r3, 0x0)
	}
	else if ((UART0->ISR&UART_TX_IOV_S)==UART_TX_IOV_S)			//TX overrun interrupt
	{
		UART0->ISR=UART_TX_IOV_S;
	}
}
    2e18:	1463      	ipop
    2e1a:	1461      	nir
	else if( (UART0->ISR&UART_TX_INT_S)==UART_TX_INT_S ) 		//TX interrupt
    2e1c:	9343      	ld.w      	r2, (r3, 0xc)
    2e1e:	e4422001 	andi      	r2, r2, 1
    2e22:	3a40      	cmpnei      	r2, 0
    2e24:	0c05      	bf      	0x2e2e	// 2e2e <UART0IntHandler+0x32>
		UART0->ISR=UART_TX_INT_S;
    2e26:	3201      	movi      	r2, 1
    2e28:	b343      	st.w      	r2, (r3, 0xc)
		TxDataFlag = TRUE;
    2e2a:	106b      	lrw      	r3, 0x200000c0	// 2e54 <UART0IntHandler+0x58>
    2e2c:	07f5      	br      	0x2e16	// 2e16 <UART0IntHandler+0x1a>
	else if ((UART0->ISR&UART_RX_IOV_S)==UART_RX_IOV_S)			//RX overrun interrupt
    2e2e:	9343      	ld.w      	r2, (r3, 0xc)
    2e30:	e4422008 	andi      	r2, r2, 8
    2e34:	3a40      	cmpnei      	r2, 0
    2e36:	0c04      	bf      	0x2e3e	// 2e3e <UART0IntHandler+0x42>
		UART0->ISR=UART_RX_IOV_S;
    2e38:	3208      	movi      	r2, 8
		UART0->ISR=UART_TX_IOV_S;
    2e3a:	b343      	st.w      	r2, (r3, 0xc)
}
    2e3c:	07ee      	br      	0x2e18	// 2e18 <UART0IntHandler+0x1c>
	else if ((UART0->ISR&UART_TX_IOV_S)==UART_TX_IOV_S)			//TX overrun interrupt
    2e3e:	9343      	ld.w      	r2, (r3, 0xc)
    2e40:	e4422004 	andi      	r2, r2, 4
    2e44:	3a40      	cmpnei      	r2, 0
    2e46:	0fe9      	bf      	0x2e18	// 2e18 <UART0IntHandler+0x1c>
		UART0->ISR=UART_TX_IOV_S;
    2e48:	3204      	movi      	r2, 4
    2e4a:	07f8      	br      	0x2e3a	// 2e3a <UART0IntHandler+0x3e>
    2e4c:	20000074 	.long	0x20000074
    2e50:	200000bf 	.long	0x200000bf
    2e54:	200000c0 	.long	0x200000c0

Disassembly of section .text.UART1IntHandler:

00002e58 <UART1IntHandler>:
//UART1 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART1IntHandler(void) 
{
    2e58:	1460      	nie
    2e5a:	1462      	ipush
    // ISR content ...
	if ((UART1->ISR&UART_RX_INT_S)==UART_RX_INT_S)				//RX interrupt
    2e5c:	1073      	lrw      	r3, 0x20000070	// 2ea8 <UART1IntHandler+0x50>
    2e5e:	9360      	ld.w      	r3, (r3, 0x0)
    2e60:	9343      	ld.w      	r2, (r3, 0xc)
    2e62:	e4422002 	andi      	r2, r2, 2
    2e66:	3a40      	cmpnei      	r2, 0
    2e68:	0c08      	bf      	0x2e78	// 2e78 <UART1IntHandler+0x20>
	{
		UART1->ISR=UART_RX_INT_S;
    2e6a:	3202      	movi      	r2, 2
    2e6c:	b343      	st.w      	r2, (r3, 0xc)
		RxDataFlag = TRUE;
    2e6e:	3201      	movi      	r2, 1
    2e70:	106f      	lrw      	r3, 0x200000bf	// 2eac <UART1IntHandler+0x54>
	}
	else if( (UART1->ISR&UART_TX_INT_S)==UART_TX_INT_S ) 		//TX interrupt
    {
		UART1->ISR=UART_TX_INT_S;
		TxDataFlag = TRUE;
    2e72:	a340      	st.b      	r2, (r3, 0x0)
	}
	else if ((UART1->ISR&UART_TX_IOV_S)==UART_TX_IOV_S)			//TX overrun interrupt
	{
		UART1->ISR=UART_TX_IOV_S;
	}
}
    2e74:	1463      	ipop
    2e76:	1461      	nir
	else if( (UART1->ISR&UART_TX_INT_S)==UART_TX_INT_S ) 		//TX interrupt
    2e78:	9343      	ld.w      	r2, (r3, 0xc)
    2e7a:	e4422001 	andi      	r2, r2, 1
    2e7e:	3a40      	cmpnei      	r2, 0
    2e80:	0c05      	bf      	0x2e8a	// 2e8a <UART1IntHandler+0x32>
		UART1->ISR=UART_TX_INT_S;
    2e82:	3201      	movi      	r2, 1
    2e84:	b343      	st.w      	r2, (r3, 0xc)
		TxDataFlag = TRUE;
    2e86:	106b      	lrw      	r3, 0x200000c0	// 2eb0 <UART1IntHandler+0x58>
    2e88:	07f5      	br      	0x2e72	// 2e72 <UART1IntHandler+0x1a>
	else if ((UART1->ISR&UART_RX_IOV_S)==UART_RX_IOV_S)			//RX overrun interrupt
    2e8a:	9343      	ld.w      	r2, (r3, 0xc)
    2e8c:	e4422008 	andi      	r2, r2, 8
    2e90:	3a40      	cmpnei      	r2, 0
    2e92:	0c04      	bf      	0x2e9a	// 2e9a <UART1IntHandler+0x42>
		UART1->ISR=UART_RX_IOV_S;
    2e94:	3208      	movi      	r2, 8
		UART1->ISR=UART_TX_IOV_S;
    2e96:	b343      	st.w      	r2, (r3, 0xc)
}
    2e98:	07ee      	br      	0x2e74	// 2e74 <UART1IntHandler+0x1c>
	else if ((UART1->ISR&UART_TX_IOV_S)==UART_TX_IOV_S)			//TX overrun interrupt
    2e9a:	9343      	ld.w      	r2, (r3, 0xc)
    2e9c:	e4422004 	andi      	r2, r2, 4
    2ea0:	3a40      	cmpnei      	r2, 0
    2ea2:	0fe9      	bf      	0x2e74	// 2e74 <UART1IntHandler+0x1c>
		UART1->ISR=UART_TX_IOV_S;
    2ea4:	3204      	movi      	r2, 4
    2ea6:	07f8      	br      	0x2e96	// 2e96 <UART1IntHandler+0x3e>
    2ea8:	20000070 	.long	0x20000070
    2eac:	200000bf 	.long	0x200000bf
    2eb0:	200000c0 	.long	0x200000c0

Disassembly of section .text.UART2IntHandler:

00002eb4 <UART2IntHandler>:
//UART2 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART2IntHandler(void) 
{
    2eb4:	1460      	nie
    2eb6:	1462      	ipush
    // ISR content ...
	if ((UART2->ISR&UART_RX_INT_S)==UART_RX_INT_S)				//RX interrupt
    2eb8:	1072      	lrw      	r3, 0x2000006c	// 2f00 <UART2IntHandler+0x4c>
    2eba:	9360      	ld.w      	r3, (r3, 0x0)
    2ebc:	9343      	ld.w      	r2, (r3, 0xc)
    2ebe:	e4422002 	andi      	r2, r2, 2
    2ec2:	3a40      	cmpnei      	r2, 0
    2ec4:	0c08      	bf      	0x2ed4	// 2ed4 <UART2IntHandler+0x20>
	{
		UART2->ISR=UART_RX_INT_S;
    2ec6:	3202      	movi      	r2, 2
    2ec8:	b343      	st.w      	r2, (r3, 0xc)
		RxDataFlag = TRUE;
    2eca:	106f      	lrw      	r3, 0x200000bf	// 2f04 <UART2IntHandler+0x50>
	}
	else if( (UART2->ISR&UART_TX_INT_S)==UART_TX_INT_S ) 		//TX interrupt
    {
		//UART2->ISR=UART_TX_INT_S;
		TxDataFlag = TRUE;
    2ecc:	3201      	movi      	r2, 1
    2ece:	a340      	st.b      	r2, (r3, 0x0)
	}
	else if ((UART2->ISR&UART_TX_IOV_S)==UART_TX_IOV_S)			//TX overrun interrupt
	{
		UART2->ISR=UART_TX_IOV_S;
	}
}
    2ed0:	1463      	ipop
    2ed2:	1461      	nir
	else if( (UART2->ISR&UART_TX_INT_S)==UART_TX_INT_S ) 		//TX interrupt
    2ed4:	9343      	ld.w      	r2, (r3, 0xc)
    2ed6:	e4422001 	andi      	r2, r2, 1
    2eda:	3a40      	cmpnei      	r2, 0
    2edc:	0c03      	bf      	0x2ee2	// 2ee2 <UART2IntHandler+0x2e>
		TxDataFlag = TRUE;
    2ede:	106b      	lrw      	r3, 0x200000c0	// 2f08 <UART2IntHandler+0x54>
    2ee0:	07f6      	br      	0x2ecc	// 2ecc <UART2IntHandler+0x18>
	else if ((UART2->ISR&UART_RX_IOV_S)==UART_RX_IOV_S)			//RX overrun interrupt
    2ee2:	9343      	ld.w      	r2, (r3, 0xc)
    2ee4:	e4422008 	andi      	r2, r2, 8
    2ee8:	3a40      	cmpnei      	r2, 0
    2eea:	0c04      	bf      	0x2ef2	// 2ef2 <UART2IntHandler+0x3e>
		UART2->ISR=UART_RX_IOV_S;
    2eec:	3208      	movi      	r2, 8
		UART2->ISR=UART_TX_IOV_S;
    2eee:	b343      	st.w      	r2, (r3, 0xc)
}
    2ef0:	07f0      	br      	0x2ed0	// 2ed0 <UART2IntHandler+0x1c>
	else if ((UART2->ISR&UART_TX_IOV_S)==UART_TX_IOV_S)			//TX overrun interrupt
    2ef2:	9343      	ld.w      	r2, (r3, 0xc)
    2ef4:	e4422004 	andi      	r2, r2, 4
    2ef8:	3a40      	cmpnei      	r2, 0
    2efa:	0feb      	bf      	0x2ed0	// 2ed0 <UART2IntHandler+0x1c>
		UART2->ISR=UART_TX_IOV_S;
    2efc:	3204      	movi      	r2, 4
    2efe:	07f8      	br      	0x2eee	// 2eee <UART2IntHandler+0x3a>
    2f00:	2000006c 	.long	0x2000006c
    2f04:	200000bf 	.long	0x200000bf
    2f08:	200000c0 	.long	0x200000c0

Disassembly of section .text.USART0IntHandler:

00002f0c <USART0IntHandler>:
//USART Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void USART0IntHandler(void) 
{
    2f0c:	1460      	nie
    2f0e:	1462      	ipush
	unsigned int status;
	status = USART0->MISR & USART0->IMSCR ;
    2f10:	106f      	lrw      	r3, 0x20000068	// 2f4c <USART0IntHandler+0x40>
    2f12:	9320      	ld.w      	r1, (r3, 0x0)
    2f14:	9167      	ld.w      	r3, (r1, 0x1c)
    2f16:	9145      	ld.w      	r2, (r1, 0x14)
    2f18:	68c8      	and      	r3, r2
	if( status & USART_RXRDY ) 
    2f1a:	e4632001 	andi      	r3, r3, 1
    2f1e:	3b40      	cmpnei      	r3, 0
    2f20:	0c14      	bf      	0x2f48	// 2f48 <USART0IntHandler+0x3c>
	{
	   r_usrat_cont++;
    2f22:	106c      	lrw      	r3, 0x200002e8	// 2f50 <USART0IntHandler+0x44>
    2f24:	8340      	ld.b      	r2, (r3, 0x0)
    2f26:	2200      	addi      	r2, 1
    2f28:	7488      	zextb      	r2, r2
    2f2a:	a340      	st.b      	r2, (r3, 0x0)
		if(r_usrat_cont>=3)
    2f2c:	8340      	ld.b      	r2, (r3, 0x0)
    2f2e:	7488      	zextb      	r2, r2
    2f30:	3a02      	cmphsi      	r2, 3
    2f32:	0c03      	bf      	0x2f38	// 2f38 <USART0IntHandler+0x2c>
		{
			r_usrat_cont=0;
    2f34:	3200      	movi      	r2, 0
    2f36:	a340      	st.b      	r2, (r3, 0x0)
		}
		r_usart_buf[r_usrat_cont]=CSP_USART_GET_RHR(USART0);
    2f38:	8360      	ld.b      	r3, (r3, 0x0)
    2f3a:	914a      	ld.w      	r2, (r1, 0x28)
    2f3c:	7488      	zextb      	r2, r2
    2f3e:	1006      	lrw      	r0, 0x200002e2	// 2f54 <USART0IntHandler+0x48>
    2f40:	60c0      	addu      	r3, r0
    2f42:	a340      	st.b      	r2, (r3, 0x0)
		CSP_USART_SET_ICR(USART0, USART_RXRDY);
    2f44:	3301      	movi      	r3, 1
    2f46:	b168      	st.w      	r3, (r1, 0x20)
	}
	if (status & USART_TXRDY) 
	{
		//CSP_USART_SET_ICR(USART0, USART_TXRDY);
	}
}
    2f48:	1463      	ipop
    2f4a:	1461      	nir
    2f4c:	20000068 	.long	0x20000068
    2f50:	200002e8 	.long	0x200002e8
    2f54:	200002e2 	.long	0x200002e2

Disassembly of section .text.I2CIntHandler:

00002f58 <I2CIntHandler>:
//I2C Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2CIntHandler(void) 
{
    2f58:	1460      	nie
    2f5a:	1462      	ipush
    2f5c:	14d0      	push      	r15
    // ISR content ...
	I2C_Slave_Receive();										//I2C slave receive function in interruption
    2f5e:	e3fff6d9 	bsr      	0x1d10	// 1d10 <I2C_Slave_Receive>
}
    2f62:	d9ee2000 	ld.w      	r15, (r14, 0x0)
    2f66:	1401      	addi      	r14, r14, 4
    2f68:	1463      	ipop
    2f6a:	1461      	nir

Disassembly of section .text.SPI0IntHandler:

00002f6c <SPI0IntHandler>:
//SPI Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SPI0IntHandler(void) 
{
    2f6c:	1460      	nie
    2f6e:	1462      	ipush
	// ISR content ...
	if((SPI0->MISR&SPI_PORIM)==SPI_PORIM)					//Receive Overrun Interrupt
    2f70:	126c      	lrw      	r3, 0x20000064	// 30a0 <SPI0IntHandler+0x134>
    2f72:	3001      	movi      	r0, 1
    2f74:	9360      	ld.w      	r3, (r3, 0x0)
    2f76:	9327      	ld.w      	r1, (r3, 0x1c)
    2f78:	6840      	and      	r1, r0
    2f7a:	3940      	cmpnei      	r1, 0
    2f7c:	0c04      	bf      	0x2f84	// 2f84 <SPI0IntHandler+0x18>
	{
		SPI0->ICR = SPI_PORIM;
    2f7e:	3201      	movi      	r2, 1
			}
		}
	}
	else if((SPI0->MISR&SPI_TXIM)==SPI_TXIM)				//Transmit FIFO Interrupt
	{
		SPI0->ICR = SPI_TXIM;
    2f80:	b348      	st.w      	r2, (r3, 0x20)
	}
}
    2f82:	0473      	br      	0x3068	// 3068 <SPI0IntHandler+0xfc>
	else if((SPI0->MISR&SPI_RTIM)==SPI_RTIM)				//Receive Timeout Interrupt
    2f84:	9327      	ld.w      	r1, (r3, 0x1c)
    2f86:	e4212002 	andi      	r1, r1, 2
    2f8a:	3940      	cmpnei      	r1, 0
    2f8c:	0c03      	bf      	0x2f92	// 2f92 <SPI0IntHandler+0x26>
		SPI0->ICR = SPI_RTIM;
    2f8e:	3202      	movi      	r2, 2
    2f90:	07f8      	br      	0x2f80	// 2f80 <SPI0IntHandler+0x14>
	else if((SPI0->MISR&SPI_RXIM)==SPI_RXIM)				//Receive FIFO Interrupt,FIFO can be set 1/8,1/4,1/2 FIFO Interrupt
    2f92:	9327      	ld.w      	r1, (r3, 0x1c)
    2f94:	e4212004 	andi      	r1, r1, 4
    2f98:	3940      	cmpnei      	r1, 0
    2f9a:	0c7b      	bf      	0x3090	// 3090 <SPI0IntHandler+0x124>
		SPI0->ICR = SPI_RXIM;
    2f9c:	3204      	movi      	r2, 4
    2f9e:	b348      	st.w      	r2, (r3, 0x20)
		if(SPI0->DR==0xaa)
    2fa0:	9342      	ld.w      	r2, (r3, 0x8)
    2fa2:	eb4200aa 	cmpnei      	r2, 170
    2fa6:	0863      	bt      	0x306c	// 306c <SPI0IntHandler+0x100>
			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
    2fa8:	3102      	movi      	r1, 2
    2faa:	9343      	ld.w      	r2, (r3, 0xc)
    2fac:	6884      	and      	r2, r1
    2fae:	3a40      	cmpnei      	r2, 0
    2fb0:	0ffd      	bf      	0x2faa	// 2faa <SPI0IntHandler+0x3e>
			SPI0->DR = 0x11;
    2fb2:	3211      	movi      	r2, 17
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
    2fb4:	3110      	movi      	r1, 16
			SPI0->DR = 0x11;
    2fb6:	b342      	st.w      	r2, (r3, 0x8)
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
    2fb8:	9343      	ld.w      	r2, (r3, 0xc)
    2fba:	6884      	and      	r2, r1
    2fbc:	3a40      	cmpnei      	r2, 0
    2fbe:	0bfd      	bt      	0x2fb8	// 2fb8 <SPI0IntHandler+0x4c>
			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
    2fc0:	3102      	movi      	r1, 2
    2fc2:	9343      	ld.w      	r2, (r3, 0xc)
    2fc4:	6884      	and      	r2, r1
    2fc6:	3a40      	cmpnei      	r2, 0
    2fc8:	0ffd      	bf      	0x2fc2	// 2fc2 <SPI0IntHandler+0x56>
			SPI0->DR = 0x12;
    2fca:	3212      	movi      	r2, 18
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
    2fcc:	3110      	movi      	r1, 16
			SPI0->DR = 0x12;
    2fce:	b342      	st.w      	r2, (r3, 0x8)
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
    2fd0:	9343      	ld.w      	r2, (r3, 0xc)
    2fd2:	6884      	and      	r2, r1
    2fd4:	3a40      	cmpnei      	r2, 0
    2fd6:	0bfd      	bt      	0x2fd0	// 2fd0 <SPI0IntHandler+0x64>
			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
    2fd8:	3102      	movi      	r1, 2
    2fda:	9343      	ld.w      	r2, (r3, 0xc)
    2fdc:	6884      	and      	r2, r1
    2fde:	3a40      	cmpnei      	r2, 0
    2fe0:	0ffd      	bf      	0x2fda	// 2fda <SPI0IntHandler+0x6e>
			SPI0->DR = 0x13;
    2fe2:	3213      	movi      	r2, 19
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
    2fe4:	3110      	movi      	r1, 16
			SPI0->DR = 0x13;
    2fe6:	b342      	st.w      	r2, (r3, 0x8)
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
    2fe8:	9343      	ld.w      	r2, (r3, 0xc)
    2fea:	6884      	and      	r2, r1
    2fec:	3a40      	cmpnei      	r2, 0
    2fee:	0bfd      	bt      	0x2fe8	// 2fe8 <SPI0IntHandler+0x7c>
			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
    2ff0:	3102      	movi      	r1, 2
    2ff2:	9343      	ld.w      	r2, (r3, 0xc)
    2ff4:	6884      	and      	r2, r1
    2ff6:	3a40      	cmpnei      	r2, 0
    2ff8:	0ffd      	bf      	0x2ff2	// 2ff2 <SPI0IntHandler+0x86>
			SPI0->DR = 0x14;
    2ffa:	3214      	movi      	r2, 20
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
    2ffc:	3110      	movi      	r1, 16
			SPI0->DR = 0x14;
    2ffe:	b342      	st.w      	r2, (r3, 0x8)
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
    3000:	9343      	ld.w      	r2, (r3, 0xc)
    3002:	6884      	and      	r2, r1
    3004:	3a40      	cmpnei      	r2, 0
    3006:	0bfd      	bt      	0x3000	// 3000 <SPI0IntHandler+0x94>
			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
    3008:	3102      	movi      	r1, 2
    300a:	9343      	ld.w      	r2, (r3, 0xc)
    300c:	6884      	and      	r2, r1
    300e:	3a40      	cmpnei      	r2, 0
    3010:	0ffd      	bf      	0x300a	// 300a <SPI0IntHandler+0x9e>
			SPI0->DR = 0x15;
    3012:	3215      	movi      	r2, 21
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
    3014:	3110      	movi      	r1, 16
			SPI0->DR = 0x15;
    3016:	b342      	st.w      	r2, (r3, 0x8)
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
    3018:	9343      	ld.w      	r2, (r3, 0xc)
    301a:	6884      	and      	r2, r1
    301c:	3a40      	cmpnei      	r2, 0
    301e:	0bfd      	bt      	0x3018	// 3018 <SPI0IntHandler+0xac>
			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
    3020:	3102      	movi      	r1, 2
    3022:	9343      	ld.w      	r2, (r3, 0xc)
    3024:	6884      	and      	r2, r1
    3026:	3a40      	cmpnei      	r2, 0
    3028:	0ffd      	bf      	0x3022	// 3022 <SPI0IntHandler+0xb6>
			SPI0->DR = 0x16;
    302a:	3216      	movi      	r2, 22
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
    302c:	3110      	movi      	r1, 16
			SPI0->DR = 0x16;
    302e:	b342      	st.w      	r2, (r3, 0x8)
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
    3030:	9343      	ld.w      	r2, (r3, 0xc)
    3032:	6884      	and      	r2, r1
    3034:	3a40      	cmpnei      	r2, 0
    3036:	0bfd      	bt      	0x3030	// 3030 <SPI0IntHandler+0xc4>
			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
    3038:	3102      	movi      	r1, 2
    303a:	9343      	ld.w      	r2, (r3, 0xc)
    303c:	6884      	and      	r2, r1
    303e:	3a40      	cmpnei      	r2, 0
    3040:	0ffd      	bf      	0x303a	// 303a <SPI0IntHandler+0xce>
			SPI0->DR = 0x17;
    3042:	3217      	movi      	r2, 23
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
    3044:	3110      	movi      	r1, 16
			SPI0->DR = 0x17;
    3046:	b342      	st.w      	r2, (r3, 0x8)
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
    3048:	9343      	ld.w      	r2, (r3, 0xc)
    304a:	6884      	and      	r2, r1
    304c:	3a40      	cmpnei      	r2, 0
    304e:	0bfd      	bt      	0x3048	// 3048 <SPI0IntHandler+0xdc>
			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
    3050:	3102      	movi      	r1, 2
    3052:	9343      	ld.w      	r2, (r3, 0xc)
    3054:	6884      	and      	r2, r1
    3056:	3a40      	cmpnei      	r2, 0
    3058:	0ffd      	bf      	0x3052	// 3052 <SPI0IntHandler+0xe6>
			SPI0->DR = 0x18;
    305a:	3218      	movi      	r2, 24
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
    305c:	3110      	movi      	r1, 16
			SPI0->DR = 0x18;
    305e:	b342      	st.w      	r2, (r3, 0x8)
			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
    3060:	9343      	ld.w      	r2, (r3, 0xc)
    3062:	6884      	and      	r2, r1
    3064:	3a40      	cmpnei      	r2, 0
    3066:	0bfd      	bt      	0x3060	// 3060 <SPI0IntHandler+0xf4>
}
    3068:	1463      	ipop
    306a:	1461      	nir
			if(((SPI0->SR) & SSP_TFE)!=SSP_TFE)
    306c:	9343      	ld.w      	r2, (r3, 0xc)
    306e:	6880      	and      	r2, r0
    3070:	3a40      	cmpnei      	r2, 0
    3072:	0bfb      	bt      	0x3068	// 3068 <SPI0IntHandler+0xfc>
				SPI0->DR=0x0;								//FIFO空
    3074:	b342      	st.w      	r2, (r3, 0x8)
				while(((SPI0->SR) & SSP_BSY) == SSP_BSY);		//发送或接收是否完成？
    3076:	3110      	movi      	r1, 16
				SPI0->DR=0x0;								//FIFO空
    3078:	b342      	st.w      	r2, (r3, 0x8)
				SPI0->DR=0x0;								//FIFO空
    307a:	b342      	st.w      	r2, (r3, 0x8)
				SPI0->DR=0x0;								//FIFO空
    307c:	b342      	st.w      	r2, (r3, 0x8)
				SPI0->DR=0x0;								//FIFO空
    307e:	b342      	st.w      	r2, (r3, 0x8)
				SPI0->DR=0x0;								//FIFO空
    3080:	b342      	st.w      	r2, (r3, 0x8)
				SPI0->DR=0x0;								//FIFO空
    3082:	b342      	st.w      	r2, (r3, 0x8)
				SPI0->DR=0x0;								//FIFO空
    3084:	b342      	st.w      	r2, (r3, 0x8)
				while(((SPI0->SR) & SSP_BSY) == SSP_BSY);		//发送或接收是否完成？
    3086:	9343      	ld.w      	r2, (r3, 0xc)
    3088:	6884      	and      	r2, r1
    308a:	3a40      	cmpnei      	r2, 0
    308c:	0bfd      	bt      	0x3086	// 3086 <SPI0IntHandler+0x11a>
    308e:	07ed      	br      	0x3068	// 3068 <SPI0IntHandler+0xfc>
	else if((SPI0->MISR&SPI_TXIM)==SPI_TXIM)				//Transmit FIFO Interrupt
    3090:	9347      	ld.w      	r2, (r3, 0x1c)
    3092:	e4422008 	andi      	r2, r2, 8
    3096:	3a40      	cmpnei      	r2, 0
    3098:	0fe8      	bf      	0x3068	// 3068 <SPI0IntHandler+0xfc>
		SPI0->ICR = SPI_TXIM;
    309a:	3208      	movi      	r2, 8
    309c:	0772      	br      	0x2f80	// 2f80 <SPI0IntHandler+0x14>
    309e:	0000      	bkpt
    30a0:	20000064 	.long	0x20000064

Disassembly of section .text.SIO0IntHandler:

000030a4 <SIO0IntHandler>:
//SIO Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SIO0IntHandler(void) 
{
    30a4:	1460      	nie
    30a6:	1462      	ipush
	CK801->IPR[5]=0X40404000;
	CK801->IPR[6]=0X40404040;
	CK801->IPR[7]=0X40404040;*/
	
	//序列小于16bit发送程序
	if(SIO0->MISR&SIO_TXDNE)							//TXDNE
    30a8:	1160      	lrw      	r3, 0x2000005c	// 3128 <SIO0IntHandler+0x84>
    30aa:	9360      	ld.w      	r3, (r3, 0x0)
    30ac:	9349      	ld.w      	r2, (r3, 0x24)
    30ae:	e4422001 	andi      	r2, r2, 1
    30b2:	3a40      	cmpnei      	r2, 0
    30b4:	0c05      	bf      	0x30be	// 30be <SIO0IntHandler+0x1a>
	{
		SIO0->ICR=SIO_TXDNE;
    30b6:	3201      	movi      	r2, 1
		if(R_SIORX_count>=2)
			R_SIORX_count=0;
	}
	else if(SIO0->MISR&SIO_BREAK)						//BREAK
	{
		SIO0->ICR=SIO_BREAK;
    30b8:	b34b      	st.w      	r2, (r3, 0x2c)
		nop;
    30ba:	6c03      	mov      	r0, r0
    30bc:	0426      	br      	0x3108	// 3108 <SIO0IntHandler+0x64>
	else if(SIO0->MISR&SIO_RXDNE)						//RXDNE 
    30be:	9349      	ld.w      	r2, (r3, 0x24)
    30c0:	e4422002 	andi      	r2, r2, 2
    30c4:	3a40      	cmpnei      	r2, 0
    30c6:	0c04      	bf      	0x30ce	// 30ce <SIO0IntHandler+0x2a>
		SIO0->ICR=SIO_RXDNE;
    30c8:	3202      	movi      	r2, 2
	}
	else if(SIO0->MISR&SIO_TIME)						//TIMEOUT
	{
		SIO0->ICR=SIO_TIME;
    30ca:	b34b      	st.w      	r2, (r3, 0x2c)
	}
}
    30cc:	041e      	br      	0x3108	// 3108 <SIO0IntHandler+0x64>
	else if(SIO0->MISR&SIO_TXBUFEMPT)
    30ce:	9349      	ld.w      	r2, (r3, 0x24)
    30d0:	e4422004 	andi      	r2, r2, 4
    30d4:	3a40      	cmpnei      	r2, 0
    30d6:	0c03      	bf      	0x30dc	// 30dc <SIO0IntHandler+0x38>
		SIO0->ICR=SIO_TXBUFEMPT;
    30d8:	3204      	movi      	r2, 4
    30da:	07f8      	br      	0x30ca	// 30ca <SIO0IntHandler+0x26>
	else if(SIO0->MISR&SIO_RXBUFEMPT)					//RXBUFFULL	
    30dc:	9349      	ld.w      	r2, (r3, 0x24)
    30de:	e4422008 	andi      	r2, r2, 8
    30e2:	3a40      	cmpnei      	r2, 0
    30e4:	0c14      	bf      	0x310c	// 310c <SIO0IntHandler+0x68>
		SIO0->ICR=SIO_RXBUFEMPT;
    30e6:	3208      	movi      	r2, 8
    30e8:	b34b      	st.w      	r2, (r3, 0x2c)
			R_SIORX_buf[R_SIORX_count]=SIO0->RXBUF;		
    30ea:	1051      	lrw      	r2, 0x200002f0	// 312c <SIO0IntHandler+0x88>
    30ec:	9220      	ld.w      	r1, (r2, 0x0)
    30ee:	9307      	ld.w      	r0, (r3, 0x1c)
    30f0:	4162      	lsli      	r3, r1, 2
    30f2:	1030      	lrw      	r1, 0x200002f4	// 3130 <SIO0IntHandler+0x8c>
    30f4:	60c4      	addu      	r3, r1
    30f6:	b300      	st.w      	r0, (r3, 0x0)
			R_SIORX_count++;
    30f8:	9260      	ld.w      	r3, (r2, 0x0)
    30fa:	2300      	addi      	r3, 1
    30fc:	b260      	st.w      	r3, (r2, 0x0)
		if(R_SIORX_count>=2)
    30fe:	9260      	ld.w      	r3, (r2, 0x0)
    3100:	3b21      	cmplti      	r3, 2
    3102:	0803      	bt      	0x3108	// 3108 <SIO0IntHandler+0x64>
			R_SIORX_count=0;
    3104:	3300      	movi      	r3, 0
    3106:	b260      	st.w      	r3, (r2, 0x0)
}
    3108:	1463      	ipop
    310a:	1461      	nir
	else if(SIO0->MISR&SIO_BREAK)						//BREAK
    310c:	9349      	ld.w      	r2, (r3, 0x24)
    310e:	e4422010 	andi      	r2, r2, 16
    3112:	3a40      	cmpnei      	r2, 0
    3114:	0c03      	bf      	0x311a	// 311a <SIO0IntHandler+0x76>
		SIO0->ICR=SIO_BREAK;
    3116:	3210      	movi      	r2, 16
    3118:	07d0      	br      	0x30b8	// 30b8 <SIO0IntHandler+0x14>
	else if(SIO0->MISR&SIO_TIME)						//TIMEOUT
    311a:	9349      	ld.w      	r2, (r3, 0x24)
    311c:	e4422020 	andi      	r2, r2, 32
    3120:	3a40      	cmpnei      	r2, 0
    3122:	0ff3      	bf      	0x3108	// 3108 <SIO0IntHandler+0x64>
		SIO0->ICR=SIO_TIME;
    3124:	3220      	movi      	r2, 32
    3126:	07d2      	br      	0x30ca	// 30ca <SIO0IntHandler+0x26>
    3128:	2000005c 	.long	0x2000005c
    312c:	200002f0 	.long	0x200002f0
    3130:	200002f4 	.long	0x200002f4

Disassembly of section .text.EXI0IntHandler:

00003134 <EXI0IntHandler>:
//EXT0/16 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI0IntHandler(void) 
{
    3134:	1460      	nie
    3136:	1462      	ipush
    // ISR content ...
	if ((SYSCON->EXIRS&EXI_PIN0)==EXI_PIN0) 			//EXT0 Interrupt
    3138:	106b      	lrw      	r3, 0x200000a0	// 3164 <EXI0IntHandler+0x30>
    313a:	9360      	ld.w      	r3, (r3, 0x0)
    313c:	d843202c 	ld.w      	r2, (r3, 0xb0)
    3140:	e4422001 	andi      	r2, r2, 1
    3144:	3a40      	cmpnei      	r2, 0
    3146:	0c05      	bf      	0x3150	// 3150 <EXI0IntHandler+0x1c>
	{
		SYSCON->EXICR = EXI_PIN0;
    3148:	3201      	movi      	r2, 1
	}
	else if ((SYSCON->EXIRS&EXI_PIN16)==EXI_PIN16) 		//EXT16 Interrupt
	{
		SYSCON->EXICR = EXI_PIN16;
    314a:	dc43202b 	st.w      	r2, (r3, 0xac)
	}
}
    314e:	0408      	br      	0x315e	// 315e <EXI0IntHandler+0x2a>
	else if ((SYSCON->EXIRS&EXI_PIN16)==EXI_PIN16) 		//EXT16 Interrupt
    3150:	3280      	movi      	r2, 128
    3152:	d823202c 	ld.w      	r1, (r3, 0xb0)
    3156:	4249      	lsli      	r2, r2, 9
    3158:	6848      	and      	r1, r2
    315a:	3940      	cmpnei      	r1, 0
    315c:	0bf7      	bt      	0x314a	// 314a <EXI0IntHandler+0x16>
}
    315e:	1463      	ipop
    3160:	1461      	nir
    3162:	0000      	bkpt
    3164:	200000a0 	.long	0x200000a0

Disassembly of section .text.EXI1IntHandler:

00003168 <EXI1IntHandler>:
//EXT1/17 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI1IntHandler(void) 
{
    3168:	1460      	nie
    316a:	1462      	ipush
    // ISR content ...
	if ((SYSCON->EXIRS&EXI_PIN1)==EXI_PIN1) 			//EXT1 Interrupt
    316c:	106b      	lrw      	r3, 0x200000a0	// 3198 <EXI1IntHandler+0x30>
    316e:	9360      	ld.w      	r3, (r3, 0x0)
    3170:	d843202c 	ld.w      	r2, (r3, 0xb0)
    3174:	e4422002 	andi      	r2, r2, 2
    3178:	3a40      	cmpnei      	r2, 0
    317a:	0c05      	bf      	0x3184	// 3184 <EXI1IntHandler+0x1c>
	{
		SYSCON->EXICR = EXI_PIN1;
    317c:	3202      	movi      	r2, 2
	}
	else if ((SYSCON->EXIRS&EXI_PIN17)==EXI_PIN17) 		//EXT17 Interrupt
	{
		SYSCON->EXICR = EXI_PIN17;
    317e:	dc43202b 	st.w      	r2, (r3, 0xac)
	}
}
    3182:	0408      	br      	0x3192	// 3192 <EXI1IntHandler+0x2a>
	else if ((SYSCON->EXIRS&EXI_PIN17)==EXI_PIN17) 		//EXT17 Interrupt
    3184:	3280      	movi      	r2, 128
    3186:	d823202c 	ld.w      	r1, (r3, 0xb0)
    318a:	424a      	lsli      	r2, r2, 10
    318c:	6848      	and      	r1, r2
    318e:	3940      	cmpnei      	r1, 0
    3190:	0bf7      	bt      	0x317e	// 317e <EXI1IntHandler+0x16>
}
    3192:	1463      	ipop
    3194:	1461      	nir
    3196:	0000      	bkpt
    3198:	200000a0 	.long	0x200000a0

Disassembly of section .text.EXI2to3IntHandler:

0000319c <EXI2to3IntHandler>:
//EXI2~3 18~19Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI2to3IntHandler(void) 
{
    319c:	1460      	nie
    319e:	1462      	ipush
    // ISR content ...
	if ((SYSCON->EXIRS&EXI_PIN2)==EXI_PIN2) 			//EXT2 Interrupt
    31a0:	1072      	lrw      	r3, 0x200000a0	// 31e8 <EXI2to3IntHandler+0x4c>
    31a2:	9360      	ld.w      	r3, (r3, 0x0)
    31a4:	d843202c 	ld.w      	r2, (r3, 0xb0)
    31a8:	e4422004 	andi      	r2, r2, 4
    31ac:	3a40      	cmpnei      	r2, 0
    31ae:	0c05      	bf      	0x31b8	// 31b8 <EXI2to3IntHandler+0x1c>
	{
		SYSCON->EXICR = EXI_PIN2;
    31b0:	3204      	movi      	r2, 4
	{
		SYSCON->EXICR = EXI_PIN18;
	}
	else if ((SYSCON->EXIRS&EXI_PIN19)==EXI_PIN19) 		//EXT19 Interrupt
	{
		SYSCON->EXICR = EXI_PIN19;
    31b2:	dc43202b 	st.w      	r2, (r3, 0xac)
	}
}
    31b6:	0417      	br      	0x31e4	// 31e4 <EXI2to3IntHandler+0x48>
	else if ((SYSCON->EXIRS&EXI_PIN3)==EXI_PIN3) 		//EXT3 Interrupt
    31b8:	d843202c 	ld.w      	r2, (r3, 0xb0)
    31bc:	e4422008 	andi      	r2, r2, 8
    31c0:	3a40      	cmpnei      	r2, 0
    31c2:	0c03      	bf      	0x31c8	// 31c8 <EXI2to3IntHandler+0x2c>
		SYSCON->EXICR = EXI_PIN3;
    31c4:	3208      	movi      	r2, 8
    31c6:	07f6      	br      	0x31b2	// 31b2 <EXI2to3IntHandler+0x16>
	else if ((SYSCON->EXIRS&EXI_PIN18)==EXI_PIN18) 		//EXT18 Interrupt
    31c8:	3280      	movi      	r2, 128
    31ca:	d823202c 	ld.w      	r1, (r3, 0xb0)
    31ce:	424b      	lsli      	r2, r2, 11
    31d0:	6848      	and      	r1, r2
    31d2:	3940      	cmpnei      	r1, 0
    31d4:	0bef      	bt      	0x31b2	// 31b2 <EXI2to3IntHandler+0x16>
	else if ((SYSCON->EXIRS&EXI_PIN19)==EXI_PIN19) 		//EXT19 Interrupt
    31d6:	3280      	movi      	r2, 128
    31d8:	d823202c 	ld.w      	r1, (r3, 0xb0)
    31dc:	424c      	lsli      	r2, r2, 12
    31de:	6848      	and      	r1, r2
    31e0:	3940      	cmpnei      	r1, 0
    31e2:	0be8      	bt      	0x31b2	// 31b2 <EXI2to3IntHandler+0x16>
}
    31e4:	1463      	ipop
    31e6:	1461      	nir
    31e8:	200000a0 	.long	0x200000a0

Disassembly of section .text.EXI4to9IntHandler:

000031ec <EXI4to9IntHandler>:
//EXI4~9 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI4to9IntHandler(void) 
{
    31ec:	1460      	nie
    31ee:	1462      	ipush
    // ISR content ...
	if ((SYSCON->EXIRS&EXI_PIN4)==EXI_PIN4) 			//EXT4 Interrupt
    31f0:	107c      	lrw      	r3, 0x200000a0	// 3260 <EXI4to9IntHandler+0x74>
    31f2:	9360      	ld.w      	r3, (r3, 0x0)
    31f4:	d843202c 	ld.w      	r2, (r3, 0xb0)
    31f8:	e4422010 	andi      	r2, r2, 16
    31fc:	3a40      	cmpnei      	r2, 0
    31fe:	0c06      	bf      	0x320a	// 320a <EXI4to9IntHandler+0x1e>
	{
		SYSCON->EXICR = EXI_PIN4;
    3200:	3210      	movi      	r2, 16
	{
		SYSCON->EXICR = EXI_PIN8;
	}
	else if ((SYSCON->EXIRS&EXI_PIN9)==EXI_PIN9) 		//EXT9 Interrupt
	{
		SYSCON->EXICR = EXI_PIN9;
    3202:	dc43202b 	st.w      	r2, (r3, 0xac)
	} 

}
    3206:	1463      	ipop
    3208:	1461      	nir
	else if ((SYSCON->EXIRS&EXI_PIN5)==EXI_PIN5) 		//EXT5 Interrupt
    320a:	d843202c 	ld.w      	r2, (r3, 0xb0)
    320e:	e4422020 	andi      	r2, r2, 32
    3212:	3a40      	cmpnei      	r2, 0
    3214:	0c03      	bf      	0x321a	// 321a <EXI4to9IntHandler+0x2e>
		SYSCON->EXICR = EXI_PIN5;
    3216:	3220      	movi      	r2, 32
    3218:	07f5      	br      	0x3202	// 3202 <EXI4to9IntHandler+0x16>
	else if ((SYSCON->EXIRS&EXI_PIN6)==EXI_PIN6) 		//EXT6 Interrupt
    321a:	d843202c 	ld.w      	r2, (r3, 0xb0)
    321e:	e4422040 	andi      	r2, r2, 64
    3222:	3a40      	cmpnei      	r2, 0
    3224:	0c03      	bf      	0x322a	// 322a <EXI4to9IntHandler+0x3e>
		SYSCON->EXICR = EXI_PIN6;
    3226:	3240      	movi      	r2, 64
    3228:	07ed      	br      	0x3202	// 3202 <EXI4to9IntHandler+0x16>
	else if ((SYSCON->EXIRS&EXI_PIN7)==EXI_PIN7) 		//EXT7 Interrupt
    322a:	d843202c 	ld.w      	r2, (r3, 0xb0)
    322e:	e4422080 	andi      	r2, r2, 128
    3232:	3a40      	cmpnei      	r2, 0
    3234:	0c03      	bf      	0x323a	// 323a <EXI4to9IntHandler+0x4e>
		SYSCON->EXICR = EXI_PIN7;
    3236:	3280      	movi      	r2, 128
    3238:	07e5      	br      	0x3202	// 3202 <EXI4to9IntHandler+0x16>
	else if ((SYSCON->EXIRS&EXI_PIN8)==EXI_PIN8) 		//EXT8 Interrupt
    323a:	d843202c 	ld.w      	r2, (r3, 0xb0)
    323e:	e4422100 	andi      	r2, r2, 256
    3242:	3a40      	cmpnei      	r2, 0
    3244:	0c04      	bf      	0x324c	// 324c <EXI4to9IntHandler+0x60>
		SYSCON->EXICR = EXI_PIN8;
    3246:	3280      	movi      	r2, 128
    3248:	4241      	lsli      	r2, r2, 1
    324a:	07dc      	br      	0x3202	// 3202 <EXI4to9IntHandler+0x16>
	else if ((SYSCON->EXIRS&EXI_PIN9)==EXI_PIN9) 		//EXT9 Interrupt
    324c:	d843202c 	ld.w      	r2, (r3, 0xb0)
    3250:	e4422200 	andi      	r2, r2, 512
    3254:	3a40      	cmpnei      	r2, 0
    3256:	0fd8      	bf      	0x3206	// 3206 <EXI4to9IntHandler+0x1a>
		SYSCON->EXICR = EXI_PIN9;
    3258:	3280      	movi      	r2, 128
    325a:	4242      	lsli      	r2, r2, 2
    325c:	07d3      	br      	0x3202	// 3202 <EXI4to9IntHandler+0x16>
    325e:	0000      	bkpt
    3260:	200000a0 	.long	0x200000a0

Disassembly of section .text.EXI10to15IntHandler:

00003264 <EXI10to15IntHandler>:
//EXI4 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI10to15IntHandler(void) 
{
    3264:	1460      	nie
    3266:	1462      	ipush
    // ISR content ...
	if ((SYSCON->EXIRS&EXI_PIN10)==EXI_PIN10) 			//EXT10 Interrupt
    3268:	107a      	lrw      	r3, 0x200000a0	// 32d0 <EXI10to15IntHandler+0x6c>
    326a:	9360      	ld.w      	r3, (r3, 0x0)
    326c:	d843202c 	ld.w      	r2, (r3, 0xb0)
    3270:	e4422400 	andi      	r2, r2, 1024
    3274:	3a40      	cmpnei      	r2, 0
    3276:	0c06      	bf      	0x3282	// 3282 <EXI10to15IntHandler+0x1e>
	{
		SYSCON->EXICR = EXI_PIN10;
    3278:	3280      	movi      	r2, 128
    327a:	4243      	lsli      	r2, r2, 3
	{
		SYSCON->EXICR = EXI_PIN14;
	}
	else if ((SYSCON->EXIRS&EXI_PIN15)==EXI_PIN15) 		//EXT15 Interrupt
	{
		SYSCON->EXICR = EXI_PIN15;
    327c:	dc43202b 	st.w      	r2, (r3, 0xac)
	}
}
    3280:	0426      	br      	0x32cc	// 32cc <EXI10to15IntHandler+0x68>
	else if ((SYSCON->EXIRS&EXI_PIN11)==EXI_PIN11) 		//EXT11 Interrupt
    3282:	d843202c 	ld.w      	r2, (r3, 0xb0)
    3286:	e4422800 	andi      	r2, r2, 2048
    328a:	3a40      	cmpnei      	r2, 0
    328c:	0c04      	bf      	0x3294	// 3294 <EXI10to15IntHandler+0x30>
		SYSCON->EXICR = EXI_PIN11;
    328e:	3280      	movi      	r2, 128
    3290:	4244      	lsli      	r2, r2, 4
    3292:	07f5      	br      	0x327c	// 327c <EXI10to15IntHandler+0x18>
	else if ((SYSCON->EXIRS&EXI_PIN12)==EXI_PIN12) 		//EXT12 Interrupt
    3294:	3280      	movi      	r2, 128
    3296:	d823202c 	ld.w      	r1, (r3, 0xb0)
    329a:	4245      	lsli      	r2, r2, 5
    329c:	6848      	and      	r1, r2
    329e:	3940      	cmpnei      	r1, 0
    32a0:	0bee      	bt      	0x327c	// 327c <EXI10to15IntHandler+0x18>
	else if ((SYSCON->EXIRS&EXI_PIN13)==EXI_PIN13) 		//EXT13 Interrupt
    32a2:	3280      	movi      	r2, 128
    32a4:	d823202c 	ld.w      	r1, (r3, 0xb0)
    32a8:	4246      	lsli      	r2, r2, 6
    32aa:	6848      	and      	r1, r2
    32ac:	3940      	cmpnei      	r1, 0
    32ae:	0be7      	bt      	0x327c	// 327c <EXI10to15IntHandler+0x18>
	else if ((SYSCON->EXIRS&EXI_PIN14)==EXI_PIN14) 		//EXT14 Interrupt
    32b0:	3280      	movi      	r2, 128
    32b2:	d823202c 	ld.w      	r1, (r3, 0xb0)
    32b6:	4247      	lsli      	r2, r2, 7
    32b8:	6848      	and      	r1, r2
    32ba:	3940      	cmpnei      	r1, 0
    32bc:	0be0      	bt      	0x327c	// 327c <EXI10to15IntHandler+0x18>
	else if ((SYSCON->EXIRS&EXI_PIN15)==EXI_PIN15) 		//EXT15 Interrupt
    32be:	3280      	movi      	r2, 128
    32c0:	d823202c 	ld.w      	r1, (r3, 0xb0)
    32c4:	4248      	lsli      	r2, r2, 8
    32c6:	6848      	and      	r1, r2
    32c8:	3940      	cmpnei      	r1, 0
    32ca:	0bd9      	bt      	0x327c	// 327c <EXI10to15IntHandler+0x18>
}
    32cc:	1463      	ipop
    32ce:	1461      	nir
    32d0:	200000a0 	.long	0x200000a0

Disassembly of section .text.LPTIntHandler:

000032d4 <LPTIntHandler>:
//LPT Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void LPTIntHandler(void) 
{
    32d4:	1460      	nie
    32d6:	1462      	ipush
    // ISR content ...
	if((LPT->MISR&LPT_TRGEV0)==LPT_TRGEV0)			//TRGEV0 interrupt
    32d8:	106d      	lrw      	r3, 0x20000038	// 330c <LPTIntHandler+0x38>
    32da:	9360      	ld.w      	r3, (r3, 0x0)
    32dc:	934e      	ld.w      	r2, (r3, 0x38)
    32de:	e4422001 	andi      	r2, r2, 1
    32e2:	3a40      	cmpnei      	r2, 0
    32e4:	0c05      	bf      	0x32ee	// 32ee <LPTIntHandler+0x1a>
	{
		LPT->ICR = LPT_TRGEV0;
    32e6:	3201      	movi      	r2, 1
	{
		LPT->ICR = LPT_MATCH;
	}
	else if((LPT->MISR&LPT_PEND)==LPT_PEND)			//PEND interrupt
	{
		LPT->ICR = LPT_PEND;
    32e8:	b350      	st.w      	r2, (r3, 0x40)
	}
}
    32ea:	1463      	ipop
    32ec:	1461      	nir
	else if((LPT->MISR&LPT_MATCH)==LPT_MATCH)		//MATCH interrupt
    32ee:	934e      	ld.w      	r2, (r3, 0x38)
    32f0:	e4422002 	andi      	r2, r2, 2
    32f4:	3a40      	cmpnei      	r2, 0
    32f6:	0c03      	bf      	0x32fc	// 32fc <LPTIntHandler+0x28>
		LPT->ICR = LPT_MATCH;
    32f8:	3202      	movi      	r2, 2
    32fa:	07f7      	br      	0x32e8	// 32e8 <LPTIntHandler+0x14>
	else if((LPT->MISR&LPT_PEND)==LPT_PEND)			//PEND interrupt
    32fc:	934e      	ld.w      	r2, (r3, 0x38)
    32fe:	e4422004 	andi      	r2, r2, 4
    3302:	3a40      	cmpnei      	r2, 0
    3304:	0ff3      	bf      	0x32ea	// 32ea <LPTIntHandler+0x16>
		LPT->ICR = LPT_PEND;
    3306:	3204      	movi      	r2, 4
    3308:	07f0      	br      	0x32e8	// 32e8 <LPTIntHandler+0x14>
    330a:	0000      	bkpt
    330c:	20000038 	.long	0x20000038

Disassembly of section .text.BT0IntHandler:

00003310 <BT0IntHandler>:
//BT0 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void BT0IntHandler(void) 
{
    3310:	1460      	nie
    3312:	1462      	ipush
    // ISR content ...
	if((BT0->MISR&BT_PEND)==BT_PEND)				//BT0 PEND interrupt
    3314:	1070      	lrw      	r3, 0x20000030	// 3354 <BT0IntHandler+0x44>
    3316:	9360      	ld.w      	r3, (r3, 0x0)
    3318:	934c      	ld.w      	r2, (r3, 0x30)
    331a:	e4422001 	andi      	r2, r2, 1
    331e:	3a40      	cmpnei      	r2, 0
    3320:	0c05      	bf      	0x332a	// 332a <BT0IntHandler+0x1a>
	{
		BT0->ICR = BT_PEND;
    3322:	3201      	movi      	r2, 1
	{
		BT0->ICR = BT_OVF;
	} 
	else if((BT0->MISR&BT_EVTRG)==BT_EVTRG)			//BT0 Event trigger interrupt
	{
		BT0->ICR = BT_EVTRG;
    3324:	b34d      	st.w      	r2, (r3, 0x34)
	}
}
    3326:	1463      	ipop
    3328:	1461      	nir
	else if((BT0->MISR&BT_CMP)==BT_CMP)				//BT0 CMP Match interrupt 
    332a:	934c      	ld.w      	r2, (r3, 0x30)
    332c:	e4422002 	andi      	r2, r2, 2
    3330:	3a40      	cmpnei      	r2, 0
    3332:	0c03      	bf      	0x3338	// 3338 <BT0IntHandler+0x28>
		BT0->ICR = BT_CMP;
    3334:	3202      	movi      	r2, 2
    3336:	07f7      	br      	0x3324	// 3324 <BT0IntHandler+0x14>
	else if((BT0->MISR&BT_OVF)==BT_OVF)				//BT0 OVF interrupt
    3338:	934c      	ld.w      	r2, (r3, 0x30)
    333a:	e4422004 	andi      	r2, r2, 4
    333e:	3a40      	cmpnei      	r2, 0
    3340:	0c03      	bf      	0x3346	// 3346 <BT0IntHandler+0x36>
		BT0->ICR = BT_OVF;
    3342:	3204      	movi      	r2, 4
    3344:	07f0      	br      	0x3324	// 3324 <BT0IntHandler+0x14>
	else if((BT0->MISR&BT_EVTRG)==BT_EVTRG)			//BT0 Event trigger interrupt
    3346:	934c      	ld.w      	r2, (r3, 0x30)
    3348:	e4422008 	andi      	r2, r2, 8
    334c:	3a40      	cmpnei      	r2, 0
    334e:	0fec      	bf      	0x3326	// 3326 <BT0IntHandler+0x16>
		BT0->ICR = BT_EVTRG;
    3350:	3208      	movi      	r2, 8
    3352:	07e9      	br      	0x3324	// 3324 <BT0IntHandler+0x14>
    3354:	20000030 	.long	0x20000030

Disassembly of section .text.BT1IntHandler:

00003358 <BT1IntHandler>:
//BT1 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void BT1IntHandler(void) 
{
    3358:	1460      	nie
    335a:	1462      	ipush
    // ISR content ...
	if((BT1->MISR&BT_PEND)==BT_PEND)				//BT1 PEND interrupt
    335c:	1071      	lrw      	r3, 0x2000002c	// 33a0 <BT1IntHandler+0x48>
    335e:	9360      	ld.w      	r3, (r3, 0x0)
    3360:	934c      	ld.w      	r2, (r3, 0x30)
    3362:	e4422001 	andi      	r2, r2, 1
    3366:	3a40      	cmpnei      	r2, 0
    3368:	0c05      	bf      	0x3372	// 3372 <BT1IntHandler+0x1a>
	{
		BT1->ICR = BT_PEND;
    336a:	3201      	movi      	r2, 1
	{
		BT1->ICR = BT_OVF;
	} 
	else if((BT0->MISR&BT_EVTRG)==BT_EVTRG)			//BT1 Event trigger interrupt
	{
		BT1->ICR = BT_EVTRG;
    336c:	b34d      	st.w      	r2, (r3, 0x34)
	} 
}
    336e:	1463      	ipop
    3370:	1461      	nir
	else if((BT0->MISR&BT_CMP)==BT_CMP)				//BT1 CMP Match interrupt 
    3372:	104d      	lrw      	r2, 0x20000030	// 33a4 <BT1IntHandler+0x4c>
    3374:	9240      	ld.w      	r2, (r2, 0x0)
    3376:	922c      	ld.w      	r1, (r2, 0x30)
    3378:	e4212002 	andi      	r1, r1, 2
    337c:	3940      	cmpnei      	r1, 0
    337e:	0c03      	bf      	0x3384	// 3384 <BT1IntHandler+0x2c>
		BT1->ICR = BT_CMP;
    3380:	3202      	movi      	r2, 2
    3382:	07f5      	br      	0x336c	// 336c <BT1IntHandler+0x14>
	else if((BT0->MISR&BT_OVF)==BT_OVF)				//BT1 OVF interrupt
    3384:	922c      	ld.w      	r1, (r2, 0x30)
    3386:	e4212004 	andi      	r1, r1, 4
    338a:	3940      	cmpnei      	r1, 0
    338c:	0c03      	bf      	0x3392	// 3392 <BT1IntHandler+0x3a>
		BT1->ICR = BT_OVF;
    338e:	3204      	movi      	r2, 4
    3390:	07ee      	br      	0x336c	// 336c <BT1IntHandler+0x14>
	else if((BT0->MISR&BT_EVTRG)==BT_EVTRG)			//BT1 Event trigger interrupt
    3392:	924c      	ld.w      	r2, (r2, 0x30)
    3394:	e4422008 	andi      	r2, r2, 8
    3398:	3a40      	cmpnei      	r2, 0
    339a:	0fea      	bf      	0x336e	// 336e <BT1IntHandler+0x16>
		BT1->ICR = BT_EVTRG;
    339c:	3208      	movi      	r2, 8
    339e:	07e7      	br      	0x336c	// 336c <BT1IntHandler+0x14>
    33a0:	2000002c 	.long	0x2000002c
    33a4:	20000030 	.long	0x20000030

Disassembly of section .text.LEDIntHandler:

000033a8 <LEDIntHandler>:
//LED Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void LEDIntHandler(void) 
{
    33a8:	1460      	nie
    33aa:	1462      	ipush
    // ISR content ...
	if ((LED0->MISR &ICEND)==ICEND) 
    33ac:	1069      	lrw      	r3, 0x20000020	// 33d0 <LEDIntHandler+0x28>
    33ae:	9360      	ld.w      	r3, (r3, 0x0)
    33b0:	9344      	ld.w      	r2, (r3, 0x10)
    33b2:	e4422001 	andi      	r2, r2, 1
    33b6:	3a40      	cmpnei      	r2, 0
    33b8:	0c05      	bf      	0x33c2	// 33c2 <LEDIntHandler+0x1a>
    {
        LED0->ICR = ICEND;
    33ba:	3201      	movi      	r2, 1
    } 
    else if((LED0->MISR &IPEND)==IPEND) 
    {
        LED0->ICR = IPEND;
    33bc:	b345      	st.w      	r2, (r3, 0x14)
    } 
}
    33be:	1463      	ipop
    33c0:	1461      	nir
    else if((LED0->MISR &IPEND)==IPEND) 
    33c2:	9344      	ld.w      	r2, (r3, 0x10)
    33c4:	e4422002 	andi      	r2, r2, 2
    33c8:	3a40      	cmpnei      	r2, 0
    33ca:	0ffa      	bf      	0x33be	// 33be <LEDIntHandler+0x16>
        LED0->ICR = IPEND;
    33cc:	3202      	movi      	r2, 2
    33ce:	07f7      	br      	0x33bc	// 33bc <LEDIntHandler+0x14>
    33d0:	20000020 	.long	0x20000020

Disassembly of section .text.CMPIntHandler:

000033d4 <CMPIntHandler>:
//CMP Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CMPIntHandler(void) 
{
    33d4:	1460      	nie
    33d6:	1462      	ipush
	if((CMP0->MISR & MISR_EDGEDET0)==MISR_EDGEDET0) 
    33d8:	1072      	lrw      	r3, 0x2000001c	// 3420 <CMPIntHandler+0x4c>
    33da:	9360      	ld.w      	r3, (r3, 0x0)
    33dc:	9348      	ld.w      	r2, (r3, 0x20)
    33de:	e4422001 	andi      	r2, r2, 1
    33e2:	3a40      	cmpnei      	r2, 0
    33e4:	0c04      	bf      	0x33ec	// 33ec <CMPIntHandler+0x18>
	{
		CMP0->ICR =	EDGEDET;
    33e6:	3201      	movi      	r2, 1
	}
	else if((CMP0->MISR & MISR_RAWDET0)==MISR_RAWDET0) 
	{
		CMP0->ICR =	RAWDET;
    33e8:	b349      	st.w      	r2, (r3, 0x24)
    33ea:	0407      	br      	0x33f8	// 33f8 <CMPIntHandler+0x24>
	else if((CMP0->MISR & MISR_RAWDET0)==MISR_RAWDET0) 
    33ec:	3280      	movi      	r2, 128
    33ee:	9328      	ld.w      	r1, (r3, 0x20)
    33f0:	4249      	lsli      	r2, r2, 9
    33f2:	6848      	and      	r1, r2
    33f4:	3940      	cmpnei      	r1, 0
    33f6:	0bf9      	bt      	0x33e8	// 33e8 <CMPIntHandler+0x14>
	}
	if((CMP1->MISR & MISR_EDGEDET1)==MISR_EDGEDET1) 
    33f8:	106b      	lrw      	r3, 0x20000018	// 3424 <CMPIntHandler+0x50>
    33fa:	9360      	ld.w      	r3, (r3, 0x0)
    33fc:	9348      	ld.w      	r2, (r3, 0x20)
    33fe:	e4422002 	andi      	r2, r2, 2
    3402:	3a40      	cmpnei      	r2, 0
    3404:	0c05      	bf      	0x340e	// 340e <CMPIntHandler+0x3a>
	{
		CMP1->ICR =	EDGEDET;
    3406:	3201      	movi      	r2, 1
	}
	else if((CMP1->MISR & MISR_RAWDET1)==MISR_RAWDET1) 
	{
		CMP1->ICR =	RAWDET;
    3408:	b349      	st.w      	r2, (r3, 0x24)
	}
}
    340a:	1463      	ipop
    340c:	1461      	nir
	else if((CMP1->MISR & MISR_RAWDET1)==MISR_RAWDET1) 
    340e:	3180      	movi      	r1, 128
    3410:	9348      	ld.w      	r2, (r3, 0x20)
    3412:	412a      	lsli      	r1, r1, 10
    3414:	6884      	and      	r2, r1
    3416:	3a40      	cmpnei      	r2, 0
    3418:	0ff9      	bf      	0x340a	// 340a <CMPIntHandler+0x36>
		CMP1->ICR =	RAWDET;
    341a:	3280      	movi      	r2, 128
    341c:	4249      	lsli      	r2, r2, 9
    341e:	07f5      	br      	0x3408	// 3408 <CMPIntHandler+0x34>
    3420:	2000001c 	.long	0x2000001c
    3424:	20000018 	.long	0x20000018

Disassembly of section .text.TKEYIntHandler:

00003428 <TKEYIntHandler>:
//TKEY Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void TKEYIntHandler(void)
{
    3428:	1460      	nie
    342a:	1462      	ipush
    342c:	14d0      	push      	r15
	csi_tkey_int_process();
    342e:	e3fff0d4 	bsr      	0x15d6	// 15d6 <csi_tkey_int_process>
}
    3432:	d9ee2000 	ld.w      	r15, (r14, 0x0)
    3436:	1401      	addi      	r14, r14, 4
    3438:	1463      	ipop
    343a:	1461      	nir

Disassembly of section .text.PriviledgeVioHandler:

0000343c <PriviledgeVioHandler>:
    343c:	783c      	jmp      	r15

Disassembly of section .text.PendTrapHandler:

0000343e <PendTrapHandler>:
    // ISR content ...

}

void PendTrapHandler(void) 
{
    343e:	1460      	nie
    3440:	1462      	ipush
    // ISR content ...

}
    3442:	1463      	ipop
    3444:	1461      	nir

Disassembly of section .text.Trap3Handler:

00003446 <Trap3Handler>:
    3446:	1460      	nie
    3448:	1462      	ipush
    344a:	1463      	ipop
    344c:	1461      	nir

Disassembly of section .text.Trap2Handler:

0000344e <Trap2Handler>:
    344e:	1460      	nie
    3450:	1462      	ipush
    3452:	1463      	ipop
    3454:	1461      	nir

Disassembly of section .text.Trap1Handler:

00003456 <Trap1Handler>:
    3456:	1460      	nie
    3458:	1462      	ipush
    345a:	1463      	ipop
    345c:	1461      	nir

Disassembly of section .text.Trap0Handler:

0000345e <Trap0Handler>:
    345e:	1460      	nie
    3460:	1462      	ipush
    3462:	1463      	ipop
    3464:	1461      	nir

Disassembly of section .text.UnrecExecpHandler:

00003466 <UnrecExecpHandler>:
    3466:	1460      	nie
    3468:	1462      	ipush
    346a:	1463      	ipop
    346c:	1461      	nir

Disassembly of section .text.BreakPointHandler:

0000346e <BreakPointHandler>:
    346e:	1460      	nie
    3470:	1462      	ipush
    3472:	1463      	ipop
    3474:	1461      	nir

Disassembly of section .text.AccessErrHandler:

00003476 <AccessErrHandler>:
    3476:	1460      	nie
    3478:	1462      	ipush
    347a:	1463      	ipop
    347c:	1461      	nir

Disassembly of section .text.IllegalInstrHandler:

0000347e <IllegalInstrHandler>:
    347e:	1460      	nie
    3480:	1462      	ipush
    3482:	1463      	ipop
    3484:	1461      	nir

Disassembly of section .text.MisalignedHandler:

00003486 <MisalignedHandler>:
    3486:	1460      	nie
    3488:	1462      	ipush
    348a:	1463      	ipop
    348c:	1461      	nir

Disassembly of section .text.LCDIntHandler:

0000348e <LCDIntHandler>:
    348e:	1460      	nie
    3490:	1462      	ipush
    3492:	1463      	ipop
    3494:	1461      	nir

Disassembly of section .text.CNTAIntHandler:

00003496 <CNTAIntHandler>:
    3496:	1460      	nie
    3498:	1462      	ipush
    349a:	1463      	ipop
    349c:	1461      	nir

Disassembly of section .text.startup.main:

0000349e <main>:

/***************************************************/
//main
/**************************************************/
int main(void) 
{
    349e:	14d0      	push      	r15
	delay_nms(1000);						
    34a0:	30fa      	movi      	r0, 250
    34a2:	4002      	lsli      	r0, r0, 2
    34a4:	e3fff67e 	bsr      	0x21a0	// 21a0 <delay_nms>
	APT32F110x_init();
    34a8:	e3fff6f0 	bsr      	0x2288	// 2288 <APT32F110x_init>
    while(1)
	{
		SYSCON_IWDCNT_Reload();
    34ac:	e3fff618 	bsr      	0x20dc	// 20dc <SYSCON_IWDCNT_Reload>
    34b0:	07fe      	br      	0x34ac	// 34ac <main+0xe>
