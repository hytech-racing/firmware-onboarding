#include "LEDController.h"
#include "BMEConstants.h"

void LEDController::init() {
    pinMode(BMEConstants::led_pin, OUTPUT);
    blinkInterval = BMEConstants::max_int;
    ledState = false;
    digitalWrite(BMEConstants::led_pin, ledState);
    lastToggled = millis();
}

void LEDController::tempToRate(float temperature) {
    temperature = constrain(temperature, BMEConstants::min_temp, BMEConstants::max_temp);
    float slope = (BMEConstants::max_int - BMEConstants::min_int) / 
    (BMEConstants::min_temp - BMEConstants::max_temp);
    float y_int = BMEConstants::min_int - slope * BMEConstants::max_temp;
    blinkInterval = slope * temperature + y_int ;
}

void LEDController::updateLEDState () {
    unsigned long timestamp = millis();
    if ( timestamp - lastToggled >= blinkInterval ) {
        ledState = !ledState;
        lastToggled = timestamp;
        digitalWrite(BMEConstants::led_pin, ledState);
    }
}