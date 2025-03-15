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
#include "StackMonitor.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "UARTModule.h"

/***** PRIVATE CONSTANTS *****************************************************/
extern uint32_t _top_of_stack;
extern uint32_t _bottom_of_stack;

#define STACK_END_MARKER   0xABABABAB
#define STACK_UNUSED_MARKER 3452816845
/***** PRIVATE MACROS ********************************************************/


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

void uartSendString(const char* str)
{
    uartSendData((uint8_t*)str, strlen(str));
}

void sendStackInfoOverUART()
{
    char buffer[64];  // Puffer für formatierten String
    int stackValid = isStackValid();
    int freeStackBytes = getFreeStackBytes();

    snprintf(buffer, sizeof(buffer), "Stack Valid: %d\r\n", stackValid);
    uartSendString(buffer);

    snprintf(buffer, sizeof(buffer), "Free Stack Bytes: %d\r\n", freeStackBytes);
    uartSendString(buffer);
}

/***** PRIVATE FUNCTIONS *****************************************************/
