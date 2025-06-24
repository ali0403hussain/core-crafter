/**
 * @file private/boot_stage2.h
 * 
 * @brief boot stage 2 private header file for rp2040.
 * 
 * 2nd stage bootloader for RP2040: W25Q080 configured to Quad I/O Continuous Read XIP mode
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef PRIVATE_BOOT_STAGE_2_H_INCLUDE
#define PRIVATE_BOOT_STAGE_2_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif


/*
 * ----------------- DEFINES-----------------------
 */

/**
 * @brief Flash Commands defines
 */
#define FLASH_CMD_READ_QUAD_IO      (0xEBU)
#define FLASH_CMD_WRITE_ENABLE      (0x06U)
#define FLASH_CMD_READ_STATUS2      (0x35U)
#define FLASH_CMD_WRITE_STATUS      (0x01U)
#define FLASH_CMD_READ_STATUS1      (0x05U)

#define FLASH_QUAD_ENABLE_BIT       (0x02U)
#define FLASH_WAIT_CYCLES           (4U)
#define FLASH_ADDRESS_LENGTH        (8U)              /**< Address length divided by 4 */
#define FLASH_CONTINUOUS_READ_MODE  (0xA0U)


#define PICO_FLASH_SPI_CLKDIV       (4U)

/**
 * @brief Cortex-M0+ Vector Table Definitions (ARMv6-M Standard)
 */

#define VTOR_OFFSET_RESET_VECTOR    (0x4U)
#define VTOR_OFFSET_INITIAL_SP      (0x0U)
#define FLASH_VECTOR_TABLE_OFFSET   (0x100U) 


/*
 * -----------FUNCTIONS PROTOTYPE------------------
 */

/**
 * @brief Wait for SSI controller to be idle.
 * 
 * @param void
 * 
 * @return void
 */
static void boot_stage2_waitSsiReady( void );

/**
 * @brief Read a flash status register.
 * 
 * @param cmd Command opcode to read status register.
 * @param out Value read from the flash.
 * 
 * @return error_t ERR_OK on success.
 */
static error_t boot_stage2_readFlashStatus( uint8_t cmd, uint8_t *out );

/**
 * @brief Write Enable command to Flash.
 * 
 * @param void
 * 
 * @return void
 */
static void boot_stage2_flashWriteEnable( void );

/**
 * @brief Configure QSPI Pads.
 * 
 * @param void
 * 
 * @return error_t ERR_OK on success.
 */
static error_t boot_stage2_configQspiPads( void );

/**
 * @brief Configure SSI
 * 
 * @param void
 * 
 * @return error_t ERR_OK on success.
 */
static error_t boot_stage2_configSsi( void );

/**
 * @brief Enable QSPI Quad mode
 * 
 * @param void
 * 
 * @return error_t ERR_OK on success.
 */
static error_t boot_stage2_enableQspiQuadMode( void );

/**
 * @brief Enter continuous mode
 * 
 * @param void
 * 
 * @return error_t ERR_OK on success.
 */
static error_t boot_stage2_enterContinuousReadMode( void );

/**
 * @brief Enter XIP mode
 * 
 * @param void
 * 
 * @return error_t ERR_OK on success.
 */
error_t boot_stage2_enterXipMode( void );


#ifdef __cplusplus
}
#endif // __cplusplus

#endif //PRIVATE_BOOT_STAGE_2_H_INCLUDE

