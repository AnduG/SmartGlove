#include "LCD1602.h"
#include "TCA9548.h"
#include <Wire.h>

LiquidCrystal_I2C lcd(lcd_address, lcd_cols, lcd_rows);

void lcd1602_init() {
  tca9548_select(lcd_mux_channel);
  lcd.begin();
  lcd.clear();
  lcd.setCursor(0, 0);
  delay(25);
}

void lcd1602_write_char(uint8_t pos_col, uint8_t pos_row, char c) {
  tca9548_select(lcd_mux_channel);
  lcd.setCursor(pos_col, pos_row);
  lcd.print(c);
}

void lcd1602_clear() {
  tca9548_select(lcd_mux_channel);
  lcd.clear();
  lcd.setCursor(0, 0);
}