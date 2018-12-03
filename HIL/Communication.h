/*
 * Communication.h
 *
 *  Created on: 15/10/2018
 *      Author: kikia
 */

#ifndef HIL_COMMUNICATION_H_
#define HIL_COMMUNICATION_H_

#include "UARTDriver.h"

extern volatile uint_8 rxData;
extern volatile uint_8 rxFlag;

void COMM_vfnDriverInit (void);
uint_8 COMM_bfnSendMsg (uint_8 *bpMsgToSend, uint_8 bMsgSize);
uint_8 COMM_bfnReceiveMsg (uint_8 *bpDataRx);


#endif /* HIL_COMMUNICATION_H_ */
