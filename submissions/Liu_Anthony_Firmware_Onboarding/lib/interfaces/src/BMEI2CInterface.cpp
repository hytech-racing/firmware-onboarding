#include "BMEI2CInterface.h"


bool BMEI2CInterface::init(uint8_t address)
{
    return _bme.begin(address, &Wire);
}

float BMEI2CInterface::read_temperature()
{
    return _bme.readTemperature();
}