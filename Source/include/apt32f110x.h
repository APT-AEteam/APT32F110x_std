/****************************************************************************
* @file    apt32f110.h
* @author  APT SZ AE Team
* @version V1.00
* @date    2022/01/15
******************************************************************************
*THIS SOFTWARE WHICH IS FOR ILLUSTRATIVE PURPOSES ONLY WHICH PROVIDES 
*CUSTOMER WITH CODING INFORMATION REGARDING THEIR PRODUCTS.
*APT CHIP SHALL NOT BE HELD RESPONSIBILITY ADN LIABILITY FOR ANY DIRECT, 
*INDIRECT DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF 
*SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION 
*CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.AND APT CHIP RESERVES 
*THE RIGHT TO MAKE CHANGES IN THE SOFTWARE WITHOUT NOTIFICATION
*******************************************************************************/

/***********************************************************************
Define to prevent recursive inclusion
***********************************************************************/ 
#ifndef APT32F110X_H
#define APT32F110X_H

/***********************************************************************
Includes
***********************************************************************/
#include "apt32f110x_types_local.h"
#include "apt32f110x_ck802.h"

/***********************************************************************
@brief CK802 bits Structure
***********************************************************************/
typedef struct {
	volatile unsigned int ReservedA[4];		//0xE000E000
	volatile unsigned int CORET_CSR;		//0xE000E010
	volatile unsigned int CORET_RVR;		//0xE000E014
	volatile unsigned int CORET_CVR;		//0xE000E018
	volatile unsigned int CORET_CALIB;		//0xE000E01C
	volatile unsigned int ReservedB[56];	//Reserved
	volatile unsigned int ISER;				//0xE000E100
	volatile unsigned int ReservedC[15];	//Reserved
	volatile unsigned int IWER;				//0xE000E140
	volatile unsigned int ReservedD[15];	//Reserved
	volatile unsigned int ICER;				//0xE000E180
	volatile unsigned int ReservedE[15];	//Reserved
	volatile unsigned int IWDR;				//0xE000E1C0
	volatile unsigned int ReservedF[15];	//Reserved
	volatile unsigned int ISPR;				//0xE000E200
	volatile unsigned int ReservedG[31];	//Reserved
	volatile unsigned int ICPR;				//0xE000E280
	volatile unsigned int ReservedH[31];	//Reserved
	volatile unsigned int IABR;				//0xE000E300
	volatile unsigned int ReservedI[63];	//Reserved
	volatile unsigned int IPR[8];			//0xE000E400 ~ 0xE000E41C
	volatile unsigned int ReservedJ[504];	//Reserved
	volatile unsigned int ISR; 				//0xE000EC00
	volatile unsigned int IPTR; 			//0xE000EC04
} CSP_CK802_T;
/***********************************************************************
@brief IFC bits Structure
***********************************************************************/
typedef volatile struct {
	volatile unsigned int IDR ;
	volatile unsigned int CEDR ;
	volatile unsigned int SRR ;
	volatile unsigned int CMR ;
	volatile unsigned int CR ;
	volatile unsigned int MR ;
	volatile unsigned int FM_ADDR ;
	volatile unsigned int Reserved ;
	volatile unsigned int KR ;
	volatile unsigned int IMCR ;
	volatile unsigned int RISR ;
	volatile unsigned int MISR ;
	volatile unsigned int ICR ;
} CSP_IFC_T ;
/***********************************************************************
@brief SYSCON Structure
***********************************************************************/
typedef volatile struct {                   			// 0x40011000
	volatile unsigned int IDCCR;                        // 0x000: Identification & System Controller Clock Control Register
	volatile unsigned int GCER;                         // 0x004: System Controller General Control Enable Register
	volatile unsigned int GCDR;                         // 0x008: System Controller General Control Disable Register
	volatile unsigned int GCSR;                         // 0x00C: System Controller General Control Status Register
	volatile unsigned int CKST;                         // 0x010
	volatile unsigned int RAMCHK;                       // 0x014*/
	volatile unsigned int EFLCHK;                       // 0x018*/
	volatile unsigned int SCLKCR;                       // 0x01C: System Controller System Clock Selection & Division Register
	volatile unsigned int PCLKCR;                       // 0x020: System Controller Peripheral Clock Selection & Division Register
	volatile unsigned int _RSVD0;                       // 0x024*/
	volatile unsigned int PCER0;                        // 0x028: System Controller Peripheral Clock Enable Register
	volatile unsigned int PCDR0;                        // 0x02C: System Controller Peripheral Clock Disable Register
	volatile unsigned int PCSR0;                        // 0x030: System Controller Peripheral Clock Status Register
	volatile unsigned int PCER1;                        // 0x034: System Controller Peripheral Clock Enable Register
	volatile unsigned int PCDR1;                        // 0x038: System Controller Peripheral Clock Disable Register
	volatile unsigned int PCSR1;                        // 0x03C: System Controller Peripheral Clock Status Register
	volatile unsigned int OSTR;                         // 0x040: System Controller External OSC Stable Time Control Register
	volatile unsigned int _RSVD1;                       // 0x044: System Controller PLL Stable Time Control Register
	volatile unsigned int _RSVD2;                       // 0x048: System Controller PLL PMS Value Control Register
	volatile unsigned int LVDCR;                        // 0x04C: System Controller LVD Control Register
	volatile unsigned int CLCR;                         // 0x050: System Controller IMOSC Fine Adjustment Register
	volatile unsigned int PWRCR;                        // 0x054: System Controller Power Control Register
	volatile unsigned int PWRKEY;                       // 0x058: System Controller Power Control Register
	volatile unsigned int _RSVD3;                       // 0x05C: */
	volatile unsigned int _RSVD4;                       // 0x060: */
	volatile unsigned int OPT1;                         // 0x064: System Controller OSC Trim Control Register
	volatile unsigned int OPT0;                         // 0x068: System Controller Protection Control Register
	volatile unsigned int WKCR;                         // 0x06C: System Controller Clock Quality Check Control Register
	volatile unsigned int _RSVD5;                       // 0x070: System Controller Clock Quality Check Control Register
	volatile unsigned int IMER;                         // 0x074: System Controller Interrupt Enable Register
	volatile unsigned int IMDR;                         // 0x078: System Controller Interrupt Disable Register
	volatile unsigned int IMCR;                         // 0x07C: System Controller Interrupt Mask Register
	volatile unsigned int IAR;                          // 0x080: System Controller Interrupt Active Register
	volatile unsigned int ICR;                          // 0x084: System Controller Clear Status Register
	volatile unsigned int RISR;                         // 0x088: System Controller Raw Interrupt Status Register
	volatile unsigned int MISR;                         // 0x08C: System Controller Raw Interrupt Status Register
	volatile unsigned int RSR;                          // 0x090: System Controller Raw Interrupt Status Register
	volatile unsigned int EXIRT;                        // 0x094: System Controller Reset Status Register
	volatile unsigned int EXIFT;                        // 0x098: System Controller External Interrupt Mode 1 (Positive Edge) Register
	volatile unsigned int EXIER;                        // 0x09C: System Controller External Interrupt Mode 2 (Negative Edge) Register
	volatile unsigned int EXIDR;                        // 0x0A0: System Controller External Interrupt Enable Register
	volatile unsigned int EXIMR;                        // 0x0A4: System Controller External Interrupt Disable Register
	volatile unsigned int EXIAR;                        // 0x0A8: System Controller External Interrupt Mask Register
	volatile unsigned int EXICR;                        // 0x0AC: System Controller External Interrupt Active Register
	volatile unsigned int EXIRS;                        // 0x0B0: System Controller External Interrupt Clear Status Register
	volatile unsigned int IWDCR;                        // 0x0B4: System Controller Independent Watchdog Control Register
	volatile unsigned int IWDCNT;                       // 0x0B8: SystCem Controller Independent Watchdog Counter Value Register
	volatile unsigned int IWDEDR;                       // 0x0BC: System Controller Independent Watchdog Enable/disable Register
	volatile unsigned int IOMAP0;                       // 0x0C0: Customer Information Content mirror of 1st byte
	volatile unsigned int IOMAP1;                       // 0x0C4: Customer Information Content mirror of 1st byte
	volatile unsigned int _RSVD6;                       // 0x0C8:Reserved
	volatile unsigned int _RSVD7;                       // 0x0CC:Reserved
	volatile unsigned int _RSVD8;                       // 0x0D0:Reserved
	volatile unsigned int _RSVD9;                       // 0x0D4:Reserved
	volatile unsigned int _RSVD10;                      // 0x0D8:Reserved
	volatile unsigned int _RSVD11;                      // 0x0DC:Reserved
	volatile unsigned int _RSVD12;                      // 0x0E0:Reserved
	volatile unsigned int UID0 ;                        // 0x0E4: Customer Information Content mirror of 1st byte
	volatile unsigned int UID1 ;                        // 0x0E8: Customer Information Content mirror of 1st byte
	volatile unsigned int UID2 ;                        // 0x0EC: Customer Information Content mirror of 1st byte
	volatile unsigned int PWROPT;                       // 0x0F0: Power recovery timmming control
	volatile unsigned int EVTRG;                       	// 0x0F4: Event trigger select register
	volatile unsigned int EVPS;                       	// 0x0F8: Event trigger count register
	volatile unsigned int EVSWF;                       	// 0x0FC: Event Counter Software Trigger Control Register
	volatile unsigned int UREG0;                       	// 0x100: 32-bit user register
	volatile unsigned int UREG1;                       	// 0x104: 32-bit user register
	volatile unsigned int UREG2;                       	// 0x108: 16-bit user register
	volatile unsigned int UREG3;                       	// 0x10C: 16-bit user register
	volatile unsigned int _RSVD13;						// 0x110: Reserved
	volatile unsigned int _RSVD14;						// 0x114: Reserved
	volatile unsigned int CQCR;                       	// 0x118: Clock Qualification Control Register
	volatile unsigned int CQSR;                       	// 0x11C: Clock Qualification Result Register
	volatile unsigned int _RSVD15;                      // 0x120: Reserved
	volatile unsigned int _RSVD16;                      // 0x124: Reserved
	volatile unsigned int DBGCR;                       	// 0x128: Debug Control
} CSP_SYSCON_T;  
/***********************************************************************
@brief ETCB Structure
***********************************************************************/
typedef volatile struct{				  				// 0x40012000
    volatile unsigned int  EN;           				// 0x000:ETCB Enable
    volatile unsigned int  SWTRG;         				// 0x004:ETCB Software Trigger Generator
    volatile unsigned int  CH0CON0;       				// 0x008:ETCB Channel 0 Control Register 0
    volatile unsigned int  CH0CON1;       				// 0x00C:ETCB Channel 0 Control Register 1
    volatile unsigned int  CH1CON0;       				// 0x010:ETCB Channel 1 Control Register 0
    volatile unsigned int  CH1CON1;       				// 0x014:ETCB Channel 1 Control Register 1
    volatile unsigned int  CH2CON0;       				// 0x018:ETCB Channel 2 Control Register 0
    volatile unsigned int  CH2CON1;       				// 0x01C:ETCB Channel 2 Control Register 1
	volatile unsigned int  _RSVD0;		  				// 0x020: Reserved
	volatile unsigned int  _RSVD1;						// 0x024: Reserved
	volatile unsigned int  _RSVD2;						// 0x028: Reserved
	volatile unsigned int  _RSVD3;						// 0x02C: Reserved
    volatile unsigned int  CH3CON;       				// 0x030:ETCB Channel 3 Control Register
	volatile unsigned int  CH4CON;       				// 0x034:ETCB Channel 4 Control Register
	volatile unsigned int  CH5CON;       				// 0x038:ETCB Channel 5 Control Register
	volatile unsigned int  CH6CON;       				// 0x03C:ETCB Channel 6 Control Register
	volatile unsigned int  CH7CON;       				// 0x040:ETCB Channel 7 Control Register
	volatile unsigned int  CH8CON;       				// 0x044:ETCB Channel 8 Control Register
	volatile unsigned int  CH9CON;       				// 0x048:ETCB Channel 9 Control Register
	volatile unsigned int  CH10CON;       				// 0x04C:ETCB Channel 10 Control Register
	volatile unsigned int  CH11CON;       				// 0x050:ETCB Channel 11 Control Register
} CSP_ETCB_T, *CSP_ETCB_PTR;    
/***********************************************************************
@brief ADC0 Structure
***********************************************************************/   
typedef volatile struct{							//0x40030000
    volatile unsigned int  ECR;              		//0x000: Clock Enable Register
    volatile unsigned int  DCR;              		//0x004: Clock Disable Register
    volatile unsigned int  PMSR;             		//0x008: Power Management Status Register
    volatile unsigned int  Reserved0;				//0x00C: 0x020: Reserved
    volatile unsigned int  CR;               		//0x010: Control Register
    volatile unsigned int  MR;               		//0x014: Mode Register
    volatile unsigned int  SHR;						//0x018: Reserved
    volatile unsigned int  CSR;              		//0x01C: Clear Status Register
    volatile unsigned int  SR;               		//0x020: Status Register
    volatile unsigned int  IER;              		//0x024: Interrupt Enable Register
    volatile unsigned int  IDR;              		//0x028: Interrupt Disable Register
    volatile unsigned int  IMR;              		//0x02C: Interrupt Mask Register
    volatile unsigned int  SEQ[16];          		//0x030~0X06C: Conversion Mode Register 0~11
    volatile unsigned int  PRI;              		//0x070: Conversion Priority Register
    volatile unsigned int  TDL0;             		//0x074: Trigger Delay control Register
    volatile unsigned int  TDL1;             		//0x078: Trigger Delay control Register
    volatile unsigned int  SYNCR;            		//0x07C: Sync Control Register
    volatile unsigned int  Reserved1;        		//0x080: Trigger Filter Control Register
    volatile unsigned int  Reserved2;        		//0x084: Trigger Filter Window  Register
    volatile unsigned int  EVTRG;            		//0x088: Event Trigger Control  Register
    volatile unsigned int  EVPS;             		//0x000: Event Prescale Register
    volatile unsigned int  EVSWF;            		//0x000: Event Softtrig Register
    volatile unsigned int  ReservedD[27];			//0x08C~0x0FC: Reserved
    volatile unsigned int  DR[16];           		//0x100: Convert Data Register
    volatile unsigned int  CMP0;             		//0x140: Comparison Data Register
    volatile unsigned int  CMP1;             		//0x144: Comparison Data Register
	volatile unsigned int  DRMASK;					//0x148: Comparison Data Register	
 } CSP_ADC12_T, *CSP_ADC12_PTR;
 
