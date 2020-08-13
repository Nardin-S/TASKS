/*
 * I2C.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef I2C_H_
#define I2C_H_

#include "ATmega32_Registers.h"
#include  "BitMath.h"

/** _TWSR_ OPERATION STATUS ***/

#define START_ACK                           0X08    //_start has been sent
#define REPEATED_START_ACK                  0X10    //_Repeated Start condition has been transmitted

#define SlaveAddress_AND_WR_ACK             0X18    //_Master transmitted (slave address +Write request) ACK
#define SlaveAddress_AND_RD_ACK             0X40    //_Master transmitted (slave address + Read request) ACK

#define Write_Byte_ACK                      0X28    //_ MASTER TRANSMIT DATA ACK
#define Read_Byte_With_NACK                 0X58    //_ MASTER RECEIVE DATA NOT ACK

#define Slave_Address_Received_WR_REQ       0X60    //_Slave address has been received with write request
#define Slave_Address_Received_RD_REQ       0XA8    //_Slave address has been received with Read request

#define Slave_DATA_RECEIVED                 0X80    //_Read byte  request is received
#define Slave_Byte_TRANSMITTED              0XC0    //_Write byte request is received



/**** OPERATIONS ON I2C ****/

void I2C_init_Master(void) ;
void I2C_init_Slave (void) ;

/*** FRAME SECTIONS ***/

void I2C_START_CONDITION (void) ;
void I2C_Repeated_START  (void) ;

void I2C_Send_Slave_Address_WriteOperation (Uint8 Address) ;
void I2C_Send_Slave_Address_ReadOperation  (Uint8 Address) ;


void  I2C_Write_Byte (Uint8 Data) ;
Uint8 I2C_Read_Byte (void) ;

void I2C_STOP_CONDITION (void) ;


#endif /* I2C_H_ */
