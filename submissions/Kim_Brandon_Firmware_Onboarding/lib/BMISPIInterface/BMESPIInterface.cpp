#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface()
    : bme_(BMEConstants::BME_CS_PIN)
{
}

bool BMESPIInterface::begin()
{
    connected_ = bme_.begin();
    return connected_;
}

void BMESPIInterface::update()
{
    if (!connected_)
    {
        return;
    }

    float reading = bme_.readTemperature();
    if (!isnan(reading))
    {
        temperatureC_ = reading;
    }
}

float BMESPIInterface::getTemperatureC() const
{
    return temperatureC_;
}

bool BMESPIInterface::isConnected() const
{
    return connected_;
}