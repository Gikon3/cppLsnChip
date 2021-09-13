#include "main.h"
#include "spim1.h"
#include "poll.h"
#include "memory_poll.h"

static uint32_t pattern0_5 = PATTERN_5;
static uint32_t pattern1_5 = PATTERN_5;
static uint32_t pattern2_5 = PATTERN_5;
static uint32_t pattern0_A = PATTERN_A;
static uint32_t pattern1_A = PATTERN_A;
static uint32_t pattern2_A = PATTERN_A;

static uint8_t initFl = 0;
static uint8_t f_parity0 = 0;
static uint8_t f_parity1 = 0;
static uint8_t f_parity2 = 0;
static uint32_t ARRAY[ARRAY_SIZE];

void memory_poll_init()
{
    pattern0_5 = PATTERN_5;
    pattern1_5 = PATTERN_5;
    pattern2_5 = PATTERN_5;
    pattern0_A = PATTERN_A;
    pattern1_A = PATTERN_A;
    pattern2_A = PATTERN_A;
    
    initFl = 0;
    f_parity0 = 0;
    f_parity1 = 0;
    f_parity2 = 0;
}

void memoryPoll() {
    CheckBlock check;
    check.count_errors = 0;
    
    if (initFl) {
        memoryRead(memoryGetPat(), &check);
        poll_tx_log(&check, memory0_opcode());
        check.count_errors = 0;
        memoryParitySwap();
    }
    initFl = 0xFF;
    
    memoryWrite(memoryGetPat());
#   if (MEMORY_TEST == 1)
    mem_insert_errors();
#   endif
    memoryRead(memoryGetPat(), &check);
    
    poll_tx_log(&check, memory1_opcode());
}

void memoryRead(uint32_t pattern, CheckBlock *check) {
    for(uint32_t i = 0; i < ARRAY_SIZE; ++ i) {
        if(ARRAY[i] != pattern) {
            poll_add_word(check, (uint32_t)&ARRAY[i], ARRAY[i]);
        }
    }
}

void memoryWrite(uint32_t pattern) {
    for(uint32_t i = 0; i < ARRAY_SIZE; ++ i) {
        ARRAY[i] = pattern;
    }
}

int memoryGetParityCycle() {
    return f_parity0 & f_parity1 & f_parity2;
}

void memoryParitySwap() {
    if(memoryGetParityCycle()) {
        f_parity0 = 0;
        f_parity1 = 0;
        f_parity2 = 0;
    }
    else {
        f_parity0 = 0xFF;
        f_parity1 = 0xFF;
        f_parity2 = 0xFF;
    }
}

uint32_t memoryGetPat() {
    if(memoryGetParityCycle()) {
        return memoryGetCorrectPatA();
    }
    return memoryGetCorrectPat5();
}

uint32_t memoryGetCorrectPat5() {
    if(pattern0_5 == pattern1_5 || pattern1_5 == pattern2_5) {
        pattern0_5 = pattern1_5;
        pattern2_5 = pattern1_5;
        return pattern2_5;
    }
    if(pattern0_5 == pattern2_5) {
        pattern1_5 = pattern0_5;
        return pattern1_5;
    }
    return PATTERN_5;
}

uint32_t memoryGetCorrectPatA() {
    if(pattern0_A == pattern1_A || pattern1_A == pattern2_A) {
        pattern0_A = pattern1_A;
        pattern2_A = pattern1_A;
        return pattern2_A;
    }
    if(pattern0_A == pattern2_A) {
        pattern1_A = pattern0_A;
        return pattern1_A;
    }
    return PATTERN_A;
}

uint32_t memory0_opcode()
{
    if (memoryGetParityCycle()) return OPCODE_MEMORY0_A_POLL;
    else return OPCODE_MEMORY0_5_POLL;
}

uint32_t memory1_opcode()
{
    if (memoryGetParityCycle()) return OPCODE_MEMORY1_A_POLL;
    else return OPCODE_MEMORY1_5_POLL;
}

#if (MEMORY_TEST == 1)
void mem_insert_errors()
{
    for (unsigned int i = 0; i < 100; ++i) {
        ARRAY[i*30] = 0x11111111;
    }
}
#endif
