/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */


#include "E2PROM.h"

#include "LCD.h"

int main(void)
{

	 LCD_initial();

	 EEPROM_WRITE(0x50, 21);

	 Uint8 DATA = EEPROM_READ (0x50);

	 LCD_WriteChar(DATA);


	while(1)
	{


	}
}
