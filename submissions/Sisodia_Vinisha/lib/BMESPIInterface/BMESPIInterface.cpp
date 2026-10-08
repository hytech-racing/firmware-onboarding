#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface()
    : sensor(BMEConstants::SPI_CS_PIN)
{
}


bool BMESPIInterface::begin()
{
    return sensor.begin();
}

void BMESPIInterface::update()
{
    temperature = sensor.readTemperature();
}

float BMESPIInterface::getTemperature() const
{
    return temperature;
}