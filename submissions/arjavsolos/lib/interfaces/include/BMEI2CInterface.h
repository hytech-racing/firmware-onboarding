#pragma once

#include <Adafruit_BME280.h>
#include <etl/singleton.h>

class BMEI2CInterface
{
public:
    BMEI2CInterface() = default;

    bool begin();
    bool update();
    bool isReady() const;
    float temperatureC() const;

private:
    Adafruit_BME280 sensor_;
    float temperatureC_ = NAN;
    bool ready_ = false;
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;
