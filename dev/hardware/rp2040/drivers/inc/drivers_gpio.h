/**
 * @file drivers_gpio.h
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

#ifndef DRIVERS_GPIO_H_INCLUDE
#define DRIVERS_GPIO_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif

/*
 * -----------INCLUDES------------------
 */

#include "../../../../hal/inc/hal_gpio.h"


/*
 * -----------TYPEDEF, STRUCT, ENUMS------------------
 */

/**
 * @brief GPIO Direction typedef enum
 */
typedef enum 
{
    GPIO_DIR_INPUT = 0,
    GPIO_DIR_OUTPUT,
} gpio_dir_t;

/**
 * @brief GPIO PullUP/PullDown typedef enum
 */
typedef enum 
{
    GPIO_PULL_NONE = 0,
    GPIO_PULL_UP,
    GPIO_PULL_DOWN,
} gpio_pull_t;

/**
 * @brief GPIO Drive typedef enum
 */
typedef enum 
{
    GPIO_DRIVE_2MA   = 0x00,
    GPIO_DRIVE_4MA   = 0x01,
    GPIO_DRIVE_8MA   = 0x02,
    GPIO_DRIVE_12MA  = 0x03
} gpio_drive_t;

/**
 * @brief GPIO Function typedef enum
 */
typedef enum 
{
    GPIO_FUNC_XIP   = 0,    /**< Select XIP as GPIO pin function */
    GPIO_FUNC_SPI   = 1,    /**< Select SPI as GPIO pin function */
    GPIO_FUNC_UART  = 2,    /**< Select UART as GPIO pin function */
    GPIO_FUNC_I2C   = 3,    /**< Select I2C as GPIO pin function */
    GPIO_FUNC_PWM   = 4,    /**< Select PWM as GPIO pin function */
    GPIO_FUNC_SIO   = 5,    /**< Select SIO as GPIO pin function */
    GPIO_FUNC_PIO0  = 6,    /**< Select PIO0 as GPIO pin function */
    GPIO_FUNC_PIO1  = 7,    /**< Select PIO1 as GPIO pin function */
    GPIO_FUNC_GPCK  = 8,    /**< Select GPCK as GPIO pin function */
    GPIO_FUNC_USB   = 9,    /**< Select USB as GPIO pin function */
    GPIO_FUNC_NULL  = 0x1f, /**< Select NULL as GPIO pin function */
} gpio_function_t;

/**
 * @brief GPIO Configuration typedef struct
 */
typedef struct 
{
    uint8_t         pin;                /**< GPIO pin number */
    gpio_dir_t      direction;          /**< Input or Output */ 
    gpio_pull_t     pull;               /**< Pull up/down/none */ 
    gpio_drive_t    drive_strength;     /**< GPIO drive strength */ 
    bool_t          schmitt_trigger;    /**< Enable/disable Schmitt trigger input */ 
    bool_t          slew_fast;          /**< Slew rate control */ 
    gpio_function_t function;           /**< Gpio pin function */ 
} gpio_config_t;

/*
 * -----------FUNCTION PROTOTYPE------------------
 */

/**
 * @brief Driver layer exposed api to init driver layer
 * 
 * @param halInterface pointer to halInterface
 * 
 * @return @error_t ERR_OK on Success 
 */
error_t drivers_gpio_layerInit( hal_gpio_interface_t *halInterface );

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //DRIVERS_GPIO_H_INCLUDE
