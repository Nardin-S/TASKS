/*
 * E2PROM.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#include "E2PROM.h"

void EEPROM_WRITE(Uint8 ADDRESS , Uint8 data)
{

	I2C_init_Master();  //INITIATE micro controller as master
	I2C_START_CONDITION () ;
	I2C_Send_Slave_Address_WriteOperation (0x50) ;
    I2C_Send_Slave_Address_WriteOperation (ADDRESS) ;       // specific memory location
	I2C_Write_Byte (data) ;
	I2C_STOP_CONDITION () ;

}


Uint8 EEPROM_READ (Uint8 ADDRESS)
{

	Uint8 Data ;

	I2C_init_Master();  //INITIATE micro controller as master
	I2C_START_CONDITION () ;
	I2C_Send_Slave_Address_WriteOperation (0x50) ;
    I2C_Send_Slave_Address_WriteOperation (ADDRESS) ;

	I2C_Repeated_START  ();
	I2C_Send_Slave_Address_WriteOperation (0x50) ;
    I2C_Send_Slave_Address_ReadOperation  (ADDRESS) ;

	Data = I2C_Read_Byte () ;
	I2C_STOP_CONDITION ();

	return Data ;

}
