#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface()
        : bme(BMEConstants::SPI_CS)
    {
    }

    bool begin();
    void update();

    float getTemp() const { return temp; }
    float getHum() const { return hum; }
    float getPress() const { return press; }
    float getAlt() const { return alt; }

private:
    Adafruit_BME280 bme;
    float temp = 0.0f;
    float hum = 0.0f;
    float press = 0.0f;
    float alt = 0.0f;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;
