#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin()
{
    return _sensor.begin(BMEConstants::I2C_ADDRESS);
}

float BMEI2CInterface::get_temperature()
{
    return _sensor.readTemperature();
}