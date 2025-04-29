
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void lcd_int(void);
void lcd_writechar(u8 ch);
void lcd_clear(void);
void lcd_writenumber(s16 num);
void lcd_writeLongNumber(s32 num);
void lcd_writestring(str8 str);
void lcd_set_cursor(u8 line, u8 cell);
void lcd_writebinary(u8 num);
void lcd_writehex(u16 num);
void print_ascii(u8 ch);
void lcd_clearcell(u8 line ,u8 cell ,u8 num);
#endif /* LCD_INTERFACE_H_ */