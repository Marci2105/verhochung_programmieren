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
#ifndef _FLOWRATESENSOR_H
#define _FLOWRATESENSOR_H


/***** INCLUDES **************************************************************/

#include <stdbool.h>

/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/


/***** PROTOTYPES ************************************************************/

void setFlowRate(int targetFlowRate);

int getFlowRate();

int getValidFlowRate();

void setValidFlowRate(int targetFlowRate);


#endif