typedef volatile struct{
	volatile unsigned int	TS1;					//0x0000: 常温下温度传感器信息1*/	
	volatile unsigned int	IR1;					//0x0004: 常温下内部1V电压参考信息1*/	
	volatile unsigned int	Reserved00;				//0x0008: */	
	volatile unsigned int	Reserved0;				//0x000C: */	
	volatile unsigned int	Reserved1;				//0x0010: */	
	volatile unsigned int	Reserved2;				//0x0014: */	
	volatile unsigned int	Reserved3;				//0x0018: */
	volatile unsigned int	Reserved4;				//0x001C: */
	volatile unsigned int	Reserved5;				//0x0020: */	
	volatile unsigned int	Reserved6;				//0x0024: */	
	volatile unsigned int	Reserved7;				//0x0028: */	
	volatile unsigned int	Reserved8;				//0x002C: */	
	volatile unsigned int	Reserved9;				//0x0030: */	
	volatile unsigned int	Reserved10;				//0x0034: */	
	volatile unsigned int	Reserved11;				//0x0038: */	
	volatile unsigned int	Reserved12;				//0x003C: */	
	volatile unsigned int	TS2;					//0x0040: 高温下温度传感器信息2*/	
	volatile unsigned int	IR2;					//0x0044: 高温下内部1V电压参考信息2*/	
} CSP_ADC12_TEMP_T, *CSP_ADC12_TEMP_PTR;
/***********************************************************************
@brief GPIOX  Structure
***********************************************************************/  
typedef volatile struct{							
    volatile unsigned int  CONLR;                	//0x000: Control Low  Register
    volatile unsigned int  CONHR;                	//0x004: Control High Register
    volatile unsigned int  WODR;                 	//0x008: Write Output Data Register              
    volatile unsigned int  SODR;                 	//0x00C: Set Output Data (bit-wise) Register
    volatile unsigned int  CODR;                 	//0x010: Clear Output Data (bit-wise) Register
    volatile unsigned int  ODSR;                 	//0x014: Output Data Status Register
    volatile unsigned int  PSDR;                 	//0x018: Pin Data Status Register              
    volatile unsigned int  FLTEN;         			//0x01C: Input Signal Filter Enable Control Register
    volatile unsigned int  PUDR;                 	//0x020: IO Pullup_Pulldown Register
    volatile unsigned int  DSCR;                 	//0x024: Output Driving Strength Register
    volatile unsigned int  OMCR;                 	//0x028: Slew-rate, Open-Drain Control  
    volatile unsigned int  IECR;                 	//0x02C: EXI enable control  
	volatile unsigned int  IEER;					//0x030: EXI enable control 
	volatile unsigned int  IEDR;					//0x03C: EXI enable control 
 } CSP_GPIO_T, *CSP_GPIO_PTR; 

