/*
 * sensors.h
 *
 * Created: 06/10/2023 10:56:51 م
 *  Author: JOBA
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_
#define TEMP_ch          CH0
#define Pressure_ch          CH7
#include "stand_type.h"
u16 Temp_read(void);
u16 pressure_read(void)  ;

#endif /* SENSORS_H_ */