#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface() 
    : bme_(BMEConstants::BME_CS_PIN) // Uses hardware SPI with defined Chip Select pin
{
}

bool BMESPIInterface::begin()
{
    return bme_.begin();
}

float BMESPIInterface::read_temperature()
{
    return bme_.readTemperature();
}