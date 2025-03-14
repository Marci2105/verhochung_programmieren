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

#include "../Service/SpeedSensor.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/

#define FACTOR_TEN 10u
#define FACTOR_TWENTY 20u
#define MOTOR_OFF 0u
#define MOTOR_ON 5000u //Can not be reached normally


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/

static int motorSpeed = MOTOR_ON;
static int motorStatus = MOTOR_ON;


/***** PUBLIC FUNCTIONS ******************************************************/

void setMotorSpeed(int adcR1Value){

	if(adcR1Value==MOTOR_OFF){
		motorSpeed = MOTOR_OFF;
		motorStatus = MOTOR_OFF;

	}else if(adcR1Value==MOTOR_ON){
		motorStatus=MOTOR_ON;

	}

	if(motorStatus==MOTOR_ON){

	int r1ValueMV = adcR1Value * ADC_RES_TO_MVOLT;
	motorSpeed = ((r1ValueMV - SENSOR_DEFECT_SIGNAL_LOW) * FACTOR_TEN) / FACTOR_TWENTY;
	}


}

int getMotorSpeed(){
	return motorSpeed;
}



/***** PRIVATE FUNCTIONS *****************************************************/
