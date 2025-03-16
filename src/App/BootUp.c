/******************************************************************************
 * @file BootUp.c
 *
 * @author Marcel Schad, Samuel Schwarz
 * @date   16.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief implements the Boot Up State
 *
 * @details provides a Boot Up running and start function
 *
 *
 *****************************************************************************/


/***** INCLUDES **************************************************************/

#include "BootUp.h"
#include "CheckSensors.h"
#include "FlowRateSensor.h"
#include "SpeedSensor.h"
#include "SerialOutputController.h"
#include "StackMonitor.h"


/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/
#define STACK_NOT_VALID 0u

/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/

Error_BootUp_t bootUpStart(){
	uartSendString("boot up state\r\n");
	Error_BootUp_t error = NO_ERROR;
	int motorSpeed = getMotorSpeed();
	int flowRate = getFlowRate();


	 if(checkMotorSpeed(motorSpeed)==INVALID_DATA || checkFlowRate(flowRate)==INVALID_DATA){
	    	error = ERROR_SENSOR_BOOTUP;
	 }


	return error;
}


/***** PRIVATE FUNCTIONS *****************************************************/
