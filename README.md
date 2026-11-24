# Rangefinder (UCF EEL 3926L)

Embedded C firmware for an **MSP430G2553** ultrasonic rangefinder system built in **Code Composer Studio** for University of Central Florida Junior Design (`EEL 3926L`).

## Hardware & Peripherals
- **MCU:** TI MSP430G2553 (`8 MHz` MCLK)
- **Distance Sensing:** Ultrasonic range sensor with a `510 Ω` / `1 kΩ` voltage divider on the echo line to step `5 V` echo logic down to `3.3 V`
- **Display:** `16x2` character LCD over `I2C` (`P1.6` SCL, `P1.7` SDA; default address `0x27`)
- **Analog & PWM Control:** `10 kΩ` potentiometer read via `10-bit` `ADC` (`0–3.3 V` -> `0–1023`) scaled to `PWM` duty cycle (`0–100%`) for LED brightness control
- **Status Indicator:** MOSFET-switched LED (`BS170`) for blink/status signaling
- **Power & Debug:** `3.3 V` (`TPS613221ADBVR`) and `5.0 V` (`TPS613222ADBVR`) boost regulator rails (`2.4 V–3.3 V` dual-AA input) and Spy-Bi-Wire programming/debug interface

## Repository Structure
- `main.c` — Main application loop handling sensor triggering/echo timing, ADC scaling, LCD updates, and LED/PWM behavior
- `Junior_Design.h` — Hardware initialization (`Init_HW`), timer/loop delays, ADC/ultrasonic helpers, and LCD driver functions
- `lnk_msp430g2553.cmd` — Linker command file for the MSP430G2553 memory map

## Build & Flash
1. Open the project in **Code Composer Studio** (`MSP430G2553` target).
2. Verify pin/channel `#defines` (`LCD_SCL`, `LCD_SDA`, `USENSOR_TRIGGER`, `ECHO_INTERUPT`, `ADC_INPUTPIN`, `ADC_INPUT`, `ADC_LED`) match your wiring.
3. Build the project and flash to the target via Spy-Bi-Wire (`SBWTDIO` / `SBWTCK`).
