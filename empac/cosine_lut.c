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
* void buildDcCosineLut(float *lutArray, uint16_t size)
*
*/

///////////////Includes/////////////////////////////////////////////////////////////////////////////
#include "cosine_lut.h"

///////////////Global Variables/////////////////////////////////////////////////////////////////////
float dcCosTable[LUT_RESOLUTION];		//DC offset cosine function table (0-1)

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
	buildDcCosineLut(dcCosTable, LUT_RESOLUTION);
}

/*
* Function:
* void buildDcCosineLut(float *lutArray)
*
* Builds a DC offset cosine function look up table in RAM with the number of elements specified by
* 'size'. Maximum value = 1, minimum value = 0. 
*
* Inputs:
* float *lutArray:
*   A predefined floating point array where the cosine table will be stored
* uint16_t size:
*   16bit integer giving the size of the look up table.
*
* Returns:
* none
*
* Implementation:
* A for loop counts from 0 to size, populating the lookup table with amplitude shifted cosine
* values. The values range from 0 to 1 (DC offset) 
*
*/
void buildDcCosineLut(float *lutArray, uint16_t size)
{
	for (uint16_t i = 0; i < size; i++)
	{
		lutArray[i] = 0.5*cos(2*i*M_PI/size) + 0.5;
	}
}

/*
* Function:
* float dcCosDeg(float degrees)
*
* Returns the DC offset cosine function for the given angle in degrees from the look up table.
* Equivalent to y = 0.5*cos(degrees) + 0.5
*
* Inputs:
* float degrees:
*   Angle in degrees for which to return a value
*
* Returns:
*   Floating point cosine function value for the given angle
*
* Implementation:
* The angle is checked to make sure it is within range of the LUT, and corrected if neccesary.
* The row from the look up table is derived by multiplying the maximum number of table elements
* specified by LUT_RESOLUTION by the ratio of the given angle to 360 degrees.
*
*/
float dcCosDeg(float degrees)
{
	if (degrees > 360.0)
		degrees = 360.0;
	if (degrees < 0.0)
		degrees = 0.0;
	uint16_t tableElement = round(LUT_RESOLUTION*degrees/360.0);
	return dcCosTable[tableElement];
}

/*
* Function:
* float dcCosRad(float degrees)
*
* Returns the DC offset cosine function for the given angle in radians from the look up table.
* Equivalent to y = 0.5*cos(degrees) + 0.5
*
* Inputs:
* float degrees:
*   Angle in degrees for which to return a value
*
* Returns:
*   Floating point cosine function value for the given angle
*
* Implementation:
* The angle is checked to make sure it is within range of the LUT, and corrected if neccesary.
* The row from the look up table is derived by multiplying the maximum number of table elements
* specified by LUT_RESOLUTION by the ratio of the given angle to 360 degrees.
*
*/
float dcCosRad(float radians)
{
	if (radians > 2*M_PI)
		radians = 2*M_PI;
	if (radians < 0.0)
		radians = 0.0;
	uint16_t tableElement = round(LUT_RESOLUTION*radians/2/M_PI);
	return dcCosTable[tableElement];	
}