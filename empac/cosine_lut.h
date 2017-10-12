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
* void buildLuts(void)
* void buildDcCosineLutPWM(uint16_t *lutArray, uint16_t size)
* uint16_t pwmDcCosDeg(float degrees)
* uint16_t pwmDcCosRad(float radians)
* uint16_t pwmDcCos(int16_t tableElement)
* uint16_t pwmCosDeg(float degrees)
* uint16_t pwmCosRad(float radians)
* uint16_t pwmCos(int16_t tableElement)
*
*/

#ifndef COSINE_LUT_H_
#define COSINE_LUT_H_

//////////////[Includes]////////////////////////////////////////////////////////////////////////////
#include <math.h>			//for M_PI, cos(), fabs()
//#include <float.h>
#include <stdlib.h>			//for abs() function
#include <stdint.h>			//Gives C99 standard integer definitions

//////////////[Defines]/////////////////////////////////////////////////////////////////////////////
//Number of elements each look up table has. If each value is a 4 byte float then a 1024 element LUT
//should take up 4kb (4 * 1024) which is 50% of the available RAM
#define LUT_RESOLUTION	1024				//10bit look up table
#define PWM_TOP			1023				//PWM top value

//By pre calculating these conversion factors, the program execution ought to speed up.
#define RAD_LUT_CONV	162.974661	//Radians conversion factor: LUT_RESOLUTION/2/PI
#define DEG_LUT_CONV	2.844444	//Degrees conversion factor: LUT_RESOLUTION/360
#define TWO_PI			6.283185
//////////////[Functions]///////////////////////////////////////////////////////////////////////////
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
*/
void buildLuts(void);

/*
* Function:
* void buildCosineLutPWM(uint16_t *lutArray)
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
void buildCosineLutPWM(int16_t *lutArray, uint16_t size);

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
*/
//void buildDcCosineLutPWM(uint16_t *lutArray, uint16_t size);

/*
* Function:
* uint16_t pwmDcCosDeg(float degrees)
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
*/
//uint16_t pwmDcCosDeg(float degrees);

/*
* Function:
* uint16_t pwmDcCosRad(float degrees)
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
*/
//uint16_t pwmDcCosRad(float radians);

/*
* Function:
* uint16_t pwmDcCosRad(float degrees)
*
* Returns the DC offset cosine function for the given angle in radians from the look up table.
* Equivalent to y = 0.5*cos(degrees) + 0.5
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
//uint16_t pwmDcCos(int16_t tableElement);

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
int16_t pwmCosDeg(float degrees);

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
int16_t pwmCosRad(float radians);

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
int16_t pwmCos(int16_t tableElement);


#endif /* COSINE_LUT_H_ */