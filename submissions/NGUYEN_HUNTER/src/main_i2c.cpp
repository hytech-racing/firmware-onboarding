#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"
#include "FirmwareApplication.h"

FirmwareApplication<BMEI2CInterfaceInstance> application;
void setup() { application.setup(F("Bus: I2C")); }
void loop() { application.loop(); }
