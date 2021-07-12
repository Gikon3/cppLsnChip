#ifndef __uart_h
#define __uart_h

#include <stdint.h>
#include "cpp_lsn.h"

typedef struct __UartMap {
    volatile uint32_t BRT;
    volatile uint32_t TXPRM;
    volatile uint32_t TXCONF;
    volatile uint32_t TXD;
    volatile uint32_t TXFL;
    volatile uint32_t :32;
    volatile uint32_t :32;
    volatile uint32_t :32;
    volatile uint32_t BRR;
    volatile uint32_t RXPRM;
    volatile uint32_t RXCONF;
    volatile uint32_t RXD;
    volatile uint32_t RXFL;
    volatile uint32_t :32;
    volatile uint32_t CONF;
} UartMap;

#define UART0_M ((UartMap *)MP_UART0_BASE)
#define UART1_M ((UartMap *)MP_UART1_BASE)

#endif
