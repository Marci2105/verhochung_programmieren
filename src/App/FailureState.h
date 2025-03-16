/******************************************************************************
 * @file FailureState.h
 *
 * @author Marcel Schad, Samuel Schwarz
 * @date   16.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief implements the Failure State
 *
 * @details provides a Failure running and start function
 *
 *
 *****************************************************************************/
#ifndef _FAILURESTATE_H
#define _FAILURESTATE_H


/***** INCLUDES **************************************************************/


/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/

typedef enum _Error_Case_t{
	SENSOR_FAILURE,
	SYSTEM_FAILURE
}Error_Case_t;

/***** PROTOTYPES ************************************************************/

void failureStart(Error_Case_t errorType);

#endif