typedef volatile struct{
	volatile unsigned int  IGRPL;                	//0x000: EXI group control
    volatile unsigned int  IGRPH;	             	//0x004: EXI group control
	volatile unsigned int  IGREX;					//0x008: External Interrupt Group Extended Configuration Register
    volatile unsigned int  IO_CLKEN;				//0x00C: GPIO group clock enable control register
 } CSP_IGRP_T, *CSP_IGRP_PTR;   
/***********************************************************************
@brief BTx Structure
***********************************************************************/       
typedef struct{
   volatile unsigned int	RSSR;  					//0x000: Reset/Start Control Register
   volatile unsigned int	CR;		    			//0x004: General Control Register
   volatile unsigned int	PSCR;					//0x008: Counter Clock Prescaler Register
   volatile unsigned int	PRDR; 					//0x00C: Period Register
   volatile unsigned int	CMP;					//0X010: Compare Data
   volatile unsigned int	CNT;					//0x014: Counter Register
   volatile unsigned int	EVTRG;					//0x018: Event Generation Control Register
   volatile unsigned int	EVPS;   				//0x01C: */
   volatile unsigned int	EVCNTINTI;  			//0x020: */
   volatile unsigned int    EVSWF;      			//0x024: Event Counter Software Trigger Register
   volatile unsigned int	RISR;   				//0x028: Raw Interrupt Status Register    
   volatile unsigned int	IMCR;     				//0x02C: Interrupt Masking Control Register
   volatile unsigned int	MISR;  					//0x030: Masked Interrupt Status Register
   volatile unsigned int	ICR;    				//0x034: Interrupt Clear Register
} CSP_BT_T, *CSP_BT_PTR;
/***********************************************************************
@brief CA0   bits Structure
***********************************************************************/      
 typedef struct
 {
    volatile unsigned int      CADATAH;        		//0x000: DATA High Register
    volatile unsigned int      CADATAL;        		//0x004: DATA Low Register
    volatile unsigned int      CACON;          		//0x008: Control Register
    volatile unsigned int      INTMASK;        		//0x00C: Interrupt Mask CR
 } CSP_CA_T, *CSP_CA_PTR; 
