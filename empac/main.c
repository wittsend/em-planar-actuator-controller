/*
 * 3phase.c
 * 3 Phase DDS with a single timer
 *
 * Created: 27/07/2017 3:22:00 PM
 * Author : Matthew Witt
 */ 

//////////////Includes//////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>
#include <math.h>

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
	DDRE = 0x03;			//Set port E 0,1 for output (mux)
	DDRD = 0x06;			//Set port D 5,6 for output (mux)
	PORTD = 0x00;			//Set mux to 0
	PORTE = 0x00;			//Set mux to 0
	DDRC = 0xFF;			//PORTC for output
	PORTC = 0x00;			//Switch all LEDs off initially
	
	TCCR3A 
	=	(0x02<<COM3A0)		//Clear OC3A on compare match, set on TOP
	|	(0x02<<COM3B0)		//Clear OC3B on compare match, set on TOP
	|	(0x02<<COM3C0)		//Clear OC3C on compare match, set on TOP
	|	(0x03<<WGM30);		//WG mode 7 Fast 10bit PWM
	TCCR3B
	=	(0x01<<WGM32)		//WG mode 7 Fast 10bit PWM
	|	(0x01<<CS30);		//clk/8
	
	OCR3A = 0x003F;			//Initial values for OCR3
	OCR3B = 0x003F;
	OCR3C = 0x003F;
	return;
}