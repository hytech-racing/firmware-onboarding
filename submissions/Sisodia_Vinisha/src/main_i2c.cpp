#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"

// put function declarations here:

BMEI2CInterface bme;
LEDController led;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  led.begin();
    if (!bme.begin())
    {
    Serial.println("BME280 initialization failed. Check wiring and I2C address.");

    while (true)
    {
        delay(1000);
    }
    }
}

void loop() {
  bme.update();
  led.update(bme.getTemperature());
}

// put function definitions here:
