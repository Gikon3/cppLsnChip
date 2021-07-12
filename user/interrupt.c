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
    tmr0En();
}

void TMR1_IRQHandler()
{
    poll_en();
    tmr1En();
}

void EXT_IRQHandler()
{
}
