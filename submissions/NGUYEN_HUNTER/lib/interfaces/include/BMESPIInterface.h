#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface {
public:
    BMESPIInterface();
    bool begin();
    float readTemperature();
    float temperatureC() const { return temperatureC_; }
private:
    Adafruit_BME280 sensor_;
    float temperatureC_ = NAN;
};
using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;
