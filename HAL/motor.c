#include "stand_type.h"
#include "DIO_interface.h"
#include "motor_interface.h"
#include "motor_confg.h"
#include "privet.h"
void Motor_int(void)
{
	//no code needed
}
extern const DIO_pin_type Motor_IN1[number_of_motor];
extern const DIO_pin_type Motor_IN2[number_of_motor];

void Motor_stop(Motor_number motor)
{
	DIO_writepin(Motor_IN1[motor],low);
	DIO_writepin(Motor_IN2[motor],low);
}

void Motor_cw(Motor_number motor)
{
	DIO_writepin(Motor_IN1[motor],high);
	DIO_writepin(Motor_IN2[motor],low);
}
void Motor_ccw(Motor_number motor)
{
	DIO_writepin(Motor_IN1[motor],low);
	DIO_writepin(Motor_IN2[motor],high);
}
