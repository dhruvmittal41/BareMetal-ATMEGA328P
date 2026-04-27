# ATmega328P Bare-Metal C 

![C](https://img.shields.io/badge/Language-C-blue.svg)
![Microcontroller](https://img.shields.io/badge/MCU-ATmega328P-orange.svg)
![Board](https://img.shields.io/badge/Board-Arduino_Uno-teal.svg)

A collection of bare-metal C programs for the Arduino Uno (ATmega328P). This repository documents my journey of learning embedded systems from the ground up, bypassing the Arduino IDE and high-level libraries to directly manipulate hardware registers.

## 🧠 Why Bare Metal?

While frameworks like the Arduino core are excellent for rapid prototyping, they obscure the underlying hardware architecture. This repository is dedicated to mastering silicon-level programming by:
* **Reading the Datasheet:** Translating ATmega328P datasheet specifications directly into C code.
* **Direct Register Manipulation:** Controlling peripherals (GPIO, Timers, ADC, UART) via memory-mapped registers.
* **Understanding the Build Process:** Managing compilation, linking, and flashing manually using standard GNU toolchains rather than clicking "Upload" in an IDE.
* **Optimizing Performance:** Writing deterministic, highly efficient code with minimal overhead.

## 🛠️ Hardware Requirements

* **Development Board:** Arduino Uno Rev3 (or any ATmega328P-based board)
* **Peripherals:** LEDs, resistors (220Ω - 330Ω), jumper wires, breadboard
* **Interface:** Standard USB Type-A to Type-B cable

## 💻 Toolchain Setup

To build and flash these programs, you will need the AVR GCC toolchain and AVRDUDE. 

**For Linux (Debian/Ubuntu):**
```bash
sudo apt-get update
sudo apt-get install gcc-avr binutils-avr avr-libc avrdude make