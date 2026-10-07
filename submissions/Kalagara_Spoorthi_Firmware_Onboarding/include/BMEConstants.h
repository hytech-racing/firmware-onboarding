#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    constexpr uint8_t BME_I2C_ADDRESS = 0x76;
    constexpr uint8_t BME_CS_PIN = 5;
    constexpr uint8_t LED_PIN = LED_BUILTIN;
}