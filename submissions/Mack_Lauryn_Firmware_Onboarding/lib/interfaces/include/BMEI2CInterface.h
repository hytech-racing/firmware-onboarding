#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{
public:
    BMEI2CInterface() = default;

    bool begin();
    float get_temperature();

private:
    Adafruit_BME280 _sensor;
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;