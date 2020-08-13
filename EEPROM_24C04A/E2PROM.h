/*
 * E2PROM.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef E2PROM_H_
#define E2PROM_H_

#include "I2C.h"

void EEPROM_WRITE(Uint8 ADDRESS , Uint8 data);
Uint8 EEPROM_READ (Uint8 ADDRESS);


#endif /* E2PROM_H_ */
