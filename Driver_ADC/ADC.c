/*
 * ADC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#include "ADC.h"

void ADC_Initial(void)
{
	/************************************  __ VREF __ ****************************************************/
	   switch ( ADC_VOLTAGE_REFERENCE)
	   {
		case ADC_VREF_AVCC :
	          Set_bit(ADMUX,6);
	          clr_bit(ADMUX,7);
	          break;

		case ADC_VREF_AVREF :
			 clr_bit(ADMUX,6);
			 clr_bit(ADMUX,7);
			 break;

		case ADC_VREF_INTERNAL :   // 2.56 V
			 Set_bit(ADMUX,6);
			 Set_bit(ADMUX,7);
			 break;

		default :
			 break;
		}

	   /************************************  __ CHANNEL __ ****************************************************/
	   switch (ADC_CHANNEL )
	   {
	   case ADC_CHANNEL_0 :
	          // clr_bit(ADMUX,0);
	          break;

		case  ADC_CHANNEL_1  :
			 Set_bit(ADMUX,0);
			 break;

		case  ADC_CHANNEL_2  :
			 Set_bit(ADMUX,1);
			 break;

		case  ADC_CHANNEL_3  :
			 Set_bit(ADMUX,0);
			 Set_bit(ADMUX,0);
			 break;

		case  ADC_CHANNEL_4  :
			 Set_bit(ADMUX,2);
			 break;

		case  ADC_CHANNEL_5  :
			 Set_bit(ADMUX,0);
			 Set_bit(ADMUX,2);
			 break;

		case  ADC_CHANNEL_6  :
			 Set_bit(ADMUX,1);
			 Set_bit(ADMUX,2);
			 break;

		case  ADC_CHANNEL_7  :
			 Set_bit(ADMUX,0);
			 Set_bit(ADMUX,1);
			 Set_bit(ADMUX,2);
			 break;

		default:
			 break;
		}

	   /************************************  __ADJUSTMENT__ ****************************************************/
	   switch (ADC_ADJUSTMENT)
	   {
	   case ADC_RIGHT_ADJUST :
	     clr_bit(ADMUX,5);
	     break;

	   case ADC_LEFT_ADJUST :
	      Set_bit(ADMUX,5);
	      break;
	   }

	   /************************************  __ CONVERSION __ ****************************************************/
       switch (ADC_CONVERSION_TRIGGER)
       {
        case ADC_AUTO_TRIGGER:
          Set_bit(ADCSRA,5);
          break;

        case ADC_One_Time_Conversion:
           clr_bit(ADCSRA,5);
           break;

        default :
        	break;
        }



    /************************************  __ PRESCALAR __ ****************************************************/
       switch (ADC_PRESCALER)
       {

       case ADC_PRESC_2 :

        	Set_bit(ADCSRA,0);

        	clr_bit(ADCSRA,1);

        	clr_bit(ADCSRA,2);

        	break;

       case ADC_PRESC_4 :

        	clr_bit(ADCSRA,0);

        	Set_bit(ADCSRA,1);

        	clr_bit(ADCSRA,2);

        	break;

       case ADC_PRESC_8 :

        	Set_bit(ADCSRA,0);

        	Set_bit(ADCSRA,1);

        	clr_bit(ADCSRA,2);

        	break;

       case ADC_PRESC_16 :

        	clr_bit(ADCSRA,0);

        	clr_bit(ADCSRA,1);

        	Set_bit(ADCSRA,2);

        	break;

       case ADC_PRESC_32 :

        	clr_bit(ADCSRA,0);

        	clr_bit(ADCSRA,1);

        	Set_bit(ADCSRA,2);

        	break;

       case ADC_PRESC_64 :

        	clr_bit(ADCSRA,0);

        	Set_bit(ADCSRA,1);

        	Set_bit(ADCSRA,2);

        	break;

       case ADC_PRESC_128 :

        	Set_bit(ADCSRA,0);

        	Set_bit(ADCSRA,1);

        	Set_bit(ADCSRA,2);

        	break;

       default:
    	   break;
       }


/************************************  __ INTERRUPT __ ****************************************************/
       switch  (ADC_INTERRUPT_STATUS)
       {
       case ADC_INTERRUPT_DISABLE :
        	clr_bit(ADCSRA , 3);
            break;
       case  ADC_INTERRUPT_ENABLE :
    	     Set_bit(ADCSRA , 3);
    	     break;

       default:
         	   break;
            }


	//ADC Enable */
Set_bit(ADCSRA,7);


}





void ADC_Read(Uint16* Analog_Value)
{

Uint16 Digital_Value = 0;

/* Start Conversion*/
Set_bit(ADCSRA,6);

#if  ADC_INTERRUPT_STATUS  ==  ADC_INTERRUPT_DISABLE

while( ! get_bit(ADCSRA,4) );

Digital_Value = ADC_ADJUSTMENT; //(ADCH << 2) | (ADCL >>6);

*Analog_Value = ((Digital_Value * 500) / 1024) ;

#elif ADC_INTERRUPT_STATUS  ==  ADC_INTERRUPT_ENABLE

while( get_bit(ADCSRA,4) );

Digital_Value = ADC_ADJUSTMENT; //(ADCH << 2) | (ADCL >>6);

*Analog_Value = ((Digital_Value * 500) / 1024) ;

#endif
}











