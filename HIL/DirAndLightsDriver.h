/*
 * DirAndLightsDriver.h
 *
 *  Created on: 23/11/2018
 *      Author: Enrique Martinez Salas y Daniel Coppel Vizcarra
 */

#ifndef HIL_DIRANDLIGHTSDRIVER_H_
#define HIL_DIRANDLIGHTSDRIVER_H_

#include "GPIODriver.h"

void vfnInitDirAndLightsDriver();
void vfnMoveDirection(uint_8 driveDir);
void vfnTurnLights(uint_8 turn);

#endif /* HIL_DIRANDLIGHTSDRIVER_H_ */
