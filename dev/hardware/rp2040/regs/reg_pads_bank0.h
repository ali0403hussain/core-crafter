/**
 * @file reg_pads_bank0.h
 * 
 * @description PADS IO Bank0 registers
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef REG_PADS_BANK_0_H_INCLUDE
#define REG_PADS_BANK_0_H_INCLUDE

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
 * @brief       PADS_BANK0_VOLTAGE_SELECT
 * @description Voltage select. Per bank control
 *              0x0 -> Set voltage to 3.3V (DVDD >= 2V5)
 *              0x1 -> Set voltage to 1.8V (DVDD <= 1V8)
 */
#define PADS_BANK0_VOLTAGE_SELECT_BITS   (0x00000001u)

/**
 * @brief       PADS_BANK0_GPIO_OD
 * @description Output disable. Has priority over output enable from peripherals
 */
#define PADS_BANK0_GPIO_OD_BITS          (0x00000080u)

/**
 * @brief       PADS_BANK0_GPIO_IE
 * @description Input enable
 */
#define PADS_BANK0_GPIO_IE_BITS          (0x00000040u)

/**
 * @brief       PADS_BANK0_GPIO_DRIVE
 * @description Drive strength.
 *              0x0 -> 2mA
 *              0x1 -> 4mA
 *              0x2 -> 8mA
 *              0x3 -> 12mA
 */
#define PADS_BANK0_GPIO_DRIVE_BITS       (0x00000030u)
#define PADS_BANK0_GPIO_DRIVE_MSB        (5u)
#define PADS_BANK0_GPIO_DRIVE_LSB        (4u)

/**
 * @brief       PADS_BANK0_GPIO_PUE
 * @description Pull up enable
 */
#define PADS_BANK0_GPIO_PUE_BITS         (0x00000008u)

/**
 * @brief       PADS_BANK0_GPIO_PDE
 * @description Pull down enable
 */
#define PADS_BANK0_GPIO_PDE_BITS         (0x00000004u)

/**
 * @brief       PADS_BANK0_GPIO_SCHMITT
 * @description Enable schmitt trigger
 */
#define PADS_BANK0_GPIO_SCHMITT_BITS     (0x00000002u)

/**
 * @brief       PADS_BANK0_GPIO0_SLEWFAST
 * @description Slew rate control. 1 = Fast, 0 = Slow
 */
#define PADS_BANK0_GPIO_SLEWFAST_BITS    (0x00000001u)


/*
* -----------STRUCT, ENUMS, TYPEDEF------------------
*/

/**
 * @brief PADS BANK 0 Register typedef struct
 */
typedef struct 
{
    reg_ro_32 voltage_select;
    reg_rw_32 gpio[NUM_BANK0_GPIOS];
}reg_pads_bank0_t;

#define REG_PADS_BANK_0            ((reg_pads_bank0_t*)PADS_BANK0_BASE)


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // REG_PADS_BANK_0_H_INCLUDE
