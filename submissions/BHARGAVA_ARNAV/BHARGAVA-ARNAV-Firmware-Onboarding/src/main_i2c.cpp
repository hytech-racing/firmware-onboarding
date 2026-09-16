#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

bool initWorked; 
unsigned long lastReading = 0; 

void setup()
{
  Serial.begin(115200);
  LEDControllerInstance::create();
  BMEI2CInterfaceInstance::create();
  LEDControllerInstance::instance().init();
  initWorked = BMEI2CInterfaceInstance::instance().init();
  Serial.println(String(initWorked));

}
void loop()
{
  
  if (initWorked) {
    if (millis() - lastReading >= BMEConstants::read_interval) {
      lastReading = millis();
      float temperature = BMEI2CInterfaceInstance::instance().getTemperature();
      LEDControllerInstance::instance().tempToRate(temperature);
      Serial.println(temperature, 2);
    }
    LEDControllerInstance::instance().updateLEDState();
  } else {
    Serial.println("Initialization failed (.begin() returned false)");
    while (true) {};
  }
}
