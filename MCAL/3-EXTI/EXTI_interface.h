
/****************************************************************/
/****************************************************************/
/**********************  Author: shaaban elsayed ****************/
/**********************  Layer:MCAL              ****************/
/**********************  SWE:EXTI                ****************/
/**********************  Verison:1.00            ****************/
/**********************  Date:4/12/2023          ****************/
/****************************************************************/
/****************************************************************/


#ifndef    EXTI_INTERFACE_H_
#define    EXTI_INTERFACE_H_

#define   LOW_LEVEL    1
#define   ON_CHANGE    2
#define   FALLING_EDGE 3
#define   RISING_EDGE  4


#define  INT0      1
#define  INT1      2
#define  INT2      3


// prebuild 
void EXTI_voidInt0Init(void);

void EXTI_voidInt1Init(void);

void EXTI_voidInt2Init(void);
/*description :A function to set the reuied sense control of INT0 using postbuild configuration
input : copy_u8Sense , options are  
   LOW_LEVEL    
   ON_CHANGE    
   FALLING_EDGE 
   RISING_EDGE  
 */
//post build because configuration change during runtime
u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense);

u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense);

u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense);

u8 EXTI_u8IntEnable(u8 Copy_u8Int);

u8 EXTI_u8IntDisable(u8 Copy_u8Int);
 
u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void));  

u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt0Func)(void));

u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt0Func)(void));

 

#endif