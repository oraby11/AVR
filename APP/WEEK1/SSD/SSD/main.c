/*
 * SSD.c
 *
 * Created: 28/09/2024 10:55:10 م
 * Author : ExTrA
 */ 
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include <util/delay.h>


int main(void)
{
 SSD_Type _7Segment;
 _7Segment.DataPort=DIO_u8PORTA;
 _7Segment.EnablePort=DIO_u8PORTA;
 _7Segment.Type=SSD_COMMON_CATHODE;
  SSD_Type _7Segment2;
  _7Segment.DataPort=DIO_u8PORTB;
  _7Segment.EnablePort=DIO_u8PORTB;
  _7Segment.Type=SSD_COMMON_CATHODE;
  SSD_voidInitialDataPort(_7Segment);
  SSD_voidEnable(_7Segment);
  SSD_voidInitialDataPort(_7Segment2);
  SSD_voidEnable(_7Segment2);
    while (1) 
    {
		
		u8 Local_u8Counter=0;
		u8 Local_u8Counter2=0;
		for(Local_u8Counter=0;Local_u8Counter<10;Local_u8Counter++)
		{
			for(Local_u8Counter2=0;Local_u8Counter2<10;Local_u8Counter2++)
			{
			 SSD_voidSendNumber(_7Segment,Local_u8Counter);
			 SSD_voidSendNumber(_7Segment2,Local_u8Counter2);
			 _delay_ms(3000);
			}
		}
		
		
		 
    }
}

