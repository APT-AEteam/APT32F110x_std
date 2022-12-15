/*
  ******************************************************************************
  * @file    apt32f110_i2c.c
  * @author  APT SZ AE Team
  * @version V1.00
  * @date    2022/03/07
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
#include "apt32f110x_i2c.h"

/****************************************************
//define
*****************************************************/ 
volatile uint8_t I2CWrBuffer[BUFSIZE];
volatile uint8_t I2CRdBuffer[BUFSIZE];
volatile uint8_t RdIndex = 0;
volatile uint8_t WrIndex = 0;
volatile uint8_t I2C_Data_Adress;	
volatile uint8_t I2C_St_Adress;	
volatile U8_T f_ERROR=0;
volatile U32_T R_IIC_ERROR_CONT,R_IIC_ERROR_CONT2;

/****************************************************
//extern
*****************************************************/ 
extern void delay_nms(unsigned int t);


/*************************************************************/
//I2C RESET,CLEAR ALL REGISTER
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_DeInit(void)
{
    I2C0->ENABLE  	= 0;
    I2C0->IMSCR  	= 0;
    I2C0->ICR   	= 0X7FFF;
} 
/*************************************************************/
//I2C DMA Control
//EntryParameter:I2C_Tx_Rx_CMD,I2C_TX_FL_Less_X,I2C_RX_FL_Greater_X
//I2C_Tx_Rx_CMD:BIT0(RX dma cmd);BIT1(TX dam cmd)
//I2C_TX_FL_Less_X:I2C_TX_FL_Less_FIFO_7,I2C_TX_FL_Less_FIFO_FLSEL
//I2C_RX_FL_Greater_X:I2C_RX_FL_Greater_FIFO_1,I2C_RX_FL_Greater_FIFO_FLSEL
//ReturnValue:NONE
/*************************************************************/
void I2C_DMA_Control(U8_T I2C_Tx_Rx_CMD , I2C_TX_DMA_SEL_TypeDef I2C_TX_FL_Less_X , I2C_RX_DMA_SEL_TypeDef I2C_RX_FL_Greater_X)
{
	I2C0->DMACR=(I2C0->DMACR&0xfffffff0)|I2C_Tx_Rx_CMD|I2C_TX_FL_Less_X|I2C_RX_FL_Greater_X;
}
/*************************************************************/
//I2C MASTER Initial
//EntryParameter:SPEEDMODE,MASTERBITS,
//SPEEDMODE:FAST_MODE(>100K),STANDARD_MODE(<100K)
//MASTERBITS:I2C_MASTRER_7BIT/I2C_MASTRER_10BIT
//ReturnValue:NONE
/*************************************************************/
void I2C_Master_CONFIG(I2C_SDA_TypeDef I2C_SDA_IO,I2C_SCL_TypeDef I2C_SCL_IO,I2C_SPEEDMODE_TypeDef SPEEDMODE,
						I2C_MASTRERBITS_TypeDef MASTERBITS,U16_T I2C_MASTER_ADDS,U16_T SS_SCLHX,U16_T SS_SCLLX)
{
	//SDA IO Initial
    if(I2C_SDA_IO==I2C_SDA_PA0_3)
    {
    GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFF0FFF)  | 0x00005000;          
    }
    if(I2C_SDA_IO==I2C_SDA_PA0_4)
    {
    GPIOA0->CONLR = (GPIOA0->CONLR&0XFFF0FFFF)  | 0x00070000;          
    }
	if(I2C_SDA_IO==I2C_SDA_PB0_1)
    {
    GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFF0F)  | 0x00000060;          
    }
	if(I2C_SDA_IO==I2C_SDA_PA0_8)
    {
    GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFF0)  | 0x00000006;          
    }
	if(I2C_SDA_IO==I2C_SDA_PB0_7)
    {
    GPIOB0->CONLR = (GPIOB0->CONLR&0X0FFFFFFF)  | 0x50000000;          
    }
	if(I2C_SDA_IO==I2C_SDA_PA1_10)
    {
    GPIOA1->CONHR = (GPIOA1->CONHR&0XFFFFF0FF)  | 0x00000900;          
    }
	if(I2C_SDA_IO==I2C_SDA_PA1_13)
    {
    GPIOA1->CONHR = (GPIOA1->CONHR&0XFF0FFFFF)  | 0x00900000;          
    }
	//SCL IO Initial
	if (I2C_SCL_IO==I2C_SCL_PA0_3)
    {
    GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFF0FFF)  | 0x00007000;               
    }
	if (I2C_SCL_IO==I2C_SCL_PA0_4)
    {
    GPIOA0->CONLR = (GPIOA0->CONLR&0XFFF0FFFF)  | 0x00050000;               
    }
	if (I2C_SCL_IO==I2C_SCL_PB0_0)
    {
    GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFF0)  | 0x00000006;               
    }
	if (I2C_SCL_IO==I2C_SCL_PA0_7)
    {
    GPIOA0->CONLR = (GPIOA0->CONLR&0X0FFFFFFF)  | 0x60000000;               
    }
	if (I2C_SCL_IO==I2C_SCL_PB0_6)
    {
    GPIOB0->CONLR = (GPIOB0->CONLR&0XF0FFFFFF)  | 0x05000000;               
    }
	if (I2C_SCL_IO==I2C_SCL_PA1_9)
    {
    GPIOA1->CONHR = (GPIOA1->CONHR&0XFFFFFF0F)  | 0x00000090;               
    }
	if (I2C_SCL_IO==I2C_SCL_PA1_12)
    {
    GPIOA1->CONHR = (GPIOA1->CONHR&0XFFF0FFFF)  | 0x00090000;               
    }
	
	I2C0->ENABLE = (I2C0->ENABLE&0XFFFFFFFE)|I2C_DISABLE; 
	I2C0->CR =(I2C0->CR&0XFFFFF000)|I2C_MASTER_EN |I2C_SLAVE_DIS| SPEEDMODE | MASTERBITS | I2C_RESTART_EN;				//Repeat start bit enable
	I2C0->TADDR =I2C_MASTER_ADDS;
	if(SPEEDMODE==FAST_MODE)
	{
		I2C0->FS_SCLH  = SS_SCLHX;  							//SCL high time
		I2C0->FS_SCLL  = SS_SCLLX;  							//SCL low  time
	}
	else if(SPEEDMODE==STANDARD_MODE)
	{
		I2C0->SS_SCLH  = SS_SCLHX;  							//SCL high time
		I2C0->SS_SCLL  = SS_SCLLX;  							//SCL low  time
	}
	
}
/*************************************************************/
//I2C SLAVE Initial
//EntryParameter:SPEEDMODE,SLAVEBITS,I2C_SALVE_ADD
//SPEEDMODE:FAST_MODE(>100K),STANDARD_MODE(<100K)
//SLAVEBITS:I2C_SLAVE_7BIT/I2C_SLAVE_10BIT
//I2C_SALVE_ADD:I2C SLAVE ADDRESS
//ReturnValue:NONE
/*************************************************************/
void I2C_Slave_CONFIG(I2C_SDA_TypeDef I2C_SDA_IO,I2C_SCL_TypeDef I2C_SCL_IO,I2C_SPEEDMODE_TypeDef SPEEDMODE,
						I2C_SLAVEBITS_TypeDef SLAVEBITS,U16_T I2C_SALVE_ADDS,U16_T SS_SCLHX,U16_T SS_SCLLX)
{
	//SDA IO Initial
    if(I2C_SDA_IO==I2C_SDA_PA0_3)
    {
    GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFF0FFF)  | 0x00005000;          
    }
    if(I2C_SDA_IO==I2C_SDA_PA0_4)
    {
    GPIOA0->CONLR = (GPIOA0->CONLR&0XFFF0FFFF)  | 0x00070000;          
    }
	if(I2C_SDA_IO==I2C_SDA_PB0_1)
    {
    GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFF0F)  | 0x00000060;          
    }
	if(I2C_SDA_IO==I2C_SDA_PA0_8)
    {
    GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFF0)  | 0x00000006;          
    }
	if(I2C_SDA_IO==I2C_SDA_PB0_7)
    {
    GPIOB0->CONLR = (GPIOB0->CONLR&0X0FFFFFFF)  | 0x50000000;          
    }
	if(I2C_SDA_IO==I2C_SDA_PA1_10)
    {
    GPIOA1->CONHR = (GPIOA1->CONHR&0XFFFFF0FF)  | 0x00000900;          
    }
	if(I2C_SDA_IO==I2C_SDA_PA1_13)
    {
    GPIOA1->CONHR = (GPIOA1->CONHR&0XFF0FFFFF)  | 0x00900000;          
    }
	//SCL IO Initial
	if (I2C_SCL_IO==I2C_SCL_PA0_3)
    {
    GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFF0FFF)  | 0x00007000;               
    }
	if (I2C_SCL_IO==I2C_SCL_PA0_4)
    {
    GPIOA0->CONLR = (GPIOA0->CONLR&0XFFF0FFFF)  | 0x00050000;               
    }
	if (I2C_SCL_IO==I2C_SCL_PB0_0)
    {
    GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFF0)  | 0x00000006;               
    }
	if (I2C_SCL_IO==I2C_SCL_PA0_7)
    {
    GPIOA0->CONLR = (GPIOA0->CONLR&0X0FFFFFFF)  | 0x60000000;               
    }
	if (I2C_SCL_IO==I2C_SCL_PB0_6)
    {
    GPIOB0->CONLR = (GPIOB0->CONLR&0XF0FFFFFF)  | 0x05000000;               
    }
	if (I2C_SCL_IO==I2C_SCL_PA1_9)
    {
    GPIOA1->CONHR = (GPIOA1->CONHR&0XFFFFFF0F)  | 0x00000090;               
    }
	if (I2C_SCL_IO==I2C_SCL_PA1_12)
    {
    GPIOA1->CONHR = (GPIOA1->CONHR&0XFFF0FFFF)  | 0x00090000;               
    }


	I2C0->ENABLE = (I2C0->ENABLE&0XFFFFFFFE)|I2C_DISABLE;
	I2C0->CR =(I2C0->CR&0XFFFFF000)| I2C_MASTER_DIS |I2C_SLAVE_EN | SPEEDMODE | SLAVEBITS;
	I2C0->SADDR = I2C_SALVE_ADDS;
	if(SPEEDMODE==FAST_MODE)
	{
		I2C0->FS_SCLH  = SS_SCLHX;  							//SCL high time
		I2C0->FS_SCLL  = SS_SCLLX;  							//SCL low  time
	}
	else if(SPEEDMODE==STANDARD_MODE)
	{
		I2C0->SS_SCLH  = SS_SCLHX;  							//SCL high time
		I2C0->SS_SCLL  = SS_SCLLX;  							//SCL low  time
	}
	INTC_IPR4_WRITE(0X40400040);   								//setting highest INT Priority when using i2c as salve
}
/*************************************************************/
//I2C SDA TSETUP THOLD CONFIG
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_SDA_TSETUP_THOLD_CONFIG(U8_T SDA_TSETUP , U8_T SDA_RX_THOLD , U16_T SDA_TX_THOLD)
{
	I2C0->SDA_TSETUP=SDA_TSETUP;
	I2C0->SDA_THOLD=(SDA_RX_THOLD<<16)|SDA_TX_THOLD;
}
/*************************************************************/
//I2C INT CONFIG
//EntryParameter:I2C_RX_UNDER,I2C_RX_OVER,I2C_RX_FULL,I2C_TX_OVER    
//				 I2C_TX_EMPTY,I2C_RD_REQ,I2C_TX_ABRT,I2C_RX_DONE    
//				 I2C_INT_BUSY,I2C_STOP_DET,I2C_START_DET,I2C_GEN_CALL   
//				 I2C_RESTART_DET,I2C_MST_ON_HOLD,I2C_SCL_SLOW   
//NewState:ENABLE/DISABLE
//ReturnValue:NONE
/*************************************************************/
void I2C_ConfigInterrupt_CMD(FunctionalStatus NewState,U32_T INT_TYPE)
{
	if(NewState != DISABLE)
	{
		I2C0->IMSCR |= INT_TYPE;
	}
	else
	{
		I2C0->IMSCR &= (~INT_TYPE);
	}
}
/*************************************************************/
//I2C FIFO trigger data
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_FIFO_TriggerData(U16_T RX_FLSEL,U16_T TX_FLSEL)
{
	I2C0->RX_FLSEL = RX_FLSEL;  							
	I2C0->TX_FLSEL = TX_FLSEL;  							
}
/*************************************************************/
//I2C Stop
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_Stop(void)
{
	I2C0->DATA_CMD = (I2C0->DATA_CMD&0XFFFFFDFF)|I2C_CMD_STOP;                         //Enable I2C
}
/*************************************************************/
//I2C enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_Enable(void)
{
	I2C0->ENABLE = (I2C0->ENABLE&0XFFFFFFFE)|I2C_ENABLE;                         //Enable I2C
	while((I2C0->STATUS&0x1000)!=0x1000);
}
/*************************************************************/
//I2C disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_Disable(void)
{
	I2C0->ENABLE =(I2C0->ENABLE&0XFFFFFFFE)|I2C_DISABLE;                         //Disable I2C
	while((I2C0->STATUS&0x1000)==0x1000);
}
/*************************************************************/
//I2C Abort enable in master mode
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_Abort_EN(void)
{
	I2C0->ENABLE = (I2C0->ENABLE&0XFFFFFFFD)|I2C_ABORT;                         //Enable Abort
}
/*************************************************************/
//I2C Abort status
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
U8_T I2C_Abort_Status(void)
{
	uint8_t value = 0;
    uint32_t dat = 0;
	dat=(I2C0->ENABLE)&0x02;
    if (dat == 0x02)								
	{
	    value = 1;										//aborting
	} 
    return value;										//no abort or abort over
}
/*************************************************************/
//I2C RECOVER enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_SDA_Recover_EN(void)
{
	I2C0->ENABLE = (I2C0->ENABLE&0XFFFFFFF7)|I2C_SDA_REC_EN;                         //Enable Recover Enable
}
/*************************************************************/
//I2C RECOVER enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_SDA_Recover_DIS(void)
{
	I2C0->ENABLE = (I2C0->ENABLE&0XFFFFFFF7)|I2C_SDA_REC_DIS;                         //Enable Recover Disable
}
/*************************************************************/
//I2C Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_Int_Enable(void)
{
	INTC_ISER_WRITE(I2C_INT);                             //Enable I2C interrupt
}
/*************************************************************/
//I2C Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_Int_Disable(void)
{
    INTC_ICER_WRITE(I2C_INT);                             //Disable I2C interrupt
}
/*************************************************************/
//I2C reset 
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_RESET(void)
{
	I2C0->SRR=0X3;
}
/*************************************************************/
//I2C WRITE OneByte
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_WRITE_Byte(U8_T write_adds,U8_T i2c_data)
{;
	
	I2C0->DATA_CMD = I2C_CMD_WRITE|write_adds ;
	I2C0->DATA_CMD = i2c_data |I2C_CMD_STOP;
	R_IIC_ERROR_CONT2=0;
	do
	{
		if(R_IIC_ERROR_CONT2++>=100000)
		{
			R_IIC_ERROR_CONT2=0;
			f_ERROR=1;
			I2C_MASTER_CONFIG();
			//I2C_Disable();
			//I2C_Enable();
			break;
		}
	}
	while( (I2C0->STATUS & I2C_BUSY) != I2C_BUSY ); 		//Wait for FSM working
	do
	{
		if(R_IIC_ERROR_CONT2++>=100000)
		{
			R_IIC_ERROR_CONT2=0;
			f_ERROR=1;
			I2C_MASTER_CONFIG();
			//I2C_Disable();
			//I2C_Enable();
			break;
		}
	}
	while(((I2C0->STATUS) & I2C_TFE) != I2C_TFE);
}
/*************************************************************/
//I2C WRITE nByte
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_WRITE_nByte(U8_T write_adds,volatile U8_T *i2c_data,U8_T NumByteToWrite)
{
	//U32_T R_EEROR_CONT=0;
	U8_T i;
	I2C0->DATA_CMD = I2C_CMD_WRITE|write_adds ;
	for(i=0;i<NumByteToWrite;i++)
	{
		R_IIC_ERROR_CONT2=0;
		if(i>=NumByteToWrite-1)
		{
			I2C0->DATA_CMD = *(i2c_data+i) |I2C_CMD_STOP;
		}
		else
		{
			I2C0->DATA_CMD = *(i2c_data+i);
		}
		do
		{
			if(R_IIC_ERROR_CONT2++>=100000)
			{
				R_IIC_ERROR_CONT2=0;
				f_ERROR=1;
				I2C_MASTER_CONFIG();
				//I2C_Disable();
				//I2C_Enable();
				break;
			}
		}
		while( (I2C0->STATUS & I2C_BUSY) != I2C_BUSY ); 		//Wait for FSM working
		
		do
		{
			if(R_IIC_ERROR_CONT2++>=100000)
			{
				R_IIC_ERROR_CONT2=0;
				f_ERROR=1;
				I2C_MASTER_CONFIG();
				//I2C_Disable();
				//I2C_Enable();
				break;
			}
		}
		while(((I2C0->STATUS) & I2C_TFNF) != I2C_TFNF);
	}
}
/*************************************************************/
//I2C READ OneByte
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
U8_T I2C_READ_Byte(U8_T read_adds)
{
	U8_T value;
//	U32_T R_EEROR_CONT=0;
	I2C0->DATA_CMD = I2C_CMD_WRITE|read_adds|I2C_CMD_RESTART1;
	I2C0->DATA_CMD = I2C_CMD_READ |I2C_CMD_STOP;
	R_IIC_ERROR_CONT2=0;
	do
	{
		if(R_IIC_ERROR_CONT2++>=100000)
		{
			R_IIC_ERROR_CONT2=0;
			f_ERROR=1;
			I2C_MASTER_CONFIG();
			break;
		}
	}
	while( (I2C0->STATUS & I2C_BUSY) != I2C_BUSY ); 		//Wait for FSM working
	do
	{
		if(R_IIC_ERROR_CONT2++>=100000)
		{
			R_IIC_ERROR_CONT2=0;
			f_ERROR=1;
			I2C_MASTER_CONFIG();
			break;
		}
	}
	while( (I2C0->STATUS & I2C_RFNE) != I2C_RFNE ); 		//Wait for RX done
	value=I2C0->DATA_CMD &0XFF;
	return value;
}
/*************************************************************/
//I2C READ nByte
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_READ_nByte(U8_T read_adds,volatile U8_T *i2c_data,U8_T NumByteToWrite)
{
	//U32_T R_EEROR_CONT=0;
	U8_T i;
	I2C0->DATA_CMD = I2C_CMD_WRITE|read_adds|I2C_CMD_RESTART1;
	for(i=0;i<NumByteToWrite;i++)
	{
		R_IIC_ERROR_CONT2=0;
		if(i>=NumByteToWrite-1)
		{
			I2C0->DATA_CMD = I2C_CMD_READ |I2C_CMD_STOP;
		}
		else
		{
			I2C0->DATA_CMD = I2C_CMD_READ;
		}
		do
		{
			if(R_IIC_ERROR_CONT2++>=100000)
			{
				R_IIC_ERROR_CONT2=0;
				f_ERROR=1;
				I2C_MASTER_CONFIG();
				break;
			}
		}
		while( (I2C0->STATUS & I2C_BUSY) != I2C_BUSY ); 		//Wait for FSM working
		do
		{
			if(R_IIC_ERROR_CONT2++>=100000)
			{
				R_IIC_ERROR_CONT2=0;
				f_ERROR=1;
				I2C_MASTER_CONFIG();
				break;
			}
		}
		while( (I2C0->STATUS & I2C_RFNE) != I2C_RFNE ); 		//Wait for RX done
		*(i2c_data+i)=I2C0->DATA_CMD &0XFF;
	}
}
U16_T R_READ_BUF=0;
/*************************************************************/
//I2C slave Receive
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2C_Slave_Receive(void)
{
	
	if(!(((I2C0->MISR&I2C_SCL_SLOW)==I2C_SCL_SLOW)
			||((I2C0->MISR&I2C_TX_ABRT)==I2C_TX_ABRT)))				 //SCLK锁死,IIC发送中止))
	{
	if((I2C0->MISR&I2C_RX_FULL)==I2C_RX_FULL)        //有接收到数据
	{
		if(RdIndex==0)
		{
			RdIndex=1;
			I2C_Data_Adress=I2C0->DATA_CMD&0XFF;
			I2C_St_Adress=I2C_Data_Adress;
		}
		else if(RdIndex==1)
		{
			__asm volatile("nop"
					);	
			if(I2C_Data_Adress<BUFSIZE)
			{
				I2CRdBuffer[I2C_Data_Adress]= I2C0->DATA_CMD&0XFF;
			}
			I2C_Data_Adress++;
		}
		I2C0->ICR = I2C_RX_FULL;
		R_IIC_ERROR_CONT=0;
	}
		
	if((I2C0->MISR&I2C_RD_REQ)==I2C_RD_REQ)			//读请求产生
	{
		if(RdIndex==1)
		{
			RdIndex=2;
			WrIndex = I2C_St_Adress;
			I2C_ConfigInterrupt_CMD(ENABLE,I2C_TX_EMPTY);
			if(WrIndex<BUFSIZE)
			{
				I2C0->DATA_CMD= (I2C0->DATA_CMD&0XFFFFFF00) |I2CWrBuffer[WrIndex];
			}	
		}	
		I2C0->ICR = I2C_RD_REQ;
		R_IIC_ERROR_CONT=0;
	} 
                         
	if((I2C0->MISR&I2C_TX_EMPTY)==I2C_TX_EMPTY)				//IIC发送为空
	{
		if(RdIndex==2)
		{
			if(WrIndex+1<BUFSIZE)
			{
				I2C0->DATA_CMD= (I2C0->DATA_CMD&0XFFFFFF00) |I2CWrBuffer[WrIndex+1];
			}
			WrIndex++;
		}
		else
		{
			if(R_IIC_ERROR_CONT>10000)
			{
				I2C_Disable();
				I2C0->DATA_CMD= (I2C0->DATA_CMD&0XFFFFFF00);
				I2C_SLAVE_CONFIG();
				R_IIC_ERROR_CONT=0;
			}
			else
			{
				R_IIC_ERROR_CONT++;
			}
		}
		I2C0->CR = I2C_TX_EMPTY;
	}	
							
	if((I2C0->MISR&I2C_STOP_DET)==I2C_STOP_DET)
	{
		I2C0->ICR =I2C_STOP_DET;
		if(RdIndex!=0)
		{
			RdIndex=0;
			I2C_ConfigInterrupt_CMD(DISABLE,I2C_TX_EMPTY);
		}
		//R_READ_BUF=I2C0->DATA_CMD&0XFF;
		R_IIC_ERROR_CONT=0;
	}
}
else
{
		I2C_Disable();
		I2C0->DATA_CMD= (I2C0->DATA_CMD&0XFFFFFF00);
		I2C_SLAVE_CONFIG(); 
		RdIndex=0;	
		I2C_ConfigInterrupt_CMD(ENABLE,I2C_TX_EMPTY);				
		I2C0->ICR = I2C_SCL_SLOW|I2C_TX_ABRT;
		R_IIC_ERROR_CONT=0;
	
}
}



/*********************************************************************** 
//						 END OF FILE         
***********************************************************************/