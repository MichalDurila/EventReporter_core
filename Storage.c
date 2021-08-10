/*
 ******************************************************************************
 *                                                                            *
 *                              Michal Durila                                 *
 *                                                                            *
 *                                                                            *
 *                           ALL RIGHTS RESERVED                              *
 *                                                                            *
 ******************************************************************************
 */

/**
 *  @file Storage.c
 *  @author Michal Durila
 *  @brief This module stores/loads data to/from local non-volatile memory.
 *
 * Copyright 2021 Michal Durila, All rights reserved.
 */

#include "Storage.h"
#include "Modules.h"

#include <stdio.h>


/* Module ID assignment */
static const Modules_Id_e m_eModuleId = E_MODULES_ID_STORAGE;


/**
 * @brief The function stores event report in local memory.
 *
 * @param in_pu8EventData   Event report data array
 * @param in_u32DataSize    Size of event report data in bytes
 */
void Storage_StoreEventReport(const uint8_t *in_pu8EventData, uint32_t in_u32DataSize)
{
    printf("Storage_StoreEventReport: %u\n", m_eModuleId);

    return;
}