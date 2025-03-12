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
