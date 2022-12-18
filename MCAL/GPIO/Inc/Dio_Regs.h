/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Dio_Regs.h
 *  Module:  	  Dio_Regs
 *
 *  Description:  Header file for Dio Register Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  18/12/2022
 *********************************************************************************************************************/
#ifndef DIO_REGS_H
#define DIO_REGS_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*
GPIO Port A (APB) base: 0x4000.4000
GPIO Port B (APB) base: 0x4000.5000
GPIO Port C (APB) base: 0x4000.6000
GPIO Port D (APB) base: 0x4000.7000
GPIO Port E (APB) base: 0x4002.4000
GPIO Port F (APB) base: 0x4002.5000
*/
/* Macros to reflect Port Alphabet to number*/
#define A   0
#define B   1
#define C   2
#define D   3
#define E   4
#define F   5

/* Macro to calculate base address on Advance peripheral Bus APB for each port*/
#define GPIO_PORTS_ADDRESS(x)  (x<E?((x*0x1000)+(0x40004000)):((x*0x1000)+(0x40020000)))

/* Macros for Register offsets*/
#define GPIODATA_OFFSET     0x000
#define GPIODIR_OFFSET      0x400
#define GPIOAFSEL_OFFSET    0x420
#define GPIODR2R_OFFSET     0x500
#define GPIODR4R_OFFSET     0x504
#define GPIODR8R_OFFSET     0x508
#define GPIOODR_OFFSET      0x50C
#define GPIOPUR_OFFSET      0x510
#define GPIOPDR_OFFSET      0x514
#define GPIOSLR_OFFSET      0x518
#define GPIODEN_OFFSET      0x51C
#define GPIOLOCK_OFFSET     0x520
#define GPIOCR_OFFSET       0x524
#define GPIOAMSEL_OFFSET    0x528
#define GPIOPCTL_OFFSET     0x52C

/* Macros for Register Mapping. note--> didn't map all register by software*/
#define GPIODATA(x)     (*((volatile uint32 *)(GPIO_PORTS_ADDRESS(x)+GPIODATA_OFFSET)))
#define GPIODIR(x)      (*((volatile uint32 *)(GPIO_PORTS_ADDRESS(x)+GPIODIR_OFFSET)))
#define GPIOAFSEL(x)    (*((volatile uint32 *)(GPIO_PORTS_ADDRESS(x)+GPIOAFSEL_OFFSET)))
#define GPIODR2R(x)     (*((volatile uint32 *)(GPIO_PORTS_ADDRESS(x)+GPIODR2R_OFFSET)))
#define GPIODR4R(x)     (*((volatile uint32 *)(GPIO_PORTS_ADDRESS(x)+GPIODR4R_OFFSET)))
#define GPIODR8R(x)     (*((volatile uint32 *)(GPIO_PORTS_ADDRESS(x)+GPIODR8R_OFFSET)))
#define GPIOODR(x)      (*((volatile uint32 *)(GPIO_PORTS_ADDRESS(x)+GPIOODR_OFFSET)))
#define GPIOPUR(x)      (*((volatile uint32 *)(GPIO_PORTS_ADDRESS(x)+GPIOPUR_OFFSET)))
#define GPIOPDR(x)      (*((volatile uint32 *)(GPIO_PORTS_ADDRESS(x)+GPIOPDR_OFFSET)))
#define GPIOSLR(x)      (*((volatile uint32 *)(GPIO_PORTS_ADDRESS(x)+GPIOSLR_OFFSET)))
#define GPIODEN(x)      (*((volatile uint32 *)(GPIO_PORTS_ADDRESS(x)+GPIODEN_OFFSET)))
#define GPIOLOCK(x)     (*((volatile uint32 *)(GPIO_PORTS_ADDRESS(x)+GPIOLOCK_OFFSET)))
#define GPIOCR(x)       (*((volatile uint32 *)(GPIO_PORTS_ADDRESS(x)+GPIOCR_OFFSET)))
#define GPIOAMSEL(x)    (*((volatile uint32 *)(GPIO_PORTS_ADDRESS(x)+GPIOAMSEL_OFFSET)))
#define GPIOPCTL(x)     (*((volatile uint32 *)(GPIO_PORTS_ADDRESS(x)+GPIOPCTL_OFFSET)))


#endif /* DIO_REGS_H*/
/**********************************************************************************************************************
 *  END OF FILE: Dio_Regs.h
 *********************************************************************************************************************/
