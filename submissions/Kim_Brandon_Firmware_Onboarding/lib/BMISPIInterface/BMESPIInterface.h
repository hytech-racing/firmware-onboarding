#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface();

    bool begin();                    // false if the sensor isn't found
    void update();                   // read the sensor, store the value
    float getTemperatureC() const;
    bool isConnected() const;

private:
    Adafruit_BME280 bme_;            // hardware-SPI constructor (takes CS pin)
    float temperatureC_ = 0.0f;
    bool connected_ = false;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;