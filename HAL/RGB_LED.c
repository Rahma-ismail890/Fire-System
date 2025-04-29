#include "stand_type.h"
#include "utilt.h"
#include "memory.h"
#include "Timer1.h"
#include "DIO_interface.h"
#include "RGB_LED.h"

static RGB_LIGHTS arr_light[total_lights] ={{0,0,0},{255,255,255},{255,0,0},{0,255,0},{0,0,255},{255,255,0},{255,0,255},{0,255,255},{128,0,0},{255,153,204},{0,128,0},{0,0,128},{128,0,128},{255,165,0}};
void RGB_light(light_name light)
{

    Timer1_ICR1_write(255);
	    Timer0_OCR_write(arr_light[light].RED);
		Timer1_OCR1A_write(arr_light[light].GREEN);
	    Timer1_OCR1B_write(arr_light[light].BLUE);
		TCNT0=0;
		TCNT1=0;  	
	
	
	
}
u8 flag=0;
void showRoom(light_name light1,light_name light2)
{
	static u8 r,g,b;
	if(flag==0)
	{
		r=arr_light[light1].RED;
		g=arr_light[light1].GREEN;
		b=arr_light[light1].BLUE;
		flag=1;
	}
	Timer1_ICR1_write(255);
	if(r>arr_light[light2].RED)
	{
		
		Timer0_OCR_write(r);
		r--;
	}
	if(r<arr_light[light2].RED)
	{
		
		Timer0_OCR_write(r);
		r++;
	}
		if(g>arr_light[light2].GREEN)
		{
		
			Timer1_OCR1A_write(g);
				g--;
		}
		if(g<arr_light[light2].GREEN)
		{
			
			Timer1_OCR1A_write(g);
			g++;
		}
			if(b>arr_light[light2].BLUE)
			{
				
				Timer1_OCR1B_write(b);
				b--;
			}
			if(b<arr_light[light2].BLUE)
			{
				
				Timer1_OCR1B_write(b);
				b++;
			}
	if(r==arr_light[light2].RED&&g==arr_light[light2].GREEN&&b==arr_light[light2].BLUE)
	{
		flag=0;
		
	}
}