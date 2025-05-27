
#ifndef TCA9548_H
#define TCA9548_H

#include <Arduino.h>

#define SDA_PIN 21
#define SCL_PIN 22

void tca9548_init();

void tca9548_select(uint8_t i);

#endif