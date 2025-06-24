/**
 * @file reg_pll.h
 * 
 * @description PLL registers
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef REG_PLL_H_INCLUDE
#define REG_PLL_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../std-lib/type/inc/types.h"
#include "reg_map.h"
#include "../inc/platform_def.h"


/**
 * @brief Pll Register typedef struct
 */
typedef struct 
{
    reg_rw_32 cs;
    reg_rw_32 pwr;
    reg_rw_32 fbdiv_int;
    reg_rw_32 prim;
}reg_pll_t;

#define REG_PLL_SYS            ((reg_pll_t*)PLL_SYS_BASE)
#define REG_PLL_USB            ((reg_pll_t*)PLL_USB_BASE)


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // REG_PLL_H_INCLUDE

