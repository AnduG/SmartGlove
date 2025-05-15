#ifndef MPU6050_H
#define MPU6050_H

#include "TCA9548.h"

#define MPU6050_ADDRESS 0x68
#define PWR_MGMT_1 0x6B
#define ACCEL_XOUT_H 0x3B

class MPU6050 {
public:
  MPU6050(uint8_t mux_channel);

  void init();

  // void getData(int16_t &x_acc, int16_t &y_acc, int16_t &z_acc, int16_t &x_rot, int16_t &y_rot, int16_t &z_rot);

private:
  uint8_t _mux_channel;
};

#endif