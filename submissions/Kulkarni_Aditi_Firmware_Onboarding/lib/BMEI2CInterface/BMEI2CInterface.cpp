// Implements all the operations
#include "BMEI2CInterface.h"
#include "BMEConstants.h"

bool BMEI2CInterface::begin()
{
    if (sensor.begin(BMEConstants::I2C_ADDRESS))
    {
        return true;
    }
    const uint8_t alternateAddress =
        (BMEConstants::I2C_ADDRESS == 0x76) ? 0x77 : 0x76;

    return sensor.begin(alternateAddress);
}
void BMEI2CInterface::update()
{
    temperatureC = sensor.readTemperature();
}
float BMEI2CInterface::getTemperature() const
{
    return temperatureC;
}