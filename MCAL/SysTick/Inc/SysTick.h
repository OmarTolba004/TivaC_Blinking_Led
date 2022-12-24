/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  SysTick.h
 *  Module:  	  SysTick
 *
 *  Description:  Header file for SysTick Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  20/12/2022
 *********************************************************************************************************************/

#ifndef SYSTICK_H
#define SYSTICK_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "SysTick_Types.h"

/**********************************************************************************************************************
 *  FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/

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
void SysTick_Init(SysTick_LoadValueType LoadValue);

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
void SysTick_Set_CallBack(void (*ptrToFunc)(void));

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
void SysTick_Fire(SysTick_LoadValueType LoadValue);

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
SysTick_CurrentTickType SysTick_Get_Current_Count(void);

#endif /* SYSTICK_H */
/**********************************************************************************************************************
 *  END OF FILE: SysTick.h
 *********************************************************************************************************************/
