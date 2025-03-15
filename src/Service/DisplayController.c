/******************************************************************************
 * @file <Filename>.h
 *
 * @author <Author>
 * @date   <Date>
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief <Some short descrition>
 *
 * @details <A more detailed description>
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
