#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface();

    bool begin();
    void update();
    float getTemperature() const;

private:
    Adafruit_BME280 sensor;
    float temperature = 0.0f;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;