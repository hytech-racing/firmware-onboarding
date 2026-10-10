#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    using celsius = float;

    // I2C: SDA = A4, SCL = A5 on the Uno (hardware Wire)
    constexpr uint8_t I2C_ADDRESS = 0x76; // use 0x77 if your breakout has SDO tied high

    // SPI: SCK = 13, MISO = 12, MOSI = 11 on the Uno (hardware SPI)
    constexpr uint8_t SPI_CS_PIN = 10;

    // LED on pin 8
    constexpr uint8_t LED_PIN = 13;

    constexpr unsigned long SERIAL_BAUD = 115200;
    constexpr unsigned long SENSOR_READ_PERIOD_MS = 250;

    // Temperature -> blink mapping
    constexpr celsius TEMP_MIN_C = 25.0f;  // at or below: slowest blink
    constexpr celsius TEMP_MAX_C = 27.0f;  // at or above: fastest blink
    constexpr unsigned long BLINK_SLOW_MS = 1000;
    constexpr unsigned long BLINK_FAST_MS = 100;
}