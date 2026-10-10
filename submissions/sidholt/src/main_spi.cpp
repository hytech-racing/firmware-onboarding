#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

unsigned long lastPrint = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BME280 SPI test...");

  if (!BMESPIInterfaceInstance::instance().begin()) {
    Serial.println("No BME280 found, check SPI wiring");
    while (true) {
    }
  }

  Serial.println("BME280 connected over SPI");
  LEDControllerInstance::instance().begin(BMEConstants::LED_PIN_SPI);
}

void loop() {
  auto& bme = BMESPIInterfaceInstance::instance();
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
