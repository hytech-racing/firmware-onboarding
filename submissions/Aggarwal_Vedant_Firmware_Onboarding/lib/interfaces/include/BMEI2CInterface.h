#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"


class BMEI2CInterface
{
public:

    BMEI2CInterface() = default;
    bool begin();
    float readTemperature();
    // Code here!

private:
    Adafruit_BME280 bme;
   // Code here!

};
using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;