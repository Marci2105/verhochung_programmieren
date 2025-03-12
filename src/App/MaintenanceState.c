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

#include <stdbool.h>

#include "MaintenanceState.h"
#include "SpeedSensor.h"
#include "FlowRateSensor.h"
#include "AppTasks.h"
#include "LEDModule.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/

#define NO_VALIDFLOWRATE_SET 1000u	//Can not be reached by flowRate


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/

void maintenanceStart(){

}


void maintenanceRunning(){

	ledToggleLED(LED0);

	if(getValidFlowRate()==NO_VALIDFLOWRATE_SET){

		//Anzeige auf 7 segment display "--"
	}


	// Check Button SW1 and SW2
	    if (getButtonSW1State() == BUTTON_PRESSED) {
	    	increaseValidFlowRate();
	    } else if (getButtonSW2State() == BUTTON_PRESSED) {
	    	decreaseValidFlowRate();
	    }
}

/***** PRIVATE FUNCTIONS *****************************************************/
