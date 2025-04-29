/*
 * motor_interface.h
 *
 * Created: 27/09/2023 05:36:28 م
 *  Author: JOBA
 */ 


#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_
typedef enum
{
	M1,
	M2,
	M3,
	M4
	}Motor_number;
void Motor_int(void);
void Motor_stop(Motor_number motor);
void Motor_cw(Motor_number motor);
void Motor_ccw(Motor_number motor);


#endif /* MOTOR_INTERFACE_H_ */