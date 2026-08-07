#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

static unsigned long last_read_ms = 0;

void setup()
{
    Serial.begin(115200);

    LEDContollerInstance::create(LED_BUILTIN);
    LEDContollerInstance::instance().init();

    BMESPIInterfaceInstance::create();
    if (!BMESPIInterfaceInstance::instance().init(BMEConstants::CS_PIN))
    {
        Serial.println("ERR bme280 not found - check wiring/CS pin");
        pinMode(LED_BUILTIN, OUTPUT);
        while (true)
        {
            digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
            delay(100);
        }
    }

    Serial.println("BME280 ready (SPI)");
}

void loop()
{
    unsigned long curr_millis = millis();

    if (curr_millis - last_read_ms >= BMEConstants::SENSOR_READ_INTERVAL_MS)
    {
        last_read_ms = curr_millis;

        celsius temp_C = BMESPIInterfaceInstance::instance().read_temperature();

        LEDContollerInstance::instance().update_blink_interval(temp_C);

        Serial.print("temp = "); Serial.print(temp_C); Serial.println("C");
        Serial.print("blink interval = "); Serial.print(LEDContollerInstance::instance().get_blink_interval_ms()); Serial.println("ms");
    }

    LEDContollerInstance::instance().update_LED_state(curr_millis);
}