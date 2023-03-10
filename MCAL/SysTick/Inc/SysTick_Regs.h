/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  SysTick_Regs.h
 *  Module:  	  SysTick_Regs
 *
 *  Description:  Header file for SysTick registers
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  21/12/2022
 *********************************************************************************************************************/

#ifndef SYSTICK_REGS_H
#define SYSTICK_REGS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  MACROS
 *********************************************************************************************************************/
#define SYSTICK_BASE_ADRESS 0xE000E000 + 0x010
#define SYSTICK    (*((volatile SYSTICK_TYPE *)(0xE000E010)))

/**********************************************************************************************************************
 *  GLOBAL DATA 
 *********************************************************************************************************************/

typedef struct
{
uint32 ENABLE : 1;
uint32 INTEN : 1;
uint32 CLK_SRC : 1;
uint32          :13;
uint32 COUNT: 1;
uint32  :0;
}STCTRL_BF;

typedef union
{
    uint32 REG;
    STCTRL_BF BF;
}STCTRL_TYPE;

typedef struct
{
uint32 RELOAD : 24;
uint32  :0;
}STRELOAD_BF;

typedef union
{
    uint32 REG;
    STRELOAD_BF BF;
}STRELOAD_TYPE;

typedef struct
{
uint32 CURRENT : 24;
uint32  :0;
}STCURRENT_BF;

typedef union
{
    uint32 REG;
    STCURRENT_BF BF;
}STCURRENT_TYPE;

typedef struct
{
    STCTRL_TYPE STCtrl;
    STRELOAD_TYPE STReload;
    STCURRENT_TYPE STCurrent;
}SYSTICK_TYPE;

#endif /* SYSTICK_REGS_H */
/**********************************************************************************************************************
 *  END OF FILE: SysTick_Regs.h
 *********************************************************************************************************************/
