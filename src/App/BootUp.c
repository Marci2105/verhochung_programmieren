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

#include "BootUp.h"
#include "CheckSensors.h"
#include "FlowRateSensor.h"
#include "SpeedSensor.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/

Error_BootUp_t bootUpStart(){
	Error_BootUp_t error = NO_ERROR;
	int motorSpeed = getMotorSpeed();
	int flowRate = getFlowRate();


	 if(checkMotorSpeed(motorSpeed)==INVALID_DATA || checkFlowRate(flowRate)==INVALID_DATA){
	    	error = ERROR_SENSOR_BOOTUP;
	 }

	return error;
}


/***** PRIVATE FUNCTIONS *****************************************************/
