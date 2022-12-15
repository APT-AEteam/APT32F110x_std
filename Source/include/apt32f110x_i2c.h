/*
  ******************************************************************************
  * @file    apt32f110_i2c.h
  * @author  APT AE Team
  * @version V1.00
  * @date    2022/02/21
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
 

#ifndef _apt32f110_i2c_H
#define _apt32f110_i2c_H

/****************************************************
//include
*****************************************************/ 
#include "apt32f110x.h"

#define BUFSIZE             255

/******************************************************************************
 @brief : I2C Control Register 
******************************************************************************/
 #define I2C_MASTER_EN      (0x01ul << 0)   // I2C Master Mode             */
 #define I2C_MASTER_DIS     (0x00ul << 0)   // I2C Master Mode             */
 #define I2C_SS             (0x01ul << 1)   // I2C Standard Speed Mode     */ 
 #define I2C_FS             (0x02ul << 1)   // I2C Fast Speed Mode         */ 
 #define I2C_HS             (0x03ul << 1)   // I2C High Speed Mode         */ 
 #define I2C_10BIT_SLAVE    (0x01ul << 3)   // I2C 10bit or 7bit in Slave  */
 #define I2C_7BIT_SLAVE     (0x00ul << 3)   // I2C 10bit or 7bit in Slave  */
 #define I2C_10BIT_MASTER   (0x01ul << 4)   // I2C 10bit or 7bit in Master */
 #define I2C_7BIT_MASTER    (0x00ul << 4)   // I2C 10bit or 7bit in Master */           
 #define I2C_RESTART_EN     (0x01ul << 5)   // I2C Restart Enable          */
 #define I2C_RESTART_DIS    (0x00ul << 5)   // I2C Restart Disable         */
 #define I2C_SLAVE_EN       (0x00ul << 6)   // I2C Slave Enable            */
 #define I2C_SLAVE_DIS      (0x01ul << 6)   // I2C Slave Disable           */
 #define I2C_STOPDET_IFADD  (0x01ul << 7)   // I2C STOPDET If Addressed    */
 #define I2C_STOPDET_ALS    (0x00ul << 7)   // I2C STOPDET Always          */
 #define I2C_TX_EMPTY_CTRL  (0x01ul << 8)   // I2C TX_EMPTY Control        */
 #define I2C_TX_EMPTY_DONE  (0x00ul << 8)   // I2C TX_EMPTY and Send Done  */
 #define I2C_RX_HOLD_CTRL   (0x01ul << 9)   // I2C Rx Hold Ctrl @FIFO Full */
 #define I2C_RX_HOLD_NONE   (0x00ul << 9)   // I2C Rx Hold None @FIFO Full */
 #define I2C_STOPDET_MM     (0x01ul <<10)   // I2C STOPDET only in Master  */
 #define I2C_BUSCLR_EN      (0x01ul <<11)   // I2C Enable Bus Clear Feature */
 #define I2C_BUSCLR_DIS     (0x00ul <<11)   // I2C Disable Bus Clear Feature


/******************************************************************************
 @brief : I2C Data and Command Register 
******************************************************************************/
 #define I2C_CMD_READ       (0x01ul << 8)   // I2C Read Command            */
 #define I2C_CMD_WRITE      (0x00ul << 8)   // I2C Write Command           */
 #define I2C_CMD_STOP       (0x01ul << 9)   // I2C Stop after this byte    */
 #define I2C_CMD_NONESTOP   (0x00ul << 9)   // I2C None Stop When FIFO Empty or Not    */
 #define I2C_CMD_RESTART0    (0x00ul <<10)   // I2C Restart Mode0          */
 #define I2C_CMD_RESTART1    (0x01ul <<10)   // I2C Restart Mode1          */
 #define I2C_CMD_1stDATA    (0x01ul <<11)   // I2C First Data Byte       */
 #define I2C_DATA(val)      (((val) & 0xFFul) << 0)  // Data Writing Macro */

