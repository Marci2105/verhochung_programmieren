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

#define SENSOR_DEFECT_SIGNAL_LOW		500			//!< 500mV scaled to the ADC resolution
#define SENSOR_DEFECT_SIGNAL_HIGH		2500		//!< 2500mV scaled to the ADC resolution
#define MVOLT_TO_ADC_RES				4096/3300	//!< switch scale from 0-3300 mV to 0-4096
#define ADC_RES_TO_MVOLT				3300/4096


/***** TYPES *****************************************************************/


/***** PROTOTYPES ************************************************************/

void setMotorSpeed(int adcR1Value);
int getMotorSpeed();

#endif
