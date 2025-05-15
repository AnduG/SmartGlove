#include <Wire.h>
#include "MPU6050.h"

MPU6050::MPU6050(uint8_t mux_channel) {
  _mux_channel = mux_channel;
}

void MPU6050::init() {
  tca9548_select(_mux_channel);
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(PWR_MGMT_1);
  Wire.write(0x00);
  Wire.endTransmission();
}

// void MPU6050::getData(int16_t &x_acc, int16_t &y_acc, int16_t &z_acc, int16_t &x_rot, int16_t &y_rot, int16_t &z_rot) {

// }