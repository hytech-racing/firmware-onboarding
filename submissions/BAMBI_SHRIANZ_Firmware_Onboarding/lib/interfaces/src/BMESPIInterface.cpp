#include "BMESPIInterface.h"

bool BMESPIInterface::init()
{
    ready_ = bme_.begin();
    return ready_;
}

void BMESPIInterface::tick()
{
    if (!ready_)
    {
        return;
    }
    temperature_c_ = bme_.readTemperature();
}

BMEConstants::celsius BMESPIInterface::read_temperature()
{
    return temperature_c_;
}