#include "LEDcontroller.h"


void ledController::flashLEDByTemperature(int pin, float tempC) {
    int duration = 1000; // default

    if (tempC > 27.0)  duration = 150;
    else if (tempC > 26.0)  duration = 500;
    else if (tempC > 25.0) duration = 1000;

    digitalWrite(pin, HIGH);
    delay(duration);
    digitalWrite(pin, LOW);
    delay(duration);


}