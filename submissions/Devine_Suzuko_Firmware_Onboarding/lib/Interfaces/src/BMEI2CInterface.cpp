#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin()
{
    // Try the most common BME280 I2C address first.
    if (bme.begin(BMEConstants::I2C_ADDRESS_PRIMARY))
    {
        return true;
    }

    // If that fails, try the alternate address.
    if (bme.begin(BMEConstants::I2C_ADDRESS_SECONDARY))
    {
        return true;
    }

    return false;
}

float BMEI2CInterface::readTemperature()
{
    return bme.readTemperature();
}