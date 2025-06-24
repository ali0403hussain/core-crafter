/**
 * @file reg_xosc.h
 * 
 * @description XOSC registers
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef REG_XOSC_H_INCLUDE
#define REG_XOSC_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../std-lib/type/inc/types.h"
#include "reg_map.h"
#include "../inc/platform_def.h"


/**
 * @brief XOSC Register typedef struct
 */
typedef struct 
{
    reg_rw_32 ctrl;
    reg_rw_32 status;
    reg_rw_32 dormant;
    reg_rw_32 startup;
    uint32_t _pad[3];
    reg_rw_32 count;
}reg_xosc_t;

#define REG_XOSC            ((reg_xosc_t*)XOSC_BASE)


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // REG_XOSC_H_INCLUDE

