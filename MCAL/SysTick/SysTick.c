/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  SysTick.c
 *  Module:  	  SysTick
 *
 *  Description:  Source file for SysTick Module
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
#include "SysTick.h"
#include "SysTick_Regs.h"
#include "SysTick_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/* Porinter to function */
static volatile void (*SysTick_Callback_ptr)(void);

/*******************************************************************************
 * Service Name: SysTick_Init
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): LoadValue - SysTick_LoadValueType
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Init SysTick Driver
 *******************************************************************************/
void SysTick_Init(SysTick_LoadValueType LoadValue)
{
    /*  Program the value in the STRELOAD register*/
    SYSTICK.STReload.BF.RELOAD = LoadValue;

    /* Clear the STCURRENT register by writing to it with any value.*/
    SYSTICK.STCurrent.BF.CURRENT = 0x01;

    /* Configure the STCTRL register for the required operation.*/
    SYSTICK.STCtrl.BF.CLK_SRC = SYSTICK_CLK_SOURCE;
    SYSTICK.STCtrl.BF.INTEN = SYSTICK_NOTIFICATION;
    /* Disable Systick at the beggining*/
    SYSTICK.STCtrl.BF.ENABLE = 0;
}

/*******************************************************************************
 * Service Name: SysTick_Set_CallBack
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): void - Pointer to function
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set call back function
 *******************************************************************************/
void SysTick_Set_CallBack(void (*ptrToFunc)(void))
{
    SysTick_Callback_ptr = ptrToFunc;
}

/*******************************************************************************
 * Service Name: SysTick_Fire
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): LoadValue - SysTick_LoadValueType
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to fire SysTick counts
 *******************************************************************************/
void SysTick_Fire(SysTick_LoadValueType LoadValue)
{
    /* Load the value into its register*/
    SYSTICK.STReload.BF.RELOAD = LoadValue;
    /* Clear the STCURRENT register by writing to it with any value.*/
    SYSTICK.STCurrent.BF.CURRENT = 0x01;
    /* Enable SysTick*/
    SYSTICK.STCtrl.BF.ENABLE = 1;
}

/*******************************************************************************
 * Service Name: SysTick_Get_Current_Count
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: SysTick_CurrentTickType (Current Timer Tick value)
 * Description: Function to Init SysTick Driver
 *******************************************************************************/
SysTick_CurrentTickType SysTick_Get_Current_Count(void)
{
    return SYSTICK.STCurrent.BF.CURRENT;
}

/* [TODO] : ISR implementation*/

/**********************************************************************************************************************
 *  END OF FILE: SysTick.c
 *********************************************************************************************************************/
