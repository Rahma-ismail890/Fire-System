/*
 * LED.c
 *
 * Created: 11/28/2023 5:09:55 AM
 *  Author: Ayman
 */ 
#include "DIO_interface.h"
void LedOn(DIO_pin_type led)
{
	DIO_writepin(led,high);
}

void LedOff(DIO_pin_type led)
{
	DIO_writepin(led,low);
}
void ToggelLed(DIO_pin_type led)
{
	DIO_togglepin(led);
}