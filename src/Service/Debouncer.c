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
    static uint8_t stableCount_SW1 = 0u;
    static uint8_t stableCount_SW2 = 0u;
    static uint8_t stableCount_B1 = 0u;

    Button_Status_t currentState = buttonGetButtonStatus(button);

    if (button == BTN_SW1) {
        if (currentState == BUTTON_PRESSED) {
            if (stableCount_SW1 < DEBOUNCE_COUNTS) {
                stableCount_SW1++;
            }
        } else {
            stableCount_SW1 = 0u;
        }
        return currentState;
    }

    if (button == BTN_SW2) {
        if (currentState == BUTTON_PRESSED) {
            if (stableCount_SW2 < DEBOUNCE_COUNTS) {
                stableCount_SW2++;
            }
        } else {
            stableCount_SW2 = 0u;
        }
        return currentState;
    }

    if (button == BTN_B1) {
        if (currentState == BUTTON_PRESSED) {
            if (stableCount_B1 < DEBOUNCE_COUNTS) {
                stableCount_B1++;
            }
        } else {
            stableCount_B1 = 0u;
        }
        return currentState;
    }

    return BUTTON_RELEASED;
}



/***** PRIVATE FUNCTIONS *****************************************************/
