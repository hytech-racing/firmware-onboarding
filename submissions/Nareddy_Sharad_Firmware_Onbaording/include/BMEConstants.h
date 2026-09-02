#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    constexpr uint8_t I2C_ADDRESS = 0x76; // I2C address of the BME280 sensor
    constexpr uint8_t SPI_CS_PIN  = 10; // SPI chip select pin for the BME280 sensor
    
}