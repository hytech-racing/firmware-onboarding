#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"


class BMESPIInterface
{
public:

    BMESPIInterface() = default;
    bool begin();
    float readTemperature(void);

private:

    Adafruit_BME280 bme{
        BMEConstants::BME_CS_PIN,
        BMEConstants::BME_MOSI_PIN,
        BMEConstants::BME_MISO_PIN,
        BMEConstants::BME_SCK_PIN
    };
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;