#include "TEMP_FILTER.h"
#include "TEMP_FILTER_cfg.h"
static u16 tempfiltered;

void TEMP_Fiter_Init(void)
{
	tempfiltered=Temp_read();
}


void TEMP_Fiter_Runnable(void)                                 
{
	static u16 i=0;
	u16 unfiltered_temp=Temp_read();
	static u16 total_temp=0;
	static u16 unfiltered_tempArr[10];
	static u16 in=0;
	static u16 out=0;
	if(FILTER_TYPE==first_degree_filter)
	{
		 unfiltered_tempArr[out]=unfiltered_temp;
		out++;
		in++;
		if(in==10)
		{
			for(u16 x=0;x<10;x++)
			{
				total_temp=total_temp+unfiltered_tempArr[x];
			}
			tempfiltered=total_temp/10;
			out=0;
			in--;
		}
	}
	 else if(FILTER_TYPE==mean_filter)
	{
		total_temp=total_temp+unfiltered_temp;
		i++;
		if(i==10)
		{
			tempfiltered=total_temp/10;
			i=0;
			total_temp=0;
		}
		
	}
	
	
	}
	u16  TEMP_Fiter_Getter(void)
	{
		return tempfiltered;
	}