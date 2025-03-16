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
#include "DisplayController.h"
#include "ADCModule.h"
#include "Potentiometer.h"
#include "FlowRateSensor.h"
#include "SpeedSensor.h"
#include "StackMonitor.h"


/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/

#define DISPLAY_DASH 16u
#define DISPLAY_LOWER_O 18u
#define DISPLAY_OFF 19u

/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/

static Button_Status_t SW1State = BUTTON_RELEASED;
static Button_Status_t SW2State = BUTTON_RELEASED;
static Button_Status_t B1State = BUTTON_RELEASED;

static int leftDisplay = DISPLAY_OFF;
static int rightDisplay = DISPLAY_OFF;


/***** PUBLIC FUNCTIONS ******************************************************/


void taskApp10ms()
{
	SW1State = debouncer(BTN_SW1);
	SW2State = debouncer(BTN_SW2);
	B1State = debouncer(BTN_B1);

	int r1Value = getR1Value();
	int r2Value = getR2Value();
	setMotorSpeed(r1Value);
	setFlowRate(r2Value);


	controlDisplay(leftDisplay, rightDisplay);
}


void taskApp50ms()
{

	sampleAppRun();
}

void taskApp250ms()
{
	sendStackInfoOverUART();
}


Button_Status_t getButtonSW1State()
{
    static bool getPressedState = false;



    if(getPressedState == false){
    	if(SW1State == BUTTON_PRESSED){
    		getPressedState = true;
    	}
    }else{

    	if(SW1State == BUTTON_RELEASED){
    	    	getPressedState = false;
    	    }
    	return BUTTON_RELEASED;
    }

	return SW1State;
}

Button_Status_t getButtonSW2State()
{
	static bool getPressedState = false;

	    if(getPressedState == false){
	    	if(SW2State == BUTTON_PRESSED){
	    		getPressedState = true;
	    	}
	    }else{
	    	if(SW2State == BUTTON_RELEASED){
	    	    getPressedState = false;
	    	}
	    	    return BUTTON_RELEASED;
	    }

    return SW2State;
}

Button_Status_t getButtonB1State()
{
	static bool getPressedState = false;

	    if(getPressedState == false){
	    	if(B1State == BUTTON_PRESSED){
	    		getPressedState = true;
	    	}
	    }else{
	    	if(B1State == BUTTON_RELEASED){
	    	   	getPressedState = false;
	    	}
	    	   	return BUTTON_RELEASED;
	    }

    return B1State;
}

void setDisplay(int left, int right){
	leftDisplay = left;
	rightDisplay = right;
}



/***** PRIVATE FUNCTIONS *****************************************************/




