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

#include <stdbool.h>

#include "OperationalState.h"
#include "SpeedSensor.h"
#include "FlowRateSensor.h"
#include "AppTasks.h"
#include "LEDModule.h"
#include "CheckSensors.h"

/***** PRIVATE CONSTANTS *****************************************************/

#define MOTOR_OFF 0u
#define TIME_STAMP 50u

//Timers:
#define WARNING_TIME 3000u
#define SPEED_WARNING_TIME 5000u
#define SPEED_FLASH_TIME 3000u
#define SPEED_ON_TIME 3000u
#define SPEED_OFF_TIME 3000u
#define MOTOR_START_TIME 5000u

#define TIMER_RESET 0u

//Valid Flow Rate:
#define NO_VALIDFLOWRATE_SET 1000u	//Can not be reached by flowRate
#define SET 0u
#define NOT_SET 1u
#define WAIT_FOR_MOTOR_START 2u
#define TOLERANCE_VALIDFLOWRATE 10u

//Display:
#define DISPLAY_DASH 16u
#define DISPLAY_LOWER_O 18u
#define DISPLAY_OFF 19u

#define FACTOR_HUNDRED 100u
#define FACTOR_TEN 10u

/***** PRIVATE TYPES *********************************************************/

typedef struct {
    int warning;
    int flash;
    int on;
    int off;
    int motorStart;
} TimerStruct;



/***** PRIVATE VARIABLES *****************************************************/

static int lastMotorRPM = 0u;
static TimerStruct timers = {0u, 0u, 0u, 0u, 0u};
static bool warningIndicatorOn = false;
static bool warningLEDFlashing = false;
static int validFlowRate = NOT_SET;

/***** PRIVATE FUNCTION PROTOTYPES ******************************************/
static bool isConditionViolated(int motorSpeed, int flowRate);
static void displayMotorSpeed(int motorSpeed);

/***** PUBLIC FUNCTIONS ******************************************************/

void operationalStart(){
	ledSetLED(LED0, LED_ON);

	if(getValidFlowRate()==NO_VALIDFLOWRATE_SET){

		setDisplay(DISPLAY_LOWER_O, DISPLAY_LOWER_O);
		validFlowRate = NOT_SET;
	}else{
		validFlowRate = WAIT_FOR_MOTOR_START;
	}
}




Error_Operational_t operationalRunning() {

	Error_Operational_t error = NO_ERROR_SENSOR;

	if(validFlowRate==WAIT_FOR_MOTOR_START){
		timers.motorStart += TIME_STAMP;

		if(timers.motorStart >= MOTOR_START_TIME){
			validFlowRate = SET;
		}

	}else if(validFlowRate==SET){

    int motorSpeed = getMotorSpeed();
    int flowRate = getFlowRate();


    //Check if there is correct sensor data
    if(checkMotorSpeed(motorSpeed)==INVALID_DATA || checkFlowRate(flowRate)==INVALID_DATA){
    	ledSetLED(LED4, LED_ON);
    	error = ERROR_SENSOR_OPERATIONAL;
    }else{

    if (motorSpeed != MOTOR_OFF) {
        // Store last motorSpeed which wasn't zero
        lastMotorRPM = motorSpeed;

        displayMotorSpeed(motorSpeed);

        // Checks if the flowRate doesn't fit the motor speed for more than 3 seconds
        if (isConditionViolated(motorSpeed, flowRate)==true) {
            timers.warning += TIME_STAMP;
            if (timers.warning >= WARNING_TIME) {
                ledSetLED(LED1, LED_ON);
                warningIndicatorOn = true;
            }
        } else {
            timers.warning = 0;
            if (warningIndicatorOn) {
                ledSetLED(LED1, LED_OFF);
                warningIndicatorOn = false;
            }
        }

        // Sets the motor LED to on if the flowRate is the target FlowRate
        if (isConditionViolated(motorSpeed, flowRate)==false && flowRate>=validFlowRate-TOLERANCE_VALIDFLOWRATE && flowRate<=validFlowRate+TOLERANCE_VALIDFLOWRATE) {
            ledSetLED(LED3, LED_ON);
        } else {
            ledToggleLED(LED3);
        }

        // Motor Speed Monitoring Rules
        if (motorSpeed > 700u) {
            timers.warning += TIME_STAMP;
            if (timers.warning >= SPEED_WARNING_TIME) {
                ledSetLED(LED1, LED_ON);
            }
        } else {
            timers.warning = TIMER_RESET;
        }

        if (motorSpeed > 900u) {
            timers.flash += TIME_STAMP;
            if (timers.flash >= SPEED_FLASH_TIME) {
                //Flashing outside the if statement so it doesn't stop below 900
                warningLEDFlashing = true;
            }
        } else {
            timers.flash = TIMER_RESET;
        }


        if(warningLEDFlashing==true){
        	ledToggleLED(LED1);
        }

        if (motorSpeed < 800u && warningLEDFlashing==true) {
            timers.on += TIME_STAMP;
            if (timers.on >= SPEED_ON_TIME) {
                ledSetLED(LED1, LED_ON);
                warningLEDFlashing = false;
            }
        } else {
            timers.on = TIMER_RESET;
        }

        if (motorSpeed < 650u) {
            timers.off += TIME_STAMP;
            if (timers.off >= SPEED_OFF_TIME && warningIndicatorOn == false) {
                ledSetLED(LED1, LED_OFF);
                warningLEDFlashing = false;
            }
        } else {
            timers.off = TIMER_RESET;
        }
    } else {
        // If motor is switched off
        ledSetLED(LED3, LED_OFF);
        ledSetLED(LED1, LED_OFF);
    }

    // Check Button SW1 and SW2
    if (getButtonSW1State() == BUTTON_PRESSED) {
        setMotorSpeed(MOTOR_OFF);
    } else if (getButtonSW2State() == BUTTON_PRESSED) {
        setMotorSpeed(lastMotorRPM);
    }
	}
	}

	return error;
}

/***** PRIVATE FUNCTIONS *****************************************************/

static bool isConditionViolated(int motorSpeed, int flowRate) {
    if ((motorSpeed > 0 && motorSpeed <= 200 && !(flowRate > 0 && flowRate <= 20)) ||
        (motorSpeed > 200 && motorSpeed <= 400 && !(flowRate > 20 && flowRate <= 50)) ||
        (motorSpeed > 400 && motorSpeed <= 600 && !(flowRate > 50 && flowRate <= 75)) ||
        (motorSpeed > 600 && !(flowRate <= 80))) {
        return true;
    }
    return false;
}

static void displayMotorSpeed(int motorSpeed){
	int left = motorSpeed/FACTOR_HUNDRED;
	int right = motorSpeed/FACTOR_TEN;
	setDisplay(left, right);
}
