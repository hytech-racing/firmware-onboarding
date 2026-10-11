#pragma once

#include <Arduino.h>
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface();

    bool begin();
    float readTemperature();

private:
    static constexpr int CS_PIN = 10;

    Adafruit_BME280 bme;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;