#include "BMEI2CInterface.h"
bool BMEI2CInterface::begin()
{
    return bme.begin();
}

float BMEI2CInterface::readTemperature(void)
{
    return bme.readTemperature();
}