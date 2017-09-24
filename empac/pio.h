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
//////////////[Includes]////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>			//Hardware specific register definitions

//////////////[Defines]/////////////////////////////////////////////////////////////////////////////
//Phase control port and pin definitions
#define PIO_PHA_PORT	PORTC
#define PIO_PHB_PORT	PORTC
#define PIO_PHC_PORT	PORTC

#define PIO_PHA_PIN		0
#define PIO_PHB_PIN		1
#define PIO_PHC_PIN		2

//Phase control macros
#define pioPhaseAOn		(PIO_PHA_PORT |= (1<<PIO_PHA_PIN))
#define pioPhaseBOn		(PIO_PHB_PORT |= (1<<PIO_PHB_PIN))
#define pioPhaseCOn		(PIO_PHC_PORT |= (1<<PIO_PHC_PIN))

#define pioPhaseAOff	(PIO_PHA_PORT &= ~(1<<PIO_PHA_PIN))
#define pioPhaseBOff	(PIO_PHB_PORT &= ~(1<<PIO_PHB_PIN))
#define pioPhaseCOff	(PIO_PHC_PORT &= ~(1<<PIO_PHC_PIN))

#define pioPhaseATog	(PIO_PHA_PORT ^= (1<<PIO_PHA_PIN))
#define pioPhaseBTog	(PIO_PHB_PORT ^= (1<<PIO_PHB_PIN))
#define pioPhaseCTog	(PIO_PHC_PORT ^= (1<<PIO_PHC_PIN))


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
*/
void pioInit(void);


#endif /* PIO_H_ */