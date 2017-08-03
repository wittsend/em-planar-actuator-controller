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

///////////////Includes/////////////////////////////////////////////////////////////////////////////
#include "pio.h"

///////////////Defines//////////////////////////////////////////////////////////////////////////////

///////////////Functions////////////////////////////////////////////////////////////////////////////
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
//Lab board IO mux control.
#if defined TARGET_LAB_BOARD
	DDRE = 0x03;			//Set port E 0,1 for output (mux)
	DDRD = 0x06;			//Set port D 5,6 for output (mux)
	PORTD = 0x00;			//Set mux to 0
	PORTE = 0x00;			//Set mux to 0
#endif

	DDRC = 0xFF;			//PORTC for output
	PORTC = 0x00;			//Switch all LEDs off initially
}