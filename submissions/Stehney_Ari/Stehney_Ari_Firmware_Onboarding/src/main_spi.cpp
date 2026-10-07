#include <Arduino.h>

#include "BMESPIInterface.h"
#include "LEDController.h"
#include <Arduino.h>

float last_sensor_value = 0;
unsigned long last_time = 0;

BMESPIInterface* bme = nullptr;
LEDController* led = nullptr;

void setup() {
    Serial.begin(115200);

    BMESPIInterfaceInstance::create();
    bme = &BMESPIInterfaceInstance::instance();

    if (!bme->begin()) {
        Serial.println("can't init BME280");
        while (1);
    }

    LEDControllerInstance::create();
    led = &LEDControllerInstance::instance();

    if (!led->begin()) {
        Serial.println("can't init LED Controller");
        while (1);
    }
}

void loop() {
  if (millis() - last_time >= BMEConstants::SENSOR_UPDATE_IVAL) {
    last_time = millis();
    last_sensor_value = bme->getTemp();
  }

  led->update(last_sensor_value);
}