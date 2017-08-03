/*
 * pwm.c
 *
 * Created: 3/08/2017 7:30:31 PM
 *  Author: Fiona
 */ 

void timerInit(void)
{	
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
}