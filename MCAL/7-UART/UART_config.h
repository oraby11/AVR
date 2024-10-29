/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: shaaban elsayed         ******************************/
/***************************     Layer:  MCAL                 ******************************/
/***************************     SWC:    UART                  ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/*
  select mode :
  SYNCHRONOUS :  set bit UMSEL  (bit 6)
  ASYNCHRONOUS : clear_bit UMSEL
*/

#define MODE_SELECT      SYNCHRONOUS

/*
UCSRC bit 5 , 4
Parity Mode :
1-Disable:            UPM1 :0     UPM0: 0
2-Reserved:           UPM1 :0     UPM0: 1
3-Enable,Even parity: UPM1 :0     UPM0: 0
4-Enable,Odd parity:  UPM1 :1     UPM0: 1

*/
#define  PARITY_MODE   DISABLE

/*
UCSRC bit 3 :stop bit 
one_bit: clear 0
two_bit:set 1
*/
#define  STOP_SELECT      ONE_BIT
/*
character size : 
5-bit ,6-bit,7-bit,8-bit,9-bit
*/
#define CHARACTER_SIZE   8-BIT 

/*Clock polarity : bit 0 (UCPOL)
TxD: Transmitted Data change  OUTPUT
RxD: Received Data Sampled    INPUT
*/
#define  CLOCK_POLARITY   OUTPUT

/*
UBRRL or UBRRH

baud rate UBRR 
F=1.0000MHZ,
F=2.0000MHZ,
F=4.0000MHZ,
F=8.0000MHZ,UBRR 51,BAUD_RATE  9600
F=16
*/
#define  FREQUENCY  8.0000MHZ
#define  UBRR_BAUD       51

#endif
