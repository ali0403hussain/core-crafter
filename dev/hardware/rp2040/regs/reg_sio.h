/**
 * @file reg_sio.h
 * 
 * @description SIO registers
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef REG_SIO_H_INCLUDE
#define REG_SIO_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif


#include "../../../std-lib/type/inc/types.h"
#include "reg_map.h"
#include "reg_sio_gpio.h"
#include "reg_sio_div.h"
#include "reg_sio_interp.h"

/**
 * @brief SIO Register typedef struct
 */
typedef struct {
    reg_ro_32        cpuid; 
    reg_sio_gpio_t   gpio;
    reg_rw_32        fifo_st;
    reg_wo_32        fifo_wr;
    reg_ro_32        fifo_rd;
    reg_ro_32        spinlock_st;
    reg_sio_div_t    div;
    reg_sio_interp_t interp[2];
    reg_rw_32        spinlock[32];
}reg_sio_t;

#define REG_SIO            ((reg_sio_t*)SIO_BASE)


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // REG_SIO_H_INCLUDE


