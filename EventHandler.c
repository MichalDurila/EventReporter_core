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
 *  @file EventHandler.c
 *  @author Michal Durila
 *  @brief This module provides methods for handling and reporting events as well as their statistics.
 *
 * Copyright 2021 Michal Durila, All rights reserved.
 */

#include "EventHandler.h"


#define NUMBER_OF_EVENT_SEVERITIES   3U
#define NUMBER_OF_EVENT_TYPES        4U

/* Module ID assignment */
static const Modules_Id_e m_eModuleId = E_MODULES_ID_EVENTHANDLER;


/**
 * @brief Composes the event report (data), sends it and stores it
 *
 * @param in_eModuleId              ID of a module, in which an event occurred
 * @param in_u32LocationInModule    Event instance - a specific and unique place in the module
 * @param in_eSeverity              Event severity
 * @param in_eType                  Event type
 */
void EventHandler_GenerateEventReport(Modules_Id_e in_eModuleId, uint32_t in_u32LocationInModule, EventHandler_Severity_e in_eSeverity, EventHandler_Type_e in_eType)
{
    EventHandler_GenerateEventReportUserData(in_eModuleId, in_u32LocationInModule, in_eSeverity, in_eType, 0U);
    return;
}

/**
 * @brief Composes the event report (data), sends it and stores it
 *
 * @param in_eModuleId              ID of a module, in which an event occurred
 * @param in_u32LocationInModule    Event instance - a specific and unique place in the module
 * @param in_eSeverity              Event severity
 * @param in_eType                  Event type
 * @param in_u32AdditionalData      User defined data up to 4B used for event context
 */
void EventHandler_GenerateEventReportUserData(Modules_Id_e in_eModuleId, uint32_t in_u32LocationInModule, EventHandler_Severity_e in_eSeverity, EventHandler_Type_e in_eType, uint32_t in_u32AdditionalData)
{

    //restart system
    //get system time

    return;
}
