#include "TCA9548.h"
#include <Wire.h>

void tca9548_init() {
  Wire.begin(SDA_Pin, SCL_Pin);
}

void tca9548_select(uint8_t i) {
  if (i > 7) return;
  Wire.beginTransmission(0x70);
  Wire.write(1 << i);
  Wire.endTransmission();
}
