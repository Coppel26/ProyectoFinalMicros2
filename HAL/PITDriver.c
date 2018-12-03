/*
 * PITDriver.c
 *
 *  Created on: 24/09/2018
 *      Author: Enrique Martinez Salas y Daniel Coppel Vizcarra
 */
#include "PITDriver.h"


volatile uint_8 pitFlag = 0;

void vfnInitPIT(void){
	SIM -> SCGC6 |= SIM_SCGC6_PIT_MASK;
	PIT -> MCR &= 0;
	PIT -> CHANNEL[0].LDVAL = 0xE4E1BF;

#ifdef PIT_INTERRUPT_EN
	NVIC -> ISER[0] |= (1<<PIT_IRQn);
	PIT -> CHANNEL[0].TCTRL |= PIT_TCTRL_TIE_MASK;

#endif
	PIT -> CHANNEL[0].TCTRL |= PIT_TCTRL_TEN_MASK;
}

#ifdef PIT_INTERRUPT_EN
	void PIT_IRQ(void){
		if(PIT -> CHANNEL[0].TFLG & PIT_TFLG_TIF_MASK){
			PIT -> CHANNEL[0].TFLG |= PIT_TFLG_TIF_MASK;
			pitFlag = 1;
		}
	}
#endif
