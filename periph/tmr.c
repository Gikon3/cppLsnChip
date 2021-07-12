#include "main.h"
#include "tmr.h"

void tmr0Config(float ms) {
    tmr0Dis();
    TMR_M->TMR0PER = (uint32_t)(HSE / 1000 * ms);
    tmr0En();
}

void tmr0En() {
    TMR_M->TMR0EN = 1;
}

void tmr0Dis()
{
    TMR_M->TMR0EN = 0;
}

void tmr1Config(float ms)
{
    tmr1Dis();
    TMR_M->TMR1PER = (uint32_t)(HSE / 1000 * ms);
}

void tmr1En()
{
    TMR_M->TMR1EN = 1;
}

void tmr1Dis()
{
    TMR_M->TMR1EN = 0;
}

float tmr1State()
{
    return TMR_M->TMR1STAT;
}
