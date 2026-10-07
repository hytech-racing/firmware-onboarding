#include "BMESPIInterface.h"

bool BMESPIInterface::begin()
{
    return bme.begin();
}

float BMESPIInterface::readTemperature()
{
    return bme.readTemperature();
}

float BMESPIInterface::readPressure()
{
    return bme.readPressure();
}

float BMESPIInterface::readHumidity()
{
    return bme.readHumidity();
}