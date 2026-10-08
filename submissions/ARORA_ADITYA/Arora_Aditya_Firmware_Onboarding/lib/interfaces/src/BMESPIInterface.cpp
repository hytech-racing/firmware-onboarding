#include "BMESPIInterface.h"

bool BMESPIInterface::init()
{
    return _bme.begin();
}

void BMESPIInterface::update()
{
    _temperature = _bme.readTemperature();
}

float BMESPIInterface::getTemperature() const
{
    return _temperature;
}