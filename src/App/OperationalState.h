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
#ifndef _OPERATIONALSTATE_H
#define _OPERATIONALSTATE_H


/***** INCLUDES **************************************************************/


/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/


typedef enum _Error_Status_t{
	ERROR_SENSOR,
	NO_ERROR_SENSOR
}Error_Status_t;

/***** PROTOTYPES ************************************************************/

void operationalStart();

Error_Status_t operationalRunning();

#endif
