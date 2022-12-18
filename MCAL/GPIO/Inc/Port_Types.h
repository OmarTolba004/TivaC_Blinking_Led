/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Port_Types.h
 *  Module:  	  Port_Types
 *
 *  Description:  Header file for Dio's types
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  18/12/2022
 *********************************************************************************************************************/

#ifndef PORT_TYPES_H
#define PORT_TYPES_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  CONSTANT MACROS
 *********************************************************************************************************************/
#define GPIO_TOTAL_CHANNELS_NUMBER		43

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/*  - Needed Types from eg-fwd. note --> I added more.
		Port_PinType
		Port_PinDirectionType
		Port_PinModeType
		Port_PinInternalAttachType
		Port_PinOutputCurrentType
		Port_ConfigType
*/

typedef enum
{
	PIN0 = 0,
	PIN1 = 1,
	PIN2 = 2,
	PIN3 = 3,
	PIN4 = 4,
	PIN5 = 5,
	PIN6 = 6,
	PIN7 = 7,
} Port_PinType;

/* Enum to hold values of ports*/
typedef enum
{
	PORT_A = 0,
	PORT_B = 1,
	PORT_C = 2,
	PORT_D = 3,
	PORT_E = 4,
	PORT_F = 5,
} Port_PortType;
typedef enum
{
	INPUT = 0,
	OUTPUT = 1,
} Port_PinDirectionType;

/* Enum to hold channel level state*/
typedef enum
{
	PIN_LEVEL_LOW = 0,
	PIN_LEVEL_HIGH = 1
} Port_PinLevelType;

typedef enum
{
	DIO_MODE = 0,
	AF_MODE = 1, /* [TODO] : more AF function will be added later*/
} Port_PinModeType;

typedef enum
{
	INTERNAL_PULL_UP = 0,
	INTERNAL_PULL_DOWN = 1,
	OPEN_DRAIN = 2,
	SLEW_RATE = 3,
} Port_PinInternalAttachType;

typedef enum
{
	DRIVE_2mA = 0,
	DRIVE_4mA = 1,
	DRIVE_8mA = 2,
} Port_PinOutputCurrentType;

/* Enum to enable state of channel*/
typedef enum
{
	ENABLED = 0,
	DISABLED = 1,
} Port_EnableType;

typedef struct
{
	Port_PinType  pinType;
	Port_PortType  portType;
	Port_PinDirectionType pinDirectionType;
	Port_PinModeType pinModeType;
	Port_PinInternalAttachType pinInternalAttachType;
	Port_PinOutputCurrentType pinOutputCurrentType;
	Port_EnableType enableType;
}Port_ConfigType;

typedef struct
{
	Port_ConfigType configType[GPIO_TOTAL_CHANNELS_NUMBER];
}Port_ConfigTypeArray;

#endif /* PORT_TYPES_H*/
/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
