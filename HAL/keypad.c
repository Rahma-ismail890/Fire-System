#include "stand_type.h"
#include "DIO_interface.h"
#include "keypad.h"
#include "keypad_private.h"
void keypad_int(void)
{
	DIO_writepin(first_output,high);
	DIO_writepin(first_output+1,high);
	DIO_writepin(first_output+2,high);
	DIO_writepin(first_output+3,high);
}

u8 keypad_getkey(void)
{
	u8 key =default;
	for(u8 i=0;i<row;i++)
	{
		DIO_writepin(first_output+i,low);
		for(u8 j=0;j<column;j++)
		{
			if(DIO_readpin(first_input+j)==low)
			{
				key=keypad_arr[i][j];
				while(DIO_readpin(first_input+j)==low);
			}
			
		}
		DIO_writepin(first_output+i,high);
	}
	return key;
}