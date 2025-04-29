/*
 * ADC.c
 *
 * Created: 06/10/2023 04:20:02 م
 *  Author: JOBA
 */ 
#include "stand_type.h"
#include "memory.h"
#include "utilt.h"
#include "ADC.h"
#define F_CPU 8000000
#include <util\delay.h>

void ADC_enable(void)
{
	SET_BIT(ADCSRA,ADEN);
}
void ADC_disable(void)
{
	CLER_BIT(ADCSRA,ADEN);
}

void ADC_int(ADC_vref_type vref,ADC_prescaller_type prescaller)
{

   // select prescaller
	prescaller =prescaller & 0x07;
	ADCSRA=(ADCSRA & 0xf8 )| prescaller;
	CLER_BIT(ADMUX,ADLAR);	
	// select vref
	switch(vref)
	{
		case AREF:
		CLER_BIT(ADMUX,REFS0);
		CLER_BIT(ADMUX,REFS1);
		break;
		case AVCC:
		SET_BIT(ADMUX,REFS0);
		CLER_BIT(ADMUX,REFS1);
		break;
		case v256:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}
	
	
     	// ADC enable
     	ADC_enable();
     	
}

u16 ADC_read(ADC_channel channel)
{
	
	//select ch
	channel =channel&0x07;
	ADMUX=(0xe0 & ADMUX )| channel;
	//start conversion
	SET_BIT(ADCSRA,ADSC);
	//wait until finish
	while(READ_BIT(ADCSRA,ADSC));
	//read
	return ADC;
}
u16 ADC_read_volt(ADC_channel channel)
{
	u16 adc=ADC_read(channel);
	u16 vin=(adc*(u32)5000)/1024;
	return vin;
} 