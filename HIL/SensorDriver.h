/*
 * TempDriver.h
 *
 *  Created on: 30/09/2018
 *      Author: kikia
 */

#ifndef HIL_SENSORDRIVER_H_
#define HIL_SENSORDRIVER_H_

#include "ADCDriver.h"

void Sensor_vfnDriverInit (void);
uint_8 Sensor_bfnGetIn(uint_8 *bpSensorValue);

#endif /* HIL_SENSORDRIVER_H_ */
