/*
* timer.h
*
* Author : Matthew Witt
* Created: 6/08/2017 1:23:27 PM
*
* Project Repository:https://github.com/AdamParlane/aut-swarm-robotics
*
* Sets up the timer for 1ms interrupts
* Has delay and get ms functions and the timer handler interrupt
*
* More Info:
* Atmel SAM 4N Processor Datasheet:http://www.atmel.com/Images/Atmel-11158-32-bit%20Cortex-M4-Microcontroller-SAM4N16-SAM4N8_Datasheet.pdf
*
* Functions:
* void timer2Init(void)
* ISR(TIMER0_COMPA_vect)
*
*/

//////////////[Includes]////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>
#include <avr/interrupt.h>

#include "timer.h"

//////////////[Defines]/////////////////////////////////////////////////////////////////////////////
#define TIMER0_COMPA	0x00	//Normal
#define TIMER0_COMPB	0x00	//Normal
#define TIMER0_COMPC	0x00	//Normal
#define TIMER0_FOCA		0x00
#define TIMER0_FOCB		0x00
#define TIMER0_WGM		0x02	//Mode 2 CTC
#define TIMER0_CLKSEL	0x04	//div by 64
#define TIMER0_OCR0A	125		//Compare every 125 counts (1ms)
#define TIMER0_OCR0B	0x00
#define TIMER0_OCAIE	0x01	//Output compare interrupt enabled
#define TIMER0_OCBIE	0x00
#define TIMER0_OVIE		0x00

///////////////Global Vars//////////////////////////////////////////////////////////////////////////
uint32_t systemTimestamp = 0;

//////////////[Functions]///////////////////////////////////////////////////////////////////////////
/*
* Function:
* void timer2Init(void)
*
* Initializes timer0
*
* Inputs:
* none
*
* Returns:
* none
*
* Implementation:
* See above for timer2 bit field settings
*
*/
void timer2Init(void)
{
	TCCR0A
	=	((TIMER0_COMPA & 0x03) << 6)
	|	((TIMER0_COMPB & 0x03) << 4)
	|	((TIMER0_WGM & 0x03) << 0);
	
	TCCR0B
	=	((TIMER0_FOCA & 0x01) << 7)
	|	((TIMER0_FOCB & 0x01) << 6)
	|	((TIMER0_WGM & 0x04) << 1)
	|	((TIMER0_CLKSEL & 0x07) << 0);
	
	//TIMSK2 = 0x02;
	TIMSK0
	=	((TIMER0_OCBIE & 0x01) << 2)
	|	((TIMER0_OCAIE & 0x01) << 1)
	|	((TIMER0_OVIE & 0x01) << 0);

	OCR0A = TIMER0_OCR0A;
	OCR0B = TIMER0_OCR0B;
}

/*
* Function:
* ISR(TIMER0_COMPA_vect)
*
* Timer 2 output compare A interrupt
*
* Inputs:
* none
*
* Returns:
* none
*
* Implementation:
* Increments systemTimestamp for timing applications
*
*/
ISR(TIMER0_COMPA_vect)
{
	systemTimestamp++;
}

