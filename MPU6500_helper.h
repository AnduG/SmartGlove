// #ifndef MPU6500_HELPER_H
// #define MPU6500_HELPER_H

// #include <cstdint>

// #define POWER_MANAGEMENT 0x6B
// #define USER_CTRL 0x6A

// #define MPU6500_ADDR 0x68
// #define ACC_PRECISION_ADDR 0x1B
// #define GYRO_PRECISION_ADDR 0x1C
// #define FIFO_CONFIG_ADDR 0x23
// #define SAMPLE_RATE_ADDR 0x19

// #define GYRO_FULL_SCALE_250_DPS 0x00 
// #define GYRO_FULL_SCALE_500_DPS 0x08
// #define GYRO_FULL_SCALE_1000_DPS 0x10
// #define GYRO_FULL_SCALE_2000_DPS 0x18

// #define ACC_FULL_SCALE_2_G 0x00 
// #define ACC_FULL_SCALE_4_G 0x08
// #define ACC_FULL_SCALE_8_G 0x10
// #define ACC_FULL_SCALE_16_G 0x18

// #define FIFO_RST 0x04
// #define FIFO_EN 0x40
// #define FIFO_CONFIG 0x78

// float get_gyro_factor(uint8_t gyro_scale);
// float get_acc_factor(uint8_t acc_scale);

// void write_reg(uint8_t reg_addr, uint8_t value);
// void req_data(uint8_t reg_addr, int count);

// void wake_up();
// void set_acc_scale(uint8_t acc_scale);
// void set_gyro_scale(uint8_t gyro_scale);

// void reset_queue();
// void enable_queue();
// void config_queue();

// #endif