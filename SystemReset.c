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
 *  @file SystemReset.c
 *  @author Michal Durila
 *  @brief This module provides a method to reset the system.
 *
 * Copyright 2021 Michal Durila, All rights reserved.
 */

#include "SystemReset.h"
#include "Modules.h"


/* Module ID assignment */
static const Modules_Id_e m_eModuleId = E_MODULES_ID_SYSTEMRESET;


/**
 * @brief Resets the whole system to the default state
 */
void SystemReset_ResetSystem(void)
{
    if (E_MODULES_ID_SYSTEMRESET == m_eModuleId)
    {
        ;
    }

    return;
}
