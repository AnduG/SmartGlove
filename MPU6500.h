#ifndef MPU6500_H
#define MPU6500_H

#include <MPU6500_WE.h>

#define MPU6500_ADDRESS 0x68

class MPU6500 {
public:
  MPU6500(uint8_t mux_channel);

  void init();
  xyzFloat get_data();

private:
  uint8_t _mux_channel;
  MPU6500_WE* _mpu;
};

#endif