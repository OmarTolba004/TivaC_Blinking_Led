/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Dio.c
 *  Module:  	  Dio
 *
 *  Description:  Source file for Dio Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  18/12/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Macros.h"
#include "Dio.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/*******************************************************************************
 * Service Name: Dio_WriteChannel
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in):  Port - Dio_PortType, Pin - Dio_PinType , Value -Dio_LevelType 
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Dio_LevelType
 * Description: Function for DIO Write Channel API
 *******************************************************************************/
void Dio_WriteChannel(Dio_PortType Port, Dio_ChannelType Pin, Dio_LevelType Value)
{
}

/*******************************************************************************
 * Service Name: Dio_ReadChannel
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Port - Dio_PortType , Pin - Dio_PinType 
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Dio_LevelType
 * Description: Function for DIO read Channel API
 *******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_PortType Port, Dio_ChannelType Pin)
{
}

/*******************************************************************************
 * Service Name: Dio_ReadPort
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Port - Dio_PortType
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Dio_LevelType
 * Description: Function for DIO read Port API
 *******************************************************************************/
uint32 Dio_ReadPort(Dio_PortType Port)
{
}

/*******************************************************************************
 * Service Name: Dio_WritePort
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Port - Dio_PortType, Value - uint8
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Dio_LevelType
 * Description: Function for DIO Write Port API
 *******************************************************************************/
void Dio_WritePort(Dio_PortType Port, uint32 value)
{
}

/*******************************************************************************
 * Service Name: Dio_FlipChannel
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ChannelId - Dio_ChannelType
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Dio_LevelType
 * Description: Function for DIO flip Channel, then read Channel API
 *******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_PortType PortId, Dio_ChannelType ChannelId)
{
}
/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
