/******************************************************************************
 * @file OperationalState.h
 *
 * @author Marcel Schad, Samuel Schwarz
 * @date   16.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief implements the Operatinal State
 *
 * @details provides a operational running and start function
 *
 *
 *****************************************************************************/
#ifndef _OPERATIONALSTATE_H
#define _OPERATIONALSTATE_H


/***** INCLUDES **************************************************************/


/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/


typedef enum _Error_Operational_t{
	ERROR_SENSOR_OPERATIONAL,
	NO_ERROR_SENSOR
}Error_Operational_t;

/***** PROTOTYPES ************************************************************/

void operationalStart();

Error_Operational_t operationalRunning();

#endif
