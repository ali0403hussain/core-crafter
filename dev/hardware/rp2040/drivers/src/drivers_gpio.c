/**
 * @file drivers_gpio.c
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

/*
 * -----------INCLUDES------------------
 */

#include "../../../../inc/project.h"

#include "../../inc/platform_def.h"
#include "../../regs/reg_sio_gpio.h"
#include "../../regs/reg_pads_bank0.h"
#include "../../regs/reg_gpio_bank0.h"

#include "private/drivers_gpio.h"
#include "../inc/drivers_gpio.h"

/*
 * -----------FUNCTIONS DEFINATIONS------------------
 */

/**
 * @brief Driver layer exposed api to init driver layer
 * 
 * @param halInterface pointer to halInterface
 * 
 * @return @error_t ERR_OK on Success 
 */
error_t drivers_gpio_layerInit( hal_gpio_interface_t *halInterface )
{
    if ( !halInterface )
    {
        return ERR_NULL_PTR;
    }
    else
    {
        halInterface->init   = drivers_gpio_initHandler;
        halInterface->write  = drivers_gpio_writeHandler;
        halInterface->read   = drivers_gpio_readHandler;
        halInterface->toggle = drivers_gpio_toggleHandler;
    }

    return ERR_OK;
}

/**
 * @brief Initialize GPIO peripheral handlers
 * 
 * @param config void pointer to configuration struct
 * 
 * @return @error_t 
 */
error_t drivers_gpio_initHandler( void *config )
{
    error_t retValue = ERR_OK;

    if ( !config )
    {
        retValue = ERR_NULL_PTR;
    }
    else
    {
        gpio_config_t *ptrGpioConfig = (gpio_config_t*)config;

        const gpio_config_t gpioConfig =
        {
            .pin             = ptrGpioConfig->pin,
            .direction       = ptrGpioConfig->direction,
            .pull            = ptrGpioConfig->pull,
            .drive_strength  = ptrGpioConfig->drive_strength,
            .schmitt_trigger = ptrGpioConfig->schmitt_trigger,
            .slew_fast       = ptrGpioConfig->slew_fast,
            .function        = ptrGpioConfig->function
        };

        retValue = drivers_gpio_validatPin( gpioConfig.pin );

        if ( ERR_OK == retValue )
        {
            // Reset PAD register to default safe values
            retValue = helper_reg_access_writeReg32( &REG_PADS_BANK_0->gpio[gpioConfig.pin], 
                                                     PIN_RESET_VALUE ); 
        }

        // Disable output level in SIO for safety
        if ( ERR_OK == retValue )
        {
            retValue = helper_reg_access_setBits32( &REG_SIO_GPIO->gpio_oe_clr, 
                                                    GET_PIN_MASK( PIN_SET_VALUE, gpioConfig.pin ) ); 
        }

        // Disable output enable in SIO for safety
        if ( ERR_OK == retValue )
        {
            retValue = helper_reg_access_setBits32( &REG_SIO_GPIO->gpio_out_clr, 
                                                    GET_PIN_MASK( PIN_SET_VALUE, gpioConfig.pin ) ); 
        }

        // Configure pad register
        if ( ERR_OK == retValue )
        {
            // Set input enable on, output disable off
            retValue = helper_reg_access_writeReg32Masked( &REG_PADS_BANK_0->gpio[gpioConfig.pin], 
                                                           PADS_BANK0_GPIO_IE_BITS,
                                                           PADS_BANK0_GPIO_IE_BITS | PADS_BANK0_GPIO_OD_BITS );

            // Configure PAD register bits for drive strength, pull, schmitt, slew
            volatile uint32_t padReg = 0;

            retValue = loc_drivers_gpio_configPad( &gpioConfig, &padReg );

            if ( ERR_OK == retValue )
            {
                retValue = helper_reg_access_writeReg32( &REG_PADS_BANK_0->gpio[gpioConfig.pin], 
                                                         padReg );
            }
        }

        //Configure direction and output enable in SIO
        if ( ERR_OK == retValue )
        {
            if ( gpioConfig.direction == GPIO_DIR_OUTPUT ) 
            {
                // Set output enable bit
                retValue = helper_reg_access_writeReg32( &REG_SIO_GPIO->gpio_oe_set, 
                                                         GET_PIN_MASK( PIN_SET_VALUE, gpioConfig.pin ) );
            } 
            else 
            {
                // Clear output enable bit
                retValue = helper_reg_access_writeReg32( &REG_SIO_GPIO->gpio_oe_clr, 
                                                         GET_PIN_MASK( PIN_SET_VALUE, gpioConfig.pin ) );
            }
        }

        //Configure function 
        if ( ERR_OK == retValue )
        {
            retValue = helper_reg_access_writeReg32( &REG_GPIO_BANK_0->statusCtrl[ gpioConfig.pin ].ctrl,
                                                     GET_PIN_MASK( gpioConfig.function, IO_BANK0_GPIO_CTRL_FUNCSEL_LSB ) );
        }
    }

    return retValue;
}

