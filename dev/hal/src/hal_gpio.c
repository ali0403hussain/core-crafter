/**
 * @file hal_gpio.c
 * 
 * @brief gpio hal layer source file.
 * 
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

#include "../../inc/project.h"
#include "../../hardware/rp2040/drivers/inc/drivers_gpio.h"

#include "../inc/hal_gpio.h"


/*
 * -----------FUNCTIONS DEFINATIONS------------------
 */

/**
 * @brief Hal layer exposed api to init Hal layer
 * 
 * @param halInterface pointer to halInterface
 * 
 * @return @error_t ERR_OK on Success 
 */
error_t hal_gpio_layerInit( hal_gpio_interface_t *halInterface )
{
    error_t retValue = ERR_OK;

    if ( !halInterface )
    {
        retValue = ERR_NULL_PTR;
    }
    else
    {
        retValue = drivers_gpio_layerInit( halInterface );
    }

    return retValue;
}