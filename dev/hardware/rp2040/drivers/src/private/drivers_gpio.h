/**
 * @file private/drivers_gpio.h
 * 
 * @brief rp2040 gpio drivers header file.
 * 
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef PRIVATE_DRIVERS_GPIO_H_INCLUDE
#define PRIVATE_DRIVERS_GPIO_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif

#include "../../inc/drivers_gpio.h"

/*
 * -----------INLINE FUNCTIONS------------------
 */

/**
 * @brief Internal helper to validate pin number
 * 
 * @param pin Gpio pin number
 * 
 * @return @error_t 
 */
static inline error_t drivers_gpio_validatPin( uint8_t pin ) 
{
    return (pin < NUM_BANK0_GPIOS) ? ERR_OK : ERR_INVALID_PARAM;
}


/*
 * -----------HANDLERS PROTOTYPE------------------
 */

/**
 * @brief Initialize GPIO peripheral handlers
 * 
 * @param config void pointer to configuration struct
 * 
 * @return @error_t 
 */
static error_t drivers_gpio_initHandler( void *config );

/**
 * @brief Set GPIO pin output level (only valid if pin configured as output)
 * 
 * @param pin GPIO pin number
 * @param value Boolean level to set (True=high, False=low)
 * 
 * @return error_t 
 */
static error_t drivers_gpio_writeHandler( uint8_t pin, bool_t value );

/**
 * @brief Read GPIO pin input level
 * 
 * @param pin GPIO pin number
 * @param value Pointer to bool_t where input level will be stored
 * 
 * @return error_t 
 */
static error_t drivers_gpio_readHandler( uint8_t pin, bool_t *value );

/**
 * @brief Toggle GPIO pin output (if output)
 * 
 * @param pin GPIO pin number
 * 
 * @return error_t 
 */
static error_t drivers_gpio_toggleHandler( uint8_t pin );

/*
 * -----------FUNCTIONS PROTOTYPE------------------
 */

/**
 * @brief Local function to gpio configure pad register
 * 
 * @param ptrConfig Pointer to gpio config data
 * @param padValue variable for pad value
 * 
 * @return error_t 
 */
static error_t loc_drivers_gpio_configPad( const gpio_config_t *ptrConfig, volatile uint32_t *padValue );


#ifdef __cplusplus
}
#endif // __cplusplus

#endif //PRIVATE_DRIVERS_GPIO_H_INCLUDE
