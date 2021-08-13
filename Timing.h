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
 *  @file Timing.h
 *  @author Michal Durila
 *  @brief This module provides a method, which gives the amount of time elapsed from the start in seconds.
 *
 * Copyright 2021 Michal Durila, All rights reserved.
 */

#ifndef __TIMING_H__
#define __TIMING_H__

#include "Common.h"

#define TIMING_INITIAL_TIME 0.0

/**
 * @brief Gives the amount of time elapsed from the start of the system
 *
 * @return Elapsed time in seconds
 */
float64_t Timing_GetTime(void);

#endif /* __TIMING_H__ */
