#include "BMESPIInterface.h"
#include "BMEConstants.h"

int BMESPIInterface::begin()
{

    return _inst.begin();
}

float BMESPIInterface::getTemp()
{
    return _inst.readTemperature();
}

float BMESPIInterface::getHumidity()
{
    return _inst.readHumidity();
}

float BMESPIInterface::getPressure()
{
    return _inst.readPressure() / 100.0F; // all these pulled from adafruit bme280test.ino example
}