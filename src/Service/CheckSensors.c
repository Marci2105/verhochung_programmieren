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


#include "CheckSensors.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/

#define MIN_FLOWRATE 0u
#define MAX_FLOWRATE 80u

#define MIN_MOTORSPEED 0u
#define MAX_MOTORSPEED 1000u

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

	if(currentMotorSpeed>=MIN_MOTORSPEED && currentMotorSpeed<=MAX_MOTORSPEED){
			result = VALID_DATA;
		}

	return result;
}

/***** PRIVATE FUNCTIONS *****************************************************/
