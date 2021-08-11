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
 *  @file EventHandler.h
 *  @author Michal Durila
 *  @brief This module provides methods for handling and reporting events as well as their statistics.
 *
 * Copyright 2021 Michal Durila, All rights reserved.
 */

#ifndef SRC_EVENTHANDLER_H_
#define SRC_EVENTHANDLER_H_

#include "Common.h"
#include "Modules.h"

/* Typedef containing all defined event severities */
typedef enum
{
    E_EVENTHANDLER_SEVERITY_LOW      = 0U,
    E_EVENTHANDLER_SEVERITY_NORMAL   = 1U,
    E_EVENTHANDLER_SEVERITY_MEDIUM   = 2U
} EventHandler_Severity_e;

/* Typedef containing all defined event types */
typedef enum
{
    E_EVENTHANDLER_TYPE_NULLARGUMENT     = 0U,
    E_EVENTHANDLER_TYPE_MINDATALENGTH    = 1U,
    E_EVENTHANDLER_TYPE_ADDRESSRANGE     = 2U,
    E_EVENTHANDLER_TYPE_DIVISIONBYZERO   = 3U
} EventHandler_Type_e;

void EventHandler_GenerateEventReport(Modules_Id_e in_eModuleId, uint32_t in_u32LocationInModule, EventHandler_Severity_e in_eSeverity, EventHandler_Type_e in_eType);
void EventHandler_GenerateEventReportUserData(Modules_Id_e in_eModuleId, uint32_t in_u32LocationInModule, EventHandler_Severity_e in_eSeverity, EventHandler_Type_e in_eType, uint32_t in_u32AdditionalData);

#endif /* SRC_EVENTHANDLER_H_ */
