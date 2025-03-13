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
#ifndef _STARTUP_H
#define _STARTUP_H


/***** INCLUDES **************************************************************/


/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/

typedef enum _Error_BootUp_t{
	ERROR_SYSTEM,
	ERROR_SENSOR_BOOTUP,
	NO_ERROR
}Error_BootUp_t;

/***** PROTOTYPES ************************************************************/

Error_BootUp_t bootUpStart();

#endif
