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


#define NUMBER_OF_EVENT_SEVERITIES 3U

/* Module ID assignment */
static const Modules_Id_e m_eModuleId = E_MODULES_ID_EVENTHANDLER;

static uint32_t m_au32EventsCounter[NUMBER_OF_EVENT_SEVERITIES][EVENTHANDLER_NUMBER_OF_EVENT_TYPES];
static float64_t m_af64LastTime[EVENTHANDLER_NUMBER_OF_EVENT_TYPES];
static boolean m_abIsStandbyMode[EVENTHANDLER_NUMBER_OF_EVENT_TYPES];


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

/* SRS-006 */
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
    //get system time

    /* SRS-013 */
    if ((EVENTHANDLER_NUMBER_OF_EVENT_TYPES > in_eType) && (abIsEnabledReporting[in_eType]))
    {
        if (NUMBER_OF_EVENT_SEVERITIES > in_eSeverity)
        {
            /* SRS-008 */
            if ((E_EVENTHANDLER_TYPE_NULLARGUMENT == in_eType) && (E_EVENTHANDLER_SEVERITY_MEDIUM > in_eSeverity))
            {
                in_eSeverity = E_EVENTHANDLER_SEVERITY_MEDIUM;
            }

            /* SRS-010 */
            m_au32EventsCounter[in_eSeverity][in_eType]++;

            /* SRS-004 */
            if (E_EVENTHANDLER_SEVERITY_MEDIUM == in_eSeverity)
            {
                //restart system
            }
        }
    }

    return;
}

/**
 * @brief Initializes all static arrays to correct values
 */
void EventHandler_InitializeOnStart(void)
{
    uint32_t u32IterType;
    uint32_t u32IterSeverity;

    for (u32IterType = 0; EVENTHANDLER_NUMBER_OF_EVENT_TYPES > u32IterType; u32IterType++)
    {
        for (u32IterSeverity = 0; NUMBER_OF_EVENT_SEVERITIES > u32IterSeverity; u32IterSeverity++)
        {
            m_au32EventsCounter[u32IterSeverity][u32IterType] = 0;
        }

        m_af64LastTime[u32IterType] = 0.0;
        m_abIsStandbyMode[u32IterType] = false;
        abIsEnabledReporting[u32IterType] = true;
    }

    return;
}

/**
 * @brief Gets the number of the generated events of the specified severity and type
 *
 * @param in_u32IndexSeverity   Defined event severity
 * @param in_u32IndexType       Defined event type
 */
uint32_t EventHandler_GetEventsCounter(uint32_t in_u32IndexSeverity, uint32_t in_u32IndexType)
{
    uint32_t u32EventsCounter = 0U;

    if ((NUMBER_OF_EVENT_SEVERITIES > in_u32IndexSeverity) && (EVENTHANDLER_NUMBER_OF_EVENT_TYPES > in_u32IndexType))
    {
        u32EventsCounter = m_au32EventsCounter[in_u32IndexSeverity][in_u32IndexType];
    }

    return u32EventsCounter;
}
