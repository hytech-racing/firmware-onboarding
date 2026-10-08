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

    // Your public methods go here

private:
Adafruit_BME280 bme;

    // Your private variables go here
};

using BMEI2CInterfaceInstance =
    etl::singleton<BMEI2CInterface>;