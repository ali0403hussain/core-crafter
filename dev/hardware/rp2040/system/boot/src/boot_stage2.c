/**
 * @file boot_stage2.c
 * 
 * @brief boot stage 2 source file for rp2040.
 * 
 * 2nd stage bootloader for RP2040: W25Q080 configured to Quad I/O Continuous Read XIP mode
 * This code replicates the behavior of the second-stage bootloader designed to bring the 
 * external flash into XIP (Execute-In-Place) mode for devices like the Winbond W25Q080:
 * 
 * @ref Reference taken from pico sdk
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

#include "../../../../../inc/project.h"
#include "../../../../../std-lib/helper/inc/helper_reg_access.h"

#include "../../../regs/reg_ssi.h"
#include "../../../regs/reg_pads_qspi.h"
#include "../../../regs/reg_m0plus.h"
#include "../../../regs/reg_map.h"

#include "private/boot_stage2.h" 


/*
 * -----------FUNCTIONS DEFINATIONS------------------
 */

/**
 * @brief Wait for SSI controller to be idle.
 * 
 * @param void
 * 
 * @return void
 */
void boot_stage2_waitSsiReady( void )
{
    uint32_t status;
    do
    {
        (void)helper_reg_access_readReg32( &REG_SSI->sr, &status );
        
    } while ( status & SSI_SR_BUSY_BIT );
}

/**
 * @brief Read a flash status register.
 * 
 * @param cmd Command opcode to read status register.
 * @param out Value read from the flash.
 * 
 * @return error_t ERR_OK on success.
 */
error_t boot_stage2_readFlashStatus( uint8_t cmd, uint8_t *out )
{
    error_t retValue = ERR_OK;

    retValue = helper_reg_access_writeReg32( &REG_SSI->ctrlr0, ( SSI_CTRLR0_DFS_8BIT | SSI_CTRLR0_TMOD_TX_RX ) );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    retValue = helper_reg_access_writeReg32( &REG_SSI->ssienr, BIT_SET_VALUE );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    retValue = helper_reg_access_writeReg32( &REG_SSI->dr0, cmd );
    
    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    boot_stage2_waitSsiReady();

    uint32_t dummyReadReg;
    retValue = helper_reg_access_readReg32( &REG_SSI->dr0, &dummyReadReg );    /**< discard command echo */

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    boot_stage2_waitSsiReady();

    uint32_t readRegValue;
    retValue = helper_reg_access_readReg32( &REG_SSI->dr0, &readRegValue );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }
    *out = (uint8_t)( readRegValue & 0xFFU );

    return ERR_OK;
}

/**
 * @brief Write Enable command to Flash.
 * 
 * @param void
 * 
 * @return void
 */
void boot_stage2_flashWriteEnable( void )
{
    (void)helper_reg_access_writeReg32( &REG_SSI->dr0, FLASH_CMD_WRITE_ENABLE );

    boot_stage2_waitSsiReady();

    uint32_t dummyReadReg;
    helper_reg_access_readReg32( &REG_SSI->dr0, &dummyReadReg );
}

/**
 * @brief Configure QSPI Pads.
 * 
 * @param void
 * 
 * @return error_t ERR_OK on success.
 */
error_t boot_stage2_configQspiPads( void )
{
    error_t retValue = ERR_OK;

    const uint32_t PAD_SCLK_CONFIG = (2U << 4U) | (1U << 6U);      /**< Drive strength = 8mA, Slew rate = fast */
    retValue = helper_reg_access_writeReg32( &REG_PADS_QSPI->gpio_qspi_sclk, PAD_SCLK_CONFIG );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    uint32_t padSd0Val;
    retValue = helper_reg_access_readReg32( &REG_PADS_QSPI->gpio_qspi_sd_0, &padSd0Val );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    padSd0Val &= ~(1U << 5U);    /**< Disable schmitt trigger */

    retValue = helper_reg_access_writeReg32( &REG_PADS_QSPI->gpio_qspi_sd_0, padSd0Val );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    retValue = helper_reg_access_writeReg32( &REG_PADS_QSPI->gpio_qspi_sd_1, padSd0Val );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    retValue = helper_reg_access_writeReg32( &REG_PADS_QSPI->gpio_qspi_sd_2, padSd0Val );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    retValue = helper_reg_access_writeReg32( &REG_PADS_QSPI->gpio_qspi_sd_3, padSd0Val );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    return ERR_OK;
}

