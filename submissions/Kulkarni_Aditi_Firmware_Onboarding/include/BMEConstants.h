#pragma once
#include <Arduino.h>
namespace BMEConstants
{
    constexpr uint8_t LED_PIN = LED_BUILTIN;
    constexpr uint8_t I2C_ADDRESS = 0x76;
    constexpr uint8_t SPI_CS_PIN = 10;
    constexpr unsigned long SERIAL_BAUD = 115200;
    constexpr unsigned long SAMPLE_INTERVAL_MS = 500;
    constexpr float COOL_TEMP_C = 15.0f;
    constexpr float HOT_TEMP_C = 35.0f;
    constexpr unsigned long SLOW_BLINK_MS = 1000;
    constexpr unsigned long FAST_BLINK_MS = 100;
}