#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

bool initWorked; 
unsigned long lastReading = 0; 

void setup()
{
  Serial.begin(115200);
  LEDControllerInstance::create();
  BMESPIInterfaceInstance::create();
  LEDControllerInstance::instance().init();
  initWorked = BMESPIInterfaceInstance::instance().init();
  Serial.println(initWorked);
  
}
void loop()
{
  
  if (initWorked) {
    if (millis() - lastReading >= BMEConstants::read_interval) {
      lastReading = millis();
      float temperature = BMESPIInterfaceInstance::instance().getTemperature();
      LEDControllerInstance::instance().tempToRate(temperature);
      Serial.println(temperature, 2);
    }
    LEDControllerInstance::instance().updateLEDState();
  } else {
    Serial.println("Initialization failed (.begin() returned false)");
    while (true) {};
  }
}

