#include "stand_type.h"
#include "sensors.h"
#include "utilt.h"
#include "ADC.h"
u16 Temp_read(void)               //temp c*10
{
	u16 volt=ADC_read_volt(TEMP_ch);
	u16 temp=volt;
	return temp;
}


u16 pressure_read(void)               //pressure p*10
{
	u16 adc=ADC_read(Pressure_ch );
	u16 pressure=((u32)1000*(adc-55)/921)+150;
	return pressure;
}