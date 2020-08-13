/*
 * I2C.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#include "I2C.h"

                           /***** Initialization *****/

void I2C_init_Master(void)
{
	                /*** CLOCK ***/
 TWBR =0x0C ;
 clr_bit(TWSR,0);
 clr_bit(TWSR,1);

                  /*** Enable I2C IN OUR device ***/
 Set_bit(TWCR,2);

}


void I2C_init_Slave (void)
{
                  /***_ Address of target slave _***/
TWAR = ( 0X01 << 1 ) ;

                  /*** Enable I2C IN OUR device ***/
Set_bit(TWCR,2);

}
/*__________________________________________________________________________________________*/

                                      /***** Operations *****/

void I2C_START_CONDITION (void)
{
	Set_bit(TWCR,5);
	Set_bit(TWCR,2);
	Set_bit(TWCR,7);      // CLEARING FLAG ..... START OPERATION

	while(get_bit(TWCR,7) == 0);         //Flag check
	while ((TWSR & 0XF8) == START_ACK);  // status check
}
void I2C_Repeated_START  (void)
{
	Set_bit(TWCR,5);
	Set_bit(TWCR,2);
	Set_bit(TWCR,7);      // CLEARING FLAG ..... START OPERATION

	while(get_bit(TWCR,7) == 0);                  //Flag check
	while ((TWSR & 0XF8) == REPEATED_START_ACK);  // status check

}

void I2C_Send_Slave_Address_WriteOperation (Uint8 Address)
{
	TWDR = (Address << 1) ;   // ÍØíÊ address Çááí ÚÇæÒ Çßáãå  + write operation

	Set_bit(TWCR,2);       // Enabling Peripheral
	Set_bit(TWCR,7);      // CLEARING FLAG ..... START OPERATION

	while(get_bit(TWCR,7) == 0);                        //Flag check
	while ((TWSR & 0XF8) == SlaveAddress_AND_WR_ACK);  // status check


}
void I2C_Send_Slave_Address_ReadOperation  (Uint8 Address)
{
	   TWDR = (Address << 1) | (0X01) ;   // ÍØíÊ address ÇáÌåÇÒ  Çááí ÚÇæÒ Çßáãå  + Read operation

		Set_bit(TWCR,2);       // Enabling Peripheral
		Set_bit(TWCR,7);      // CLEARING FLAG ..... START OPERATION

		while(get_bit(TWCR,7) == 0);                        //Flag check
		while ((TWSR & 0XF8) == SlaveAddress_AND_RD_ACK);  // status check

}


void  I2C_Write_Byte (Uint8 Data)
{
	   TWDR = Data ;

	   Set_bit(TWCR,2);       // Enabling Peripheral
       Set_bit(TWCR,7);      // CLEARING FLAG ..... START OPERATION

	   while(get_bit(TWCR,7) == 0);                        //Flag check
	   while ((TWSR & 0XF8) == Write_Byte_ACK);           // status check

}


Uint8 I2C_Read_Byte (void)
{

	Set_bit(TWCR,2);       // Enabling Peripheral
    Set_bit(TWCR,7);      // CLEARING FLAG ..... START OPERATION

    while(get_bit(TWCR,7) == 0);                        //Flag check
	while ((TWSR & 0XF8) == Read_Byte_With_NACK);      // status check

	return TWDR ;
}

void I2C_STOP_CONDITION (void)
{

	Set_bit(TWCR,4);
	Set_bit(TWCR,2);
	Set_bit(TWCR,7);      // CLEARING FLAG ..... START OPERATION

	while(get_bit(TWCR,7) == 0);         //Flag check

}
