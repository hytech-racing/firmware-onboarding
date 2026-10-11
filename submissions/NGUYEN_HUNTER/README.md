# NGUYEN_HUNTER_Firmware_Onboarding

Arduino Uno / Arduino framework implementation of Training Module 11. Open `Firmware_Project.code-workspace` from the repository root in VS Code. PlatformIO IDE is installed on this computer; the workspace provides **Build both Uno environments** and **Test LED logic on host** tasks (Terminal → Run Task).

## Build and test

Run these commands from `submissions/NGUYEN_HUNTER` in a PlatformIO terminal:

```sh
pio run -e uno_i2c -e uno_spi
pio test -c platformio-native.ini -e native
```

The hardware `platformio.ini` preserves the module's supplied configuration. Native tests use a separate configuration to avoid inheriting the Uno board/framework. Host tests use GCC when available; otherwise install `ziglang==0.15.2` in the Python environment running PlatformIO. The local VS Code tasks already point to the prepared PlatformIO installation.

## Architecture and behavior

`BMEI2CInterface` and `BMESPIInterface` initialize the Adafruit driver, read temperature, and cache the reading. Each uses the prescribed ETL singleton alias. `LEDController` accepts temperature and elapsed time, with no Arduino or sensor dependency. `main_i2c.cpp` and `main_spi.cpp` select their interface; shared main-loop orchestration initializes hardware, samples every 250 ms, prints at 115200 baud, and applies the controller's LED state.

The module specifies warmer → faster and cooler → slower, but gives no numerical mapping or LED pin. This implementation chooses a linear half-period from 1000 ms at 0°C to 100 ms at 50°C, clamped outside that interval. A full blink includes one on and one off half-period. At 25°C the full period is 1100 ms. Constants are centralized in `include/BMEConstants.h`.

Blink scheduling uses `millis()` without a blocking blink delay, handles unsigned timer rollover, and preserves phase after delayed loop calls. Initialization failure leaves the LED off and retries every two seconds. Invalid temperature values (NaN, infinity, or outside −40…85°C) also leave the LED off and trigger reinitialization. Adafruit's temperature API cannot reliably identify every mid-run electrical disconnection; inspect the hardware and serial output if readings appear stale.

## Wiring

Use an external LED: Uno D8 → 220–330 Ω resistor → LED anode; LED cathode → GND. D13 is reserved for SPI clock, so the onboard LED is not the temperature indicator.

| Signal | I2C firmware | SPI firmware |
| --- | --- | --- |
| GND | Common ground | Common ground |
| SCK/SCL | A5 | D13 |
| SDI/SDA | A4 | D11 (MOSI) |
| SDO | GND, selects address 0x76 | D12 (MISO) |
| CS | High, per breakout's I2C requirements | D10 |

Power according to the **actual breakout**. The Adafruit BME280 breakout supports 3–5 V VIN and level shifting; a bare BME280 or an unverified generic board must use its specified supply and appropriate logic-level conversion. Do not assume every board is 5 V tolerant. For an I2C board fixed at 0x77, change `I2C_ADDRESS` once in `BMEConstants.h`, then rebuild. These are alternative wiring configurations; rewire before changing modes.

References: [Adafruit wiring guide](https://learn.adafruit.com/adafruit-bme280-humidity-barometric-pressure-temperature-sensor-breakout/arduino-test), [PlatformIO AVR documentation](https://docs.platformio.org/en/latest/platforms/atmelavr.html).

## Hardware acceptance — pending

No Uno serial device was detected during local validation. Neither firmware has been flashed or observed on physical hardware. For **each** environment, connect the corresponding wiring, then run:

```sh
pio run -e uno_i2c -t upload
pio device monitor -b 115200
# Repeat with uno_spi after rewiring.
```

Select the correct upload port if automatic detection fails. Confirm the startup identifies the intended bus, `BME280 connected.` appears, and live `Temperature_C=... half_period_ms=...` readings are plausible. Warm the sensor gently and verify the reported half-period decreases and the D8 LED blinks faster; cool it and verify the reverse. Verify missing sensor at startup keeps the LED off, emits retry messages, and reconnecting restores readings. Save serial captures and photos/video for both modes. Do not use extreme heating or cooling.

## Submission — pending

This folder is in a local clone of the team repository. It has not been forked, committed, pushed, or submitted on GitHub. Use your own fork when submitting; the current origin is the upstream team repository. The prepared `SUBMISSION.md` contains the requested title and a truthful PR template. After real hardware testing, update its unchecked hardware item and attach evidence. GitHub CI and lead approval remain pending. The module's final reviewer instruction defines completion as approval, adding the `completed` label, and closing **without merging**.
