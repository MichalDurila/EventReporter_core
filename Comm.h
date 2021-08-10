/*
 ******************************************************************************
 *                                                                            *
 *                           esc Aerospace s.r.o.                             *
 *                       https://www.esc-aerospace.com                        *
 *                                                                            *
 *                           ALL RIGHTS RESERVED                              *
 *                                                                            *
 ******************************************************************************
 */

/**
 *  @file Comm.h
 *  @author esc
 *  @brief This module provides communication with externally connected systems.
 *
 * Copyright 2021 esc Aerospace s.r.o., All rights reserved.
 */

#ifndef __COMM_H__
#define __COMM_H__

#include "Common.h"

/**
 * @brief The function sends event report to external system.
 *
 * @param in_pu8EventData   Event report data array
 * @param in_u32DataSize    Size of event report data in bytes
 */
void Comm_SendEventReport(const uint8_t *in_pu8EventData, uint32_t in_u32DataSize);

#endif /* __COMM_H__ */
