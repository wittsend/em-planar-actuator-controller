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
* void adcInit(void)
* uint8_t adcNewData(void)
* uint16_t adcGetData(uint8_t channel)
*
*/

#ifndef ADC_H_
#define ADC_H_

///////////////Defines//////////////////////////////////////////////////////////////////////////////
//ADC channel defines
#define ADC_CH_POT1	0x01
#define ADC_CH_POT2	0x02

#define ADC_CH_JOYSTICK_X	0x01
#define ADC_CH_JOYSTICK_Y	0x02

//Number of ADC channels available
#define ADC_CHANNELS	8

//Changes the mux channel while ensuring previous settings remain
#define adcSetChannel(value)	(ADMUX = (ADMUX&0xE0)|value)

//Retrieve 10bit ADC sample
#define adcGetSample			((ADCH<<8)|ADCL)

//Start Conversion
#define adcStartConv			(ADCSRA |= (1<<ADSC))

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
*/
uint8_t adcNewData(void);

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
*/
uint16_t adcGetData(uint8_t channel);

#endif /* ADC_H_ */