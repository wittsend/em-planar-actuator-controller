/*
* main.c
*
* Author : Matthew Witt (pxf5695@autuni.ac.nz)
* Created: 27/07/2017 3:22:00 PM
*
* Project Repository:https://github.com/wittsend/em-planar-actuator-controller
*
* Dual 3 phase direct digital synthesiser for controlling an electromagnetic planar actuator.
*
* More Info:
* Atmel AT90USB1287 Datasheet:http://www.atmel.com/images/doc7593.pdf
* Relevant reference materials or datasheets if applicable
*
* Functions:
* void setup(void)
* int main(void)
*
*/

//////////////Includes//////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>			//Hardware specific register definitions
#include <stdint.h>			//Gives C99 standard integer definitions
//#include <math.h>

#include "pio.h"
#include "pwm.h"
#include "cosine_lut.h"

//////////////Functions/////////////////////////////////////////////////////////////////////////////
void setup(void);
/*
* Function:
* int main(void)
*
* Overview of program operation
*
* Inputs:
* none
*
* Returns:
* none
*
* Implementation:
* TODO:main function implementation.
*
*/
int main(void)
{
	setup();
    while(1) 
    {
		for(float angle = 0.0; angle < 360; angle += DEG_LUT_CONV)
		//for(int16_t angle = 0; angle < 2048; angle++)
		{
			//Would use a LUT for the final product rather than on the fly maths
			//Waveforms are shifted up by 511.5 so the minimum is at 0 and the max is 1023
			//OCR3A = dcCos(angle);
			//OCR3B = dcCos(angle+341);
			//OCR3C = dcCos(angle+682);
			OCR3A = dcCosDeg(angle);
			OCR3B = dcCosDeg(angle+120);
			OCR3C = dcCosDeg(angle+240);
			
		}
		
    }
}

/*
* Function:
* void setup(void)
*
* Initialises all hardware and builds cosine look up table
*
* Inputs:
* none
*
* Returns:
* none
*
* Implementation:
* - Set up parallel IO pins for use
* - Initialise the PWM channels that will be used to control the coils
*
*/
void setup(void)
{
	buildLuts();
	pioInit();
	xPwmInit();
	//yPwmInit();		//Not implemented
	return;
}
