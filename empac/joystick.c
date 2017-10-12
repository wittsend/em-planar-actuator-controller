/*
* joystick.c
*
* Author : Matthew Witt (pxf5695@autuni.ac.nz)
* Created: 18/09/2017 3:13:48 PM
*
* Project Repository:https://github.com/wittsend/em-planar-actuator-controller
*
* Joystick driver software
*
* More Info:
* Atmel AT90USB1287 Datasheet:http://www.atmel.com/images/doc7593.pdf
* Relevant reference materials or datasheets if applicable
*
* Functions:
* void joyUpdate(JoystickData2D *jd)
* static uint8_t joyGetRawData(JoystickData2D *jd)
* static void joyCalculateOutput(JoystickData2D *jd)
*
*/
///////////////Includes/////////////////////////////////////////////////////////////////////////////
#include <stdlib.h>		//Used for abs()

#include "adc.h"
#include "joystick.h"

//////////////[Private functions]///////////////////////////////////////////////////////////////////


//////////////[Functions]///////////////////////////////////////////////////////////////////////////
/*
* Function:
* void joyUpdate(JoystickData2D *jd)
*
* This function is used to poll the ADC for new joystick data.
*
* Inputs:
* JoystickData2D *jd:
*   Pointer to a JoystickData2D object that will be polled.
*
* Returns:
* none
*
* Implementation:
* First, check if there is any new data from the ADC. If there is, then calculate fresh output
* data from the raw input.
*
*/
void joyUpdate(JoystickData2D *jd)
{
	if(joyGetRawData(jd))		//If get raw adc data, and if new data retrieved
	{
		joyCalculateOutput(jd);	//Calculate output from raw data
	}
}

/*
* Function:
* uint8_t joyGetRawData(JoystickData2D *jd)
*
* If new ADC data has been sampled, then retrieve it and load it into the given JoystickData2D
* object
*
* Inputs:
* JoystickData2D *jd:
*   Pointer to the Joystick object that will have ADC data retrieved for it.
*
* Returns:
* 1 if new data was retrieved, otherwise 0
*
* Implementation:
* First, check if the ADC has been updated. Next, start a for loop to update each axis in the
* given Joystick object. Finally retrieve the raw ADC data from the ADC interface and store it in
* the given Joystick object.
*
*/
uint8_t joyGetRawData(JoystickData2D *jd)
{
	if(adcNewData())	//Check if new data is available from the ADC
	{
		//Retrieve raw data from ADC for each axis in jd
		for(uint8_t thisAxis = 0; thisAxis < jd->numOfAxes; thisAxis++)
			jd->axis[thisAxis].raw = adcGetData(jd->axis[thisAxis].adcChannel);
		return 1;		//Return 1 if new data was retrieved
	}
	return 0;			//Otherwise return 0
}

/*
* Function:
* void joyCalculateOutput(JoystickData2D *jd)
*
* Calculates a signed output from the raw ADC data for each axis on the joystick, with deadzone
* applied to it.
*
* Inputs:
* JoystickData2D *jd:
*   The pointer to the Joystick object to calculate output data for
*
* Returns:
* none
*
* Implementation:
* int32_t offCentre stores a signed version of the raw data and is used to determine if the axis is 
* outside of the deadzone.
* - The function starts a for loop that will perform the same calculation for each axis on the
* joystick.
* - Next, the off centre value is calculated. This is a signed value that represents how far from
* centre the current axis is.
* - If the off centre value is within our set deadzone for the current axis, then output for the 
* current axis becomes 0. Otherwise, we remove the deadzone from the off centre value and calculate
* the scaled output.
*
*/
void joyCalculateOutput(JoystickData2D *jd)
{
	int32_t offCentre;
	//Retrieve raw data from ADC for each axis in jd
	for(uint8_t thisAxis = 0; thisAxis < jd->numOfAxes; thisAxis++)
	{
		//Calculate how far off centre the axis is
		offCentre = (int16_t)jd->axis[thisAxis].raw - (int16_t)jd->axis[thisAxis].rawCnt;
		
		//If the axis is within the deadzone (+/- jd.axis[x].deadzone), then we just output a 0
		if(abs(offCentre) > jd->axis[thisAxis].deadzone)
		{
			if(offCentre > 0)
				//Subtract deadzone from off centre value
				offCentre -= (int16_t)jd->axis[thisAxis].deadzone;
			else
				//Add the deadzone to off centre value
				offCentre += (int16_t)jd->axis[thisAxis].deadzone;

			//Calculate the axis output
			jd->axis[thisAxis].output 
			=	(int16_t)((offCentre*jd->axis[thisAxis].outputMax)
			/	(jd->axis[thisAxis].rawMax
			-	jd->axis[thisAxis].rawCnt
			-	jd->axis[thisAxis].deadzone));
		} else {
			jd->axis[thisAxis].output = 0;
		}
	}
	return;
}