/******************************************************************************
 * @file Application.h
 *
 * @author Andreas Schmidt (a.v.schmidt81@googlemail.com
 * @date   08.02.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Header file for main application (state machine)
 *
 *
 *****************************************************************************/
#ifndef _APPLICATION_H_
#define _APPLICATION_H_

/***** INCLUDES **************************************************************/
#include <stdint.h>

/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/
#define STATE_ID_STARTUP			1       //!< Example State for Startup
#define STATE_ID_OPERATIONAL		2       //!< Example State for Runing
#define STATE_ID_MAINTENANCE		3
#define STATE_ID_FAILURE        	4       //!< Example State for Failure

#define EVT_ID_INIT_READY       	1       //!< Event ID for INIT_READY
#define EVT_ID_SENSOR_FAILED    	2       //!< Event ID for Sensor Failure
#define EVT_ID_ENTER_MAINTENANCE    3       //!< Event ID for Sensor Failure
#define EVT_ID_LEAVE_MAINTENANCE   	4       //!< Event ID for Sensor Failure


/***** TYPES *****************************************************************/


/***** PROTOTYPES ************************************************************/

int32_t sampleAppInitialize();

int32_t sampleAppRun();

int32_t sampleAppSendEvent(int32_t eventID);

#endif
