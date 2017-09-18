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
<<<<<<< HEAD
* uint8_t adcNewData(void)
* uint16_t adcGetData(uint8_t channel)
* ISR(ADC_Vect)
=======
* ISR(ADC_vect)
>>>>>>> ADC-current-control-test-code
*
*/

/////////////[Includes]/////////////////////////////////////////////////////////////////////////////
#include "adc.h"

//////////////[Global variables]////////////////////////////////////////////////////////////////////
volatile uint8_t adcCurrentChannel = 0;
volatile uint8_t adcNewDataFlag = 0;		//1 When new data, otherwise 0
volatile uint16_t adcData[ADC_CHANNELS];	//Stores data from each ADC channel

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
*/
void adcInit(void)
{
	ADMUX	
	=	(1<<REFS0);
	//|	0x01;					//Voltage reference selection.
	
	adcSetChannel(ADC_CH_JOYSTICK_X);

	=	(1<<REFS0)
	//|	0x01;					//Voltage reference selection.
	ADCSRB
	|=	(1<<ADHSM)				//High speed
	|	(0x00);					//Free running mode
	ADCSRA
	=	(1<<ADEN)				//Enable the ADC
	|	(1<<ADSC)				//Start converting
	|	(1<<ADIE)				//Enable interrupt
	//|	(1<<ADATE)				//Auto triggering Enabled
	|	0x07;					//1/128th conversion speed
}

/*
* Function:
* uint8_t adcNewData(void)
*
* Tells the calling function whether or not new data is available to be read from the ADC driver
*
* Inputs:
* none
*
* Returns:
* 1 if new ADC data is available, otherwise returns 0
*
* Implementation:
* If newDataFlag is set, then reset newDataFlag and return 1, otherwise return 0
*
*/
uint8_t adcNewData(void)
{
	if(adcNewDataFlag)
	{
		adcNewDataFlag = 0;
		return 1;
	} else
		return 0;
}

/*
* Function:
* uint16_t adcGetData(uint8_t channel)
*
* Will return the data last sampled from the given ADC channel
*
* Inputs:
* uint8_t channel:
*   The channel number of the desired ADC channel to read
*
* Returns:
* The data last retrieved from said ADC channel
*
* Implementation:
* If channel is out of range, then return 0, otherwise return the value stored in the adcData array
* for the given channel.
*
*/
uint16_t adcGetData(uint8_t channel)
{
	if(channel >= ADC_CHANNELS)
		return 0;
		
	return adcData[channel];
}

/*
* Function:
* ISR(ADC_vect)
*
* ADC conversion complete interrupt
*
* Inputs:
* none
*
* Returns:
* none
*
* Implementation:
* This interrupt is called when the last ADC conversion has finished. The first this is the data 
* from the last conversion is retrieved and stored. Next, the ADC channel is changed to the next
* channel. If the channel that was just read was the last ADC channel, then set the adcNewDataFlag.
* Finally, conversion is started again on the next channel.
*
*/
ISR(ADC_vect)
{
	adcData[adcCurrentChannel] = adcGetSample;
	
	switch(adcCurrentChannel)
	{
		case ADC_CH_JOYSTICK_X:
			adcCurrentChannel = ADC_CH_JOYSTICK_Y;
			break;
			
		case ADC_CH_JOYSTICK_Y:
			adcCurrentChannel = ADC_CH_JOYSTICK_X;
			adcNewDataFlag = 1;
			break;
	}
	adcSetChannel(adcCurrentChannel);
	adcStartConv;
}