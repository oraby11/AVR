/**********************************************************/
/**********************************************************/
/*************   Author:  shaaban elsayed  ****************/
/*************   Layer:   HAL             ****************/
/*************   SWC:     CLCD             *****************/
/*************   Version   1.00           ******************/
/**********************************************************/
/**********************************************************/

#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

void CLCD_voidSendCommand(u8 Copy_u8Command){
	
	
	    /*set  RS pin to low for command */
	    DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	    /*set RW pin to low for write*/ 
		DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
		/*set command to data pins */
		DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);
		/*set enable pulse*/
		DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
		
}
void  CLCD_voidSendData(u8 Copy_u8Data){
	
	   /*set  RS pin to high for data */
	   DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	   /*set RS pin to low for write*/
	   DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	   /*set data to data pins */
	   DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);
	   /*set enable pulse*/
	   DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	   _delay_ms(2);
	   DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

}
void CLCD_voidInit(){
 // #if MODE==8_BITS
	/*Wait  30ms*/
	_delay_ms(40);
	/*function set command 2lines:5*8 font size */		
	CLCD_voidSendCommand(0b00111000);
	//_delay_ms(1);
	/*Display on off  control:display enable ,disable cursor , no blink cursor */
	CLCD_voidSendCommand(0b00001100);
	//_delay_ms(1); 
	/*clear display */
	CLCD_voidSendCommand(0b00000001); 
	//_delay_ms(1);
	//CLCD_voidSendCommand(0x06);//0b00000100
	//#elif MODE==4_BITS
}
void CLCD_voidSendString(const char* Copy_pcString){
	u8	Local_u8Counter =0;
		while(Copy_pcString[Local_u8Counter]!='\0'){
			CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
			Local_u8Counter++;	
		}
}

void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos){
		u8 Local_u8Address=0;
		if(Copy_u8XPos==0){
			Local_u8Address=Copy_u8YPos;
		}
		else if (Copy_u8XPos==1){
			Local_u8Address=Copy_u8YPos+0x40;
			
		}
		/*set bit number 7 for set DDRAM address command then the command */
		CLCD_voidSendCommand(Local_u8Address+128);
	}
	void CLCD_voidWriteSpeicalCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos){
		u8 Local_u8CGRAMAddress=0,Local_u8Iterator;
		/*calculate the CGRAM address whose each block is 8 bytes*/
		 Local_u8CGRAMAddress=Copy_u8PatternNumber*8;
		 /* send CGRAM address command to LCD with setting bit 6 ,clearing bit 7 */
		 CLCD_voidSendCommand(Local_u8CGRAMAddress+64);
		 /*write the pattern into CG Ram  */
		 for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++){
			 CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
		 }
		 /*go back DDRAM to display the pattern  */
		 CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);
		 /*display the pattern written in the CGRAM*/
		 CLCD_voidSendData(Copy_u8PatternNumber);
		
	}
		void CLCD_voidWriteNumber(u32 Copy_u32Number){
		/*u8 Local_CopyBit[16];//16 is the limit of visable in LCD 
		u8 Local_u8SizeDigit=0;
		Local_u8SizeDigit=(Copy_u32Number/10) +1 ;
		
	   for(u32 i=Local_u8SizeDigit-1;Local_u8SizeDigit;i--)
	   {
		Local_CopyBit[i]= Copy_u32Number%10;
		}
		for(u32 i=0;i<Local_u8SizeDigit;i++)
		{
			CLCD_voidSendData(Local_CopyBit[i]);
		}*/
		u32 LOC_u32Reversed = 1 ;

		if( Copy_u32Number == 0 ){ CLCD_voidSendData('0'); }

		else{
			
			while( Copy_u32Number != 0 ){

				LOC_u32Reversed = ( LOC_u32Reversed * 10 ) + ( Copy_u32Number % 10 );
				Copy_u32Number /= 10 ;
			}
			while( LOC_u32Reversed != 1 ){

				CLCD_voidSendData( ( LOC_u32Reversed % 10 ) + 48 );
				LOC_u32Reversed /= 10 ;

			}

		}
	}     
	
		
		void CLCD_voidClearLCD(void){	
		CLCD_voidSendCommand(0b00000001);
			
		}
	

		
	
	
	