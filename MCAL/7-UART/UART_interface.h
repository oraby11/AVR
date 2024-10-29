/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: shaaban elsayed         ******************************/
/***************************     Layer:  MCAL                 ******************************/
/***************************     SWC:    UART                  ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void USART_voidInit(void);

void USART_u8SendSych(u8 Copy_u8Data);
u8 USART_u8ReceiveSych(void );

void USART_voidSendAsync(u8 Copy_u8Data,void (*Copy_pvNotificationFunc)(void));
void USART_u8SendCharAsych(u8 Copy_u8Char,void (*NotificationFunc)(void) );
void USART_voidReceiveAsync(u8 *Copy_u8Data,void (*Copy_pvNotification)(void));

void  USART_u8SendStringSych(char *Copy_u8String );
u8 USART_u8ReceiveStringAsync(u8 *Copy_u8String, void (*NotifReceiveFuncString)(void));





#endif