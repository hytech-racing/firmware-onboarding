#include "BMESPIinterface.h"

bool BMESPIinterface::initialize()
{
    return _sensor.begin();
}

float BMESPIinterface::read_temperature()
{
    return _sensor.readTemperature();
}