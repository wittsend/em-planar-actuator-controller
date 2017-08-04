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

///////////////Defines//////////////////////////////////////////////////////////////////////////////
//Base phase relationships:
//Cosine table phase relationships
#define PHA			0
#define PHB			341
#define PHC			682
//Phase relationships in degrees
#define PHA_DEG		0
#define PHB_DEG		120
#define PHC_DEG		240
//Phase relationships in radians
#define PHA_RAD		0
#define PHB_RAD		2.094395
#define PHC_RAD		4.188790

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
	//yPwmInit();		//Not implemented
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
		//for(float angle = 0.0; angle < 360.0; angle += DEG_LUT_CONV)
		for(int16_t angle = 0; angle < 1024; angle++)
		{
			//Would use a LUT for the final product rather than on the fly maths
			//Waveforms are shifted up by 511.5 so the minimum is at 0 and the max is 1023
			OCR3A = dcCos(angle+PHA);
			OCR3B = dcCos(angle+PHB);
			OCR3C = dcCos(angle+PHC);
			//OCR3A = dcCosDeg(angle);
			//OCR3B = dcCosDeg(angle+120);
			//OCR3C = dcCosDeg(angle+240);
		}
    }
}


