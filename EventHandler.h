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

#ifndef __EVENTHANDLER_H__
#define __EVENTHANDLER_H__

#include "Common.h"
#include "Modules.h"

#define EVENTHANDLER_NUMBER_OF_EVENT_TYPES 5U

/* SRS-013 */
/* Variable that enables / disables the event reporting for each event type separately */
boolean abIsEnabledReporting[EVENTHANDLER_NUMBER_OF_EVENT_TYPES];

/* SRS-003 */
/* Typedef containing all defined event severities */
typedef enum
{
    E_EVENTHANDLER_SEVERITY_LOW    = 0U,
    E_EVENTHANDLER_SEVERITY_NORMAL = 1U,
    E_EVENTHANDLER_SEVERITY_MEDIUM = 2U
} EventHandler_Severity_e;

/* SRS-007 */
/* Typedef containing all defined event types */
typedef enum
{
    E_EVENTHANDLER_TYPE_NULLARGUMENT       = 0U,
    E_EVENTHANDLER_TYPE_MINDATALENGTH      = 1U,
    E_EVENTHANDLER_TYPE_ADDRESSRANGE       = 2U,
    E_EVENTHANDLER_TYPE_DIVISIONBYZERO     = 3U,
    E_EVENTHANDLER_TYPE_UNUPDATEDCONSTANTS = 4U
} EventHandler_Type_e;

void EventHandler_GenerateEventReport(Modules_Id_e in_eModuleId, uint32_t in_u32LocationInModule, EventHandler_Severity_e in_eSeverity, EventHandler_Type_e in_eType);
void EventHandler_GenerateEventReportUserData(Modules_Id_e in_eModuleId, uint32_t in_u32LocationInModule, EventHandler_Severity_e in_eSeverity, EventHandler_Type_e in_eType, uint32_t in_u32AdditionalData);
void EventHandler_InitializeOnStart(void);
uint32_t EventHandler_GetEventsCounter(EventHandler_Severity_e in_eSeverity, EventHandler_Type_e in_eType);
boolean EventHandler_GetStandbyMode(EventHandler_Type_e in_eType);

#endif /* __EVENTHANDLER_H__ */
