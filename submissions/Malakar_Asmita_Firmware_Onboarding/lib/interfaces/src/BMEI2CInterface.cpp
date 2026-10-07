#include "BMEI2CInterface.h"

bool BMEI2CInterface::init()
{
    return bme.begin(BMEConstants::I2C_ADDRESS);
}

float BMEI2CInterface::readTemperature()
{
    return bme.readTemperature();
}