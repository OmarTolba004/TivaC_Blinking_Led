/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  IntCtrl.c
 *  Module:  	  IntCtrl
 *
 *  Description:  Source file for IntCtrl Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  20/12/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Macros.h"
#include "IntCtrl_Types.h"
#include "IntCtrl_Regs.h"

/**********************************************************************************************************************
 *  STATIC FUNCTION
 *********************************************************************************************************************/

/*******************************************************************************
 * Service Name: SCB_SetGroupingType
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set the type of Grouping
 */
static void SCB_SetGroupingType(IntCtrl_GROUPING_TYPES GroupingType);

/*******************************************************************************
 * Service Name: IntCtrl_SetPriority
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set the Priority for interrupts
 */
static void IntCtrl_SetPriority(IntCtrl_PeripheralGateType PeripheralGate, uint8 Priority);

/*******************************************************************************
 * Service Name: IntCtrl_EnablePriority
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Enable interrupts
 */
static void IntCtrl_EnableInterrupts(void);

/*******************************************************************************
 * Service Name: IntCtrl_DisableInterrupts
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Disable intterupts
 */
static void IntCtrl_DisableInterrupts(void);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS DEFINITIONS
 *********************************************************************************************************************/

/*******************************************************************************
 * Service Name: IntCtrl_Init
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to initialize interrupts and exceptions
 */
void IntCtrl_Init(void)
{
    /* Set Grouping Type*/
}

static void SCB_SetGroupingType(IntCtrl_GROUPING_TYPES GroupingType)
{
    /* this value must be written to unlock this register*/
    uint16 vectKey = 0x05FA;
    /* unlock APINT register*/
    SCB_APINT.BF.VECTKEY = vectKey;
    /* Set grouping value*/
    SCB_APINT.BF.PRIGROUP = GroupingType;
}

static void IntCtrl_SetPriority(IntCtrl_PeripheralGateType PeripheralGate, uint8 Priority)
{
    if (PeripheralGate < 15)
    {
        SCB_EXC_TYPES excType = PeripheralGate;
        switch (excType)
        {
        case RESET:
            break;
        case NMI:
            break;
        case HARD_FAULT:
            break;
        case MEMORY_MANAGEMENT:
            SCB_SYSPRI1.BF.MEM = Priority;
            break;
        case BUS_FAULT:
            SCB_SYSPRI1.BF.BUS = Priority;
            break;
        case USAGE_FAULT:
            SCB_SYSPRI1.BF.USAGE = Priority;
            break;
        case SVCALL:
            SCB_SYSPRI2.BF.SVC = Priority;
            break;
        case DEBUG_MONITOR:
            SCB_SYSPRI3.BF.DEBUG = Priority;
            break;
        case PENDSV:
            SCB_SYSPRI3.BF.PENDSV = Priority;
            break;
        case SYSTICK:
            SCB_SYSPRI3.BF.TICK = Priority;
            break;
        default:
            /* Un-reachable*/
            break;
        }
    }
    else
    {
        /* Get the corresponding interrupt number bit*/
        uint8 interruptIndex = PeripheralGate - 15;
        /* Get the index in the corresponding register*/
        uint8 indexInReg = interruptIndex % 4;

        switch (indexInReg)
        {
        case 0:
            NVIC_PRI(interruptIndex).BF.INTA = Priority;
            break;
        case 1:
            NVIC_PRI(interruptIndex).BF.INTB = Priority;
            break;
        case 2:
            NVIC_PRI(interruptIndex).BF.INTC = Priority;
            break;
        case 3:
            NVIC_PRI(interruptIndex).BF.INTD = Priority;
            break;
        }
    }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c.c
 *********************************************************************************************************************/
