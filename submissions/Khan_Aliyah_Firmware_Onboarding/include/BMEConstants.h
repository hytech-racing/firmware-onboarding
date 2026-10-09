#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    constexpr uint8_t LED_PIN = LED_BUILTIN;
    constexpr uint8_t BME_I2C_ADDRESS = 0x76;

    constexpr unsigned long MIN_BLINK_INTERVAL = 100;
    constexpr unsigned long MAX_BLINK_INTERVAL = 1000;
}