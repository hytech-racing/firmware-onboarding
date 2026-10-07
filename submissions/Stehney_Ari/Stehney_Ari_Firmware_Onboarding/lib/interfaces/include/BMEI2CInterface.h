#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{
public:

    BMEI2CInterface() = default;

    int begin();

    float getTemp();
    float getHumidity();
    float getPressure();

private:

    Adafruit_BME280 _inst;
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;