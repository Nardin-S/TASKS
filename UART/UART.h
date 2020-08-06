/*
 * UART.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef UART_H_
#define UART_H_

#include "DIO.h"


void UART_InIT (void);

void UART_TX_Byte (Uint8  transmitted_data);

void UART_TX_String (Uint8* str );

Uint8 UART_RX_Byte (void);

void  UART_RX_String (void );  // TASK

#endif /* UART_H_ */
