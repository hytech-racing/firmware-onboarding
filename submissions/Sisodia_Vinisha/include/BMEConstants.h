#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    constexpr uint8_t SPI_CS_PIN = 10;
    constexpr uint8_t LED_PIN = LED_BUILTIN;
    constexpr float MIN_TEMPERATURE = 15.0f;
    constexpr float MAX_TEMPERATURE = 35.0f;

    constexpr unsigned long SLOW_BLINK_INTERVAL_MS = 1000;
    constexpr unsigned long FAST_BLINK_INTERVAL_MS = 100;
}