
// #include <Wire.h>
// #include <math.h>

// #include "MPU6500_snap.h"
// #include "MPU6500_helper.h"
// #include "TCA9548.h"

// MPU6500::MPU6500(uint8_t mux_channel, float default_x, float default_y, float default_z) {
//   _mux_channel = mux_channel;
//   _acc_scale = ACC_FULL_SCALE_2_G;
//   _gyro_scale = GYRO_FULL_SCALE_250_DPS;
//   _alpha = 0.98;
//   pitch = 0;
//   roll = 0;
//   _default_x = default_x;
//   _default_y = default_y;
//   _default_z = default_z;
//   _gyro_bias_x = 0;
//   _gyro_bias_y = 0;
//   _gyro_bias_z = 0;
// }

// void MPU6500::set_sample_rate(uint16_t sample_rate) {
//   uint8_t div = (1000 / sample_rate) - 1;
//   write_reg(SAMPLE_RATE_ADDR, div);
//   _sample_rate = sample_rate;
// }

// void MPU6500::calibrate_gyro() {
//   float sum_x = 0, sum_y = 0, sum_z = 0;
//   int samples = 500;
//   int dt = round(1000 / _sample_rate);
//   for (int i = 0; i < samples; i++) {
//     fetch_set();  // or raw gyro read
//     sum_x += x_rot;
//     sum_y += y_rot;
//     sum_z += z_rot;
//     delay(dt);  // sample every 2ms
//   }
//   _gyro_bias_x = sum_x / samples;
//   _gyro_bias_y = sum_y / samples;
//   _gyro_bias_z = sum_z / samples;
//   Serial.println(_gyro_bias_x);
//   Serial.println(_gyro_bias_y);
//   Serial.println(_gyro_bias_z);
// }

// void MPU6500::reset_pos() {
//   x_pos = _default_x;
//   y_pos = _default_y;
//   z_pos = _default_z;
// }

// void MPU6500::reset_vel() {
//   _vel_x = 0;
//   _vel_y = 0;
//   _vel_z = 0;
// }

// void MPU6500::init(uint16_t sample_rate) {
//   tca9548_select(_mux_channel);

//   wake_up();

//   set_acc_scale(_acc_scale);
//   set_gyro_scale(_gyro_scale);
//   set_sample_rate(sample_rate);

//   reset_queue();
//   enable_queue();
//   config_queue();

//   reset_pos();
//   reset_vel();

//   delay(100);
// }

// bool get_queue_dim(uint16_t &dim) {
//   req_data(FIFO_COUNT_ADDR, 2);
//   if (Wire.available() >= 2) {
//     dim = ((Wire.read() << 8) | (Wire.read()));
//     return true;
//   }
//   return false;
// }

// bool MPU6500::fetch_set() {
//   float acc_factor = get_acc_factor(_acc_scale);
//   float gyro_factor = get_gyro_factor(_gyro_scale);
//   req_data(FIFO_HEAD_ADDR, 12);
//   if (Wire.available() == 12) {
//     x_acc = (int16_t)((Wire.read() << 8) | Wire.read()) / acc_factor;
//     y_acc = (int16_t)((Wire.read() << 8) | Wire.read()) / acc_factor;
//     z_acc = (int16_t)((Wire.read() << 8) | Wire.read()) / acc_factor;
//     x_rot = (int16_t)((Wire.read() << 8) | Wire.read()) / gyro_factor;
//     y_rot = (int16_t)((Wire.read() << 8) | Wire.read()) / gyro_factor;
//     z_rot = (int16_t)((Wire.read() << 8) | Wire.read()) / gyro_factor;

//     x_rot -= _gyro_bias_x;
//     y_rot -= _gyro_bias_y;
//     z_rot -= _gyro_bias_z;

//     return true;
//   }
//   return false;
// }

// bool MPU6500::filter_set(float dt) {
//   if (dt <= 0) {
//     return false;
//   }

//   float acc_pitch = atan2(y_acc, sqrt(x_acc * x_acc + z_acc * z_acc)) * 180.0 / PI;
//   float acc_roll = atan2(-x_acc, z_acc) * 180.0 / PI;

//   pitch = _alpha * (pitch + x_rot * dt) + (1.0 - _alpha) * acc_pitch;
//   roll = _alpha * (roll + y_rot * dt) + (1.0 - _alpha) * acc_roll;
//   return true;
// }

// void MPU6500::process_set(float dt) {
//   float g_x_acc = x_acc * 9.81;
//   float g_y_acc = y_acc * 9.81;
//   float g_z_acc = z_acc * 9.81;

//   float pitch_rad = pitch * PI / 180.0;
//   float roll_rad = roll * PI / 180.0; 

//   float stan_x_acc = g_x_acc;
//   float stan_y_acc = g_y_acc * cos(roll_rad) + g_z_acc * sin(roll_rad);
//   float stan_z_acc = g_z_acc * cos(pitch_rad) - g_y_acc * sin(pitch_rad) - 9.81;

//   _vel_x += stan_x_acc * dt;
//   _vel_y += stan_y_acc * dt;
//   _vel_z += stan_z_acc * dt;

//   float drag = 0.98;
//   _vel_x *= drag;
//   _vel_y *= drag;
//   _vel_z *= drag;
  
//   x_pos += _vel_x * dt;
//   y_pos += _vel_y * dt;
//   z_pos += _vel_z * dt;
// }

// void MPU6500::get_data() {
//   tca9548_select(_mux_channel);

//   uint16_t fifo_count;
//   float dt = 1.0f / _sample_rate;

//   if(!get_queue_dim(fifo_count)) {
//     return;
//   }

//   for (uint16_t i = 0; i < fifo_count / 12; i++) {
//     if(fetch_set()) {
//       if(filter_set(dt)) {
//         process_set(dt);
//       }
//     }
//   }
// }