#include <Arduino.h>
#include "BMESPIInterface.h"
#include "BMEConstants.h"
#include "LEDController.h"

void setup()
{
    Serial.begin(BMEConstants::SERIAL_BAUD);
    BMESPIInterfaceInstance::create();
    if (!BMESPIInterfaceInstance::instance().init())
    {
        Serial.println("BME280 not found (SPI)");
    }
    LEDControllerInstance::create();
    LEDControllerInstance::instance().init();
}

void loop()
{
    auto& bme = BMESPIInterfaceInstance::instance();
    bme.update();
    Serial.println(bme.getTemperature());
    LEDControllerInstance::instance().setTemperature(bme.getTemperature());
    LEDControllerInstance::instance().update();
    
}