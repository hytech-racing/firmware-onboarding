#include "BMEI2CInterface.h"

// Initialize the BME280 sensor using I2C
bool BMEI2CInterface::begin()
{
    return bme.begin(0x76);
}

// Read temperature in degrees Celsius
float BMEI2CInterface::readTemperature()
{
    return bme.readTemperature();
}