/***********************************************************************
@brief	GPTAX  Structure
***********************************************************************/    
 typedef struct
 {
	volatile unsigned int	CEDR;  					//0x000: Clock control & ID
	volatile unsigned int	RSSR;					//0x004: Start & Stop Ctrl
	volatile unsigned int	PSCR;					//0x008: Clock prescaler
	volatile unsigned int	CR;  					//0x00C: Control register
	volatile unsigned int	SYNCR;					//0x010: Synchronization control reg
	volatile unsigned int	GLDCR;					//0x014: Global load control reg
	volatile unsigned int	GLDCFG; 				//0x018: Global load config
	volatile unsigned int	GLDCR2;					//0x01C: Global load control reg2
	volatile unsigned int	Reserved0;				//0x020: Reserved
	volatile unsigned int	PRDR;   				//0x024: Period reg
	volatile unsigned int	PHSR;					//0x028: Phase setting register
	volatile unsigned int	CMPA;  					//0x02C: Compare Value A
	volatile unsigned int	CMPB;   				//0x030: Compare Value B
	volatile unsigned int	Reserved2;				//0x034: Reserved
	volatile unsigned int	Reserved3;				//0x038: Reserved
	volatile unsigned int	CMPLDR;	    			//0x03C: Cmp reg load control
	volatile unsigned int	CNT;      				//0x040: Counter reg
	volatile unsigned int	AQLDR; 					//0x044: AQ reg load control
	volatile unsigned int	AQCR1;      			//0x048: Action qualify of ch-A
	volatile unsigned int	AQCR2;    				//0x04C: Action qualify of ch-B
	volatile unsigned int	Reserved4;				//0x050: Reserved
	volatile unsigned int	Reserved5;				//0x054: Reserved
	volatile unsigned int	Reserved6;				//0x058: Reserved
	volatile unsigned int	AQOSF; 					//0x05C: AQ output one-shot software forcing
	volatile unsigned int	AQCSF;      			//0x060: AQ output conti-software forcing
	volatile unsigned int	Reserved7;				//0x064: Reserved
	volatile unsigned int	Reserved8;				//0x068: Reserved
	volatile unsigned int	Reserved9;				//0x06c: Reserved
	volatile unsigned int	Reserved10;				//0x070: Reserved
	volatile unsigned int	Reserved11;				//0x074: Reserved
	volatile unsigned int	Reserved12;				//0x078: Reserved
	volatile unsigned int	Reserved13;				//0x07c: Reserved
	volatile unsigned int	Reserved14;				//0x080: Reserved
	volatile unsigned int	Reserved15;				//0x084: Reserved
	volatile unsigned int	Reserved16;				//0x088: Reserved
	volatile unsigned int	Reserved17;				//0x08c: Reserved
	volatile unsigned int	Reserved18;				//0x090: Reserved
	volatile unsigned int	Reserved19;				//0x094: Reserved
	volatile unsigned int	Reserved20;				//0x098: Reserved
	volatile unsigned int	Reserved21;				//0x09c: Reserved
	volatile unsigned int	Reserved22;				//0x0a0: Reserved
	volatile unsigned int	Reserved23;				//0x0a4: Reserved
	volatile unsigned int	Reserved24;				//0x0a8: Reserved
	volatile unsigned int	Reserved25;				//0x0ac: Reserved
	volatile unsigned int	Reserved26;				//0x0b0: Reserved
	volatile unsigned int	Reserved27;				//0x0b4: Reserved
	volatile unsigned int  TRGFTCR;    				//0x0B8: Trigger Filter control reg
	volatile unsigned int  TRGFTWR;    				//0x0BC: Trigger filter window
	volatile unsigned int  EVTRG;      				//0x0C0: Event trigger setting
	volatile unsigned int  EVPS;       				//0x0C4: Event presaler
	volatile unsigned int  EVCNTINIT;				//0x0C8: Event trigger counter initialization value register
	volatile unsigned int  EVSWF;      				//0x0CC: Event software forcing
	volatile unsigned int  RISR;       				//0x0D0: Raw interrupt status register
	volatile unsigned int  MISR;       				//0x0D4: Masked interrupt status register
	volatile unsigned int  IMCR;       				//0x0D8: Interrupt Enable Control Register
	volatile unsigned int  ICR;        				//0x0DC: Interrupt clear register
	volatile unsigned int  REGLINK;    				//0x0E0: Register link
	volatile unsigned int  REGLIK2;    				//0x0E4: Interrupt clear
	volatile unsigned int  REGPROT;    				//0x0E8: Register link
}CSP_GPTA_T,*CSP_GPTA_PTR;
/***********************************************************************
@brief	GPTBX Structure
***********************************************************************/   
 typedef struct
 {
	volatile unsigned int	CEDR;           			//0x000: Clock control & ID
	volatile unsigned int	RSSR;           			//0x004: Start & Stop Ctrl
	volatile unsigned int	PSCR;           			//0x008: Clock prescaler
	volatile unsigned int	CR;           				//0x00C: Control register
	volatile unsigned int	SYNCR;           			//0x010: Synchronization control reg
	volatile unsigned int	GLDCR;           			//0x014: Global load control reg
	volatile unsigned int	GLDCFG;           			//0x018: Global load config
	volatile unsigned int	GLDCR2;           			//0x01C: Global load control reg2
	volatile unsigned int	Reserved0;					//0x020: Reserved
	volatile unsigned int	PRDR;   					//0x024: Period reg
	volatile unsigned int	PHSR;						//0x028: Phase setting register
	volatile unsigned int	CMPA;						//0x02C: Compare Value A
	volatile unsigned int	CMPB;   					//0x030: Compare Value B
	volatile unsigned int	Reserved2;					//0x034: Reserved
	volatile unsigned int	Reserved3;					//0x038: Reserved
	volatile unsigned int	CMPLDR;	    				//0x03C: Cmp reg load control
	volatile unsigned int	CNT;      					//0x040: Counter reg
	volatile unsigned int	AQLDR; 						//0x044: AQ reg load control
	volatile unsigned int	AQCR1;      				//0x048: Action qualify of ch-A
	volatile unsigned int	AQCR2;    					//0x04C: Action qualify of ch-B
	volatile unsigned int	Reserved4;					//0x050: Reserved
	volatile unsigned int	Reserved5;					//0x054: Reserved
	volatile unsigned int	Reserved6;					//0x058: Reserved
	volatile unsigned int	AQOSF; 						//0x05C: AQ output one-shot software forcing
	volatile unsigned int	AQCSF;      				//0x060: AQ output conti-software forcing
	volatile unsigned int	DBLDR;						//0x064: Dead Time configuration loaded into control register
	volatile unsigned int	DBCR;						//0x068: Dead Time Configuration Control Register
	volatile unsigned int	DPSCR;						//0x06C: Dead Time Delay Clock Divider Control Register
	volatile unsigned int	DBDTR;						//0x070: Dead Time control rising edge delay register
	volatile unsigned int	DBDTF;						//0x074: Dead Time control faliing edge delay register
	volatile unsigned int	Reserved12;					//0x078: Reserved
	volatile unsigned int	EMSRC;						//0x07C: Emergency Input Control Register
	volatile unsigned int	EMSRC2;						//0x080: Emergency Input Control Register 2
	volatile unsigned int	EMPOL;						//0x084: Emergency Input Polarity Control Register 
	volatile unsigned int	EMECR;						//0x088: Emergency enable control register
	volatile unsigned int	EMOSR;						//0x08C: Emergency output control register
	volatile unsigned int	Reserved18;					//0x090: Reserved
	volatile unsigned int	EMSLCSR;					//0x094: Emergency Soft Lock Status Register
	volatile unsigned int	EMSLCLR;					//0x098: Emergency Soft Lock clear Register
	volatile unsigned int	EMHLSR;						//0x09C: Emergency Hard Lock Status Register
	volatile unsigned int	EMHLCLR;					//0x0A0: Emergency Hard Lock clear Register
	volatile unsigned int	EMFRCR;						//0x0A4: Emergency Software Trigger Register
	volatile unsigned int	EMRISR;						//0x0A8: Emergency interrupt raw status register
	volatile unsigned int	EMMISR;						//0x0AC: Emergency interrupt flag register
	volatile unsigned int	EMIMCR;						//0x0B0: Emergency Interrupt Enable Control Register
	volatile unsigned int	EMICR;						//0x0B4: Emergency interrupt clear register
	volatile unsigned int   TRGFTCR;    				//0x0B8: Trigger Filter control reg
	volatile unsigned int   TRGFTWR;    				//0x0BC: Trigger filter window
	volatile unsigned int  	EVTRG;      				//0x0C0: Event trigger setting
	volatile unsigned int  	EVPS;       				//0x0C4: Event presaler
	volatile unsigned int  	EVCNTINIT;					//0x0C8: Event trigger counter initialization value register
	volatile unsigned int  	EVSWF;      				//0x0CC: Event software forcing
	volatile unsigned int  	RISR;       				//0x0D0: Raw Interrupt Status
	volatile unsigned int  	MISR;       				//0x0D4: Masked Interrupt Status
	volatile unsigned int  	IMCR;       				//0x0D8: Interrupt Enable Control Register
	volatile unsigned int  	ICR;        				//0x0DC: Interrupt clear register
	volatile unsigned int  	REGLINK;    				//0x0E0: Register link
	volatile unsigned int  	REGLINK2;    				//0x0E4: Interrupt clear
	volatile unsigned int  	REGPROT;    				//0x0E8: Register link
}CSP_GPTB_T,*CSP_GPTB_PTR,CSP_GPTX_T;
/***********************************************************************
@brief EPT0    bits Structure
***********************************************************************/   
 typedef struct
 {
   volatile unsigned int	CEDR;  		//0x0000	Clock control & ID
   volatile unsigned int	RSSR;		//0x0004	Start & Stop Ctrl
   volatile unsigned int	PSCR;		//0x0008	Clock prescaler
   volatile unsigned int	CR;  		//0x000C	Control register
   volatile unsigned int	SYNCR;		//0x0010	Synchronization control reg
   volatile unsigned int	GLDCR;		//0x0014	Global load control reg
   volatile unsigned int	GLDCFG; 	//0x0018	Global load config
   volatile unsigned int	GLDCR2;		//0x001C	Global load control reg2
   volatile unsigned int    HRCFG;      //0x0020
   volatile unsigned int	PRDR;   	//0x0024	Period reg
   volatile unsigned int	PHSR;     	//0x0028	Phase control reg
   volatile unsigned int	CMPA;  		//0x002C	Compare Value A
   volatile unsigned int	CMPB;   	//0x0030	Compare Value B
   volatile unsigned int	CMPC;     	//0x0034	Compare Value C 
   volatile unsigned int	CMPD;  		//0x0038	Compare Value D
   volatile unsigned int	CMPLDR;	    //0x003C	Cmp reg load control
   volatile unsigned int	CNT;      	//0x0040	Counter reg
   volatile unsigned int	AQLDR; 		//0x0044	AQ reg load control
   volatile unsigned int	AQCR1;      //0x0048	Action qualify of ch-A
   volatile unsigned int	AQCR2;    	//0x004C	Action qualify of ch-B
   volatile unsigned int	AQCR3; 		//0x0050	Action qualify of ch-C
   volatile unsigned int	AQCR4;  	//0x0054	Action qualify of ch-D
   volatile unsigned int	AQTSCR;   	//0x0058	T event selection
   volatile unsigned int	AQOSF; 		//0x005C	AQ output one-shot software forcing
   volatile unsigned int	AQCSF;      //0x0060	AQ output conti-software forcing
   volatile unsigned int	DBLDR;    	//0x0064	Deadband control reg load control
   volatile unsigned int	DBCR;       //0x0068	Deadband control reg
   volatile unsigned int	DPSCR;		//0x006C	Deadband clock prescaler
   volatile unsigned int	DBDTR;		//0x0070	Deadband rising delay control
   volatile unsigned int	DBDTF; 		//0x0074	Deadband falling delay control
   volatile unsigned int	CPCR;  		//0x0078	Chop control
   volatile unsigned int	EMSRC; 		//0x007C	EM source setting
   volatile unsigned int	EMSRC2;		//0x0080	EM source setting
   volatile unsigned int	EMPOL; 		//0x0084	EM polarity setting
   volatile unsigned int	EMECR; 		//0x0088	EM enable control
   volatile unsigned int	EMOSR;     	//0x008C	EM trip out status setting
   volatile unsigned int	Reserved;	//0x0090	Reserved
   volatile unsigned int	EMSLSR;     //0x0094	Softlock status
   volatile unsigned int	EMSLCLR;    //0x0098	Softlock clear
   volatile unsigned int   EMHLSR;     	//0x009C    Hardlock status
   volatile unsigned int   EMHLCLR;    	//0x00A0    Hardlock clear
   volatile unsigned int   EMFRCR;     	//0x00A4    Software forcing EM
   volatile unsigned int   EMRISR;     	//0x00A8    EM RISR
   volatile unsigned int   EMMISR;     	//0x00AC    EM MISR
   volatile unsigned int   EMIMCR;     	//0x00B0    EM masking enable
   volatile unsigned int   EMICR;      	//0x00B4    EM pending clear
   volatile unsigned int   TRGFTCR;    	//0x00B8    Trigger Filter control reg
   volatile unsigned int   TRGFTWR;    	//0x00BC    Trigger filter window
   volatile unsigned int   EVTRG;      	//0x00C0    Event trigger setting
   volatile unsigned int   EVPS;       	//0x00C4    Event presaler
   volatile unsigned int   EVCNTINIT;   //0x00C8    
   volatile unsigned int   EVSWF;      	//0x00CC    Event software forcing
   volatile unsigned int   RISR;       	//0x00D0    Interrupt RISR
   volatile unsigned int   MISR;       	//0x00D4    Interrupt MISR
   volatile unsigned int   IMCR;       	//0x00D8    Interrupt IMCR
   volatile unsigned int   ICR;        	//0x00DC    Interrupt clear
   volatile unsigned int   REGLINK;    	//0x00E0    Register link
   volatile unsigned int   REGLINK2;   	//0x00E4    Register link2
   volatile unsigned int   REGPROT;    	//0x00E8    Register protection
} CSP_EPT_T, *CSP_EPT_PTR;    
/***********************************************************************
@brief UART0~UART2 Structure
***********************************************************************/      
typedef volatile struct{
    volatile unsigned int  DATA;               		//0x000: Write and Read Data Register
    volatile unsigned int  SR;                 		//0x004: Status Register
    volatile unsigned int  CTRL;               		//0x008: Control Register
    volatile unsigned int  ISR;                		//0x00C: Interrupt Status Register
    volatile unsigned int  BRDIV;              		//0x010: Baud Rate Generator Register
	volatile unsigned int  DMACR;             		//0x014: DMA Control Register
	volatile unsigned int  RTOR;             		//0x018: Receive Timeout Configuration Register
	volatile unsigned int  TTGR;              		//0x01C: Transmitter Time-Guard Configuration Register
    volatile unsigned int  SRR;						//0x020: Software reset register
 } CSP_UART_T, *CSP_UART_PTR; 
