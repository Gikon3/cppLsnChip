#include "main.h"
#include "spim1.h"
#include "rc.h"

void spim1_init(Spim1 *spim)
{
    spim->sck = SPIM1_SCK_1;
    spim->cpha = 0;
    spim->cpol = 0;
    spim->wl = SPIM1_WL_32B;
    spim->cs_mode = SPIM1_SS_PACK;
}

void spim1_config(Spim1 *spim)
{
    SPIM1_M->PRESC = SPIM1_PRESC_1;
    uint32_t tmp;
    tmp = spim->sck & 0xF;
    tmp |= (spim->cpha & 1) << 4;
    tmp |= (spim->cpol & 1) << 5;
    tmp |= (spim->wl & 3) << 6;
    tmp |= (spim->cs_mode & 1) << 8;
    SPIM1_M->CONF = tmp;
    SPIM1_M->LBM = SPIM1_LBM_USUAL;
    
    rc_ctrl(perSpim1, rstUnreset);
}

uint32_t spim1_txrx(uint32_t data)
{
    while(!(SPIM1_M->FL & 1) && SPIM1_M->TXED < 3);
    SPIM1_M->RUN = SPIM1_RUN_RX_CLR;
//    uint32_t reverseData = data << 24 | (data & 0xFF00) << 8
//        | (data & 0xFF0000) >> 8 | (data & 0xFF000000) >> 24;
    SPIM1_M->TXD = data;
    SPIM1_M->RUN = SPIM1_RUN_GO;
    while(!SPIM1_M->RDY);
    return SPIM1_M->RXD;
}
