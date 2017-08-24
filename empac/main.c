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
#include "adc.h"
#include "cosine_lut.h"

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
	//buildLuts();
	pioInit();
	//xPwmInit();
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
* Implementation:
* TODO:main function implementation.
*
*/
int main(void)
{
	setup();
	
	//uint16_t angle = 0;
	
	uint16_t pot1 = 0;
	uint16_t pot2 = 0;
	uint16_t ldr = 0;
	uint8_t currentChannel = 0;
	uint16_t currentSample = 0;
    while(1) 
    {
			//angle = adcLastSample;

			//Would use a LUT for the final product rather than on the fly maths
			//Waveforms are shifted up by 511.5 so the minimum is at 0 and the max is 1023
			//OCR3A = dcCos(angle+PHA);
			//OCR3B = dcCos(angle+PHB);
			//OCR3C = dcCos(angle+PHC);
			//OCR3A = dcCosDeg(angle);
			//OCR3B = dcCosDeg(angle+120);
			//OCR3C = dcCosDeg(angle+240);

				//currentChannel = adcGetChannel;
				//currentSample = adcLastSample;
				//switch(currentChannel)
				//{
					//case ADC_LDR_CH:
						//adcSetChannel(ADC_POT1_CH);
						//ldr = currentSample;
						//break;
//
					//case ADC_POT1_CH:
						//adcSetChannel(ADC_POT2_CH);
						//pot1 = currentSample;
						//break;
//
					//case ADC_POT2_CH:
						//adcSetChannel(ADC_LDR_CH);
						//pot2 = currentSample;
						//break;
				//}
				//adcStartConv;

    }
}


