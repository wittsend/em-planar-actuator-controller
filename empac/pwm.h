/*
* pwm.h
*
* Author : Matthew Witt (pxf5695@autuni.ac.nz)
* Created: 3/08/2017 7:46:05 PM
*
* Project Repository:https://github.com/wittsend/em-planar-actuator-controller
*
* Defines and function prototypes relating to Pulse Width Modulation
*
* More Info:
* Atmel AT90USB1287 Datasheet:http://www.atmel.com/images/doc7593.pdf
* Relevant reference materials or datasheets if applicable
*
* Functions:
* void xPwmInit(void)
* void yPwmInit(void)
*
*/

#ifndef PWM_H_
#define PWM_H_

//////////////[Includes]////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>			//Hardware specific register definitions

//////////////[Defines]/////////////////////////////////////////////////////////////////////////////

//////////////[Functions]///////////////////////////////////////////////////////////////////////////
/*
* Function:
* void xPwmInit(void)
*
* Initialises the timer X and the 3 PWM channels used for the x axis stator windings.
*
* Inputs:
* none
*
* Returns:
* none
*
*/
void xPwmInit(void);

/*
* Function:
* void yPwmInit(void)
*
* Initialises the timer X and the 3 PWM channels used for the y axis stator windings.
*
* Inputs:
* none
*
* Returns:
* none
*
*/
void yPwmInit(void);

#endif /* PWM_H_ */