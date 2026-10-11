#include "BMESPIInterface.h"

// Configure the BME280 to use hardware SPI
BMESPIInterface::BMESPIInterface()
    : bme(CS_PIN)
{
}

// Initialize the sensor
bool BMESPIInterface::begin()
{
    return bme.begin();
}

// Read temperature in degrees Celsius
float BMESPIInterface::readTemperature()
{
    return bme.readTemperature();
}