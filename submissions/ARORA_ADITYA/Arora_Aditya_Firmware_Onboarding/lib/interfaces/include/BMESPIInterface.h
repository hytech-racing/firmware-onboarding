#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface() : _bme(BMEConstants::SPI_CS_PIN) {}

    bool init();
    void update();
    float getTemperature() const;

private:
    Adafruit_BME280 _bme;
    float _temperature = 0.0f;
};
using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;