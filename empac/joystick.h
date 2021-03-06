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
* void joyUpdate(JoystickData2D *jd)
*
*/

#ifndef JOYSTICK_H_
#define JOYSTICK_H_

//////////////[Defines]/////////////////////////////////////////////////////////////////////////////
#define X							0
#define Y							1

///////////////[Type Definitions]///////////////////////////////////////////////////////////////////

//A structure to define a single axis on the joystick
typedef struct JoystickAxis
{
	uint16_t rawMax;			//Maximum raw number from the ADC (1023 on a 10-bit ADC)
	uint16_t rawMin;			//Minimum raw number from the ADC (usually 0)
	uint16_t rawCnt;			//The value from the ADC when the axis is centred (ideally 512)
	uint16_t deadzone;			//The number of ADC LSBs to disregard about the centre point
	uint16_t raw;				//The raw input for this axis from the ADC
	uint8_t adcChannel;			//The ADC mux channel that this axis is on
	float outputMax;			//The maximum output value
	float output;				//The current filtered joystick output
} JoystickAxis;

//Defines a 2 axis joystick.
typedef struct JoystickData2D
{
	const uint8_t numOfAxes;	//Set to 2 when initialised.
	JoystickAxis axis[2];		//2D joystick has two axes, X and Y
} JoystickData2D;

///////////////[Functions]//////////////////////////////////////////////////////////////////////////
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
*/
void joyUpdate(JoystickData2D *jd);

uint8_t joyGetRawData(JoystickData2D *jd);
void joyCalculateOutput(JoystickData2D *jd);

#endif /* JOYSTICK_H_ */