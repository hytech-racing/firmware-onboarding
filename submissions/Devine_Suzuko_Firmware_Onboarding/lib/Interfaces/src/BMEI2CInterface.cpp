#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin(uint8_t addr)
{
    return bme.begin(addr);
}

float BMEI2CInterface::readTemperature()
{
    return bme.readTemperature();
}