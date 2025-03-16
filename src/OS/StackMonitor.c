/******************************************************************************
 * @file StackMonitor.c
 *
 * @author Marcel Schad, Samuel Schwarz
 * @date   26.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Stack Monitor module
 *
 * @details monitors the free stack bytes and checks if the stack is valid
 *
 *
 *****************************************************************************/


/***** INCLUDES **************************************************************/
#include "StackMonitor.h"
#include <stdint.h>
#include "SerialOutputController.h"
#include <stdio.h>
#include <string.h>
#include "LogOutput.h"


/***** PRIVATE CONSTANTS *****************************************************/
extern uint32_t _top_of_stack;
extern uint32_t _bottom_of_stack;

/***** PRIVATE MACROS ********************************************************/

#define STACK_END_MARKER   0xABABABAB
#define STACK_UNUSED_MARKER 3452816845

#define BUFFER_SIZE 20
/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/


int isStackValid() {
    uint32_t* stackEnd = (uint32_t*) &_top_of_stack;
    if ( *stackEnd == STACK_END_MARKER)
    {
    	return 1;
    } else {
    	//stack is corrupt

    	return 0;
    }
}

int getFreeStackBytes() {
    uint32_t* ptr = (uint32_t*) &_top_of_stack;
    ptr++;
    uint32_t freeWords = 0;

    while ((uint32_t*) ptr < (uint32_t*) &_bottom_of_stack) {
        if (*ptr == STACK_UNUSED_MARKER) {
            freeWords++;
        } else {
        	break;
        }
        ptr++;
    }

    return freeWords * sizeof(uint32_t);
}


void sendStackInfoOverUART()
{
    int stackValid = isStackValid();
    int freeStackBytes = getFreeStackBytes();
    freeStackBytes = freeStackBytes * sizeof(uint32_t) + sizeof(uint32_t);

    if (stackValid == 1)
    {
    	uartSendString("Stack is valid\r\n");
    } else {
    	uartSendString("Stack is not Valid\r\n");
    }

    char buffer[BUFFER_SIZE];  // Puffer für den formatierten String
    snprintf(buffer, sizeof(buffer), "free bytes: %d\r\n", freeStackBytes);
    uartSendString(buffer);

}

/***** PRIVATE FUNCTIONS *****************************************************/
