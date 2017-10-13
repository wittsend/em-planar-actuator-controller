/*
* pwm.c
*
* Author : Matthew Witt (pxf5695@autuni.ac.nz)
* Created: 3/08/2017 7:30:31 PM
*
* Project Repository:https://github.com/wittsend/em-planar-actuator-controller
*
* Functions for initialising and controlling the PWM outputs
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

//////////////[Includes]////////////////////////////////////////////////////////////////////////////
#include "pwm.h"

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
* Implementation:
* Timer X is initialised and each PWM channel is set up. The timer is set up to run in
* 10bit fast PWM mode, which means that the timer counter counts from 0 to 2^10 - 1 (1023). The
* duty cycle is set by the value stored in OCRnX where n is the number of the associated timer and
* X is the PWM channel. There are three PWM channels per timer. The OCR value can be a number
* anywhere between 0 and 1023. The fast PWM mode below is set to clear the PWM pin X when
* the timer counter is equal to OCRnX and to set pin X when the timer counter reaches the TOP value
* (1023)
*
* Improvements:
* Macros and defines for pin names and timer settings.
*
*/
void xPwmInit(void)
{	
	TCCR1A
	=	(0x02<<COM3A0)		//Clear OC3A on compare match, set on TOP
	|	(0x02<<COM3B0)		//Clear OC3B on compare match, set on TOP
	|	(0x02<<COM3C0)		//Clear OC3C on compare match, set on TOP
	|	(0x03<<WGM30);		//WG mode 7 Fast 10bit PWM
	TCCR1B
	=	(0x01<<WGM32)		//WG mode 7 Fast 10bit PWM
	|	(0x01<<CS30);		//clk/1 (7.8kHz PWM)
	
	OCR1A = 0x003F;			//Initial values for OCR3
	OCR1B = 0x003F;
	OCR1C = 0x003F;
}

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
* Implementation:
* Timer X is initialised and each PWM channel is set up. The timer is set up to run in 
* 10bit fast PWM mode, which means that the timer counter counts from 0 to 2^10 - 1 (1023). The
* duty cycle is set by the value stored in OCRnX where n is the number of the associated timer and
* X is the PWM channel. There are three PWM channels per timer. The OCR value can be a number
* anywhere between 0 and 1023. The fast PWM mode below is set to clear the PWM pin X when 
* the timer counter is equal to OCRnX and to set pin X when the timer counter reaches the TOP value
* (1023)
*
* Improvements:
* Macros and defines for pin names and timer settings.
*
*/
void yPwmInit(void)
{
	TCCR3A
	=	(0x02<<COM3A0)		//Clear OC3A on compare match, set on TOP
	|	(0x02<<COM3B0)		//Clear OC3B on compare match, set on TOP
	|	(0x02<<COM3C0)		//Clear OC3C on compare match, set on TOP
	|	(0x03<<WGM30);		//WG mode 7 Fast 10bit PWM
	TCCR3B
	=	(0x01<<WGM32)		//WG mode 7 Fast 10bit PWM
	|	(0x01<<CS30);		//clk/1 (7.8kHz PWM)
	
	OCR3A = 0x003F;			//Initial values for OCR3
	OCR3B = 0x003F;
	OCR3C = 0x003F;
}