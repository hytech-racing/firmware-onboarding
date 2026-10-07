#include "BMEI2CInterface.h"
#include "BMEConstants.h"

int BMEI2CInterface::begin()
{
    return _inst.begin(BMEConstants::ADDR_I2C);
}

float BMEI2CInterface::getTemp()
{
    return _inst.readTemperature();
}

float BMEI2CInterface::getHumidity()
{
    return _inst.readHumidity();
}

float BMEI2CInterface::getPressure()
{
    return _inst.readPressure() / 100.0F; // all these pulled from adafruit bme280test.ino example
}