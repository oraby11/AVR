
/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: shaaban elsayed         ******************************/
/***************************     Layer:  HAL                 ******************************/
/***************************     SWC:    SWITCH                  ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/




#include"STD_TYPES"
#include "DIO_interface.h"
#include "SWITCH_interface"




void SWITCH_voidInit()
{
	 DIO_u8SetPinDirection(SWITCH_Configuration.PORT,SWITCH_Configuration.PIN ,DIO_u8PIN_INPUT );
	 
	 /*If SW is Internal pull up */
	 if (SWITCH_Configuration.PULL_State== SW_Int_PULL_UP)
	 {
		 DIO_u8SetPinValue(SWITCH_Configuration.PORT,SWITCH_Configuration.PIN,DIO_u8PIN_HIGH);
	 }
	
}

u8  SWITCH_voidGetValue(SWITCH_Configuration)
{
    u8 LOC_u8Result = SW_NOT_PRESSED ;
	u8 LOC_u8PinVal = SW_NOT_PRESSED ;
	
	if ( (SW_Config.Pull_State == SW_Int_PULL_UP) || (SW_Config.Pull_State == SW_Ext_PULL_UP) )
	{
		DIO_u8GetPinValue( SW_Config.Port , SW_Config.Pin , &LOC_u8PinVal );
		
		if (LOC_u8PinVal==0)
		{
			LOC_u8Result = SW_PRESSED ;
		}
		else if (LOC_u8PinVal==1)
		{
			LOC_u8Result = SW_NOT_PRESSED ;
		}

	}
	else if (SW_Config.Pull_State == SW_Ext_PULL_DOWN)
	{
		DIO_enumGetPinValue( SW_Config.Port , SW_Config.Pin , &LOC_u8PinVal );
		
		if (LOC_u8PinVal==0)
		{
			LOC_u8Result = SW_NOT_PRESSED ;
		}
		else if (LOC_u8PinVal==1)
		{
			LOC_u8Result = SW_PRESSED ;
		}
	}
		
	return LOC_u8Result ;
	
}