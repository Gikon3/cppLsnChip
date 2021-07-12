/**************************************************************************//**
 * @file     cpp_lsn.h
 * @brief    CMSIS Cortex-M# Core Peripheral Access Layer Header File for
 *           Device cppLsn
 * @version  V3.01
 * @date     06. March 2012
 *
 * @note
 * Copyright (C) 2010-2012 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/


#ifndef DT_CPP_LSN_H
#define DT_CPP_LSN_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* ToDo: replace '<Device>' with your device name; add your doxyGen comment   */
/** @addtogroup cppLsn_Definitions cppLsn Definitions
  This file defines all structures and symbols for cppLsn:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - Peripheral definitions
  @{
*/


/******************************************************************************/
/*                Processor and Core Peripherals                              */
/******************************************************************************/
/** @addtogroup cppLsn_CMSIS Device CMSIS Definitions
  Configuration of the Cortex-M# Processor and Core Peripherals
  @{
*/

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */

typedef enum IRQn
{
/******  Cortex-M# Processor Exceptions Numbers ***************************************************/

/* ToDo: use this Cortex interrupt numbers if your device is a CORTEX-M3 / Cortex-M4 device       */
  NonMaskableInt_IRQn           = -14,      /*!<  2 Non Maskable Interrupt                        */
  MemoryManagement_IRQn         = -12,      /*!<  4 Memory Management Interrupt                   */
  BusFault_IRQn                 = -11,      /*!<  5 Bus Fault Interrupt                           */
  UsageFault_IRQn               = -10,      /*!<  6 Usage Fault Interrupt                         */
  SVCall_IRQn                   = -5,       /*!< 11 SV Call Interrupt                             */
  DebugMonitor_IRQn             = -4,       /*!< 12 Debug Monitor Interrupt                       */
  PendSV_IRQn                   = -2,       /*!< 14 Pend SV Interrupt                             */
  SysTick_IRQn                  = -1,       /*!< 15 System Tick Interrupt                         */

/******  Device Specific Interrupt Numbers ********************************************************/
/* ToDo: add here your device specific external interrupt numbers
         according the interrupt handlers defined in startup_Device.s
         eg.: Interrupt for Timer#1       TIM1_IRQHandler   ->   TIM1_IRQn                        */ 
               TMR0_IRQn        = 0,
               TMR1_IRQn        = 1,       
              UART0_IRQn        = 2,
              UART1_IRQn        = 3,
              SPIQF_IRQn        = 4,
               I2CM_IRQn        = 5,
              SPIM4_IRQn        = 6,
               GPIO_IRQn        = 7,
              SPIM1_IRQn        = 8,
                EXT_IRQn        = 9
} IRQn_Type;


/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M# Processor and Core Peripherals */
/* ToDo: set the defines according your Device                                                    */
/* ToDo: define the correct core revision
         __CM0_REV if your device is a CORTEX-M0 device
         __CM3_REV if your device is a CORTEX-M3 device
         __CM4_REV if your device is a CORTEX-M4 device                                           */
#define __CM3_REV                 0x0201    /*!< Core Revision r2p1                               */
#define __NVIC_PRIO_BITS          2         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used     */
#define __MPU_PRESENT             1         /*!< MPU present or not                               */
/* ToDo: define __FPU_PRESENT if your devise is a CORTEX-M4                                       */
#define __FPU_PRESENT             0        /*!< FPU present or not                                */

/*@}*/ /* end of group cppLsn_CMSIS */


/* ToDo: include the correct core_cm#.h file
         core_cm0.h if your device is a CORTEX-M0 device
         core_cm3.h if your device is a CORTEX-M3 device
         core_cm4.h if your device is a CORTEX-M4 device                                          */
#include <core_cm3.h>                       /* Cortex-M3 processor and core peripherals           */
/* ToDo: include your system_<Device>.h file
         replace 'cppLsn' with your device name                                                 */
#include "system_cpp_lsn.h"                /* cppLsn System  include file                      */


/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/
/** @addtogroup cppLsn_Peripherals cppLsn Peripherals
  <Device> Device Specific Peripheral registers structures
  @{
*/

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/* ToDo: add here your device specific peripheral access structure typedefs
         following is an example for a timer                                  */

/*------------- 16-bit Timer/Event Counter (TMR) -----------------------------*/
/** @addtogroup cppLsn_TMR cppLsn 16-bit Timer/Event Counter (TMR)
  @{
*/

