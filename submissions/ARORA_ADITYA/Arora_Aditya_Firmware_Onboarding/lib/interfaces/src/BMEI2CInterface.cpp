#include "BMEI2CInterface.h"

bool BMEI2CInterface::init()
{
    return _bme.begin(BMEConstants::I2C_ADDRESS);
}

void BMEI2CInterface::update()
{
    _temperature = _bme.readTemperature();
}

float BMEI2CInterface::getTemperature() const
{
    return _temperature;
}