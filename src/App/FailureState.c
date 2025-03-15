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


#include "FailureState.h"
#include "LEDModule.h"


/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/

void failureStart(Error_Case_t errorType){

	if(errorType==SENSOR_FAILURE){
		ledSetLED(LED4, LED_ON);
	}

		ledSetLED(LED2, LED_ON);
		ledSetLED(LED0, LED_OFF);


}

/***** PRIVATE FUNCTIONS *****************************************************/
