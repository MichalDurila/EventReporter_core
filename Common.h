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

#define NULL                             ((void *)0)
#define COMMON_STARTING_INDEX_OF_ARRAY   0U
#define COMMON_FLOAT64_SIZE_IN_BYTES     8U
#define COMMON_UINT32_SIZE_IN_BYTES      4U
#define COMMON_BYTE_SIZE_IN_BITS         8U

typedef enum
{
    E_FALSE = 0U,
    E_TRUE  = 1U
} boolean;

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef double float64_t;

#endif /* __COMMON_H__ */
