#include "DIO_interface.h"
#include "stand_type.h"
#include "lcd_interface.h"
#include "lcd_confg.h"
#include "utilt.h"
#define F_CPU 8000000
#include <util\delay.h>

static void writeIns(u8 value)
{
		DIO_writepin(RS,low);
		DIO_writepin(PINA6,READ_BIT(value,7));
		DIO_writepin(PINA5,READ_BIT(value,6));
		DIO_writepin(PINA4,READ_BIT(value,5));
		DIO_writepin(PINA3,READ_BIT(value,4));
		DIO_writepin(EN,high);
		_delay_ms(1);
		DIO_writepin(EN,low);
		_delay_ms(1);
		DIO_writepin(RS,low);
		DIO_writepin(PINA6,READ_BIT(value,3));
		DIO_writepin(PINA5,READ_BIT(value,2));
		DIO_writepin(PINA4,READ_BIT(value,1));
		DIO_writepin(PINA3,READ_BIT(value,0));
		DIO_writepin(EN,high);
		_delay_ms(1);
		DIO_writepin(EN,low);
		_delay_ms(1);
	
}
static void lcd_write_data(u8 value)
{
	
	DIO_writepin(RS,high);
	DIO_writepin(PINA6,READ_BIT(value,7));
	DIO_writepin(PINA5,READ_BIT(value,6));
	DIO_writepin(PINA4,READ_BIT(value,5));
	DIO_writepin(PINA3,READ_BIT(value,4));
	DIO_writepin(EN,high);
	_delay_ms(1);
	DIO_writepin(EN,low);
	_delay_ms(1);
		DIO_writepin(RS,high);
	DIO_writepin(PINA6,READ_BIT(value,3));
	DIO_writepin(PINA5,READ_BIT(value,2));
	DIO_writepin(PINA4,READ_BIT(value,1));
	DIO_writepin(PINA3,READ_BIT(value,0));
		DIO_writepin(EN,high);
		_delay_ms(1);
		DIO_writepin(EN,low);
		_delay_ms(1);
}
void lcd_int(void)
{
	_delay_ms(50);
	writeIns(0x02);
	writeIns(0x28);
	writeIns(0x0c);
	writeIns(0x01);
	_delay_ms(1);
	writeIns(0x06);
	
}
void lcd_writechar(u8 ch)
{
	lcd_write_data(ch);
}
void lcd_clear(void)
{
		writeIns(0x01);
		_delay_ms(1);
}

void lcd_writenumber(s16 num)
{
	u8 flag=0;
	if(num<0)
	{
		num=num*(-1);
		flag=1;
	}
	u16 i=0;
	u8 arr[20];
	while(num)
	{
		arr[i]=num%10+'0';
		num=num/10;
		i++;	
	}
	if(flag==1)
	{
		arr[i]='-';
		i++;
	}
	for(s16 x=i-1;x>=0;x--)
	{
		lcd_writechar(arr[x]);
	}
}
void lcd_writeLongNumber(s32 num)
{
	u8 flag=0;
	if(num<0)
	{
		num=num*(-1);
		flag=1;
	}
	u16 i=0;
	u8 arr[20];
	while(num)
	{
		arr[i]=num%10+'0';
		num=num/10;
		i++;
	}
	if(flag==1)
	{
		arr[i]='-';
		i++;
	}
	for(s16 x=i-1;x>=0;x--)
	{
		lcd_writechar(arr[x]);
	}
}
void lcd_writestring(str8 str)
{
	for(int i=0;str[i];i++)
	{
		lcd_writechar(str[i]);
	}
}

void lcd_set_cursor(u8 line, u8 cell)//first line 0 ,second line 1
{
	if(line==0)
	{
		writeIns(0x80|cell);
	}
	if(line==1)
	{
		writeIns(0x80|0x40|cell);
	}
}
void lcd_writebinary(u8 num)
{
	
	s8 i=7;
	u8 f=0;
	
	while(i>=0)
	{
		if((READ_BIT(num,i)!=0)&&f==0)
		{
			f=1;
		}
		if(f==1)
		{
			lcd_writechar(READ_BIT(num,i)+'0');
			
		}
		i--;
		
	}
	
}
void lcd_writehex(u16 num)
{
	u8 arr[10];
	u8 i=0;
	while (num)
	{
		u8 r=num%16;
		num=num/16;
		if(r==15)
		{
			r='F';
		}
		else if(r==14)
		{
			r='E';
		}
		else if(r==13)
		{
			r='D';
		}
		else if(r==12)
		{
			r='C';
		}
		else if(r==11)
		{
			r='B';
		}
		else if(r==10)
		{
			r='A';
		}
		else
		{
			r=r+'0';
		}
		arr[i]=r;
		i++;
	}
        for(s16 x=i-1;x>=0;x--)
        {
	        lcd_writechar(arr[x]);
        }	
}
void print_ascii(u8 ch)
{
	lcd_writenumber(ch);
}
void lcd_clearcell(u8 line ,u8 cell ,u8 num)
{
	lcd_set_cursor(line,cell);
	for(u8 i=0;i<num;i++)
	{
		lcd_writechar(' ');
	}
}