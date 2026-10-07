#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:

    BMESPIInterface() = default;

    int begin();

    float getTemp();
    float getHumidity();
    float getPressure();

private:

    Adafruit_BME280 _inst{BMEConstants::CS_SPI};
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;