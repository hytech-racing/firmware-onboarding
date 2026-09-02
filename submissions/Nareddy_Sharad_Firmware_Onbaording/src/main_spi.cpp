#include "BMESPIinterface.h"
#include "LEDcontroller.h"

#define LED_PIN 13

void setup()
{
    Serial.begin(115200);
    BMESPIInterfaceInstance::create();
    BMESPIInterfaceInstance::instance().startSensor();
    LEDControllerInstance::create();
    
}

void loop()
{
    float tempC = BMESPIInterfaceInstance::instance().readTemperature();
    LEDControllerInstance::instance().flashLEDByTemperature(LED_PIN, tempC);
}