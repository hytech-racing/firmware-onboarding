#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "BMEConstants.h"
#include "LEDController.h"

void setup()
{
    Serial.begin(BMEConstants::SERIAL_BAUD);
    BMEI2CInterfaceInstance::create();
    if (!BMEI2CInterfaceInstance::instance().init())
    {
        Serial.println("BME280 not found (I2C)");
    }
    LEDControllerInstance::create();
    LEDControllerInstance::instance().init();
}

void loop()
{
    auto& bme = BMEI2CInterfaceInstance::instance();
    bme.update();
    Serial.println(bme.getTemperature());
    LEDControllerInstance::instance().setTemperature(bme.getTemperature());
    LEDControllerInstance::instance().update();
    
}