/******************************************************************************
 * @file Application.h
 *
 * @author Andreas Schmidt (a.v.schmidt81@googlemail.com
 * @date   08.02.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Implementation file for main application (state machine)
 *
 *
 *****************************************************************************/


/***** INCLUDES **************************************************************/
#include <string.h>

#include "Application.h"
#include "Util/Global.h"
#include "Util/printf.h"
#include "AppTasks.h"


#include "OperationalState.h"
#include "MaintenanceState.h"
#include "FailureState.h"
#include "BootUp.h"

#include "UARTModule.h"
#include "ButtonModule.h"
#include "LEDModule.h"

#include "Util/StateTable/StateTable.h"


/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/
// State realte functions (on-Entry, on-State and on-Exit)
static int32_t onEntryStartup(State_t* pState, int32_t eventID);
static int32_t onEntryOperational(State_t* pState, int32_t eventID);
static int32_t onEntryMaintenance(State_t* pState, int32_t eventID);
static int32_t onStateOperational(State_t* pState, int32_t eventID);
static int32_t onStateMaintenance(State_t* pState, int32_t eventID);
static int32_t onEntryFailure(State_t* pState, int32_t eventID);

/***** PRIVATE VARIABLES *****************************************************/

/**
 * @brief List of State for the State Machine
 *
 * This list only constructs the state objects for each possible state
 * in the state machine. There are no transistions or events defined
 *
 */
static State_t gStateList[] =
{
    {STATE_ID_STARTUP, 		onEntryStartup,  	0,                  	0,  false},
    {STATE_ID_OPERATIONAL, 	onEntryOperational, onStateOperational,		0,  false},
    {STATE_ID_MAINTENANCE, 	onEntryMaintenance, onStateMaintenance, 	0,  false},
    {STATE_ID_FAILURE, 		onEntryFailure,  	0,                  	0,  false}
};

/**
 * @brief Definition of the transistion table of the state machine. Each row
 * contains FROM_STATE_ID, TO_STATE_ID, EVENT_ID, Function Pointer Guard Function
 *
 * The last two members of a transistion row are only the initialization of dynamic
 * members used durin runtim
 */
static StateTableEntry_t gStateTableEntries[] =
{
    {STATE_ID_STARTUP,          STATE_ID_OPERATIONAL,       EVT_ID_INIT_READY,          0,      0,      0},
    {STATE_ID_STARTUP,          STATE_ID_FAILURE,           EVT_ID_SENSOR_FAILED,       0,      0,      0},
    {STATE_ID_OPERATIONAL,      STATE_ID_FAILURE,           EVT_ID_SENSOR_FAILED,       0,      0,      0},
    {STATE_ID_OPERATIONAL,      STATE_ID_MAINTENANCE,   EVT_ID_ENTER_MAINTENANCE,       0,      0,      0},
    {STATE_ID_MAINTENANCE,      STATE_ID_OPERATIONAL,   EVT_ID_LEAVE_MAINTENANCE,       0,      0,      0}

};

/**
 * @brief Global State Table instance
 *
 */
static StateTable_t gStateTable;

//Save Error Type
static Error_Case_t errorType;


/***** PUBLIC FUNCTIONS ******************************************************/

int32_t sampleAppInitialize()
{

    gStateTable.pStateList = gStateList;
    gStateTable.stateCount = sizeof(gStateList) / sizeof(State_t);
    int32_t result = stateTableInitialize(&gStateTable, gStateTableEntries, sizeof(gStateTableEntries) / sizeof(StateTableEntry_t), STATE_ID_STARTUP);

    return result;
}

int32_t sampleAppRun()
{
    int32_t result = stateTableRunCyclic(&gStateTable);
    return result;
}

int32_t sampleAppSendEvent(int32_t eventID)
{
    int32_t result = stateTableSendEvent(&gStateTable, eventID);
    return result;
}


/***** PRIVATE FUNCTIONS *****************************************************/

static int32_t onEntryStartup(State_t* pState, int32_t eventID)
{

	Error_BootUp_t error = NO_ERROR;

		error = bootUpStart();

		if(error == ERROR_SYSTEM){

			errorType = SYSTEM_FAILURE;
	        return sampleAppSendEvent(EVT_ID_SENSOR_FAILED);
		}else if(error==ERROR_SENSOR_BOOTUP){

			errorType = SENSOR_FAILURE;
			return sampleAppSendEvent(EVT_ID_SENSOR_FAILED);
		}

    return sampleAppSendEvent(EVT_ID_INIT_READY);
}

static int32_t onEntryOperational(State_t* pState, int32_t eventID){
	operationalStart();
	return 0;
}

static int32_t onEntryMaintenance(State_t* pState, int32_t eventID){
	maintenanceStart();
	return 0;
}


static int32_t onStateOperational(State_t* pState, int32_t eventID)
{
	Error_Operational_t error = NO_ERROR_SENSOR;

	error = operationalRunning();

	if(error == ERROR_SENSOR_OPERATIONAL){

		errorType = SENSOR_FAILURE;
        return sampleAppSendEvent(EVT_ID_SENSOR_FAILED);
	}


	//Switch state if B1 was pressed
    if (getButtonB1State()==BUTTON_PRESSED){
        return sampleAppSendEvent(EVT_ID_ENTER_MAINTENANCE);
    }

    return 0;
}

static int32_t onStateMaintenance(State_t* pState, int32_t eventID)
{
	maintenanceRunning();

	//switch state if B1 was pressed
    if (getButtonB1State()==BUTTON_PRESSED){
        return sampleAppSendEvent(EVT_ID_LEAVE_MAINTENANCE);
    }


    return 0;
}



static int32_t onEntryFailure(State_t* pState, int32_t eventID)
{

	//Handle errorType
	failureStart(errorType);

    return 0;
}
