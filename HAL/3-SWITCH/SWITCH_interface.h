/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: shaaban elsayed         ******************************/
/***************************     Layer:  HAL                 ******************************/
/***************************     SWC:    SWITCH                  ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


#define SWITCH_PRESSED        1
#define SWITCH_NOT_PRESSED    0

/*options of State :
1-SW_Int_PULL_UP
2-SW_Ext_PULL_UP
3-SW_Ext_PULL_DOWN
4-SW_FLOATING
*/

#define SW_Int_PULL_UP     0
#define SW_Ext_PULL_UP     1
#define SW_Ext_PULL_DOWN   2
#define SW_FLOATING        3


typedef struct  
{
	u8 PORT;
	u8 PIN 
	u8 PULL_State;
}TYPE_SWITCH;


void SWITCH_voidInit(TYPE_SWITCH  SWITCH_Configuration);

u8  SWITCH_voidGetValue(TYPE_SWITCH  SWITCH_Configuration);

#endif