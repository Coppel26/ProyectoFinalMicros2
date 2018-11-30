/*
 * TYPES.h
 *
 *  Created on: 01/10/2018
 *      Author: Enrique Martinez Salas y Daniel Coppel Vizcarra
 */

#ifndef TYPES_H_
#define TYPES_H_

	#include "MKL25Z4.h"

	typedef unsigned char	uint_8;
	typedef unsigned short	uint_16;
	typedef unsigned long	uint_32;
	typedef signed char		int_8;
	typedef signed char		int_16;
	typedef signed char		int_32;
	#define SUCCESS			(1)
	#define ERROR			(0)
	#ifdef NULL
		#define NULL		(void*)0
	#endif

#endif /* TYPES_H_ */
