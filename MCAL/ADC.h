/*
 * ADC.h
 *
 * Created: 06/10/2023 04:19:48 م
 *  Author: JOBA
 */ 


#ifndef ADC_H_
#define ADC_H_

#define REFS0      6
#define REFS1      7
#define ADEN       7
#define ADSC       6
#define ADLAR      5
typedef enum
{
	AREF,
	AVCC,
	v256
	}ADC_vref_type;

typedef enum
{
	prescaller2=1,
	prescaller4,
	prescaller8,
	prescaller16,
	prescaller32,
	prescaller64,
	prescaller128
	
	}ADC_prescaller_type;
	
	typedef enum 
	{
		CH0,
		CH1,
		CH2,
		CH3,
		CH4,
		CH5,
		CH6,
		CH7
		}ADC_channel;
void ADC_int(ADC_vref_type vref,ADC_prescaller_type prescaller);
void ADC_enable(void);
void ADC_disable(void);
u16 ADC_read(ADC_channel channel);
u16 ADC_read_volt(ADC_channel channel);
#endif /* ADC_H_ */