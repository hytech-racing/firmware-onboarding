#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface();

    // Initializes the sensor over hardware SPI
    bool begin();

    // Reads and returns the ambient temperature in Celsius
    float read_temperature();

private:
    Adafruit_BME280 bme_;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;