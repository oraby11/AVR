/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: shaaban elsayed         ******************************/
/***************************     Layer:  HAL                 ******************************/
/***************************     SWC:    SSD                 ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

static u8 Local_u8SSDNumber[10]=SevenSegArr;
/*Set port as output */
void SSD_voidInitialDataPort  ( SSD_Type Copy_u8Port )
{
	DIO_u8SetPortDirection(Copy_u8Port.DataPort,DIO_u8PORT_OUTPUT);
	
}

void SSD_voidEnable    ( SSD_Type Copy_u8SSD ){

	if( Copy_u8SSD.Type == SSD_COMMON_CATHODE ){

		DIO_u8SetPinDirection( Copy_u8SSD.EnablePort , Copy_u8SSD.EnablePin , DIO_u8PIN_OUTPUT );
		DIO_u8SetPinValue( Copy_u8SSD.EnablePort , Copy_u8SSD.EnablePin , DIO_u8PIN_LOW );

		}else if( Copy_u8SSD.Type == SSD_COMMON_ANODE ){

		DIO_u8SetPinDirection( Copy_u8SSD.EnablePort , Copy_u8SSD.EnablePin , DIO_u8PIN_OUTPUT );
		DIO_u8SetPinValue( Copy_u8SSD.EnablePort , Copy_u8SSD.EnablePin , DIO_u8PIN_HIGH );

	}

}
void SSD_voidDisable          ( SSD_Type Copy_u8SDD )
{
	
	if( Copy_u8SDD.Type == SSD_COMMON_CATHODE ){

		DIO_u8SetPinDirection( Copy_u8SDD.EnablePort , Copy_u8SDD.EnablePin , DIO_u8PIN_OUTPUT );
		DIO_u8SetPinValue( Copy_u8SDD.EnablePort , Copy_u8SDD.EnablePin , DIO_u8PIN_HIGH );

	}
	else if( Copy_u8SDD.Type == SSD_COMMON_ANODE ){

		DIO_u8SetPinDirection( Copy_u8SDD.EnablePort , Copy_u8SDD.EnablePin , DIO_u8PIN_OUTPUT );
		DIO_u8SetPinValue( Copy_u8SDD.EnablePort , Copy_u8SDD.EnablePin , DIO_u8PIN_LOW );

	}
}
void SSD_voidSendNumber       ( SSD_Type Copy_u8SDD , u8 Copy_u8Number )
{
	if( Copy_u8SDD.Type == SSD_COMMON_CATHODE ){

		DIO_u8SetPortValue( Copy_u8SDD.DataPort , Local_u8SSDNumber[ Copy_u8Number ] );

		}else if( Copy_u8SDD.Type == SSD_COMMON_ANODE ){

		DIO_u8SetPortValue( Copy_u8SDD.DataPort , ~( Local_u8SSDNumber[ Copy_u8Number ] ) );

	}
	
}


