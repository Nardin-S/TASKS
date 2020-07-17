/*
 * Temp_Sensor.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#include "Temp_Sensor.h"


void TempSensor_Initial(void)
{
	ADC_Initial();

}


void TempSensor_Read(Uint16* Temp)
{

	ADC_Read(Temp);

}
