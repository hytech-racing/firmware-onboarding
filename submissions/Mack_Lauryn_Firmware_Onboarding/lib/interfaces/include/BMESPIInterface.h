#pragma once

#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface() : _sensor(BMEConstants::CS_PIN, &SPI) {}

    bool begin();
    float get_temperature();

private:
    Adafruit_BME280 _sensor;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;