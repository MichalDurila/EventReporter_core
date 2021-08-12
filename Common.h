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
 *  @file Common.h
 *  @author Michal Durila
 *  @brief This module defines some data types and NULL pointer.
 *
 * Copyright 2021 Michal Durila, All rights reserved.
 */

#ifndef __COMMON_H__
#define __COMMON_H__

#define NULL ((void *)0)

typedef enum
{
    E_FALSE = 0U,
    E_TRUE  = 1U
} boolean;

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef double float64_t;

#endif /* __COMMON_H__ */
