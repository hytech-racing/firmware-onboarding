#pragma once

#include <Arduino.h>

namespace BMEConstants
{
    constexpr uint8_t BME_CS_PIN = 10;

    constexpr uint8_t LED_PIN = LED_BUILTIN;

    constexpr float MIN_TEMP = 23.0;
    constexpr float MAX_TEMP = 28.0;

    constexpr unsigned long SLOW_BLINK_MS = 1000;
    constexpr unsigned long FAST_BLINK_MS = 100;
}