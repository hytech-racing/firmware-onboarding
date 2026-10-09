#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

static unsigned long last_debug_print_ms = 0;
constexpr unsigned long DEBUG_INTERVAL_MS = 500;

void setup()
{
    Serial.begin(115200);

    LEDControllerInstance::instance().begin();

    if (!BMEI2CInterfaceInstance::instance().begin())
    {
        Serial.println(F("[ERROR] BME280 sensor not detected over I2C. Check wiring/pullups!"));
        while (1) { delay(10); }
    }

    Serial.println(F("[INIT] BME280 I2C interface initialized."));
}

void loop()
{
    float temp_c = BMEI2CInterfaceInstance::instance().read_temperature();
    LEDControllerInstance::instance().update(temp_c);

        unsigned long now = millis();
        if (now - last_debug_print_ms >= DEBUG_INTERVAL_MS)
        {
            last_debug_print_ms = now;

            unsigned long period_ms = LEDControllerInstance::instance().get_current_period_ms();

            Serial.print(F("Temp: "));
            Serial.print(temp_c, 2);
            Serial.print(F(" C | Blink Period: "));
            Serial.print(period_ms);
            Serial.println(F(" ms"));
        }
    
}