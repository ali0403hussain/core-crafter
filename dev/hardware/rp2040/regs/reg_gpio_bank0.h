/**
 * @file reg_gpio_bank0.h
 * 
 * @description GPIO IO Bank0 registers
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef REG_GPIO_BANK_0_H_INCLUDE
#define REG_GPIO_BANK_0_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../std-lib/type/inc/types.h"
#include "reg_map.h"
#include "../inc/platform_def.h"


/*
* -----------DEFINES------------------
*/

/**
 * @brief       IO_BANK0_GPIO_CTRL_IRQOVER
 * @description 0x0 -> don't invert the interrupt
 *              0x1 -> invert the interrupt
 *              0x2 -> drive interrupt low
 *              0x3 -> drive interrupt high
 */
#define IO_BANK0_GPIO_CTRL_IRQOVER_BITS   (0x30000000u)
#define IO_BANK0_GPIO_CTRL_IRQOVER_MSB    (29u)
#define IO_BANK0_GPIO_CTRL_IRQOVER_LSB    (28u)

/**
 * @brief       IO_BANK0_GPIO_CTRL_INOVER
 * @description 0x0 -> don't invert the peri input
 *              0x1 -> invert the peri input
 *              0x2 -> drive peri input low
 *              0x3 -> drive peri input high
 */
#define IO_BANK0_GPIO_CTRL_INOVER_BITS   (0x00030000u)
#define IO_BANK0_GPIO_CTRL_INOVER_MSB    (17u)
#define IO_BANK0_GPIO_CTRL_INOVER_LSB    (16u)

/**
 * @brief       IO_BANK0_GPIO_CTRL_OEOVER
 * @description 0x0 -> drive output enable from peripheral signal selected by funcsel
 *              0x1 -> drive output enable from inverse of peripheral signal selected by funcsel
 *              0x2 -> disable output
 *              0x3 -> enable output
 */
#define IO_BANK0_GPIO_CTRL_OEOVER_BITS   (0x00003000u)
#define IO_BANK0_GPIO_CTRL_OEOVER_MSB    (13u)
#define IO_BANK0_GPIO_CTRL_OEOVER_LSB    (12u)

/**
 * @brief       IO_BANK0_GPIO_CTRL_OUTOVER
 * @description 0x0 -> drive output from peripheral signal selected by funcsel
 *              0x1 -> drive output from inverse of peripheral signal selected by funcsel
 *              0x2 -> drive output low
 *              0x3 -> drive output high
 */
#define IO_BANK0_GPIO_CTRL_OUTOVER_BITS   (0x00000300u)
#define IO_BANK0_GPIO_CTRL_OUTOVER_MSB    (9u)
#define IO_BANK0_GPIO_CTRL_OUTOVER_LSB    (8u)

/**
 * @brief       IO_BANK0_GPIO_CTRL_FUNCSEL
 * @description 0-31 -> selects pin function according to the gpio table
 *              31 == NULL
 *              0x00 -> jtag_tck
 *              0x01 -> spi0_rx
 *              0x02 -> uart0_tx
 *              0x03 -> i2c0_sda
 *              0x04 -> pwm_a_0
 *              0x05 -> sio_0
 *              0x06 -> pio0_0
 *              0x07 -> pio1_0
 *              0x09 -> usb_muxing_overcurr_detect
 *              0x1f -> null
 */
#define IO_BANK0_GPIO_CTRL_FUNCSEL_BITS   (0x0000001fu)
#define IO_BANK0_GPIO_CTRL_FUNCSEL_MSB    (4u)
#define IO_BANK0_GPIO_CTRL_FUNCSEL_LSB    (0u)

/**
 * @brief GPIO STATUS CTRL Register typedef struct
 */
typedef struct 
{
    reg_ro_32 status;
    reg_rw_32 ctrl;
}reg_gpio_status_ctrl_t;

/**
 * @brief GPIO INTERUPT CTRL Register typedef struct
 */
typedef struct 
{
    reg_rw_32 inte[4];
    reg_rw_32 intf[4];
    reg_rw_32 ints[4];
}reg_gpio_irq_ctrl_t;

/**
 * @brief GPIO Register typedef struct
 */
typedef struct 
{
    reg_gpio_status_ctrl_t statusCtrl[NUM_BANK0_GPIOS];
    reg_rw_32              intr[4];
    union 
    {
        reg_gpio_irq_ctrl_t irq_ctrl[3];
        struct {
            reg_gpio_irq_ctrl_t proc0_irq_ctrl;
            reg_gpio_irq_ctrl_t proc1_irq_ctrl;
            reg_gpio_irq_ctrl_t dormant_wake_irq_ctrl;
        };
    };
    
}reg_gpio_bank0_t;

#define REG_GPIO_BANK_0            ((reg_gpio_bank0_t*)IO_BANK0_BASE)


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // REG_GPIO_BANK_0_H_INCLUDE

