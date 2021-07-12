#ifndef __spod_h
#define __spod_h

#include <stdint.h>
#include "cpp_lsn.h"

typedef struct __SpodMap {
    volatile uint32_t RUN;
    volatile uint32_t SCALE;
    volatile uint32_t CTRL;
    volatile uint32_t FL;
    volatile uint32_t ETH;
    volatile uint32_t ETHSH;
    volatile uint32_t ACF;
    volatile uint32_t :32;
    volatile uint32_t :32;
    volatile uint32_t ETHB[25];
    volatile uint32_t :32;
    volatile uint32_t :32;
    volatile uint32_t BUFF[512];
} SpodMap;

#define SPOD_M ((SpodMap *)MP_SPOD_BASE)

#endif
