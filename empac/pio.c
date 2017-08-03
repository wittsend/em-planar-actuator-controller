/*
 * pio.c
 *
 * Created: 3/08/2017 7:31:46 PM
 *  Author: Fiona
 */ 

void pioInit(void)
{
//Lab board IO mux control.
#if defined TARGET_LAB_BOARD
	DDRE = 0x03;			//Set port E 0,1 for output (mux)
	DDRD = 0x06;			//Set port D 5,6 for output (mux)
	PORTD = 0x00;			//Set mux to 0
	PORTE = 0x00;			//Set mux to 0
#endif

	DDRC = 0xFF;			//PORTC for output
	PORTC = 0x00;			//Switch all LEDs off initially
}