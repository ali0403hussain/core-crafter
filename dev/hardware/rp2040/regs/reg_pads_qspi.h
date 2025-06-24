/**
 * @file reg_pads_qspi.h
 * 
 * @brief   Pads Qspi registers
 * @details The QSPI Bank Pad Control registers
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef REG_PADS_QSPI_H_INCLUDE
#define REG_PADS_QSPI_H_INCLUDE

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
 * @brief Pads Qspi Register typedef struct
 */
typedef struct 
{
    reg_rw_32 voltage_select;
    reg_rw_32 gpio_qspi_sclk;
    reg_rw_32 gpio_qspi_sd_0;
    reg_rw_32 gpio_qspi_sd_1;
    reg_rw_32 gpio_qspi_sd_2;
    reg_rw_32 gpio_qspi_sd_3;
    reg_rw_32 gpio_qspi_ss;
}reg_pads_qspi_t;

#define REG_PADS_QSPI            ((reg_pads_qspi_t*)PADS_QSPI_BASE)


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // REG_PADS_QSPI_H_INCLUDE

