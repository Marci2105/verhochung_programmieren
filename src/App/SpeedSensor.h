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
#ifndef _FILENAME_H
#define _FILENAME_H


/***** INCLUDES **************************************************************/


/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/

typedef enum
{
    WARNING_LED_ON,
    WARNING_LED_FLASH,
    WARNING_LED_OFF
}Warning_LED_State_t;

/***** PROTOTYPES ************************************************************/

void setMotorSpeed(int motorRPM);
int getMotorSpeed();

#endif