/***********************************************************************
@brief USART Structure
***********************************************************************/    
typedef struct
{
    volatile unsigned int  IDR;        				//0x0000:    ID Register                    
    volatile unsigned int  CEDR;       				//0x0004:	 Clock Enable/Disable Register  
    volatile unsigned int  SRR;        				//0x0008:    Software Reset Register        
    volatile unsigned int  CR;         				//0x000C:    Control Register                
    volatile unsigned int  MR;         				//0x0010:    Mode Register                   
    volatile unsigned int  IMSCR;      				//0x0014:    Interrupt Set/Clear Register       
    volatile unsigned int  RISR;       				//0x0018:    Raw Interrupt Status Register      
    volatile unsigned int  MISR;       				//0x001C:    Masked Interrupt Status Register   
    volatile unsigned int  ICR;        				//0x0020:    Clear Status Register              
    volatile unsigned int  SR;         				//0x0024:    Status Register                 
    volatile unsigned int  RHR;        				//0x0028:    Receiver Data Register       
    volatile unsigned int  THR;        				//0x002C:    Transmit Data Register       
    volatile unsigned int  BRGR;       				//0x0030:    Baud Rate Generator Register    
    volatile unsigned int  RTOR;       				//0x0034:    Receiver Time-out Register      
    volatile unsigned int  TTGR;       				//0x0038:    Transmitter Time-guard Register 
    volatile unsigned int  LIR;        				//0x003C:    LIN Identifier Register         
    volatile unsigned int  DFWR0;      				//0x0040:    Data Field Write 0 Register     
    volatile unsigned int  DFWR1;      				//0x0044:    Data Field Write 1 Register     
    volatile unsigned int  DFRR0;   				//0x0048:    Data Field Read 0 Register      
    volatile unsigned int  DFRR1;      				//0x004C:    Data Field Read 1 Register      
    volatile unsigned int  SBLR;       				//0x0050:    Sync Break Length Register      
    volatile unsigned int  LCP1;       				//0x0054:    Limit counter protocol 1        
    volatile unsigned int  LCP2;       				//0x0058:    Limit counter protocol 2        
    volatile unsigned int  DMACR;					//0x005C:    DMA control register    
	volatile unsigned int  RSVD[12];				//0x0060~0x008C    
	volatile unsigned int  RXFL;					//0x0090:    Recieve FIFO status register  
	volatile unsigned int  TXFL;					//0x0094:    Transmit FIFO status register          
} CSP_USART_T,*CSP_USART_PTR;   
/***********************************************************************
@brief SPI0 Structure
***********************************************************************/  
typedef struct{
	volatile unsigned int  CR0;						//0x000: Control Register 0 */
	volatile unsigned int  CR1;						//0x004: Control Register 1 */
	volatile unsigned int  DR; 						//0x008: Receive FIFO(read) and transmit FIFO data register(write) */
	volatile unsigned int  SR;						//0x00C: Status register
	volatile unsigned int  CPSR;					//0x010: Clock prescale register
	volatile unsigned int  IMSCR;					//0x014: Interrupt mask set and clear register
	volatile unsigned int  RISR;					//0x018: Raw interrupt status register
	volatile unsigned int  MISR;					//0x01C: Masked interrupt status register
	volatile unsigned int  ICR;						//0x020: Interrupt clear register
	volatile unsigned int  DMACR;					//0x024: DMA transceiver controllerr
	volatile unsigned int  SRR;						//0x028: Software reset register
} CSP_SSP_T, *CSP_SSP_PTR;
/***********************************************************************
@brief SIO0 Structure
***********************************************************************/ 
typedef struct{
	volatile unsigned int  CR;						//0x000: Control Register 0 */
	volatile unsigned int  TXCR0;					//0x004: TX Control Register 0 */
	volatile unsigned int  TXCR1; 					//0x008: TX Control Register 1 */
	volatile unsigned int  TXBUF;					//0x00C: TX Buffer Register
	volatile unsigned int  RXCR0;					//0x010: RX Control Register 0 */
	volatile unsigned int  RXCR1;					//0x014: RX Control Register 1 */
	volatile unsigned int  RXCR2;					//0x018: RX Control Register 2 */
	volatile unsigned int  RXBUF;					//0x01C: RX Buffer Register
	volatile unsigned int  RISR;					//0x020: Raw interrupt status register
	volatile unsigned int  MISR;					//0x024: Masked interrupt status register
	volatile unsigned int  IMCR;					//0x028: Interrupt Enable Control Register
	volatile unsigned int  ICR;						//0x02C: Interrupt clear register
	volatile unsigned int  SRR;						//0x030: Software reset register
} CSP_SIO_T, *CSP_SIO_PTR;
/***********************************************************************
@brief I2C0 Structure
***********************************************************************/      
 typedef volatile struct
 {
    volatile unsigned int  CR;           			//0x000: I2C Control
    volatile unsigned int  TADDR;           		//0x004: I2C Target Address
    volatile unsigned int  SADDR;           		//0x008: I2C Slave Address
    volatile unsigned int  ReservedD;      			//0x00C: Reserved
    volatile unsigned int  DATA_CMD;      			//0x010: I2C Rx/Tx Data Buffer and Command
    volatile unsigned int  SS_SCLH;       			//0x014: I2C Standard Speed SCL High Count
    volatile unsigned int  SS_SCLL;       			//0x018: I2C Standard Speed SCL Low  Count
    volatile unsigned int  FS_SCLH;       			//0x01C: I2C Fast mode and Fast Plus SCL High Count
    volatile unsigned int  FS_SCLL;       			//0x020: I2C Fast mode and Fast Plus SCL Low  Count
    volatile unsigned int  ReservedA;      			//0x024: Reserved */
    volatile unsigned int  ReservedC;      			//0x028: Reserved
    volatile unsigned int  RX_FLSEL;      			//0x02C: I2C Receive FIFO Threshold
    volatile unsigned int  TX_FLSEL;      			//0x030: I2C Transmit FIFO Threshold
    volatile unsigned int  RX_FL;         			//0x034: I2C Receive  FIFO Level
    volatile unsigned int  TX_FL;         			//0x038: I2C Transmit FIFO Level
    volatile unsigned int  ENABLE;        			//0x03C: I2C Enable
    volatile unsigned int  STATUS;        			//0x040: I2C Status
    volatile unsigned int  ReservedB;    			//0x044: Reserved
    volatile unsigned int  SDA_TSETUP;    			//0x048: I2C SDA Setup Time
    volatile unsigned int  SDA_THOLD;     			//0x04C: I2C SDA hold time length*/
    volatile unsigned int  SPKLEN;     				//0x050: I2C SS and FS Spike Suppression Limit
    volatile unsigned int  ReservedE;				//0x054: Reserved
	volatile unsigned int  MISR;          			//0x058: I2C Masked Interrupt Status
    volatile unsigned int  IMSCR;         			//0x05C: I2C Interrupt Enable
    volatile unsigned int  RISR;          			//0x060: I2C Raw Interrupt Status
    volatile unsigned int  ICR;           			//0x064: I2C Interrupt Clear
    volatile unsigned int  ReservedF;				//0x068: Reserved
    volatile unsigned int  SCL_TOUT; 				//0x06C: I2C SCL Stuck at Low Timeout
    volatile unsigned int  SDA_TOUT; 				//0x070: I2C SDA Stuck at Low Timeout
    volatile unsigned int  TX_ABRT;   				//0x074: I2C Transmit Abort Status
    volatile unsigned int  GCALL;     				//0x078: I2C ACK General Call
    volatile unsigned int  NACK; 					//0x07C: I2C Generate SLV_DATA_NACK*/
	volatile unsigned int  DMACR;					//0x080: DMA transceiver controllerr
	volatile unsigned int  Reserved0;
	volatile unsigned int  Reserved1;
	volatile unsigned int  SRR;						//0x08C: Software reset register
 } CSP_I2C_T, *CSP_I2C_PTR; 