/*****************************************************************************
 @brief : I2C Enable Register
******************************************************************************/                     
 #define I2C_ENABLE         (0x01ul << 0)   // I2C Enable                  */
 #define I2C_DISABLE        (0x00ul << 0)   // I2C Enable                  */
 #define I2C_ABORT          (0x01ul << 1)   // I2C Abort Transfer          */
 #define I2C_ABORT_OV       (0x00ul << 1)   // I2C Abort Transfer Over or No Abort          */
 #define I2C_TX_CMD_BLOCK   (0x01ul << 2)   // I2C Block Transmission      */
 #define I2C_SDA_REC_EN     (0x01ul << 3)   // I2C Enable Stuck Recovery   */
 #define I2C_SDA_REC_DIS    (0x00ul << 3)   // I2C Enable Stuck Recovery   */

/*****************************************************************************
 @brief : I2C STATUS Register
******************************************************************************/                     
 #define I2C_BUSY           (0x01ul << 0)   // I2C Activity                */
 #define I2C_FREE           (0x00ul << 0)   // I2C Activity                */
 #define I2C_TFNF           (0x01ul << 1)   // I2C Transmit FIFO Not Full  */
 #define I2C_TFNF_FULL      (0x00ul << 1)   // I2C Transmit FIFO Is Full   */
 #define I2C_TFE            (0x01ul << 2)   // I2C Transmit FIFO Empty     */
 #define I2C_TFE_NOT        (0x00ul << 2)   // I2C Transmit FIFO Not Empty     */
 #define I2C_RFNE           (0x01ul << 3)   // I2C Receive FIFO Not Empty  */
 #define I2C_RFNE_EMPTY     (0x00ul << 3)   // I2C Receive FIFO Is Empty  */
 #define I2C_RFF            (0x01ul << 4)   // I2C Receive FIFO Full       */
 #define I2C_MST_BUSY       (0x01ul << 5)   // I2C Master FSM Activity     */
 #define I2C_MST_FREE       (0x00ul << 5)   // I2C Master FSM Free     */
 #define I2C_SLV_BUSY       (0x01ul << 6)   // I2C Slave  FSM Activity     */
 #define I2C_SLV_FREE       (0x01ul << 6)   // I2C Slave  FSM Free     */
 #define I2C_REC_FREE       (0x00ul << 6)   // I2C Recovery No FAIL    */
 #define I2C_REC_FAIL       (0x01ul << 11)   // I2C Recovery FAIL    */
 
/*****************************************************************************
 @brief : I2C Interrupt Mask/Status Register
******************************************************************************/                     
 #define I2C_RX_UNDER       (0x01ul << 0)   // I2C Interrupt Status        */
 #define I2C_RX_OVER        (0x01ul << 1)   // I2C Interrupt Status        */
 #define I2C_RX_FULL        (0x01ul << 2)   // I2C Interrupt Status        */
 #define I2C_TX_OVER        (0x01ul << 3)   // I2C Interrupt Status        */
 #define I2C_TX_EMPTY       (0x01ul << 4)   // I2C Interrupt Status        */
 #define I2C_RD_REQ         (0x01ul << 5)   // I2C Interrupt Status        */
 #define I2C_TX_ABRT        (0x01ul << 6)   // I2C Interrupt Status        */
 #define I2C_RX_DONE        (0x01ul << 7)   // I2C Interrupt Status        */
 #define I2C_INT_BUSY       (0x01ul << 8)   // I2C Interrupt Status        */
 #define I2C_STOP_DET       (0x01ul << 9)   // I2C Interrupt Status        */
 #define I2C_START_DET      (0x01ul <<10)   // I2C Interrupt Status        */
 #define I2C_GEN_CALL       (0x01ul <<11)   // I2C Interrupt Status        */
 #define I2C_RESTART_DET    (0x01ul <<12)   // I2C Interrupt Status        */
 #define I2C_MST_ON_HOLD    (0x01ul <<13)   // I2C Interrupt Status        */
 #define I2C_SCL_SLOW       (0x01ul <<14)   // I2C Interrupt Status        */

 
