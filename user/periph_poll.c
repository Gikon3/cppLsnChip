#include "main.h"
#include "spim1.h"
#include "poll.h"
#include "periph_poll.h"
#include "i2cm.h"
#include "spiqf.h"
#include "spod.h"
#include "uart.h"
#include "rc.h"

void periphPoll() {
    CheckBlock check;
    
    check.count_errors = 0;
    pollSpiqf(&check);
    poll_tx_log(&check, OPCODE_SPIQF_POLL);
    
    check.count_errors = 0;
    pollUart(0, &check);
    poll_tx_log(&check, OPCODE_UART0_POLL);
    
    check.count_errors = 0;
    pollUart(1, &check);
    poll_tx_log(&check, OPCODE_UART1_POLL);
    
    check.count_errors = 0;
    pollI2cm(&check);
    poll_tx_log(&check, OPCODE_I2CM_POLL);
    
    check.count_errors = 0;
    pollSpod(&check);
    poll_tx_log(&check, OPCODE_SPOD_POLL);
}

void pollSpiqf(CheckBlock *check) {
    spiqfRead(check);
    rc_ctrl(perSpiqf, rstReset);
    rc_ctrl(perSpiqf, rstUnreset);
}

void pollUart(uint8_t uart_sel, CheckBlock *check) {
    if(!uart_sel) {
        uart0Read(check);
        rc_ctrl(perUart0, rstReset);
        rc_ctrl(perUart0, rstUnreset);
    }
    else {
        uart1Read(check);
        rc_ctrl(perUart1, rstReset);
        rc_ctrl(perUart1, rstUnreset);
    }
}

void pollI2cm(CheckBlock *check) {
    i2cmRead(check);
    rc_ctrl(perI2cm, rstReset);
    rc_ctrl(perI2cm, rstUnreset);
}

void pollSpod(CheckBlock *check) {
    spodRead(check);
    rc_ctrl(perSpod, rstReset);
    rc_ctrl(perSpod, rstUnreset);
}

void spiqfRead(CheckBlock *check) {
    if((SPIQF_M->CONF & 0xF) != 4) {
        poll_add_word(check, (uint32_t)&SPIQF_M->CONF, SPIQF_M->CONF);
    }
    if(SPIQF_M->CW1 != 5) {
        poll_add_word(check, (uint32_t)&SPIQF_M->CW1, SPIQF_M->CW1);
    }
    if(SPIQF_M->CW2 != 2) {
        poll_add_word(check, (uint32_t)&SPIQF_M->CW2, SPIQF_M->CW2);
    }
    if(SPIQF_M->WP != 1) {
        poll_add_word(check, (uint32_t)&SPIQF_M->WP, SPIQF_M->WP);
    }
    if(SPIQF_M->TXF != 256) {
        poll_add_word(check, (uint32_t)&SPIQF_M->TXF, SPIQF_M->TXF);
    }
    if(SPIQF_M->RXF != 0) {
        poll_add_word(check, (uint32_t)&SPIQF_M->RXF, SPIQF_M->RXF);
    }
    if(SPIQF_M->FL != 1) {
        poll_add_word(check, (uint32_t)&SPIQF_M->FL, SPIQF_M->FL);
    }
    if(SPIQF_M->RDY != 0) {
        poll_add_word(check, (uint32_t)&SPIQF_M->RDY, SPIQF_M->RDY);
    }
}

void uart0Read(CheckBlock *check) {
    if(UART0_M->BRT != 0) {
        poll_add_word(check, (uint32_t)&UART0_M->BRT, UART0_M->BRT);
    }
    if(UART0_M->TXPRM != 0x43) {
        poll_add_word(check, (uint32_t)&UART0_M->TXPRM, UART0_M->TXPRM);
    }
    if(UART0_M->TXCONF != 0) {
        poll_add_word(check, (uint32_t)&UART0_M->TXCONF, UART0_M->TXCONF);
    }
    if(UART0_M->TXFL != 0x200) {
        poll_add_word(check, (uint32_t)&UART0_M->TXFL, UART0_M->TXFL);
    }
    if(UART0_M->BRR != 0) {
        poll_add_word(check, (uint32_t)&UART0_M->BRR, UART0_M->BRR);
    }
    if(UART0_M->RXPRM != 3) {
        poll_add_word(check, (uint32_t)&UART0_M->RXPRM, UART0_M->RXPRM);
    }
    if(UART0_M->RXCONF != 0) {
        poll_add_word(check, (uint32_t)&UART0_M->RXCONF, UART0_M->RXCONF);
    }
    if(UART0_M->RXFL != 0x100) {
        poll_add_word(check, (uint32_t)&UART0_M->RXFL, UART0_M->RXFL);
    }
    if(UART0_M->CONF != 0) {
        poll_add_word(check, (uint32_t)&UART0_M->CONF, UART0_M->CONF);
    }
}

