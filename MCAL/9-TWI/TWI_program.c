
#include "BIT_MATHS.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "TWI_config.h"
#include "TWI_interface.h"
#include "TWI_register.h"
#include "TWI_private.h"


void TWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
	/*set clock freq to 400kbps*/
	//Set TWBR =0
	TWDR=2;
	//Clear bits of TWPs
	CLR_BIT(TWSR,TWSR_TWPSO);
	CLR_BIT(TWSR,TWSR_TWPS1);
	
	//Init node address
	if(Copy_u8SlaveAddress !=0)
	{
		//Bit 0 not intersted
		TWAR=Copy_u8SlaveAddress<<1;
	}
	
	//Enable TWI
	SET_BIT(TWCR,TWCR_TWEN);
	
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	//init address
	TWAR=Copy_u8SlaveAddress<<1;
	//enable TWI
    SET_BIT(TWCR,TWCR_TWEN);
}

TWI_ErrorStatus TWI_SendStart(void)
{
	TWI_ErrorStatus Local_ErrorStatus=NoERRor;
	
	/*Send start condition on bus*/
	SET_BIT(TWCR,TWCR_TWSTA);
	
	/*Clear flag to start previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	
	/*wait until interrupt raised again*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	
	if ((TWSR & 0xf8) != START_ACK)
	{
		Local_ErrorStatus=StartConditionError;
	}
	else 
	{
		
	}
	
	return Local_ErrorStatus;
}

TWI_ErrorStatus TWI_SendRepeatedStart(void)
{
		TWI_ErrorStatus Local_ErrorStatus=NoERRor;
		
		/*Send start condition on bus*/
		SET_BIT(TWCR,TWCR_TWSTA);
		
		/*Clear flag to start previous operation */
		SET_BIT(TWCR,TWCR_TWINT);
		
		/*wait until interrupt raised again*/
		while(GET_BIT(TWCR,TWCR_TWINT)==0);
		
		if ((TWSR & 0xf8) != REP_START_ACK )
		{
			Local_ErrorStatus=RepeatedStartError;
		}
		else
		{
			
		}
		
		return Local_ErrorStatus;
}

TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus  Local_ErrorStatus=NoERRor;
	//Clear start 
	CLR_BIT(TWCR,TWCR_TWSTA);
	
	//Set slave address in 7 MSB in data register
	TWDR=Copy_u8SlaveAddress<<1;
	CLR_BIT(TWDR,0);    
	
		/*Clear flag to start previous operation */
		SET_BIT(TWCR,TWCR_TWINT);
		
		/*wait until interrupt raised again*/
		while(GET_BIT(TWCR,TWCR_TWINT)==0);
		
		if ((TWSR & 0xf8) != SLAVE_ADD_AND_WR_ACK )
		{
			Local_ErrorStatus=SlaveAddressWithReadError;
		}
		else
		{
			
		}
	return Local_ErrorStatus;
}

TWI_ErrorStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	
	TWI_ErrorStatus  Local_ErrorStatus=NoERRor;
	//Clear start
	CLR_BIT(TWCR,TWCR_TWSTA);
		//Set slave address in 7 MSB in data register
		TWDR=Copy_u8SlaveAddress<<1;
		SET_BIT(TWDR,0);
		
			/*Clear flag to start previous operation */
			SET_BIT(TWCR,TWCR_TWINT);
			
			/*wait until interrupt raised again*/
			while(GET_BIT(TWCR,TWCR_TWINT)==0);
			
			if ((TWSR & 0xf8) != SLAVE_ADD_AND_RD_ACK )
			{
				Local_ErrorStatus=SlaveAddressWithReadError;
			}
			else
			{
				
			}
	return Local_ErrorStatus;
}

TWI_ErrorStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	
	TWI_ErrorStatus  Local_ErrorStatus=NoERRor;
	//write data byte
	TWDR=Copy_u8DataByte;
			/*Clear flag to start previous operation */
			SET_BIT(TWCR,TWCR_TWINT);
			
			/*wait until interrupt raised again*/
			while(GET_BIT(TWCR,TWCR_TWINT)==0);
			
			if ((TWSR & 0xf8) != MASTER_WR_BYTE_ACK )
			{
				Local_ErrorStatus=MasterWriteByteError;
			}
			else
			{
				
			}
	
	return Local_ErrorStatus;
}

TWI_ErrorStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte)
{
	TWI_ErrorStatus  Local_ErrorStatus=NoERRor;
	//Enable master generating ACK bit after receiving data
	SET_BIT(TWCR,TWCR_TWEA);
	
	 //start slave send data
		/*Clear flag to start previous operation */
		SET_BIT(TWCR,TWCR_TWINT);
		
		/*wait until interrupt raised again*/
		while(GET_BIT(TWCR,TWCR_TWINT)==0);
		
		if ((TWSR & 0xf8) != MASTER_RD_BYTE_ACK )
		{
			Local_ErrorStatus=MasterReadByteError;
		}
		else
		{
			//read receive data
			*Copy_pu8DataByte= TWDR;
		}
	return Local_ErrorStatus;
}

void TWI_SendStop(void)
{
	//Set stop bit
	SET_BIT(TWCR,TWCR_TWSTO);
	
	/*Clear flag to start previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	
}