/*****************************************************************************
 @brief : I2C SDA hold/setup Timing Register
******************************************************************************/                     
 #define I2C_TX_HOLD(val)   (((val) & 0xFFul) << 0)   // SDA TX Hold Delay */
 #define I2C_RX_HOLD(val)   (((val) & 0xFFul) <<16)   // SDA RX Hold Delay */
 #define I2C_SETUP(val)     (((val) & 0xFFul) << 0)   // SDA Setup Delay   */
 
/*****************************************************************************
 @brief : I2C Burr Interference Filter Control Register
******************************************************************************/                     
 #define I2C_SPKLEN(val)     (((val) & 0xFFul) << 0)   //I2C Burr interference filter control register   */
 
/*****************************************************************************
 @brief : I2C SCL/SDA Stuck Time Out
******************************************************************************/                     
 #define I2C_SCL_TOUT(val)   (((val) & 0xFFFFFFFFul) << 0)   //I2C SCL Stuck Time Out   */
 #define I2C_SDA_TOUT(val)   (((val) & 0xFFFFFFFFul) << 0)   //I2C SDA Stuck Time Out   */

/*****************************************************************************
 @brief: I2C General Call Register
******************************************************************************/                     
 #define I2C_GCALL_EN          (0x01ul << 0)   // I2C uses ACK to answer General Call     */
 #define I2C_GCALL_DIS         (0x00ul << 0)   // I2C does not generate a General Call interrupt     */

/*****************************************************************************
 @brief : I2C Slave NACK Control Register
******************************************************************************/                     
 #define I2C_NACK_DATA          (0x01ul << 0)   // I2C Generate a NACK after the data byte is received     */
 #define I2C_NACK_NORMAL       (0x00ul << 0)   // I2C Generate NACK/ACK as normal  */ 

/*****************************************************************************
 @brief : I2C IO selection
******************************************************************************/   
typedef enum
{
    I2C_SDA_PA0_3= 0,		//AF2=5
	I2C_SDA_PA0_4= 1,		//AF4=7
	I2C_SDA_PB0_1= 2,		//AF3=6
    I2C_SDA_PA0_8= 3,		//AF3=6
    I2C_SDA_PB0_7= 4,		//AF2=5
	I2C_SDA_PA1_10= 5,		//AF6=9
	I2C_SDA_PA1_13= 6,		//AF6=9
}I2C_SDA_TypeDef;
/*****************************************************************************
 @brief : I2C IO selection
******************************************************************************/   
typedef enum
{
    I2C_SCL_PA0_3 = 0,		//AF4=7	
	I2C_SCL_PA0_4 = 1,		//AF2=5
    I2C_SCL_PB0_0 = 2,		//AF3=6
    I2C_SCL_PA0_7 = 3,		//AF3=6
	I2C_SCL_PB0_6 = 4,		//AF2=5
	I2C_SCL_PA1_9 = 5,		//AF6=9
	I2C_SCL_PA1_12 = 6,		//AF6=9
}I2C_SCL_TypeDef;
/*****************************************************************************
 @brief : I2C MODE
******************************************************************************/   
typedef enum
{
	STANDARD_MODE = (0x01ul << 1),
    FAST_MODE=(0x02ul << 1),
}I2C_SPEEDMODE_TypeDef;
/*****************************************************************************
 @brief : I2C SLAVE BIT
******************************************************************************/   
typedef enum
{
	I2C_SLAVE_7BIT= (0x00ul << 3),
    I2C_SLAVE_10BIT=(0x01ul << 3),
}I2C_SLAVEBITS_TypeDef;
/*****************************************************************************
 @brief : I2C MASTER BIT
******************************************************************************/   
typedef enum
{
	I2C_MASTRER_7BIT= (0x00ul << 4),
    I2C_MASTRER_10BIT=(0x01ul << 4),
}I2C_MASTRERBITS_TypeDef;
/*****************************************************************************
 @brief : I2C TX DMA SEL
******************************************************************************/   
typedef enum
{
	I2C_TX_FL_Less_FIFO_7		=	0X00<<3,
	I2C_TX_FL_Less_FIFO_FLSEL	=	0X01<<3
}I2C_TX_DMA_SEL_TypeDef;
/*****************************************************************************
 @brief : I2C RX DMA SEL
******************************************************************************/   
typedef enum
{
	I2C_RX_FL_Greater_FIFO_1		=	0X00<<2,
	I2C_RX_FL_Greater_FIFO_FLSEL	=	0X01<<2
}I2C_RX_DMA_SEL_TypeDef;
/*********************************************************************** 
 @brief  I2C extern functions                  
***********************************************************************/ 
extern void I2C_Master_CONFIG(I2C_SDA_TypeDef I2C_SDA_IO,I2C_SCL_TypeDef I2C_SCL_IO,I2C_SPEEDMODE_TypeDef SPEEDMODE,
								I2C_MASTRERBITS_TypeDef MASTERBITS,U16_T I2C_MASTER_ADD,U16_T SS_SCLH,U16_T SS_SCLL);
