/******************************************************************************
 * @file AppTasks.c
 *
 * @author Andreas Schmidt (a.v.schmidt81@googlemail.com
 * @date   08.02.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Implementation File for the application tasks
 *
 *
 *****************************************************************************/


/***** INCLUDES **************************************************************/
#include "Scheduler.h"
#include "AppTasks.h"
#include "ButtonModule.h"
#include "Debouncer.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/


void taskApp10ms()
{
	Button_Status_t but1 = debouncer(BTN_SW1);
	Button_Status_t but2 = debouncer(BTN_SW2);
	Button_Status_t but3 = debouncer(BTN_B1);
}


void taskApp50ms()
{

}

void taskApp250ms()
{

}


/***** PRIVATE FUNCTIONS *****************************************************/