/***********************************************************************
@brief LPT Structure
***********************************************************************/  
typedef volatile struct{
   volatile unsigned int    CEDR;  					//0x000: Clock control & ID
   volatile unsigned int    RSSR;					//0x004: Start & Stop Ctrl
   volatile unsigned int    PSCR;					//0x008: Clock prescaler
   volatile unsigned int    CR;  					//0x00C: Control register
   volatile unsigned int    SYNCR;					//0x010: Synchronization control reg
   volatile unsigned int    PRDR;   				//0x014: Period reg
   volatile unsigned int    CMP;   					//0x018: Compare Value A*/
   volatile unsigned int    CNT;      				//0x01C: Counter reg
   volatile unsigned int    TRGFTCR;    			//0x020: Trigger Filter control reg
   volatile unsigned int    TRGFTWR;    			//0x024: Trigger filter window
   volatile unsigned int    EVTRG;      			//0x028: Event trigger setting
   volatile unsigned int    EVPS;       			//0x02C: Event presaler
   volatile unsigned int    EVSWF;      			//0x030: Event software forcing
   volatile unsigned int    RISR;       			//0x034: Raw Interrupt Status
   volatile unsigned int    MISR;       			//0x038: Masked Interrupt Status
   volatile unsigned int    IMCR;       			//0x03C: Interrupt Enable Control Register
   volatile unsigned int    ICR;        			//0x040: Interrupt clear register
   volatile unsigned int    SR;        				//0x044: Synchronization Status Register
} CSP_LPT_T, *CSP_LPT_PTR;
/***********************************************************************
@brief CRC     bits Structure
***********************************************************************/ 
typedef struct
{
   volatile unsigned int	Reserved0;				//0x000: Reserved
   volatile unsigned int	CEDR;            		//0x004: Clock Enable/Disable Register
   volatile unsigned int	SRR;             		//0x008: Software Reset Register
   volatile unsigned int	CR;              		//0x00C: Control Register
   volatile unsigned int	SEED;            		//0x010: Seed Value Register
   volatile unsigned int	DATAIN;          		//0x014: Data in Value Register
   volatile unsigned int	DATAOUT;         		//0x018: Data out Value Register
} CSP_CRC_T, *CSP_CRC_PTR;
/***********************************************************************
@brief RTC Structure
***********************************************************************/ 
typedef struct{
   volatile unsigned int	TIMR;  					//0x000: Time Control Register
   volatile unsigned int	DATR;					//0x004: Date Control Register
   volatile unsigned int	CR;  					//0x008: Control Register
   volatile unsigned int	CCR;  					//0x00C: Clock Control register
   volatile unsigned int	ALRAR;					//0x010: Alarm A*/
   volatile unsigned int	ALRBR;					//0x014: Alarm B*/
   volatile unsigned int	SSR;    				//0x018: Sub second
   volatile unsigned int	CAL;   					//0x01C: Calibration*/
   volatile unsigned int   	RISR;       			//0x020: Raw Interrupt Status
   volatile unsigned int	IMCR;   				//0x024: Interrupt Enable Control Register
   volatile unsigned int	MISR;     				//0x028: Masked Interrupt Status
   volatile unsigned int	ICR;   					//0x02C: Interrupt clear register
   volatile unsigned int	KEY;    				//0x030: Protection register
   volatile unsigned int	EVTRG;  				//0x034: Synchronous Event Trigger Control Register
   volatile unsigned int	EVPS;   				//0x038: Synchronized event count controller
} CSP_RTC_T, *CSP_RTC_PTR; 	    
/***********************************************************************
@brief WWDT Structure
***********************************************************************/  	
typedef struct{
	volatile unsigned int	CR;						//0x000: Control Register
	volatile unsigned int	CFGR;					//0x004: Configuration Register
	volatile unsigned int	RISR;					//0x008: Raw Interrupt Status Register
	volatile unsigned int 	MISR;					//0x00C: Masked Interrupt Status Register
	volatile unsigned int	IMCR;					//0x010: Interrupt Masking Control Register
	volatile unsigned int	ICR;					//0x014: Interrupt Pending Clear Register
 }CSP_WWDT_T,*CSP_WWDT_PTR;
/***********************************************************************
@brief HWD Structure
***********************************************************************/ 
typedef struct{
	volatile S32_T			DIVIDENT;				//0x000: Dividend register
	volatile S32_T			DIVISOR;				//0x004: Divisor register
	volatile S32_T			QUOTIENT;				//0x008: Quotient register
	volatile S32_T			REMAIN;					//0x00C: Remainder register
	volatile unsigned int	CR;						//0x010: Control register
 }CSP_HWD_T,*CSP_HWD_PTR; 
/**********************************************************************
@brief LCD Structure
**********************************************************************/
typedef struct{
    volatile unsigned int		IDR;            	//0x000: ID
    volatile unsigned int      	CEDR;         		//0x004: Clock control
    volatile unsigned int      	SRR;            	//0x008: Software reset Register
    volatile unsigned int      	CR;           		//0x00C: Control Reg
    volatile unsigned int      	CDR;           		//0x010: Masked Interrupt Status Register
    volatile unsigned int      	MOD;            	//0x014: Interrupt Clear Register
	volatile unsigned int      	SR;       			//0x018: Status Register 
	volatile unsigned int      	ICR;       			//0x01C: Interrupt Clear Register  
	volatile unsigned int      	IER;       			//0x020: Interrupt Enable Register  
	volatile unsigned int      	MISR;       		//0x024: Masked Interrupt Status
	volatile unsigned int      	CR2;       			//0x028: Control Reg 2
	volatile unsigned int 		ReservedD[245];		//0x02C: Reserved
    volatile unsigned int      	DMR[32];			//0x400~47C:Segment Data0~31
 } CSP_LCD_T, *CSP_LCD_PTR;
/***********************************************************************
@brief  LED Structure
**********************************************************************/
typedef struct{
    volatile unsigned int      CR;             			//0x000: Control Register
    volatile unsigned int      BRIGHT;         			//0x004: Brightness Control Register
    volatile unsigned int      RISR;           			//0x008: Raw Interrupt Status Register
    volatile unsigned int      IMCR;           			//0x00C: Interrupt Masking Control Reg
    volatile unsigned int      MISR;           			//0x010: Masked Interrupt Status Register
    volatile unsigned int      ICR;            			//0x014: Interrupt Clear Register
	volatile unsigned int		RSVD;          				//0x018: Reserved  
	volatile unsigned int      TIMCR;          			//0x01C: Timing Control
	volatile unsigned int      BLKER;          			//0x020: Blink enable Control
	volatile unsigned int      BLKDR;          			//0x024: Blink Clear Control
	volatile unsigned int      BLKST;          			//0x028: Blink Status Register
    volatile unsigned int      SEGDATA[10];       			//0x02C~0x048: Segment Data0~7 */
 } CSP_LED_T, *CSP_LED_PTR;
/***********************************************************************
 @brief  CMP Structure
**********************************************************************/
typedef struct{
    volatile unsigned int      CEDR;           			//0x000: D and Clock Control Register
    volatile unsigned int      CR0;            			//0x004: Control Register0
    volatile unsigned int      DFCR1;         				//0x008: Filter Control Register1
    volatile unsigned int      DFCR2;         				//0x00C: Filter Control Register2*/
    volatile unsigned int      WFCR;          				//0x010: Capture Window Control Register0
    volatile unsigned int      INPCR;         				//0x014: Input Config Register
    volatile unsigned int      RISR;           			//0x018: Raw Interrupt Status Reg
    volatile unsigned int      IMCR;           			//0x01C: Interrupt Masking Control Reg
    volatile unsigned int      MISR;           			//0x020: Masked Interrupt Status Reg
    volatile unsigned int      ICR;            			//0x024: Interrupt Clear Register
 } CSP_CMP_T, *CSP_CMP_PTR;
