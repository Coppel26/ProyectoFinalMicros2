/*
 * Communication.c
 *
 *  Created on: 15/10/2018
 *      Author: Enrique Martinez Salas y Daniel Coppel Vizcarra
 */


#include "Communication.h"
void COMM_RxUartData(uint_8 data);

volatile uint_8 rxData;
volatile uint_8 rxFlag = ERROR;

void COMM_vfnDriverInit (void){
#ifdef UART0_INTERRUPT_EN
	vfnUART0CallbackRegister(COMM_RxUartData);
#endif
	UART_vfnDriverInit();
}

uint_8 COMM_bfnSendMsg (uint_8 *bpMsgToSend, uint_8 bMsgSize){
	while (bMsgSize--){
		UART0_bfnSend(*bpMsgToSend);

	}
	return *bpMsgToSend;
}

uint_8 COMM_bfnReceiveMsg (uint_8 *bpDataRx){
		uint_8 COMM_RStatus = 0;

		if(UART0_bfnRead(bpDataRx)){
			COMM_RStatus = SUCCESS;
		}else{
			COMM_RStatus = ERROR;
		}
		return COMM_RStatus;
}

#ifdef UART0_INTERRUPT_EN
void COMM_RxUartData(uint_8 data){
	rxFlag = SUCCESS;
	//UART0_bfnSend(data);
	rxData = data;
}
#endif
