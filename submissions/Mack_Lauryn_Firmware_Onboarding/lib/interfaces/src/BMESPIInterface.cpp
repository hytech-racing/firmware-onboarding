#include "BMESPIInterface.h"

bool BMESPIInterface::begin()
{
    return _sensor.begin();
}

float BMESPIInterface::get_temperature()
{
    return _sensor.readTemperature();
}