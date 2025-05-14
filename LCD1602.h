
#include <LiquidCrystal_I2C.h>

#ifndef LCD_H1602
#define LCD_H1602

#define lcd_address 0x27
#define lcd_cols 16
#define lcd_rows 2
#define lcd_mux_channel 6

extern LiquidCrystal_I2C lcd;

LiquidCrystal_I2C lcd1602_init();

void lcd1602_write_char(uint8_t pos_col, uint8_t pos_row, char c);

void lcd1602_clear()

#endif 