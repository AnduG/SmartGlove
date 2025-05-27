#ifndef LCD_H1602
#define LCD_H1602

#include <LiquidCrystal_I2C.h>

#define LCD_ADDRESS 0x27
#define LCD_COLS 16
#define LCD_ROWS 2

extern LiquidCrystal_I2C lcd;

void lcd1602_init();

void lcd1602_write_char(uint8_t pos_col, uint8_t pos_row, char c);

void lcd1602_write_char(char c);

void lcd1602_write_string(uint8_t pos_col, uint8_t pos_row, const char* s);

void lcd1602_set_first_row();

void lcd1602_set_second_row();

void lcd1602_clear();

void lcd1602_test();

#endif