/*
 ******************************************************************************
 *                                                                            *
 *                           esc Aerospace s.r.o.                             *
 *                       https://www.esc-aerospace.com                        *
 *                                                                            *
 *                           ALL RIGHTS RESERVED                              *
 *                                                                            *
 ******************************************************************************
 */

/**
 *  @file NvmMem.c
 *  @author esc
 *  @brief This module is used to write data into the non-volatile memory.
 *
 * Copyright 2021 esc Aerospace s.r.o., All rights reserved.
 */

#include "NvmMem.h"
#include "Modules.h"
#include "Common.h"


#define NVM_ADDRESS_LOW_LIM     0x00001000
#define NVM_ADDRESS_HIGH_LIM    0x00200000

/* Module ID assignment */
static const Modules_Id_e m_eModuleId = E_MODULES_ID_NVMMEM;


/**
 * @brief Writes data to the non-volatile memory at the specific address
 *
 * @param in_u32Address     Target memory address
 * @param in_pu8Data        Data to be written
 * @param in_u32DataSize    Size of the data in bytes
 */
void NvmMem_Write(uint32_t in_u32Address, const uint8_t *in_pu8Data, uint32_t in_u32DataSize)
{
    /* Address range check */
    if ((NVM_ADDRESS_LOW_LIM > in_u32Address) || (NVM_ADDRESS_HIGH_LIM < in_u32Address))
    {
        /* TODO: GENERATE EVENT */
        return;
    }

    /* Data validity check */
    if (NULL == in_pu8Data)
    {
        /* TODO: GENERATE NULL ARGUMENT EVENT */
        return;
    }

    /* Minimum data length check */
    if (0U == in_u32DataSize)
    {
        /* TODO: GENERATE EVENT */
        return;
    }

    /* ... MEMORY WRITING IMPLEMENTATION ... */

    return;
}
