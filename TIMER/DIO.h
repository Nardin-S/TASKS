/*
 * DIO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef DIO_H_   ///Guard
#define DIO_H_

#include "ATmega32_Registers.h"
#include "BitMath.h"

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3


#define DIO_Pin0  0
#define DIO_Pin1  1
#define DIO_Pin2  2
#define DIO_Pin3  3
#define DIO_Pin4  4
#define DIO_Pin5  5
#define DIO_Pin6  6
#define DIO_Pin7  7

// SET ALL PORT PINS DIRECTION
#define DIO_PORT_OUTPUT    0xFF
#define DIO_PORT_INPUT     0x00

// SET CERTIAN Pin DIRECTION in PORT
#define DIO_Pin_OUTPUT    1
#define DIO_Pin_INPUT     0

// hatala3 value 3la all pins of PORT
#define DIO_PORT_High   0xFF
#define DIO_PORT_LOW    0x00


// hatala3 value 3la pin Mo3aiana fi el PORT
#define DIO_Pin_High    1
#define DIO_Pin_LOW     0



// here is PROTOTYPE

void DIO_SetPortDir(Uint8 port , Uint8 dir);
void DIO_SetPinDir(Uint8 port , Uint8 pin  ,Uint8 dir);


void DIO_WritePort(Uint8 port , Uint8 value);
void DIO_WritePin(Uint8 port , Uint8 pin  ,Uint8 value);

void DIO_ReadPort(Uint8 port , Uint8* value);
void DIO_ReadPin(Uint8 port , Uint8 pin  ,Uint8* value);

void DIO_TogglePin(Uint8 port , Uint8 pin);

#endif /* DIO_H_ */
