#include "BMEI2CInterface.h"

bool BMEI2CInterface::init()
{
    ready_ = bme_.begin(BMEConstants::I2C_ADDRESS);
    return ready_;
}

void BMEI2CInterface::tick()
{
    if (!ready_)
    {
        return;
    }
    temperature_c_ = bme_.readTemperature();
}

BMEConstants::celsius BMEI2CInterface::read_temperature()
{
    return temperature_c_;
}