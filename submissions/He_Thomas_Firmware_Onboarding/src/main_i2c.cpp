#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"


void setup()
{
  LEDControllerInstance::instance().setup();
  if (BMEI2CInterfaceInstance::instance().begin() == false) {
    exit(0);
  }
}

void loop()
{
  float temperature = BMEI2CInterfaceInstance::instance().readTemperature();
  LEDControllerInstance::instance().blinkblinkblink(temperature);

}