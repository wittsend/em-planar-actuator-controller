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
* void adcInit(void)
* ISR(ADC_vect)
*
*/

/////////////[Includes]/////////////////////////////////////////////////////////////////////////////
#include "adc.h"

/////////////[Defines]//////////////////////////////////////////////////////////////////////////////

/////////////[Global Variables]/////////////////////////////////////////////////////////////////////

/////////////[Functions]////////////////////////////////////////////////////////////////////////////

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
void adcInit(void)
{
	ADMUX	
	=	(1<<REFS0)
	|	(1<<ADLAR);
	//|	0x01;					//Voltage reference selection.
	ADCSRB
	|=	(1<<ADHSM)				//High speed
	|	(0x00);					//Free running mode
	ADCSRA
	=	(1<<ADEN)				//Enable the ADC
	|	(1<<ADSC)				//Start converting
	|	(1<<ADIE)				//Enable interrupt
	//|	(1<<ADATE)				//Auto triggering Enabled
	|	(ADC_DIV8_CLK);			//1MHz ADC clock
	
	adcSetChannel(ADC_PHA_CH);
}

/*
* Function:
* ISR(ADC_vect)
*
* The analogue to digital converter interrupt service routine. Runs when an ADC conversion is 
* complete.
*
* Inputs:
* none
*
* Returns:
* none
*
* Implementation:
* This is a state machine that looks at what ADC channel was set to determine the state we are in.
* The value in the ADC holding register for the current channel is compared to hysteretic threshold
* values, and the respective coil control pin is set high or low depending on whether the ADC
* was below or above the thresholds. When finished, the adcChannel is changed to the next channel
* and the conversion is started again.
*
*/
ISR(ADC_vect)
{
	//uint8_t currCh = adcGetChannel;
	//uint16_t sample = adcLastSample;
	PORTC ^= (1<<0);
	switch(adcGetChannel)
	{
		case ADC_PHA_CH:
			adcSetChannel(ADC_PHA_CH);
			//if(adcLastSample > ADC_UPPER_THRES)
				//pioPhaseAOff;
			//if(adcLastSample < ADC_LOWER_THRES)
				//pioPhaseAOn;
			break;

		case ADC_PHB_CH:
			adcSetChannel(ADC_PHC_CH);
			//if(adcLastSample > ADC_UPPER_THRES)
				//pioPhaseBOff;
			//if(adcLastSample < ADC_LOWER_THRES)
				//pioPhaseBOn;
			break;

		case ADC_PHC_CH:
			adcSetChannel(ADC_PHA_CH);
			//if(adcLastSample > ADC_UPPER_THRES)
				//pioPhaseCOff;
			//if(adcLastSample < ADC_LOWER_THRES)
				//pioPhaseCOn;

			break;
	}
	adcStartConv;
	PORTC ^= (1<<0);
}