/***********************************************************************
 @brief  DMA Structure
**********************************************************************/
typedef struct
{
	volatile unsigned int	ISRX;  			//0x0000	Initial Source Addr Register
	volatile unsigned int	ISCRX;			//0x0004	Initial Source Control Register
	volatile unsigned int	IDRX;			//0x0008	Initial Target Addr Register
	volatile unsigned int	IDCRX; 			//0x000C	Initial Target Control Register
	volatile unsigned int	CRX;			//0x0010	Channelx Control Register
	volatile unsigned int	SRX;			//0x0014	Channelx Status Register
	volatile unsigned int	CSRX;			//0x0018	current Source Register
	volatile unsigned int	CDRX;   		//0x001C	current Target Register
    volatile unsigned int	MTRX;  			//0x0020	Mask Trigger Register
	volatile unsigned int  RSRX;      		//0x0024    Request Select Register
	volatile unsigned int	RSVD1[182];		//0x0028 
	volatile unsigned int	RSVD2[128];		//0x04fc
	volatile unsigned int	IDR;  			//0x0500	ID Register
	volatile unsigned int	SRR;			//0x0504	Soft Reset Register
	volatile unsigned int	CESR;			//0x0508	Status Register
	volatile unsigned int	ISR; 			//0x050C	Interrupt Status Register
	volatile unsigned int	ICR;			//0x0510	Interrupt Clear Register
} CSP_DMA_T; 
/***********************************************************************
 @brief  Tkey Structure
**********************************************************************/
typedef struct
{
	volatile unsigned int	TCH_IDR;  			//0x0000	Initial Source Addr Register
	volatile unsigned int	TCH_CCR;			//0x0004	Initial Source Control Register
	volatile unsigned int	TCH_CON0;			//0x0008	Initial Target Addr Register
	volatile unsigned int	TCH_CON1; 			//0x000C	Initial Target Control Register
	volatile unsigned int	TCH_RSSR;			//0x0010	Channelx Control Register
	volatile unsigned int	TCH_THR;			//0x0014	Channelx Status Register
	volatile unsigned int	TCH_SCVAL;			//0x0018	current Source Register
	volatile unsigned int	TCH_TKST;   		//0x001C	current Target Register
    volatile unsigned int	TCH_CHINF;  		//0x0020	Mask Trigger Register
	volatile unsigned int	TCH_RISR;  			//0x0024	Mask Trigger Register
	volatile unsigned int   TCH_MISR;      		//0x0028    Request Select Register
	volatile unsigned int	TCH_IMCR;			//0x002C 
	volatile unsigned int	TCH_ICR;			//0x0030
	volatile unsigned int   TCH_EVTRG;
	volatile unsigned int   TCH_EVPS;
	volatile unsigned int   TCH_EVSWF;
}CSP_TKEY_T;

typedef struct
{
	volatile unsigned int	TCH_DAT[32];		//0x1000-1080	Soft Reset Register
}CSP_TKEY1_T;

typedef struct
{
	volatile unsigned int	TCH_SEQxCON[32]; 	//0x2000-2080	Interrupt Status Register
}CSP_TKEY2_T;
/***********************************************************************
@brief  Flash Address Setting
**********************************************************************/ 
 #define FLASHBase 		0x00000000
 #define FLASHSize 		0x00010000
 #define FLASHLimit 	(FLASHBase + FLASHSize) 
 #define DFLASHBase 	0x10000000
 #define DFLASHSize 	0x10001000
 #define DFLASHLimit 	(FLASHBase + FLASHSize) 
/***********************************************************************
@brief  SRAM Address Setting
**********************************************************************/ 
#ifdef REMAP
	#define SRAMBASE		0x00000000
	#define SRAMSIZE 		0x00002000
	#define SRAMLIMIT		(SRAMBASE + SRAMSIZE) 
	#define MEMVECTORBASE	0x00000700
	#define MEMVECTORSIZE	(0x50 << 2)
#else
	#define SRAMBASE 		0x20000000
	#define SRAMSIZE 		0x00002000
	#define SRAMLIMIT 		(SRAMBASE + SRAMSIZE) 
	#define MEMVECTORBASE 	0x20000700
	#define MEMVECTORSIZE 	(0x50 << 2)
#endif
/***********************************************************************
@brief  Peripheral Address Setting
**********************************************************************/ 
#define APB_PERI_BASE		0x40000000UL 
#define APB_SFM0_BASE   	(APB_PERI_BASE + 0x00000)
#define APB_IFC_BASE    	(APB_PERI_BASE + 0x10000)
#define APB_SYS_BASE  	    (APB_PERI_BASE + 0x11000)
#define APB_ETCB_BASE    	(APB_PERI_BASE + 0x12000)
#define APB_TKEY_BASE    	(APB_PERI_BASE + 0x20000)
#define APB_TKEY2_BASE    	(APB_PERI_BASE + 0x22000)
#define APB_TKEY1_BASE    	(APB_PERI_BASE + 0x21000)
#define APB_ADC0_BASE    	(APB_PERI_BASE + 0x30000)
#define APB_BT0_BASE       	(APB_PERI_BASE + 0x50000)
#define APB_BT1_BASE      	(APB_PERI_BASE + 0x51000)
#define APB_CNTA_BASE     	(APB_PERI_BASE + 0x52000)
#define APB_GPTA0_BASE    	(APB_PERI_BASE + 0x53000)
#define APB_GPTA1_BASE    	(APB_PERI_BASE + 0x54000)
#define APB_GPTB0_BASE    	(APB_PERI_BASE + 0x55000)
#define APB_GPTB1_BASE    	(APB_PERI_BASE + 0x56000)
#define APB_EPT0_BASE   	(APB_PERI_BASE + 0x57000)
#define APB_RTC_BASE		(APB_PERI_BASE + 0x60000)
#define APB_LPT_BASE     	(APB_PERI_BASE + 0x61000)
#define APB_WWDT_BASE		(APB_PERI_BASE + 0x62000)
#define APB_LED0_BASE    	(APB_PERI_BASE + 0x70000)
#define APB_UART0_BASE   	(APB_PERI_BASE + 0x80000)
#define APB_UART1_BASE   	(APB_PERI_BASE + 0x81000)
#define APB_UART2_BASE  	(APB_PERI_BASE + 0x82000)
#define APB_USART0_BASE   	(APB_PERI_BASE + 0x83000)
#define APB_SPI0_BASE  		(APB_PERI_BASE + 0x90000)	//SPI
#define APB_I2C0_BASE   	(APB_PERI_BASE + 0xA0000)	//IIC
#define APB_SIO0_BASE  		(APB_PERI_BASE + 0xB0000)	
#define AHB_GPIO_BASE 		0x60000000
#define APB_GPIOA0_BASE  	(AHB_GPIO_BASE + 0x0000) 	//A0  
#define APB_GPIOA1_BASE  	(AHB_GPIO_BASE + 0x1000) 	//A1  
#define APB_GPIOB0_BASE  	(AHB_GPIO_BASE + 0x2000) 	//B0 
#define APB_GPIOC0_BASE  	(AHB_GPIO_BASE + 0x4000) 	//C0 
#define APB_IGRP_BASE		(AHB_GPIO_BASE + 0xF000)	//IGRP
#define APB_LCD0_BASE    	(APB_PERI_BASE + 0xC0000)
#define APB_CMP0_BASE    	(APB_PERI_BASE + 0xD0000)
#define APB_CMP1_BASE    	(APB_PERI_BASE + 0xD1000)
#define AHB_RFL_BASE     	(SRAMBASE + 0x02000)
#define AHB_CRC_BASE     	0x50000000
#define AHB_HWD_BASE		0x70000000	
#define AHB_DMA_BASE    	0x80000000
#define APB_DMA0_BASE		(AHB_DMA_BASE + 0x0000)	//DMA0
#define APB_DMA1_BASE		(AHB_DMA_BASE + 0x0080)	//DMA1
#define APB_DMA2_BASE		(AHB_DMA_BASE + 0x0100)	//DMA2
#define APB_DMA3_BASE		(AHB_DMA_BASE + 0x0180)	//DMA3

