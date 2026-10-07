#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin()
{
    return bme.begin(BMEConstants::BME_I2C_ADDRESS);
}

float BMEI2CInterface::readTemperature()
{
    return bme.readTemperature();
}

float BMEI2CInterface::readPressure()
{
    return bme.readPressure();
}

float BMEI2CInterface::readHumidity()
{
    return bme.readHumidity();
}