/**
 * @file helper_runtime.c
 * 
 * @brief Abstract startup interface for bare-metal embedded systems.
 * 
 * Provides data and bss initialization, system init, and main entry point abstractions.
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

/*
 * -----------INCLUDES------------------
 */
#include "../../../inc/project.h"

#include "private/helper_runtime.h"
#include "../inc/helper_runtime.h"

/*
 * -----------FUNCTIONS DEFINATIONS------------------
 */

/**
 * @brief provides interface to initialize runtime during startup
 * 
 * @param sidata Pointer to start of source in flash (const)
 * @param sdata  Pointer to start of destination in RAM
 * @param edata  Pointer to end of destination in RAM (exclusive)
 * @param sbss   Pointer to start of destination in RAM for bss section 
 * @param ebss   Pointer to end of destination in RAM (exclusive)
 * 
 * @return error_t ERR_OK on success, error code otherwise
 */
error_t helper_runtime_init( const uint32_t *sidata, uint32_t *sdata, uint32_t *edata, uint32_t *sbss, uint32_t *ebss )
{
    error_t retValue = ERR_OK;

    retValue = helper_runtime_copyDataSection( sidata, sdata, edata );

    if( ERR_OK == retValue )
    {
        retValue = helper_runtime_zeroBssSection( sbss, ebss );
    }

    return retValue;
}

/**
 * @brief Copies initialized data from flash to RAM (.data section)
 * 
 * @param src Pointer to start of source in flash (const)
 * @param dst Pointer to start of destination in RAM
 * @param end Pointer to end of destination in RAM (exclusive)
 * 
 * @return error_t ERR_OK on success, error code otherwise
 */
error_t helper_runtime_copyDataSection( const uint32_t *src, uint32_t *dst, uint32_t *end ) 
{
    if (!src || !dst || !end) 
    {
        return ERR_NULL_PTR;
    }

    if (dst >= end) 
    {
        return ERR_INVALID_PARAM; // Invalid range
    }

    while (dst < end) 
    {
        *dst++ = *src++;
    }

    return ERR_OK;
}

/**
 * @brief Zero out BSS section
 * 
 * @param dst Pointer to start of destination in RAM for bss section
 * @param end Pointer to end of destination in RAM (exclusive)
 * 
 * @return error_t ERR_OK on success, error code otherwise
 */
error_t helper_runtime_zeroBssSection( uint32_t *dst, uint32_t *end ) 
{
    if (!dst || !end) 
    {
        return ERR_NULL_PTR;
    }

    if (dst >= end) 
    {
        return ERR_INVALID_PARAM; // Invalid range
    }

    while (dst < end) 
    {
        *dst++ = 0;
    }

    return ERR_OK;
}