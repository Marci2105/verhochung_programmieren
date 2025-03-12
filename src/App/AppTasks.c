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
#include "Application.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/

static Button_Status_t SW1State = BUTTON_RELEASED;
static Button_Status_t SW2State = BUTTON_RELEASED;
static Button_Status_t B1State = BUTTON_RELEASED;


/***** PUBLIC FUNCTIONS ******************************************************/


void taskApp10ms()
{
	SW1State = debouncer(BTN_SW1);
	SW2State = debouncer(BTN_SW2);
	B1State = debouncer(BTN_B1);
}


void taskApp50ms()
{

	sampleAppRun();
}

void taskApp250ms()
{

}


Button_Status_t getButtonSW1State()
{
    return SW1State;
}

Button_Status_t getButtonSW2State()
{
    return SW2State;
}

Button_Status_t getButtonB1State()
{
    return B1State;
}



/***** PRIVATE FUNCTIONS *****************************************************/




