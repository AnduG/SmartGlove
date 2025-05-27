
// #include <Wire.h>

// #include "MPU6500_helper.h"

// float get_acc_factor(uint8_t acc_scale) {
//   switch(acc_scale) {
//     case ACC_FULL_SCALE_2_G:
//       return 16384;
//     case ACC_FULL_SCALE_4_G:
//       return 8192;
//     case ACC_FULL_SCALE_8_G:
//       return 4096;
//     case ACC_FULL_SCALE_16_G:
//       return 2048;
//   }
// }

// float get_gyro_factor(uint8_t gyro_scale) {
//   switch(gyro_scale) {
//     case GYRO_FULL_SCALE_250_DPS:
//       return 131;
//     case GYRO_FULL_SCALE_500_DPS:
//       return 65.5;
//     case GYRO_FULL_SCALE_1000_DPS:
//       return 32.8;
//     case GYRO_FULL_SCALE_2000_DPS:
//       return 16.4;
//   }
// }

// void write_reg(uint8_t reg_addr, uint8_t value) {
//   Wire.beginTransmission(MPU6500_ADDR);
//   Wire.write(reg_addr);
//   Wire.write(value);
//   Wire.endTransmission();
//   delay(5);
// }

// void req_data(uint8_t reg_addr, int count) {
//   Wire.beginTransmission(MPU6500_ADDR);
//   Wire.write(reg_addr);
//   Wire.endTransmission(false);
//   Wire.requestFrom(MPU6500_ADDR, count);
// }

// void wake_up() {
//   write_reg(POWER_MANAGEMENT, 0x00);
// }

// void set_acc_scale(uint8_t acc_scale) {
//   write_reg(ACC_PRECISION_ADDR, acc_scale);
// }

// void set_gyro_scale(uint8_t gyro_scale) {
//   write_reg(GYRO_PRECISION_ADDR, gyro_scale);
// }

// void reset_queue() {
//   write_reg(USER_CTRL, FIFO_RST);
// }

// void enable_queue() {
//   write_reg(USER_CTRL, FIFO_EN);
// }

// void config_queue() {
//   write_reg(FIFO_CONFIG_ADDR, (0x08 | 0x10 | 0x20 | 0x40)); // enables ACCEL, GYRO X, GYRO Y GYRO Z
// }