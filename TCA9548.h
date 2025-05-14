#include <Arduino.h>

#ifndef TCA9548_H
#define TCA9548_H

#define SDA_Pin 21
#define SCL_Pin 22

void tca9548_init();

void tca9548_select(uint8_t i);

#endif