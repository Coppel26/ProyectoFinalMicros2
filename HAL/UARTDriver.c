/*
 * UARTDriver.c
 *
 *  Created on: 15/10/2018
 *      Author: Enrique Martinez Salas y Daniel Coppel Vizcarra
 */
#include "UARTDriver.h"

#ifdef UART0_INTERRUPT_EN
void(*vfnCallbackFn)(uint_8 bpRxData);
#endif

void UART_vfnDriverInit(void){
	//KL25 = 47 nS de frecuencia
	SIM -> SOPT2 |= SIM_SOPT2_UART0SRC(1);//Seleccciona el clock de UART0
	SIM -> SCGC4 |= SIM_SCGC4_UART0_MASK;//CLOCK ENABLE FOR UART0
	SIM -> SCGC5 |= SIM_SCGC5_PORTA_MASK;//CLOCK ENABLE FOR PORT A
	//SIM -> SCGC5 |= SIM_SCGC5_PORTD_MASK;//CLOCK ENABLE FOR PORT A

	PORTA -> PCR[1] |= PORT_PCR_MUX(2); //PORT A1 -> UART0 Rx
	PORTA -> PCR[2] |= PORT_PCR_MUX(2); //PORT A2 -> UART0 Tx

	//PORTE -> PCR[20] |= PORT_PCR_MUX(2);
	//PORTE -> PCR[21] |= PORT_PCR_MUX(2);

	//PORTD->PCR[6] |= PORT_PCR_MUX(3);
	//PORTD->PCR[7] |= PORT_PCR_MUX(3);

	//UART0 -> BDH = (0 & 0x1F);//20.97MHz Formula para BR BaudClock/((OSR+1)*BR)
	UART0 -> BDL = (129 & 0xFF);

	//UART0->C1 |= UART0_C1_PT_MASK;
	//UART0->C1 |= UART0_C1_PE_MASK;

	UART0 -> C2 |= UART0_C2_TE_MASK;
	UART0 -> C2 |= UART0_C2_RE_MASK;

#ifdef UART0_INTERRUPT_EN
		NVIC-> ISER[0] |= (1 << UART0_IRQn);
		UART0 -> C2 |= UART0_C2_RIE_MASK;
#endif

}

uint_8 UART0_bfnSend (uint_8 bTxData){
	static uint_8 Sstatus = 0;

	if(UART0 -> S1 & UART0_S1_TDRE_MASK){
		UART0 -> D = bTxData;
		Sstatus = SUCCESS;
	}else{
		Sstatus = ERROR;
	}
	return Sstatus;
}

//codigo para interrupciones
#ifdef UART0_INTERRUPT_EN
	void UART0_IRQ(void){
		vfnCallbackFn(UART0 -> D);

		if(UART0 -> S1 & UART0_S1_OR_MASK){
			UART0 -> S1 |= UART0_S1_OR_MASK;
		}
	}

	void vfnUART0CallbackRegister(void vfnCallBack(uint_8 data)){
		vfnCallbackFn = vfnCallBack;
	}
//codigo sin interrupciones (poleo)
#else
	uint_8 UART0_bfnRead (uint_8 *bpRxData){
		static uint_8 Rstatus = 0;

		if(UART0->S1 & UART0_S1_RDRF_MASK){
			*bpRxData = UART0 -> D;
			Rstatus = SUCCESS;
		}else{
			Rstatus = ERROR;
		}
		if(UART0 -> S1 & UART0_S1_OR_MASK){
			UART0 -> S1 |= UART0_S1_OR_MASK;
		}
		return Rstatus;
	}
#endif
