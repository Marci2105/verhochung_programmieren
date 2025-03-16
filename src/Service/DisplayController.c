/******************************************************************************
 * @file DisplayController.c
 *
 * @author Marcel Schad, Samuel Schwarz
 * @date   16.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief 7 seg display module
 *
 * @details displays a number on the set side
 *
 *
 *****************************************************************************/


/***** INCLUDES **************************************************************/

#include "DisplayController.h"

#include "DisplayModule.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/

typedef enum _Last_Display_t{
	DISPLAY_LEFT,
	DISPLAY_RIGHT
}Last_Display_t;

/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/

void controlDisplay(int leftDisplay, int rightDisplay){
	static Last_Display_t lastDisp = DISPLAY_LEFT;

	if(lastDisp==DISPLAY_LEFT){
		displayShowDigit(RIGHT_DISPLAY, rightDisplay);
		lastDisp = DISPLAY_RIGHT;
	}else{
		displayShowDigit(LEFT_DISPLAY, leftDisplay);
		lastDisp = DISPLAY_LEFT;
	}
}

/***** PRIVATE FUNCTIONS *****************************************************/