//typedef struct
//{
//  __IO uint32_t EN;                         /*!< Offset: 0x0000   Timer Enable Register           */               
//  __IO uint32_t RUN;                        /*!< Offset: 0x0004   Timer RUN Register              */
//  __IO uint32_t CR;                         /*!< Offset: 0x0008   Timer Control Register          */
//  __IO uint32_t MOD;                        /*!< Offset: 0x000C   Timer Mode Register             */
//       uint32_t RESERVED0[1];
//  __IO uint32_t ST;                         /*!< Offset: 0x0014   Timer Status Register           */
//  __IO uint32_t IM;                         /*!< Offset: 0x0018   Interrupt Mask Register         */
//  __IO uint32_t UC;                         /*!< Offset: 0x001C   Timer Up Counter Register       */
//  __IO uint32_t RG0                         /*!< Offset: 0x0020   Timer Register                  */
//       uint32_t RESERVED1[2];
//  __IO uint32_t CP;                         /*!< Offset: 0x002C   Capture register                */
//} MP_TMR_TypeDef;

/*@}*/ /* end of group <Device>_TMR */


#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

/*@}*/ /* end of group <Device>_Peripherals */


/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/* ToDo: add here your device peripherals base addresses                
         following is an example for timer                                    */
/** @addtogroup cppLsn_MemoryMap cppLsn Memory Mapping
  @{
*/

/* Peripheral and SRAM base address */
#define MP_BOOT_BASE        (0x00000000UL)             /*!< (BOOTROM   ) Base Address */
#define MP_SRAM_BASE        (0x10000000UL)             /*!< (SRAM      ) Base Address */
#define MP_PERIPH_BASE      (0x4000C000UL)             /*!< (Peripheral) Base Address */
#define MP_SPOD_BASE        (0x40000000UL)             /*!< (SPOD      ) Base Address */
#define MP_FLASH_BASE       (0x60000000UL)             /*!< (FLASH     ) Base Address */

/* Peripheral memory map */
#define MP_EMIF_BASE          (MP_PERIPH_BASE + 0x0580)  /*!<(EMIF     )  Base Address */     
#define MP_Misc_BASE          (MP_PERIPH_BASE + 0x0540)  /*!<(Misc     )  Base Address */   
#define MP_I2CS_BASE          (MP_PERIPH_BASE + 0x0500)  /*!<(I2CS     )  Base Address */   
#define MP_I2CM_BASE          (MP_PERIPH_BASE + 0x04C0)  /*!<(I2CM     )  Base Address */   
#define MP_UART1_BASE         (MP_PERIPH_BASE + 0x0380)  /*!<(UART1    )  Base Address */   
#define MP_UART0_BASE         (MP_PERIPH_BASE + 0x0340)  /*!<(UART0    )  Base Address */   
#define MP_SPIQF_BASE         (MP_PERIPH_BASE + 0x0300)  /*!<(SPIQF    )  Base Address */   
#define MP_SPIM1_BASE         (MP_PERIPH_BASE + 0x02C0)  /*!<(SPIM1    )  Base Address */   
#define MP_SPIM4_BASE         (MP_PERIPH_BASE + 0x0280)  /*!<(SPIM4    )  Base Address */   
#define MP_GPIO_BASE          (MP_PERIPH_BASE + 0x0200)  /*!<(GPIO     )  Base Address */   
#define MP_Timers_BASE        (MP_PERIPH_BASE + 0x0180)  /*!<(Timers   )  Base Address */   
#define MP_CG_BASE            (MP_PERIPH_BASE + 0x0140)  /*!<(Clocks Generator)  Base Address */   
#define MP_RC_BASE            (MP_PERIPH_BASE + 0x0100)  /*!<(Reset Controller)  Base Address */   
#define MP_TSM_BASE           (MP_PERIPH_BASE + 0x00C0)  /*!<(TSM             )  Base Address */   
#define MP_RTC_BASE           (MP_PERIPH_BASE + 0x0080)  /*!<(RTC             )  Base Address */    

/*@}*/ /* end of group cppLsn_MemoryMap */


#define REG(addr) (*(volatile unsigned int *)(addr))

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
/* ToDo: add here your device peripherals pointer definitions                
         following is an example for timer                                    */

/** @addtogroup cppLsn_PeripheralDecl cppLsn Peripheral Declaration
  @{
*/

//#define MP_TIM0        ((MP_TMR_TypeDef *) MP_TIM0_BASE)
//#define MP_TIM1        ((MP_TMR_TypeDef *) MP_TIM1_BASE)
//#define MP_TIM2        ((MP_TMR_TypeDef *) MP_TIM2_BASE)
/*@}*/ /* end of group cppLsn_PeripheralDecl */

/*@}*/ /* end of group cppLsn_Definitions */

#ifdef __cplusplus
}
#endif

#endif  /* CPP_LSN_H */
