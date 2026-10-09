#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

static unsigned long last_debug_print_ms = 0;
constexpr unsigned long DEBUG_INTERVAL_MS = 200;

void setup()
{
    Serial.begin(115200);

    LEDControllerInstance::instance().begin();

    if (!BMESPIInterfaceInstance::instance().begin())
    {
        Serial.println(F("[ERROR] BME280 sensor not detected over SPI. Check CS/wiring!"));
        while (1) { delay(10); }
    }

    Serial.println(F("[INIT] BME280 SPI interface initialized."));
}

void loop()
{
    float temp_c = BMESPIInterfaceInstance::instance().read_temperature();
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