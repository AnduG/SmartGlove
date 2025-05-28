
#include <Wire.h>

#include "TCA9548.h"
#include "LCD1602.h"
#include "MPU6500.h"
#include "interpreter.h"


#define FUNCTION_MODE 2
// FUNCTION_MODE 1 => Learning/Recoding
// FUNCTION_MODE 2 => Interpreting Mode

MPU6500 ref_unit(2);
MPU6500 thumb_unit(7);
MPU6500 index_unit(6);
MPU6500 middle_unit(5);
MPU6500 ring_unit(4);
MPU6500 pinky_unit(3);

#define LED_PIN 26

#define BUTTON_PIN 14
#define DEBOUNCE_THRESHOLD 500

volatile bool buttonPressed = false; 
volatile uint32_t last_interrupt = 0;
int press_count;

void IRAM_ATTR handleButtonInterrupt() {
  uint32_t current = millis();
  if (current - last_interrupt > DEBOUNCE_THRESHOLD) {
    buttonPressed = true;
    last_interrupt = current;
  }
}

void perpare_lcd() {
  lcd1602_init();
  delay(1000);
  lcd1602_test();
}

void prepare_glove() {
  lcd1602_write_string(1, 0, "Get ready for");
  lcd1602_write_string(3, 1, "calibration");
  delay(2000);
  lcd1602_clear();
  lcd1602_write_char(7, 0, '5');
  delay(1000);
  lcd1602_write_char(7, 0, '4');
  delay(1000);
  lcd1602_write_char(7, 0, '3');
  delay(1000);
  lcd1602_write_char(7, 0, '2');
  delay(1000);
  lcd1602_write_char(7, 0, '1');
  delay(1000);
  lcd1602_write_string(1, 0, "Remain still!");
  lcd1602_write_string(1, 1, "Calibrating...");
  ref_unit.init();
  thumb_unit.init();
  index_unit.init();
  middle_unit.init();
  ring_unit.init();
  pinky_unit.init();
  lcd1602_clear();
  lcd1602_write_string(6, 0, "Done!");
}

void seek_i2c_connections() {
  for (uint8_t mux = 0; mux < 8; mux++) {
    tca9548_select(mux);
    for (uint8_t address = 1; address < 127; address++) {
      Wire.beginTransmission(address);
      if (Wire.endTransmission() == 0) {
        Serial.print("Found device at 0x");
        Serial.print(address, HEX);
        Serial.print(" on ");
        Serial.println(mux, HEX);
        delay(10);
      }
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  delay(1000);
  Serial.begin(115200);
  delay(1000);
  tca9548_init();
  delay(1000);
  perpare_lcd();
  delay(2000);
  prepare_glove();

  pinMode(LED_PIN, OUTPUT);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handleButtonInterrupt, FALLING);

  Serial.println("Done.");
  if (FUNCTION_MODE == 1) {
    Serial.println("idx,x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4,x5,y5,z5,x6,y6,z6,letter");
  }
  press_count = 0;
}

void print_angles(MPU6500 &unit) {
  xyzFloat angle = unit.get_data();
  Serial.print(angle.x);
  Serial.print(",");
  Serial.print(angle.y);
  Serial.print(",");
  Serial.print(angle.z);
  Serial.print(",");
}

void record_loop() {
  if (buttonPressed) {
    buttonPressed = false;
    Serial.print(press_count);
    Serial.print(',');
    print_angles(ref_unit);
    print_angles(thumb_unit);
    print_angles(index_unit);
    print_angles(middle_unit);
    print_angles(ring_unit);
    print_angles(pinky_unit);
    press_count++;
    Serial.println();
  }
}

void read_angles(float* data, MPU6500 &unit) {
  xyzFloat angle = unit.get_data();
  data[0] = angle.x;
  data[1] = angle.y;
  data[2] = angle.z;
}

int active_class = -1;
uint32_t active_start = 0;
bool already_used_class = false;

void interpret_loop() {
  float data[INPUTS];
  read_angles(data, ref_unit);
  read_angles(data + 3, thumb_unit);
  read_angles(data + 6, index_unit);
  read_angles(data + 9, middle_unit);
  read_angles(data + 12, ring_unit);
  read_angles(data + 15, pinky_unit);
  int cls = classify(data);
  if (cls != active_class) {
    active_class = cls;
    active_start = millis();
    already_used_class = false;
  } else {
    uint32_t now = millis();
    if (now - active_start > 2000 && !already_used_class) {
      already_used_class = true;
      Serial.println(cls);
      if (cls == -1) {
        digitalWrite(LED_PIN, LOW);
      } else {
        digitalWrite(LED_PIN, HIGH);
      }
      if (cls >= 0 && cls < 26) {
        lcd1602_write_char(translate(cls));
      }
      if (cls == 26) {
        lcd1602_set_first_row();
      }
      if (cls == 27) {
        lcd1602_set_second_row();
      }
      if (cls == 28) {
        lcd1602_clear();
      }
    }
  }
}

void loop() {
  if (FUNCTION_MODE == 1) {
    record_loop();
  } else {
    interpret_loop();
  }
}
