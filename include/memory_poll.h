#ifndef __memory_poll_h
#define __memory_poll_h

#include <stdint.h>
#include "cpp_lsn.h"
#include "poll.h"

#define ARRAY_SIZE  32000
#define PATTERN_5   0x55555555
#define PATTERN_A   0xAAAAAAAA

void memory_poll_init(void);
void memoryPoll(void);
void memoryRead(uint32_t pattern, CheckBlock *check);
void memoryWrite(uint32_t pattern);
int memoryGetParityCycle(void);
void memoryParitySwap(void);
uint32_t memoryGetPat(void);
uint32_t memoryGetCorrectPat5(void);
uint32_t memoryGetCorrectPatA(void);
uint32_t memory0_opcode(void);
uint32_t memory1_opcode(void);

#endif
