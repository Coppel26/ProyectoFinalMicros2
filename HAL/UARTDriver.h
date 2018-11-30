/*
 * PWMDriver.h
 *
 *  Created on: 05/10/2018
 *      Author: Enrique Martinez Salas y Daniel Coppel Vizcarra
 */
#ifndef HAL_UARTDRIVER_H_
#define HAL_UARTDRIVER_H_

#include "MKL25Z4.h"
#include "core_cm0plus.h"
#include "TYPES.h"

//#define UART0_INTERRUPT_EN

void UART_vfnDriverInit(void);
uint_8 UART0_bfnSend (uint_8 bTxData);

#ifdef UART0_INTERRUPT_EN//codigo para interrupciones
	#define UART0_IRQ		UART0_IRQHandler
	void vfnUART0CallbackRegister(void vfnCallBack (uint_8 data));

#else//Codigo con poleo o sin interrupciones
	uint_8 UART0_bfnRead (uint_8 *bpRxData);

#endif
#endif /* HAL_UARTDRIVER_H_ */
