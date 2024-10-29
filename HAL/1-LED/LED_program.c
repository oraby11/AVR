/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: shaaban elsayed         ******************************/
/***************************     Layer:  HAL                 ******************************/
/***************************     SWC:    LED                  ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "STD_TYPES"
#include "DIO_interface"
#include "LED_interface"


void LED_voidInit(LED_TYPE LED_Configuration)
{
	
		DIO_u8SetPinDirection( LED_.ConfigurationPORT,LED_Configuration.PIN, DIO_u8PIN_OUTPUT);
}

void LED_voidOn(LED_TYPE LED_Configuration)
{
	
	if (LED_Configuration.ACTIVE_State ==ACTIVE_HIGH )
	{
		DIO_u8SetPinValue( LED_Configuration.PORT,LED_Configuration.PIN, DIO_u8PIN_HIGH);
		
	}
	else if (LED_Configuration.ACTIVE_State ==ACTIVE_LOW )
	{
		DIO_u8SetPinValue( LED_Configuration.PORT,LED_Configuration.PIN, DIO_u8PIN_LOW);
		
	}
	
	
}

void LED_voidOff(LED_TYPE LED_Configuration)
{
	
	if (LED_Configuration.ACTIVE_State ==ACTIVE_HIGH )
	{
		DIO_u8SetPinValue( LED_Configuration.PORT,LED_Configuration.PIN, DIO_u8PIN_LOW);
		
	}
	else if (LED_Configuration.ACTIVE_State ==ACTIVE_LOW )
	{
		DIO_u8SetPinValue( LED_Configuration.PORT,LED_Configuration.PIN, DIO_u8PIN_LOW);
		
	}	
	
}

void LED_voidToggle(LED_TYPE LED_Configuration)
{
	
	
	
	if (LED_Configuration.ACTIVE_State ==ACTIVE_HIGH )
	{
		DIO_u8SetPinValue( LED_Configuration.PORT,LED_Configuration.PIN, DIO_u8PIN_LOW);
		
	}
	else if (LED_Configuration.ACTIVE_State ==ACTIVE_LOW )
	{
		DIO_u8SetPinValue( LED_Configuration.PORT,LED_Configuration.PIN, DIO_u8PIN_HIGH);
		
	}
}

