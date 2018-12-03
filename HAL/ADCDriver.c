/*
 * ADCDriver.c
 *
 *  Created on: 30/09/2018
 *      Author: Enrique Martinez Salas y Daniel Coppel Vizcarra
 */

#include "ADCDriver.h"

void ADC_vfnDriverInit (void){
	SIM -> SCGC6 |= SIM_SCGC6_ADC0_MASK;
	SIM -> SCGC5 |= SIM_SCGC5_PORTE_MASK;
	ADC0-> CFG1 |= ADC_CFG1_ADICLK(0);
	ADC0-> CFG1 |= ADC_CFG1_MODE(0);
	ADC0-> CFG1 |= ADC_CFG1_ADIV(0);
	ADC0-> CFG2 |= ADC_CFG2_ADACKEN_MASK;
	ADC0-> SC3  |= ADC_SC3_AVGE_MASK;
	ADC0-> SC3  |= ADC_SC3_AVGS(2);
}

uint_8 ADC_bfnReadData(uint_8 *bpADCValue){
	ADC0 -> SC1[0] = ADC_SC1_ADCH(0);

	while( (ADC0->SC1[0] & ADC_SC1_COCO_MASK) == 0){}

	*bpADCValue = ADC0-> R[0];

	return SUCCESS;
}
