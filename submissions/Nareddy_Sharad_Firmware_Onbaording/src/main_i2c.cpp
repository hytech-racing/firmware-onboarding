#include "BMEI2Cinterface.h"
#include "LEDcontroller.h"
#include "BMEConstants.h"
#include <Arduino.h>

#define LED_PIN 13

void setup()
{
    Serial.begin(115200);
    BMEI2CInterfaceInstance::create();
    BMEI2CInterfaceInstance::instance().startSensor();
    LEDControllerInstance::create();

}

void loop()
{
    float tempC = BMEI2CInterfaceInstance::instance().readTemperature();
    LEDControllerInstance::instance().flashLEDByTemperature(LED_PIN, tempC);
    Serial.print("Temperature: ");
    Serial.println(tempC);
}