#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin()
{
    return sensor.begin();
}

void BMEI2CInterface::update()
{
    temperature = sensor.readTemperature();
}

float BMEI2CInterface::getTemperature() const
{
    return temperature;
}