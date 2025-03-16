/******************************************************************************
 * @file FlowRateSensor.c
 *
 * @author Marcel Schad, Samuel Schwarz
 * @date   16.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief flow rate sensor module
 *
 * @details functions to update valid flow rate, to get/set the flow rate and to get the valid flow rate
 *
 *
 *****************************************************************************/

/***** INCLUDES **************************************************************/

#include "FlowRateSensor.h"
#include <stdbool.h>

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/

#define NO_VALIDFLOWRATE_SET		1000u	//Can not be reached by flowRate
#define VALIDFLOWRATE_STEP			5u
#define MIN_VALIDFLOWRATE			0u
#define MAX_VALIDFLOWRATE			80u
#define STEP_SIZE					5
#define MVOLT_TO_FLOW_RATE_TOP		10
#define MVOLT_TO_FLOW_RATE_BOTTOM	250


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/

static int flowRate = 0;
static int validFlowRate = NO_VALIDFLOWRATE_SET;

/***** PUBLIC FUNCTIONS ******************************************************/

void setFlowRate(int adcR2Value){
	int r2ValueMV = adcR2Value * ADC_RES_TO_MVOLT;
	flowRate = ((r2ValueMV - SENSOR_DEFECT_SIGNAL_LOW) * MVOLT_TO_FLOW_RATE_TOP) / MVOLT_TO_FLOW_RATE_BOTTOM;
	flowRate = (flowRate / STEP_SIZE) * STEP_SIZE;
}


int getFlowRate(){
	return flowRate;
}

int getValidFlowRate(){
	return validFlowRate;
}

void increaseValidFlowRate(){
	if(validFlowRate==NO_VALIDFLOWRATE_SET){
		validFlowRate = MIN_VALIDFLOWRATE + VALIDFLOWRATE_STEP;
	}else if(validFlowRate>=MAX_VALIDFLOWRATE){
		validFlowRate = MAX_VALIDFLOWRATE;
	}else{
		validFlowRate += VALIDFLOWRATE_STEP;
	}
}

void decreaseValidFlowRate(){
	if(validFlowRate==NO_VALIDFLOWRATE_SET){
		validFlowRate = MIN_VALIDFLOWRATE;
	}else if(validFlowRate<=MIN_VALIDFLOWRATE){
		validFlowRate = MIN_VALIDFLOWRATE;
	}else{
		validFlowRate -= VALIDFLOWRATE_STEP;
	}
}

/***** PRIVATE FUNCTIONS *****************************************************/
