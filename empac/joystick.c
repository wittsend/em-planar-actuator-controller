/*
* filename.c/h
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
* void funcName(void)
*
*/
///////////////Includes/////////////////////////////////////////////////////////////////////////////
#include "adc.h"
#include "joystick.h"

//////////////[Global Variables]////////////////////////////////////////////////////////////////////


///////////////Functions////////////////////////////////////////////////////////////////////////////
/*
* Function:
* [function declaration]
*
* [brief purpose of function]
*
* Inputs:
* [input arguments and any relevant explanation]
*
* Returns:
* [return values and any relevant explanation]
*
* Implementation:
* [explain key steps of function]
* [use heavy detail for anything complicated]
*
* Improvements:
* [Ideas for improvements that are yet to be made](optional)
*
*/
void joyUpdate(JoystickData *jd)
{
	jd->rawX = adcGetData(jd->adcChannelX);
	jd->rawY = adcGetData(jd->adcChannelY);
}

void joyCalcLUTs(void)
{
	
}