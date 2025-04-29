
#define F_CPU 8000000
#include <util\delay.h>


#include "memory.h"
#include "utilt.h"
#include "DIO_interface.h"
#include "motor_interface.h"
#include "lcd_interface.h"
#include "stepper_motor.h"
#include "keypad.h"
#include "ADC.h"
#include "sensors.h"
#include "7seg.h"
#include "EIU.h"
#include "TEMP_FILTER.h"
#include "EEPROM.h"
#include "Timer1.h"
#include "RGB_LED.h"
#include "UART.h"
#include "UART_service.h"
#include "Cacet.h"
#include "LDR.h"
#include "FireSystem.h"
#include "PasswordSystem.h"
#include "LED.h"

int main(void)
{

    sei();        
	DIO_int();
	lcd_int();
    keypad_int();
    ADC_int(AVCC,prescaller64);
	EXI_Enable(EX_INT0);
	EXI_TriggerEdge(EX_INT0,RISING_EDGE);
	EXI_SetCallBack(EX_INT0,F);
	passwordSystem();
	FireSystem();
}