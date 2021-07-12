#include "main.h"
#include "spim4.h"
#include "rc.h"

void spim4ChInit(Spim4ChInit *ch_param, uint8_t ch_sel) {
    ch_param->ch_sel = ch_sel;
    ch_param->sck = SPIM4_SCK_1;
    ch_param->cpha = 0;
    ch_param->cpol = 0;
    ch_param->wl = SPIM4_WL_32B;
    ch_param->cs_mode = SPIM4_SS_WORD;
}

void spim4Conf(Spim4ChInit *ch_param) {
    SPIM4_M->PRESC = SPIM4_PRESC_1;
    uint32_t tmp;
    tmp = ch_param->sck & 0xF;
    tmp |= (ch_param->cpha & 1) << 4;
    tmp |= (ch_param->cpol & 1) << 5;
    tmp |= (ch_param->wl & 3) << 6;
    tmp |= (ch_param->cs_mode & 1) << 8;
    SPIM4_M->CONF[ch_param->ch_sel] = tmp;
    SPIM4_M->SS = ch_param->ch_sel;
    SPIM4_M->LBM = SPIM4_LBM_USUAL;

    rc_ctrl(perSpim4, rstUnreset);
}

uint32_t spim4TxRx(uint32_t data) {
    while(!(SPIM4_M->FL & 1) && SPIM4_M->TXED < 3);
    SPIM4_M->RUN = SPIM4_RUN_RX_CLR;
    SPIM4_M->TXD = data;
    SPIM4_M->RUN = SPIM4_RUN_GO;
    while(!SPIM4_M->RDY);
    return SPIM4_M->RXD;
}
