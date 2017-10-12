/*
* pio.c
*
* Author : Matthew Witt (pxf5695@autuni.ac.nz)
* Created: 3/08/2017 7:45:54 PM
*
* Project Repository:https://github.com/wittsend/em-planar-actuator-controller
*
* Contains parallel IO initialisation routine
*
* More Info:
* Atmel AT90USB1287 Datasheet:http://www.atmel.com/images/doc7593.pdf
* Relevant reference materials or datasheets if applicable
*
* Functions:
* void pioInit(void)
*
*/

//////////////[Includes]////////////////////////////////////////////////////////////////////////////
#include "pio.h"

//////////////[Functions]///////////////////////////////////////////////////////////////////////////
/*
* Function:
* void pioInit(void)
*
* Initialises IO pins on the microcontroller to perform their tasks.
*
* Inputs:
* none
*
* Returns:
* none
*
* Implementation:
* TODO:[explain key steps of function]
* [use heavy detail for anything complicated]
*
*/
void pioInit(void)
{
	DDRF = 0x00;			//PORTA for input (Analogue inputs)
	DDRB = 0xE0;			//PWM outputs for X axis
	DDRC = 0x3F;			//PORTC for output (Polarity select pins)
	DDRE = 0x3A;			//PWM outputs for Y axis and UART TX
	
	PORTB = 0xE0;
	PORTC = 0x00;			//Switch all Outputs off initially
	PORTE = 0x3A;
}