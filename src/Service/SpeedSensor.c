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


/***** INCLUDES **************************************************************/

#include "../Service/SpeedSensor.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/

static int motorSpeed = 0;


/***** PUBLIC FUNCTIONS ******************************************************/

void setMotorSpeed(int targetMotorRPM){
	motorSpeed = targetMotorRPM;
}

int getMotorSpeed(){
	return motorSpeed;
}

Warning_LED_State_t monitorMotorSpeed(){
	static Warning_LED_State_t ledState = WARNING_LED_OFF;

	static int counter_700 = 0;
	    static int counter_900 = 0;
	    static int counter_800 = 0;
	    static int counter_650 = 0;

	    if (motorSpeed > 900) {
	        counter_900++;
	        counter_700 = 0;
	        counter_800 = 0;
	        counter_650 = 0;
	        if (counter_900 >= 60) {
	            ledState = WARNING_LED_FLASH;
	        }
	    } else if (motorSpeed > 700) {
	        counter_700++;
	        counter_900 = 0;
	        counter_800 = 0;
	        counter_650 = 0;
	        if (counter_700 >= 100) {
	            ledState = WARNING_LED_ON;
	        }
	    } else if (motorSpeed < 800) {
	        counter_800++;
	        counter_900 = 0;
	        counter_700 = 0;
	        counter_650 = 0;
	        if (counter_800 >= 60) {
	            if (ledState == WARNING_LED_FLASH) {
	                ledState = WARNING_LED_ON;
	            }
	        }
	    } else if (motorSpeed < 650) {
	        counter_650++;
	        counter_900 = 0;
	        counter_700 = 0;
	        counter_800 = 0;
	        if (counter_650 >= 60) {
	            ledState = WARNING_LED_OFF;
	        }
	    } else {
	        counter_700 = 0;
	        counter_900 = 0;
	        counter_800 = 0;
	        counter_650 = 0;
	    }

	return ledState;
}

/***** PRIVATE FUNCTIONS *****************************************************/
