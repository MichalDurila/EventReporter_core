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
 *  @file Comm.c
 *  @author Michal Durila
 *  @brief This module provides communication with externally connected systems.
 *
 * Copyright 2021 Michal Durila, All rights reserved.
 */

#include "Comm.h"
#include "Modules.h"

#include <stdio.h>


/* Module ID assignment */
static const Modules_Id_e m_eModuleId = E_MODULES_ID_COMM;


/**
 * @brief The function sends event report to external system.
 *
 * @param in_pu8EventData   Event report data array
 * @param in_u32DataSize    Size of event report data in bytes
 */
void Comm_SendEventReport(const uint8_t *in_pu8EventData, uint32_t in_u32DataSize)
{
    uint32_t u32IterBytes = COMMON_STARTING_INDEX_OF_ARRAY;

    printf("Comm_SendEventReport: Module ID = %u, Received message = 0x", m_eModuleId);

    for (; in_u32DataSize > u32IterBytes; u32IterBytes++)
    {
        printf("%X ", *(in_pu8EventData + u32IterBytes));
    }

    printf("\n");

    return;
}
