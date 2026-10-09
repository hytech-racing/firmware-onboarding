#include "BMESPIInterface.h"
// connects the sensor
bool BMESPIInterface::begin()
{
    return sensor.begin();
}
// stores the new temperature reading
void BMESPIInterface::update()
{
    temperatureC = sensor.readTemperature();
}
// returns the new temperature
float BMESPIInterface::getTemperature() const
{
    return temperatureC;
}