/*
 * BUZZER.c
 *
 * Created: 11/28/2023 5:17:47 AM
 *  Author: Ayman
 */ 
#include "DIO_interface.h"
void BuzzerOn(DIO_pin_type buzzer)
{
	DIO_writepin(buzzer,high);
}

void BuzzerOff(DIO_pin_type buzzer)
{
	DIO_writepin(buzzer,low);
}