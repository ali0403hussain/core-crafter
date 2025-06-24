/**
 * @file reg_clock.h
 * 
 * @description CLOCK registers
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef REG_CLOCK_H_INCLUDE
#define REG_CLOCK_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../std-lib/type/inc/types.h"
#include "reg_map.h"
#include "../inc/platform_def.h"


/*
* -----------DEFINES------------------
*/

/**
 * @brief       CLOCKS_CLK_CTRL_ENABLE
 * @description Starts and stops the clock generator cleanly
 */
#define CLOCKS_CLK_CTRL_ENABLE_BITS      (0x00000800u)

/**
 * @brief       CLOCKS_FC0_STATUS_RUNNING
 * @description Status Running
 */
#define CLOCKS_FC0_STATUS_RUNNING_BITS   (0x00000100u)

/**
 * @brief       CLOCKS_FC0_STATUS_DONE
 * @description Status Done
 */
#define CLOCKS_FC0_STATUS_DONE_RESET     (0x0u)
#define CLOCKS_FC0_STATUS_DONE_BITS      (0x00000010u)

/**
 * @brief       CLOCKS_FC0_RESULT_KHZ
 * @description Results 
 */
#define CLOCKS_FC0_RESULT_KHZ_RESET      (0x0000000u)
#define CLOCKS_FC0_RESULT_KHZ_BITS       (0x3fffffe0u)
#define CLOCKS_FC0_RESULT_KHZ_MSB        (29u)
#define CLOCKS_FC0_RESULT_KHZ_LSB        (5u)


/*
* -----------TYPEDEF, STRUCT ENUM------------------
*/

/**
 * @brief Clock Ctrl Div and Select Register typedef struct
 */
typedef struct 
{
    reg_rw_32 ctrl;
    reg_rw_32 div;
    reg_ro_32 selected;
}reg_clock_ctrl_div_sel_t;

/**
 * @brief Clock Peri Ctrl and Select Register typedef struct
 */
typedef struct 
{
    reg_rw_32 ctrl;
    uint32_t  _pad;
    reg_ro_32 selected;
}reg_clock_peri_ctrl_div_sel_t;

/**
 * @brief Clock Sys Resus ctrl and Select Register typedef struct
 */
typedef struct 
{
    reg_rw_32 ctrl;
    reg_ro_32 selected;
}reg_clock_resus_ctrl_sel_t;

/**
 * @brief Clock FC Register typedef struct
 */
typedef struct 
{
    reg_rw_32 ref_khz;
    reg_rw_32 min_khz;
    reg_rw_32 max_khz;
    reg_rw_32 delay;
    reg_rw_32 interval;
    reg_rw_32 src;
    reg_ro_32 status;
    reg_ro_32 result;
}reg_clock_fc_t;

/**
 * @brief Clock Register typedef struct
 */
typedef struct 
{
    union 
    {
        reg_clock_ctrl_div_sel_t clk_ctrl_0[6];
        struct
        {
            reg_clock_ctrl_div_sel_t gpout_0;
            reg_clock_ctrl_div_sel_t gpout_1;
            reg_clock_ctrl_div_sel_t gpout_2;
            reg_clock_ctrl_div_sel_t gpout_3;
            reg_clock_ctrl_div_sel_t ref;
            reg_clock_ctrl_div_sel_t sys;
        };
        
    };
    reg_clock_peri_ctrl_div_sel_t peri;
    union 
    {
        reg_clock_ctrl_div_sel_t clk_ctrl_1[3];
        struct
        {
            reg_clock_ctrl_div_sel_t usb;
            reg_clock_ctrl_div_sel_t adc;
            reg_clock_ctrl_div_sel_t rtc;
        };
        
    };
    reg_clock_resus_ctrl_sel_t resus;
    reg_clock_fc_t             fc0;
    union 
    {
        struct 
        {
            reg_rw_32 wake_en0; 
            reg_rw_32 wake_en1; 
        };
        reg_rw_32 wake_en[2];
    };
    union 
    {
        struct 
        {
            reg_rw_32 sleep_en0; 
            reg_rw_32 sleep_en1; 
        };
        reg_rw_32 sleep_en[2];
    };
    union 
    {
        struct 
        {
            reg_ro_32 enabled0;
            reg_ro_32 enabled1; 
        }; 
        reg_ro_32 enabled[2];
    };
    reg_ro_32 intr;
    reg_rw_32 inte;
    reg_rw_32 intf;
    reg_ro_32 ints;
}reg_clock_t;

#define REG_CLOCK            ((reg_clock_t*)CLOCKS_BASE)


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // REG_CLOCK_H_INCLUDE

