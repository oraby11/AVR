/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: shaaban elsayed         ******************************/
/***************************     Layer:  MCAL                 ******************************/
/***************************     SWC:    UART                  ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_


#define  UDR    *((volatile u8* ) 0x2C)              //USART Transmit Data Buffer Register and USART Receive Data Buffer Registers

#define  UCSRA    *((volatile u8* ) 0x2B)
#define  UCSRA_RXC    7                 
#define  UCSRA_TXC    6
#define  UCSRA_UDRA   5           //flag to transmit data UDRA is set after reset to indicate transmitter is ready
#define  UCSRA_FE     4
#define  UCSRA_DOR    3
#define  UCSRA_PE     2
#define  UCSRA_U2X    1
#define  UCSRA_MPCM   0

#define  UCSRB    *((volatile u8* ) 0x2A)
#define  UCSRB_RXCIE    7
#define  UCSRB_TXCIE    6
#define  UCSRB_UDRIE    5        //Data register empty interrupt enable
#define  UCSRB_RXEN     4          //Recieving enable  
#define  UCSRB_TXEN     3          //Transimt enable 
#define  UCSRB_UCSZ2    2        
#define  UCSRB_RXB8     1
#define  UCSRB_TXB8     0

#define  UCSRC   *((volatile u8* ) 0x40)
#define  UCSRC_URSEL   7
#define  UCSRC_UMSEL   6        //Selcet synchronous or Asynchronous
#define  UCSRC_UPM1    5       //enable parity mode 
#define  UCSRC_UPM0    4       //enable parity mode 
#define  UCSRC_USBS    3       // Stop bits  
#define  UCSRC_UCSZ1   2       //character size
#define  UCSRC_UCSZ0   1       //character size 
#define  UCSRC_UCPOL   0       //Clock polarity for synchronous 

#define  UBRRH    *((volatile u8* ) 0x29)
#define  UBRRH_UBRRH7    7
#define  UBRRH_UBRRH3    3
#define  UBRRH_UBRRH2    2
#define  UBRRH_UBRRH1    1
#define  UBRRH_UBRRH0    0


#define  UBRRL    *((volatile u8* ) 0x29)     //Baud rate 
#define  UBRRL_UBRRL7   7
#define  UBRRL_UBRRL6   6
#define  UBRRL_UBRRL5   5
#define  UBRRL_UBRRL4   4
#define  UBRRL_UBRRL3   3
#define  UBRRL_UBRRL2   2
#define  UBRRL_UBRRL1   1
#define  UBRRL_UBRRL0   0


#endif