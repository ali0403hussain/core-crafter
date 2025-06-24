/**
 * @file reg_syscfg.h
 * 
 * @description SYS_CFG registers
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef REG_SYS_CFG_H_INCLUDE
#define REG_SYS_CFG_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../std-lib/type/inc/types.h"
#include "reg_map.h"
#include "../inc/platform_def.h"


/**
 * @brief SYS_CFG Register typedef struct
 */
typedef struct 
{
    reg_rw_32 proc0_nmi_mask;
    reg_rw_32 proc1_nmi_mask;
    reg_rw_32 proc_config;
    reg_rw_32 proc_in_sync_bypass;
    reg_rw_32 proc_in_sync_bypass_hi;
    reg_rw_32 dbgforce;
    reg_rw_32 mempowerdown;
}reg_sys_cfg_t;

#define REG_SYS_CFG            ((reg_sys_cfg_t*)SYSCFG_BASE)


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // REG_SYS_CFG_H_INCLUDE

