/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: shaaban elsayed         ******************************/
/***************************     Layer:  MCAL                 ******************************/
/***************************     SWC:    SPI                  ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "BIT_MATHS.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_register.h"
void SPI_voidInit(void)
{
	#if MODE_SELECT==MASTER
	SET_BIT(SPCR, MSTR);
	#else
	CLR_BIT(SPCR, MSTR);
	#endif
	#if (CLK_PHASE_SPI == SAMPLE_THEN_SETUP_SPI)
	CLR_BIT(SPCR, CPHA);
	#else
	SET_BIT(SPCR, CPHA);
	#endif

	#if (CLK_POLARITY_SPI == RISING_THEN_FALLING_SPI)
	CLR_BIT(SPCR, CPOL);
	#else
	SET_BIT(SPCR, CPOL)
	#endif
	//Clock prescalar
    #if (SPI_CLK_RATE == SPI_CLK_OVER_2)
    CLR_BIT(SPCR, SPR0);
    CLR_BIT(SPCR, SPR1);
    SET_BIT(SPSR, SPI2X);
    #elif (SPI_CLK_RATE == SPI_CLK_OVER_4)
    CLR_BIT(SPCR, SPR0);
    CLR_BIT(SPCR, SPR1);
    CLR_BIT(SPSR, SPI2X);
    #elif (SPI_CLK_RATE == SPI_CLK_OVER_8)
    SET_BIT(SPCR, SPR0);
    CLR_BIT(SPCR, SPR1);
    SET_BIT(SPSR, SPI2X);
    #elif (SPI_CLK_RATE == SPI_CLK_OVER_16)
    SET_BIT(SPCR, SPR0);
    CLR_BIT(SPCR, SPR1);
    CLR_BIT(SPSR, SPI2X);
    #elif (SPI_CLK_RATE == SPI_CLK_OVER_32)
    CLR_BIT(SPCR, SPR0);
    SET_BIT(SPCR, SPR1);
    SET_BIT(SPSR, SPI2X);
    #elif (SPI_CLK_RATE == SPI_CLK_OVER_64)
    SET_BIT(SPCR, SPR0);
    SET_BIT(SPCR, SPR1);
    SET_BIT(SPSR, SPI2X);
    #elif (SPI_CLK_RATE == SPI_CLK_OVER_128)
    SET_BIT(SPCR, SPR0);
    SET_BIT(SPCR, SPR1);
    CLR_BIT(SPSR, SPI2X);
    #endif
	
	//SPI enable 
	SET_BIT(SPCR,SPE);
	
}


u8 SPI_u8TransceiveSynch(u8 Copy_u8DataRecieve,u8 Copy_u8DataSend )
{
	//Send data
	SPDR=Copy_u8DataRecieve;
	
	//polling to wait until transfer complete
	while(GET_BIT(SPSR,SPIF)==0);
	
	/*Get exchange data*/
	return SPDR;
}
u8 SPI_u8TransceiveAsynch(u8 Copy_u8DataRecieve,u8 Copy_u8DataSend,void (*Notfication)(void) )
{
	
	//Send data
	SPDR=Copy_u8DataRecieve;
	//polling to wait until transfer complete
	if(GET_BIT(SPSR,SPIF)==0)
	{
		SET_BIT(SPSR,SPIF);
		
	}
	/*Get exchange data*/
	return SPDR;
}


