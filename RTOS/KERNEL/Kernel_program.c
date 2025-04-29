#include "stand_type.h"
#include "memory.h"
#include "Kernel_private.h"
#include "Kernel_interface.h"
#include "Kernel_config.h"

#define OK           0
#define NOK          1
typedef struct
{
	u16 periodicity;
	void (*TaskFunc)(void);
	}Task_T;

Task_T SystemTasks[Task_NUM]={{NULL}};
	
void RTOS_voidStart(void)
{
	//configer timer to generate interrupt every 1ms
	Timer1_SetInterruptTime_ms(1,Scheduler);
	//enable global interrupts
	sei();
}

u8 RTOS_u8CreateTask(u8 Copy_u8Priority,void (*Copy_pvtaskFunc)(void),u16 Copy_u16periodicity)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_pvtaskFunc!=NULLPTR)
	{
		SystemTasks[Copy_u8Priority].periodicity=Copy_u16periodicity;
		SystemTasks[Copy_u8Priority].TaskFunc=Copy_pvtaskFunc;
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

static void Scheduler(void)
{
	volatile static u16 Local_u16SystickCounter=0;
	u8 Local_u8TaskCounter=0;
	Local_u16SystickCounter++;
	for(Local_u8TaskCounter=0;Local_u8TaskCounter<Task_NUM;Local_u8TaskCounter++)
	{
		if(Local_u16SystickCounter % SystemTasks[Local_u8TaskCounter].periodicity==0)
		{
			if(SystemTasks[Local_u8TaskCounter].TaskFunc!=NULLPTR)
			{
				SystemTasks[Local_u8TaskCounter].TaskFunc();
			}
		}
		else
		{
			
		}
	}
}



