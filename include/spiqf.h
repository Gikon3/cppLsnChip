#ifndef __spiqf_h
#define __spiqf_h

#include <stdint.h>
#include "cpp_lsn.h"

typedef struct __SpiqfMap {
    volatile uint32_t CONF;
    volatile uint32_t CW1;
    volatile uint32_t CW2;
    volatile uint32_t TS;
    volatile uint32_t WP;
    volatile uint32_t RUN;
    volatile uint32_t TXD;
    volatile uint32_t RXD;
    volatile uint32_t TXF;
    volatile uint32_t RXF;
    volatile uint32_t FL;
    volatile uint32_t RDY;
} SpiqfMap;

#define SPIQF_M ((SpiqfMap *)MP_SPIQF_BASE)

#endif
