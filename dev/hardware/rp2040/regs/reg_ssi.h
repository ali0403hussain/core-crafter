/**
 * @file reg_ssi.h
 * 
 * @brief   Synchronous Serial Interface (SSI) controller registers
 * @details Synchronous Serial Interface (SSI) controller which appears on the QSPI pins and is used to
 *          communicate with external Flash devices. The SSI forms part of the XIP block. 
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef REG_SSI_H_INCLUDE
#define REG_SSI_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif


/*
* -----------INCLUDES------------------
*/

#include "../../../std-lib/type/inc/types.h"
#include "reg_map.h"


/*
* -----------DEFINES------------------
*/

/**
 * @brief       SSI_SR_BUSY_BIT
 * @description SSI busy bit
 */
#define SSI_SR_BUSY_BIT                     (0x01U)

/**
 * @brief       SSI_CTRLR0_DFS_32BIT
 * @description 32-bit frame size
 */
#define SSI_CTRLR0_DFS_32BIT                (0x1FU)      

/**
 * @brief       SSI_CTRLR0_DFS_8BIT
 * @description 8-bit frame size
 */
#define SSI_CTRLR0_DFS_8BIT                 (0x07U)      

/**
 * @brief       SSI_CTRLR0_TMOD_TX_RX
 * @description Transmit + Receive mode
 */
#define SSI_CTRLR0_TMOD_TX_RX               (0x0U << 8U) 

/**
 * @brief       SSI_CTRLR0_SPI_FRF_STD
 * @description SPI standard frame format
 */
#define SSI_CTRLR0_SPI_FRF_STD              (0x0U << 21U)

/**
 * @brief       SSI_CTRLR0_SPI_FRF_EEPROM
 * @description SPI EEPROM mode
 */
#define SSI_CTRLR0_SPI_FRF_EEPROM           (0x3U << 21U)


/*
* -----------TYPEDEF, STRUCT ENUM------------------
*/

/**
 * @brief SSI Register typedef struct
 */
typedef struct 
{
    reg_rw_32 ctrlr0;
    reg_rw_32 ctrlr1;
    reg_rw_32 ssienr;
    reg_rw_32 mwcr;
    reg_rw_32 ser;
    reg_rw_32 baudr;
    reg_rw_32 txftlr;
    reg_rw_32 rxftlr;
    reg_ro_32 txflr;
    reg_ro_32 rxflr;
    reg_ro_32 sr;
    reg_rw_32 imr;
    reg_ro_32 isr;
    reg_ro_32 risr;
    reg_ro_32 txoicr;
    reg_ro_32 rxoicr;
    reg_ro_32 rxuicr;
    reg_ro_32 msticr;
    reg_ro_32 icr;
    reg_rw_32 dmacr;
    reg_rw_32 dmatdlr;
    reg_rw_32 dmardlr;
    reg_ro_32 idr;
    reg_ro_32 ssi_version_id;
    reg_rw_32 dr0;
    uint32_t _pad[35];
    reg_rw_32 rx_sample_dly;
    reg_rw_32 spi_ctrlr0;
    reg_rw_32 txd_drive_edge;
}reg_ssi_t;

#define REG_SSI            ((reg_ssi_t*)XIP_SSI_BASE)


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // REG_SSI_H_INCLUDE

