#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "KEYPAD_interface.h"
#include "PORT_config.h"

u8 Calculator(u8 Local_u8KEYPressedNumber1,u8 Local_u8KEYPressedNumber2,u8 Local_u8KEYOperation);

void main(void)
{
	PORT_voidInit();
	// PINS OF LCD
	DIO_u8SetPortDirection(DIO_u8PORTB, DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN5, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN6, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN7, DIO_u8PIN_OUTPUT);
	// PORT KEYPAD
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN3, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN4, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN5, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN6, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN7, DIO_u8PIN_INPUT);
	DIO_u8SetPortValue(DIO_u8PORTD, DIO_u8PORT_HIGH);
	
	u8 Local_u8KEY;
	u8 Local_u8KEYPressedNumber1 = 0;
	u8 Local_u8KEYPressedNumber2 = 0;
	u8 Local_u8KEYOperation;
	u8 flag = 0;
	CLCD_voidInit();
	//Initialize LCD
	_delay_ms(200); 
    CLCD_voidSendString("Calculator");
	_delay_ms(2000);
	CLCD_voidClearLCD();
	CLCD_voidSendString("Start");
	_delay_ms(2000);
	CLCD_voidClearLCD();
	while (1)
	{
		Local_u8KEY = KPD_u8GetPressedKEY();
		if(Local_u8KEY >= '0' && Local_u8KEY <= '9' && flag == 0)
		{
			CLCD_voidSendData(Local_u8KEY);  
			Local_u8KEYPressedNumber1 = Local_u8KEY - '0';  
			flag = 1; //flag to can add number 2
		}
		else if(Local_u8KEY >= '0' && Local_u8KEY <= '9' && flag == 1)
		{
			CLCD_voidSendData(Local_u8KEY); 
			Local_u8KEYPressedNumber2 = Local_u8KEY - '0';  		
		}
		else if (Local_u8KEY == '+' || Local_u8KEY == '-' || Local_u8KEY == '*' || Local_u8KEY == '/')
		{
			CLCD_voidSendData(Local_u8KEY);  
			
			Local_u8KEYOperation = Local_u8KEY;
		}
		else if (Local_u8KEY == '=')
		{
			CLCD_voidSendString("=");
			Calculator(Local_u8KEYPressedNumber1, Local_u8KEYPressedNumber2, Local_u8KEYOperation);
		}
		else if (Local_u8KEY == '?')
		{
			CLCD_voidClearLCD();
			flag = 0;  
		}
	}
}

u8 Calculator(u8 Local_u8KEYPressedNumber1, u8 Local_u8KEYPressedNumber2, u8 Local_u8KEYOperation)
{
	switch(Local_u8KEYOperation)
	{
		case '-':
		CLCD_voidWriteNumber(Local_u8KEYPressedNumber1 - Local_u8KEYPressedNumber2);
		break;
		case '*':
		CLCD_voidWriteNumber(Local_u8KEYPressedNumber1 * Local_u8KEYPressedNumber2);
		break;
		case '/':
		if (Local_u8KEYPressedNumber2 != 0)
		{
			CLCD_voidWriteNumber(Local_u8KEYPressedNumber1 / Local_u8KEYPressedNumber2);
		}
		else
		{
			CLCD_voidSendString("Err");
		}
		break;
		case '+':
		CLCD_voidWriteNumber(Local_u8KEYPressedNumber1 + Local_u8KEYPressedNumber2);
		break;
		default:
		CLCD_voidSendString("Invalid");
		break;
	}
}
