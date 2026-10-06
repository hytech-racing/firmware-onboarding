#include "LEDController.h"

void LEDController::init()
{
    pinMode(BMEConstants::LED_PIN, OUTPUT);
    
    digitalWrite(BMEConstants::LED_PIN, LOW);
    ledState = false;
}

void LEDController::update(float currentTemperature)
{
    float constrainedTemp = constrain(currentTemperature, 
                                      BMEConstants::TEMP_LOWER_BOUND_C, 
                                      BMEConstants::TEMP_UPPER_BOUND_C);

    uint32_t blinkInterval = map((long)constrainedTemp, 
                                 (long)BMEConstants::TEMP_LOWER_BOUND_C, 
                                 (long)BMEConstants::TEMP_UPPER_BOUND_C, 
                                 BMEConstants::BLINK_SLOW_MS, 
                                 BMEConstants::BLINK_FAST_MS);

    unsigned long currentMillis = millis();
    
    if (currentMillis - previousMillis >= blinkInterval) {
        previousMillis = currentMillis;
        
        ledState = !ledState;
        
        digitalWrite(BMEConstants::LED_PIN, ledState ? HIGH : LOW);
    }
}