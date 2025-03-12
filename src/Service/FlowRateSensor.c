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
#include "ADCModule.h"
#include "Filter/Filter.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/

#define NO_VALIDFLOWRATE_SET 1000u	//Can not be reached by flowRate
#define VALIDFLOWRATE_STEP 5u
#define MIN_VALIDFLOWRATE 0u
#define MAX_VALIDFLOWRATE 80u

/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/

static int flowRate = 0;
static int validFlowRate = NO_VALIDFLOWRATE_SET;

/***** PUBLIC FUNCTIONS ******************************************************/

void setFlowRate(int adcR2Value){
	uint32_t r2ValueMV = adcR2Value * ADC_RES_TO_MVOLT;

	if (adcR2Value < SENSOR_DEFECT_SIGNAL_LOW || adcR2Value > SENSOR_DEFECT_SIGNAL_HIGH)
		flowRate = 0; //error

	flowRate = ((r2ValueMV - SENSOR_DEFECT_SIGNAL_LOW) * 10) / 250;
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
