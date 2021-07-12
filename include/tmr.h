#ifndef __tmr_h
#define __tmr_h

#include <stdint.h>
#include "cpp_lsn.h"

typedef struct __TmrMap {
    volatile uint32_t TMR0EN;
    volatile uint32_t TMR0PER;
    volatile uint32_t TMR1EN;
    volatile uint32_t TMR1PER;
    volatile uint32_t TMR1STAT;
} TmrMap;

#define TMR_M ((TmrMap *)MP_Timers_BASE)

void tmr0Config(float ms);
void tmr0En(void);
void tmr0Dis(void);
void tmr1Config(float ms);
void tmr1En(void);
void tmr1Dis(void);
float tmr1State(void);

#endif
