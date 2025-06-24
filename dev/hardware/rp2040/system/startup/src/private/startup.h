/**
 * @file private/startup.h
 * 
 * @brief startup private header file for rp2040.
 * 
 * Provides data and bss initialization, system init, and main entry point.
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef PRIVATE_STARTUP_H_INCLUDE
#define PRIVATE_STARTUP_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif


/**  
 * @name Linker script symbols  
 * Symbols provided by linker script.  
 * @{  
 */
extern uint32_t _sidata;    /**< Start address for the initialization values of the data section in Flash */
extern uint32_t _sdata;     /**< Start address for the data section in RAM */
extern uint32_t _edata;     /**< End address for the data section in RAM */
extern uint32_t _sbss;      /**< Start address for the bss section in RAM */
extern uint32_t _ebss;      /**< End address for the bss section in RAM */
extern uint32_t __stack;    /**< Stack  */
/** @} */

extern int main(void);      /**< main start point of app  */

/**  
 * @brief Interrupt functions  
 */
__attribute__((noreturn)) void defaultHandler( void );
__attribute__((noreturn)) void resetHandler( void );

/**  
 * @brief Core interrupt functions as weak and alias of the defaultHandler  
 */
void nmiHandler         ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void hardFaultHandler   ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void svCallHandler      ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void pendSvHandler      ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void sysTickHandler     ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));

/**  
 * @brief Other external interrupt functions as weak and alias of the defaultHandler
 */
void timerIrq0          ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void timerIrq1          ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void timerIrq2          ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void timerIrq3          ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void pwmIrqWrap         ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void usbctrlIrq         ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void xipIrq             ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void pio0Irq0           ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void pio0Irq1           ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void pio1Irq0           ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void pio1Irq1           ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void dmaIrq0            ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void dmaIrq1            ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void ioIrqBank0         ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void ioIrqQspi          ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void sioIrqProc0        ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void sioIrqProc1        ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void clocksIrq          ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void spi0Irq            ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void spi1Irq            ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void uart0Irq           ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void uart1Irq           ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void adcIrqFifo         ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void i2c0Irq            ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void i2c1Irq            ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));
void rtcIrq             ( void ) __attribute__((noreturn, weak, alias("defaultHandler")));


#ifdef __cplusplus
}
#endif // __cplusplus

#endif //PRIVATE_STARTUP_H_INCLUDE

