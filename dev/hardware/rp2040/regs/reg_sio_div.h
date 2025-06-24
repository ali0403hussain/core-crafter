/**
 * @file reg_sio_div.h
 * 
 * @description SIO DIV registers
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef REG_SIO_DIV_H_INCLUDE
#define REG_SIO_DIV_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif


#include "../../../std-lib/type/inc/types.h"
#include "reg_map.h"

#define SIO_DIV_CSR_READY       (1u << 0)
#define SIO_DIV_CSR_BUSY        (1u << 1)

/**
 * @brief SIO_DIV Register typedef struct
 */
typedef struct 
{
    reg_rw_32 div_udividend;
    reg_rw_32 div_udivisor;
    reg_rw_32 div_sdividend;
    reg_rw_32 div_sdivisor;
    reg_rw_32 div_quotient;
    reg_rw_32 div_remainder;
    reg_ro_32 div_csr;
}reg_sio_div_t;

#define REG_SIO_DIV            ((reg_sio_div_t*)SIO_DIV_BASE)


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // REG_SIO_DIV_H_INCLUDE

