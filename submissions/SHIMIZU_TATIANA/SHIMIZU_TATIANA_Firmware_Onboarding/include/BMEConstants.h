#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    // On-board LED pin
    constexpr uint8_t LED_PIN = 13;

    // SPI Hardware Pin Definitions for Arduino Uno
    constexpr uint8_t BME_CS_PIN   = 10;
    constexpr uint8_t BME_MOSI_PIN = 11;
    constexpr uint8_t BME_MISO_PIN = 12;
    constexpr uint8_t BME_SCK_PIN  = 13;

    // Default I2C Address for BME280 breakout boards (often 0x76 or 0x77)
    constexpr uint8_t BME_I2C_ADDR = 0x76;

    // Temperature bounds for LED blink scaling (in Celsius)
    constexpr float TEMP_MIN_C = 25.0f;
    constexpr float TEMP_MAX_C = 27.0f;

    // Blink period limits in milliseconds (faster blink = smaller period)
    constexpr unsigned long BLINK_PERIOD_SLOW_MS = 1000;
    constexpr unsigned long BLINK_PERIOD_FAST_MS = 100;
}