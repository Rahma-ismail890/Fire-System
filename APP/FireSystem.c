/*
 * FireSystem.c
 *
 * Created: 11/28/2023 5:01:28 AM
 *  Author: Ayman
 */ 
#include "sensors.h"
#include "DIO_interface.h"
#include "motor_interface.h"
#include "BUZZER.h"
#include "LED.h"
#define F_CPU 8000000
#include <util\delay.h>
#include "PasswordSystem.h"
#include "EIU.h"
#include "FireSystem.h"
static u8 fire=0;
 void F(void)
{
	fire=1;
}
void FireSystem(void)
{
	/*EXI_Enable(EX_INT0);
	EXI_TriggerEdge(EX_INT0,RISING_EDGE);
	EXI_SetCallBack(EX_INT0,F);*/

		lcd_clear();
		lcd_set_cursor(0,0);
		lcd_writestring("  Fire System");
		lcd_set_cursor(1,0);
		lcd_writestring("    welcome");
		_delay_ms(200);
		lcd_clear();
		
		while(1)
		{
			
			u16 temp=Temp_read();
			u16 p=pressure_read();
			
			
			if(temp<500&&p<1000&&fire==0)
			{
				Motor_stop(Fun);
				Motor_stop(Pump);
				lcd_set_cursor(0,0);
				lcd_writenumber(temp/10);
				lcd_writechar('.');
				lcd_writenumber(temp%10);
				lcd_writechar('C');
				lcd_writestring("   Fine");
				lcd_writestring("                 ");
				lcd_set_cursor(1,0);
				lcd_writenumber(p/10);
				lcd_writechar('.');
				lcd_writenumber(p%10);
				lcd_writestring("KPa");
				lcd_writestring("                ");
			    LedOff(FireLed);
				LedOff(HeatLed);
				BuzzerOff(Alarm);
			}
			else if(temp>500&&p<1000&&fire==0)
			{
				DIO_writepin(PINB1,low);
				DIO_writepin(PINB2,low);
				lcd_set_cursor(0,0);
				lcd_writenumber(temp/10);
				lcd_writechar('.');
				lcd_writenumber(temp%10);
				lcd_writechar('C');
				lcd_writestring("    Heat");
				lcd_writestring("                 ");
				lcd_set_cursor(1,0);
				lcd_writenumber(p/10);
				lcd_writechar('.');
				lcd_writenumber(p%10);
				lcd_writestring("KPa");
				lcd_writestring("                ");
				LedOn(HeatLed);
				Motor_cw(Fun);
			}
			else if((temp>=500||p>=1000)&&fire==1)
			{
				Motor_stop(Fun);
				Motor_cw(Pump);
				lcd_set_cursor(0,0);
				lcd_writenumber(temp/10);
				lcd_writechar('.');
				lcd_writenumber(temp%10);
				lcd_writechar('C');
				lcd_writestring("     fire");
				lcd_writestring("                 ");
				lcd_set_cursor(1,0);
				lcd_writenumber(p/10);
				lcd_writechar('.');
				lcd_writenumber(p%10);
				lcd_writestring("KPa");
				lcd_writestring("                ");
				  LedOn(FireLed);
				  LedOff(HeatLed);
				  BuzzerOn(Alarm);
			}
			else if(fire==1)
			{
							lcd_set_cursor(0,0);
							lcd_writenumber(temp/10);
							lcd_writechar('.');
							lcd_writenumber(temp%10);
							lcd_writechar('C');
							lcd_writestring("     fire");
							lcd_writestring("                 ");
							lcd_set_cursor(1,0);
							lcd_writenumber(p/10);
							lcd_writechar('.');
							lcd_writenumber(p%10);
							lcd_writestring("KPa");
							lcd_writestring("                ");
			}
				if(fire==1&&temp<500&&p<1000)
				{
					EnterPassword();
					fire=0;
				}
		}
	
}