/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Port.c
 *  Module:  	  Port
 *
 *  Description:  Source file for Port Module
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
#include "Port.h"
#include "Dio_Regs.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/*******************************************************************************
 * Service Name: Port_Init
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ConfigPtr - Pointer to post-build (Linking) configuration data
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Setup the Port configuration:
 *  	1. The direction of pin: INPUT or OUTPUT
 *  	2. The initial value of the port pin
 *  	3. The initial port pin mode
 *  	4. The internal resisors of input pins
 *  	5. Output type
 *  	6. The ouptut Current of output pins
 *******************************************************************************/
void Port_Init(const Port_ConfigTypeArray *ConfigPtr)
{
    if (ConfigPtr == NULL_PTR)
    {
        return;
    }

    /* Index to loop over all Channels*/
    uint8 channelIndex;

    /* Pointer to Current port in specific loop iteration*/
    volatile uint32 *portPtr = NULL_PTR;

    for (channelIndex = 0; channelIndex < GPIO_TOTAL_CHANNELS_NUMBER; channelIndex++)
    {

        switch (ConfigPtr->configType[channelIndex].enableType == DISABLED)
        {
            /* Skip this loop iteration if channel is disabled*/
            continue;
        }

        /* Assign portPtr to its correct value*/
        switch (ConfigPtr->configType[channelIndex].portType)
        {
        case PORT_A:
            portPtr = GPIO_PORTS_ADDRESS(A);
            /* [TODO]: you need to enable RCC*/
            break;
        case PORT_B:
            portPtr = GPIO_PORTS_ADDRESS(B);
            break;
        case PORT_C:
            portPtr = GPIO_PORTS_ADDRESS(C);
            break;
        case PORT_D:
            portPtr = GPIO_PORTS_ADDRESS(D);
            break;
        case PORT_E:
            portPtr = GPIO_PORTS_ADDRESS(E);
            break;
        case PORT_F:
            portPtr = GPIO_PORTS_ADDRESS(F);
            break;
        }
        
        switch(ConfigPtr->configType[channelIndex].pinModeType)
        {
            case DIO_MODE:
            break;
            case AF_MODE:
            /* [TODO]: implement AF all modes*/
            break;
        }
    }
}
/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
