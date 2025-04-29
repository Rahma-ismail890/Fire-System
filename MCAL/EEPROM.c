/*
 * EEPROM.c
 *
 * Created: 12/10/2023 01:48:47 م
 *  Author: JOBA
 */ 
#include "memory.h"
#include "stand_type.h"
#include "utilt.h"
#include "EEPROM.h"

void EEPROM_write(u16 address,u8 data)
{
	while(READ_BIT(EECR,EEWE));
	EEARL=address;
	EEDR=data;
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
}

u8 EEPROM_read(u16 address)
{
	while(READ_BIT(EECR,EEWE));
	EEARL=address;
	SET_BIT(EECR,EERE);
	u8 data=EEDR;
}