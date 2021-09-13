#include "cpp_lsn.h"
#include "main.h"
#include "cg.h"
#include "tmr.h"
#include "gpio.h"
#include "spim1.h"
#include "spim4.h"
#include "poll.h"
#include "memory_poll.h"
#include "periph_poll.h"

int main() {
    SystemInit();
    
    cg_config(1E8);
    gpio_config();
    
    Spim1 spim1;
    spim1_init(&spim1);
    spim1_config(&spim1);
    spim1_txrx(OPCODE_START);
    NVIC_EnableIRQ(TMR1_IRQn);
    tmr1_config(100);
    tmr1_on();
    
    poll_init();
    memory_poll_init();
    periph_poll_init();
    while(1) {
        if(poll_get_fl()) {
            poll_dis();
            memoryPoll();
            periphPoll();
        }
    }
}
