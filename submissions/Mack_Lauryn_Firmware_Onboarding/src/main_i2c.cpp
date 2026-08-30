#include <Arduino.h>
#include "BMEI2CInterface.h"

void setup()
{
    Serial.begin(115200);

    auto& bme = BMEI2CInterfaceInstance::instance();

    if (!bme.begin())
    {
        Serial.println("BME280 not found!");
        while (true)
        {
        }
    }
}

void loop()
{
    auto& bme = BMEI2CInterfaceInstance::instance();

    Serial.print("Temperature: ");
    Serial.println(bme.get_temperature());

    delay(1000);
}