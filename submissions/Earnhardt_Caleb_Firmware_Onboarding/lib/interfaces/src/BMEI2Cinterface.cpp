#include "BMEI2Cinterface.h"

bool BMEI2Cinterface::initialize()
{
    return _sensor.begin(0x77); // this is the i2c address. 
    //arduino sends a message with this address when it wants to communicate with this sensor specifically.
}

float BMEI2Cinterface::read_temperature()
{
    return _sensor.readTemperature();
}