/**
 * @brief Configure SSI
 * 
 * @param void
 * 
 * @return error_t ERR_OK on success.
 */
error_t boot_stage2_configSsi( void )
{
    error_t retValue = ERR_OK;

    retValue = helper_reg_access_writeReg32( &REG_SSI->ssienr, BIT_RESET_VALUE );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    retValue = helper_reg_access_writeReg32( &REG_SSI->baudr, PICO_FLASH_SPI_CLKDIV );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    retValue = helper_reg_access_writeReg32( &REG_SSI->rx_sample_dly, BIT_SET_VALUE );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    return ERR_OK;
}

/**
 * @brief Enable QSPI Quad mode
 * 
 * @param void
 * 
 * @return error_t ERR_OK on success.
 */
error_t boot_stage2_enableQspiQuadMode( void )
{
    error_t retValue = ERR_OK;

    uint8_t sr2;
    retValue = boot_stage2_readFlashStatus( FLASH_CMD_READ_STATUS2, &sr2 );
    
    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    if ( (sr2 & FLASH_QUAD_ENABLE_BIT) == BIT_RESET_VALUE ) 
    {
        boot_stage2_flashWriteEnable();

        retValue = helper_reg_access_writeReg32( &REG_SSI->dr0, FLASH_CMD_WRITE_STATUS );

        if ( ERR_OK != retValue )
        {
            return retValue;
        }

        retValue = helper_reg_access_writeReg32( &REG_SSI->dr0, BIT_RESET_VALUE );

        if ( ERR_OK != retValue )
        {
            return retValue;
        }

        retValue = helper_reg_access_writeReg32( &REG_SSI->dr0, FLASH_QUAD_ENABLE_BIT );

        if ( ERR_OK != retValue )
        {
            return retValue;
        }

        boot_stage2_waitSsiReady();

        uint32_t dummyReadReg;
        retValue = helper_reg_access_readReg32( &REG_SSI->dr0, &dummyReadReg );

        if ( ERR_OK != retValue )
        {
            return retValue;
        }

        retValue = helper_reg_access_readReg32( &REG_SSI->dr0, &dummyReadReg );

        if ( ERR_OK != retValue )
        {
            return retValue;
        }

        retValue = helper_reg_access_readReg32( &REG_SSI->dr0, &dummyReadReg );

        if ( ERR_OK != retValue )
        {
            return retValue;
        }

        /**< Wait until flash write completes */
        uint8_t sr1;
        do
        {
            (void)boot_stage2_readFlashStatus( FLASH_CMD_READ_STATUS1, &sr1 );
        } while (sr1 & 0x01U);
    }
    else
    {
        return ERR_BUSY;
    }

    return ERR_OK;
}

/**
 * @brief Enter continuous mode
 * 
 * @param void
 * 
 * @return error_t ERR_OK on success.
 */
error_t boot_stage2_enterContinuousReadMode( void )
{
    error_t retValue = ERR_OK;

    retValue = helper_reg_access_writeReg32( &REG_SSI->ssienr, 0U);

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    uint32_t ctrlr0Val = ( SSI_CTRLR0_SPI_FRF_EEPROM | SSI_CTRLR0_DFS_32BIT | SSI_CTRLR0_TMOD_TX_RX );

    retValue = helper_reg_access_writeReg32( &REG_SSI->ctrlr0, ctrlr0Val );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    retValue = helper_reg_access_writeReg32( &REG_SSI->ctrlr1, 0U) ;

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    uint32_t spiCtrlr0Val = (FLASH_ADDRESS_LENGTH << 2U) |
                            (FLASH_WAIT_CYCLES << 11U) |
                            (1U << 8U) | (2U << 16U);

    retValue = helper_reg_access_writeReg32( &REG_SSI->ctrlr0, spiCtrlr0Val );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }
    
    retValue = helper_reg_access_writeReg32( &REG_SSI->ssienr, 1U );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    retValue = helper_reg_access_writeReg32( &REG_SSI->dr0, FLASH_CMD_READ_QUAD_IO );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    retValue = helper_reg_access_writeReg32( &REG_SSI->dr0, FLASH_CONTINUOUS_READ_MODE );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    boot_stage2_waitSsiReady();

    return ERR_OK;
}

