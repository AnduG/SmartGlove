
#include <Wire.h>

#include "MPU6500.h"
#include "TCA9548.h"

MPU6500::MPU6500(uint8_t mux_channel) {
  _mux_channel = mux_channel;
  _mpu = new MPU6500_WE(MPU6500_ADDRESS);
}

void MPU6500::init() {
  tca9548_select(_mux_channel);

  _mpu->init();
  _mpu->autoOffsets();

  _mpu->enableGyrDLPF();
  _mpu->setGyrDLPF(MPU6500_DLPF_6);
  _mpu->setGyrRange(MPU6500_GYRO_RANGE_250);

  _mpu->enableAccDLPF(true);
  _mpu->setAccDLPF(MPU6500_DLPF_6);
  _mpu->setAccRange(MPU6500_ACC_RANGE_2G);
}

  xyzFloat MPU6500::get_data() {
    tca9548_select(_mux_channel);
    return _mpu->getAngles();
  }