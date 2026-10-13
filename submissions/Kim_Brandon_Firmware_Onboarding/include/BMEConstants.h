#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    constexpr uint8_t LED_PIN = 8;
    constexpr uint8_t BME_CS_PIN = 10;           

    constexpr uint8_t BME_I2C_ADDRESS = 0x77;    

    constexpr uint32_t SERIAL_BAUD = 115200;

    constexpr uint32_t SENSOR_READ_INTERVAL_MS = 500;

    constexpr float MIN_TEMP_C = 20.0f;         
    constexpr float MAX_TEMP_C = 35.0f;         
    constexpr uint32_t SLOWEST_BLINK_MS = 1000;
    constexpr uint32_t FASTEST_BLINK_MS = 100;
}