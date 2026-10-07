#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    // Serial
    constexpr uint32_t SERIAL_BAUD = 115200; 

    // I2C
    constexpr uint8_t I2C_ADDRESS = 0x77;

    // SPI (CS Pin)
    // SCK = 13, MISO = 12, MOSI = 11
    constexpr int8_t SPI_CS_PIN = 10;

    // LED
    constexpr uint8_t LED_PIN = 7;

    // Temperature 
    constexpr float TEMP_COLD_C = 20.0f;              // lowest
    constexpr float TEMP_HOT_C = 35.0f;               // highest
    //blink slow 
    constexpr uint32_t BLINK_INTERVAL_SLOW_MS = 1000; 
    //blink fast
    constexpr uint32_t BLINK_INTERVAL_FAST_MS = 100;  

    // Timing
    constexpr uint32_t SAMPLE_PERIOD_MS = 100; 
    constexpr uint32_t PRINT_PERIOD_MS = 500;  
}