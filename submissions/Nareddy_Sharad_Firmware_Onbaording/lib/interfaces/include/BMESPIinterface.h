#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface() : sensor(BMEConstants::SPI_CS_PIN) {}

    bool startSensor();
    float readTemperature();

private:
    Adafruit_BME280 sensor; // SPI
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;