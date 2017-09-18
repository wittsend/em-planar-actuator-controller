/*
* joystick.h
*
* Author : Matthew Witt (pxf5695@autuni.ac.nz)
* Created: 18/09/2017 3:14:02 PM
*
* Project Repository:https://github.com/wittsend/em-planar-actuator-controller
*
* Header file for joystick.c
*
* More Info:
* Atmel AT90USB1287 Datasheet:http://www.atmel.com/images/doc7593.pdf
* Relevant reference materials or datasheets if applicable
*
* Functions:
* void funcName(void)
*
*/

#ifndef JOYSTICK_H_
#define JOYSTICK_H_

//////////////[Defines]/////////////////////////////////////////////////////////////////////////////
#define JOYSTICK_LUT_SIZE			1024

///////////////[Type Definitions]///////////////////////////////////////////////////////////////////
typedef struct JoystickData
{
	uint16_t rawMaxX;
	uint16_t rawMinX;
	uint16_t rawCntX;
	uint16_t deadzoneX;

	uint16_t rawMaxY;
	uint16_t rawMinY;
	uint16_t rawCntY;
	uint16_t deadzoneY;
	
	uint16_t rawX;
	uint16_t rawY;
	
	uint16_t outputResolution;
	uint16_t outputX[JOYSTICK_LUT_SIZE];
	uint16_t outputY[JOYSTICK_LUT_SIZE];
	
	uint8_t adcChannelX;
	uint8_t adcChannelY;
	
} JoystickData;

///////////////[Functions]//////////////////////////////////////////////////////////////////////////
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






#endif /* JOYSTICK_H_ */