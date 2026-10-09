#pragma once

#include <Arduino.h>

namespace BMEConstants
{
// BME280 I2C modules commonly use 0x76 or 0x77. Change this if your board
// uses the other address.
constexpr uint8_t I2C_ADDRESS = 0x76;

// Arduino Uno hardware-SPI pins are fixed: MOSI=11, MISO=12, SCK=13.
constexpr uint8_t SPI_CS_PIN = 10;

// Use an external LED and a 220-330 ohm resistor. LED_BUILTIN is pin 13,
// which conflicts with the SPI clock on the Uno.
constexpr uint8_t LED_PIN = 6;

// Temperatures at or below MIN blink slowly; temperatures at or above MAX
// blink quickly. Values between them are mapped linearly.
constexpr float MIN_TEMPERATURE_C = 0.0F;
constexpr float MAX_TEMPERATURE_C = 40.0F;
constexpr unsigned long SLOW_BLINK_INTERVAL_MS = 1500UL;
constexpr unsigned long FAST_BLINK_INTERVAL_MS = 150UL;

constexpr unsigned long SENSOR_READ_INTERVAL_MS = 500UL;
} // namespace BMEConstants
