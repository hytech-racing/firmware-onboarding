# Firmware Onboarding Project

This PlatformIO project reads temperature from a BME280 using either I2C or SPI
and changes an external LED's blink rate. The LED blinks faster as temperature
rises and slower as temperature falls.

## Project structure

```text
firmware-onboarding-project/
|-- include/
|   `-- BMEConstants.h
|-- lib/
|   |-- interfaces/
|   |   |-- include/
|   |   |   |-- BMEI2CInterface.h
|   |   |   `-- BMESPIInterface.h
|   |   `-- src/
|   |       |-- BMEI2CInterface.cpp
|   |       `-- BMESPIInterface.cpp
|   `-- systems/
|       |-- include/
|       |   `-- LEDController.h
|       `-- src/
|           `-- LEDController.cpp
|-- src/
|   |-- main_i2c.cpp
|   `-- main_spi.cpp
`-- platformio.ini
```

The interface classes only initialize the BME280, collect readings, and expose
the latest valid temperature. `LEDController` contains the decision-making logic
that converts temperature to blink interval and updates the LED without blocking.

## Wiring

Use a BME280 breakout that is compatible with your Uno's voltage levels. A bare
BME280 sensor is a 3.3 V device; do not connect a bare sensor directly to 5 V.

External LED for both modes:

- Uno pin 6 -> 220-330 ohm resistor -> LED anode (long leg)
- LED cathode (short leg) -> GND

I2C mode:

- BME280 VIN/VCC -> the voltage required by your breakout
- BME280 GND -> Uno GND
- BME280 SDA -> Uno A4/SDA
- BME280 SCL -> Uno A5/SCL
- The code defaults to address `0x76`; change `I2C_ADDRESS` to `0x77` if needed

Hardware SPI mode:

- BME280 VIN/VCC -> the voltage required by your breakout
- BME280 GND -> Uno GND
- BME280 SCK/SCL -> Uno pin 13
- BME280 SDO/MISO -> Uno pin 12
- BME280 SDI/MOSI -> Uno pin 11
- BME280 CS/CSB -> Uno pin 10

The external LED uses pin 6 because the Uno's built-in LED is on pin 13, which
is also the hardware-SPI clock pin.

## Build and upload

Open this folder in VS Code with PlatformIO installed. Build both environments:

```sh
pio run -e uno_i2c
pio run -e uno_spi
```

Upload the version matching your wiring:

```sh
pio run -e uno_i2c -t upload
# or
pio run -e uno_spi -t upload
```

Open the serial monitor at 115200 baud:

```sh
pio device monitor -b 115200
```

## How the blink calculation works

The controller clamps temperatures to a useful range:

- 0 C or colder: 1500 ms between LED toggles
- 40 C or warmer: 150 ms between LED toggles
- Between 0 C and 40 C: a linear value between those intervals

For example, 20 C is halfway through the temperature range, so the toggle
interval is about halfway between 1500 ms and 150 ms: 825 ms.

All thresholds, intervals, pins, and the I2C address are centralized in
`include/BMEConstants.h`.

## Before submitting

1. Fork `hytech-racing/firmware-onboarding` on GitHub.
2. In your fork, place this project's contents directly inside
   `submissions/YOUR_GITHUB_USERNAME/`. The `platformio.ini` file must be at
   `submissions/YOUR_GITHUB_USERNAME/platformio.ini` so the repository's CI
   workflow can find it.
3. Build both environments successfully.
4. Test the I2C wiring and then the SPI wiring on real hardware.
5. Commit, push, and open a pull request titled `LAST_FIRST_Submission`.
6. Complete every field in the repository's pull request template.
