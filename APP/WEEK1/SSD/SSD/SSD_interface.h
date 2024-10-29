/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: shaaban elsayed         ******************************/
/***************************     Layer:  HAL                 ******************************/
/***************************     SWC:    SSD                  ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "STD_TYPES.h"
#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_COMMON_CATHODE  0
#define SSD_COMMON_ANODE    1

typedef struct{

	u8 Type       ;                 // SSD_COMMON_CATHODE or SSD_COMMON_ANODE
	u8 DataPort   ;                 // SSD_PORTA or SSD_PORTB or SSD_PORTC or SSD_PORTD
	u8 EnablePort ;                 // SSD_PORTA or SSD_PORTB or SSD_PORTC or SSD_PORTD
	u8 EnablePin  ;                 // SSD_PIN0 , SSD_PIN1 ,SSD_PIN2 , SSD_PIN3 , SSD_PIN4 , SSD_PIN5 , SSD_PIN6 , SSD_PIN7

}SSD_Type;

void SSD_voidInitialDataPort  ( SSD_Type Copy_u8Port );
void SSD_voidEnable           ( SSD_Type Copy_u8SSD );
void SSD_voidDisable          ( SSD_Type Copy_u8SDD );
void SSD_voidSendNumber       ( SSD_Type Copy_u8SDD , u8 Copy_u8Number );

#endif