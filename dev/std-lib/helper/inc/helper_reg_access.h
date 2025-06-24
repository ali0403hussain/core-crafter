/**
 * @file helper_reg_access.h
 * 
 * @brief prvides interface for registers access
 * 
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef HELPER_REG_ACCESS_H_INCLUDE
#define HELPER_REG_ACCESS_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif


/*
 * -----------DEFINES------------------
 */

#define PIN_SET_VALUE              (1u)
#define PIN_RESET_VALUE            (0u)

#define BIT_SET_VALUE              (1u)
#define BIT_RESET_VALUE            (0u)

#define GET_PIN_MASK(value, pin)   ((uint32_t)(value) << (pin))


/*
 * -----------INLINE FUNCTIONS------------------
 */

/**
 * @brief Read a 32-bit value from a register.
 * 
 * @param reg   Address of readable register
 * @param out   Pointer to output variable
 * 
 * @return error_t ERR_OK on success, error code otherwise
 */
static inline error_t helper_reg_access_readReg32(reg_ro_32 *reg, volatile uint32_t *out) 
{
    if (!reg || !out) 
    {
        return ERR_NULL_PTR;
    }
    else
    {
        *out = *reg;
    }
    return ERR_OK;
}

/**
 * @brief Write a 32-bit value to a register.
 * 
 * @param reg    Address of writable register
 * @param value  Value to write
 * 
 * @return error_t ERR_OK on success, error code otherwise
 */
static inline error_t helper_reg_access_writeReg32(reg_rw_32 *reg, uint32_t value) 
{
    if (!reg) 
    {
        return ERR_NULL_PTR;
    }
    else
    {
        *reg = value;
    }
    return ERR_OK;
}

/**
 * @brief Write to a register using a mask (update only selected bits).
 * 
 * @param reg   Address of writable register
 * @param value Bits values
 * @param mask  Mask of bits to change
 * 
 * @return error_t ERR_OK on success, error code otherwise
 */
static inline error_t helper_reg_access_writeReg32Masked(reg_rw_32 *reg, uint32_t value, uint32_t mask) 
{
    if (!reg) 
    {
        return ERR_NULL_PTR;
    }
    else
    {
        *reg = (*reg & ~mask) | (value & mask);
    }
    return ERR_OK;
}

/**
 * @brief Set specific bits in a register (bitwise OR).
 * 
 * @param reg    Address of writable register
 * @param mask   Mask of bits to change
 * 
 * @return error_t ERR_OK on success, error code otherwise
 */
static inline error_t helper_reg_access_setBits32(reg_rw_32 *reg, uint32_t mask) 
{
    if (!reg) 
    {
        return ERR_NULL_PTR;
    }
    else
    {
        *reg |= mask;
    }
    return ERR_OK;
}

/**
 * @brief Clear specific bits in a register (bitwise AND NOT).
 * 
 * @param reg   Address of writable register
 * @param mask  Mask of bits to change
 * 
 * @return error_t ERR_OK on success, error code otherwise
 */
static inline error_t helper_reg_access_clearBits32(reg_rw_32 *reg, uint32_t mask) 
{
    if (!reg) 
    {
        return ERR_NULL_PTR;
    }
    else
    {
        *reg &= ~mask;
    }
    return ERR_OK;
}

/**
 * @brief Toggle specific bits in a register (bitwise XOR).
 * 
 * @param reg   Address of writable register
 * @param mask  Mask of bits to change
 * 
 * @return error_t ERR_OK on success, error code otherwise
 */
static inline error_t helper_reg_access_toggleBits32(reg_rw_32 *reg, uint32_t mask) 
{
    if (!reg) 
    {
        return ERR_NULL_PTR;
    }
    else
    {
        *reg ^= mask;
    }
    return ERR_OK;
}


#ifdef __cplusplus
}
#endif // __cplusplus

#endif //HELPER_REG_ACCESS_H_INCLUDE

