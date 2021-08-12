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


#define EXPECTED_EVENT_DATA_SIZE_IN_BYTES 28U

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
    if (EXPECTED_EVENT_DATA_SIZE_IN_BYTES == in_u32DataSize)
    {
        printf("Comm_SendEventReport: TRUE, Module ID = %u\n", m_eModuleId);
    }
    else
    {
        printf("Comm_SendEventReport: FALSE, Module ID = %u\n", m_eModuleId);
    }

    return;
}
