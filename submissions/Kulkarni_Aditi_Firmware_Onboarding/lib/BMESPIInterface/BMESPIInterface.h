// Same operations as I2C but makes sure sensors constructure uses hardware SPI and pin10
#pragma once
#include <Adafruit_BME280.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    bool begin();
    void update();
    float getTemperature() const;

private:
    Adafruit_BME280 sensor{BMEConstants::SPI_CS_PIN};
    float temperatureC = 0.0f;
};