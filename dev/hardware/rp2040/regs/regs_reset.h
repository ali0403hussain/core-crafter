/**
 * @file reg_reset.h
 * 
 * @description RESET registers
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef REG_RESET_H_INCLUDE
#define REG_RESET_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../std-lib/type/inc/types.h"
#include "reg_map.h"
#include "../inc/platform_def.h"


/**
 * @brief RESET Register typedef struct
 */
typedef struct 
{
    reg_rw_32 reset;
    reg_rw_32 wdsel;
    reg_ro_32 reset_done;
}reg_reset_t;

#define REG_RESET            ((reg_reset_t*)RESETS_BASE)


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // REG_RESET_H_INCLUDE

