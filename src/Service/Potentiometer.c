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
#include "Potentiometer.h"
#include <stdbool.h>
#include <stdint.h>
#include "Filter/Filter.h"
#include "ADCModule.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/

EMAFilterData_t gEMAFilter;
WMAFilterData_t gWMAFilter;


void potentiometerInit()
{
	filterInitEMA(&gEMAFilter, 1000, 200, true);
	filterInitWMA(&gWMAFilter, 5);
}

uint32_t getR1Value()
{
	return filterEMA(&gEMAFilter, ADC_INPUT0);
}

uint32_t getR2Value()
{
	return filterWMA(&gWMAFilter, ADC_INPUT1);
}

/***** PUBLIC FUNCTIONS ******************************************************/


/***** PRIVATE FUNCTIONS *****************************************************/
