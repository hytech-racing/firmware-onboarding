#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"
#include "LEDController.h"


void LEDController::setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void LEDController::blinkblinkblink(float temp) {
    unsigned long blinkDelay = -20 * temp + 1000;
    digitalWrite(LED_BUILTIN, HIGH);
    delay(blinkDelay);
    digitalWrite(LED_BUILTIN, LOW);
    delay(blinkDelay);
}