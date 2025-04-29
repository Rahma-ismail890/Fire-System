/*
 * DIO_interface.h
 *
 * Created: 25/09/2023 11:17:26 ص
 *  Author: JOBA
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "stand_type.h"
typedef enum
{
	low,
	high
	}DIO_pinvoltage_type;

typedef enum
{
	OUTPUT,
	INFREE,
	INPULL
	}DIO_pinstatues_type;
	
typedef enum
	{
		PINA0=0,
		PINA1,
		PINA2,
		PINA3,
		PINA4,
		PINA5,
		PINA6,
		PINA7,
		PINB0,
		PINB1,
		PINB2,
		PINB3,
		PINB4,
		PINB5,
		PINB6,
		PINB7,
		PINC0,
		PINC1,
        PINC2,
		PINC3,
		PINC4,
		PINC5,
		PINC6,
		PINC7,
		PIND0,
		PIND1,
		PIND2,
		PIND3,
		PIND4,
		PIND5,
		PIND6,
		PIND7,
		TOTAL_PIN
		}DIO_pin_type;
        typedef enum
		{
			PA=0,
			PB,
			PC,
			PD
			}DIO_port_type;
			
		
		
		void DIO_writepin(DIO_pin_type pin,DIO_pinvoltage_type volt);
		
		DIO_pinvoltage_type DIO_readpin(DIO_pin_type pin);
		
		void DIO_togglepin(DIO_pin_type pin);
		
        void DIO_writeport(DIO_port_type port,DIO_pinvoltage_type value);
		
		u8 DIO_readport(DIO_port_type port);
		
		void DIO_int(void);
		
#endif /* DIO_INTERFACE_H_ */