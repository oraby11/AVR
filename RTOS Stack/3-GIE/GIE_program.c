/****************************************************************/
/****************************************************************/
/**********************  Author: shaaban elsayed ****************/
/**********************  Layer:MCAL              ****************/
/**********************  SWE:GIE          ****************/
/**********************  Verison:1.00            ****************/
/**********************  Date:4/12/2023          ****************/
/****************************************************************/
/****************************************************************/


#include  "STD_TYPES.h"
#include  "BIT_MATHS.h"

#include  "GIE_register.h"
#include  "GIE_interface.h"



void GIE_voidEnable(void){
	
	SET_BIT(SREG,SREG_I);
	
	
}

void GIE_voidDisable(void ){
	
	CLR_BIT(SREG,SREG_I);
	
}