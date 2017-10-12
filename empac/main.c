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
	//timer2Init();
	xPwmInit();
	yPwmInit();
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
			[X].rawCnt		= 530,
			[X].deadzone	= 16,
			[X].adcChannel	= ADC_CH_JOYSTICK_X,
			[X].outputMax	= 100,
			
			[Y].rawMax		= 1023,
			[Y].rawMin		= 0,
			[Y].rawCnt		= 510,
			[Y].deadzone	= 16,
			[Y].adcChannel	= ADC_CH_JOYSTICK_Y,
			[Y].outputMax	= 100
		}
	};

	int16_t angleXA = 0;
	int16_t angleXB = 0;
	int16_t angleXC = 0;
	int16_t angleYA = 0;
	int16_t angleYB = 0;
	int16_t angleYC = 0;

    while(1) 
    {
		////Update the Phase A angles
		//angleXA += jd.axis[X].output;
		//angleYA += jd.axis[Y].output;
		//
		////If the angles are getting too big, scale them down
		//while(angleXA >= LUT_RESOLUTION)
			//angleXA -= LUT_RESOLUTION;
			//
		//while(angleXA < 0)
			//angleXA += LUT_RESOLUTION;
			//
		//while(angleYA >= LUT_RESOLUTION)
			//angleYA -= LUT_RESOLUTION;
			//
		//while(angleYA < 0)
			//angleYA += LUT_RESOLUTION;
		//
		////Calculate phase angles
		//angleXB = angleXA + PHB;
		//angleXC = angleXB + PHC;
		//angleYB = angleYA + PHB;
		//angleYC = angleYB + PHC;
//
		////Set the polarity pins
		//if(pwmCos(angleXA) < 0) pioXPhaseAOff; else pioXPhaseAOn;
		//if(pwmCos(angleXB) < 0) pioXPhaseBOff; else pioXPhaseBOn;
		//if(pwmCos(angleXC) < 0) pioXPhaseCOff; else pioXPhaseCOn;
		//if(pwmCos(angleYA) < 0) pioYPhaseAOff; else pioYPhaseAOn;
		//if(pwmCos(angleYB) < 0) pioYPhaseBOff; else pioYPhaseBOn;
		//if(pwmCos(angleYC) < 0) pioYPhaseCOff; else pioYPhaseCOn;
//
		////Set the PWM duty cycles
		//pwmXPHA = abs(pwmCos(angleXA));
		//pwmXPHB = abs(pwmCos(angleXB));
		//pwmXPHC = abs(pwmCos(angleXC));
		//pwmYPHA = abs(pwmCos(angleYA));
		//pwmYPHB = abs(pwmCos(angleYB));
		//pwmYPHC = abs(pwmCos(angleYC));

		//Poll the Joystick
		joyUpdate(&jd);		//Fetch new data from joystick.
    }
}


