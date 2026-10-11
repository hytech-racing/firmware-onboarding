#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface {
public:
    BMEI2CInterface() = default;
    bool begin();
    float readTemperature();
    float temperatureC() const { return temperatureC_; }
private:
    Adafruit_BME280 sensor_;
    float temperatureC_ = NAN;
};
using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;
