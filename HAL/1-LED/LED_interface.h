/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: shaaban elsayed         ******************************/
/***************************     Layer:  HAL                 ******************************/
/***************************     SWC:    LED                  ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define ACTIVE_HIGH   1
#define ACTIVE_LOW    0

typedef struct 
{
  u8 PORT;
  u8 PIN;
  u8 ACTIVE_State;
  
}LED_TYPE


void LED_voidInit(LED_TYPE LED_Configuration);

void LED_voidOn(LED_TYPE LED_Configuration);

void LED_voidOff(LED_TYPE LED_Configuration);

void LED_voidToggle(LED_TYPE LED_Configuration);




#endif