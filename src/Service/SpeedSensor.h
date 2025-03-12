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
#ifndef _SPEEDSENSOR_H
#define _SPEEDSENSOR_H


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
