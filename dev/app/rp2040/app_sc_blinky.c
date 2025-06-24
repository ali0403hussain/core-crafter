/**
 * @file app_sc_blinky.c
 * 
 * @brief rp2040 single core blinky application.
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

#include "../../hal/inc/hal_gpio.h"
#include "../../hardware/rp2040/drivers/inc/drivers_gpio.h"


/*
 * -----------DEFINES------------------
 */

#define RP2040_ON_BOARD_LED           (25u)   /**< GPIO25 on RP2040 (built-in LED) */


/*
 * -----------FORWARD DECLARATION, GLOBAL VARS------------------
 */

hal_gpio_interface_t halGpioInst;                      /**< Hal Gpio Instance */ 
hal_gpio_interface_t *ptrHalGpioInst = &halGpioInst;   /**< Pointer to Hal Gpio Instance */ 

static const gpio_config_t ledPinConfig = 
{
    .pin             = RP2040_ON_BOARD_LED,                   
    .direction       = GPIO_DIR_OUTPUT,
    .pull            = GPIO_PULL_NONE,
    .drive_strength  = GPIO_DRIVE_4MA,
    .schmitt_trigger = False,
    .slew_fast       = False,
    .function        = GPIO_FUNC_SIO
};

/*
 * -----------FUNCTIONS DEFINATIONS------------------
 */

/**
 * @brief main entry point for sample app
 * 
 * @param void
 * 
 * @return 0
 */
int main( void )
{
    error_t retValue = ERR_OK;

    // Initialize Gpio Hal layer
    retValue = hal_gpio_layerInit( ptrHalGpioInst );

    if ( ERR_OK == retValue )
    {
        retValue = ptrHalGpioInst->init( ( void* )&ledPinConfig );
    }

    while( retValue == ERR_OK )
    {
       (void) ptrHalGpioInst->toggle( RP2040_ON_BOARD_LED );

       for (volatile int i = 0; i < 500000; i++);  // crude delay
    }

    return 0;
}