/*******************************************************************************************/
/*******************************************************************************************/
/***************************     Author: shaaban elsayed         ******************************/
/***************************     Layer: RTOS Stack                 ******************************/
/***************************     SWC:    RTOS                  ******************************/
/***************************     Version:1.00                 ******************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "BIT_MATHS.h"
#include "STD_TYPES.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_config.h"

Task_t SystemTasks[TASK_NUM]={{NULL}};

void RTOS_voidStart(void)
{
	//Timer0_u8CompMatchSetCallBack(&voidScheduler)
   //Enable GIE
   //Timer0Init();
}

u8  RTOS_voidCreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity,void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay)
{
	u8 Local_u8ErrorState=OK;
	//check if the required priority is empty or used before for another task 
	if (SystemTasks[Copy_u8Priority].TaskFunc==NULL)
	{
			SystemTasks[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
			SystemTasks[Copy_u8Priority].TaskFunc=Copy_pvTaskFunc;		
			SystemTasks[Copy_u8Priority].State=TASK_RESUMED;  //init task state	
	        SystemTasks[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;
	} 
	else 
	{
		Local_u8ErrorState=NOK;
	}
    return Local_u8ErrorState;
}
static void voidScheduler(void)
{
	static u16 Local_u8TicKCounter=0;
	u8 Local_u8TasKCounter;
	Local_u8TicKCounter++;
	/*loop on all tasks to check periodicitiy*/
	for(Local_u8TasKCounter=0 ; Local_u8TasKCounter<TASK_NUM;Local_u8TasKCounter++)
	{
		//check task suspended or resume
		if(SystemTasks[Local_u8TasKCounter].State==TASK_RESUMED)
		{
			
			if(SystemTasks[Local_u8TasKCounter].FirstDelay==0)
			{
				/*invoke the task function*/
				if(SystemTasks[Local_u8TasKCounter].TaskFunc !=NULL)
				{
					SystemTasks[Local_u8TasKCounter].TaskFunc();
					//Assign first delay parameter to periodicity - 1
					SystemTasks[Local_u8TasKCounter].FirstDelay=SystemTasks[Local_u8TasKCounter].Periodicity-1;
				}
				else
				{
					//Decremant first delay
					SystemTasks[Local_u8TasKCounter].FirstDelay--;
				}
		    }
		
		}
		else 
		{
			//task is suspended ,do nothing
		}
	}	
}
void RTOS_voidSuspendTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].State=TASK_SUSPENDED;
}

void RTOS_voidResumeTask(u8 Copy_u8Priority )
{
	SystemTasks[Copy_u8Priority].State=TASK_RESUMED;	
}

void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].TaskFunc=NULL;
}