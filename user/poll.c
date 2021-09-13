#include "main.h"
#include "poll.h"
#include "spim1.h"

static uint8_t pollFl = 0;

void poll_init()
{
    pollFl = 0;
}

void poll_en()
{
    pollFl = 1;
}

void poll_dis()
{
    pollFl = 0;
}

uint8_t poll_get_fl()
{
    return pollFl;
}

void poll_tx_log(CheckBlock *check, uint32_t blockId)
{
    spim1_txrx(OPCODE_BEGIN_MSG);
    spim1_txrx(blockId);
    spim1_txrx(check->count_errors);
    uint32_t crc = OPCODE_BEGIN_MSG ^ blockId ^ check->count_errors;
    uint32_t num_cycles = check->count_errors < MAX_ERRORS ? check->count_errors: MAX_ERRORS;
    for (uint32_t i = 0; i < num_cycles; ++ i) {
        spim1_txrx(check->addr_array[i]);
        spim1_txrx(check->error_array[i]);
        crc ^= check->addr_array[i];
        crc ^= check->error_array[i];
    }
    spim1_txrx(crc); /* hash */
    spim1_txrx(OPCODE_END_MSG);
}

void poll_add_word(CheckBlock *check, uint32_t addr, uint32_t data)
{
    if (check->count_errors < MAX_ERRORS) {
        check->addr_array[check->count_errors] = addr;
        check->error_array[check->count_errors] = data;  
    }
    ++check->count_errors;
}
