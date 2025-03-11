/******************************************************************************
 * @file Debouncer.h
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

#include <stdint.h>
#include <stdbool.h>

#include "Debouncer.h"

#include "ButtonModule.h"


/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/

#define DEBOUNCE_COUNTS  5u


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/



Button_Status_t debouncer(int button) {
    static uint8_t stableCount = 0;
    static Button_Status_t lastReadState = BUTTON_RELEASED;

    Button_Status_t currentState = buttonGetButtonStatus(button);

    if (currentState == lastReadState) {
        if (stableCount < DEBOUNCE_COUNTS) {
            stableCount++;
        }
    } else {
        stableCount = 0;
    }

    lastReadState = currentState;

    if (stableCount < DEBOUNCE_COUNTS) {
        currentState = BUTTON_RELEASED;
    }


    return currentState;
}


/***** PRIVATE FUNCTIONS *****************************************************/
