#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

LEDController ledController(BMEConstants::LED_PIN);
BMESPIInterface bmeInterface;

void setup()
{
    Serial.begin(115200);
    ledController.begin();
    if (!bmeInterface.begin())
    {
        Serial.println("Could not find BME280 sensor");
        while (1)
            ;
    }
}

void loop()
{
    float temperature = bmeInterface.readTemperature();
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");
    int blinkInterval = ledController.getBlinkInterval(temperature);
    ledController.toggle();
    delay(blinkInterval);
}
