
#include <Wire.h>

#include "LCD1602.h"

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLS, LCD_ROWS);

  void lcd1602_init() {
    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0, 0);
    delay(25);
  }

  void lcd1602_write_char(uint8_t pos_col, uint8_t pos_row, char c) {
    if (pos_col >= LCD_COLS || pos_row >= LCD_ROWS) {
      return;
    } 
    lcd.setCursor(pos_col, pos_row);
    lcd.print(c);
  }

  void lcd1602_write_char(char c) {
    lcd.write(c);
  }

  void lcd1602_write_string(uint8_t pos_col, uint8_t pos_row, const char* s) {
    lcd.setCursor(pos_col, pos_row);
    lcd.print(s);
  }

  void lcd1602_set_first_row() {
    lcd.setCursor(0, 0);
  }

  void lcd1602_set_second_row() {
    lcd.setCursor(0, 1);
  }

  void lcd1602_test() {
    lcd.setCursor(2, 0);
    lcd.print("Booting up!");
  }

  void lcd1602_clear() {
    lcd.clear();
    lcd.setCursor(0, 0);
  }