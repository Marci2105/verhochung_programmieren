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
#ifndef _FLOWRATESENSOR_H
#define _FLOWRATESENSOR_H

#define SENSOR_DEFECT_SIGNAL_LOW		500			//!< 500mV scaled to the ADC resolution
#define SENSOR_DEFECT_SIGNAL_HIGH		2500		//!< 2500mV scaled to the ADC resolution
#define ADC_RES_TO_MVOLT				3300/4096
/***** INCLUDES **************************************************************/

#include <stdbool.h>

/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/


/***** PROTOTYPES ************************************************************/

void setFlowRate(int targetFlowRate);

int getFlowRate();

int getValidFlowRate();

void increaseValidFlowRate();

void decreaseValidFlowRate();


#endif
