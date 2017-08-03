/*
* cosine_lut.h
*
* Author : Matthew Witt (pxf5695@autuni.ac.nz)
* Created: 3/08/2017 7:45:38 PM
*
* Project Repository:http://www.atmel.com/images/doc7593.pdf
*
* Contains settings and defines for cosine look up table, as well as function prototypes.
*
* More Info:
* Atmel AT90USB1287 Datasheet:http://www.atmel.com/images/doc7593.pdf
* Relevant reference materials or datasheets if applicable
*
* Functions:
* void buildDcCosineLut(float *lutArray, uint16_t size)
*
*/

#ifndef COSINE_LUT_H_
#define COSINE_LUT_H_

///////////////Includes/////////////////////////////////////////////////////////////////////////////
#include <math.h>
#include <stdint.h>

///////////////Defines//////////////////////////////////////////////////////////////////////////////
//Number of elements each look up table has. If each value is a 4 byte float then a 1024 element LUT
//should take up 4kb (4 * 1024)
#define LUT_RESOLUTION	1024

///////////////Functions////////////////////////////////////////////////////////////////////////////
/*
* Function:
* void buildCosineLut(float *lutArray)
*
* Builds a DC offset cosine function look up table in RAM with the number of elements specified by
* 'size'. Maximum value = 1, minimum value = 0
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
*/
void buildDcCosineLut(float *lutArray, uint16_t size);

#endif /* COSINE_LUT_H_ */