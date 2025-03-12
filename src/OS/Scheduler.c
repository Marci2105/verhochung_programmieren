/******************************************************************************
 * @file Scheduler.c
 *
 * @author Andreas Schmidt (a.v.schmidt81@googlemail.com
 * @date   08.02.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Implementation of the cooperative scheduler with a  pre-defined set
 * of cyclic "task slots"
 *
 *
 *****************************************************************************/

//!< zum nutzen erst globale variable anlegen Scheduler sched;
//! dann inizialisieren schedInitialize(&sched);
//! funktionen hinzufügen sched.pTask_10ms = funktion1;
//! in superloop schedCycle(&sched);

/***** INCLUDES **************************************************************/
#include "Scheduler.h"

#include "stm32g4xx_hal.h"
/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/
#define HAL_TICK_VALUE_10MS     10      //!< Number of HAL Ticks used for 10ms Tasks
#define HAL_TICK_VALUE_50MS     50	    //!< Number of HAL Ticks used for 50ms Tasks
#define HAL_TICK_VALUE_250MS    250     //!< Number of HAL Ticks used for 250ms Tasks

static uint32_t schedGetElapsedTime(uint32_t savedTimeStamp, uint32_t currentTime);

/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/


int32_t schedInitialize(Scheduler* pScheduler)
{
	if (pScheduler == 0)
		return SCHED_ERR_INVALID_PTR;

	pScheduler->halTick_10ms	= 0;
	pScheduler->halTick_50ms	= 0;
	pScheduler->halTick_250ms	= 0;

	pScheduler->pTask_10ms		= 0;
	pScheduler->pTask_50ms		= 0;
	pScheduler->pTask_250ms		= 0;

    return SCHED_ERR_OK;
}


int32_t schedCycle(Scheduler* pScheduler)
{
	if (pScheduler == 0)
		return SCHED_ERR_INVALID_PTR;

	uint32_t timeElapsed	= 0;
	uint32_t actualTick		= 0;

	//!< 10ms Tasks
	actualTick = HAL_GetTick();

	timeElapsed = schedGetElapsedTime(pScheduler->halTick_10ms, actualTick);

	if (timeElapsed >= HAL_TICK_VALUE_10MS)
	{
		pScheduler->halTick_10ms = actualTick;
		if (pScheduler->pTask_10ms != 0)
		{
			pScheduler->pTask_10ms();
		}
	}

	//!< 50ms Tasks
	actualTick = HAL_GetTick();

	timeElapsed = schedGetElapsedTime(pScheduler->halTick_50ms, actualTick);

	if (timeElapsed >= HAL_TICK_VALUE_50MS)
	{
		pScheduler->halTick_50ms = actualTick;
		if (pScheduler->pTask_50ms != 0)
		{
			pScheduler->pTask_50ms();
		}
	}

	//!< 250ms Tasks
	actualTick = HAL_GetTick();

	timeElapsed = schedGetElapsedTime(pScheduler->halTick_250ms, actualTick);

	if (timeElapsed >= HAL_TICK_VALUE_250MS)
	{
		pScheduler->halTick_250ms = actualTick;
		if (pScheduler->pTask_250ms != 0)
		{
			pScheduler->pTask_250ms();
		}
	}

    return SCHED_ERR_OK;
}

static uint32_t schedGetElapsedTime(uint32_t savedTimeStamp, uint32_t currentTime)
{
	uint32_t timeDiff = currentTime - savedTimeStamp;
	return timeDiff;
}


/***** PRIVATE FUNCTIONS *****************************************************/
