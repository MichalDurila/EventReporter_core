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
#include "Timing.h"
#include "SystemReset.h"
#include "Comm.h"
#include "Storage.h"


#define NUMBER_OF_EVENT_SEVERITIES       3U
#define OVERFLOW_LIMIT_IN_SECONDS        10.0
#define REENABLE_REPORTING_AFTER_MINUTES 10.0
#define SECONDS_IN_MINUTE                60
#define EVENT_DATA_SIZE_IN_BYTES         28U

/* Module ID assignment */
static const Modules_Id_e m_eModuleId = E_MODULES_ID_EVENTHANDLER;

/* Typedef containing all defined event instances in this module */
typedef enum
{
    E_EVENT_INSTANCE_EVENTHANDLER_GENERATEEVENTREPORTUSERDATA_SEVERITIES = 0U,
    E_EVENT_INSTANCE_EVENTHANDLER_GENERATEEVENTREPORTUSERDATA_TYPES      = 1U
} EventInstance_e;

static const float64_t m_f64ReenableReportingAfterSeconds = (SECONDS_IN_MINUTE * REENABLE_REPORTING_AFTER_MINUTES) + OVERFLOW_LIMIT_IN_SECONDS;

static uint32_t m_au32EventsCounter[NUMBER_OF_EVENT_SEVERITIES][EVENTHANDLER_NUMBER_OF_EVENT_TYPES];
static float64_t m_af64LastTime[EVENTHANDLER_NUMBER_OF_EVENT_TYPES];
static boolean m_abIsStandbyMode[EVENTHANDLER_NUMBER_OF_EVENT_TYPES];
static boolean m_abIsEnabledReporting[EVENTHANDLER_NUMBER_OF_EVENT_TYPES];

static void EventHandler_InitializeBeforeReset(void);
static void EventHandler_ComposeAndSendReport(float64_t in_f64CurrentTimeInSeconds, Modules_Id_e in_eModuleId, uint32_t in_u32LocationInModule, EventHandler_Severity_e in_eSeverity, EventHandler_Type_e in_eType, uint32_t in_u32AdditionalData);


/**
 * @brief Handles the event and creates a report
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
 * @brief Handles the event and creates a report
 *
 * @param in_eModuleId              ID of a module, in which an event occurred
 * @param in_u32LocationInModule    Event instance - a specific and unique place in the module
 * @param in_eSeverity              Event severity
 * @param in_eType                  Event type
 * @param in_u32AdditionalData      User defined data up to 4B used for event context
 */
