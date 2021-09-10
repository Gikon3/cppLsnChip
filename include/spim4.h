#ifndef __spim4_h
#define __spim4_h

#include <stdint.h>
#include "cpp_lsn.h"

typedef struct __Spim4Map {
    volatile uint32_t PRESC;
    volatile uint32_t CONF[4];
    volatile uint32_t SS;
    volatile uint32_t TXD;
    volatile uint32_t LBM;
    volatile uint32_t RUN;
    volatile uint32_t RXD;
    volatile uint32_t TXED;
    volatile uint32_t RXRD;
    volatile uint32_t FL;
    volatile uint32_t RDY;
} Spim4Map;

typedef struct
{
    uint8_t ch_sel;
    
    uint8_t sck;
    uint8_t cpha;
    uint8_t cpol;
    uint8_t wl;
    uint8_t cs_mode;
} Spim4ChInit;

#define SPIM4_M ((Spim4Map *)MP_SPIM4_BASE)

#define SPIM4_PRESC_1   0
#define SPIM4_PRESC_2   1
#define SPIM4_PRESC_4   2
#define SPIM4_PRESC_8   3

#define SPIM4_SCK_1     0
#define SPIM4_SCK_2     1
#define SPIM4_SCK_4     2
#define SPIM4_SCK_5     3
#define SPIM4_SCK_8     4
#define SPIM4_SCK_10    5
#define SPIM4_SCK_16    6
#define SPIM4_SCK_20    7
#define SPIM4_SCK_32    8
#define SPIM4_SCK_40    9
#define SPIM4_SCK_64    10
#define SPIM4_SCK_80    11
#define SPIM4_SCK_128   12
#define SPIM4_SCK_160   13
#define SPIM4_SCK_320   14
#define SPIM4_SCK_640   15

#define SPIM4_WL_8B     0
#define SPIM4_WL_16B    1
#define SPIM4_WL_24B    2
#define SPIM4_WL_32B    3

#define SPIM4_SS_WORD   0
#define SPIM4_SS_PACK   1

#define SPIM4_LBM_USUAL 0
#define SPIM4_LBM_TEST  1

#define SPIM4_RUN_GO        7
#define SPIM4_RUN_TX_CLR    4
#define SPIM4_RUN_RX_CLR    2

void spim4ChInit(Spim4ChInit *ch_param, uint8_t ch_sel);
void spim4Conf(Spim4ChInit *ch_param);
uint32_t spim4TxRx(uint32_t data);

#endif
