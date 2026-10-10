#pragma once

#include <Adafruit_BME280.h>
#include <etl/singleton.h>

class BMEI2Cinterface
{
public:
    BMEI2Cinterface() = default;

    bool initialize();
    float read_temperature();

private:
    Adafruit_BME280 _sensor;
};

using BMEI2CinterfaceInstance = etl::singleton<BMEI2Cinterface>;