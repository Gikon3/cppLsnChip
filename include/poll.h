#ifndef __poll_h
#define __poll_h

#include <stdint.h>
#include "cpp_lsn.h"

#define MAX_ERRORS  64

#define OPCODE_START            0xF0DAA000
#define OPCODE_BEGIN_MSG        0xF0DA0000
#define OPCODE_MEMORY0_5_POLL   0xF0DA0010
#define OPCODE_MEMORY0_A_POLL   0xF0DA0011
#define OPCODE_MEMORY1_5_POLL   0xF0DA0012
#define OPCODE_MEMORY1_A_POLL   0xF0DA0013
#define OPCODE_SPIQF_POLL       0xF0DA0020
#define OPCODE_UART0_POLL       0xF0DA0030
#define OPCODE_UART1_POLL       0xF0DA0040
#define OPCODE_I2CM_POLL        0xF0DA0050
#define OPCODE_SPOD_POLL        0xF0DA0060
#define OPCODE_END_MSG          0xF0DA0EFF

typedef struct __CheckBlock {
    uint32_t count_errors;
    uint32_t addr_array[MAX_ERRORS];
    uint32_t error_array[MAX_ERRORS];
} CheckBlock;

void poll_en(void);
void poll_dis(void);
uint8_t poll_get_fl(void);
void poll_tx_log(CheckBlock *check, uint32_t blockId);
void poll_add_word(CheckBlock *check, uint32_t addr, uint32_t data);

#endif
