/*
 * DIO.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#include "DIO.h"

void DIO_SetPortDir(Uint8 port , Uint8 dir){

	switch (port)
{
	case DIO_PORTA :
		DDRA = dir ;
		break;

	case DIO_PORTB :
			DDRB = dir ;
			break;

	case DIO_PORTC :
			DDRC = dir ;
			break;

	case DIO_PORTD :
			DDRD = dir ;
			break;

	default:
		break;
	}
}


void DIO_SetPinDir(Uint8 port , Uint8 pin  ,Uint8 dir){

	switch (dir)
	{
	  case (DIO_Pin_OUTPUT):

	    switch (port)
	    {
	    case  DIO_PORTA:
		    	Set_bit(DDRA,pin);
		    	break;

	    case  DIO_PORTB:
		    	Set_bit(DDRB,pin);
		    	break;

	    case  DIO_PORTC:
		    	Set_bit(DDRC,pin);
		    	break;

		case  DIO_PORTD:
		    	Set_bit(DDRD,pin);
		    	break;

	   default:
		    	break ;
	    }

	  break ;
	  case (DIO_Pin_INPUT):
			  switch (port)
	          {
	          case  DIO_PORTA:
	   	    	clr_bit(DDRA,pin);
	  		    	break;

    		    case  DIO_PORTB:
    		    	clr_bit(DDRB,pin);
	    	    	break;

	    		    case  DIO_PORTC:
	    		    	clr_bit(DDRC,pin);
	    		    	break;

	    		    case  DIO_PORTD:
	    		    	clr_bit(DDRD,pin);
	    		    	break;

	    		    default:
	    		    	break ;
	    	    }
	    break;

	    default :
	    	break;
	}
}


void DIO_WritePort(Uint8 port , Uint8 value)
{
  switch(port)
  {
     case DIO_PORTA:
	  PORTA = value;
      break;

     case DIO_PORTB :
       DDRB =value ;
       break;

     case DIO_PORTC :
     	DDRC =value ;
     	break;

     case DIO_PORTD :
     	DDRD = value ;
     	break;

     default:
     	break;
  }
}

void DIO_WritePin(Uint8 port , Uint8 pin  ,Uint8 value)
{
	switch (value)
	{
	case (DIO_Pin_High):
			switch (port)
			{
			case  DIO_PORTA:
		       Set_bit(PORTA,pin);
		       break;

		    case  DIO_PORTB:
		    	Set_bit(PORTB,pin);
		    	break;

		    case  DIO_PORTC:
		    	Set_bit(PORTC,pin);
		    	break;

		    case  DIO_PORTD:
		    	Set_bit(PORTD,pin);
		    	break;

		    default:
		    	break ;
			}

	  break ;

	  case (DIO_Pin_LOW):
			  switch (port)
			{
	    	case  DIO_PORTA:
	    		   clr_bit(PORTA,pin);
	    		   break;

	    	case  DIO_PORTB:
	    		    clr_bit(PORTB,pin);
	    		    break;

	   		case  DIO_PORTC:
	    		    clr_bit(PORTC,pin);
	    		    break;

	   		case  DIO_PORTD:
	    		    clr_bit(PORTD,pin);
	    		    break;

	    	   default:
	    		   break ;
	    	 }
	    break;

	    default :
	    	break;
	}
}


void DIO_ReadPort(Uint8 port , Uint8* value)
{
	switch(port)
	  {
	     case DIO_PORTA :
		 *value = PINA;
	      break;

	     case DIO_PORTB :
	      *value = PINB;
	       break;

	     case DIO_PORTC :
	       *value = PINC;
	     	break;

	     case DIO_PORTD :
	        *value = PIND ;
	     	 break;

	     default:
	     	break;
	  }
}
void DIO_ReadPin(Uint8 port , Uint8 pin  ,Uint8* value)
{

	 switch(port)
		  {
		     case DIO_PORTA:
		    	 *value =  get_bit(PINA,pin);
		    	 break;

		     case DIO_PORTB :
		    	 *value =  get_bit(PINB,pin);
		       break;

		     case DIO_PORTC :
		       *value =  get_bit(PINC,pin);
		     	break;

		     case DIO_PORTD :
		    	 *value =  get_bit(PIND , pin);
		     	 break;

		     default:
		     	break;
		  }
}

void DIO_TogglePin(Uint8 port , Uint8 pin){

			switch (port)
			{
			case  DIO_PORTA:
				toggle(PORTA,pin);
		       break;

		    case  DIO_PORTB:
		    	toggle(PORTB,pin);
		    	break;

		    case  DIO_PORTC:
		    	toggle(PORTC,pin);
		    	break;

		    case  DIO_PORTD:
		    	toggle(PORTD,pin);
		    	break;

		    default:
		    	break ;
			}
}
