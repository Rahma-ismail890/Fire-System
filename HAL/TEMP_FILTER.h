/*
 * TEMP_FILTER.h
 *
 * Created: 12/10/2023 08:43:19 ص
 *  Author: JOBA
 */ 


#ifndef TEMP_FILTER_H_
#define TEMP_FILTER_H_

#include "stand_type.h"
#include "sensors.h"
typedef enum 
{
	first_degree_filter=0,
	mean_filter
	}TEMPFILTER_TYPE;
	
void TEMP_Fiter_Init(void);
void TEMP_Fiter_Runnable(void);
u16  TEMP_Fiter_Getter(void); 



#endif /* TEMP_FILTER_H_ */