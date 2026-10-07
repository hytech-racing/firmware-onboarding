#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    /* I2C address for BME280 */
    constexpr unsigned char ADDR_I2C = 0x76;

    /* CS pin for BME280 */
    constexpr unsigned char CS_SPI = 10;

    /* LED pin, set to arduino int led */
    constexpr unsigned char LED = LED_BUILTIN;

    /* mapping for blink interval */
    constexpr float TEMP_LOW = 20.0F;
    constexpr unsigned long LOW_IVAL = 1000;

    constexpr float TEMP_HIGH = 30.0F;
    constexpr unsigned long HIGH_IVAL = 500;

    /* random stuff for main */
    constexpr unsigned long SENSOR_UPDATE_IVAL = 500;
}