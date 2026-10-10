#include "BMESPIInterface.h"

bool BMESPIInterface::begin()
{
    return bme.begin();
}

void BMESPIInterface::update()
{
    temp = bme.readTemperature();
    hum = bme.readHumidity();
    press = bme.readPressure() / 100.0f;
    alt = bme.readAltitude(BMEConstants::SEA_LEVEL_HPA);
}
