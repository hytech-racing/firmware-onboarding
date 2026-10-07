#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface() = default;

    bool begin();
    float readTemperature();  // degrees C
    float readPressure();     // Pa
    float readHumidity();     // % RH

private:
    Adafruit_BME280 bme{BMEConstants::BME_CS_PIN};
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;