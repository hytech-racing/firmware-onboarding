#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"

BMESPIInterface bme;
LEDController led;


void setup()
{
    Serial.begin(115200);
    led.begin();
        if (!bme.begin())
        {
          Serial.println("BME280 initialization failed. Check SPI wiring.");

         while (true)
            {
            delay(1000);
            }
         }
}

void loop()
{
    bme.update();
    led.update(bme.getTemperature());
}