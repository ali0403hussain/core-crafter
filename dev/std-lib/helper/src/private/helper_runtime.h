/**
 * @file private/helper_runtimeinit.h
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

#ifdef __cplusplus
extern "C" {
#endif

#ifndef PRIVATE_HELPER_RUNTIME_H_INCLUDE
#define PRIVATE_HELPER_RUNTIME_H_INCLUDE

/*
 * -----------FUNCTIONS DECLERATION------------------
 */

/**
 * @brief Copies initialized data from flash to RAM (.data section)
 * 
 * @param src Pointer to start of source in flash (const)
 * @param dst Pointer to start of destination in RAM
 * @param end Pointer to end of destination in RAM (exclusive)
 * 
 * @return error_t ERR_OK on success, error code otherwise
 */
static error_t helper_runtime_copyDataSection( const uint32_t *src, uint32_t *dst, uint32_t *end );

/**
 * @brief Zero out BSS section
 * 
 * @param dst Pointer to start of destination in RAM for bss section
 * @param end Pointer to end of destination in RAM (exclusive)
 * 
 * @return error_t ERR_OK on success, error code otherwise
 */
static error_t helper_runtime_zeroBssSection( uint32_t *dst, uint32_t *end );


#endif //PRIVATE_HELPER_RUNTIME_H_INCLUDE

#ifdef __cplusplus
}
#endif // __cplusplus
