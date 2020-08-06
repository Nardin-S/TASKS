/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */


#include "UART.h"
#include "LCD.h"

int main (void)
{

	UART_InIT () ;

	UART_TX_String ("HELLO!") ;

	 LCD_initial ();



	while(1)
	{

	}
}
