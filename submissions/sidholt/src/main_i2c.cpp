#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

unsigned long lastPrint = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BME280 I2C test...");

  if (!BMEI2CInterfaceInstance::instance().begin()) {
    Serial.println("No BME280 found, check I2C wiring");
    while (true) {
    }
  }

  Serial.println("BME280 connected over I2C");
  LEDControllerInstance::instance().begin(BMEConstants::LED_PIN);
}

void loop() {
  auto& bme = BMEI2CInterfaceInstance::instance();
  unsigned long now = millis();

  if (now - lastPrint >= 2000) {
    lastPrint = now;
    bme.update();

    Serial.print("Temp = ");
    Serial.print(bme.getTemp());
    Serial.println(" C");
    Serial.print("Pressure = ");
    Serial.print(bme.getPress());
    Serial.println(" hPa");
    Serial.print("Altitude = ");
    Serial.print(bme.getAlt());
    Serial.println(" m");
    Serial.print("Humidity = ");
    Serial.print(bme.getHum());
    Serial.println(" %");
    Serial.println();
  }

  LEDControllerInstance::instance().update(bme.getTemp());
}
