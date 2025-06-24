#!/usr/bin/env python3

import argparse
import struct
import zlib

# RP2040 boot2 image properties
BOOT2_EXPECTED_SIZE = 256
BOOT2_CRC_OFFSET = 252

def compute_crc(data):
    # RP2040 ROM expects CRC32 with polynomial 0x1EDC6F41 (same as standard zlib crc32)
    crc = zlib.crc32(data[:BOOT2_CRC_OFFSET]) & 0xFFFFFFFF
    return crc

def process_boot2(input_file, output_file):
    with open(input_file, "rb") as f:
        data = f.read()

    # Pad to 256 bytes if necessary
    if len(data) < BOOT2_EXPECTED_SIZE:
        data += b'\x00' * (BOOT2_EXPECTED_SIZE - len(data))
    elif len(data) > BOOT2_EXPECTED_SIZE:
        raise ValueError(f"Input boot2 binary too large ({len(data)} bytes)")

    crc = compute_crc(data)
    # Insert CRC at offset 252 (last 4 bytes)
    data = data[:BOOT2_CRC_OFFSET] + struct.pack("<I", crc)

    with open(output_file, "wb") as f:
        f.write(data)

    print(f"Processed {input_file} -> {output_file}")
    print(f"Inserted CRC32: 0x{crc:08X}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="RP2040 Boot2 CRC Patcher")
    parser.add_argument("input", help="Input boot2 binary file (without CRC)")
    parser.add_argument("output", help="Output boot2 binary file (with CRC)")

    args = parser.parse_args()
    process_boot2(args.input, args.output)
