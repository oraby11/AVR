/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: shaaban elsayed         ******************************/
/***************************     Layer:  MCAL                 ******************************/
/***************************     SWC:    UART                  ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "UART_interface.h"
#include "UART_register.h"
#include "UART_config.h"


u8 *USART_u8CharDataAdress=0;
u8 *USART_u8CharData=0;

static void(*USART_PvReciveFunc)(void);
static void(*USART_PvSendFunc)(void);

void USART_voidInit(void)
{
	
	//To write values on UCSRC
	u8 Local_u8UCSRCValue=0; 
	#if CHARACTER_SIZE ==  8-BIT  
	SET_BIT(Local_u8UCSRCValue,7);     //use UCSRC
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);     //set to 8 bit
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);    //set to 8 bit
	UCSRC=Local_u8UCSRCValue;
	#endif
	//mode select 
	#if MODE_SELECT==ASYCHRONOUS
	   SET_BIT(UCSRC,UCSRC_UMSEL);
	#elif  MODE_SELECT==SYCHRONOUS
	   CLR_BIT(UCSRC,UCSRC_UMSEL);
    #endif
	//Parity Mode 
	#if PARITY_MODE ==  DISABLE
	CLR_BIT(UCSRC,UCSRC_UPM0);
	CLR_BIT(UCSRC,UCSRC_UPM1);
	#endif
	//Stop bits
	#if STOP_SELECT == ONE_BIT
	CLR_BIT(UCSRC,UCSRC_USBS);
	#endif
	//Clock Polarity
	#if CLOCK_POLARITY == OUTPUT
	CLR_BIT(UCSRC,UCSRC_UCPOL);
	#endif
	
	UBRRL=UBRR_BAUD;   //baud rate 9600 bit/sec
	
	SET_BIT(UCSRB,UCSRB_RXEN);     //Re enable
	SET_BIT(UCSRB,UCSRB_TXEN);     //TX enable
	
}

void USART_u8SendSynch(u8 Copy_u8Data)
{
	while(GET_BIT(UCSRA,UCSRA_UDRA)==0);  //polling wait until transmit (flag)data is empty
	UDR=Copy_u8Data;
	
}

u8  USART_u8ReceiveSynch(void)
{
	while(GET_BIT(UCSRA,UCSRA_RXC)==0); //wait to receive complete
	return UDR;
	
}
/*
void USART_u8SendCharAsych(u8 Copy_u8Char,void (*NotificationFunc)(void) )
{
	
	
	USART_PvSendFunc=Copy_u8Char;
    SET_BIT(UCSRB,UCSRB_UDRIE);
}*/
void USART_voidSendAsync(u8 Copy_u8Data,void (*Copy_pvNotificationFunc)(void))
{
	USART_u8CharData=Copy_u8Data;
	USART_PvSendFunc=Copy_pvNotificationFunc;
	SET_BIT(UCSRB,UCSRB_UDRIE);	
}
void USART_voidReceiveAsync(u8 *Copy_u8Data,void (*Copy_pvNotification)(void))
{
	USART_u8CharDataAdress=Copy_u8Data;
	USART_PvReciveFunc=Copy_pvNotification;
	SET_BIT(UCSRB,UCSRB_RXCIE);
}
	
void  USART_u8SendStringSych(char *Copy_u8String )
{
	u8 Local_u8Iterator=0;
	while(Copy_u8String[Local_u8Iterator] !='\0')
		{
			USART_u8SendSynch(Copy_u8String[Local_u8Iterator]);
			Local_u8Iterator++;
		}
}

u8 USART_u8ReceiveStringAsync(u8 *Copy_u8String, void (*NotifReceiveFuncString)(void))
{
	u8 *Local_u8String=NULL;
	     USART_PvReciveFunc= NotifReceiveFuncString;
	if(GET_BIT(UCSRA,UCSRA_RXC)==1)
	{
		while(&Copy_u8String!='\0')
		{
			*Local_u8String=&Copy_u8String;
		}
		
	}
	//Enable Interrupt
	SET_BIT(UCSRA,UCSRA_RXC);
	return &Local_u8String;
}
  //ISR
  void __vector__13(void)  __attribute__((signal));
  void __vector__13(void){
	  *USART_u8CharDataAdress=UDR;
	  USART_PvReciveFunc();
  }
  
 void __vector__14(void)  __attribute__((signal));
 void __vector__14(void){
	UDR=USART_u8CharData;
	USART_PvSendFunc();
	CLR_BIT(UCSRB,UCSRB_UDRIE);
 }
 
 

 