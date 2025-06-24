/**
 * @file reg_watchdog.h
 * 
 * @description WATCH DOG registers
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef REG_WDOG_H_INCLUDE
#define REG_WDOG_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../std-lib/type/inc/types.h"
#include "reg_map.h"
#include "../inc/platform_def.h"


/**
 * @brief WDOG Register typedef struct
 */
typedef struct 
{
    reg_rw_32 ctrl;
    reg_wo_32 load;
    reg_ro_32 reason;
    reg_rw_32 scratch[8];
    reg_rw_32 tick;
}reg_wdog_t;

#define REG_WDOG            ((reg_wdog_t*)WATCHDOG_BASE)


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // REG_WDOG_H_INCLUDE

