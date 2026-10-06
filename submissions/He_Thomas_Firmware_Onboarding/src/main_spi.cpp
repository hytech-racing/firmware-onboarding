#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"


void setup()
{
  LEDControllerInstance::instance().setup();
  if (BMESPIInterfaceInstance::instance().begin() == false) {
    exit(0);
  }
}

void loop()
{
  float temperature = BMESPIInterfaceInstance::instance().readTemperature();
  LEDControllerInstance::instance().blinkblinkblink(temperature);

}