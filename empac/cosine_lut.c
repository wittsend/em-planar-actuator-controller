/*
* cosine_lut.c
*
* Author : Matthew Witt (pxf5695@autuni.ac.nz)
* Created: 3/08/2017 7:45:13 PM
*
* Project Repository:http://www.atmel.com/images/doc7593.pdf
*
* Contains function for building cosine look up table.
*
* More Info:
* Atmel AT90USB1287 Datasheet:http://www.atmel.com/images/doc7593.pdf
* Relevant reference materials or datasheets if applicable
*
* Functions:
* void buildLut(void)
* uint16_t pwmDcCosDeg(float degrees)
* uint16_t pwmDcCosRad(float radians)
* uint16_t pwmDcCos(int16_t tableElement)
*
*/

//////////////[Includes]////////////////////////////////////////////////////////////////////////////
#include "cosine_lut.h"
#include <math.h>

//////////////[Global Variables]////////////////////////////////////////////////////////////////////
int16_t pwmCosTablePWM[LUT_RESOLUTION];			//Cosine PWM LUT

//////////////[Functions]///////////////////////////////////////////////////////////////////////////
/*
* Function:
* void buildLut(void)
*
* Builds a cosine function look up table in RAM with the number of elements specified by
* 'size'. Maximum value = PWM_TOP, minimum value = -PWM_TOP.
*
* Inputs:
* uint16_t *lutArray:
*   A predefined floating point array where the cosine table will be stored
* uint16_t size:
*   16bit integer giving the size of the look up table.
*
* Returns:
* none
*
* Implementation:
* A for loop counts from 0 to size, populating the lookup table with amplitude shifted cosine
* values. The values range from 0 to PWM_TOP (DC offset)
*
*/
void buildLut(void)
{
	for (uint16_t i = 0; i < LUT_RESOLUTION; i++)
	{
		pwmCosTablePWM[i] = (int16_t)round(PWM_TOP*cos((TWO_PI*i)/(float)LUT_RESOLUTION));
	}
}

/*
* Function:
* uint16_t pwmCosDeg(float degrees)
*
* Returns the cosine function for the given angle in degrees from the look up table.
* Equivalent to y = PWM_TOP*cos(degrees)
*
* Inputs:
* float degrees:
*   Angle in degrees for which to return a value
*
* Returns:
*   Floating point DC offset cosine function value for the given angle (0-1023)
*
* Implementation:
* The angle is checked to make sure it is within range of the LUT, and corrected if necessary.
* The row from the look up table is derived by multiplying the maximum number of table elements
* specified by LUT_RESOLUTION by the ratio of the given angle to 360 degrees.
*
*/
int16_t pwmCosDeg(float degrees)
{
	degrees = fabs(degrees);				//Cosine function is symmetrical, so invert if angle is
	//less than 0.
	while(degrees >= 360.0)					//If table value is out of range, keep subtracting 360
		degrees -= 360.0;					//until its in range.
	while(degrees <= 360.0)					//If table value is out of range, keep subtracting 360
		degrees += 360.0;					//until its in range.
	
	uint16_t tableElement = round(DEG_LUT_CONV*degrees);
	return pwmCosTablePWM[tableElement];
}

/*
* Function:
* uint16_t pwmCosRad(float radians)
*
* Returns the cosine function for the given angle in radians from the look up table.
* Equivalent to y = PWM_TOP*cos(radians)
*
* Inputs:
* float radians:
*   Angle in radians for which to return a value
*
* Returns:
*   Floating point DC offset cosine function value for the given angle (0-1023)
*
* Implementation:
* The angle is checked to make sure it is within range of the LUT, and corrected if necessary.
* The row from the look up table is derived by multiplying the maximum number of table elements
* specified by LUT_RESOLUTION by the ratio of the given angle to 360 degrees.
*
*/
int16_t pwmCosRad(float radians)
{
	radians = fabs(radians);				//Cosine function is symmetrical, so invert if angle is
	//less than 0.
	while(radians >= TWO_PI)					//If table value is out of range, keep subtracting 2pi
		radians -= TWO_PI;					//until its in range.
	while(radians <= TWO_PI)					//If table value is out of range, keep subtracting 2pi
		radians += TWO_PI;					//until its in range.

	uint16_t tableElement = round(RAD_LUT_CONV*radians);
	return pwmCosTablePWM[tableElement];
}

/*
* Function:
* uint16_t pwmCos(int16_t tableElement)
*
* Returns the cosine function for the given look up table element.
* Equivalent to y = PWM_TOP*cos(LUT Element)
*
* Inputs:
* int16_t tableElement:
*   Table row number from which to retrieve a value (Valid values are from 0 to 1023. Number
*   wrapping occurs if an out of range value is passed)
*
* Returns:
*   Floating point cosine function value stored in the given table element
*
* Implementation:
* The element is checked to make sure it is within range of the LUT, and corrected if necessary.
* The cosine value from the look up table is returned.
*
*/
int16_t pwmCos(int16_t tableElement)
{
	uint16_t e = abs(tableElement);			//Cosine function is symmetrical, so invert if angle is
	//less than 0.
	while(e >= LUT_RESOLUTION)				//If table value is out of range, scale it down so its
		e -= LUT_RESOLUTION;				//in range.

	return pwmCosTablePWM[e];
}
