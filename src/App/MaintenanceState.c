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

#define DISPLAY_DASH 16u
#define DISPLAY_LOWER_O 18u
#define DISPLAY_OFF 19u

#define FACTOR_TEN 10u

#define MOTOR_OFF 0u

/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/

void maintenanceStart(){
	setMotorSpeed(MOTOR_OFF);
	ledSetLED(LED3, LED_OFF);
}


void maintenanceRunning(){

	ledToggleLED(LED0);

	if(getValidFlowRate()==NO_VALIDFLOWRATE_SET){
		setDisplay(DISPLAY_DASH, DISPLAY_DASH);
	}else{
		int left = getValidFlowRate()/FACTOR_TEN;
		int right = getValidFlowRate()%FACTOR_TEN;
		setDisplay(left, right);
	}


	// Check Button SW1 and SW2
	    if (getButtonSW1State() == BUTTON_PRESSED) {
	    	increaseValidFlowRate();
	    } else if (getButtonSW2State() == BUTTON_PRESSED) {
	    	decreaseValidFlowRate();
	    }
}

/***** PRIVATE FUNCTIONS *****************************************************/
