# PR title: NGUYEN_HUNTER_Submission

## Summary

Implements BME280 temperature acquisition over I2C and hardware SPI on Arduino Uno. Separate ETL singleton interfaces cache sensor data; a hardware-independent LEDController maps warmer readings to faster D8 LED blinking. Shared setup/loop orchestration checks initialization, reports readings at 115200 baud, and retries failed initialization. Both Uno environments build locally and all nine host logic tests pass.

## Checklist

- [x] Project is under `submissions/NGUYEN_HUNTER/` with its own `platformio.ini`, following the module's LAST_FIRST folder format.
- [x] Both `uno_i2c` and `uno_spi` build cleanly locally.
- [ ] I have actually flashed and tested both modes on a real Uno with a BME280.

## Anything you got stuck on

The local computer had no GCC host compiler. The separate native test configuration supports Zig as a local fallback, and the nine controller tests passed. No Uno serial device was available; physical wiring, uploads, live temperature/blink behavior, GitHub CI, and lead approval remain unverified.
