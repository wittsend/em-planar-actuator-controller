/*
* pio.h
*
* Author : Matthew Witt (pxf5695@autuni.ac.nz)
* Created: 3/08/2017 7:45:54 PM
*
* Project Repository:https://github.com/wittsend/em-planar-actuator-controller
*
* Contains pin definitions and parallel IO initialisation function prototype
*
* More Info:
* Atmel AT90USB1287 Datasheet:http://www.atmel.com/images/doc7593.pdf
* Relevant reference materials or datasheets if applicable
*
* Functions:
* void pioInit(void)
*
*/

#ifndef PIO_H_
#define PIO_H_
///////////////Includes/////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>			//Hardware specific register definitions

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
*/
void pioInit(void);


#endif /* PIO_H_ */