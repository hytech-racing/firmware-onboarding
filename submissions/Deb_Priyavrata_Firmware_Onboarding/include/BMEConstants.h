#pragma once
#include <Arduino.h> 

namespace BMEConstants {
	constexpr uint8_t i2cLedPin = LED_BUILTIN; // Use the Uno's built-in LED with I2C.
	constexpr uint8_t spiLedPin = 7; // Use pin 7 because SPI clock already uses pin 13.
	constexpr uint8_t i2cAddressPrimary = 0x76; // First common I2C address for BME280 boards.
	constexpr uint8_t i2cAddressSecondary = 0x77; // Alternate address used by some BME280 boards.
	constexpr uint8_t spiChipSelectPin = 10; // Selects the BME280 for SPI communication.
	constexpr unsigned long sensorReadIntervalMs = 1000; // Read a new temperature once per second.
	constexpr float coolestTemperatureC = 0.0f; // Lower end of the temperature-to-speed mapping.
	constexpr float warmestTemperatureC = 40.0f; // Upper end of the temperature-to-speed mapping.
	constexpr unsigned long slowBlinkPeriodMs = 2000; // Full on/off cycle at or below the lower bound.
	constexpr unsigned long fastBlinkPeriodMs = 200; // Full on/off cycle at or above the upper bound.
}