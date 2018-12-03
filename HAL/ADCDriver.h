/*
 * ADCDriver.h
 *
 *  Created on: 30/09/2018
 *      Author: Enrique Martinez Salas y Daniel Coppel Vizcarra
 */

#ifndef HAL_ADCDRIVER_H_
#define HAL_ADCDRIVER_H_

#include "MKL25Z4.h"
#include "TYPES.h"
#include "PITDriver.h"

void ADC_vfnDriverInit (void);
uint_8 ADC_bfnReadData(uint_8 *bpADCValue);



#endif /* HAL_ADCDRIVER_H_ */
