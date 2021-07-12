;/**************************************************************************//**
; * @file     startup_cppLsn.s
; * @brief    CMSIS Cortex-M# Core Device Startup File for
; *           Device cppLsn
; * @version  V3.01
; * @date     06. March 2012
; *
; * @note
; * Copyright (C) 2012 ARM Limited. All rights reserved.
; *
; * @par
; * ARM Limited (ARM) is supplying this software for use with Cortex-M
; * processor based microcontrollers.  This file can be freely distributed
; * within development tools that are supporting such ARM based processors.
; *
; * @par
; * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
; * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
; * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
; * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
; * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
; *
; ******************************************************************************/
;/*
;//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
;*/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000100

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY

                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     MemManage_Handler         ; MPU Fault Handler
                DCD     BusFault_Handler          ; Bus Fault Handler
                DCD     UsageFault_Handler        ; Usage Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     DebugMon_Handler          ; Debug Monitor Handler
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                DCD     TMR0_IRQHandler
                DCD     TMR1_IRQHandler
                DCD     UART0_IRQHandler
                DCD     UART1_IRQHandler
                DCD     SPIQF_IRQHandler
                DCD     I2CM_IRQHandler
                DCD     SPIM4_IRQHandler
                DCD     GPIO_IRQHandler
                DCD     SPIM1_IRQHandler
                DCD     EXT_IRQHandler

                ; External Interrupts
; ToDo:  Add here the vectors for the device specific external interrupts handler
;                DCD     <DeviceInterrupt>_IRQHandler       ;  0: Default
__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY


; Reset Handler
Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  main
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PendSV_Handler\
                PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler\
                PROC
                EXPORT  SysTick_Handler           [WEAK]
                ;IMPORT caliber
                ;	LDR   R1, =0xE000E018
                ;	LDR   R1, [R1]
                ;	LDR   R0, =caliber
                ;	STR   R1, [R0]
                ;	BX    LR
                B       .
                ENDP

Default_Handler PROC

                ENDP

; ToDo:  Add here the export definition for the device specific external interrupts handler
;                EXPORT  <DeviceInterrupt>_IRQHandler         [WEAK]

; ToDo:  Add here the names for the device specific external interrupts handler
;<DeviceInterrupt>_IRQHandler
;                B       .
;                ENDP

TMR0_IRQHandler	    PROC
                    EXPORT  TMR0_IRQHandler         [WEAK]
                    B       .
                    ENDP

TMR1_IRQHandler     PROC
                    EXPORT  TMR1_IRQHandler         [WEAK]
                    B       .
                    ENDP

UART0_IRQHandler    PROC
                    EXPORT  UART0_IRQHandler        [WEAK]
                    B       .
                    ENDP

UART1_IRQHandler    PROC
                    EXPORT  UART1_IRQHandler        [WEAK]
                    B       .
                    ENDP

SPIQF_IRQHandler    PROC
                    EXPORT  SPIQF_IRQHandler        [WEAK]
                    B       .
                    ENDP

I2CM_IRQHandler     PROC
                    EXPORT  I2CM_IRQHandler         [WEAK]
                    B       .
                    ENDP

SPIM4_IRQHandler    PROC
                    EXPORT  SPIM4_IRQHandler        [WEAK]
                    B       .
                    ENDP

GPIO_IRQHandler     PROC
                    EXPORT  GPIO_IRQHandler         [WEAK]
                    B       .
                    ENDP

SPIM1_IRQHandler    PROC
                    EXPORT  SPIM1_IRQHandler        [WEAK]
                    B       .
                    ENDP

EXT_IRQHandler      PROC
                    EXPORT  EXT_IRQHandler          [WEAK]
                    B       .
                    ENDP

                    ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap PROC
                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR
                ENDP

                ALIGN

                ENDIF


                END
