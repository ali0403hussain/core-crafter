/**
 * @file reg_map.h
 * 
 * @description registers mapping file
 * 
 * @ref Data taken from doc/device/rp2040/rp2040-datasheet.pdf/2.2 Address Map
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef REG_MAP_H_INCLUDE
#define REG_MAP_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif


/*
 * -----------DEFINES------------------
 */

#define ROM_BASE                    (0x00000000u)
#define XIP_BASE                    (0x10000000u)
#define XIP_MAIN_BASE               (0x10000000u)
#define XIP_NOALLOC_BASE            (0x11000000u)
#define XIP_NOCACHE_BASE            (0x12000000u)
#define XIP_NOCACHE_NOALLOC_BASE    (0x13000000u)
#define XIP_CTRL_BASE               (0x14000000u)
#define XIP_SRAM_BASE               (0x15000000u)
#define XIP_SRAM_END                (0x15004000u)
#define XIP_SSI_BASE                (0x18000000u)
#define SRAM_BASE                   (0x20000000u)
#define SRAM_STRIPED_BASE           (0x20000000u)
#define SRAM_STRIPED_END            (0x20040000u)
#define SRAM4_BASE                  (0x20040000u)
#define SRAM5_BASE                  (0x20041000u)
#define SRAM_END                    (0x20042000u)
#define SRAM0_BASE                  (0x21000000u)
#define SRAM1_BASE                  (0x21010000u)
#define SRAM2_BASE                  (0x21020000u)
#define SRAM3_BASE                  (0x21030000u)
#define SYSINFO_BASE                (0x40000000u)
#define SYSCFG_BASE                 (0x40004000u)
#define CLOCKS_BASE                 (0x40008000u)
#define RESETS_BASE                 (0x4000c000u)
#define PSM_BASE                    (0x40010000u)
#define IO_BANK0_BASE               (0x40014000u)
#define IO_QSPI_BASE                (0x40018000u)
#define PADS_BANK0_BASE             (0x4001c000u)
#define PADS_QSPI_BASE              (0x40020000u)
#define XOSC_BASE                   (0x40024000u)
#define PLL_SYS_BASE                (0x40028000u)
#define PLL_USB_BASE                (0x4002c000u)
#define BUSCTRL_BASE                (0x40030000u)
#define UART0_BASE                  (0x40034000u)
#define UART1_BASE                  (0x40038000u)
#define SPI0_BASE                   (0x4003c000u)
#define SPI1_BASE                   (0x40040000u)
#define I2C0_BASE                   (0x40044000u)
#define I2C1_BASE                   (0x40048000u)
#define ADC_BASE                    (0x4004c000u)
#define PWM_BASE                    (0x40050000u)
#define TIMER_BASE                  (0x40054000u)
#define WATCHDOG_BASE               (0x40058000u)
#define RTC_BASE                    (0x4005c000u)
#define ROSC_BASE                   (0x40060000u)
#define VREG_AND_CHIP_RESET_BASE    (0x40064000u)
#define TBMAN_BASE                  (0x4006c000u)
#define DMA_BASE                    (0x50000000u)
#define USBCTRL_DPRAM_BASE          (0x50100000u)
#define USBCTRL_BASE                (0x50100000u)
#define USBCTRL_REGS_BASE           (0x50110000u)
#define PIO0_BASE                   (0x50200000u)
#define PIO1_BASE                   (0x50300000u)
#define XIP_AUX_BASE                (0x50400000u)
#define SIO_BASE                    (0xd0000000u)
#define SIO_GPIO_BASE               (0xd0000004u)
#define SIO_DIV_BASE                (0xd0000060u)
#define SIO_INTERP_0_BASE           (0xd0000080u)
#define PPB_BASE                    (0xe0000000u)


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // REG_MAP_H_INCLUDE

