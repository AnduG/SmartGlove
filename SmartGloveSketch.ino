#include <Wire.h>

#include "TCA9548.h"
#include "LCD1602.h"
#include "MPU6050.h"

// MPU6050 test_unit(7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  Serial.println("starts!");
  Serial.println("starts!");
  Serial.println("starts!");
  tca9548_init();
  delay(1000);
  Serial.println("Past tca!");
  Serial.println("Past tca!");
  Serial.println("Past tca!");
  // lcd1602_init();
  // delay(1000);
  // Serial.println("Past lcd!");
  // Serial.println("Past tca!");
  // Serial.println("Past tca!");
  // test_unit.init();

  Wire.beginTransmission(0x70);
  if (Wire.endTransmission() == 0) {
    Serial.print("Found device at 0x70");
  }
  // for (uint8_t mux = 0; mux < 8; mux++) {
  //   // tca9548_select(mux);
  //   for (uint8_t address = 1; address < 127; address++) {
  //     Wire.beginTransmission(address);
  //     if (Wire.endTransmission() == 0) {
  //       Serial.print("Found device at 0x");
  //       Serial.print(address, HEX);
  //       Serial.print(" on ");
  //       Serial.println(mux, HEX);
  //       delay(10);
  //     }
  //   }
  // }
  Serial.println("Done.");


  // Wire.beginTransmission(MPU6050_ADDRESS);
  // Wire.write(0x75);
  // Wire.endTransmission(false);

  // Wire.requestFrom(MPU6050_ADDRESS, 1);
  // if (Wire.available()) {
  //   char id = Wire.read();
  //   Serial.println(id, HEX);
  // }
}

void loop() {
  // put your main code here, to run repeatedly:

}
