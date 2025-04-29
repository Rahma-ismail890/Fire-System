/*
 * EEPROM.h
 *
 * Created: 12/10/2023 01:48:25 م
 *  Author: JOBA
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

u8 EEPROM_read(u16 address);

void EEPROM_write(u16 address,u8 data);

#endif /* EEPROM_H_ */