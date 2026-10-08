#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

BMESPIInterface sensor;
LEDController led;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);

    if (!sensor.begin())
    {
        Serial.println("BME280 SPI initialization failed!");
    }
}

void loop()
{
    float temperature = sensor.readTemperature();

    led.update(temperature);
}