#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    constexpr float TEMP_MIN = 20.0f;
    constexpr float TEMP_MAX = 35.0f;
    constexpr unsigned long INTERVAL_MIN = 100;  // Fast blink when hot
    constexpr unsigned long INTERVAL_MAX = 1000; // Slow blink when cool
    constexpr uint8_t LED_PIN = LED_BUILTIN;
}