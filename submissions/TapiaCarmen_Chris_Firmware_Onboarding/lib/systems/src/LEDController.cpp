#include "LEDController.h"
void ledController::flashLEDbyTemperature( float tempC)
{
     if (tempC < 28.0) {

            digitalWrite(LED_BUILTIN, HIGH);
            delay(2000);
            digitalWrite(LED_BUILTIN, LOW);
            delay(2000);
    } else if (tempC >= 28.0 && tempC < 29.0) {

         digitalWrite(LED_BUILTIN, HIGH);
          delay(250);
            digitalWrite(LED_BUILTIN, LOW);
            delay(250);

     } else {
            digitalWrite(LED_BUILTIN, HIGH);
            delay(125);
            digitalWrite(LED_BUILTIN, LOW);
            delay(125);

        }
    }
