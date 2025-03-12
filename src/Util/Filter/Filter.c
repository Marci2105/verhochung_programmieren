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
#include "Filter.h"

#include <stdbool.h>
#include <stdint.h>

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/
int32_t filterInitEMA(EMAFilterData_t* pEMA, int32_t scalingFactor, int32_t alpha, bool resetFilter)
{
	if (pEMA == 0)
		return FILTER_ERR_INVALID_PTR;

	if (alpha <= ALPHA_MIN_VALUE)
		return FILTER_ERR_INVALID_PARAM;

	if (scalingFactor <= SCALING_FACTOR_MIN_VALUE)
		return FILTER_ERR_INVALID_PARAM;

	pEMA->scalingFactor = scalingFactor;
	pEMA->alpha = alpha;

	if (resetFilter == true)
	{
		pEMA->firstValueAvailable = false;
		pEMA->previousValue = 0;
	}

	return FILTER_ERR_OK;
}

int32_t filterResetEMA(EMAFilterData_t* pEMA)
{
	if (pEMA == 0)
		return FILTER_ERR_INVALID_PTR;

	pEMA->firstValueAvailable = false;
	pEMA->previousValue = 0;

	return FILTER_ERR_OK;
}

int32_t filterEMA(EMAFilterData_t* pEMA, int32_t sensorValue)
{
	if (pEMA == 0)
		return FILTER_ERR_INVALID_PTR;

	if (sensorValue < ADC_MIN_VALUE || sensorValue > ADC_MAX_VALUE)
		return FILTER_ERR_GENERAL;

	if (pEMA->firstValueAvailable == false)
	{
		pEMA->previousValue = sensorValue * pEMA->scalingFactor;
		pEMA->firstValueAvailable = true;
	} else {
		pEMA->previousValue = (pEMA->alpha * sensorValue + (pEMA->scalingFactor - pEMA->alpha) * pEMA->previousValue) / pEMA->scalingFactor;
	}

	return pEMA->previousValue / pEMA->scalingFactor;
}

int32_t filterInitWMA(WMAFilterData_t* pWMA, uint32_t windowSize)
{
	if (pWMA == 0)
		return FILTER_ERR_INVALID_PTR;

	if (windowSize <= 0)
		return FILTER_ERR_INVALID_PARAM;

	// set the window size
	if (windowSize > WINDOW_SIZE)
	{
		pWMA->windowSize = WINDOW_SIZE;
	} else {
		pWMA->windowSize = windowSize;
	}

    pWMA->index = 0;
    pWMA->sum = 0;
    pWMA->filled = false;

    // initialize buffer with 0
    for (uint32_t i = 0; i < WINDOW_SIZE; i++) {
        pWMA->buffer[i] = 0;
    }

	return FILTER_ERR_OK;
}

int32_t filterResetWMA(WMAFilterData_t* pWMA)
{
	if (pWMA == 0)
		return FILTER_ERR_INVALID_PTR;

	// set all values in buffer to 0
    for (uint32_t i = 0; i < WINDOW_SIZE; i++) {
        pWMA->buffer[i] = 0;
    }

    // clear all WMA values
    pWMA->index = 0;
    pWMA->sum = 0;
    pWMA->filled = false;

    return FILTER_ERR_OK;
}

int32_t filterWMA(WMAFilterData_t* pWMA, int32_t sensorValue)
{
	uint32_t avg = 0;

	if (pWMA == 0)
		return FILTER_ERR_INVALID_PTR;

	if (sensorValue < ADC_MIN_VALUE || sensorValue > ADC_MAX_VALUE)
		return FILTER_ERR_GENERAL;

	if (pWMA->filled == true)
	{
		pWMA->sum -= pWMA->buffer[pWMA->index];
	}

	//adjust the buffer and the sum for the new sensor value
	pWMA->buffer[pWMA->index] = sensorValue;
	pWMA->sum += sensorValue;

	//adjust index
	pWMA->index = (pWMA->index + 1) % pWMA->windowSize;

	//check if buffer is full
	if (pWMA->index == 0)
	{
		pWMA->filled = true;
	}

	//calculate avg
	if (pWMA->filled == true)
	{
		avg = pWMA->sum / pWMA->windowSize;
	} else {
		avg = pWMA->sum / pWMA->index;
	}


	return avg;
}


/***** PRIVATE FUNCTIONS *****************************************************/
