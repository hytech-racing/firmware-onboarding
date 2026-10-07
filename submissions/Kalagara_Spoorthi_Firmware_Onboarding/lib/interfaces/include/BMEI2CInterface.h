#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{
public:
    BMEI2CInterface() = default;

    bool begin();
    float readTemperature();  // degrees C
    float readPressure();     // Pa
    float readHumidity();     // % RH

private:
    Adafruit_BME280 bme;
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;