#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"
#include "FirmwareApplication.h"

FirmwareApplication<BMESPIInterfaceInstance> application;
void setup() { application.setup(F("Bus: hardware SPI")); }
void loop() { application.loop(); }
