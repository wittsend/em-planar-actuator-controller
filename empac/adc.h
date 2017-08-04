/*
* adc.h
*
* Author : Matthew Witt (pxf5695@autuni.ac.nz)
* Created: 4/08/2017 1:55:37 PM
*
* Project Repository:https://github.com/wittsend/em-planar-actuator-controller
*
* Provides hardware definitions and function prototypes for the analogue to digital converter.
*
* More Info:
* Atmel AT90USB1287 Datasheet:http://www.atmel.com/images/doc7593.pdf
* Relevant reference materials or datasheets if applicable
*
* Functions:
* void funcName(void)
*
*/

#ifndef ADC_H_
#define ADC_H_

//////////////Includes//////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>

///////////////Defines//////////////////////////////////////////////////////////////////////////////
//ADC channel defines
#define POT1	0x01
#define POT2	0x02

//Changes the mux channel while ensuring previous settings remain
#define setAdcChannel(value)	(ADMUX &= 0xE0|(value & 0x1F))

//Retrieve 10bit ADC sample
#define getAdcSample			((ADCH<<8)|ADCL)
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
void adcInit(void);


#endif /* ADC_H_ */