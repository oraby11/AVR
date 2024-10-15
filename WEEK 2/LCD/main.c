

#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"

int main(void)
{
	/* Initialized LCD pins direction */
	DIO_u8SetPortDirection(CLCD_DATA_PORT,DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_OUTPUT);

	/* Initialized pins for buttons */
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_INPUT);

	/* Enable pull-up resistors for buttons */
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_HIGH);

	CLCD_voidInit();
	u8 Local_u8Button1State = 0;
	u8 Local_u8Button2State = 0;
	u8 Local_u8Button3State = 0;
	u8 Local_u8Counter = 0;

	
	CLCD_voidSendString("What Language?");
	_delay_ms(2000);  
	
	CLCD_voidClearLCD();
	CLCD_voidSendString("1-C\t 2-C++ \t");
	CLCD_voidGoToXY(1, 0);
	CLCD_voidSendString("3-C#");
	
     DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN0, &Local_u8Button1State);
     DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN1, &Local_u8Button2State);
     DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN2, &Local_u8Button3State);
	/* Wait for button press */
	while (DIO_u8PIN_HIGH==Local_u8Button1State && DIO_u8PIN_HIGH== Local_u8Button2State&& DIO_u8PIN_HIGH== Local_u8Button3State)
	{
		 DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN0, &Local_u8Button1State);
		 DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN1, &Local_u8Button2State);
		 DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN2, &Local_u8Button3State);
	}
	
	if (Local_u8Button1State ==DIO_u8PIN_LOW )
	{
		Local_u8Counter++;  
	}

	CLCD_voidClearLCD();
	CLCD_voidSendString("What microcontroller?");
	_delay_ms(2000);

	CLCD_voidClearLCD();
	CLCD_voidSendString("1-PIC\t 3-STM\t ");
	CLCD_voidGoToXY(1, 0);
	CLCD_voidSendString("2-ATMEGA32\t");
	
	
 DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN0, &Local_u8Button1State);
 DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN1, &Local_u8Button2State);
 DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN2, &Local_u8Button3State);
	 /* Wait for button press */
     while (DIO_u8PIN_HIGH==Local_u8Button1State && DIO_u8PIN_HIGH== Local_u8Button2State&& DIO_u8PIN_HIGH== Local_u8Button3State)	 {
		 DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN0, &Local_u8Button1State);
		 DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN1, &Local_u8Button2State);
		 DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN2, &Local_u8Button3State);
	 }
	 
	if ( Local_u8Button2State==DIO_u8PIN_LOW )
	{
		Local_u8Counter++;  
		
	}

	CLCD_voidClearLCD();
	CLCD_voidSendString("What layer?");
	_delay_ms(2000);

	CLCD_voidClearLCD();
	CLCD_voidSendString("1-APP\t 2-MCAL\t");
	CLCD_voidGoToXY(1, 0);
	CLCD_voidSendString("3-HAL");
    
	
	 DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN0, &Local_u8Button1State);
	 DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN1, &Local_u8Button2State);
	 DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN2, &Local_u8Button3State);
	 /* Wait for button press */
	 while (DIO_u8PIN_HIGH==Local_u8Button1State && DIO_u8PIN_HIGH== Local_u8Button2State&& DIO_u8PIN_HIGH== Local_u8Button3State)
	 {
		 DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN0, &Local_u8Button1State);
		 DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN1, &Local_u8Button2State);
		 DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN2, &Local_u8Button3State);
	 }
	 
	if (Local_u8Button3State  ==DIO_u8PIN_LOW )
	{
		Local_u8Counter++;  
		
	}

	/* final result */
	CLCD_voidClearLCD();
	CLCD_voidSendString("Your score is:");
	CLCD_voidGoToXY(1, 0);
	CLCD_voidWriteNumber(Local_u8Counter);

	while (1)
	{
		// Infinite loop
	}
}


  	/*CLCD_voidSendString("Shaaban");
		_delay_ms(1000); 
        CLCD_voidSendData('S');
	    CLCD_voidSendData('H');
	    CLCD_voidSendData('A');
	    CLCD_voidSendData('A');
   	    CLCD_voidSendData('B');
	    CLCD_voidSendData('A');
	    CLCD_voidSendData('A'); 
	    _delay_ms(1000); 
		CLCD_voidGoToXY(0,1);
		CLCD_voidSendString("shaaban");
		_delay_ms(500);
		CLCD_voidClearLCD();
		CLCD_voidGoToXY(0,4);
		CLCD_voidSendString("shaaban");
		_delay_ms(500);
		CLCD_voidClearLCD();
		CLCD_voidGoToXY(1,1);
		CLCD_voidSendString("shaaban");
		_delay_ms(500);
		CLCD_voidClearLCD();*/