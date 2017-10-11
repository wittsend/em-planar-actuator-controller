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
//X axis
#define PIO_XPHA_PORT	PORTC
#define PIO_XPHB_PORT	PORTC
#define PIO_XPHC_PORT	PORTC
#define PIO_XPHA_PIN	0
#define PIO_XPHB_PIN	1
#define PIO_XPHC_PIN	2
//Y axis
#define PIO_YPHA_PORT	PORTC
#define PIO_YPHB_PORT	PORTC
#define PIO_YPHC_PORT	PORTC
#define PIO_YPHA_PIN	3
#define PIO_YPHB_PIN	4
#define PIO_YPHC_PIN	5

//Phase control macros
//X axis
#define pioXPhaseAOn	(PIO_XPHA_PORT |= (1<<PIO_XPHA_PIN))
#define pioXPhaseBOn	(PIO_XPHB_PORT |= (1<<PIO_XPHB_PIN))
#define pioXPhaseCOn	(PIO_XPHC_PORT |= (1<<PIO_XPHC_PIN))
#define pioXPhaseAOff	(PIO_XPHA_PORT &= ~(1<<PIO_XPHA_PIN))
#define pioXPhaseBOff	(PIO_XPHB_PORT &= ~(1<<PIO_XPHB_PIN))
#define pioXPhaseCOff	(PIO_XPHC_PORT &= ~(1<<PIO_XPHC_PIN))
#define pioXPhaseATog	(PIO_XPHA_PORT ^= (1<<PIO_XPHA_PIN))
#define pioXPhaseBTog	(PIO_XPHB_PORT ^= (1<<PIO_XPHB_PIN))
#define pioXPhaseCTog	(PIO_XPHC_PORT ^= (1<<PIO_XPHC_PIN))

//Y axis
#define pioYPhaseAOn	(PIO_YPHA_PORT |= (1<<PIO_YPHA_PIN))
#define pioYPhaseBOn	(PIO_YPHB_PORT |= (1<<PIO_YPHB_PIN))
#define pioYPhaseCOn	(PIO_YPHC_PORT |= (1<<PIO_YPHC_PIN))
#define pioYPhaseAOff	(PIO_YPHA_PORT &= ~(1<<PIO_YPHA_PIN))
#define pioYPhaseBOff	(PIO_YPHB_PORT &= ~(1<<PIO_YPHB_PIN))
#define pioYPhaseCOff	(PIO_YPHC_PORT &= ~(1<<PIO_YPHC_PIN))
#define pioYPhaseATog	(PIO_YPHA_PORT ^= (1<<PIO_YPHA_PIN))
#define pioYPhaseBTog	(PIO_YPHB_PORT ^= (1<<PIO_YPHB_PIN))
#define pioYPhaseCTog	(PIO_YPHC_PORT ^= (1<<PIO_YPHC_PIN))

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