#define CK802_ADDR_BASE  	0xE000E000	
#define AHB_ADC_TEMP_BASE	0x00080100
/***********************************************************************
@brief  Interrupt Bit Position
**********************************************************************/ 
#define CORET_INT   (0x01ul<<0)       //IRQ0
#define SYSCON_INT  (0x01ul<<1)       //IRQ1
#define IFC_INT     (0x01ul<<2)       //IRQ2
#define ADC_INT     (0x01ul<<3)       //IRQ3
#define EPT0_INT    (0x01ul<<4)       //IRQ4
#define DMA_INT    	(0x01ul<<5)       //IRQ5
#define WWDT_INT    (0x01ul<<6)       //IRQ6
#define EXI0_INT    (0x01ul<<7)       //IRQ7
#define EXI1_INT    (0x01ul<<8)       //IRQ8
#define GPTA0_INT   (0x01ul<<9)       //IRQ9 
#define GPTA1_INT   (0x01ul<<10)      //IRQ10 
#define GPTB0_INT   (0x01ul<<11)      //IRQ11 
#define RTC_INT     (0x01ul<<12)      //IRQ12
#define UART0_INT   (0x01ul<<13)      //IRQ13
#define UART1_INT   (0x01ul<<14)      //IRQ14
#define UART2_INT   (0x01ul<<15)      //IRQ15
#define USART_INT   (0x01ul<<16)      //IRQ16
#define GPTB1_INT   (0x01ul<<17)      //IRQ17
#define SIO_INT     (0x01ul<<18)      //IRQ17
#define I2C_INT     (0x01ul<<19)      //IRQ19
#define SPI_INT     (0x01ul<<20)      //IRQ20
#define EXI2_INT    (0x01ul<<21)      //IRQ21
#define EXI3_INT    (0x01ul<<22)      //IRQ22
#define EXI4_INT    (0x01ul<<23)      //IRQ23
#define CA_INT      (0x01ul<<24)      //IRQ24
#define TKEY_INT    (0x01ul<<25)      //IRQ25
#define LPT_INT     (0x01ul<<26)      //IRQ26
#define LED_INT     (0x01ul<<27) 	  //IRQ27
#define CMP_INT     (0x01ul<<28)      //IRQ28
#define BT0_INT     (0x01ul<<29)      //IRQ29
#define BT1_INT     (0x01ul<<30)      //IRQ30
#define LCD_INT     (0x01ul<<31) 	  //IRQ31
/**********************************************************************
@brief  extern  typedef struct
**********************************************************************/ 
extern CSP_CK802_T  	*CK802    ;
extern CSP_IFC_T 		*IFC      ; 
extern CSP_SYSCON_T 	*SYSCON   ;
extern CSP_ETCB_T   	*ETCB 	  ;
extern CSP_TKEY_T 		*TKEY     ;
extern CSP_TKEY1_T 		*TKEY1     ;
extern CSP_TKEY2_T 		*TKEY2     ;
extern CSP_ADC12_T 		*ADC0     ;
extern CSP_ADC12_TEMP_T *ADC0_TEMP  ;
extern CSP_GPIO_T 		*GPIOA0   ;
extern CSP_GPIO_T 		*GPIOA1   ;
extern CSP_GPIO_T 		*GPIOB0   ;
extern CSP_GPIO_T 		*GPIOC0   ;
extern CSP_IGRP_T		*GPIOGRP  ;
extern CSP_UART_T 		*UART0    ;
extern CSP_UART_T 		*UART1    ;
extern CSP_UART_T 		*UART2    ;
extern CSP_USART_T 		*USART0    ;
extern CSP_SSP_T  		*SPI0     ;
extern CSP_SIO_T  		*SIO0     ;
extern CSP_I2C_T  		*I2C0     ;
extern CSP_CA_T  		*CA0      ;
/*extern CSP_GPTA_T 		*GPTA0    ;
extern CSP_GPTA_T 		*GPTA1    ;
extern CSP_GPTB_T 		*GPTB0    ;
extern CSP_GPTB_T 		*GPTB1    ;*/
extern CSP_GPTX_T 		*GPTA0    ;
extern CSP_GPTX_T 		*GPTA1    ;
extern CSP_GPTX_T 		*GPTB0    ;
extern CSP_GPTX_T 		*GPTB1    ;
extern CSP_EPT_T 		*EPT0     ;
extern CSP_LPT_T 		*LPT      ;
extern CSP_HWD_T 		*HWD      ;
extern CSP_WWDT_T 		*WWDT     ;
extern CSP_BT_T  		*BT0      ;
extern CSP_BT_T  		*BT1      ;
extern CSP_CRC_T 		*CRC      ;
extern CSP_RTC_T 		*RTC      ;
extern CSP_LCD_T 		*LCD     ;
extern CSP_LED_T 		*LED0     ;
extern CSP_CMP_T    	*CMP0	  ;
extern CSP_CMP_T    	*CMP1	  ;
extern CSP_DMA_T    	*DMA	  ;
extern CSP_DMA_T    	*DMA0	  ;
extern CSP_DMA_T    	*DMA1	  ;
extern CSP_DMA_T    	*DMA2	  ;
extern CSP_DMA_T    	*DMA3	  ;
/**********************************************************************
@brief ISR Define for generating special interrupt related (CK802), with compile option -mistack
**********************************************************************/ 
void MisalignedHandler(void) 	__attribute__((isr));
void IllegalInstrHandler(void) 	__attribute__((isr));
void AccessErrHandler(void) 	__attribute__((isr));
void BreakPointHandler(void) 	__attribute__((isr));
void UnrecExecpHandler(void)	__attribute__((isr));
void Trap0Handler(void) 		__attribute__((isr));
void Trap1Handler(void) 		__attribute__((isr));
void Trap2Handler(void) 		__attribute__((isr));
void Trap3Handler(void) 		__attribute__((isr));
void PendTrapHandler(void) 		__attribute__((isr));

void CORETHandler(void) 		__attribute__((isr));
void SYSCONIntHandler(void) 	__attribute__((isr));
void IFCIntHandler(void) 		__attribute__((isr));
void ADCIntHandler(void) 		__attribute__((isr));
void EPT0IntHandler(void) 		__attribute__((isr));
void DMAIntHandler(void)		__attribute__((isr));
void WWDTIntHandler(void) 		__attribute__((isr));
void EXI0IntHandler(void) 		__attribute__((isr));
void EXI1IntHandler(void) 		__attribute__((isr));
void GPTA0IntHandler(void) 		__attribute__((isr));
void GPTA1IntHandler(void) 		__attribute__((isr));
void GPTB0IntHandler(void) 		__attribute__((isr));
void RTCIntHandler(void) 		__attribute__((isr));
void UART0IntHandler(void) 		__attribute__((isr));
void UART1IntHandler(void) 		__attribute__((isr));
void UART2IntHandler(void) 		__attribute__((isr));
void USART0IntHandler(void) 	__attribute__((isr));
void GPTB1IntHandler(void) 		__attribute__((isr));
void SIO0IntHandler(void) 		__attribute__((isr));
void I2CIntHandler(void) 		__attribute__((isr));
void SPI0IntHandler(void)		__attribute__((isr));
void EXI2to3IntHandler(void) 	__attribute__((isr));
void EXI4to9IntHandler(void) 	__attribute__((isr));
void EXI10to15IntHandler(void) 	__attribute__((isr));
void CNTAIntHandler(void) 		__attribute__((isr));
void TKEYIntHandler(void) 		__attribute__((isr));
void LPTIntHandler(void)		__attribute__((isr));
void LEDIntHandler(void) 		__attribute__((isr));
void CMPIntHandler(void) 		__attribute__((isr));
void BT0IntHandler(void) 		__attribute__((isr));
void BT1IntHandler(void) 		__attribute__((isr));
void LCDIntHandler(void) 		__attribute__((isr));


/**********************************************************************
@brief  extern functions
**********************************************************************/ 
extern int __divsi3 (int a, int b);
extern int __modsi3 (int a, int b);
extern unsigned int __udivsi3 (unsigned int a, unsigned int b);
extern unsigned int __umodsi3 (unsigned int a, unsigned int b);
extern void delay_nms(unsigned int t);
extern void delay_nus(unsigned int t);

#endif
/*********************************************************************** 
//				(C) COPYRIGHT 2022 APT Chip 
//						 END OF FILE         
***********************************************************************/