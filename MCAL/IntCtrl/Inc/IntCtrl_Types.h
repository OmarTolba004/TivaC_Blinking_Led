/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  IntCtrl_Types.h
 *  Module:  	  IntCtrl_Types
 *
 *  Description:  Header file for IntCtrl Types
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  18/12/2022
 *********************************************************************************************************************/

#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * CONSTANT MACROS
 *********************************************************************************************************************/
#define SCB_TOTAL_NUMBER_OF_EXCEPTIONS      10
#define INTCTRL_TOTAL_NUMBER_OF_INTERRUPTS      1

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

typedef enum
{
EIGHT_GROUPS_ONE_SUBGROUP = 0x04,
FOUR_GROUPS_TWO_SUBGROUP = 0x05,
TWO_GROUPS_FOUR_SUBGROUP = 0x06,
ONE_GROUPS_EIGHT_SUBGROUP = 0x07,
}IntCtrl_GROUPING_TYPES;

typedef enum
{
    RESET = 1,
    NMI = 2,
    HARD_FAULT = 3,
    MEMORY_MANAGEMENT = 4,
    BUS_FAULT = 5,
    USAGE_FAULT = 6,
    SVCALL = 11,
    DEBUG_MONITOR = 12,
    PENDSV = 14,
    SYSTICK = 15,
}SCB_EXC_TYPES;

typedef uint8 IntCtrl_InerruptTypes;

/* To hold the value of sub group priority*/
typedef uint8 IntCtrl_PeripheralGateType;

/* To hold the value of group priority*/
typedef uint8 IntCtrl_GroupPriorityType;

/* To hold the value of sub group priority*/
typedef uint8 IntCtrl_SubGroupPriorityType;

typedef struct 
{
IntCtrl_PeripheralGateType peripheralGateType;
IntCtrl_GroupPriorityType groupPriorityType;
IntCtrl_SubGroupPriorityType subGroupPriorityType;
}IntCtrl_ConfigType;


typedef struct 
{
IntCtrl_ConfigType configType[SCB_TOTAL_NUMBER_OF_EXCEPTIONS+INTCTRL_TOTAL_NUMBER_OF_INTERRUPTS];
}IntCtrl_ConfigTypeArr;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#endif /* INTCTRL_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
