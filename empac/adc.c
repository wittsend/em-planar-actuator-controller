/*
* adc.c
*
* Author : Matthew Witt (pxf5695@autuni.ac.nz)
* Created: 4/08/2017 1:55:37 PM
*
* Project Repository:https://github.com/wittsend/em-planar-actuator-controller
*
* Control and setup functions for the analogue to digital converter.
*
* More Info:
* Atmel AT90USB1287 Datasheet:http://www.atmel.com/images/doc7593.pdf
* Relevant reference materials or datasheets if applicable
*
* Functions:
* void funcName(void)
*
*/

//////////////Includes//////////////////////////////////////////////////////////////////////////////
#include "adc.h"

///////////////Defines//////////////////////////////////////////////////////////////////////////////


//////////////Functions/////////////////////////////////////////////////////////////////////////////

/*
* Function:
* void initAdc(void)
*
* Sets up the analogue to digital hardware
*
* Inputs:
* none
*
* Returns:
* none
*
* Implementation:
* Currently sets the ADC in free running mode and just reads from one potentiometer. Eventually
* it will be retrieving data from two pots and will probably have to use single conversion.
*
* Improvements:
* Macros to handle tasks of mux switching etc.
*
*/
void initAdc(void)
{
	ADMUX	
	=	(1<<REFS0);				//Voltage reference selection.
	ADCSRB
	=	0x00;					//Free running mode
	ADCSRA
	=	(1<<ADEN)				//Enable the ADC
	|	(1<<ADSC)				//Start converting
	|	(1<<ADATE)				//Auto triggering Enabled
	|	0x07;					//1/128th conversion speed
	
	setAdcChannel(POT1);
}