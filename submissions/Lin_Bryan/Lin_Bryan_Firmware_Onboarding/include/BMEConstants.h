#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    constexpr uint8_t LED_PIN = 13;
    
    constexpr uint8_t SPI_CS_PIN = 10;
    
    constexpr uint8_t I2C_ADDRESS = 0x76;

    constexpr float TEMP_LOWER_BOUND_C = 25.0f;
    constexpr float TEMP_UPPER_BOUND_C = 30.0f;

    constexpr uint32_t BLINK_SLOW_MS = 1500;
    constexpr uint32_t BLINK_FAST_MS = 100;
}