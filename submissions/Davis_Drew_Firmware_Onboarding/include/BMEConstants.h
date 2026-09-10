#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    // BME280 I2C addresses.
    constexpr uint8_t I2C_ADDRESS_PRIMARY = 0x76;
    constexpr uint8_t I2C_ADDRESS_SECONDARY = 0x77;

    // Arduino Uno SPI chip-select pin
    constexpr uint8_t SPI_CS_PIN = 10;

    // External LED pin
    constexpr uint8_t LED_PIN = 7;

    // How often we read the temperature sensor
    constexpr unsigned long SENSOR_READ_INTERVAL_MS = 250;

    // Temperature range used by the LED controller
    constexpr float MIN_TEMP_C = 15.0;
    constexpr float MAX_TEMP_C = 35.0;

    // At low temperatures: blink slowly
    constexpr unsigned long SLOW_BLINK_INTERVAL_MS = 1000;

    // At high temperatures: blink quickly
    constexpr unsigned long FAST_BLINK_INTERVAL_MS = 150;
}