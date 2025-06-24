/* linker_core0.ld */
/* Memory layout for Core0 - lower 128 KB of SRAM reserved */

ENTRY(boot_stage2);

MEMORY
{
  flash(rx) : ORIGIN = 0x10000000, LENGTH = 2M
  sram(rwx) : ORIGIN = 0x20000000, LENGTH = 128K      /**< Core0 RAM partition */
}

SECTIONS
{
  .boot2 :
  {
    _sboot2 = .;
    *(.boot2*)
    _eboot2 = .;
    . = . + (252 - (_eboot2 - _sboot2));
    *(.crc*)
  } > flash
  
  .text :
  {
    *(.vector*)
    *(.text*)
    *(.rodata*)
  } > flash

  .data :
  {
    *(.data*)
  } > sram AT > flash     /**< "> sram" is the VMA(Virtual/Runtime Memory Address), "> flash" is the LMA(Load Memory Address) */

  .bss (NOLOAD) :
  {
    *(.bss*)
  } > sram

  .stack (NOLOAD) :
  {
    . = ORIGIN(sram) + LENGTH(sram);
    __stack = .;
  } > sram

  /* Get start and end for .data section */
  _sdata = ADDR(.data);                             /**< Start address for the data section in RAM */
  _edata = _sdata + SIZEOF(.data);                  /**< End address for the data section in RAM */
  _sidata = LOADADDR(.data);                        /**< Start address for the initialization values of the data section in Flash */

  /* Get start and end of .bss section */
  _sbss = ADDR(.bss);                               /**< Start address for the bss section in RAM */
  _ebss = _sbss + SIZEOF(.bss);             /**< End address for the bss section in RAM */

}
