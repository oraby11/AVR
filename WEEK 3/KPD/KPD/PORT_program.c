/**********************************************************/
/**********************************************************/
/*************   Author:  shaaban elsayed  ****************/
/*************   Layer:   MCAL            ****************/
/*************   SWC:     PORT             *****************/
/*************   Version   1.00           ******************/
/**********************************************************/
/**********************************************************/




#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_interface.h"
#include "PORT_register.h"


void PORT_voidInit(void)
{
DDRA=PORTA_DIR;
DDRB=PORTB_DIR;
DDRC=PORTC_DIR;
DDRD=PORTD_DIR;

DDRA=PORTA_INITAL_VALUE;
DDRB=PORTB_INITAL_VALUE;
DDRC=PORTC_INITAL_VALUE;
DDRD=PORTD_INITAL_VALUE;





}