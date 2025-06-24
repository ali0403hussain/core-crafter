/**
 * @file types_errorcode.h
 * 
 * @brief provides possible error codes
 * 
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef TYPES_ERROR_CODE_H_INCLUDE
#define TYPES_ERROR_CODE_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif


/*
 * -----------STRUCT, ENUMS, TYPEDEF------------------
 */

/**
 * @brief Standard error codes for embedded project
 */
typedef enum {
    ERR_OK                  = 0,    /**< No error */
    ERR_UNKNOWN             = -1,   /**< Unknown error */
    
    /* General errors */
    ERR_INVALID_PARAM       = -2,   /**< Invalid parameter passed */
    ERR_NULL_PTR            = -3,   /**< Null pointer error */
    ERR_TIMEOUT             = -4,   /**< Operation timed out */
    ERR_NOT_READY           = -5,   /**< Peripheral/device not ready */
    ERR_BUSY                = -6,   /**< Peripheral/device busy */
    ERR_UNSUPPORTED         = -7,   /**< Operation not supported */
    ERR_OVERFLOW            = -8,   /**< Buffer overflow or resource overflow */
    ERR_UNDERFLOW           = -9,   /**< Buffer underflow */
    ERR_OUT_OF_MEMORY       = -10,  /**< Memory allocation failed */
    ERR_HW_FAILURE          = -11,  /**< Hardware failure or fault */
    
    /* Startup errors */
    ERR_STARTUP_INIT_FAIL   = -20,  /**< Startup initialization failure */
    ERR_CLOCK_FAIL          = -21,  /**< Clock setup failure */
    
    /* HAL errors */
    ERR_HAL_INIT_FAIL       = -30,  /**< HAL initialization failure */
    ERR_HAL_INVALID_STATE   = -31,  /**< HAL in invalid state */
    
    /* Driver errors */
    ERR_DRV_NOT_FOUND       = -40,  /**< Driver not found */
    ERR_DRV_INIT_FAIL       = -41,  /**< Driver initialization failed */
    ERR_DRV_COMM_FAIL       = -42,  /**< Communication failure (e.g. I2C, SPI) */
    
    /* Application-specific errors */
    ERR_APP_INVALID_STATE   = -50,  /**< Application in invalid state */
    ERR_APP_RESOURCE_FAIL   = -51,  /**< Application resource failure */
    
    /* Add more error codes here as needed */
} error_t;


#ifdef __cplusplus
}
#endif // __cplusplus

#endif //TYPES_ERROR_CODE_H_INCLUDE

