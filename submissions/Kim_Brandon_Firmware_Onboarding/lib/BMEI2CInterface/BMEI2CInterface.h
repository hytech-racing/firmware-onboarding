#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{
public:
    BMEI2CInterface() = default;

    bool begin();                    // false if the sensor isn't found
    void update();                   // read the sensor, store the value
    float getTemperatureC() const;
    bool isConnected() const;

private:
    Adafruit_BME280 bme_;            // default constructor = I2C
    float temperatureC_ = 0.0f;
    bool connected_ = false;
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;