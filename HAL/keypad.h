/*
 * keybad.h
 *
 * Created: 04/10/2023 08:39:02 م
 *  Author: JOBA
 */ 
#include "stand_type.h"

#ifndef KEYBAD_H_
#define KEYBAD_H_

#define   first_output     PINB4
#define   first_input      PIND0
#define   column           4
#define   row              4
#define   default   'T'

void keypad_int(void);
u8 keypad_getkey(void);
#endif /* KEYBAD_H_ */