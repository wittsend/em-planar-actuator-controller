/*
 * 3phase.c
 * 3 Phase DDS with a single timer
 *
 * Created: 27/07/2017 3:22:00 PM
 * Author : Matthew Witt
 */ 

//////////////Includes//////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>
#include <stdint.h>			//Gives C99 standard integer definitions

//////////////Functions/////////////////////////////////////////////////////////////////////////////
void setup(void);

int main(void)
{
	setup();
    while(1) 
    {
		for(float angle = 0.0; angle < (2.0*M_PI); angle = angle + 0.001)
		{
			//Would use a LUT for the final product rather than on the fly maths
			//Waveforms are shifted up by 511.5 so the minimum is at 0 and the max is 1023
			OCR3A = (int)(511.5*cos(angle) + 511.5);				//Phase A (0 deg shift)
			OCR3B = (int)(511.5*cos(angle + 2*M_PI/3.0) + 511.5);	//Phase B (120 deg shift)
			OCR3C = (int)(511.5*cos(angle + 4*M_PI/3.0) + 511.5);	//Phase C (240 deg shift)
		}
    }
}

void setup(void)
{


	

	return;
}