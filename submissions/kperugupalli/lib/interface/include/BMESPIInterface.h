#pragma once

#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface() = default;
    bool begin();
    float readTemperature();

    // SPI initialization and temperature methods

private:
    // SPI sensor object
    Adafruit_BME280 bme{10};
};

using BMESPIInterfaceInstance =
    etl::singleton<BMESPIInterface>;