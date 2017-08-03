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

///////////////Functions////////////////////////////////////////////////////////////////////////////
/*
* Function:
* void buildCosineLut(float *lutArray)
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
* Improvements:
* [Ideas for improvements that are yet to be made](optional)
*
*/
void buildDcCosineLut(float *lutArray, uint16_t size)
{
	for (uint16_t i = 0; i < size; i++)
	{
		lutArray[i] = 0.5*cos(2*i*M_PI/size) + 0.5;
	}
}
