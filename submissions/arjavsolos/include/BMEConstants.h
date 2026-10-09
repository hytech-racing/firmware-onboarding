#pragma once

#include <Arduino.h>

namespace BMEConstants
{
constexpr uint8_t I2C_ADDRESS = 0x76;

constexpr uint8_t SPI_CS_PIN = 10;

constexpr uint8_t LED_PIN = 6;

constexpr float MIN_TEMPERATURE_C = 0.0F;
constexpr float MAX_TEMPERATURE_C = 40.0F;
constexpr unsigned long SLOW_BLINK_INTERVAL_MS = 1500UL;
constexpr unsigned long FAST_BLINK_INTERVAL_MS = 150UL;

constexpr unsigned long SENSOR_READ_INTERVAL_MS = 500UL;
}
