#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

static unsigned long last_read_ms = 0;

void setup()
{
    Serial.begin(115200);

    LEDContollerInstance::create(LED_BUILTIN);
    LEDContollerInstance::instance().init();

    BMEI2CInterfaceInstance::create();
    if (!BMEI2CInterfaceInstance::instance().init(BMEConstants::BME_ADDRESS))
    {
        Serial.println("ERR bme280 not found - check wiring/address");
        pinMode(LED_BUILTIN, OUTPUT);
        while (true)
        {
            digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
            delay(100);
        }
    }

    Serial.println("BME280 ready (I2C)");
}

void loop()
{
    unsigned long curr_millis = millis();

    if (curr_millis - last_read_ms >= BMEConstants::SENSOR_READ_INTERVAL_MS)
    {
        last_read_ms = curr_millis;

        celsius temp_C = BMEI2CInterfaceInstance::instance().read_temperature();

        LEDContollerInstance::instance().update_blink_interval(temp_C);

        Serial.print("temp = "); Serial.print(temp_C); Serial.println("C");
        Serial.print("blink interval = "); Serial.print(LEDContollerInstance::instance().get_blink_interval_ms()); Serial.println("ms");
    }

    LEDContollerInstance::instance().update_LED_state(curr_millis);
}