#include <Arduino.h>

#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

LEDController ledController;

unsigned long previousMillis = 0;
bool ledState = false;

void setup() {
    Serial.begin(9600);
    pinMode(BMEConstants::LED_PIN,OUTPUT);
    BMEI2CInterfaceInstance::create();
    if (!BMEI2CInterfaceInstance::instance().begin()) {
        Serial.println("Couldn't initialize BME280 using I2C");
        while (true) {

        }
    }


}

void loop() {
    const float temperature = BMEI2CInterfaceInstance::instance().readTemperature();
    const unsigned long blinkInterval = ledController.getBlinkInterval(temperature);

    const unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= blinkInterval) {
        previousMillis = currentMillis;
        ledState = !ledState;

        digitalWrite(BMEConstants::LED_PIN,ledState? HIGH:LOW);
        
    }
}