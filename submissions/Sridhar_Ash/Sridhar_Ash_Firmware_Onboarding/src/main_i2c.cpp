#include <Arduino.h>

#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

void setup()
{
    Serial.begin(115200);

    BMEI2CInterfaceInstance::create();
    LEDControllerInstance::create();
    
    LEDControllerInstance::instance().init();

    bool success = BMEI2CInterfaceInstance::instance().init();

    if (!success)
    {
        Serial.println("BME280 initialization failed!");
    }
}

void loop()
{
    float temperature =
        BMEI2CInterfaceInstance::instance().get_temperature();

    Serial.print("Temperature: ");
    Serial.println(temperature);

    LEDControllerInstance::instance().update(temperature);
}