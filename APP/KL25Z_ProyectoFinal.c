/*
 * Copyright 2016-2018 NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    KL25Z_ProyectoFinal.c
 * @brief   Application entry point.
 */
/* TODO: insert other include files here. */
#include "DirAndLightsDriver.h"
#include "Communication.h"
#include "SensorDriver.h"
/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */

int main(void) {
	uint_8 num;
	uint_8 sensor;
	vfnInitDirAndLightsDriver();
	Sensor_vfnDriverInit();
	COMM_vfnDriverInit();
    while(1) {
    	if(Sensor_bfnGetIn(&sensor)== 255){
    		if(COMM_bfnReceiveMsg(&num)){
    			if(num<=stop){
    				vfnMoveDirection(num);
    			}else{
    				vfnTurnLights(num);
    			}
    		}

    	}else{
    		if(COMM_bfnReceiveMsg(&num)){
    			switch(num){
    			case down:
					vfnMoveDirection(num);
    				if(pitFlag){
    					pitFlag = 0;
    				}
    				break;
    			case off:
    				vfnTurnLights(num);
    				break;
    			case on:
    				vfnTurnLights(num);
       				break;
    			}
    		}else{
			vfnMoveDirection(stop);
    		}
		}
    }
    return 0 ;
}
