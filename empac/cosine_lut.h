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
* void buildCosineLut(float *lutArray)
*
*/

#ifndef COSINE_LUT_H_
#define COSINE_LUT_H_

///////////////Includes/////////////////////////////////////////////////////////////////////////////
#include <math.h>

///////////////Defines//////////////////////////////////////////////////////////////////////////////
//Number of elements each look up table has
#define LUT_RESOLUTION	1024

///////////////Functions////////////////////////////////////////////////////////////////////////////

void buildCosineLut(float *lutArray);

#endif /* COSINE_LUT_H_ */