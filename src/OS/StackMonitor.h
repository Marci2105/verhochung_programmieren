/******************************************************************************
 * @file StackMonitor.h
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
#ifndef SRC_OS_STACKMONITOR_H_
#define SRC_OS_STACKMONITOR_H_


/***** INCLUDES **************************************************************/


/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/


/***** PROTOTYPES ************************************************************/
int isStackValid();
int getFreeStackBytes();
void sendStackInfoOverUART();

#endif /* SRC_OS_STACKMONITOR_H_ */