/**
 * @brief Set GPIO pin output level (only valid if pin configured as output)
 * 
 * @param pin GPIO pin number
 * @param value Boolean level to set (True=high, False=low)
 * @return error_t 
 */
error_t drivers_gpio_writeHandler( uint8_t pin, bool_t value )
{
    error_t retValue = ERR_OK;
    
    retValue = drivers_gpio_validatPin( pin );

    if ( ERR_OK == retValue )
    {
        if (value) 
        {
            retValue = helper_reg_access_writeReg32( &REG_SIO_GPIO->gpio_out_set, 
                                                     GET_PIN_MASK( PIN_SET_VALUE, pin ) );
        } 
        else 
        {
            retValue = helper_reg_access_writeReg32( &REG_SIO_GPIO->gpio_out_clr, 
                                                     GET_PIN_MASK( PIN_SET_VALUE, pin ) );
        }
    }

    return retValue;
}

/**
 * @brief Read GPIO pin input level
 * 
 * @param pin GPIO pin number
 * @param value Pointer to bool_t where input level will be stored
 * @return error_t 
 */
error_t drivers_gpio_readHandler( uint8_t pin, bool_t *value )
{
    error_t retValue = ERR_OK;

    if ( !value )
    {
        retValue = ERR_NULL_PTR;
    }
    else
    {
        retValue = drivers_gpio_validatPin( pin );

        volatile uint32_t gpioInReg = 0;

        if ( ERR_OK == retValue )
        {
            retValue = helper_reg_access_readReg32( &REG_SIO_GPIO->gpio_in, &gpioInReg );
        }

        if ( ERR_OK == retValue )
        {
            *value = ( ( gpioInReg & ( GET_PIN_MASK( PIN_SET_VALUE, pin ) ) ) != 0 ) ? True : False;
        }
    }

    return retValue;
}

/**
 * @brief Toggle GPIO pin output (if output)
 * 
 * @param pin GPIO pin number
 * @return error_t 
 */
error_t drivers_gpio_toggleHandler( uint8_t pin )
{
    error_t retValue = ERR_OK;
    
    retValue = drivers_gpio_validatPin( pin );

    if ( ERR_OK == retValue )
    {
        // Toggle by XORing bit
        retValue = helper_reg_access_writeReg32( &REG_SIO_GPIO->gpio_out_xor, 
                                                 GET_PIN_MASK( PIN_SET_VALUE, pin ) );
    }

    return retValue;
}

/**
 * @brief Local function to gpio configure pad register
 * 
 * @param padValue variable for pad value
 * 
 * @return error_t 
 */
error_t loc_drivers_gpio_configPad( const gpio_config_t *ptrConfig, volatile uint32_t *padValue )
{
    error_t retValue = ERR_OK;

    if ( !padValue || !ptrConfig )
    {
        retValue = ERR_NULL_PTR;
    }
    else
    {
        // Drive strength
        *padValue |= GET_PIN_MASK( ptrConfig->drive_strength, PADS_BANK0_GPIO_DRIVE_LSB );

        // Pull-up/down
        switch ( ptrConfig->pull ) 
        {
            case GPIO_PULL_NONE:
                // Both pull-up and pull-down disabled
                break;
            case GPIO_PULL_UP:
                *padValue |= PADS_BANK0_GPIO_PUE_BITS;  // pull-up enable
                break;
            case GPIO_PULL_DOWN:
                *padValue |= PADS_BANK0_GPIO_PDE_BITS;  // pull-down enable
                break;
            default:
                retValue = ERR_INVALID_PARAM;
        }
        
        if ( ERR_OK == retValue )
        {
            // Schmitt trigger input enable
            if ( ptrConfig->schmitt_trigger ) 
            {
                *padValue |= PADS_BANK0_GPIO_SCHMITT_BITS;
            }

                // Slew rate
            if ( ptrConfig->slew_fast ) 
            {
                *padValue |= PADS_BANK0_GPIO_SLEWFAST_BITS; // Fast slew
            }
        }
    }  

    return retValue;
}