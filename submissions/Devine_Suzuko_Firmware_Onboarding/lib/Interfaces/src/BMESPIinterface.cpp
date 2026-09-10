#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface(int8_t cspin) : _cspin(cspin), bme(cspin) {}

bool BMESPIInterface::begin()
{
    return bme.begin();
}

float BMESPIInterface::readTemperature()
{
    return bme.readTemperature();
}