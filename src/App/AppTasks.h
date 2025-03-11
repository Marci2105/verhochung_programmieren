/******************************************************************************
 * @file AppTasks.h
 *
 * @author Andreas Schmidt (a.v.schmidt81@googlemail.com
 * @date   08.02.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Header File for the application tasks
 *
 *
 *****************************************************************************/
#ifndef _APPTASKS_H_
#define _APPTASKS_H_


/***** INCLUDES **************************************************************/
#include <stdint.h>
#include "ButtonModule.h"

/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/


/***** PROTOTYPES ************************************************************/

void taskApp10ms();
void taskApp50ms();
void taskApp250ms();

Button_Status_t getButtonSW1State();
Button_Status_t getButtonSW2State();
Button_Status_t getButtonB1State();




#endif /* SRC_APP_APPTASKS_H_ */
