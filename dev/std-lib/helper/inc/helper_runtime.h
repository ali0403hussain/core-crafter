/**
 * @file helper_runtime.h
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

#ifndef HELPER_RUNTIME_H_INCLUDE
#define HELPER_RUNTIME_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif


/*
 * -----------FUNCTIONS DECLARATION------------------
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
error_t helper_runtime_init( const uint32_t *sidata, uint32_t *sdata, uint32_t *edata, uint32_t *sbss, uint32_t *ebss );


#ifdef __cplusplus
}
#endif // __cplusplus

#endif //HELPER_RUNTIME_H_INCLUDE

