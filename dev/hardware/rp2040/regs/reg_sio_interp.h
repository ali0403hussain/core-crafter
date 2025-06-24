/**
 * @file reg_sio_interp.h
 * 
 * @description SIO INTERP registers
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef REG_SIO_INTERP_H_INCLUDE
#define REG_SIO_INTERP_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif


#include "../../../std-lib/type/inc/types.h"
#include "reg_map.h"

/**
 * @brief SIO_DIV Register typedef struct
 */
typedef struct 
{
    reg_rw_32 accum0;
    reg_rw_32 accum1;
    reg_rw_32 base0;
    reg_rw_32 base1;
    reg_rw_32 base2;
    reg_ro_32 popLane0;
    reg_ro_32 popLane1;
    reg_ro_32 popLaneFull;
    reg_ro_32 peekLane0;
    reg_ro_32 peekLane1;
    reg_ro_32 peekLaneFull;
    reg_rw_32 ctrlLane0;
    reg_rw_32 ctrlLane1;
    reg_rw_32 accum0add;
    reg_rw_32 accum1add;
    reg_wo_32 base01;
}reg_sio_interp_t;

#define REG_SIO_INTERP_ARRAY            ((reg_sio_interp_t*)SIO_INTERP_0_BASE)
#define REG_SIO_INTERP_0                (&REG_SIO_INTERP_ARRAY[0])
#define REG_SIO_INTERP_1                (&REG_SIO_INTERP_ARRAY[1])


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // REG_SIO_INTERP_H_INCLUDE

