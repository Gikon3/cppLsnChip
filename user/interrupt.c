#include "cpp_lsn.h"
#include "main.h"
#include "poll.h"
#include "tmr.h"

void HardFault_Handler()
{
    while(1);
}

void BusFault_Handler()
{
    while(1);
}

void TMR0_IRQHandler()
{
    poll_en();
    tmr0_on();
}

void TMR1_IRQHandler()
{
    poll_en();
    tmr1_on();
}

void EXT_IRQHandler()
{
}
