#include "BMEI2CInterface.h"

#include "BMEConstants.h"

bool BMEI2CInterface::begin()
{
    ready_ = sensor_.begin(BMEConstants::I2C_ADDRESS);
    return ready_;
}

bool BMEI2CInterface::update()
{
    if (!ready_)
    {
        return false;
    }

    const float newTemperature = sensor_.readTemperature();
    if (isnan(newTemperature))
    {
        return false;
    }

    temperatureC_ = newTemperature;
    return true;
}

bool BMEI2CInterface::isReady() const
{
    return ready_;
}

float BMEI2CInterface::temperatureC() const
{
    return temperatureC_;
}
