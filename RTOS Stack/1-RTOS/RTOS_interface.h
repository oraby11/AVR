/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: shaaban elsayed         ******************************/
/***************************     Layer: RTOS Stack                 ******************************/
/***************************     SWC:    RTOS                  ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

void RTOS_voidStart(void);

u8  RTOS_voidCreateTask(u8 Copy_u8Priority,u16 Copy_u8Periodicity,void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay);

void RTOS_voidSuspendTask(u8 Copy_u8Priority);
void RTOS_voidResumeTask(u8 Copy_u8Priority );
void RTOS_voidDeleteTask(u8 Copy_u8Priority);
#endif