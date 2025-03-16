/******************************************************************************
 * @file SerialOutputController.c
 *
 * @author Marcel Schad, Samuel Schwarz
 * @date   16.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Serial Output Module
 *
 * @details provides a uart send string function
 *
 *
 *****************************************************************************/


/***** INCLUDES **************************************************************/
#include "SerialOutputController.h"
#include <string.h>
#include <stdio.h>
#include "UARTModule.h"
#include "LogOutput.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/
#define BUFFER_SIZE 25u
#define ACTIVATE_UART_OUTPUT


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/
#ifdef ACTIVATE_UART_OUTPUT

void uartSendString(const char* text)
{
    outputLog(text);
}

#else

void uartSendString(const char* text)
{

}

#endif
/***** PRIVATE FUNCTIONS *****************************************************/
