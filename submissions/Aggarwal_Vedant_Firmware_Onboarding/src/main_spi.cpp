#include <Arduino.h>

#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

LEDController ledController;

unsigned long previousMillis = 0;
bool ledState = false;

void setup() {
    Serial.begin(115200);

    pinMode(BMEConstants::LED_PIN,OUTPUT);
    BMESPIInterfaceInstance::create();
    if (!BMESPIInterfaceInstance::instance().begin()) {
        Serial.println("Failed to initialize BME280 using SPI.");

        while (true) {

        }
    }
}

void loop() {
    const float temperature = BMESPIInterfaceInstance::instance().readTemperature();
    const unsigned long blinkInterval = ledController.getBlinkInterval(temperature);
    const unsigned long currentMillis = millis();

    if(currentMillis - previousMillis >= blinkInterval) {
        previousMillis = currentMillis;
        ledState = !ledState;
        digitalWrite(BMEConstants::LED_PIN, ledState?HIGH:LOW);
    }
}