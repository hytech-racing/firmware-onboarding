#pragma once
#include <Arduino.h>
namespace BMEConstants
{
    const int8_t the_cspin = 10; 
    const int8_t led_pin = 13;
    const float max_temp = 30;
    const float min_temp = 25;
    const unsigned long max_int = 1000;
    const unsigned long min_int = 100;
    const unsigned long read_interval = 700;
    const uint8_t i2c_address = 0x76; // address for the bme280
 // constants here!
}