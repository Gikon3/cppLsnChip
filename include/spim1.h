#ifndef __spim1_h
#define __spim1_h

#include <stdint.h>
#include "cpp_lsn.h"

typedef struct __Spim1Map {
    volatile uint32_t PRESC;
    volatile uint32_t CONF;
    volatile uint32_t :32;
    volatile uint32_t :32;
    volatile uint32_t :32;
    volatile uint32_t :32;
    volatile uint32_t TXD;
    volatile uint32_t LBM;
    volatile uint32_t RUN;
    volatile uint32_t RXD;
    volatile uint32_t TXED;
    volatile uint32_t RXRD;
    volatile uint32_t FL;
    volatile uint32_t RDY;
} Spim1Map;

typedef struct __Spim1 {
    uint8_t sck;
    uint8_t cpha;
    uint8_t cpol;
    uint8_t wl;
    uint8_t cs_mode;
} Spim1;

#define SPIM1_M ((Spim1Map *)MP_SPIM1_BASE)

#define SPIM1_PRESC_1   0
#define SPIM1_PRESC_2   1
#define SPIM1_PRESC_4   2
#define SPIM1_PRESC_8   3

#define SPIM1_SCK_1     0
#define SPIM1_SCK_2     1
#define SPIM1_SCK_4     2
#define SPIM1_SCK_5     3
#define SPIM1_SCK_8     4
#define SPIM1_SCK_10    5
#define SPIM1_SCK_16    6
#define SPIM1_SCK_20    7
#define SPIM1_SCK_32    8
#define SPIM1_SCK_40    9
#define SPIM1_SCK_64    10
#define SPIM1_SCK_80    11
#define SPIM1_SCK_128   12
#define SPIM1_SCK_160   13
#define SPIM1_SCK_320   14
#define SPIM1_SCK_640   15

#define SPIM1_WL_8B     0
#define SPIM1_WL_16B    1
#define SPIM1_WL_24B    2
#define SPIM1_WL_32B    3

#define SPIM1_SS_WORD   0
#define SPIM1_SS_PACK   1

#define SPIM1_LBM_USUAL 0
#define SPIM1_LBM_TEST  1

#define SPIM1_RUN_GO        7
#define SPIM1_RUN_TX_CLR    4
#define SPIM1_RUN_RX_CLR    2

void spim1_init(Spim1 *spim);
void spim1_config(Spim1 *spim);
uint32_t spim1_txrx(uint32_t data);

#endif
