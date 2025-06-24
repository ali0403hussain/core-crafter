/**
 * @file reg_m0plus.h
 * 
 * @brief   The ARM Cortex-M0+ registers registers
 * @details The ARM Cortex-M0+ Core registers.
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef REG_M0_PLUS_H_INCLUDE
#define REG_M0_PLUS_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif


/*
* -----------INCLUDES------------------
*/

#include "../../../std-lib/type/inc/types.h"
#include "reg_map.h"


/*
* -----------TYPEDEF, STRUCT ENUM------------------
*/

/**
 * @brief MO-Plus Register typedef struct
 */
typedef struct 
{
    uint32_t _pad0[14340];
    reg_rw_32 syst_csr;
    reg_rw_32 syst_rvr;
    reg_rw_32 syst_cvr;
    reg_ro_32 syst_calib;
    uint32_t _pad1[56];
    reg_rw_32 nvic_iser;
    uint32_t _pad2[31];
    reg_rw_32 nvic_icer;
    uint32_t _pad3[31];
    reg_rw_32 nvic_ispr;
    uint32_t _pad4[31];
    reg_rw_32 nvic_icpr;
    uint32_t _pad5[95];
    reg_rw_32 nvic_ipr[8];
    uint32_t _pad6[568];
    reg_ro_32 cpuid;
    reg_rw_32 icsr;
    reg_rw_32 vtor;
    reg_rw_32 aircr;
    reg_rw_32 scr;
    reg_ro_32 ccr;
    uint32_t _pad7;
    reg_rw_32 shpr[2];
    reg_rw_32 shcsr;
    uint32_t _pad8[26];
    reg_ro_32 mpu_type;
    reg_rw_32 mpu_ctrl;
    reg_rw_32 mpu_rnr;
    reg_rw_32 mpu_rbar;
    reg_rw_32 mpu_rasr;
}reg_m0plus_t;

#define REG_M0_PLUS            ((reg_m0plus_t*)PPB_BASE)


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // REG_M0_PLUS_H_INCLUDE

