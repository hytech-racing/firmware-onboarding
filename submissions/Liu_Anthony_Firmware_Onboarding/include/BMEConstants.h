#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    constexpr uint8_t BME_ADDRESS = 0x76;
    constexpr uint8_t BME_ADDRESS_ALTERNATE = 0x77;
    constexpr uint8_t CS_PIN = 10;
    constexpr unsigned long SENSOR_READ_INTERVAL_MS = 1000;
}