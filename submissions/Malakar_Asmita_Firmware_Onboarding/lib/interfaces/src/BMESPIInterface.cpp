#include "BMESPIInterface.h"

bool BMESPIInterface::init()
{
    return bme.begin();
}

float BMESPIInterface::readTemperature()
{
    return bme.readTemperature();
}