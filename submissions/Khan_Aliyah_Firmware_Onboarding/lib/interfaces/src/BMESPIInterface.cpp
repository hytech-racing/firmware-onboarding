#include "BMESPIInterface.h"

// Initialize the BME280 using SPI
bool BMESPIInterface::begin()
{
    return bme.begin();
}
// Read the current temperature in Celsius

float BMESPIInterface::readTemperature()
{
    return bme.readTemperature();
}