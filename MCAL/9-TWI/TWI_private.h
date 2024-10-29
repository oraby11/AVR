/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: shaaban elsayed         ******************************/
/***************************     Layer:  MCAL                 ******************************/
/***************************     SWC:    TWI                  ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#define START_ACK              0x08  //start has been sent
#define REP_START_ACK          0x10  //repeated start
#define SLAVE_ADD_AND_WR_ACK   0x18 //Master transmit (slave address + write request) ACK
#define SLAVE_ADD_AND_RD_ACK   0x40 //Master transmit (slave address + read request) ACK
#define MASTER_WR_BYTE_ACK     0x28 //master transmit data ACK
#define MASTER_RD_BYTE_ACK     0x50 //Master recieve data with ACK
#define MASTER_RD_BYTE_NACK    0x58 //Master recieve data with no  ACK
#define SLAVE_ADD_RECD_RD_REQ  0xA8 //means that slave address is recieved with read request
#define SLAVE_ADD_RECD_WR_REQ  0x60 //means that slave address is recieved with write request
#define SLAVE_DATA_RECEIVED    0x80 //means that a byte is recieved
#define SLAVE_BYTE_TRANSMITTED 0xB8 //means that the written byte is transmited 



#endif 