void EventHandler_GenerateEventReportUserData(Modules_Id_e in_eModuleId, uint32_t in_u32LocationInModule, EventHandler_Severity_e in_eSeverity, EventHandler_Type_e in_eType, uint32_t in_u32AdditionalData)
{
    float64_t f64CurrentTimeInSeconds = TIMING_INITIAL_TIME;

    f64CurrentTimeInSeconds = Timing_GetTime();

    if (EVENTHANDLER_NUMBER_OF_EVENT_TYPES > in_eType)
    {
        if (NUMBER_OF_EVENT_SEVERITIES > in_eSeverity)
        {
            /* SRS-013 */
            if (E_TRUE == m_abIsEnabledReporting[in_eType])
            {
                /* SRS-008 */
                if ((E_EVENTHANDLER_TYPE_NULLARGUMENT == in_eType) && (E_EVENTHANDLER_SEVERITY_MEDIUM > in_eSeverity))
                {
                    in_eSeverity = E_EVENTHANDLER_SEVERITY_MEDIUM;
                }

                /* SRS-010 */
                /* SRS-011 */
                m_au32EventsCounter[in_eSeverity][in_eType]++;

                if (E_EVENTHANDLER_SEVERITY_MEDIUM > in_eSeverity)
                {
                    if (E_TRUE == m_abIsStandbyMode[in_eType])
                    {
                        /* SRS-009 */
                        if ((m_af64LastTime[in_eType] + m_f64ReenableReportingAfterSeconds) < f64CurrentTimeInSeconds)
                        {
                            /* SRS-012 */
                            m_abIsStandbyMode[in_eType] = E_FALSE;
                            m_af64LastTime[in_eType] = f64CurrentTimeInSeconds;
                            EventHandler_ComposeAndSendReport(f64CurrentTimeInSeconds, in_eModuleId, in_u32LocationInModule, in_eSeverity, in_eType, in_u32AdditionalData);
                        }
                    }
                    else
                    {
                        /* SRS-009 */
                        if ((m_af64LastTime[in_eType] + OVERFLOW_LIMIT_IN_SECONDS) > f64CurrentTimeInSeconds)
                        {
                            /* SRS-011 */
                            m_abIsStandbyMode[in_eType] = E_TRUE;
                        }

                        m_af64LastTime[in_eType] = f64CurrentTimeInSeconds;
                        EventHandler_ComposeAndSendReport(f64CurrentTimeInSeconds, in_eModuleId, in_u32LocationInModule, in_eSeverity, in_eType, in_u32AdditionalData);
                    }
                }
                else
                {
                    EventHandler_ComposeAndSendReport(f64CurrentTimeInSeconds, in_eModuleId, in_u32LocationInModule, in_eSeverity, in_eType, in_u32AdditionalData);

                    /* SRS-004 */
                    if (E_EVENTHANDLER_SEVERITY_MEDIUM == in_eSeverity)
                    {
                        EventHandler_InitializeBeforeReset();
                        SystemReset_ResetSystem();
                    }
                }
            }
        }
        else
        {
            /* Someone forgot to change (increment) the definition of NUMBER_OF_EVENT_SEVERITIES when adding some new enums */
            EventHandler_ComposeAndSendReport(f64CurrentTimeInSeconds, m_eModuleId, (uint32_t) E_EVENT_INSTANCE_EVENTHANDLER_GENERATEEVENTREPORTUSERDATA_SEVERITIES, E_EVENTHANDLER_SEVERITY_NORMAL, E_EVENTHANDLER_TYPE_UNUPDATEDCONSTANTS, 0U);
        }
    }
    else
    {
        /* Someone forgot to change (increment) the definition of EVENTHANDLER_NUMBER_OF_EVENT_TYPES when adding some new enums */
        EventHandler_ComposeAndSendReport(f64CurrentTimeInSeconds, m_eModuleId, (uint32_t) E_EVENT_INSTANCE_EVENTHANDLER_GENERATEEVENTREPORTUSERDATA_TYPES, E_EVENTHANDLER_SEVERITY_NORMAL, E_EVENTHANDLER_TYPE_UNUPDATEDCONSTANTS, 0U);
    }

    return;
}

/**
 * @brief Composes the event report (data), sends it and stores it
 *
 * @param in_f64CurrentTimeInSeconds Current time from system start in seconds
 * @param in_eModuleId               ID of a module, in which an event occurred
 * @param in_u32LocationInModule     Event instance - a specific and unique place in the module
 * @param in_eSeverity               Event severity
 * @param in_eType                   Event type
 * @param in_u32AdditionalData       User defined data up to 4B used for event context
 */
static void EventHandler_ComposeAndSendReport(float64_t in_f64CurrentTimeInSeconds, Modules_Id_e in_eModuleId, uint32_t in_u32LocationInModule, EventHandler_Severity_e in_eSeverity, EventHandler_Type_e in_eType, uint32_t in_u32AdditionalData)
{
    uint8_t au8EventData[EVENT_DATA_SIZE_IN_BYTES];
    uint8_t *pu8EventData = ((uint8_t *) &au8EventData);

    Comm_SendEventReport(pu8EventData, EVENT_DATA_SIZE_IN_BYTES);
    Storage_StoreEventReport(pu8EventData, EVENT_DATA_SIZE_IN_BYTES);

    return;
}

