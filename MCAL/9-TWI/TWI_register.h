/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: shaaban elsayed         ******************************/
/***************************     Layer:  MCAL                 ******************************/
/***************************     SWC:    TWI                  ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_

#define    TWBR   *((volatile u8* ) 0x20)   //TWI Bit rate register
#define    TWCR   *((volatile u8* ) 0x56) 
#define    TWCR_TWINT    7           //TWI interrupt flag
#define    TWCR_TWEA     6           //Enable ACK 
#define    TWCR_TWSTA    5           //Start condition bit
#define    TWCR_TWSTO    4           //Stop bit
#define    TWCR_TWWC     3           //write collison flag
#define    TWCR_TWEN     2           //enable TWI bit 
#define    TWCR_TWIE     0           //TWI interrupt flag

#define    TWSR   *((volatile u8* ) 0x21) 
#define    TWSR_BIT7    7   /*5 bits  7-3 TWI status*/
#define    TWSR_BIT6    6
#define    TWSR_BIT5    5
#define    TWSR_BIT4    4
#define    TWSR_BIT3    3
#define    TWSR_TWPS1   1     /*Prescalar */
#define    TWSR_TWPSO   0

#define    TWDR   *((volatile u8* ) 0x23) 
#define    TWDR_BIT7     7     /* 8 bit for data*/
#define    TWDR_BIT6     6
#define    TWDR_BIT5     5
#define    TWDR_BIT4     4
#define    TWDR_BIT3     3
#define    TWDR_BIT2     2
#define    TWDR_BIT1     1
#define    TWDR_BIT0     0

#define    TWAR   *((volatile u8* ) 0x22) 
#define    TWAR_BIT7      7       /*7 bits Slave Address Register*/
#define    TWAR_BIT6      6
#define    TWAR_BIT5      5
#define    TWAR_BIT4      4
#define    TWAR_BIT3      3
#define    TWAR_BIT2      2
#define    TWAR_BIT1      1
#define    TWAR_TWGGE      0   /*General call Recongition Enable bit*/

#endif