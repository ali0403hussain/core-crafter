# === Configuration ===
BUILD_DIR := build
OUTPUT_DIR := tools/output
TOOLCHAIN_FILE := cmake/rp2040_toolchain.cmake
TARGET := core-crafter_app_sc_blinky
GENERATOR := Ninja  # Ninja or "Unix Makefiles" if you're not using Ninja

# === Default Target ===
all: configure build

# === Configure CMake ===
configure:
	cmake -S . -B $(BUILD_DIR) \
		-G $(GENERATOR) \
		-DCMAKE_TOOLCHAIN_FILE=$(TOOLCHAIN_FILE) \
		-DCMAKE_BUILD_TYPE=Debug

# === Build Project ===
build:
	cmake --build $(BUILD_DIR)

# === Clean Build Folder ===
clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(OUTPUT_DIR)
	mkdir $(OUTPUT_DIR)
	touch $(OUTPUT_DIR)/.gitkeep

# === Rebuild Everything ===
rebuild: clean all

# === Flash if needed (example using OpenOCD) ===
flash:
	openocd -f interface/picoprobe.cfg -f target/rp2040.cfg -c "program $(BUILD_DIR)/$(TARGET).elf verify reset exit"

.PHONY: all configure build clean rebuild flash
