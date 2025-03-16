/******************************************************************************
 * @file Potentiometer.c
 *
 * @author Marcel Schad, Samuel Schwarz
 * @date   16.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Potentiometer module
 *
 * @details provides a single init and a get function for each potentiometer
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
#define EMA_FILTER_SCALING			1000
#define EMA_FILTER_ALPHA			200
#define EMA_FILTER_RESET_FILTER		true
#define WMA_FILTER_WINDOW_SIZE		5
/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/

EMAFilterData_t gEMAFilter;
WMAFilterData_t gWMAFilter;


/***** PUBLIC FUNCTIONS ******************************************************/

void potentiometerInit()
{
	filterInitEMA(&gEMAFilter, EMA_FILTER_SCALING, EMA_FILTER_ALPHA, EMA_FILTER_RESET_FILTER);
	filterInitWMA(&gWMAFilter, WMA_FILTER_WINDOW_SIZE);
}

uint32_t getR1Value()
{
	return filterEMA(&gEMAFilter, ADC_INPUT0);
}

uint32_t getR2Value()
{
	return filterWMA(&gWMAFilter, ADC_INPUT1);
}

/***** PRIVATE FUNCTIONS *****************************************************/
