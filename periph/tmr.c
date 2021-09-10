#include "main.h"
#include "tmr.h"
#include "cg.h"

void tmr0_config(float ms)
{
    tmr0_off();
    TMR_M->TMR0PER = (uint32_t)(cg_get_frq() / 1000.0 * ms);
    tmr0_on();
}

void tmr0_on()
{
    TMR_M->TMR0EN = 1;
}

void tmr0_off()
{
    TMR_M->TMR0EN = 0;
}

void tmr1_config(float ms)
{
    tmr1_off();
    TMR_M->TMR1PER = (uint32_t)(cg_get_frq() / 1000.0 * ms);
}

void tmr1_on()
{
    TMR_M->TMR1EN = 1;
}

void tmr1_off()
{
    TMR_M->TMR1EN = 0;
}

uint32_t tmr1_state()
{
    return TMR_M->TMR1STAT;
}
