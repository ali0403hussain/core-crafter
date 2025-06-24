/**
 * @file hal_gpio.h
 * 
 * @brief gpio hal layer header file.
 * 
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef HAL_GPIO_H_INCLUDE
#define HAL_GPIO_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif


/*
 * -----------FUNCTION POINTERS------------------
 */

/**
 * @brief Hal Gpio interface for gpio init
 * 
 * @param config void pointer to configuration struct
 * 
 * @return @error_t ERR_OK on Success
 */
typedef error_t (*hal_gpio_init)(void *config);

/**
 * @brief Hal Gpio interface for gpio write
 * 
 * @param pin Gpio pin to write
 * @param value Value to write
 * 
 * @return @error_t ERR_OK on Success
 */
typedef error_t (*hal_gpio_write)(uint8_t pin, bool_t value);

/**
 * @brief Hal Gpio interface for gpio read
 * 
 * @param pin Gpio pin to read
 * @param value Pointer to read variable
 * 
 * @return @error_t ERR_OK on Success
 */
typedef error_t (*hal_gpio_read)(uint8_t pin, bool_t *value);

/**
 * @brief Hal Gpio interface for gpio toggle
 * 
 * @param pin Gpio pin to read
 * 
 * @return @error_t ERR_OK on Success
 */
typedef error_t (*hal_gpio_toggle)(uint8_t pin);

/**
 * @brief Hal Gpio Interface typedef struct
 */
typedef struct
{
    hal_gpio_init   init;
    hal_gpio_write  write;
    hal_gpio_read   read;
    hal_gpio_toggle toggle;
}hal_gpio_interface_t;


/*
 * -----------FUNCTION PROTOTYPE------------------
 */

/**
 * @brief Hal layer exposed api to init Hal layer
 * 
 * @param halInterface pointer to halInterface
 * 
 * @return @error_t ERR_OK on Success 
 */
error_t hal_gpio_layerInit( hal_gpio_interface_t *halInterface );


#ifdef __cplusplus
}
#endif // __cplusplus

#endif //HAL_GPIO_H_INCLUDE
