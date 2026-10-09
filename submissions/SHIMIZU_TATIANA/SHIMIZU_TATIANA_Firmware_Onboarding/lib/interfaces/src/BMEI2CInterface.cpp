#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin()
{
    // Begin communication with the sensor at the specified I2C address
    return bme_.begin(BMEConstants::BME_I2C_ADDR);
}

float BMEI2CInterface::read_temperature()
{
    return bme_.readTemperature();
}