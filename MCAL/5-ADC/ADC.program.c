/****************************************************************/
/****************************************************************/
/**********************  Author: shaaban elsayed ****************/
/**********************  Layer:MCAL              ****************/
/**********************  SWE:ADC               ****************/
/**********************  Verison:1.00            ****************/
/**********************  Date:8/4/2024          ****************/
/****************************************************************/
/****************************************************************/

#include  "STD_TYPES.h"
#include "ADC.interface.h"
#include "DIO_interface.h"
#include "ADC.register.h"
#include "ADC.config.h"
#include "ADC.private.h"

static * ADC_pu8Reading=NULL;
static void (*ADC_pvCallBackNotifictionFunc)(void)=NULL;

u8 ADC_u8BustState=IDLE;

void ADC_voidInit(void){
	 // AVCC as referance voltage
	 SET_BIT(ADMUX,ADMUX_REFS0);
	 CLR_BIT(ADMUX,ADMUX_REFS1);
	 
	 //Active left  adjust
	 SET_BIT(ADMUX,ADMUX_ADLAR);
	 //Set Prescaler to divide by 128 
	 SET_BIT(ADCSRA,ADCSRA_ADPS2);
	 SET_BIT(ADCSRA,ADCSRA_ADPS1);
     SET_BIT(ADCSRA,ADCSRA_ADPS0);
	  
	// Enable peripheral
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}


u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel,u8* Copy_puReading){
	u32 Local_u32Counter=0;
	u8 Local_u8ErrorState=OK;
	if (ADC_u8BustState ==IDLE)
	{
	  ADC_u8BustState=BUSY;
	
	//Clear the MUX bits in ADMUX register
	ADMUX &=0b11100000;
	
	//Set the required channel into MUX bits
	ADMUX |=Copy_u8Channel;
	
	//Start converison
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	
	//Polling (Busy waiting) until conversion complete flag is set
	while (((GET_BIT(ADCSRA,ADCSRA_ADIE)==0) && (Local_u32Counter !=ADC_u32TIMEOUT) );
	{
		Local_u32Counter++;
	}
	if (Local_u32Counter==ADC_u32TIMEOUT)
	{
		//Loop is broken because thr timeout is reached 
		Local_u8ErrorState=NOK;
	}
	else 
	{
		//loop is broken because flag is raised
	
	//Clear rhe conversion complete flag
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	
	//Return the reading 
	*Copy_puReading=ADCH;
	
	/*ADC is finished,return it to IDEL*/
	ADC_u8BustState=IDLE;
	}
}
	else
	{
		Local_u8ErrorState=BUSY_FUNC; 
	}
	return Local_u8ErrorState;
   }
}


u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel,u8* Copy_puReading,void (*Copy_pvNotficationFunc)(void)){
	if (ADC_u8BustState==IDLE){
	
	u8 Local_u8ErrorState=OK;
	
	if ((Copy_puReading==NULL) || (Copy_pvNotficationFunc == NULL) )
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	else
	{
		// Make ADC busy inoreder not to worl until idle
		ADC_u8BustState =BUSY;
		
		//Initialze the reading varible globly
		ADC_pu8Reading = Copy_puReading;
		//Initialize the callback notifiction function globlly
		ADC_pvCallBackNotifictionFunc= Copy_pvNotficationFunc;
		
		//Clear the MUX bits in ADMUX register
		ADMUX &=0b11100000;
		
		//Set the required channel into MUX bits
		ADMUX |=Copy_u8Channel;
		
		//Start converison
		SET_BIT(ADCSRA,ADCSRA_ADSC);
		//ADC interrupt enable
		SET_BIT(ADCSRA,ADCSRA_ADIE);
		
	}
} 
    else 
	{
		Local_u8ErrorState= BUSY_FUNC;
	}	
	
	return Local_u8ErrorState;
}
	
	 	
 void__vector_16 (void)  __attribute__((signal));
  	
 void__vector_16 (void)
	  {
		  //Reading ADC result
		  *ADC_pu8Reading=ADCH;
		  /* Make ADC state be IDEL because it finished*/
		  ADC_u8BustState=IDLE;
		  
		  // Inoke the callback notifiction function
		  
		  ADC_pvCallBackNotifictionFunc();
		 
		 //Disable ADC conversion complete interrupt
		 CLR_BIT(ADCSRA,ADCSRA_ADIE);
		  
	  }