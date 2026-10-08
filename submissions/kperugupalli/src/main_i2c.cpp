#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

BMEI2CInterface sensor;
LEDController led;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);

    if (!sensor.begin())
    {
        Serial.println("BME280 initialization failed!");
    }
}

void loop()
{
    float temperature = sensor.readTemperature();

    led.update(temperature);
}