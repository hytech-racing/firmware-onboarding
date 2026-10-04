#pragma once

#include <Adafruit_BME280.h> 
#include "BMEConstants.h" 

class BMESPIInterface {
public:
	BMESPIInterface(); // Configures the Adafruit driver to use SPI and the sensor's chip-select pin.
	bool begin(); // Initializes the BME280 over SPI and reports whether it responded.
	float readTemperatureC(); // Returns the most recently measured temperature in Celsius.

private:
	Adafruit_BME280 sensor; // The Adafruit driver object used for SPI operations.
};
