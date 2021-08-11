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

#ifndef COMMON_H_
#define COMMON_H_

#define NULL ((void *)0)

typedef enum
{
    false = 0U,
    true  = 1U
} boolean;

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef double float64_t;

#endif /* COMMON_H_ */
