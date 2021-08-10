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
 *  @file NvmMem.h
 *  @author esc
 *  @brief This module is used to write data into the non-volatile memory.
 *
 * Copyright 2021 esc Aerospace s.r.o., All rights reserved.
 */

#ifndef __NVMMEM_H__
#define __NVMMEM_H__

#include "Common.h"

void NvmMem_Write(uint32_t in_u32Address, const uint8_t *in_pu8Data, uint32_t in_u32DataSize);

#endif /* __NVMMEM_H__ */
