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
* void buildLuts(void)
* void buildDcCosineLut(float *lutArray, uint16_t size)
* uint16_t dcCosDeg(float degrees)
* uint16_t dcCosRad(float radians)
* uint16_t dcCos(int16_t tableElement)
*
*/

///////////////Includes/////////////////////////////////////////////////////////////////////////////
#include "cosine_lut.h"

///////////////Global Variables/////////////////////////////////////////////////////////////////////
static uint16_t dcCosTablePWM[LUT_RESOLUTION];	//DC offset cosine PWM LUT

///////////////Functions////////////////////////////////////////////////////////////////////////////
/*
* Function:
* void initLut(void)
*
* Builds cosine lookup tables and stores them in RAM
*
* Inputs:
* none
*
* Returns:
* none
*
* Implementation:
* buildDcCosineLut() will build a DC offset cosine table with values between 0 and 1 at a resolution
* specified in LUT_RESOLUTION.
* 
*/
void buildLuts(void)
{
	buildDcCosineLutPWM(dcCosTablePWM, LUT_RESOLUTION);
}

/*
* Function:
* void buildDcCosineLutPWM(uint16_t *lutArray)
*
* Builds a DC offset cosine function look up table in RAM with the number of elements specified by
* 'size'. Maximum value = PWM_TOP, minimum value = 0. 
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
void buildDcCosineLutPWM(uint16_t *lutArray, uint16_t size)
{
	for (uint16_t i = 0; i < size; i++)
	{
		lutArray[i] = round(PWM_TOP/2*cos(TWO_PI*i/size) + PWM_TOP/2);
	}
}


uint16_t dcCosDeg(float degrees)
{
	degrees = fabs(degrees);				//Cosine function is symmetrical, so invert if angle is
											//less than 0.
	while(degrees > 360.0)					//If table value is out of range, keep subtracting 360
											//until its in range.
	{
		degrees -= 360.0;
	}
	uint16_t tableElement = round(DEG_LUT_CONV*degrees);
	return dcCosTablePWM[tableElement];
}

/*
* Function:
* uint16_t dcCosRad(float radians)
*
* Returns the DC offset cosine function for the given angle in radians from the look up table.
* Equivalent to y = PWM_TOP*0.5*cos(degrees) + PWM_TOP*0.5
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
uint16_t dcCosRad(float radians)
{
	radians = fabs(radians);				//Cosine function is symmetrical, so invert if angle is
											//less than 0.
	while(radians > TWO_PI)					//If table value is out of range, keep subtracting 2pi
											//until its in range.
	{
		radians -= TWO_PI;
	}
	uint16_t tableElement = round(RAD_LUT_CONV*radians);
	return dcCosTablePWM[tableElement];	
}

/*
* Function:
* uint16_t dcCosRad(float degrees)
*
* Returns the DC offset cosine function for the given angle in radians from the look up table.
* Equivalent to y = PWM_TOP*0.5*cos(degrees) + PWM_TOP*0.5
*
* Inputs:
* int16_t tableElement:
*   Table row number from which to retrieve a value
*
* Returns:
*   Floating point cosine function value stored in the given table element
*
* Implementation:
* The element is checked to make sure it is within range of the LUT, and corrected if necessary.
* The cosine value from the look up table is returned.
*
*/
uint16_t dcCos(int16_t tableElement)
{
	uint16_t e = abs(tableElement);		//Cosine function is symmetrical, so invert if angle is
											//less than 0.
	while(e > LUT_RESOLUTION)	//If table value is out of range, scale it down so its
											//in range.
	{
		e -= LUT_RESOLUTION;
	}
	return dcCosTablePWM[e];
}

