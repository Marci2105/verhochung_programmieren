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

#include "FlowRateSensor.h"
#include <stdbool.h>

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/

#define NO_VALIDFLOWRATE_SET 1000u	//Can not be reached by flowRate

/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/

static int flowRate = 0;
static int validFlowRate = NO_VALIDFLOWRATE_SET;

/***** PUBLIC FUNCTIONS ******************************************************/

void setFlowRate(int FlowRate){
	flowRate = FlowRate;
}

int getFlowRate(){
	return flowRate;
}

int getValidFlowRate(){
	return validFlowRate;
}

void setValidFlowRate(int targetFlowRate){
	validFlowRate = targetFlowRate;
}

/***** PRIVATE FUNCTIONS *****************************************************/
