#pragma once
#include <Adafruit_BME280.h>
class BMEI2CInterface
{
public:
    bool begin();
    void update();
    float getTemperature() const;

private:
    Adafruit_BME280 sensor;
    float temperatureC = 0.0f;
};