extern void I2C_Slave_CONFIG(I2C_SDA_TypeDef I2C_SDA_IO,I2C_SCL_TypeDef I2C_SCL_IO,I2C_SPEEDMODE_TypeDef SPEEDMODE,
						I2C_SLAVEBITS_TypeDef SLAVEBITS,U16_T I2C_SALVE_ADDS,U16_T SS_SCLHX,U16_T SS_SCLLX);
extern void I2C_SDA_TSETUP_THOLD_CONFIG(U8_T SDA_TSETUP , U8_T SDA_RX_THOLD , U16_T SDA_TX_THOLD);						 
extern void I2C_ConfigInterrupt_CMD(FunctionalStatus NewState,U32_T INT_TYPE);
extern void I2C_FIFO_TriggerData(U16_T RX_FLSEL,U16_T TX_FLSEL);
extern void I2C_Stop(void);
extern void I2C_Enable(void);
extern void I2C_Disable(void);
extern void I2C_Abort_EN(void);
extern U8_T I2C_Abort_Status(void);
extern void I2C_SDA_Recover_EN(void);
extern void I2C_SDA_Recover_DIS(void);
extern void I2C_Int_Enable(void);
extern void I2C_Int_Disable(void);
extern void I2C_WRITE_Byte(U8_T write_adds,U8_T i2c_data);
extern void I2C_WRITE_nByte(U8_T write_adds,volatile U8_T *i2c_data,U8_T NumByteToWrite);
extern U8_T I2C_READ_Byte(U8_T read_adds);
extern void I2C_READ_nByte(U8_T read_adds,volatile U8_T *i2c_data,U8_T NumByteToWrite);
extern void I2C_Slave_Receive(void);
extern void I2C_DeInit(void);
extern void I2C_RESET(void);
extern void I2C_MASTER_CONFIG(void);
extern void I2C_DMA_Control(U8_T I2C_Tx_Rx_CMD , I2C_TX_DMA_SEL_TypeDef I2C_TX_FL_Less_X , I2C_RX_DMA_SEL_TypeDef I2C_RX_FL_Greater_X);
extern volatile uint8_t I2CWrBuffer[BUFSIZE];
extern volatile uint8_t I2CRdBuffer[BUFSIZE];
extern volatile U8_T f_ERROR;
extern void I2C_SLAVE_CONFIG(void);
#endif   // apt32f110_i2c_H */

/*********************************************************************** 
//				(C) COPYRIGHT 2022 APT Chip 
//						 END OF FILE         
***********************************************************************/