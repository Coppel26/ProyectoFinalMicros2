/*
 * DirAndLightsDriver.c
 *
 *  Created on: 23/11/2018
 *      Author: Enrique Martinez Salas y Daniel Coppel Vizcarra
 */

#include "DirAndLightsDriver.h"

void vfnInitDirAndLightsDriver(){
	vfnInitGPIODriver();
}

void vfnMoveDirection(uint_8 driveDir){
	vfnSetDir(driveDir);
}

void vfnTurnLights(uint_8 turn){
	vfnSetLight(turn);
}
