/******************************************************************************
 * @file Filter.h
 *
 * @author Andreas Schmidt (a.v.schmidt81@googlemail.com
 * @date   08.02.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Header file for Filter library
 *
 *
 *****************************************************************************/
#ifndef _FILTER_H_
#define _FILTER_H_

/***** INCLUDES **************************************************************/
#include <stdbool.h>
#include <stdint.h>

/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/
#define FILTER_ERR_OK                   0       //!< No error occured
#define FILTER_ERR_GENERAL              -1      //!< General error during filter processing
#define FILTER_ERR_INVALID_PTR          -2      //!< Invalid pointer (Null Pointer)
#define FILTER_ERR_INVALID_PARAM        -3      //!< Invalid parameter value

#define SCALING_FACTOR_MIN_VALUE		0		//!< minimum value for the scaling factor
#define ALPHA_MIN_VALUE					0		//!< minimum value for alpha

#define ADC_MAX_VALUE					4096	//!< maximum value of the used adc
#define ADC_MIN_VALUE 					0		//!< minimum value of the used adc

#define WINDOW_SIZE						5		//!< max size for the wma window

/***** TYPES *****************************************************************/

/**
 * @brief Struct which represents a EMA filter
 *
 */
typedef struct _EMAFilterData
{
    bool firstValueAvailable;                   //!< Flag to indicate whether there was already a value set as prev value
    int32_t alpha;                              //!< Alpha value (filter constant) as scaled value
    int32_t previousValue;                      //!< Previous value of the filter output
    int32_t scalingFactor;                      //!< Used scaling factor
} EMAFilterData_t;

/**
 * @brief Struct which represents a WMA filter
 *
 */
typedef struct _WMAFilterData
{
	bool filled;							//!< Flag to indicate whether the window is full
	int32_t buffer[WINDOW_SIZE];			//!< Buffer for the last values
	int32_t sum;							//!< sum of all values in the window
	uint32_t index;							//!< index for the position in the window
	uint32_t windowSize;					//!< size of the window
} WMAFilterData_t;

/***** PROTOTYPES ************************************************************/


/**
 * @brief Initialize an EMA filter with the provided parameter
 *
 * @param pEMA              Poitner to the EMA filter struct
 * @param scalingFactor     Scaling factor used for internal calculations
 * @param alpha             Already scaled alpha factor (must be scaled with same scaling factor as supplied via parameter)
 * @param resetFilter       Flag to indicate whether the filter should be reset
 *
 * @return Return FILTER_ERR_OK is no error occured
 */
int32_t filterInitEMA(EMAFilterData_t* pEMA, int32_t scalingFactor, int32_t alpha, bool resetFilter);


/**
 * @brief Resets the EMA filter structure
 *
 * @param pEMA              Pointer to the EMA filter struct
 *
 * @return Return FILTER_ERR_OK is no error occured
 */
int32_t filterResetEMA(EMAFilterData_t* pEMA);

/**
 * @brief Performs the EMA filtering on the provided sensor value
 *
 * @param pEMA              Pointer to the EMA filter struct
 * @param sensorValue       Value which should be filtered
 *
 * @return The filtered sensor value
 */
int32_t filterEMA(EMAFilterData_t* pEMA, int potentiometer);

int32_t filterInitWMA(WMAFilterData_t* pWMA, uint32_t windowSize);

int32_t filterResetWMA(WMAFilterData_t* pWMA);

int32_t filterWMA(WMAFilterData_t* pWMA, int potentiometer);

#endif
