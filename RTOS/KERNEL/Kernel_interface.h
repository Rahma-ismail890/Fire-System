/*
 * Kernel_interface.h
 *
 * Created: 11/8/2023 11:32:50 AM
 *  Author: ُENG Ayman
 */ 


#ifndef KERNEL_INTERFACE_H_
#define KERNEL_INTERFACE_H_

void RTOS_voidStart(void);
u8 RTOS_u8CreateTask(u8 Copy_u8Priority,void (*Copy_pvtaskFunc)(void),u16 Copy_u16periodicity);



#endif /* KERNEL_INTERFACE_H_ */