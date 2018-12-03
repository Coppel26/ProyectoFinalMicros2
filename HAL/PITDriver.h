/*
 * PITDriver.h
 *
 *  Created on: 24/09/2018
 *      Author: Enrique Martinez Salas y Daniel Coppel Vizcarra
 */

#ifndef PITDRIVER_H_
#define PITDRIVER_H_

#include"MKL25Z4.h"
#include "core_cm0plus.h"
#include "TYPES.h"

#define PIT_INTERRUPT_EN
#define PIT_IRQ		PIT_DriverIRQHandler

extern volatile uint_8 pitFlag;

void vfnInitPIT(void);


#endif /* PITDRIVER_H_ */
