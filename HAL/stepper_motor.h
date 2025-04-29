/*
 * stepper_motor.h
 *
 * Created: 04/10/2023 03:32:16 م
 *  Author: JOBA
 */ 


#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_


/**************************************bipoler*************************************************/
#define coil1A      PINC0
#define coil1B      PINC1
#define coil2A      PINC2
#define coil2B      PINC3
#define   delay      500
/*********************************************************************************************/
void stepper_bipolercw(void);
void stepper_bipolerccw(void);
void stepper_unipolercw(void);
void stepper_unipolerccw(void);
#endif /* STEPPER_MOTOR_H_ */