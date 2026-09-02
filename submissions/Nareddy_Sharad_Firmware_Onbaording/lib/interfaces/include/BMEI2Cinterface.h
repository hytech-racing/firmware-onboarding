#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{
public:
    BMEI2CInterface() = default;

    bool startSensor();
    float readTemperature();

private:
    Adafruit_BME280 sensor; // I2C
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;