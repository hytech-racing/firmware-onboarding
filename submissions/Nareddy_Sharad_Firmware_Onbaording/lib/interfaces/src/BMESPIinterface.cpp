#include "BMESPIinterface.h"

bool BMESPIInterface::startSensor()
{
    return sensor.begin();
}

float BMESPIInterface::readTemperature()
{
    return sensor.readTemperature();
}