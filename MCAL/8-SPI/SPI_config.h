/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: shaaban elsayed         ******************************/
/***************************     Layer:  MCAL                 ******************************/
/***************************     SWC:    SPI                  ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*Choose mode 
master or slave*/
#define  MODE_SELECT   MASTER

/*
Choose CLK Polarity:
    RISING_THEN_FALLING_SPI
    FALLING_THEN_RISING_SPI
*/
#define CLK_POLARITY_SPI RISING_THEN_FALLING_SPI

/*
Choose CLK Phase:
    SAMPLE_THEN_SETUP_SPI
    SETUP_THEN_SAMPLE_SPI
*/
#define CLK_PHASE_SPI SETUP_THEN_SAMPLE_SPI

/*
Choose SPI CLK Rate:
    SPI_CLK_OVER_2   
    SPI_CLK_OVER_4   
    SPI_CLK_OVER_8   
    SPI_CLK_OVER_16  
    SPI_CLK_OVER_32  
    SPI_CLK_OVER_64  
    SPI_CLK_OVER_128 
*/
#define SPI_CLK_RATE SPI_CLK_OVER_16









#endif