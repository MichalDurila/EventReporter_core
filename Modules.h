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
 *  @file Modules.h
 *  @author esc
 *  @brief Definition of enumerate containing names of all modules
 *
 * Copyright 2021 esc Aerospace s.r.o., All rights reserved.
 */

#ifndef __MODULES_H__
#define __MODULES_H__

/* Typedef containing all modules */
typedef enum
{
	E_MODULES_ID_COMM                    = 1U,
	E_MODULES_ID_STORAGE                 = 2U,
	E_MODULES_ID_NVMMEM                  = 3U
} Modules_Id_e;

#endif /* __MODULES_H__ */
