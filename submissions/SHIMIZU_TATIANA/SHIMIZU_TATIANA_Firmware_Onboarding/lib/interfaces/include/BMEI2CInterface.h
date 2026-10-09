#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{
public:
    BMEI2CInterface() = default;

    // Initializes the sensor over I2C
    bool begin();

    // Reads and returns the ambient temperature in Celsius
    float read_temperature();

private:
    Adafruit_BME280 bme_;
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;