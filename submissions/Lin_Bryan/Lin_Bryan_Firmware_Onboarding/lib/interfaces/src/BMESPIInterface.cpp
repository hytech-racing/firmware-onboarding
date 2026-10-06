#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface() : bme(BMEConstants::SPI_CS_PIN)
{
}

bool BMESPIInterface::init()
{
    bool status = bme.begin();

    if (status) {
        bme.setSampling(Adafruit_BME280::MODE_NORMAL,
                        Adafruit_BME280::SAMPLING_X16,
                        Adafruit_BME280::SAMPLING_X16,
                        Adafruit_BME280::SAMPLING_X16,
                        Adafruit_BME280::FILTER_OFF,
                        Adafruit_BME280::STANDBY_MS_0_5);
    }

    return status;
}

float BMESPIInterface::getTemperature()
{
    return bme.readTemperature();
}   