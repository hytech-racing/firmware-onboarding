#include "BMEI2Cinterface.h"
#include "BMEConstants.h"

bool BMEI2CInterface::startSensor()
{
    return sensor.begin(BMEConstants::I2C_ADDRESS);
}

float BMEI2CInterface::readTemperature()
{
    return sensor.readTemperature();
}