/**
 * @brief Initializes all static arrays to correct values
 */
void EventHandler_InitializeOnStart(void)
{
    uint32_t u32IterType = 0U;
    uint32_t u32IterSeverity = 0U;

    EventHandler_InitializeBeforeReset();

    for (u32IterType = 0U; EVENTHANDLER_NUMBER_OF_EVENT_TYPES > u32IterType; u32IterType++)
    {
        for (u32IterSeverity = 0U; NUMBER_OF_EVENT_SEVERITIES > u32IterSeverity; u32IterSeverity++)
        {
            m_au32EventsCounter[u32IterSeverity][u32IterType] = 0U;
        }

        m_abIsEnabledReporting[u32IterType] = E_TRUE;
    }

    return;
}

/**
 * @brief Initializes the static arrays, which would block events processing otherwise
 */
static void EventHandler_InitializeBeforeReset(void)
{
    uint32_t u32IterType = 0U;

    for (u32IterType = 0U; EVENTHANDLER_NUMBER_OF_EVENT_TYPES > u32IterType; u32IterType++)
    {
        m_af64LastTime[u32IterType] = TIMING_INITIAL_TIME;
        m_abIsStandbyMode[u32IterType] = E_FALSE;
    }

    return;
}

/**
 * @brief Gets the number of the generated events of the specified event severity and type
 *
 * @param in_eSeverity   Defined event severity
 * @param in_eType       Defined event type
 *
 * @return               Number of the generated events
 */
uint32_t EventHandler_GetEventsCounter(EventHandler_Severity_e in_eSeverity, EventHandler_Type_e in_eType)
{
    uint32_t u32EventsCounter = 0U;

    if ((NUMBER_OF_EVENT_SEVERITIES > in_eSeverity) && (EVENTHANDLER_NUMBER_OF_EVENT_TYPES > in_eType))
    {
        u32EventsCounter = m_au32EventsCounter[in_eSeverity][in_eType];
    }

    return u32EventsCounter;
}

/**
 * @brief Gets the status of the Standby mode for the specified event type
 *
 * @param in_eType   Defined event type
 *
 * @return E_FALSE   No Standby mode for the event type - the event report is processed
 * @return E_TRUE    Standby mode for the event type is active - the event report is not further processed
 */
boolean EventHandler_GetStandbyMode(EventHandler_Type_e in_eType)
{
    boolean bIsStandbyMode = E_FALSE;

    if (EVENTHANDLER_NUMBER_OF_EVENT_TYPES > in_eType)
    {
        bIsStandbyMode = m_abIsStandbyMode[in_eType];
    }

    return bIsStandbyMode;
}

/**
 * @brief Gets, whether the event reporting is enabled / disabled for the selected event type
 *
 * @param in_eType   Defined event type
 *
 * @return E_FALSE   The event report processing is disabled for the selected event type
 * @return E_TRUE    The event report processing is active for the selected event type
 */
boolean EventHandler_GetEnabledReporting(EventHandler_Type_e in_eType)
{
    boolean bIsEnabledReporting = E_FALSE;

    if (EVENTHANDLER_NUMBER_OF_EVENT_TYPES > in_eType)
    {
        bIsEnabledReporting = m_abIsEnabledReporting[in_eType];
    }

    return bIsEnabledReporting;
}

/* SRS-013 */
/**
 * @brief Sets, whether the event reporting is enabled / disabled for each event type separately
 *
 * @param in_eType        Defined event type
 * @param in_bIsEnabled   Enables or disables the event reporting for the selected event type
 */
void EventHandler_SetEnabledReporting(EventHandler_Type_e in_eType, boolean in_bIsEnabled)
{
    if (EVENTHANDLER_NUMBER_OF_EVENT_TYPES > in_eType)
    {
        m_abIsEnabledReporting[in_eType] = in_bIsEnabled;
    }

    return;
}
