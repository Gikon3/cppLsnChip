#include "cpp_lsn.h"
#include "main.h"
#include "tmr.h"
#include "gpio.h"
#include "spim1.h"
#include "poll.h"
#include "memory_poll.h"
#include "periph_poll.h"

int main() {
    SystemInit();

    gpioConf();
    
    Spim1 spim1;
    spim1_init(&spim1);
    spim1_config(&spim1);
    spim1_txrx(OPCODE_START);
    NVIC_EnableIRQ(TMR1_IRQn);
    tmr1Config(1000);
    tmr1En();
    
    while(1) {
        if(poll_get_fl()) {
            poll_dis();
            memoryPoll();
            periphPoll();
        }
    }
}
