/*
 * TempDriver.c
 *
 *  Created on: 30/09/2018
 *      Author: kikia
 */

#include "SensorDriver.h"

void Sensor_vfnDriverInit (void){
	ADC_vfnDriverInit();
	vfnInitPIT();
}

uint_8 Sensor_bfnGetIn(uint_8 *bpSensorValue){
	uint_8 ADCValue = 0;

	if(ADC_bfnReadData(&ADCValue)){
		*bpSensorValue = ADCValue;
	}else{}
	return *bpSensorValue;
}
