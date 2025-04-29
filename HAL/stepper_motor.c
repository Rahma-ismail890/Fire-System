/*
 * stepper_motor.c
 *
 * Created: 04/10/2023 03:32:59 م
 *  Author: JOBA
 */ 
#include "stand_type.h"
#include "DIO_interface.h"
#include "stepper_motor.h"
#define F_CPU 8000000
#include <util\delay.h>
void stepper_bipolercw(void)
{
	DIO_writepin(coil1A,high);
	DIO_writepin(coil1B,low);
	DIO_writepin(coil2A,low);
	DIO_writepin(coil2B,low);
	_delay_ms(delay);
	DIO_writepin(coil1A,low);
	DIO_writepin(coil1B,low);
	DIO_writepin(coil2A,high);
	DIO_writepin(coil2B,low);
	_delay_ms(delay);
	DIO_writepin(coil1A,low);
	DIO_writepin(coil1B,high);
	DIO_writepin(coil2A,low);
	DIO_writepin(coil2B,low);
	_delay_ms(delay);
	DIO_writepin(coil1A,low);
	DIO_writepin(coil1B,low);
	DIO_writepin(coil2A,low);
	DIO_writepin(coil2B,high);
	_delay_ms(delay);		
}


void stepper_bipolerccw(void)
{
	DIO_writepin(coil1A,low);
	DIO_writepin(coil1B,high);
	DIO_writepin(coil2A,low);
	DIO_writepin(coil2B,low);
	_delay_ms(delay);
	DIO_writepin(coil1A,low);
	DIO_writepin(coil1B,low);
	DIO_writepin(coil2A,low);
	DIO_writepin(coil2B,high);
	_delay_ms(delay);
	DIO_writepin(coil1A,high);
	DIO_writepin(coil1B,low);
	DIO_writepin(coil2A,low);
	DIO_writepin(coil2B,low);
	_delay_ms(delay);
	DIO_writepin(coil1A,low);
	DIO_writepin(coil1B,low);
	DIO_writepin(coil2A,high);
	DIO_writepin(coil2B,low);
	_delay_ms(delay);


}



void stepper_unipolercw(void)
{
	DIO_writepin(coil1A,high);
	DIO_writepin(coil1B,low);
	DIO_writepin(coil2A,low);
	DIO_writepin(coil2B,low);
	_delay_ms(delay);
	DIO_writepin(coil1A,low);
	DIO_writepin(coil1B,high);
	DIO_writepin(coil2A,low);
	DIO_writepin(coil2B,low);
	_delay_ms(delay);
	DIO_writepin(coil1A,low);
	DIO_writepin(coil1B,low);
	DIO_writepin(coil2A,high);
	DIO_writepin(coil2B,low);
	_delay_ms(delay);
	DIO_writepin(coil1A,low);
	DIO_writepin(coil1B,low);
	DIO_writepin(coil2A,low);
	DIO_writepin(coil2B,high);
	_delay_ms(delay);	
}

void stepper_unipolerccw(void)
{
		DIO_writepin(coil1A,low);
		DIO_writepin(coil1B,low);
		DIO_writepin(coil2A,low);
		DIO_writepin(coil2B,high);
		_delay_ms(delay);
		DIO_writepin(coil1A,low);
		DIO_writepin(coil1B,low);
		DIO_writepin(coil2A,high);
		DIO_writepin(coil2B,low);
		_delay_ms(delay);
		DIO_writepin(coil1A,low);
		DIO_writepin(coil1B,high);
		DIO_writepin(coil2A,low);
		DIO_writepin(coil2B,low);
		_delay_ms(delay);	
		DIO_writepin(coil1A,high);
		DIO_writepin(coil1B,low);
		DIO_writepin(coil2A,low);
		DIO_writepin(coil2B,low);
		_delay_ms(delay);		
					
}
