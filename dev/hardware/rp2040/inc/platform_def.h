/**
 * @file platform_def.h
 * 
 * @description Platform definations including peripherals cores etc
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef PLATFORM_DEF_H_INCLUDE
#define PLATFORM_DEF_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif


#define NUM_CORES               (2u)
#define NUM_DMA_CHANNELS        (12u)
#define NUM_DMA_TIMERS          (4u)
#define NUM_DMA_IRQS            (2u)
#define NUM_IRQS                (32u)
#define NUM_USER_IRQS           (6u)
#define NUM_PIOS                (2u)
#define NUM_PIO_STATE_MACHINES  (4u)
#define NUM_PIO_IRQS            (2u)
#define NUM_PWM_SLICES          (8u)
#define NUM_PWM_IRQS            (1u)
#define NUM_SPIN_LOCKS          (32u)
#define NUM_UARTS               (2u)
#define NUM_I2CS                (2u)
#define NUM_SPIS                (2u)
#define NUM_GENERIC_TIMERS      (1u)
#define NUM_ALARMS              (4u)
#define ADC_BASE_PIN            (26u)
#define NUM_ADC_CHANNELS        (5u)
#define NUM_RESETS              (24u)
#define NUM_BANK0_GPIOS         (30u)
#define NUM_QSPI_GPIOS          (6u)
#define PIO_INSTRUCTION_COUNT   (32u)
#define USBCTRL_DPRAM_SIZE      (4096u)


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // PLATFORM_DEF_H_INCLUDE


