/**********************************************************/
/**********************************************************/
/*************   Author:  shaaban elsayed  ****************/
/*************   Layer:   HAL             ****************/
/*************   SWC:     CLCD             *****************/
/*************   Version   1.00           ******************/
/**********************************************************/
/**********************************************************/


/* preprocessor file guard*/
#ifndef   CLCD_CONFIG_H_
#define   CLCD_CONFIG_H_

/*
Select mode 4 bit or 8 bit
*/

#define   MODE    8 

#define   CLCD_DATA_PORT    DIO_u8PORTB
#define   CLCD_CTRL_PORT    DIO_u8PORTA
#define   CLCD_RS_PIN       DIO_u8PIN5
#define   CLCD_RW_PIN       DIO_u8PIN6
#define   CLCD_E_PIN        DIO_u8PIN7    



#endif