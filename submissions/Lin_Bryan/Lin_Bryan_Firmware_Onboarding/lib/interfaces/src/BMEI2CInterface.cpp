#include "BMEI2CInterface.h"
#include "BMEConstants.h"

bool BMEI2CInterface::init()
{
    bool status = bme.begin(BMEConstants::I2C_ADDRESS);

    if (status) {
        bme.setSampling(Adafruit_BME280::MODE_NORMAL,
                        Adafruit_BME280::SAMPLING_X16,
                        Adafruit_BME280::SAMPLING_X16,
                        Adafruit_BME280::SAMPLING_X16,
                        Adafruit_BME280::FILTER_OFF,
                        Adafruit_BME280::STANDBY_MS_0_5);
    }

    return status;
}

float BMEI2CInterface::getTemperature()
{
    return bme.readTemperature();
}