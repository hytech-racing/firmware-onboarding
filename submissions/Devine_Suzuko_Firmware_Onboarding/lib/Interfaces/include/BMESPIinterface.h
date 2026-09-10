#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface(int8_t cspin = 10);
    bool begin();
    float readTemperature();

private:
    int8_t _cspin;
    Adafruit_BME280 bme;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;