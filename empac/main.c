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
#include <math.h>

#include "pio.h"
#include "pwm.h"
#include "cosine_lut.h"

//////////////Functions/////////////////////////////////////////////////////////////////////////////
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
	//yPwmInit();
	//dcCos function testing
	//float result0 = dcCos(0);		//1
	//float result1 = dcCos(512);		//0
	//float result2 = dcCos(256);		//0.5
	//float result3 = dcCos(768);		//0.5
	//float result4 = dcCos(1000);	//1

	return;
}

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
		
		//for(float angle = 0.0; angle < (2.0*M_PI); angle = angle + 2*M_PI/(float)LUT_RESOLUTION)
		for(uint16_t angle = 0; angle < LUT_RESOLUTION; angle++)
		{
			//Would use a LUT for the final product rather than on the fly maths
			//Waveforms are shifted up by 511.5 so the minimum is at 0 and the max is 1023
			OCR3A = (int)(1023.0*dcCos(angle));
			OCR3B = (int)(1023.0*dcCos(angle));
			OCR3C = (int)(1023.0*dcCos(angle));
			//OCR3A = (int)(511.5*cos(angle) + 511.5);				//Phase A (0 deg shift)
			//OCR3B = (int)(511.5*cos(angle) + 511.5);				//Phase A (0 deg shift)
			//OCR3C = (int)(511.5*cos(angle) + 511.5);				//Phase A (0 deg shift)
			//OCR3B = (int)(511.5*cos(angle + 2*M_PI/3.0) + 511.5);	//Phase B (120 deg shift)
			//OCR3C = (int)(511.5*cos(angle + 4*M_PI/3.0) + 511.5);	//Phase C (240 deg shift)
		}
		
    }
}