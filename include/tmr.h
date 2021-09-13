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

void tmr0_config(float ms);
void tmr0_on(void);
void tmr0_off(void);
void tmr1_config(float ms);
void tmr1_on(void);
void tmr1_off(void);
uint32_t tmr1_state(void);

#endif
