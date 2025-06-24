/**
 * @file startup.c
 * 
 * @brief startup source file for rp2040.
 * 
 * Provides data and bss initialization, system init, and main entry point.
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
#include "../../../../../std-lib/helper/inc/helper_runtime.h"

#include "private/startup.h"


/*
 * -----------VECTOR TABLE: 48 Exceptions = 16 Arm + 32 External------------------
 */
const vectFunc vector[48] __attribute__((section(".vector"))) = 
{
    (vectFunc)(&__stack),   /**< Stack pointer */
    resetHandler,           /**< Reset Handler */
    nmiHandler,             /**< NMI */
    hardFaultHandler,       /**< HardFault */
    0,                      /**< Reserved */
    0,                      /**< Reserved */
    0,                      /**< Reserved */
    0,                      /**< Reserved */
    0,                      /**< Reserved */
    0,                      /**< Reserved */
    0,                      /**< Reserved */
    svCallHandler,          /**< SVCall */
    0,                      /**< Reserved */
    0,                      /**< Reserved */
    pendSvHandler,          /**< PendSV */
    sysTickHandler,         /**< SysTick */
    timerIrq0,              /**< ExternalInterrupt[0]     = TIMER_IRQ_0 */
    timerIrq1,              /**< ExternalInterrupt[1]     = TIMER_IRQ_1 */
    timerIrq2,              /**< ExternalInterrupt[2]     = TIMER_IRQ_2 */
    timerIrq3,              /**< ExternalInterrupt[3]     = TIMER_IRQ_3 */
    pwmIrqWrap,             /**< ExternalInterrupt[4]     = PWM_IRQ_WRAP */
    usbctrlIrq,             /**< ExternalInterrupt[5]     = USBCTRL_IRQ */
    xipIrq,                 /**< ExternalInterrupt[6]     = XIP_IRQ */
    pio0Irq0,               /**< ExternalInterrupt[7]     = PIO0_IRQ_0 */
    pio0Irq1,               /**< ExternalInterrupt[8]     = PIO0_IRQ_1 */
    pio1Irq0,               /**< ExternalInterrupt[9]     = PIO1_IRQ_0 */
    pio1Irq1,               /**< ExternalInterrupt[10]    = PIO1_IRQ_1 */
    dmaIrq0,                /**< ExternalInterrupt[11]    = DMA_IRQ_0 */
    dmaIrq1,                /**< ExternalInterrupt[12]    = DMA_IRQ_1 */
    ioIrqBank0,             /**< ExternalInterrupt[13]    = IO_IRQ_BANK0 */
    ioIrqQspi,              /**< ExternalInterrupt[14]    = IO_IRQ_QSPI */
    sioIrqProc0,            /**< ExternalInterrupt[15]    = SIO_IRQ_PROC0 */
    sioIrqProc1,            /**< ExternalInterrupt[16]    = SIO_IRQ_PROC1 */
    clocksIrq,              /**< ExternalInterrupt[17]    = CLOCKS_IRQ */
    spi0Irq,                /**< ExternalInterrupt[18]    = SPI0_IRQ */
    spi1Irq,                /**< ExternalInterrupt[19]    = SPI1_IRQ */
    uart0Irq,               /**< ExternalInterrupt[20]    = UART0_IRQ */
    uart1Irq,               /**< ExternalInterrupt[21]    = UART1_IRQ */
    adcIrqFifo,             /**< ExternalInterrupt[22]    = ADC_IRQ_FIFO */
    i2c0Irq,                /**< ExternalInterrupt[23]    = I2C0_IRQ */
    i2c1Irq,                /**< ExternalInterrupt[24]    = I2C1_IRQ */
    rtcIrq,                 /**< ExternalInterrupt[25]    = RTC_IRQ */
    0,                      /**< ExternalInterrupt[26]    = Reserved */
    0,                      /**< ExternalInterrupt[27]    = Reserved */
    0,                      /**< ExternalInterrupt[28]    = Reserved */
    0,                      /**< ExternalInterrupt[29]    = Reserved */
    0,                      /**< ExternalInterrupt[30]    = Reserved */
    0,                      /**< ExternalInterrupt[31]    = Reserved */
};


/*
 * -----------FUNCTIONS DEFINATIONS------------------
 */

/**
 * @brief Reset Handler
 * 
 * @param void
 * 
 * @return void
 */
void resetHandler( void )
{
    error_t retValue  = ERR_OK;

    retValue = helper_runtime_init( &_sidata, &_sdata, &_edata, &_sbss, &_ebss );

    if ( ERR_OK == retValue)
    {
        main();
    }
    
    /* If main returns or init failed, loop forever */
    while (1);
}

/**
 * @brief Default Handler
 * 
 * @param void
 * 
 * @return void
 */
void defaultHandler( void )
{
    while (1)
    {
       //Do Nothing
    }
}