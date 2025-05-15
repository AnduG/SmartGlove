#include "LCD1602.h"
#include "TCA9548.h"
#include <Wire.h>

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLS, LCD_ROWS);

void lcd1602_init() {
  tca9548_select(LCD_MUX_CHANNEL);
  lcd.init();
  lcd.clear();
  lcd.setCursor(0, 0);
  delay(25);
}

void lcd1602_write_char(uint8_t pos_col, uint8_t pos_row, char c) {
  if (pos_col >= LCD_COLS || pos_row >= LCD_ROWS) {
    return;
  } 
  tca9548_select(LCD_MUX_CHANNEL);
  lcd.setCursor(pos_col, pos_row);
  lcd.print(c);
}

void lcd1602_clear() {
  tca9548_select(LCD_MUX_CHANNEL);
  lcd.clear();
  lcd.setCursor(0, 0);
}