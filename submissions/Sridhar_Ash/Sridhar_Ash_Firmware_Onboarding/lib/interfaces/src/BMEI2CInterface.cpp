#include "BMEI2CInterface.h"

bool BMEI2CInterface::init()
{
    return bme.begin(0x76);
}

float BMEI2CInterface::get_temperature()
{
    return bme.readTemperature();
}