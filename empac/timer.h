/*
* timer.h
*
* Author : Matthew Witt
* Created: 6/08/2017 1:23:27 PM
*
* Project Repository:https://github.com/AdamParlane/aut-swarm-robotics
*
* Sets up the timer, for 1ms interrupts
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
 
#ifndef TIMER_H_
#define TIMER_H_

///////////////Global Vars//////////////////////////////////////////////////////////////////////////
extern uint32_t systemTimestamp;

//////////////[Functions]///////////////////////////////////////////////////////////////////////////
/*
* Function:
* void timer2Init(void)
*
* Initializes timer0
* Used to time events with a 1ms interrupt on RC compare match
* Sets timr0 CLK speed to 12.5MHz for camera
*
* Inputs:
* none
*
* Returns:
* none
*
*/
void timer2Init(void);


#endif /* TIMER_H_ */