#include "BMESPIInterface.h"

#include "BMEConstants.h"

BMESPIInterface::BMESPIInterface()
    : sensor_(BMEConstants::SPI_CS_PIN)
{
}

bool BMESPIInterface::begin()
{
    ready_ = sensor_.begin();
    return ready_;
}

bool BMESPIInterface::update()
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

bool BMESPIInterface::isReady() const
{
    return ready_;
}

float BMESPIInterface::temperatureC() const
{
    return temperatureC_;
}
