#pragma once

#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

// Handles communication with the BME280 over SPI
class BMESPIInterface
{
public:
    BMESPIInterface() = default;

    bool begin();
    float readTemperature();

private:
    Adafruit_BME280 bme{10};
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;