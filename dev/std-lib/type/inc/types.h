/**
 * @file types.h
 * 
 * @description type
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef TYPES_H_INCLUDE
#define TYPES_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif


/*
 * -----------DEFINES------------------
 */

/**
 * @brief Limits
 */
#define INT8_MAX            ( 127 )
#define INT8_MIN            ( -128 )
#define INT16_MAX           ( 32767 )
#define INT16_MIN           ( -32768 )
#define INT32_MAX           ( 2147483647 )
#define INT32_MIN           ( -2147483648 )
#define INT64_MAX           ( 9223372036854775807LL )
#define INT64_MIN           ( -9223372036854775807LL - 1 )

#define UINT8_MAX           ( 255U )
#define UINT8_MIN           ( 0U )
#define UINT16_MAX          ( 65535U )
#define UINT16_MIN          ( 0U )
#define UINT32_MAX          ( 4294967295U )
#define UINT32_MIN          ( 0U )
#define UINT64_MAX          ( 18446744073709551615ULL )
#define UINT64_MIN          ( 0U )

#define SIZE_T_MAX          ( 4294967295U )
#define SIZE_T_MIN          ( 0U )

/**
 * @brief Macros Functions
 */
#define types_doNothing()   __asm volatile("nop")


/*
 * -----------STRUCT, ENUMS, TYPEDEF------------------
 */

/**
 * @brief Standard bool type for embedded project
 */
typedef enum {
    False = 0,
    True = 1
}bool_t;

typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;
typedef unsigned int       uint_t;
typedef unsigned int       size_t;

typedef volatile       uint64_t reg_rw_64;
typedef const volatile uint64_t reg_ro_64;
typedef volatile       uint64_t reg_wo_64;

typedef volatile       uint32_t reg_rw_32;
typedef const volatile uint32_t reg_ro_32;
typedef volatile       uint32_t reg_wo_32;

typedef volatile       uint16_t reg_rw_16;
typedef const volatile uint16_t reg_ro_16;
typedef volatile       uint16_t reg_wo_16;

typedef volatile       uint8_t reg_rw_8;
typedef const volatile uint8_t reg_ro_8;
typedef volatile       uint8_t reg_wo_8;

typedef volatile       uint8_t *const reg_ptr;
typedef reg_ptr const const_reg_ptr; 

typedef void (*vectFunc) (void);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // TYPES_H_INCLUDE


    