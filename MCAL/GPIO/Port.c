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

    /* To hold the value of cuurent port*/
    uint8 portIndex = 0;

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
            portIndex = A;
            /* [TODO]: you need to enable RCC*/
            break;
        case PORT_B:
            portIndex = B;
            break;
        case PORT_C:
            portIndex = C;
            break;
        case PORT_D:
            portIndex = D;
            break;
        case PORT_E:
            portIndex = E;
            break;
        case PORT_F:
            portIndex = F;

            break;
        }

        /* Special case of PD7,PF0 These pins are configured as a GPIO by default but are locked and can only be reprogrammed by unlocking the
         * pin in the GPIOLOCK register and uncommitting it by setting the GPIOCR register.
         */
        if (ConfigPtr->configType[channelIndex].portType == PORT_D && ConfigPtr->configType[channelIndex].pinType == PIN7 || ConfigPtr->configType[channelIndex].portType == PORT_F && ConfigPtr->configType[channelIndex].pinType == PIN0)
        {
            /* Unlocking the GPIO Commit (GPIOCR)*/
            GPIOLOCK(portIndex) = 0x4C4F434B;
            /* Apply Commiting*/
            SET_BIT(GPIOCR(portIndex), ConfigPtr->configType[channelIndex].pinType);
        }

        /* Special case of JTAG/SWD pins*/
        if (ConfigPtr->configType[channelIndex].portType == PORT_C && ConfigPtr->configType[channelIndex].pinType < PIN4)
        {
            /* Skip this loop iteration*/
            continue;
        }

        /* Set the direction of the GPIO port pins by programming the GPIODIR register. */
        switch (ConfigPtr->configType[channelIndex].pinDirectionType)
        {
        case INPUT:
            /* Clear channel bit in GPIODIR register. */
            CLEAR_BIT(GPIODIR(portIndex), ConfigPtr->configType[channelIndex].pinType);
            break;
        case OUTPUT:
            /* Set channel bit in GPIODIR register. */
            SET_BIT(GPIODIR(portIndex), ConfigPtr->configType[channelIndex].pinType);

            /* Specifying Desired Output value in its corresponding registers*/
            switch (ConfigPtr->configType[channelIndex].pinLevelType)
            {
            case PIN_LEVEL_LOW:
                /* Clear channel bit in GPIODATA register. */
                CLEAR_BIT(GPIODATA(portIndex), ConfigPtr->configType[channelIndex].pinType);
                break;
            case PIN_LEVEL_HIGH:
                /* Set channel bit in GPIODATA register. */
                SET_BIT(GPIODATA(portIndex), ConfigPtr->configType[channelIndex].pinType);
                break;
            }
            break;
        }

        /*  Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin.*/
        switch (ConfigPtr->configType[channelIndex].pinModeType)
        {
        case DIO_MODE:
            /* Clear channel bit in GPIOAFSEL register. */
            CLEAR_BIT(GPIOAFSEL(portIndex), ConfigPtr->configType[channelIndex].pinType);
            /* Set channel bit in GPIODEN register. */
            SET_BIT(GPIODEN(portIndex), ConfigPtr->configType[channelIndex].pinType);
            break;
        case AF_MODE:
            /* the PMCx field must be programmed in the GPIOPCTL register for
             * the specific peripheral required*/

            /* [TODO]: implement AF all modes*/
            break;
        }

        /* Specifying Desired Current in its corresponding registers*/
        /* Note by default all channels are choosed to drive 2mA by H.w
         * Setting a bit in either the GPIODR4 register or the GPIODR8 register
         * clears the corresponding 2-mA enable bit.
         */
        switch (ConfigPtr->configType[channelIndex].pinOutputCurrentType)
        {
        case DRIVE_2mA:
            /* Set channel bit in GPIODIR register. */
            SET_BIT(GPIODR2R(portIndex), ConfigPtr->configType[channelIndex].pinType);
            break;
        case DRIVE_4mA:
            /* Set channel bit in GPIODIR register. */
            SET_BIT(GPIODR4R(portIndex), ConfigPtr->configType[channelIndex].pinType);
            break;
        case DRIVE_8mA:
            /* Set channel bit in GPIODIR register. */
            SET_BIT(GPIODR8R(portIndex), ConfigPtr->configType[channelIndex].pinType);
            break;
        }

        /* Specifying Desired input internal attach type in its corresponding registers*/
        switch (ConfigPtr->configType[channelIndex].pinInternalAttachType)
        {
        case INTERNAL_PULL_UP:
            /* Set channel bit in GPIOODR register. */
            SET_BIT(GPIOPUR(portIndex), ConfigPtr->configType[channelIndex].pinType);
            break;
        case INTERNAL_PULL_DOWN:
            /* Set channel bit in GPIOPUR register. */
            SET_BIT(GPIOPDR(portIndex), ConfigPtr->configType[channelIndex].pinType);
            break;
        case OPEN_DRAIN:
            /* Set channel bit in GPIOODR register. */
            SET_BIT(GPIOODR(portIndex), ConfigPtr->configType[channelIndex].pinType);
            break;
        case SLEW_RATE:
            /* Set channel bit in GPIOODR register. */
            /* Note: Slew Rate Limit Enable (8-mA drive only) */
            SET_BIT(GPIOSLR(portIndex), ConfigPtr->configType[channelIndex].pinType);
            break;
        }

        /* Relocking Special registers*/
        if (ConfigPtr->configType[channelIndex].portType == PORT_D && ConfigPtr->configType[channelIndex].pinType == PIN7 || ConfigPtr->configType[channelIndex].portType == PORT_F && ConfigPtr->configType[channelIndex].pinType == PIN0)
        {
            /* locking the GPIO Commit (GPIOCR) by writing any dummy data*/
            GPIOLOCK(portIndex) = 0x1;
        }
    }
}
/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
