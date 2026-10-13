#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin()
{
    connected_ = bme_.begin(BMEConstants::BME_I2C_ADDRESS);
    return connected_;
}

void BMEI2CInterface::update()
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

float BMEI2CInterface::getTemperatureC() const
{
    return temperatureC_;
}

bool BMEI2CInterface::isConnected() const
{
    return connected_;
}