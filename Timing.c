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
 *  @file Timing.c
 *  @author Michal Durila
 *  @brief This module provides a method, which gives the amount of time elapsed from the start in seconds.
 *
 * Copyright 2021 Michal Durila, All rights reserved.
 */

#include "Timing.h"
#include "Modules.h"


/* Module ID assignment */
static const Modules_Id_e m_eModuleId = E_MODULES_ID_TIMING;

/* Auxiliary variable for testing purposes */
static float64_t m_f64TimeToBeReturned = TIMING_INITIAL_TIME;


/**
 * @brief Gives the amount of time elapsed from the start of the system
 *
 * @return Elapsed time in seconds
 */
float64_t Timing_GetTime(void)
{
    return m_f64TimeToBeReturned;
}

/**
 * @brief Sets the amount of time elapsed from the start of the system
 *
 * @param in_f64Time   Time in seconds to be set
 */
void Timing_SetTime(float64_t in_f64Time)
{
    m_f64TimeToBeReturned = in_f64Time;
    return;
}
