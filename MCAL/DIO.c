#include "stand_type.h"
#include "memory.h"
#include "utilt.h"
#include "DIO_interface.h"
#include "private.h"
static void DIO_intpin(DIO_pin_type pin,DIO_pinstatues_type statues)
{
	switch(statues)
	{
		case OUTPUT:
		      if(pin<8)
			  {
				  SET_BIT(DDRA,pin);
				  CLER_BIT(PORTA,pin);
			  }
			  else if(pin>7&&pin<16)
		       {
			       SET_BIT(DDRB,pin-8);
			       CLER_BIT(PORTB,pin-8);
		       }
			     else if(pin>15&&pin<24)
			     {
				     SET_BIT(DDRC,pin-16);
				     CLER_BIT(PORTC,pin-16);
			     }
				   else if(pin>23&&pin<32)
				   {
					   SET_BIT(DDRD,pin-24);
					   CLER_BIT(PORTD,pin-24);
				   }
				   break;
				   	case INFREE:
				   	if(pin<8)
				   	{
					   	CLER_BIT(DDRA,pin);
					   	CLER_BIT(PORTA,pin);
				   	}
				   	else if(pin>7&&pin<16)
				   	{
					   CLER_BIT(DDRB,pin-8);
					   	CLER_BIT(PORTB,pin-8);
				   	}
				   	else if(pin>15&&pin<24)
				   	{
					   	CLER_BIT(DDRC,pin-16);
					   	CLER_BIT(PORTC,pin-16);
				   	}
				   	else if(pin>23&&pin<32)
				   	{
					   	CLER_BIT(DDRD,pin-24);
					   	CLER_BIT(PORTD,pin-24);
				   	}
				   	break;
					   	case INPULL:
					   	if(pin<8)
					   	{
						   	CLER_BIT(DDRA,pin);
						   	SET_BIT(PORTA,pin);
					   	}
					   	else if(pin>7&&pin<16)
					   	{
						   	CLER_BIT(DDRB,pin-8);
						   SET_BIT(PORTB,pin-8);
					   	}
					   	else if(pin>15&&pin<24)
					   	{
						   	CLER_BIT(DDRC,pin-16);
						   	SET_BIT(PORTC,pin-16);
					   	}
					   	else if(pin>23&&pin<32)
					   	{
						   CLER_BIT(DDRD,pin-24);
						   	SET_BIT(PORTD,pin-24);
					   	}
					   	
				   
	}
}
void DIO_writepin(DIO_pin_type pin,DIO_pinvoltage_type volt)
{
	switch(volt)
	{
		case high:
		      if(pin<8)
		      {
			      SET_BIT(PORTA,pin);
			   
		      }
		      else if(pin>7&&pin<16)
		      {
			      SET_BIT(PORTB,pin-8);
			      
		      }
		      else if(pin>15&&pin<24)
		      {
			      SET_BIT(PORTC,pin-16);
			      
		      }
		      else if(pin>23&&pin<32)
		      {
			      SET_BIT(PORTD,pin-24);
			    
		      }
		      break;
		case low:
		   	if(pin<8)
		   	{
			  
			   	CLER_BIT(PORTA,pin);
		   	}
		   	else if(pin>7&&pin<16)
		   	{
			   	
			   	CLER_BIT(PORTB,pin-8);
		   	}
		   	else if(pin>15&&pin<24)
		   	{
			   	
			   	CLER_BIT(PORTC,pin-16);
		   	}
		   	else if(pin>23&&pin<32)
		   	{
			   
			   	CLER_BIT(PORTD,pin-24);
		   	}
	}
}
DIO_pinvoltage_type DIO_readpin(DIO_pin_type pin)
{
	
	   	if(pin<8)
	   	{
		   	
		   return READ_BIT(PINA,pin);
	   	}
	   	else if(pin>7&&pin<16)
	   	{
		   
		   return READ_BIT(PINB,pin-8);
	   	}
	   	else if(pin>15&&pin<24)
	   	{
		  return READ_BIT(PINC,pin-16);
		   
	   	}
	   	else if(pin>23&&pin<32)
	   	{
		   	
		   return READ_BIT(PIND,pin-24);
	   	}
		   
}
void DIO_togglepin(DIO_pin_type pin)
{
	
	if(pin<8)
	{
		
		TOGL_BIT(PORTA,pin);
	}
	else if(pin>7&&pin<16)
	{
		
		TOGL_BIT(PORTB,pin-8);
	}
	else if(pin>15&&pin<24)
	{
		TOGL_BIT(PORTC,pin-16);
		
	}
	else if(pin>23&&pin<32)
	{
		
		TOGL_BIT(PORTD,pin-24);
	}
	
}

 void DIO_writeport(DIO_port_type port,DIO_pinvoltage_type value)
{
	switch(port)
	{
		case PA:
		PORTA=value;
		break;
		case PB:
		PORTB=value;
		break;
		case PC:
		PORTC=value;
		break;
		case PD:
		PORTD=value;
		
	}
}
u8 DIO_readport(DIO_port_type port)
{
		switch(port)
		{
			case PA:
			return PINA;
			break;
			case PB:
			return PINB;
			break;
			case PC:
			return PINC;
			break;
			case PD:
			return PIND;
			
		}
	
}


void DIO_int(void)
{
	DIO_pin_type i;
	for(i=0;i<TOTAL_PIN;i++)
	{
		DIO_intpin(i,pinStatuesarray[i]);
	}
}