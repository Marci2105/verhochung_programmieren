/******************************************************************************
 * @file FailureState.c
 *
 * @author Marcel Schad, Samuel Schwarz
 * @date   16.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief implements the Failure State
 *
 * @details provides a Failure running and start function
 *
 *
 *****************************************************************************/


/***** INCLUDES **************************************************************/


#include "FailureState.h"
#include "LEDModule.h"
#include "SerialOutputController.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/

void failureStart(Error_Case_t errorType){
	uartSendString("failure state\r\n");
	if(errorType==SENSOR_FAILURE){
		ledSetLED(LED4, LED_ON);
		uartSendString("sensor failure\r\n");
	} else {
		uartSendString("system failure\r\n");
	}

	ledSetLED(LED2, LED_ON);
	ledSetLED(LED0, LED_OFF);





}

/***** PRIVATE FUNCTIONS *****************************************************/
