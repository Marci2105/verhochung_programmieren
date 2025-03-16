/******************************************************************************
 * @file CheckSensors.c
 *
 * @author Marcel Schad, Samuel Schwarz
 * @date   16.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Sensor Check Module
 *
 * @details provides functions to check the flow rate and the motor speed
 *
 *
 *****************************************************************************/

/***** INCLUDES **************************************************************/


#include "CheckSensors.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/

#define MIN_FLOWRATE 0u
#define MAX_FLOWRATE 80u

#define MIN_MOTORSPEED 0u
#define MAX_MOTORSPEED 1000u
#define MOTOR_ON 5000u //Can not be reached normally


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/

Data_Status_t checkFlowRate(int currentFlowRate){
	Data_Status_t result = INVALID_DATA;

	if(currentFlowRate>=MIN_FLOWRATE && currentFlowRate<=MAX_FLOWRATE){
		result = VALID_DATA;
	}

	return result;
}

Data_Status_t checkMotorSpeed(int currentMotorSpeed){
	Data_Status_t result = INVALID_DATA;
	if(currentMotorSpeed==MOTOR_ON){
		result = VALID_DATA;
	}
	else if(currentMotorSpeed>=MIN_MOTORSPEED && currentMotorSpeed<=MAX_MOTORSPEED){
			result = VALID_DATA;
		}

	return result;
}

/***** PRIVATE FUNCTIONS *****************************************************/
