/*
 * _7seg.c
 *
 * Created: 24/09/2023 03:13:33 م
 *  Author: JOBA
 */ 
#include "memory.h"
#include "stand_type.h"
#include "utilt.h"
#define F_CPU 8000000
#include <util\delay.h>
#include "7seg.h"
void _7sig_display(int n )
{
	char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	int d0=n%10;
	int d1=n/10;
	CLER_BIT(PORTC,7);
	PORTA=arr[d0]<<1;
	SET_BIT(PORTC,6);
	_delay_ms(10);
	CLER_BIT(PORTC,6);
	PORTA=arr[d1]<<1;
	SET_BIT(PORTC,7);
	_delay_ms(10);
	
	
}
void _7sig_display1(int n )
{
	char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	PORTA=arr[n]<<1;
}