void uart1Read(CheckBlock *check) {
    if(UART1_M->BRT != 0) {
        poll_add_word(check, (uint32_t)&UART1_M->BRT, UART1_M->BRT);
    }
    if(UART1_M->TXPRM != 0x43) {
        poll_add_word(check, (uint32_t)&UART1_M->TXPRM, UART1_M->TXPRM);
    }
    if(UART1_M->TXCONF != 0) {
        poll_add_word(check, (uint32_t)&UART1_M->TXCONF, UART1_M->TXCONF);
    }
    if(UART1_M->TXFL != 0x200) {
        poll_add_word(check, (uint32_t)&UART1_M->TXFL, UART1_M->TXFL);
    }
    if(UART1_M->BRR != 0) {
        poll_add_word(check, (uint32_t)&UART1_M->BRR, UART1_M->BRR);
    }
    if(UART1_M->RXPRM != 3) {
        poll_add_word(check, (uint32_t)&UART1_M->RXPRM, UART1_M->RXPRM);
    }
    if(UART1_M->RXCONF != 0) {
        poll_add_word(check, (uint32_t)&UART1_M->RXCONF, UART1_M->RXCONF);
    }
    if(UART1_M->RXFL != 0x100) {
        poll_add_word(check, (uint32_t)&UART1_M->RXFL, UART1_M->RXFL);
    }
    if(UART1_M->CONF != 0) {
        poll_add_word(check, (uint32_t)&UART1_M->CONF, UART1_M->CONF);
    }
}

void i2cmRead(CheckBlock *check) {
    if(I2CM_M->PRESC != 0x3C) {
        poll_add_word(check, (uint32_t)&I2CM_M->PRESC, I2CM_M->PRESC);
    }
    if(I2CM_M->CONF != 0) {
        poll_add_word(check, (uint32_t)&I2CM_M->CONF, I2CM_M->CONF);
    }
    if(I2CM_M->TXED != 128) {
        poll_add_word(check, (uint32_t)&I2CM_M->TXED, I2CM_M->TXED);
    }
    if(I2CM_M->RXRD != 0) {
        poll_add_word(check, (uint32_t)&I2CM_M->RXRD, I2CM_M->RXRD);
    }
    if(I2CM_M->BUSY != 0) {
        poll_add_word(check, (uint32_t)&I2CM_M->BUSY, I2CM_M->BUSY);
    }
    if(I2CM_M->FL != 0) {
        poll_add_word(check, (uint32_t)&I2CM_M->FL, I2CM_M->FL);
    }
    if(I2CM_M->RDY != 0) {
        poll_add_word(check, (uint32_t)&I2CM_M->RDY, I2CM_M->RDY);
    }
    if(I2CM_M->ADDRSCAN != 0) {
        poll_add_word(check, (uint32_t)&I2CM_M->ADDRSCAN, I2CM_M->ADDRSCAN);
    }
    if(I2CM_M->SCANEN != 0) {
        poll_add_word(check, (uint32_t)&I2CM_M->SCANEN, I2CM_M->SCANEN);
    }
    if(I2CM_M->SCANFL != 0) {
        poll_add_word(check, (uint32_t)&I2CM_M->SCANFL, I2CM_M->SCANFL);
    }
    if(I2CM_M->EOSMSK != 0) {
        poll_add_word(check, (uint32_t)&I2CM_M->EOSMSK, I2CM_M->EOSMSK);
    }
}

void spodRead(CheckBlock *check) {
    if(SPOD_M->RUN != 0) {
        poll_add_word(check, (uint32_t)&SPOD_M->RUN, SPOD_M->RUN);
    }
    if(SPOD_M->SCALE != 0) {
        poll_add_word(check, (uint32_t)&SPOD_M->SCALE, SPOD_M->SCALE);
    }
    if(SPOD_M->CTRL != 0) {
        poll_add_word(check, (uint32_t)&SPOD_M->CTRL, SPOD_M->CTRL);
    }
    if(SPOD_M->FL != 0) {
        poll_add_word(check, (uint32_t)&SPOD_M->FL, SPOD_M->FL);
    }
    if(SPOD_M->ETH != 0) {
        poll_add_word(check, (uint32_t)&SPOD_M->ETH, SPOD_M->ETH);
    }
    if(SPOD_M->ETHSH != 256) {
        poll_add_word(check, (uint32_t)&SPOD_M->ETHSH, SPOD_M->ETHSH);
    }
    if(SPOD_M->ACF != 0) {
        poll_add_word(check, (uint32_t)&SPOD_M->ACF, SPOD_M->ACF);
    }
    for(uint8_t i = 0; i < 25; ++ i) {
        if(SPOD_M->ETHB[i] != 0) {
            poll_add_word(check, (uint32_t)&SPOD_M->ETHB[i], SPOD_M->ETHB[i]);
        }
    }
    for(uint16_t i = 0; i < 512; ++ i) {
        if(SPOD_M->BUFF[i] != 0) {
            poll_add_word(check, (uint32_t)&SPOD_M->BUFF[i], SPOD_M->BUFF[i]);
        }
    }
}
