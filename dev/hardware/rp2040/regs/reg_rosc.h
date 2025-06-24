/**
 * @file reg_rosc.h
 * 
 * @description ROSC registers
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef REG_ROSC_H_INCLUDE
#define REG_ROSC_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../std-lib/type/inc/types.h"
#include "reg_map.h"
#include "../inc/platform_def.h"


/**
 * @brief ROSC Register typedef struct
 */
typedef struct 
{
    reg_rw_32 ctrl;
    reg_rw_32 freqa;
    reg_rw_32 freqb;
    reg_rw_32 dormant;
    reg_rw_32 div;
    reg_rw_32 phase;
    reg_rw_32 status;
    reg_ro_32 randombit;
    reg_rw_32 count;
}reg_rosc_t;

#define REG_ROSC            ((reg_rosc_t*)ROSC_BASE)


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // REG_ROSC_H_INCLUDE

