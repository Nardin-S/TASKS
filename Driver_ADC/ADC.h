/*
 * ADC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef ADC_H_
#define ADC_H_

#include "ADC_Configuration.h"
#include "BitMath.h"
#include "ATmega32_Registers.h"


/************************** Reference selection *******************************/
#define ADC_VREF_AVCC            0

#define ADC_VREF_AVREF           1

#define ADC_VREF_INTERNAL        2

/****************************** ADLAR *****************************************/
#define ADC_RIGHT_ADJUST         0

#define ADC_LEFT_ADJUST          1

/*************************** Select Analog channel *****************************/
#define ADC_CHANNEL_0            0
#define ADC_CHANNEL_1            1
#define ADC_CHANNEL_2            2
#define ADC_CHANNEL_3            3
#define ADC_CHANNEL_4            4
#define ADC_CHANNEL_5            5
#define ADC_CHANNEL_6            6
#define ADC_CHANNEL_7            7


/*************************** ADCSRA  *****************************/

#define ADC_AUTO_TRIGGER           0  // !!
#define ADC_One_Time_Conversion    1

#define ADC_PRESC_2              1
#define ADC_PRESC_4              2
#define ADC_PRESC_8              3
#define ADC_PRESC_16             4
#define ADC_PRESC_32             5
#define ADC_PRESC_64             6
#define ADC_PRESC_128            7

#define ADC_INTERRUPT_DISABLE    0
#define ADC_INTERRUPT_ENABLE     1


 /*************************** APIs *****************************/

void ADC_Initial(void);

void ADC_Read (Uint16* Analog_Value);

#endif /* ADC_H_ */
