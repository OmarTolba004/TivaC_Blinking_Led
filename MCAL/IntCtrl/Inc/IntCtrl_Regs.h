/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  IntCtrl_Regs.h
 *  Module:  	  IntCtrl_Regs
 *
 *  Description:  Header file for IntCtrl Registers
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  18/12/2022
 *********************************************************************************************************************/

#ifndef INTCTRL_REGS_H
#define INTCTRL_REGS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS 0xE000E000
#define NVIC_EN0 (*((volatile NVIC_EN_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x100)))
#define NVIC_EN1 (*((volatile NVIC_EN_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x104)))
#define NVIC_EN2 (*((volatile NVIC_EN_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x108)))
#define NVIC_EN3 (*((volatile NVIC_EN_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x10c)))
#define NVIC_EN4 (*((volatile NVIC_EN4_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x110)))
#define NVIC_DIS0 (*((volatile NVIC_DIS_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x180)))
#define NVIC_DIS1 (*((volatile NVIC_DIS_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x184)))
#define NVIC_DIS2 (*((volatile NVIC_DIS_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x188)))
#define NVIC_DIS3 (*((volatile NVIC_DIS_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x18C)))
#define NVIC_DIS4 (*((volatile NVIC_DIS4_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x190)))
#define NVIC_PEND0 (*((volatile NVIC_PEND_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x200)))
#define NVIC_PEND1 (*((volatile NVIC_PEND_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x204)))
#define NVIC_PEND2 (*((volatile NVIC_PEND_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x208)))
#define NVIC_PEND3 (*((volatile NVIC_PEND_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x20C)))
#define NVIC_PEND4 (*((volatile NVIC_PEND4_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x210)))
#define NVIC_UNPEND0 (*((volatile NVIC_UNPEND_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x280)))
#define NVIC_UNPEND1 (*((volatile NVIC_UNPEND_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x284)))
#define NVIC_UNPEND2 (*((volatile NVIC_UNPEND_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x288)))
#define NVIC_UNPEND3 (*((volatile NVIC_UNPEND_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x28C)))
#define NVIC_UNPEND4 (*((volatile NVIC_UNPEND4_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0x290)))
/* this macro gets number of interrupt and return refrenced pointer to need PRI register*/
#define NVIC_PRI(x) (*((volatile uint32 *)(((((x / 4) * 4) + 0x400) + 0xE000E000))))
#define SCB_APINT   (*((volatile SCB_APINT_Type *)(CORTEX_M4_CORE_PERIPHERAL_BASE_ADDRESS + 0xD0C)))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

typedef struct
{
    uint32 B0 : 1;
    uint32 B1 : 1;
    uint32 B2 : 1;
    uint32 B3 : 1;
    uint32 B4 : 1;
    uint32 B5 : 1;
    uint32 B6 : 1;
    uint32 B7 : 1;
    uint32 B8 : 1;
    uint32 B9 : 1;
    uint32 B10 : 1;
    uint32 B11 : 1;
    uint32 B12 : 1;
    uint32 B13 : 1;
    uint32 B14 : 1;
    uint32 B15 : 1;
    uint32 B16 : 1;
    uint32 B17 : 1;
    uint32 B18 : 1;
    uint32 B19 : 1;
    uint32 B20 : 1;
    uint32 B21 : 1;
    uint32 B22 : 1;
    uint32 B23 : 1;
    uint32 B24 : 1;
    uint32 B25 : 1;
    uint32 B26 : 1;
    uint32 B27 : 1;
    uint32 B28 : 1;
    uint32 B29 : 1;
    uint32 B30 : 1;
    uint32 B31 : 1;
} Bit_Field_Type;

typedef union
{
    uint32 REG;
    Bit_Field_Type BF;
} NVIC_EN_Type;

typedef struct
{
    uint32 B0 : 1;
    uint32 B1 : 1;
    uint32 B2 : 1;
    uint32 B3 : 1;
    uint32 B4 : 1;
    uint32 B5 : 1;
    uint32 B6 : 1;
    uint32 B7 : 1;
    uint32 B8 : 1;
    uint32 B9 : 1;
    uint32 B10 : 1;
    uint32 : 0;
} NVIC_EN4_BF;

typedef union
{
    uint32 REG;
    NVIC_EN4_BF BF;
} NVIC_EN4_Type;

typedef union
{
    uint32 REG;
    Bit_Field_Type BF;
} NVIC_DIS_Type;

typedef struct
{
    uint32 B0 : 1;
    uint32 B1 : 1;
    uint32 B2 : 1;
    uint32 B3 : 1;
    uint32 B4 : 1;
    uint32 B5 : 1;
    uint32 B6 : 1;
    uint32 B7 : 1;
    uint32 B8 : 1;
    uint32 B9 : 1;
    uint32 B10 : 1;
    uint32 : 0;
} NVIC_DIS4_BF;

typedef union
{
    uint32 REG;
    NVIC_DIS4_BF BF;
} NVIC_DIS4_Type;

typedef union
{
    uint32 REG;
    Bit_Field_Type BF;
} NVIC_PEND_Type;

typedef struct
{
    uint32 B0 : 1;
    uint32 B1 : 1;
    uint32 B2 : 1;
    uint32 B3 : 1;
    uint32 B4 : 1;
    uint32 B5 : 1;
    uint32 B6 : 1;
    uint32 B7 : 1;
    uint32 B8 : 1;
    uint32 B9 : 1;
    uint32 B10 : 1;
    uint32 : 0;
} NVIC_PEND4_BF;

typedef union
{
    uint32 REG;
    NVIC_PEND4_BF BF;
} NVIC_PEND4_Type;

typedef union
{
    uint32 REG;
    Bit_Field_Type BF;
} NVIC_UNPEND_Type;

typedef struct
{
    uint32 B0 : 1;
    uint32 B1 : 1;
    uint32 B2 : 1;
    uint32 B3 : 1;
    uint32 B4 : 1;
    uint32 B5 : 1;
    uint32 B6 : 1;
    uint32 B7 : 1;
    uint32 B8 : 1;
    uint32 B9 : 1;
    uint32 B10 : 1;
    uint32 : 0;
} NVIC_UNPEND4_BF;

typedef union
{
    uint32 REG;
    NVIC_UNPEND4_BF BF;
} NVIC_UNPEND4_Type;

typedef struct
{
    uint32 VECTRESET : 1;
    uint32 VECTCLRACT : 1;
    uint32 SYSRESREQ : 1;
    uint32 RESERVED_00 : 5;
    uint32 PRIGROUP : 3;
    uint32 RESERVED_01 : 4;
    uint32 ENDIANESS : 1;
    uint32 VECTKEY : 16;
} SCB_APINT_BF;

typedef union
{
    uint32 REG;
    SCB_APINT_BF BF;
} SCB_APINT_Type;

#endif /* INTCTRL_REGS_H */
/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Regs.h
 *********************************************************************************************************************/
