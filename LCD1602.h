#ifndef LCD_H1602
#define LCD_H1602

#include <LiquidCrystal_I2C.h>

#define LCD_ADDRESS 0x27
#define LCD_COLS 16
#define LCD_ROWS 2
#define LCD_MUX_CHANNEL 6

extern LiquidCrystal_I2C lcd;

void lcd1602_init();

void lcd1602_write_char(uint8_t pos_col, uint8_t pos_row, char c);

void lcd1602_clear();

#endif