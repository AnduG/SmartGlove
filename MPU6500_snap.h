
// #ifndef MPU6500_H
// #define MPU6500_H

// #define FIFO_COUNT_ADDR 0x72
// #define FIFO_HEAD_ADDR 0x74

// class MPU6500 {
// public:
//   MPU6500(uint8_t mux_channel, float default_x, float default_y, float default_z);

//   void init(uint16_t sample_rate);
//   void calibrate_gyro();
//   void get_data();

//   float x_acc;
//   float y_acc;
//   float z_acc;
//   float x_rot;
//   float y_rot;
//   float z_rot;

//   float pitch;
//   float roll;

//   float x_pos;
//   float y_pos;
//   float z_pos;

// private:
//   void set_sample_rate(uint16_t sample_rate);

//   void reset_pos();
//   void reset_vel();

//   bool fetch_set();
//   bool filter_set(float dt);
//   void process_set(float dt);

//   uint8_t _mux_channel;

//   uint8_t _gyro_scale;
//   uint8_t _acc_scale;

//   float _sample_rate;
//   float _alpha;

//   float _gyro_bias_x;
//   float _gyro_bias_y;
//   float _gyro_bias_z;

//   float _default_x;
//   float _default_y;
//   float _default_z;

//   float _vel_x;
//   float _vel_y;
//   float _vel_z;
// };

// #endif