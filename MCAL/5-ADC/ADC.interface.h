/****************************************************************/
/****************************************************************/
/**********************  Author: shaaban elsayed ****************/
/**********************  Layer:MCAL              ****************/
/**********************  SWE:ADC               ****************/
/**********************  Verison:1.00            ****************/
/**********************  Date:8/4/2024          ****************/
/****************************************************************/
/****************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInit(void);
u8 ADC_u8GetChannelReading(u8 Copy_u8Channel);

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel,u8* Copy_pu8Reading );

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel,u8* Copy_puReading,void (*Copy_pvNotficationFunc)(void));
#endif