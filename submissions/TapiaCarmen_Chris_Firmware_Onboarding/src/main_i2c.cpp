#include <Arduino.h>
#include "BMEI2Cinterface.h"
#include "LEDController.h"
#include "BMEConstants.h"
void setup() {
    
    Serial.begin(115200);

    
    BMEI2CInterfaceInstance::create();
    BMEI2CInterfaceInstance::instance().start_sensor();
    LEDControllerInstance::create();


    

    Serial.println("BME280 sensor started!");
}

void loop() {
    
    float temp = BMEI2CInterfaceInstance::instance().findtemp();
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println(" C");
    LEDControllerInstance::instance().flashLEDbyTemperature(temp);


    
}