/**
 * @brief Enter XIP mode
 * 
 * @param void
 * 
 * @return error_t ERR_OK on success.
 */
error_t boot_stage2_enterXipMode( void )
{
    error_t retValue = ERR_OK;

    retValue = helper_reg_access_writeReg32( &REG_SSI->ssienr, BIT_RESET_VALUE);

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    uint32_t spiCtrlr0Val = (FLASH_CONTINUOUS_READ_MODE << 24U) |
                            (FLASH_ADDRESS_LENGTH << 2U) |
                            (FLASH_WAIT_CYCLES << 11U) |
                            (0U << 8U) | (2U << 16U);

    retValue = helper_reg_access_writeReg32( &REG_SSI->ctrlr0, spiCtrlr0Val );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }
    
    retValue = helper_reg_access_writeReg32( &REG_SSI->ssienr, BIT_SET_VALUE );

    if ( ERR_OK != retValue )
    {
        return retValue;
    }

    return ERR_OK;
}

/** 
 * @brief Load new application vector table, set MSP and jump to reset handler
 * 
 * @param void
 * 
 * @return error_t ERR_OK on success.
 */
void boot_stage2_jumpToApp( void )
{
    /* Compute application VTOR address */
    uint32_t app_vtor = XIP_BASE + FLASH_VECTOR_TABLE_OFFSET;

    /* Update VTOR register to new application VTOR address */
    (void)helper_reg_access_writeReg32( &REG_M0_PLUS->vtor, app_vtor );

    /* Define register pointers to read Initial Stack Pointer and Reset Handler address */
    reg_ro_32 *const ptr_initial_sp   = (reg_ro_32 *)( app_vtor + VTOR_OFFSET_INITIAL_SP );
    reg_ro_32 *const ptr_reset_vector = (reg_ro_32 *)( app_vtor + VTOR_OFFSET_RESET_VECTOR );

    /* Read values using helper functions */
    uint32_t initial_sp_value = 0U;
    uint32_t reset_handler_addr = 0U;

    (void)helper_reg_access_readReg32(ptr_initial_sp, &initial_sp_value);
    (void)helper_reg_access_readReg32(ptr_reset_vector, &reset_handler_addr);

    /* Set new Main Stack Pointer (MSP) */
    __asm volatile ("msr msp, %0" :: "r" (initial_sp_value));

    /* Branch to Reset Handler */
    __asm volatile ("bx %0" :: "r" (reset_handler_addr));

    /* Safety infinite loop in case of failure (should never reach here) */
    while (1U)
    {
        __asm volatile ("nop");
    }
}

/**
 * @brief RP2040 Boot Stage 2 entry point.  
 * 
 * This function initializes QSPI interface and sets up flash for XIP mode.
 */
__attribute__((naked, noreturn, section(".boot2")))
void boot_stage2(void)
{
    error_t retValue = ERR_OK;
    
    /**< Configure QSPI pads (PADS_QSPI) */
    retValue = boot_stage2_configQspiPads();
    
    if ( ERR_OK == retValue )
    {
        /**< Configure SSI */
        retValue = boot_stage2_configSsi();

        if ( ERR_OK == retValue )
        {
            /**< Enable Quad mode if not already enabled */
            retValue = boot_stage2_enableQspiQuadMode();

            if ( ERR_OK == retValue )
            {
                /**< Dummy read to enter continuous read mode */
                retValue = boot_stage2_enterContinuousReadMode();

                if ( ERR_OK == retValue )
                {
                    /**< Enter actual XIP mode (Instruction Phase disabled) */
                    retValue = boot_stage2_enterXipMode();

                    if ( ERR_OK != retValue )
                    {
                        /**< Redirect vector table to flash and jump to application reset vector */
                        boot_stage2_jumpToApp();
                    }
                    else
                    {
                        /**< Do nothing  */
                    }
                }
                else
                {
                    /**< Do nothing  */
                }
            }
            else
            {
                /**< Do nothing  */
            }
        }
        else
        {
            /**< Do nothing  */
        }
    }
    else
    {
        /**< Do nothing  */
    }
}