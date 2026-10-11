#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin()
{
    return sensor.begin();
}

float BMEI2CInterface::readTemperature()
{
    return sensor.readTemperature();
}
