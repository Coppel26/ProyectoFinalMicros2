//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*!
	\file: 		GPIODriver.c
	\author: 	Enrique Martinez Salas y Daniel Coppel Vizcarra
	\date: 		08/11/2018
	\brief
*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "GPIODriver.h"

void vfnInitGPIODriver(){
	SIM -> SCGC5 |= SIM_SCGC5_PORTB_MASK;
	SIM -> SCGC5 |= SIM_SCGC5_PORTC_MASK;

	for(int i=0; i<=3;i++){
		PORTB -> PCR[i] |= PORT_PCR_MUX(1);
		GPIOB -> PDDR |= (1<<i);

	}

	PORTC -> PCR[1] |= PORT_PCR_MUX(1);
	GPIOC -> PDDR |= (1<<1);

}

void vfnSetDir(uint_8 dir){
	switch (dir){
	case up:
		GPIOB -> PDOR =	0;
		GPIOB -> PDOR |= MotorPinA;
		GPIOB -> PDOR |= MotorPinAA;

		break;
	case down:
		GPIOB -> PDOR =	0;
		GPIOB -> PDOR |= MotorPinB;
		GPIOB -> PDOR |= MotorPinBB;
		break;
	case left:
		GPIOB -> PDOR =	0;
		GPIOB -> PDOR |= MotorPinAA;
		break;
	case right:
		GPIOB -> PDOR =	0;
		GPIOB -> PDOR |= MotorPinA;
		break;
	case stop:
		GPIOB -> PDOR =	0;
		break;
	}
}

void vfnSetLight(uint_8 state){
	switch(state){
	case on:
		GPIOC -> PDOR |= (1<<1);
		break;
	case off:
		GPIOC -> PDOR = ~(1<<1);
	}
}



//------------------------------------------------------------------------------
// Variables
//------------------------------------------------------------------------------
/*!
    \var
    \brief
*/

//------------------------------------------------------------------------------
/*!
    \fn
    \param
    \return
    \brief
*/
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

