/*
* formatting.c
*
* Author : Matthew Witt (wittsend86@gmail.com)
* Created: 03/08/2017
* 
* Project Repository:https://github.com/wittsend/em-planar-actuator-controller
*
* The code format should be as below,
* Excessive commenting and documentations is encouraged.
* Also Note the Max line width should be 100 character. Exception to this rule is URLs
*
* Functions: 
* int functionName(char paramOne, int paramTwo, unsigned int paramThree)
* void registerAccess(void)
*
*/ 

/*
* filename.c/h
*
* Author : name (email)
* Created: time date
* 
* Project Repository:https://github.com/wittsend/em-planar-actuator-controller
*
* 1 or 2 liner on the purpose of the file
*
* More Info:
* Atmel AT90USB1287 Datasheet:http://www.atmel.com/images/doc7593.pdf
* Relevant reference materials or datasheets if applicable
*
* Functions:
* void funcName(void)
*
*/ 
//^^Template file header


/*
* Function: 
* [function declaration]
*
* [brief purpose of function]
*
* Inputs:
* [input arguments and any relevant explanation]
*
* Returns:
* [return values and any relevant explanation]
*
* Implementation:
* [explain key steps of function]
* [use heavy detail for anything complicated]
*
* Improvements:
* [Ideas for improvements that are yet to be made](optional)
*
*/
//^^Template c file function header

//^^H file function header will be the same without the implementation/improvement section

///////////////Includes/////////////////////////////////////////////////////////////////////////////

#include <libHeader1>

///////////////Defines//////////////////////////////////////////////////////////////////////////////

//Tabs keep values in line and easy to read
#define macroOne	(REG_PIOB_CODR |= (1<<12))	//Macros camelCase because they are executing code
#define macroTwo	(REG_PIOB_SODR |= (1<<12))
//Constant values should be decimal or hex form. Not binary.
//Values can be converted with programmer mode in windows calculator quite easily.
#define CONST_ONE	0x00			//Constants use CAPS_UNDERSCORE_SPACE_FORMAT

///////////////Functions////////////////////////////////////////////////////////////////////////////

/*
* Function: 
* int functionName(char paramOne, int paramTwo, unsigned int paramThree)
*
* Details code style for robot C code. Function names in camelCase.
*
* Inputs:
* paramOne does this, paramTwo does that and paramThree does the other.
*
* Returns:
* always returns 1
*
* Implementation:
* States variable definitions, and switch statement structure.
*
* Improvements:
* no doubt there will be. Hit us up (Adam or Matt)
*/
int functionName(char paramOne, int paramTwo, unsigned int paramThree)
{
	//Single spacing. Every variable should have its own definition. Variable names use camelCase.
	unsigned char varOne = 1;
	int	varTwo = 0;
	unsigned int varThree = 100;
	
	//Switch statement example
	switch state
	{
		case 1
			//Code here
			break:
			
		case 2
			//Code here
			break;
	}
	
	return varOne;
}

/*
* Function: 
* void registerAccess(void)
*
* Format for writing to registers. Use macros where ever possible to increase 
* readability
*
* Inputs:
* none
*
* Returns:
* none
*
* Implementation:
* Outlines code structure for manipulating system registers with macros
*
* Improvements:
* no doubt there will be. Hit us up (Adam or Matt)
*/
void registerAccess(void)

{

	//Register names begin with REG. The second part is the peripheral and the third is the name	
	//of the specific register being accessed (separated by underscores).
	//Register name is on the first line, then subsequent bitfields being set are on following lines.	
	//Tabs are used to space things out evenly to keep them neat and readable.	
	REG_PMC_PCER0
	
	|=	(1<<ID_TWI1);					//Sometimes there isn't a macro for a bit field

	//Bit field macros are as follows: The first part of the name is the peripheral catergory.
	//The second part is the register name, and the last part is the bitfield within that register.
	REG_TWI1_CWGR
	|=	TWI_CWGR_CLDIV(126)				//Atmel studio has macros that allow numbers to be written
	|	TWI_CWGR_CHDIV(56)				//to specific bitfields within registers
	|	TWI_CWGR_CKDIV(0);
	
	REG_TWI1_CR 
	=	TWI_CR_MSEN					//These will turn specific bits on and off
	|	TWI_CR_SVDIS;
	
								//Inline comments kept straight in a row with tabs
								//By keeping them in line they become easier to read
}
