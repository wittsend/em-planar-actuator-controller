/*
* cosine_lut.c
*
* Author : Matthew Witt (wittsend86@gmail.com)
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
* void funcName(void)
*
*/

///////////////Includes/////////////////////////////////////////////////////////////////////////////
#include "cosine_lut.h"

///////////////Functions////////////////////////////////////////////////////////////////////////////
/*
* Function:
* void buildCosineLut(float *lutArray)
*
* Builds a cosine function look up table with the number of elements specified in LUT_RESOLUTION
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
* TODO:[explain key steps of function]
* [use heavy detail for anything complicated]
*
* Improvements:
* [Ideas for improvements that are yet to be made](optional)
*
*/
void buildCosineLut(float *lutArray, uint16_t size)
{
	
}
