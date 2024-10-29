/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: shaaban elsayed         ******************************/
/***************************     Layer:  MCAL                 ******************************/
/***************************     SWC:    SPI                  ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define  SPDR   *((volatile u8* ) 0x2F)   //SPI Data register
#define  SPCR   *((volatile u8* ) 0x2D)     //SPI control regisster
#define  SPSR   *((volatile u8* ) 0x2E)      //SPI status register
/*
#define  SPSR_SPIF     7                   //SPI interrupt flag
#define  SPSR_SPI2X    0                 //Prescalar bit 2

#define  SPCR_SPE     6                      //SPI enable
#define  SPCR_MSTR    4                        //Master bit    
#define  SPCR_SPR1    1                      //Prescalar bit 1
#define  SPCR_SPR0    0                       //Prescalar bit 0
*/

/*---------------------------------------MACRO Declarations-----------------------------------*/
#define SPI_CLK_OVER_2 0
#define SPI_CLK_OVER_4 1
#define SPI_CLK_OVER_8 2
#define SPI_CLK_OVER_16 3
#define SPI_CLK_OVER_32 4
#define SPI_CLK_OVER_64 5
#define SPI_CLK_OVER_128 6
#define SPI2X 0
#define SPIF 7

//SPI Interrupt Enable
#define SPIE 7
//SPI Enable
#define SPE  6
//Data Order
#define DORD 5
//Master/Slave Select
#define MSTR 4
//Clock Polarity
#define CPOL 3
//Clock Phase
#define CPHA 2
//SPI CLK Rate Select bit1
#define SPR1 1
//SPI CLK Rate Select bit0
#define SPR0 0


#define SPI_LSB_FIRST 1
#define SPI_MSB_FIRST 0

#define SPI_MASTER 1
#define SPI_SLAVE  0

#define RISING_THEN_FALLING_SPI 1
#define FALLING_THEN_RISING_SPI 0

#define SAMPLE_THEN_SETUP_SPI 1
#define SETUP_THEN_SAMPLE_SPI 0



#endif