/******************************************************************************
 * @file Potentiometer.h
 *
 * @author Marcel Schad, Samuel Schwarz
 * @date   16.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Potentiometer module
 *
 * @details provides a single init and a get function for each potentiometer
 *
 *
 *****************************************************************************/

#ifndef SRC_SERVICE_POTENTIOMETER_H_
#define SRC_SERVICE_POTENTIOMETER_H_

/***** INCLUDES **************************************************************/

#include <stdbool.h>
#include <stdint.h>
/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/


/***** PROTOTYPES ************************************************************/

void potentiometerInit();
uint32_t getR1Value();
uint32_t getR2Value();




#endif /* SRC_SERVICE_POTENTIOMETER_H_ */
