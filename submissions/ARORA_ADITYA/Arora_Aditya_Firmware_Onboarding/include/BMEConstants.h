#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    constexpr uint8_t I2C_ADDRESS = 0x76;      
    constexpr uint8_t SPI_CS_PIN = 10;
    constexpr uint8_t LED_PIN = 9;             

    constexpr float TEMP_MIN_C = 20.0f;
    constexpr float TEMP_MAX_C = 35.0f;
    constexpr uint32_t BLINK_SLOW_MS = 1000;   
    constexpr uint32_t BLINK_FAST_MS = 100;    

    constexpr uint32_t SERIAL_BAUD = 115200;
}