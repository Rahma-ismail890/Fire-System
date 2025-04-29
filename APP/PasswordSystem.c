/*
 * PasswordSystem.c
 *
 * Created: 11/29/2023 8:42:00 AM
 *  Author: Ayman
 */
#include "stand_type.h"
#include "EEPROM.h"
#include "lcd_interface.h"
#include "keypad.h"
#define F_CPU 8000000
#include <util\delay.h>
#include "PasswordSystem.h"
static u8 password[4]={'1','2','3','4'}; 
void passwordSystem(void)
{
	
		u8 arr[4],flag=0;
		password[0]=EEPROM_read(0)+'0';
		password[1]=EEPROM_read(1)+'0';
		password[2]=EEPROM_read(2)+'0';
		password[3]=EEPROM_read(3)+'0';

		u8 key=default;
		lcd_set_cursor(0,0);
		lcd_writestring("1-Enter password");
		lcd_set_cursor(1,0);
		lcd_writestring("2-change password");
		
		_delay_ms(300);
		u8 p=0,i=0,error=0,pc=0,c=0;
		while(flag==0)
		{
			key=keypad_getkey();
			if(key!=default)
			{
				if(p==1)
				{
					arr[i]=key;
					i++;
					lcd_writechar(key);
					
					if(i==4)
					{
						
						_delay_ms(200);
						for(u8 x=0;x<4;x++)
						{
							if(password[x]!=arr[x])
							{
								error=1;
							}
						}
						if(error==1)
						{
							lcd_clear();
							lcd_writestring("wrong password");
							lcd_set_cursor(1,0);
							lcd_writestring("Try Again");
							_delay_ms(300);
							key='1';
							p=0;
							i=0;
							c++;
							error=0;
							if(c==3)
							{
								lcd_clear();
								lcd_writestring("Try After 1h");
								_delay_ms(3600000);
							}
						}
						else
						{
							lcd_clear();
							lcd_writestring("correct password");
							_delay_ms(200);
							flag=1;
						}
					}
				}
				
				
				
				if(key=='1'&&p==0&&pc==0)
				{
					p=1;
					lcd_clear();
					lcd_set_cursor(0,0);
					lcd_writestring("Enter password");
					lcd_set_cursor(1,0);
					key=default;
				}
				if(pc==1)
				{
					arr[i]=key-'0';
					i++;
					lcd_writechar(key);
					if(i==4)
					{
						for(u8 x=0;x<4;x++)
						{
							EEPROM_write(x,arr[x]);
						}
						_delay_ms(200);
						lcd_clear();
						lcd_writestring("New password is");
						lcd_set_cursor(1,0);
						for(u8 x=0;x<4;x++)
						{
							lcd_writenumber(arr[x]);
						}
						_delay_ms(500);
						flag=1;
					}
				}
				if(key=='2'&&p==0&&pc==0)
				{
					pc=1;
					lcd_clear();
					lcd_set_cursor(0,0);
					lcd_writestring("Change password");
					lcd_set_cursor(1,0);
					key=default;
				}
			}
			
		}
}

void EnterPassword(void)
{
	u8 arr[4],flag=0;
	password[0]=EEPROM_read(0)+'0';
	password[1]=EEPROM_read(1)+'0';
	password[2]=EEPROM_read(2)+'0';
	password[3]=EEPROM_read(3)+'0';
	u8 key=default;
	lcd_clear();
	lcd_set_cursor(0,0);
	lcd_writestring("Enter password");
	lcd_set_cursor(1,0);
			u8 i=0,error=0,c=0;
			while(flag==0)
			{
				key=keypad_getkey();
				if(key!=default)
				{
						arr[i]=key;
						i++;
						lcd_writechar(key);
						
						if(i==4)
						{
							
							_delay_ms(500);
							for(u8 x=0;x<4;x++)
							{
								if(password[x]!=arr[x])
								{
									error=1;
								}
							}
							if(error==1)
							{
								lcd_clear();
								lcd_writestring("wrong password");
								lcd_set_cursor(1,0);
								lcd_writestring("Try Again");
								_delay_ms(500);
									lcd_set_cursor(0,0);
									lcd_writestring("Enter password");
									lcd_set_cursor(1,0);
								i=0;
								c++;
								error=0;
								if(c==3)
								{
									lcd_clear();
									lcd_writestring("Try After 1h");
									_delay_ms(3600000);
								}
							}
							else
							{
								lcd_clear();
								lcd_writestring("correct password");
								_delay_ms(500);
								flag=1;
							}
						}
				}
			}
					
}

void ChangePassword(void)
{
	
}