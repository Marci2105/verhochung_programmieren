/******************************************************************************
 * @file CheckSensors.h
 *
 * @author Marcel Schad, Samuel Schwarz
 * @date   16.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Sensor Check Module
 *
 * @details provides functions to check the flow rate and the motor speed
 *
 *
 *****************************************************************************/
#ifndef _CHECKSENSORS_H
#define _CHECKSENSORS_H


/***** INCLUDES **************************************************************/



/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/

//Data Status of motor speed and flow rate
typedef enum _Data_Status_t{
	VALID_DATA,
	INVALID_DATA
}Data_Status_t;

/***** PROTOTYPES ************************************************************/

Data_Status_t checkFlowRate(int currentFlowRate);

Data_Status_t checkMotorSpeed(int currentMotorSpeed);


#endif
