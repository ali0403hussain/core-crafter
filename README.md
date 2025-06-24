# Core Crafter — Bare Metal Microcontroller Development

Welcome to **Core Crafter**, a collection of bare-metal development stacks for different microcontrollers. This repository contains complete register-level drivers, HAL layers, build system, and sample applications — all written from scratch without relying on any vendor SDK.

> Currently supporting: **Raspberry Pi RP2040 (initial stage)**  
> More microcontrollers will be added soon.

---

## Repository Structure

```bash
.
├── dev/                  # Core source code
│   ├── app/              # Application layer (example: blinky app for RP2040)
│   ├── hal/              # Hardware Abstraction Layer
│   ├── hardware/         # MCU specific register-level drivers & system code
│   │   └── rp2040/       # RP2040 specific drivers, registers, startup, boot
│   ├── inc/              # Global project includes
│   └── std-lib/          # Standard library components (types, helper functions)
│
├── tools/                # Tools for firmware conversion, patching, utilities
├── docs/                 # Datasheets and reference documents
├── tests/                # Unit tests (planned)
├── cmake/                # CMake toolchain files
├── build/                # Build output (generated)
│
├── LICENSE.md            # License file
├── README.md             # This file
├── CMakeLists.txt        # CMake configuration
├── Makefile              # Build helper
└── ...                   # Other documentation files (CONTRIBUTING, CODE_OF_CONDUCT, AUTHORS)
```

---

## Features

- Complete bare-metal stack for supported microcontrollers.
- No vendor SDKs — pure register-level drivers.
- Modular layered architecture:
  - Register Drivers
  - HAL Layer
  - Sample Applications
  - Startup & Boot Code
- CMake-based build system.

---

## Current Status

- ✅ RP2040 initial bring-up
  - GPIO register driver
  - HAL GPIO abstraction
  - Minimal startup code
  - Boot Stage 2 support
  - Blinky sample app

---

## Build Instructions

### Prerequisites

- CMake 3.22+
- ARM GCC Toolchain (e.g., `arm-none-eabi-gcc`)
- Python 3.x (for uf2 tools)

### Build Example

```bash
# Clone repository
git clone <repo-url>
cd <repo-folder>

# Create build directory
mkdir build 

# Build
make rebuild
```
Outputs will be generated in tools/output/ and build/ folders.

---

## Roadmap
Expand RP2040 driver coverage (Clock, UART, Timers, etc.)
- Add more MCUs (STM32, NXP, ESP32, etc.)
- Add unit tests
- Add board support for multiple hardware platforms

---

## Contribution
Contributions are welcome! Please read:

[CONTRIBUTING.md](CONTRIBUTING.md)  
[CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md)

---

## License
Distributed under the terms of [LICENSE.md](LICENSE.md)

---

## Disclaimer
This project is intended for educational, research, and hobby purposes. Use at your own risk.


