/****************************************************************/
/****************************************************************/
/**********************  Author: shaaban elsayed ****************/
/**********************  Layer:MCAL              ****************/
/**********************  SWE:EXTI                ****************/
/**********************  Verison:1.00            ****************/
/**********************  Date:4/12/2023          ****************/
/****************************************************************/
/****************************************************************/


#include  "STD_TYPES.h"
#include  "BIT_MATHS.h"

#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/*Global pointer to function to hold INT0 ISR address */
void(*EXTI_pvInt0Func)(void)=NULL;
void(*EXTI_pvInt1Func)(void)=NULL;
void(*EXTI_pvInt2Func)(void)=NULL;


void EXTI_voidInt0Init(void){
	/*
	 //Set sense control for INT0 to falling edge
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);
	//periphreal interrupt enable fpr INT0
	SET_BIT(GICR,GICR_INT0);
	*/
	
	//check sense control  
   #if INT0_SENSE  ==  LOW_LEVEL;
      CLR_BIT(MCUCR,MCUCR_ISC00);
	  CLR_BIT(MCUCR,MCUCR_ISC01); 
	  
   #elif INT0_SENSE == ON_CHANGE;	
      SET_BIT(MCUCR,MCUCR_ISC00);
      CLR_BIT(MCUCR,MCUCR_ISC01);
	  
   #elif INT0_SENSE == FALLING_EDGE;
      CLR_BIT(MCUCR,MCUCR_ISC00);
      SET_BIT(MCUCR,MCUCR_ISC01);
	  
   #elif INT0_SENSE  == RISING_EDGE;
	  SET_BIT(MCUCR,MCUCR_ISC00);
	  SET_BIT(MCUCR,MCUCR_ISC01);
   #else 
      # error "wrong INT0_SENSE " 
  #endif 
  //check peripheral interrupt enable  
  #if INT0_INITIAL_STATE==ENABLED
      SET_BIT(GICR,GICR_INT0);
  #elif INT0_INITIAL_STATE==DISABLED
      CLR_BIT(GICR,GICR_INT0);
  #else 
  #error "wrong INT0_INITIAL_STATE"
  #endif
  
  	  
}


void EXTI_voidInt1Init(void){
		//check sense control
		#if INT1_SENSE  ==  LOW_LEVEL;
		CLR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		
		#elif INT1_SENSE == ON_CHANGE;
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		
		#elif INT1_SENSE == FALLING_EDGE;
		CLR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		
		#elif INT1_SENSE  == RISING_EDGE;
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		#else
		#error "wrong INT1_SENSE "
		#endif
		//check peripheral interrupt enable
		#if INT1_INITIAL_STATE==ENABLED
		SET_BIT(GICR,GICR_INT1);
		#elif INT1_INITIAL_STATE==DISABLED
		CLR_BIT(GICR,GICR_INT1);
		#else
		#error "wrong INT1_INITIAL_STATE"
		#endif
		
}
/*
void EXTI_voidInt2Init(void){	
}
*/

u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense){
	
	u8 Local_u8ErrorState=OK;
	switch (Copy_u8Sense){
	case  LOW_LEVEL:CLR_BIT(MCUCR,MCUCR_ISC01);CLR_BIT(MCUCR,MCUCR_ISC00);break;
    case  ON_CHANGE:SET_BIT(MCUCR,MCUCR_ISC00);CLR_BIT(MCUCR,MCUCR_ISC01);break;
    case  FALLING_EDGE:CLR_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01);break ;
 	case  RISING_EDGE:SET_BIT(MCUCR,MCUCR_ISC00);SET_BIT(MCUCR,MCUCR_ISC01);break;	
   	default:Local_u8ErrorState=NOK;	   
	}
	return Local_u8ErrorState;
}
u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense){
	
	u8 Local_u8ErrorState=OK;
	switch (Copy_u8Sense){
		case  LOW_LEVEL:CLR_BIT(MCUCR,MCUCR_ISC10);CLR_BIT(MCUCR,MCUCR_ISC11);break;
		case  ON_CHANGE:SET_BIT(MCUCR,MCUCR_ISC10);CLR_BIT(MCUCR,MCUCR_ISC11);break;
		case  FALLING_EDGE:CLR_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11);break ;
		case  RISING_EDGE:SET_BIT(MCUCR,MCUCR_ISC10);SET_BIT(MCUCR,MCUCR_ISC11);break;
		default:Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense){
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Sense){
		case FALLING_EDGE:CLR_BIT(MCUCSR,MCUCSR_ISC2);break;
		case RISING_EDGE: SET_BIT(MCUCSR,MCUCSR_ISC2);break;
		default:Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
 
 u8 EXTI_u8IntDisable(u8 Copy_u8Int){
	 u8 Local_u8ErrorState=OK;
	 switch(Copy_u8Int){
		 case INT0:CLR_BIT(GICR,GICR_INT0);break;
		 case INT1:CLR_BIT(GICR,GICR_INT1);break;
		 case  INT2:CLR_BIT(GICR,GICR_INT2);break;
		 default:Local_u8ErrorState=NOK;
	 }
	 return Local_u8ErrorState;
	 
 }
 
 u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void)){
	 
	 u8 Local_u8ErrorState=OK;
	 if (Copy_pvInt0Func !=NULL )
	 {
		  EXTI_pvInt0Func= Copy_pvInt0Func;
	 }
	 else
	 {
		 Local_u8ErrorState=NULL_POINTER;
	 }
	 
 }
 
 /*ISR of INT0 */
 void __vector__1(void)  __attribute__((signal));
 void __vector__1(void){
	  if (EXTI_pvInt0Func !=NULL )
	  {
	     EXTI_pvInt0Func; 
	  }
	  else 
	  {
		  /*no thing*/
	  }
 }