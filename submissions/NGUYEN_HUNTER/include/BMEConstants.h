#pragma once
#include <stdint.h>

namespace BMEConstants {
constexpr uint32_t SERIAL_BAUD = 115200;
constexpr uint8_t I2C_ADDRESS = 0x76; // Set to 0x77 if the breakout's SDO is high.
constexpr uint8_t SPI_CS_PIN = 10;
// An external LED avoids Uno D13, which is also the SPI clock.
constexpr uint8_t LED_PIN = 8;
constexpr uint32_t SAMPLE_INTERVAL_MS = 250;
constexpr uint32_t RETRY_INTERVAL_MS = 2000;
constexpr float MIN_SENSOR_TEMPERATURE_C = -40.0f;
constexpr float MAX_SENSOR_TEMPERATURE_C = 85.0f;
constexpr float COLD_TEMPERATURE_C = 0.0f;
constexpr float HOT_TEMPERATURE_C = 50.0f;
constexpr uint32_t SLOW_HALF_PERIOD_MS = 1000;
constexpr uint32_t FAST_HALF_PERIOD_MS = 100;
}
