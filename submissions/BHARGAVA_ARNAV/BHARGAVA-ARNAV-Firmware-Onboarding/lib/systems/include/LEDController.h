#pragma once
#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"


class LEDController 
{
public: 
    LEDController() = default;

    void init() ;

    void tempToRate(float temperature); 

    void updateLEDState () ; 

private:
    unsigned long blinkInterval;
    
    unsigned long lastToggled;

    bool ledState; 

};
using LEDControllerInstance = etl::singleton<LEDController>;
