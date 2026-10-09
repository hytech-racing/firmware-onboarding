#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface {
    public:
        BMEI2CInterface() = default;

        bool init();
        void update();
        float getTemperature() const;
    
    private:
        Adafruit_BME280 bme;
        float temperatureC = 0.0f;
        bool initialized = false;
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;
