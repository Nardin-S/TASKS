/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#define F_CPU  16000000
#include "Temp_Sensor.h"
#include "LCD.h"
#include <util/delay.h>

int main (void){


	Uint16 Temp = 0;

	LCD_initial();
	TempSensor_Initial();

	while(1){

		TempSensor_Read(&Temp);

		 LCD_Clear();

		LCD_WriteInteger(Temp);

	}
}
