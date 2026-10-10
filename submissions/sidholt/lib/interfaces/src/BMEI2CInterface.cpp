#include "BMEI2CInterface.h"
#include <Wire.h>

bool BMEI2CInterface::begin()
{
    return bme.begin(BMEConstants::I2C_ADDR, &Wire);
}

void BMEI2CInterface::update()
{
    temp = bme.readTemperature();
    hum = bme.readHumidity();
    press = bme.readPressure() / 100.0f;
    alt = bme.readAltitude(BMEConstants::SEA_LEVEL_HPA);
}
