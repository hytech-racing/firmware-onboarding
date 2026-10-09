#include "BMEI2CInterface.h"

// Initialize the sensor using its I2C address
bool BMEI2CInterface::begin()
{
    return bme.begin(BMEConstants::BME_I2C_ADDRESS);
}
// Read the current temperature in Celsius
float BMEI2CInterface::readTemperature()
{
    return bme.readTemperature();
}