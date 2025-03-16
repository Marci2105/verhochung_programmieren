/******************************************************************************
 * @file BootUp.h
 *
 * @author Marcel Schad, Samuel Schwarz
 * @date   16.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief implements the Boot Up State
 *
 * @details provides a Boot Up running and start function
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
