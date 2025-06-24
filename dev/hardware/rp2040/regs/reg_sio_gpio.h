/**
 * @file reg_sio_gpio.h
 * 
 * @description SIO GPIO registers
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef REG_SIO_GPIO_H_INCLUDE
#define REG_SIO_GPIO_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif


#include "../../../std-lib/type/inc/types.h"
#include "reg_map.h"

/**
 * @brief SIO_GPIO Register typedef struct
 */
typedef struct 
{
    reg_ro_32 gpio_in;
    reg_ro_32 gpio_hi_in;
    uint32_t _pad;
    reg_rw_32 gpio_out;
    reg_wo_32 gpio_out_set;
    reg_wo_32 gpio_out_clr;
    reg_wo_32 gpio_out_xor;
    reg_rw_32 gpio_oe;
    reg_wo_32 gpio_oe_set;
    reg_wo_32 gpio_oe_clr;
    reg_wo_32 gpio_oe_xor;
    reg_rw_32 gpio_hi_out;
    reg_wo_32 gpio_hi_out_set;
    reg_wo_32 gpio_hi_out_clr;
    reg_wo_32 gpio_hi_out_xor;
    reg_rw_32 gpio_hi_oe;
    reg_wo_32 gpio_hi_oe_set;
    reg_wo_32 gpio_hi_oe_clr;
    reg_wo_32 gpio_hi_oe_xor;
}reg_sio_gpio_t;

#define REG_SIO_GPIO            ((reg_sio_gpio_t*)SIO_GPIO_BASE)


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // REG_SIO_GPIO_H_INCLUDE

