#include <Arduino.h>
#include "BMEConstants.h"
#include "BMESPIInterface.h"
#include "LEDController.h"
// put function declarations here:
BMESPIInterface bme;
LEDController led;
unsigned long lastSampleMs = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(BMEConstants::SERIAL_BAUD);
  led.begin();
  if (!bme.begin()) {
    Serial.println("BME280 SPI failed. Check wiring.");
    while (true) {
      delay(1000);
    }
  }
  bme.update();
  lastSampleMs = millis();
  Serial.println("BME280 SPI ready.");
}
void loop() {
  // put your main code here, to run repeatedly:
  const unsigned long now = millis();
  if (now - lastSampleMs >= BMEConstants::SAMPLE_INTERVAL_MS) {
    lastSampleMs = now;
    bme.update();
    Serial.print("Temperature: ");
    Serial.print(bme.getTemperature());
    Serial.println(" C");
  }
  led.update(bme.getTemperature());
}
// put function definitions here:
// Interface and controller functions are defined in their own .cpp files.