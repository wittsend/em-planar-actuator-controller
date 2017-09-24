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

/////////////[Includes]/////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>			//Hardware specific register definitions
#include <avr/interrupt.h>	//Interrupt support
#include <stdint.h>			//Gives C99 standard integer definitions

//#include <math.h>

#include "pio.h"
#include "pwm.h"
#include "timer.h"
#include "adc.h"
#include "cosine_lut.h"
#include "joystick.h"

//////////////[Defines]/////////////////////////////////////////////////////////////////////////////
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

//////////////[Global Variables]////////////////////////////////////////////////////////////////////


/////////////[Functions]////////////////////////////////////////////////////////////////////////////
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
	timer2Init();
	xPwmInit();
	//yPwmInit();		//Not implemented
	adcInit();
	
	sei();				//Enable global interrupts
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
* Implementation
* TODO:main function implementation.
*
*/
int main(void)
{
	//Initialise all hardware and build LUTs
	setup();
	
	//Create Joystick object
	JoystickData2D jd =
	{
		.numOfAxes = 2,
		.axis =
		{
			[X].rawMax		= 1023,
			[X].rawMin		= 0,
			[X].rawCnt		= 512,
			[X].deadzone	= 16,
			[X].adcChannel	= ADC_CH_JOYSTICK_X,
			[X].outputMax	= 100,
			
			[Y].rawMax		= 1023,
			[Y].rawMin		= 0,
			[Y].rawCnt		= 512,
			[Y].deadzone	= 16,
			[Y].adcChannel	= ADC_CH_JOYSTICK_Y,
			[Y].outputMax	= 100
		}
	};

    while(1) 
    {
			//angle = adcLastSample;

			//Would use a LUT for the final product rather than on the fly maths
			//Waveforms are shifted up by 511.5 so the minimum is at 0 and the max is 1023

			//OCR3A = pwmDcCos(angle+PHA);
			//OCR3B = pwmDcCos(angle+PHB);
			//OCR3C = pwmDcCos(angle+PHC);

		joyUpdate(&jd);		//Fetch new data from joystick.
    }
}


