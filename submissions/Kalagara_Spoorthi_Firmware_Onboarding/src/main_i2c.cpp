#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

void setup()
{
    Serial.begin(115200);

    BMEI2CInterfaceInstance::create();
    LEDControllerInstance::create();

    if (!BMEI2CInterfaceInstance::instance().begin())
    {
        Serial.println("BME280 not found over I2C, check wiring");
    }
    LEDControllerInstance::instance().begin();
}

void loop()
{
    float temp = BMEI2CInterfaceInstance::instance().readTemperature();
    LEDControllerInstance::instance().update(temp);

    Serial.print("Temp (C): ");
    Serial.println(temp);
}